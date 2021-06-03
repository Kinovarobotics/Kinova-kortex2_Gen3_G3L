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

#include <BaseClientRpc.h>

#include <SessionManager.h>
#include <RouterClient.h>
#include <TransportClientTcp.h>
#include <DeviceManagerClientRpc.h>
#include <DeviceConfigClientRpc.h>
#include <Common.pb.h>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

// Maximum allowed waiting time during actions
constexpr auto TIMEOUT_DURATION = std::chrono::seconds(20);

// Actuator speed (deg/s)
const float SPEED = 20.0f;

// Create an event listener that will set the promise action event to the exit value
// Will set to either END or ABORT
// Use finish_promise.get_future.get() to wait and get the value
std::function<void(k_api::Base::ActionNotification)> 
    create_action_event_listener_by_promise(std::promise<k_api::Base::ActionEvent>& finish_promise)
{
    return [&finish_promise] (k_api::Base::ActionNotification notification)
    {
        const auto action_event = notification.action_event();
        switch(action_event)
        {
        case k_api::Base::ActionEvent::ACTION_END:
        case k_api::Base::ActionEvent::ACTION_ABORT:
            finish_promise.set_value(action_event);
            break;
        default:
            break;
        }
    };
}

bool example_move_to_start_position(k_api::Base::BaseClient* base)
{
    // Make sure the arm is in Single Level Servoing before executing an Action
    auto servoingMode = k_api::Base::ServoingModeInformation();
    servoingMode.set_servoing_mode(k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);
    base->SetServoingMode(servoingMode);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    // Move arm to ready position
    std::cout << "Moving the arm to the start position..." << std::endl;
    auto constrained_joint_angles = k_api::Base::ConstrainedJointAngles();
    auto joint_angles = constrained_joint_angles.mutable_joint_angles();

    auto actuator_count = base->GetActuatorCount();
    const std::vector<double> angles(actuator_count.count(), 0.0);

    for (size_t i = 0; i < angles.size(); ++i) 
    {
        auto joint_angle = joint_angles->add_joint_angles();
        joint_angle->set_joint_identifier(i);
        joint_angle->set_value(angles[i]);
    }

    // Connect to notification action topic
    std::promise<k_api::Base::ActionEvent> promise;
    auto future = promise.get_future();
    auto notification_handle = base->OnNotificationActionTopic(
        create_action_event_listener_by_promise(promise),
        k_api::Common::NotificationOptions{}
    );

    base->PlayJointTrajectory(constrained_joint_angles);

    // Wait for action to finish
    const auto status = future.wait_for(TIMEOUT_DURATION);
    base->Unsubscribe(notification_handle);

    if(status != std::future_status::ready)
    {
        std::cout << "Timeout on action notification wait" << std::endl;
        return false;
    }

    return true;
}

bool example_send_joint_speeds(k_api::Base::BaseClient* base)
{
    std::cout << "Sending the angular velocities to the robot for 10 seconds..." << std::endl;

    k_api::Base::JointSpeeds joint_speeds;

    std::vector<float> speeds;
    // The 7DOF robot will spin in the same direction for 10 seconds    
    int actuator_count = base->GetActuatorCount().count();
    if (actuator_count == 7)
    {
        speeds = {-SPEED, 0.0f, SPEED, 0.0f, -SPEED, 0.0f, SPEED};
        for (size_t i = 0 ; i < speeds.size(); ++i)
        {
            auto joint_speed = joint_speeds.add_joint_speeds();
            joint_speed->set_joint_identifier(i);
            joint_speed->set_value(speeds.at(i));
            joint_speed->set_duration(1);
        }
        base->SendJointSpeedsCommand(joint_speeds);

        // Wait 10 seconds
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
    // The 6 DOF robot will alternate between 4 spins, each for 2.5 seconds
    else if (actuator_count == 6)
    {
        for (int times = 0; times < 4; times++)
        {
            joint_speeds.clear_joint_speeds();
            // Invert the speeds each time
            if (times % 2)
            {
                speeds = {-SPEED, 0.0f, 0.0f, SPEED, 0.0f, 0.0f};
            }
            else
            {
                speeds = {SPEED, 0.0f, 0.0f, -SPEED, 0.0f, 0.0f};
            }
            
            for (size_t i = 0 ; i < speeds.size(); ++i)
            {
                auto joint_speed = joint_speeds.add_joint_speeds();
                joint_speed->set_joint_identifier(i);
                joint_speed->set_value(speeds.at(i));
                joint_speed->set_duration(1);
            }
            base->SendJointSpeedsCommand(joint_speeds);

            // Wait 2.5 seconds
            std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        }
    }
    
    // Stop the robot
    std::cout << "Stopping the robot" << std::endl;
    base->Stop();

    return true;
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
    bool success = true;
    success &= example_move_to_start_position(base);
    success &= example_send_joint_speeds(base);

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

    return success ? 0: 1;
};