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

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
#define PORT 10000

/*****************************
 * Example related functions *
 *****************************/
void create_angular_action(k_api::Base::Action* action)
{
    std::cout << "Creating angular action" << std::endl;

    action->set_name("Example angular action");
    action->set_application_data("");    

    auto reach_joint_angles = action->mutable_reach_joint_angles();
    auto joint_angles = reach_joint_angles->mutable_joint_angles();

    std::vector<float> angles = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};   
    for(size_t i = 0 ; i < angles.size(); ++i)
    {
        auto joint_angle = joint_angles->add_joint_angles();
        joint_angle->set_joint_identifier(i);
        joint_angle->set_value(angles.at(i));
    }
}

void create_cartesian_action(k_api::Base::Action* action)
{
    std::cout << "Creating Cartesian action" << std::endl;

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

/**************************
 * Example core functions *
 **************************/
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

void example_create_sequence(k_api::Base::BaseClient* pBase)
{
    std::cout << "Creating Sequence" << std::endl;

    auto sequence = k_api::Base::Sequence();
    sequence.set_name("Example sequence");
    
    std::cout << "Appending Actions to Sequence" << std::endl;
    auto task_1 = sequence.add_tasks();
    task_1->set_group_identifier(0);
    create_angular_action(task_1->mutable_action());
    
    auto task_2 = sequence.add_tasks();
    task_2->set_group_identifier(1); // sequence elements with same group_id are played at the same time
    create_cartesian_action(task_2->mutable_action());

    std::cout << "Creating sequence on device and executing it" << std::endl;
    auto sequenceHandle = pBase->CreateSequence(sequence);
    pBase->PlaySequence(sequenceHandle);

    std::cout << "Waiting 30 seconds for movement to finish ..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(30000)); // (milliseconds)

    std::cout << "Sequence completed" << std::endl;
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
    example_create_sequence(base);

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