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

namespace k_api = Kinova::Api;

#define IP_ADDRESS "192.168.1.10"
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

// Create an event listener that will set the promise action event to the exit value
// Will set promise to either END or ABORT
// Use finish_promise.get_future.get() to wait and get the value
std::function<void(k_api::Base::ActionNotification)>
create_event_listener_by_promise(std::promise<k_api::Base::ActionEvent>& finish_promise)
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

// Create an event listener that will set the sent reference to the exit value
// Will set to either END or ABORT
// Read the value of returnAction until it is set
std::function<void(k_api::Base::ActionNotification)>
create_event_listener_by_ref(k_api::Base::ActionEvent& returnAction)
{
    return [&returnAction](k_api::Base::ActionNotification notification)
    {
        const auto action_event = notification.action_event();
        switch(action_event)
        {
            case k_api::Base::ActionEvent::ACTION_END:
            case k_api::Base::ActionEvent::ACTION_ABORT:
                returnAction = action_event;
                break;
            default:
                break;
        }
    };
}

void create_angular_action(k_api::Base::Action* action, int actuator_count)
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

bool example_angular_action_movement(k_api::Base::BaseClient* base)
{
    std::cout << "Starting angular action movement ..." << std::endl;

    auto action = k_api::Base::Action();
    create_angular_action(&action, base->GetActuatorCount().count());

    // Connect to notification action topic
    // (Promise alternative)
    // See cartesian examples for Reference alternative
    std::promise<k_api::Base::ActionEvent> finish_promise;
    auto finish_future = finish_promise.get_future();
    auto promise_notification_handle = base->OnNotificationActionTopic(
            create_event_listener_by_promise(finish_promise),
            k_api::Common::NotificationOptions()
    );

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);
    //base->PlayJointTrajectory(constrained_joint_angles);

    std::cout << "Waiting for movement to finish ..." << std::endl;

    // Wait for future value from promise
    // (Promise alternative)
    // See cartesian examples for Reference alternative
    const auto status = finish_future.wait_for(TIMEOUT_DURATION);
    base->Unsubscribe(promise_notification_handle);

    if(status != std::future_status::ready)
    {
        std::cout << "Timeout on action notification wait" << std::endl;
        return false;
    }
    const auto promise_event = finish_future.get();

    std::cout << "Angular movement completed" << std::endl;
    std::cout << "Promise value : " << k_api::Base::ActionEvent_Name(promise_event) << std::endl;

    return true;
}

bool example_cartesian_action_movement(k_api::Base::BaseClient* base, k_api::BaseCyclic::BaseCyclicClient* base_cyclic)
{
    std::cout << "Starting Cartesian action movement ..." << std::endl;

    auto action = k_api::Base::Action();
    create_cartesian_action(&action, base_cyclic);

    // Connect to notification action topic
    // (Reference alternative)
    // See angular examples for Promise alternative
    k_api::Base::ActionEvent event = k_api::Base::ActionEvent::UNSPECIFIED_ACTION_EVENT;
    auto reference_notification_handle = base->OnNotificationActionTopic(
            create_event_listener_by_ref(event),
            k_api::Common::NotificationOptions()
    );

    std::cout << "Executing action" << std::endl;
    base->ExecuteAction(action);
    //base->PlayCartesianTrajectory(constrained_pose);

    std::cout << "Waiting for movement to finish ..." << std::endl;

    // Wait for reference value to be set
    // (Reference alternative)
    // See angular examples for Promise alternative
    // Set a timeout after 20s of wait
    const auto timeout = std::chrono::system_clock::now() + TIMEOUT_DURATION;
    while(event == k_api::Base::ActionEvent::UNSPECIFIED_ACTION_EVENT &&
          std::chrono::system_clock::now() < timeout)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    base->Unsubscribe(reference_notification_handle);

    if(event == k_api::Base::ActionEvent::UNSPECIFIED_ACTION_EVENT)
    {
        std::cout << "Timeout on action notification wait" << std::endl;
        return false;
    }

    std::cout << "Cartesian movement completed" << std::endl;
    std::cout << "Reference value : " << k_api::Base::ActionEvent_Name(event) << std::endl;

    return true;
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

bool example_twist_command(k_api::Base::BaseClient* base)
{
    auto command = k_api::Base::TwistCommand();
    command.set_reference_frame(k_api::Common::CARTESIAN_REFERENCE_FRAME_TOOL);
    command.set_duration(0);  // Unlimited time to execute

    std::cout << "Sending twist command for 5 seconds..." << std::endl;

    auto twist = command.mutable_twist();
    twist->set_linear_x(0.0f);
    twist->set_linear_y(0.03f);
    twist->set_linear_z(0.00f);
    twist->set_angular_x(0.0f);
    twist->set_angular_y(0.0f);
    twist->set_angular_z(5.0f);
    base->SendTwistCommand(command);

    // Let time for twist to be executed
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    std::cout << "Stopping robot ..." << std::endl;

    // Make movement stop
    base->Stop();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return true;
}

bool example_send_joint_speeds(k_api::Base::BaseClient* base)
{
    std::cout << "Sending the angular velocities to the robot for 10 seconds..." << std::endl;
    const float SPEED = 20.0f;
    k_api::Base::JointSpeeds joint_speeds;

    std::vector<float> speeds;

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

    // Stop the robot
    std::cout << "Stopping the robot" << std::endl;
    base->Stop();

    return true;
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
    auto base_cyclic = new k_api::BaseCyclic::BaseCyclicClient(router);

    // Example core
    bool success = true;
    success &= example_move_to_home_position(base);
    success &= example_cartesian_action_movement(base, base_cyclic);
    success &= example_angular_action_movement(base);
    success &= example_move_to_home_position(base);
    success &= example_create_sequence(base, base_cyclic);
    success &= example_move_to_home_position(base);
    success &= example_twist_command(base);
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
}