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
#include <TransportClientUdp.h>
#include <DeviceManagerClientRpc.h>

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000


void example_angularActionMovement(k_api::Base::BaseClient* base)
{
    std::cout << "\nStarting angular action movement ..." << std::endl;

    auto action = k_api::Base::Action();
    action.set_name("Example angular action movement");
    action.set_application_data("");

    auto reachJointAngles = action.mutable_reach_joint_angles();
    auto jointAngles = reachJointAngles->mutable_joint_angles();

    auto act_count = base->GetActuatorCount();

    // Arm straight up
    for(size_t i = 0 ; i < act_count.count(); ++i)
    {
        auto jointAngle = jointAngles->add_joint_angles();
        jointAngle->set_joint_identifier(i);
        jointAngle->set_value(0);
    }

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    std::cout << "Angular movement completed" << std::endl;
}


void example_cartesianActionMovement(k_api::Base::BaseClient* base)
{
    std::cout << "\nStarting Cartesian action movement ..." << std::endl;
    
    auto action = k_api::Base::Action();
    action.set_name("Example Cartesian action movement");
    action.set_application_data("");

    auto constrainedPose = action.mutable_reach_pose();
    auto pose = constrainedPose->mutable_target_pose();
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

void example_angularTrajectoryMovement(k_api::Base::BaseClient* base)
{
    std::cout << "\nStarting angular trajectory movement ..." << std::endl;

    auto constrainedJointAngles = k_api::Base::ConstrainedJointAngles();
    auto jointAngles = constrainedJointAngles.mutable_joint_angles();

    auto act_count = base->GetActuatorCount();

    // Arm straight up
    for(size_t i = 0 ; i < act_count.count(); ++i)
    {
        auto jointAngle = jointAngles->add_joint_angles();
        jointAngle->set_joint_identifier(i);
        jointAngle->set_value(0);
    }

    std::cout << "Executing trajectory" << std::endl;
    base->PlayJointTrajectory(constrainedJointAngles);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000));

    std::cout << "Angular trajectory movement completed" << std::endl;
}

void example_cartesianTrajectoryMovement(k_api::Base::BaseClient* base)
{
    std::cout << "\nStarting Cartesian trajectory movement ..." << std::endl;
    
    auto constrainedPose = k_api::Base::ConstrainedPose();
    auto pose = constrainedPose.mutable_target_pose();

    pose->set_x(0.8);           // x (meters)
    pose->set_y(0.0);           // y (meters)
    pose->set_z(0.36);          // z (meters)
    pose->set_theta_x(10.0);    // theta x (degrees)
    pose->set_theta_y(90.0);    // theta y (degrees)
    pose->set_theta_z(10.0);    // theta z (degrees)

    std::cout << "Executing trajectory" << std::endl;
    base->PlayCartesianTrajectory(constrainedPose);

    std::cout << "Waiting 20 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(20000)); 

    std::cout << "Cartesian trajectory movement completed" << std::endl;
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

    std::cout << "\nCreating session for communication" << std::endl;
    auto pSessionMng = new k_api::SessionManager(pRouter);
    pSessionMng->CreateSession(createSessionInfo);
    std::cout << "Session created" << std::endl;

    // Create required services
    auto pBase = new k_api::Base::BaseClient(pRouter);

    // Move arm to ready position
    std::cout << "\nMoving the arm to a safe position before executing example" << std::endl;
    auto action_type = k_api::Base::RequestedActionType();
    action_type.set_action_type(k_api::Base::REACH_JOINT_ANGLES);
    auto action_list = pBase->ReadAllActions(action_type);
    auto action_handle = k_api::Base::ActionHandle();
    action_handle.set_identifier(0); 
    for( auto action : action_list.action_list())
    {
        if(action.name() == "Home")
        {
            action_handle = action.handle();
        }
    }

    if(action_handle.identifier() == 0)
    {
        std::cout << "\nCan't reach safe position. Exiting" << std::endl;       
    }
    else
    {
        pBase->ExecuteActionFromReference(action_handle);
        std::this_thread::sleep_for(std::chrono::seconds(20)); // Leave time to action to finish
    }
    
    // Example core
    example_angularActionMovement(pBase);
    example_cartesianActionMovement(pBase);
    example_angularTrajectoryMovement(pBase);
    example_cartesianTrajectoryMovement(pBase);

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
};