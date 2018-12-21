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

#include <google/protobuf/util/json_util.h>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

void example_notification(k_api::Base::BaseClient* pBase)
{
    auto fct_callback = [](k_api::Base::ConfigurationChangeNotification data)
    {
        std::cout << "Callback triger" << std::endl;

        std::string jsonString = "";
        google::protobuf::util::MessageToJsonString(data, &jsonString);
        std::cout << "********************************" << std::endl;
        std::cout << "**  Callback function called  **" << std::endl;
        std::cout << jsonString << std::endl;
        std::cout << "********************************" << std::endl;
    };

    std::cout << "Create notification" << std::endl;
    auto notifHandle = pBase->OnNotificationConfigurationChangeTopic(fct_callback, k_api::Common::NotificationOptions());

    // creating a user to trigger the notification
    auto fullUserProfile = k_api::Base::FullUserProfile();
    auto userProfile = fullUserProfile.mutable_user_profile();
    auto userProfileHandle = userProfile->mutable_handle();
    userProfileHandle->set_identifier(0);
    userProfile->set_username("jcash");
    userProfile->set_firstname("Johnny");
    userProfile->set_lastname("Cash");
    fullUserProfile.set_password("pwd");


    k_api::Common::UserProfileHandle returnedUserProfileHandle;
    try
    {
        std::cout << "Create User to trigger notification" << std::endl;
        returnedUserProfileHandle = pBase->CreateUserProfile(fullUserProfile);
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "Error during user creation" << std::endl;
    }
    
    // let the base process the user creation request
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // unsubscribe from notifications

    std::cout << "Unsubscribe from notification" << std::endl;
    pBase->Unsubscribe(notifHandle);

    try
    {
        std::cout << "Deleting previously created user" << std::endl;
        pBase->DeleteUserProfile(returnedUserProfileHandle); // should not have received notification about this modification
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "Error during user deletion" << std::endl;
    }

}

int main(int argc, char **argv)
{
    k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
    pTransport->connect(IP_ADDRESS, PORT);
    k_api::RouterClient* pRouterClient = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

    // Create session
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouterClient);
    pSessionMng->CreateSession(createSessionInfo);
    std::cout << "Session Created" << std::endl;

    k_api::Base::BaseClient* pBase = new k_api::Base::BaseClient(pRouterClient);

    example_notification(pBase);

    pSessionMng->CloseSession();

    pTransport->disconnect();
    delete pBase;
    delete pSessionMng;
    delete pRouterClient;
    delete pTransport;
}