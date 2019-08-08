/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/

#include <SessionManager.h>
#include <BaseClientRpc.h>
#include <DeviceConfigClientRpc.h>

#include <RouterClient.h>
#include <TransportClientTcp.h>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

/*****************************
 * Example related functions *
 *****************************/
void print_limitations(const k_api::Base::JointsLimitationsList& limitations)
{
    std::cout << "============================================" << std::endl;
    for(auto limitation : limitations.joints_limitations())
    {
        std::cout << "Joint: " << limitation.joint_identifier() << std::endl;
        std::cout << "Type of limitation: " << k_api::Base::LimitationType_Name(limitation.type()) << std::endl;
        std::cout << "Value: " << limitation.value() << std::endl << std::endl;
    }
    std::cout << "============================================" << std::endl << std::endl;
}

void function_callback(const k_api::Error& err, const k_api::Base::JointsLimitationsList& limitations)
{
    std::cout << "Callback function results: " << std::endl << std::endl;
    print_limitations(limitations);
}

/**************************
 * Example core functions *
 **************************/
void example_blocking_function_call(k_api::Base::BaseClient* base)
{
    // Execution will be blocked until GetAvailableWifi has completed execution.
    auto limitations = base->GetAllJointsSpeedHardLimitation();
    std::cout << "Blocking function results: " << std::endl << std::endl;
    print_limitations(limitations);
}

void example_callback_function_call(k_api::Base::BaseClient* base)
{
    // Specify a callback to be executed when the method executes.
    base->GetAllJointsSpeedHardLimitation_callback(function_callback);

    // A lambda function can also be used as a callback function.
    auto lambda_function_callback = [](const k_api::Error &err, const k_api::Base::JointsLimitationsList& limitations)
    {
        print_limitations(limitations);
    };
    base->GetAllJointsSpeedHardLimitation_callback(lambda_function_callback);
}

void example_future_function_call(k_api::Base::BaseClient* base)
{
    // The function returns a future object, and not a workable object.
    std::future<k_api::Base::JointsLimitationsList> limitations_future_async = base->GetAllJointsSpeedHardLimitation_async();
    
    // Waiting for the promise to be completed by the API.
    auto timeout_ms = std::chrono::milliseconds(10000);
    std::future_status status = limitations_future_async.wait_for(timeout_ms);
    if(status != std::future_status::ready)
    {
        throw std::runtime_error("Timeout detected while waiting for function\n");
    }
    
    // Retrieve the workable object from the future object.
    auto limitations_async = limitations_future_async.get();
    std::cout << "Future function results: " << std::endl << std::endl;
    print_limitations(limitations_async);
}


void example_router_option(k_api::Base::BaseClient* base)
{
    // RouterClientSendOptions exists to modify the default behavior
    // of the router. Router default values are 
    //     andForget = False
    //     delay_ms = 0
    //     timeout_ms = 10000

    // RouterClientSendOptions is optional and is the last parameter to a function call.
    
    // Since RouterClientSendOptions is the last parameter, deviceID needs to be specified
    // Here we use device_id = 0 (Base)
    int device_id = 0;
    auto router_options = k_api::RouterClientSendOptions();
    router_options.timeout_ms = 5000;  // (milliseconds)
    router_options.andForget = false;
    router_options.delay_ms = 0;       // (milliseconds)

    auto limitations = base->GetAllJointsSpeedHardLimitation(device_id, router_options);
    std::cout << "Call with router option results: " << std::endl << std::endl;
    print_limitations(limitations);
}


int main(int argc, char **argv)
{
    // Create API objects
    auto error_callback = [](k_api::KError err){ cout << "_________ callback error _________" << err.toString(); };
    auto transport = new k_api::TransportClientTcp();
    auto router = new k_api::RouterClient(transport, error_callback);
    transport->connect(IP_ADDRESS, PORT);

    // Set session data connection information
    auto create_session_info = k_api::Session::CreateSessionInfo();
    create_session_info.set_username("admin");
    create_session_info.set_password("admin");
    create_session_info.set_session_inactivity_timeout(60000);   // (milliseconds)
    create_session_info.set_connection_inactivity_timeout(2000); // (milliseconds)

    // Session manager service wrapper
    std::cout << "Creating session for communication" << std::endl;
    auto session_manager = new k_api::SessionManager(router);
    session_manager->CreateSession(create_session_info);
    std::cout << "Session created" << std::endl;

    // Create services
    auto base = new k_api::Base::BaseClient(router);

    // Example core
    example_blocking_function_call(base);
    example_callback_function_call(base);
    example_future_function_call(base);
    example_router_option(base);

    // Close API session
    session_manager->CloseSession();

    // Deactivate the router and cleanly disconnect from the transport object
    router->SetActivationStatus(false);
    transport->disconnect();

    // Destroy the API
    delete base;
    delete session_manager;
    delete router;
    delete transport;
}