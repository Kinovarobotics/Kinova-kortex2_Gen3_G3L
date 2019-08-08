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

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

namespace k_api = Kinova::Api;

void example_move_to_home_position(k_api::Base::BaseClient* base)
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
    } 
    else 
    {
        base->ExecuteActionFromReference(action_handle);
        std::this_thread::sleep_for(std::chrono::milliseconds(20000)); // Leave time to action to finish
    }
}

void example_angular_action_movement(k_api::Base::BaseClient* base) 
{
    std::cout << "Starting angular action movement ..." << std::endl;

    auto action = k_api::Base::Action();
    action.set_name("Example angular action movement");
    action.set_application_data("");

    auto reach_joint_angles = action.mutable_reach_joint_angles();
    auto joint_angles = reach_joint_angles->mutable_joint_angles();

    auto actuator_count = base->GetActuatorCount();

    // Arm straight up
    for (size_t i = 0; i < actuator_count.count(); ++i) 
    {
        auto joint_angle = joint_angles->add_joint_angles();
        joint_angle->set_joint_identifier(i);
        joint_angle->set_value(0);
    }

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    std::cout << "Angular movement completed" << std::endl;
}

void example_cartesian_action_movement(k_api::Base::BaseClient* base) 
{
    std::cout << "Starting Cartesian action movement ..." << std::endl;

    auto action = k_api::Base::Action();
    action.set_name("Example Cartesian action movement");
    action.set_application_data("");

    auto constrained_pose = action.mutable_reach_pose();
    auto pose = constrained_pose->mutable_target_pose();
    pose->set_x(0.8);           // x (meters)
    pose->set_y(0.0);           // y (meters)
    pose->set_z(0.36);          // z (meters)
    pose->set_theta_x(10.0);    // theta x (degrees)
    pose->set_theta_y(90.0);    // theta y (degrees)
    pose->set_theta_z(10.0);    // theta z (degrees)

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    std::cout << "Cartesian movement completed" << std::endl;
}

void example_angular_trajectory_movement(k_api::Base::BaseClient* base) 
{

    auto constrained_joint_angles = k_api::Base::ConstrainedJointAngles();
    auto joint_angles = constrained_joint_angles.mutable_joint_angles();

    auto actuator_count = base->GetActuatorCount();

    // Arm straight up
    for (size_t i = 0; i < actuator_count.count(); ++i) 
    {
        auto joint_angle = joint_angles->add_joint_angles();
        joint_angle->set_joint_identifier(i);
        joint_angle->set_value(0);
    }

    std::cout << "Reaching joint angles..." << std::endl;
    base->PlayJointTrajectory(constrained_joint_angles);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    std::cout << "Joint angles reached" << std::endl;
}

void example_cartesian_trajectory_movement(k_api::Base::BaseClient* base) 
{

    auto constrained_pose = k_api::Base::ConstrainedPose();
    auto pose = constrained_pose.mutable_target_pose();

    pose->set_x(0.8);           // x (meters)
    pose->set_y(0.0);           // y (meters)
    pose->set_z(0.36);          // z (meters)
    pose->set_theta_x(10.0);    // theta x (degrees)
    pose->set_theta_y(90.0);    // theta y (degrees)
    pose->set_theta_z(10.0);    // theta z (degrees)

    std::cout << "Reaching cartesian pose..." << std::endl;
    base->PlayCartesianTrajectory(constrained_pose);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    std::cout << "Cartesian pose reached" << std::endl;
}

int main(int argc, char **argv)
{
    // Create API objects
    auto error_callback = [](k_api::KError err){ cout << "_________ callback error _________" << err.toString(); };
    auto transport = new k_api::TransportClientTcp();
    auto router = new k_api::RouterClient(transport, error_callback);
    transport->connect(IP_ADDRESS, PORT);

    // Set session data connection information
    auto create_session_info = k_api::Session::CreateSessionInfo();
    create_session_info.set_username("admin");
    create_session_info.set_password("admin");
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
    example_move_to_home_position(base);
    example_angular_action_movement(base);
    example_cartesian_action_movement(base);
    example_angular_trajectory_movement(base);
    example_cartesian_trajectory_movement(base);

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