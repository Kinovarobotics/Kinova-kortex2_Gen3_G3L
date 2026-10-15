#include "arm_core_functions.hpp"

namespace k_api = Kinova::Api;

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

int64_t GetTickUs()
{
#if defined(_MSC_VER)
    LARGE_INTEGER start, frequency;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    return (start.QuadPart * 1000000)/frequency.QuadPart;
#else
    struct timespec start;
    clock_gettime(CLOCK_MONOTONIC, &start);
    
    return (start.tv_sec * 1000000LLU) + (start.tv_nsec / 1000);
#endif
}

/**************************
 * Example core functions *
 **************************/
void move_to_home_position(k_api::Base::BaseClient* base)
{
    move_to_named_position(base, "Home");
}

// Moves the arm to one of its predefined joint angle actions (e.g. "Home", "Retract")
void move_to_named_position(k_api::Base::BaseClient* base, const std::string& position_name)
{
    // Make sure the arm is in Single Level Servoing before executing an Action
    auto servoingMode = k_api::Base::ServoingModeInformation();
    servoingMode.set_servoing_mode(k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);
    base->SetServoingMode(servoingMode);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Move arm to ready position
    std::cout << "Moving the arm to the \"" << position_name << "\" position" << std::endl;
    auto action_type = k_api::Base::RequestedActionType();
    action_type.set_action_type(k_api::Base::REACH_JOINT_ANGLES);
    auto action_list = base->ReadAllActions(action_type);
    auto action_handle = k_api::Base::ActionHandle();
    action_handle.set_identifier(0);
    for (auto action : action_list.action_list()) 
    {
        if (action.name() == position_name) 
        {
            action_handle = action.handle();
        }
    }

    if (action_handle.identifier() == 0) 
    {
        std::cout << "Can't find the \"" << position_name << "\" position, exiting" << std::endl;
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

        while(!action_finished)
        { 
            std::this_thread::sleep_for(ACTION_WAITING_TIME);
        }

        base->Unsubscribe(notification_handle);
    }
}

//Puts base in low-level servoing mode and initialize actuators to their current position to avoid fllowing errors
k_api::BaseCyclic::Command setup_actuators_low_level(k_api::Base::BaseClient* base, k_api::BaseCyclic::BaseCyclicClient* base_cyclic, int actuator_count){

    auto servoing_mode = k_api::Base::ServoingModeInformation();
    auto base_command = k_api::BaseCyclic::Command();
    auto base_feedback = k_api::BaseCyclic::Feedback();

    // Set the base in low-level servoing mode
    servoing_mode.set_servoing_mode(k_api::Base::ServoingMode::LOW_LEVEL_SERVOING);
    base->SetServoingMode(servoing_mode);
    base_feedback = base_cyclic->RefreshFeedback();

    // Initialize each actuator to their current position
    for (unsigned int i = 0; i < actuator_count; i++)
    {
        base_command.add_actuators()->set_position(base_feedback.actuators(i).position());
    }

    std::cout << "Done with setup actuators low level" << std::endl;

    // Send a first frame
    return base_command;

}

// Wraps an angle difference (degrees) to [-180, 180) so that 359.9 - 0.1 gives -0.2 and not 359.8
float wrap_angle_180(float angle)
{
    angle = fmod(angle + 180.0f, 360.0f);
    if (angle < 0.0f)
        angle += 360.0f;
    return angle - 180.0f;
}

// Wraps an angle (degrees) to [0, 360), the range expected by the actuator position command
float wrap_angle_360(float angle)
{
    angle = fmod(angle, 360.0f);
    if (angle < 0.0f)
        angle += 360.0f;
    return angle;
}

// Moves the angle current (degrees) towards target by at most max_step, through the shortest way around the circle
float step_towards_angle(float current, float target, float max_step)
{
    float delta = wrap_angle_180(target - current);
    delta = std::max(-max_step, std::min(max_step, delta));
    return wrap_angle_360(current + delta);
}

// Runs one cyclic Refresh call of the real-time loop. Errors (e.g. a lost UDP packet) are printed instead of thrown
// so the loop keeps going. Returns false if the call failed
bool try_cyclic_call(const char* arm_name, const std::function<void()>& call)
{
    try
    {
        call();
        return true;
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << arm_name << " Kortex exception: " << ex.what() << std::endl;
        std::cout << "Error sub-code: " << k_api::SubErrorCodes_Name(k_api::SubErrorCodes((ex.getErrorInfo().getError().error_sub_code()))) << std::endl;
    }
    catch (std::runtime_error& ex2)
    {
        std::cout << arm_name << " runtime error: " << ex2.what() << std::endl;
    }
    catch(...)
    {
        std::cout << arm_name << " unknown error." << std::endl;
    }
    return false;
}
