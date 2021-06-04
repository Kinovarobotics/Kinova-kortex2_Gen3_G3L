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
#include <Common.pb.h>
#include <DeviceConfigClientRpc.h>

#include <RouterClient.h>
#include <TransportClientTcp.h>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

/*****************************
 * Example related functions *
 *****************************/
void print_action_list(const k_api::Base::ActionList& action_list)
{
    std::cout << "List of all actions in the arm:" << std::endl;
    for(auto action : action_list.action_list())
    {
        std::cout << "============================================" << std::endl;
        std::cout << "Action name : " << action.name() << std::endl;
        std::cout << "Action identifier: " << action.handle().identifier() << std::endl;
        std::cout << "Action type: " << Kinova::Api::Base::ActionType_Name(action.handle().action_type()) << std::endl;
        std::cout << "Action permissions: " << std::endl;
        if (action.handle().permission() & Kinova::Api::Common::NO_PERMISSION) std::cout << "\t- " << Kinova::Api::Common::Permission_Name(Kinova::Api::Common::NO_PERMISSION) << std::endl;
        if (action.handle().permission() & Kinova::Api::Common::READ_PERMISSION) std::cout << "\t- " << Kinova::Api::Common::Permission_Name(Kinova::Api::Common::READ_PERMISSION) << std::endl;
        if (action.handle().permission() & Kinova::Api::Common::UPDATE_PERMISSION) std::cout << "\t- " << Kinova::Api::Common::Permission_Name(Kinova::Api::Common::UPDATE_PERMISSION) << std::endl;
        if (action.handle().permission() & Kinova::Api::Common::DELETE_PERMISSION) std::cout << "\t- " << Kinova::Api::Common::Permission_Name(Kinova::Api::Common::DELETE_PERMISSION) << std::endl;
        std::cout << "============================================" << std::endl;
    }
}

void function_callback(const k_api::Error& err, const k_api::Base::ActionList& action_list)
{
    std::cout << "Callback function results: " << std::endl;
    print_action_list(action_list);
}

/**************************
 * Example core functions *
 **************************/
void example_blocking_function_call(k_api::Base::BaseClient* base)
{
    // Execution will be blocked until GetAvailableWifi has completed execution.
    k_api::Base::RequestedActionType requested_action_type;
    auto action_list = base->ReadAllActions(requested_action_type);
    std::cout << "Blocking function results: " << std::endl << std::endl;
    print_action_list(action_list);
}

void example_callback_function_call(k_api::Base::BaseClient* base)
{
    // Specify a callback to be executed when the method executes.
    // The callback is the argument after the input, if any
    k_api::Base::RequestedActionType requested_action_type;
    base->ReadAllActions_callback(requested_action_type, function_callback);

    // A lambda function can also be used as a callback function.
    auto lambda_function_callback = [](const k_api::Error &err, const k_api::Base::ActionList& action_list)
    {
        print_action_list(action_list);
    };
    base->ReadAllActions_callback(requested_action_type, lambda_function_callback);
}

void example_future_function_call(k_api::Base::BaseClient* base)
{
    // The function returns a future object, and not a workable object.
    k_api::Base::RequestedActionType requested_action_type;
    std::future<k_api::Base::ActionList> action_list_future_async = base->ReadAllActions_async(requested_action_type);
    
    // Waiting for the promise to be completed by the API.
    auto timeout_ms = std::chrono::milliseconds(10000);
    std::future_status status = action_list_future_async.wait_for(timeout_ms);
    if(status != std::future_status::ready)
    {
        throw std::runtime_error("Timeout detected while waiting for function\n");
    }
    
    // Retrieve the workable object from the future object.
    auto action_list_async = action_list_future_async.get();
    std::cout << "Future function results: " << std::endl << std::endl;
    print_action_list(action_list_async);
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

    k_api::Base::RequestedActionType requested_action_type;
    auto action_list = base->ReadAllActions(requested_action_type, device_id, router_options);
    std::cout << "Call with router option results: " << std::endl << std::endl;
    print_action_list(action_list);
}


int main(int argc, char **argv)
{
    auto parsed_args = ParseExampleArguments(argc, argv);

    // Create API objects
    auto error_callback = [](k_api::KError err){ cout << "_________ callback error _________" << err.toString(); };
    auto transport = new k_api::TransportClientTcp();
    auto router = new k_api::RouterClient(transport, error_callback);
    transport->connect(parsed_args.ip_address, PORT);

    // Set session data connection information
    auto create_session_info = k_api::Session::CreateSessionInfo();
    create_session_info.set_username(parsed_args.username);
    create_session_info.set_password(parsed_args.password);
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