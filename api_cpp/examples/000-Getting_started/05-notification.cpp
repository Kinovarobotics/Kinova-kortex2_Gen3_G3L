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

#include <google/protobuf/util/json_util.h>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

void example_notification(k_api::Base::BaseClient* base)
{
    auto function_callback = [](k_api::Base::ConfigurationChangeNotification data)
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
    auto notification_handle = base->OnNotificationConfigurationChangeTopic(function_callback, k_api::Common::NotificationOptions());

    // Create a user profile to trigger a notification
    auto full_user_profile = k_api::Base::FullUserProfile();
    auto user_profile = full_user_profile.mutable_user_profile();
    auto user_profile_handle = user_profile->mutable_handle();
    user_profile_handle->set_identifier(0);
    user_profile->set_username("jcash");
    user_profile->set_firstname("Johnny");
    user_profile->set_lastname("Cash");
    full_user_profile.set_password("pwd");

    k_api::Common::UserProfileHandle returned_user_profile_handle;
    try
    {
        std::cout << "Creating user profile to trigger notification" << std::endl;
        returned_user_profile_handle = base->CreateUserProfile(full_user_profile);
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "User profile creation failed" << std::endl;
    }
    
    // Let the base process the user creation request
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Unsubscribe from notifications
    std::cout << "Unsubscribing from ConfigurationChange notifications" << std::endl;
    base->Unsubscribe(notification_handle);

    try
    {
        std::cout << "Deleting previously created user profile" << std::endl;
        base->DeleteUserProfile(returned_user_profile_handle); // Should not have received notification about this modification
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "User profile deletion failed" << std::endl;
    }

    // Let the base process the user deletion request and see the notification doesn't come in
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
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
    example_notification(base);

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