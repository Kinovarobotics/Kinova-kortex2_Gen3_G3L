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
#include <KError.h>

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
        auto errorInfo = ex.getErrorInfo();
        auto errorCode = errorInfo.getError();
        std::cout << "KDetailedException detected toStr: " << ex.toString().c_str() << std::endl;
        std::cout << "KDetailedoption detected what:  " << ex.what() << std::endl << std::endl;
        
        std::cout << "KError error_code: " << errorCode.error_code() << std::endl;
        std::cout << "KError sub_code: " << errorCode.error_sub_code() << std::endl;
        std::cout << "KError sub_string: " << errorCode.error_sub_string() << std::endl;
    }
}


int main(int argc, char **argv)
{
    // Setup API
    auto pTransport = new k_api::TransportClientUdp();
    auto pRouter = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });
    pTransport->connect(IP_ADDRESS, PORT);

    // Create session
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    auto pSessionMng = new k_api::SessionManager(pRouter);
    pSessionMng->CreateSession(createSessionInfo);

    // Create required services
    auto pBase = new k_api::Base::BaseClient(pRouter);

    // Example core
    example_error_management(pBase);

    // Close API session
    pSessionMng->CloseSession();

    // Deactivate the router and cleanly disconnect from the transport object
    pRouter->SetActivationStatus(false);
    pTransport->disconnect();

    // Destroy the API
    delete pBase;
    delete pSessionMng;
    delete pRouter;
    delete pTransport;
}