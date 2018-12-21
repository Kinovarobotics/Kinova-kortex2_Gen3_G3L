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
#include <TransportClientUdp.h>

namespace k_api = Kinova::Api;

#define PORT 10000
#define IP_ADDRESS "192.168.1.10"


/****************************
 * Example related function *
 ****************************/
void printWifiList(k_api::Base::WifiInformationList availableWifi)
{
    for(int i = 0 ; i < availableWifi.wifi_information_list_size(); i++)
    {
        std::cout << "============================================" << std::endl;
        std::cout << "SSID: " << availableWifi.wifi_information_list(i).ssid().identifier() << std::endl;
        std::cout << "Wi-Fi security type: " << availableWifi.wifi_information_list(i).security_type() << std::endl;
        std::cout << "Wi-Fi encryption type: " << availableWifi.wifi_information_list(i).encryption_type() << std::endl;
        std::cout << "Signal strength: " << availableWifi.wifi_information_list(i).signal_strength() << std::endl;
        std::cout << "============================================" << std::endl << std::endl;
    }
}


void fct_callback(const k_api::Error &err, const k_api::Base::WifiInformationList& wifiList)
{
    std::cout << "Callback function results: " << std::endl << std::endl;
    printWifiList(wifiList);
}


/***********
 * Example *
 ***********/
void example_blocking_function_call(k_api::Base::BaseClient* pBase)
{
    // Execution will be blocked until GetAvailableWifi has returned value
    auto availableWifi = pBase->GetAvailableWifi();
    std::cout << "Blocking function results: " << std::endl << std::endl;
    printWifiList(availableWifi);
}


void example_callback_function_call(k_api::Base::BaseClient* pBase)
{
 
    // Can callback an already implemented function
    pBase->GetAvailableWifi_callback(fct_callback);
    

    // Can use a lambda function as a callback function
    auto lambda_fct_callback = [](const k_api::Error &err, const k_api::Base::WifiInformationList& wifiList)
    {
        printWifiList(wifiList);
    };
    pBase->GetAvailableWifi_callback(lambda_fct_callback);
}


void example_future_function_call(k_api::Base::BaseClient* pBase)
{

    // The function returns a promise not a working object
    std::future<k_api::Base::WifiInformationList> availableWifiFuture_async = pBase->GetAvailableWifi_async();
    
    // Waiting for the promise to be complete by the API
    auto timeout_ms = std::chrono::milliseconds(10000);
    std::future_status status = availableWifiFuture_async.wait_for(timeout_ms);
    if(status != std::future_status::ready)
    {
        throw std::runtime_error("Timeout detected while waiting for function\n");
    }
    
    // Retrieve the workable object from the promise
    auto availableWifi_async = availableWifiFuture_async.get();
    std::cout << "Future function results: " << std::endl << std::endl;
    printWifiList(availableWifi_async);
}


void example_router_option(k_api::Base::BaseClient* pBase)
{
    // RouterClientSendOptions exists to modify the default behavior
    // of the router. The router default values are 
    //     andForget = False
    //     delay_ms = 0
    //     timeout_ms = 10000

    // RouterClientSendOptions is optional and is the last parameter to a function call.
    
    // Since RouterClientSendOptions is the last parameter, deviceID need to be specified
    auto routerOptions = k_api::RouterClientSendOptions();
    routerOptions.timeout_ms = 5000;  // (milliseconds)
    routerOptions.andForget = false;
    routerOptions.delay_ms = 0;       // (milliseconds)

    auto availableWifi_2 = pBase->GetAvailableWifi(0, routerOptions);
    std::cout << "Call with router option results: " << std::endl << std::endl;
    printWifiList(availableWifi_2);
}


int main(int argc, char **argv)
{
    k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
    k_api::RouterClient* pRouterClient = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });
    pTransport->connect(IP_ADDRESS, PORT);

    // create session
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouterClient);
    pSessionMng->CreateSession(createSessionInfo);
    std::cout << "\nSession Created" << std::endl;

    k_api::Base::BaseClient* pBase = new k_api::Base::BaseClient(pRouterClient);

    example_blocking_function_call(pBase);
    example_callback_function_call(pBase);
    example_future_function_call(pBase);
    example_router_option(pBase);

    pSessionMng->CloseSession();

    pTransport->disconnect();
    delete pBase;
    delete pSessionMng;
    delete pRouterClient;
    delete pTransport;
}