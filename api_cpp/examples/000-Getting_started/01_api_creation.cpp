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
#include <DeviceConfigClientRpc.h>
#include <BaseClientRpc.h>

#include <RouterClient.h>
#include <TransportClientUdp.h>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

void example_api_creation()
{
    // -----------------------------------------------------------
    // How to create an API with the SessionManager, DeviceConfigClient and BaseClient services
    auto errorCallback = [](k_api::KError err){ cout << "_________ callback error _________" << err.toString(); };

    auto pTransport = new k_api::TransportClientUdp();
    auto pRouterClient = new k_api::RouterClient(pTransport, errorCallback);
    pTransport->connect(IP_ADDRESS, PORT);

    // set session data connection information
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    // session manager service wrapper
    std::cout << "\nCreating Session for communication";
    auto pSessionMng = new k_api::SessionManager(pRouterClient);
    pSessionMng->CreateSession(createSessionInfo);
    std::cout << "\nSession Created";

    // create needed services
    auto pDeviceConfig = new k_api::DeviceConfig::DeviceConfigClient(pRouterClient);
    auto pBase = new k_api::Base::BaseClient(pRouterClient);

    // -----------------------------------------------------------
    // Now you're ready to use the API
    // ...

    // -----------------------------------------------------------
    // After you're done, here's how to destroy the created API
    pSessionMng->CloseSession();

    // Destroy the API
    pTransport->disconnect();
    delete pBase;
    delete pDeviceConfig;
    delete pSessionMng;
    delete pRouterClient;
    delete pTransport;
}

int main(int argc, char **argv)
{
    example_api_creation();
}