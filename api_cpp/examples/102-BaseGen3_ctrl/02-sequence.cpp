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

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000


void createAngularAction(k_api::Base::Action* action)
{
    std::cout << "\nCreating angular action" << std::endl;

    action->set_name("Example angular action");
    action->set_application_data("");    

    auto reachJointAngles = action->mutable_reach_joint_angles();
    auto jointAngles = reachJointAngles->mutable_joint_angles();

    std::vector<float> angles = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};   
    for(size_t i = 0 ; i < angles.size(); ++i)
    {
        auto jointAngle = jointAngles->add_joint_angles();
        jointAngle->set_joint_identifier(i);
        jointAngle->set_value(angles.at(i));
    }
}


void createCartesianAction(k_api::Base::Action* action)
{
    std::cout << "\nCreating Cartesian action" << std::endl;

    action->set_name("Example Cartesian movement");
    action->set_application_data("");

    auto constrainPose = action->mutable_reach_pose();
    auto pose = constrainPose->mutable_target_pose();
    pose->set_x(0.8);           // x (meters)
    pose->set_y(0.0);           // y (meters)
    pose->set_z(0.36);          // z (meters)
    pose->set_theta_x(10.0);    // theta x (degrees)
    pose->set_theta_y(90.0);    // theta y (degrees)
    pose->set_theta_z(10.0);    // theta z (degrees)
}


void example_createSequence(k_api::Base::BaseClient* pBase)
{
    std::cout << "\nCreating Sequence" << std::endl;

    auto sequence = k_api::Base::Sequence();
    sequence.set_name("Example sequence");
    
    std::cout << "Appending Actions to Sequence" << std::endl;
    auto task_1 = sequence.add_tasks();
    task_1->set_group_identifier(0);
    createAngularAction(task_1->mutable_action());
    
    auto task_2 = sequence.add_tasks();
    task_2->set_group_identifier(1); // sequence elements with same group_id are played at the same time
    createCartesianAction(task_2->mutable_action());

    std::cout << "Creating sequence on device and executing it" << std::endl;
    auto sequenceHandle = pBase->CreateSequence(sequence);
    pBase->PlaySequence(sequenceHandle);

    std::cout << "Waiting 30 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(30000)); // (milliseconds)

    std::cout << "Sequence completed" << std::endl;
}


int main(int argc, char **argv)
{
    // Setup API
    auto errorCallback =  [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); };
    auto pTransport = new k_api::TransportClientUdp();
    auto pRouter = new k_api::RouterClient(pTransport, errorCallback);
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
    example_createSequence(pBase);

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