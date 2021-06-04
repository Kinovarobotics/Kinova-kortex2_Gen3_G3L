/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2019 Kinova inc. All rights reserved.
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

#include <array>

#include "utilities.h"

#define PORT 10000

namespace k_api = Kinova::Api;

// Position of the protection zone (in meters)
const std::array<float,3> PROTECTION_ZONE_POS
{
    0.75f, 
    0.00f, 
    0.40f
};

// Size of the protection zone (in meters)
const std::array<float,3> PROTECTION_ZONE_DIMENSIONS
{
    0.05f, 
    0.30f, 
    0.40f
};

/// Theta values of the protection zone movement (in degrees)
const std::array<float,3> PROTECTION_ZONE_MOVEMENT_THETAS
{
    90.0,
    00.0,
    90.0 
};

// Waiting time during actions
const auto ACTION_WAITING_TIME = std::chrono::seconds(1);

// Create closure to set finished to true after an END or an ABORT
std::function<void(k_api::Base::ActionNotification)> 
check_for_end_or_abort(bool& finished)
{
    return [&finished](k_api::Base::ActionNotification notification)
    {
        std::cout << "EVENT : " << k_api::Base::ActionEvent_Name(notification.action_event()) << std::endl;

        // The action is finished when we receive a END or ABORT event
        switch(notification.action_event())
        {
        case k_api::Base::ActionEvent::ACTION_ABORT:
        case k_api::Base::ActionEvent::ACTION_END:
            finished = true;
            break;
        default:
            break;
        }
    };
}

bool move_to_home_position(k_api::Base::BaseClient* base)
{
    // Make sure the arm is in Single Level Servoing before executing an Action
    auto servoingMode = k_api::Base::ServoingModeInformation();
    servoingMode.set_servoing_mode(k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);
    base->SetServoingMode(servoingMode);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Move arm to ready position
    std::cout << "Moving the arm to a safe position" << std::endl;
    auto action_type = k_api::Base::RequestedActionType();
    action_type.set_action_type(k_api::Base::REACH_JOINT_ANGLES);
    auto action_list = base->ReadAllActions(action_type);
    auto action_handle = k_api::Base::ActionHandle();
    action_handle.set_identifier(0);
    for (auto action : action_list.action_list()) 
    {
        if (action.name() == "Home") 
        {
            action_handle = action.handle();
        }
    }

    if (action_handle.identifier() == 0) 
    {
        std::cout << "Can't reach safe position, exiting" << std::endl;
        return false;
    } 
    else 
    {
        bool action_finished = false; 
        // Notify of any action topic event
        auto options = k_api::Common::NotificationOptions();
        auto notification_handle = base->OnNotificationActionTopic(
            check_for_end_or_abort(action_finished),
            options
        );
        base->ExecuteActionFromReference(action_handle);

        // Leave time for action to finish
        while(!action_finished)
        { 
            std::this_thread::sleep_for(ACTION_WAITING_TIME);
        }

        base->Unsubscribe(notification_handle);
    }
    return true;
}

void move_to_protection_zone(k_api::Base::BaseClient* base)
{
    auto command = k_api::Base::TwistCommand();
    command.set_reference_frame(k_api::Common::CARTESIAN_REFERENCE_FRAME_BASE);
    command.set_duration(0);  // Unlimited time to execute

    std::cout << "Moving towards the protection zone for 4 seconds..." << std::endl;

    auto twist = command.mutable_twist();
    twist->set_linear_x(0.05f);
    twist->set_linear_y(0.0f);
    twist->set_linear_z(0.0f);
    twist->set_angular_x(0.0f);
    twist->set_angular_y(0.0f);
    twist->set_angular_z(0.0f);
    base->SendTwistCommand(command);

    // Let time for twist to be executed
    std::this_thread::sleep_for(std::chrono::milliseconds(4000));

    // Make movement stop
    base->Stop();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}

