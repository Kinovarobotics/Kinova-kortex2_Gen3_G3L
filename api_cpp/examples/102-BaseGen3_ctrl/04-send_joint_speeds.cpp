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

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

void example_move_to_start_position(k_api::Base::BaseClient* base)
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

    // We suppose the arm is a 7DOF
    std::vector<double> angles = {0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0}; 

    // 90 degrees on 4th actuator
    for (size_t i = 0; i < angles.size(); ++i) 
    {
        auto joint_angle = joint_angles->add_joint_angles();
        joint_angle->set_joint_identifier(i);
        joint_angle->set_value(angles[i]);
    }

    base->PlayJointTrajectory(constrained_joint_angles);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));
    std::cout << "Reached the starting position." << std::endl;
}

void example_send_joint_speeds(k_api::Base::BaseClient* base)
{

    std::cout << "Sending the angular velocities to the robot for 10 seconds..." << std::endl;

    k_api::Base::JointSpeeds joint_speeds;

    std::vector<float> speeds = {-10.0f, 0.0f, 10.0f, 0.0f, -10.0f, 0.0f, 10.0f};
    for(size_t i = 0 ; i < speeds.size(); ++i)
    {
        auto joint_speed = joint_speeds.add_joint_speeds();
        joint_speed->set_joint_identifier(i);
        joint_speed->set_value(speeds.at(i));
        joint_speed->set_duration(1);
    }
    base->SendJointSpeedsCommand(joint_speeds);

    // Wait 5 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    // Stop the robot
    std::cout << "Stopping the robot" << std::endl;

    k_api::Base::JointSpeeds joint_speeds_stop;
    std::vector<float> stop = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
    for(size_t i = 0 ; i < stop.size(); ++i)
    {
        auto joint_speed = joint_speeds.add_joint_speeds();
        joint_speed->set_joint_identifier(i);
        joint_speed->set_value(speeds.at(i));
        joint_speed->set_duration(1);
    }
    base->SendJointSpeedsCommand(joint_speeds_stop);
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
    example_move_to_start_position(base);
    example_send_joint_speeds(base);

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
};