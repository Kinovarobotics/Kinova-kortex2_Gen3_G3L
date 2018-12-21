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

#include <KDetailedException.h>

#include <SessionManager.h>
#include <DeviceConfigClientRpc.h>
#include <BaseClientRpc.h>

#include <RouterClient.h>
#include <TransportClientUdp.h>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

void example_error_management(k_api::Base::BaseClient* pBase)
{
    try
    {
        pBase->CreateUserProfile(k_api::Base::FullUserProfile());
    }
    catch(k_api::KDetailedException& ex)
    {
        std::cout << "KDetailedException detected toStr: " << ex.toString().c_str() << std::endl;
        std::cout << "KDetailedoption detected what:  " << ex.what() << std::endl;
    }
}


int main(int argc, char **argv)
{
    k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
    pTransport->connect(IP_ADDRESS, PORT);
    k_api::RouterClient* pRouterClient = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

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

    example_error_management(pBase);

    pSessionMng->CloseSession();

    pTransport->disconnect();
    delete pBase;
    delete pSessionMng;
    delete pRouterClient;
    delete pTransport;
}