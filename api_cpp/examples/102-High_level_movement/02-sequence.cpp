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
#include <BaseCyclicClientRpc.h>
#include <SessionManager.h>

#include <RouterClient.h>
#include <TransportClientTcp.h>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

// Maximum allowed waiting time during actions
constexpr auto TIMEOUT_DURATION = std::chrono::seconds(20);

/*****************************
 * Example related functions *
 *****************************/

// Create an event listener that will set the promise action event to the exit value
// Will set to either END or ABORT
// Use finish_promise.get_future.get() to wait and get the value
std::function<void(k_api::Base::SequenceInfoNotification)> 
    create_sequence_event_listener_by_promise(std::promise<k_api::Base::EventIdSequenceInfoNotification>& finish_promise)
{
    return [&finish_promise] (k_api::Base::SequenceInfoNotification notification)
    {
        const auto action_event = notification.event_identifier();
        
        switch(action_event)
        {
        case k_api::Base::EventIdSequenceInfoNotification::SEQUENCE_TASK_COMPLETED:
            std::cout << "Sequence task " << notification.task_index() << " completed." << std::endl;
            break;
        case k_api::Base::EventIdSequenceInfoNotification::SEQUENCE_ABORTED:
            std::cout << "Sequence aborted with error " << notification.abort_details() << ": " 
                << k_api::SubErrorCodes_Name(notification.abort_details()) << "." << std::endl;
            finish_promise.set_value(action_event);
            break;
        case k_api::Base::EventIdSequenceInfoNotification::SEQUENCE_COMPLETED:
            std::cout << "Sequence completed." << std::endl; 
            finish_promise.set_value(action_event);
            break;
        default:
            break;
        }
    
    };
}

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

void create_angular_action(k_api::Base::Action* action, unsigned int actuator_count)
{
    std::cout << "Creating angular action" << std::endl;

    action->set_name("Example angular action");
    action->set_application_data("");    

    auto reach_joint_angles = action->mutable_reach_joint_angles();
    auto joint_angles = reach_joint_angles->mutable_joint_angles();

    // Arm straight up
    for(size_t i = 0 ; i < actuator_count; ++i)
    {
        auto joint_angle = joint_angles->add_joint_angles();
        joint_angle->set_joint_identifier(i);
        joint_angle->set_value(0.0f);
    }
}

void create_cartesian_action(k_api::Base::Action* action, k_api::BaseCyclic::BaseCyclicClient* base_cyclic)
{
    std::cout << "Creating Cartesian action" << std::endl;

    action->set_name("Example Cartesian movement");
    action->set_application_data("");

    auto constrainPose = action->mutable_reach_pose();
    auto pose = constrainPose->mutable_target_pose();
    auto feedback = base_cyclic->RefreshFeedback();
    pose->set_x(feedback.base().tool_pose_x());                // x (meters)
    pose->set_y(feedback.base().tool_pose_y() - 0.1);          // y (meters)
    pose->set_z(feedback.base().tool_pose_z() - 0.2);          // z (meters)
    pose->set_theta_x(feedback.base().tool_pose_theta_x());    // theta x (degrees)
    pose->set_theta_y(feedback.base().tool_pose_theta_y());    // theta y (degrees)
    pose->set_theta_z(feedback.base().tool_pose_theta_z());    // theta z (degrees)
}

/**************************
 * Example core functions *
 **************************/
bool example_move_to_home_position(k_api::Base::BaseClient* base)
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
        // Connect to notification action topic
        std::promise<k_api::Base::ActionEvent> promise;
        auto future = promise.get_future();
        const auto notification_handle = base->OnNotificationActionTopic(
            create_action_event_listener_by_promise(promise),
            k_api::Common::NotificationOptions{}
        );

        base->ExecuteActionFromReference(action_handle);
        
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
}

bool example_create_sequence(k_api::Base::BaseClient* base, k_api::BaseCyclic::BaseCyclicClient* base_cyclic)
{
    std::cout << "Creating Sequence" << std::endl;

    auto sequence = k_api::Base::Sequence();
    sequence.set_name("Example sequence");
    
    std::cout << "Appending Actions to Sequence" << std::endl;
    auto task_1 = sequence.add_tasks();
    task_1->set_group_identifier(1); // sequence elements with same group_id are played at the same time
    create_cartesian_action(task_1->mutable_action(), base_cyclic);

    auto task_2 = sequence.add_tasks();
    task_2->set_group_identifier(0);
    create_angular_action(task_2->mutable_action(), base->GetActuatorCount().count());
    
    // Connect to sequence notification
    std::promise<k_api::Base::EventIdSequenceInfoNotification> promise;
    auto future = promise.get_future();
    auto notification_handle = base->OnNotificationSequenceInfoTopic(
        create_sequence_event_listener_by_promise(promise),
        k_api::Common::NotificationOptions()
    );

    std::cout << "Creating sequence on device and executing it" << std::endl;
    auto sequenceHandle = base->CreateSequence(sequence);
    base->PlaySequence(sequenceHandle);

    std::cout << "Waiting for sequence to finish ..." << std::endl;
    const auto status = future.wait_for(TIMEOUT_DURATION);
    base->Unsubscribe(notification_handle);

    if(status != std::future_status::ready)
    {
        std::cout << "Timeout on action notification wait" << std::endl;
        return false;
    }   
    auto event = future.get();

    std::cout << "Promise value : " << k_api::Base::EventIdSequenceInfoNotification_Name(event) << std::endl; 

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
    auto base_cyclic = new k_api::BaseCyclic::BaseCyclicClient(router);
    
    // Example core
    bool success = true;
    success &= example_move_to_home_position(base);
    success &= example_create_sequence(base, base_cyclic);

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
}