void move_in_front_of_protection_zone(k_api::Base::BaseClient* base)
{
    auto constrained_pose = k_api::Base::ConstrainedPose();
    auto pose = constrained_pose.mutable_target_pose();

    pose->set_x(PROTECTION_ZONE_POS.at(0) - 0.1f);    // x (meters)
    pose->set_y(PROTECTION_ZONE_POS.at(1));           // y (meters)
    pose->set_z(PROTECTION_ZONE_POS.at(2));           // z (meters)
    pose->set_theta_x(PROTECTION_ZONE_MOVEMENT_THETAS.at(0)); // theta x (degrees)
    pose->set_theta_y(PROTECTION_ZONE_MOVEMENT_THETAS.at(1)); // theta y (degrees)
    pose->set_theta_z(PROTECTION_ZONE_MOVEMENT_THETAS.at(2)); // theta z (degrees)

    bool action_finished = false; 
    // Notify of any action topic event
    auto options = k_api::Common::NotificationOptions();
    auto notification_handle = base->OnNotificationActionTopic(
        check_for_end_or_abort(action_finished),
        options
    );

    std::cout << "Reaching cartesian pose..." << std::endl;
    base->PlayCartesianTrajectory(constrained_pose);

    std::cout << "Waiting  for movement to finish ..." << std::endl;
    while(!action_finished)
    {
        std::this_thread::sleep_for(ACTION_WAITING_TIME);
    }

    std::cout << "Cartesian pose reached" << std::endl;

    base->Unsubscribe(notification_handle);
}

k_api::Base::ProtectionZoneHandle create_protection_zone(k_api::Base::BaseClient* base)
{
    // Create zone
    k_api::Base::ProtectionZone zone;
    zone.set_name("Example Protection Zone ");
    zone.set_is_enabled(true);

    // Set shape
    auto shape = zone.mutable_shape();
    shape->set_shape_type(k_api::Base::ShapeType::RECTANGULAR_PRISM);
    auto point = shape->mutable_origin();
    point->set_x(PROTECTION_ZONE_POS.at(0));
    point->set_y(PROTECTION_ZONE_POS.at(1));
    point->set_z(PROTECTION_ZONE_POS.at(2));
    shape->add_dimensions(PROTECTION_ZONE_DIMENSIONS.at(0));
    shape->add_dimensions(PROTECTION_ZONE_DIMENSIONS.at(1));
    shape->add_dimensions(PROTECTION_ZONE_DIMENSIONS.at(2));

    // Set orientation to Identity matrix
    auto orientation = shape->mutable_orientation();
    orientation->mutable_row1()->set_column1(1.0f);
    orientation->mutable_row2()->set_column2(1.0f);
    orientation->mutable_row3()->set_column3(1.0f);

    return base->CreateProtectionZone(zone);
}

void print_protection_zones(k_api::Base::BaseClient* base)
{
    const auto all_protection_zones = base->ReadAllProtectionZones();

    std::cout << "PROTECTION ZONES : " << std::endl;
    for(auto protection_zone : all_protection_zones.protection_zones())
    {
        std::cout 
            << "Protection Zone : " << protection_zone.name()
            << " Origin : [ " 
            << protection_zone.shape().origin().x() << " "
            << protection_zone.shape().origin().y() << " "
            << protection_zone.shape().origin().z()
            << " ] Dimensions : [ ";
            for(auto dim : protection_zone.shape().dimensions())
            {
                std::cout << dim << " ";
            }
            std::cout << "]" << std::endl;
    }
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

    // Try to Move to initial position
    if(!move_to_home_position(base))
    {
        std::cout << "Home position not available. Stopping example..." << std::endl;
        return 1;
    }

    // Move without the protection zone
    print_protection_zones(base);
    std::cout << "Moving in front of protection zone..." << std::endl;
    move_in_front_of_protection_zone(base);
    std::cout << "Moving inside disabled protection zone..." << std::endl;
    move_to_protection_zone(base);
    std::cout << "Going back to home position..." << std::endl;
    move_to_home_position(base);

    // Add the protection zone
    std::cout << "Creating and enabling protection zone..." << std::endl;
    auto protection_zone_handle = create_protection_zone(base);

    // Move with the protection zone
    print_protection_zones(base);
    std::cout << "Moving in front of protection zone..." << std::endl;
    move_in_front_of_protection_zone(base);
    std::cout << "Moving inside enabled protection zone..." << std::endl;
    move_to_protection_zone(base);
    std::cout << "Going back to home position..." << std::endl;
    move_to_home_position(base);

    // Delete the protection zone
    base->DeleteProtectionZone(protection_zone_handle);

    // Print final protection zones
    // The example protection zone should be removed
    print_protection_zones(base);

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