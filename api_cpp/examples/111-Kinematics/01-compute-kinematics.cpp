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

#include <RouterClient.h>
#include <TransportClientTcp.h>

#include "utilities.h"

#define PORT 10000

namespace k_api = Kinova::Api;

bool example_forward_kinematics(k_api::Base::BaseClient* base)
{
    // Current arm's joint angles
    std::cout << "Getting Angles for every joint..." << std::endl;
    k_api::Base::JointAngles input_joint_angles = base->GetMeasuredJointAngles();
    std::cout << "Joint ID : Joint Angle" << std::endl;
    for (auto joint_angle : input_joint_angles.joint_angles()) 
    {
        std::cout << joint_angle.joint_identifier() << " : " << joint_angle.value() << std::endl;
    }
    std::cout << std::endl;

    // Computing Foward Kinematics (Angle -> cartesian convert) from arm's current joint angles
    std::cout << "Computing Foward Kinematics using joint angles..." << std::endl;
    k_api::Base::Pose pose = base->ComputeForwardKinematics(input_joint_angles);

    std::cout << "Pose calculated : " << std::endl;
    std::cout << "Coordinate (x, y, z)  : (" << pose.x() << ", " << pose.y() << ", " << pose.z() << ")" << std::endl;
    std::cout << "Theta (theta_x, theta_y, theta_z)  : (" << pose.theta_x() << ", " << pose.theta_y() << ", " << pose.theta_z() << ")" << std::endl << std::endl;

    return true;
}


bool example_inverse_kinematics(k_api::Base::BaseClient* base)
{
    // get robot's pose (by using forward kinematics)
    k_api::Base::JointAngles input_joint_angles = base->GetMeasuredJointAngles();
    k_api::Base::Pose pose = base->ComputeForwardKinematics(input_joint_angles);

    // Object containing cartesian coordinates and Angle Guess
    k_api::Base::IKData input_IkData; 
    
    // Fill the IKData Object with the cartesian coordinates that need to be converted
    input_IkData.mutable_cartesian_pose()->set_x(pose.x());
    input_IkData.mutable_cartesian_pose()->set_y(pose.y());
    input_IkData.mutable_cartesian_pose()->set_z(pose.z());
    input_IkData.mutable_cartesian_pose()->set_theta_x(pose.theta_x());
    input_IkData.mutable_cartesian_pose()->set_theta_y(pose.theta_y());
    input_IkData.mutable_cartesian_pose()->set_theta_z(pose.theta_z());

    // Fill the IKData Object with the guessed joint angles
    Kinova::Api::Base::JointAngle* jAngle; 
    for(auto joint_angle : input_joint_angles.joint_angles())
    {
        jAngle = input_IkData.mutable_guess()->add_joint_angles();
        // '- 1' to generate an actual "guess" for current joint angles
        jAngle->set_value(joint_angle.value() - 1); 
    }

    // Computing Inverse Kinematics (cartesian -> Angle convert) from arm's current pose and joint angles guess
    std::cout << "Computing Inverse Kinematics using joint angles and pose..." << std::endl;
    k_api::Base::JointAngles computed_joint_angles = base->ComputeInverseKinematics(input_IkData);
    std::cout << "Joint ID : Joint Angle" << std::endl;
    for (auto joint_angle : computed_joint_angles.joint_angles()) 
    {
        std::cout << joint_angle.joint_identifier() << " : " << joint_angle.value() << std::endl;
    }

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

    
    // Create BaseClient
    auto base = new k_api::Base::BaseClient(router);
    
    // example core
    bool success = true;
    success &= example_forward_kinematics(base);
    success &= example_inverse_kinematics(base);

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

    return success? 0: 1;
}