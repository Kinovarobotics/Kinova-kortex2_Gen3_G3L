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

    // Subscribe to ConfigurationChange notifications
    std::cout << "Subscribing to ConfigurationChange notifications" << std::endl;
    auto notifHandle = pBase->OnNotificationConfigurationChangeTopic(fct_callback, k_api::Common::NotificationOptions());

    // Create a user profile to trigger a notification
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
        std::cout << "Creating user profile to trigger notification" << std::endl;
        returnedUserProfileHandle = pBase->CreateUserProfile(fullUserProfile);
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "User profile creation failed" << std::endl;
    }
    
    // Let the base process the user creation request
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Unsubscribe from notifications
    std::cout << "Now unsubscribe from ConfigurationChange notifications" << std::endl;
    pBase->Unsubscribe(notifHandle);

    try
    {
        std::cout << "Deleting previously created user profile" << std::endl;
        pBase->DeleteUserProfile(returnedUserProfileHandle); // Should not have received notification about this modification
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "User profile deletion failed" << std::endl;
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
    example_notification(pBase);

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