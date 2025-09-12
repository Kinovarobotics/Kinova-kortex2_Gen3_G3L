/*
* This code allows a follower robot to mimic the movement of a leader robots.
* Both robots will start at their home position. When the user presses on the wrist buttons of the leader robot,
* the user will be able to freely move the leader robot for a specific duration.
*/

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <api_setup.hpp>

#include <google/protobuf/util/json_util.h>

#if defined(_MSC_VER)
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <time.h>

#include "arm_core_functions.hpp"

namespace k_api = Kinova::Api;

#define PORT 10000
#define PORT_REAL_TIME 10001

#ifndef DURATION
#define DURATION 5             // Default duration (20 seconds) - can be overridden at build time
#endif

float velocity = 20.0f;         // Default velocity of the actuator (degrees per seconds)
float time_duration = DURATION; // Duration of the example (seconds)


void print_position(k_api::BaseCyclic::Feedback base_feedback, int actuator_idx){

    float pos = base_feedback.actuators(actuator_idx).position();
    std::cout << "Position: " << pos << ":" << std::endl;

}

bool button_status(uint32_t flags){

    const uint32_t MASK_BIT_26 = (1U << 26);
    bool is_bit_26_set = (flags & MASK_BIT_26) != 0;

    const uint32_t MASK_BIT_27 = (1U << 27);
    bool is_bit_27_set = (flags & MASK_BIT_27) != 0;

    return is_bit_26_set || is_bit_27_set;

}

void set_positions(k_api::BaseCyclic::Command  base_command, k_api::BaseCyclic::Feedback base_feedback, int nb_actuators){

    for(int i=0; i<nb_actuators;i++){
        base_command.mutable_actuators(i)->set_position(base_feedback.actuators(i).position());
    }
}

bool lead(Robot& leader, Robot& follower)
{

    k_api::Base::BaseClient* base_leader = leader.getBaseClient();
    k_api::BaseCyclic::BaseCyclicClient* base_cyclic_leader = leader.getBaseCyclicClient();
    k_api::ActuatorConfig::ActuatorConfigClient* actuator_config = leader.getActuatorConfig();

    k_api::Base::BaseClient* base_follower = follower.getBaseClient();
    k_api::BaseCyclic::BaseCyclicClient* base_cyclic_follower = follower.getBaseCyclicClient();

    bool return_status = true;

    // Get actuator count
    unsigned int actuator_count = base_leader->GetActuatorCount().count();
    
    // Clearing faults
    try
    {
        base_leader->ClearFaults();
    }
    catch(...)
    {
        std::cout << "Unable to clear robot faults" << std::endl;
        return false;
    }
    
    k_api::BaseCyclic::Feedback base_feedback_leader;
    k_api::BaseCyclic::Command  base_command_leader;

    k_api::BaseCyclic::Feedback base_feedback_follower;
    k_api::BaseCyclic::Command  base_command_follower;

    //std::vector<float> commands;

    auto servoing_mode = k_api::Base::ServoingModeInformation();

    int timer_count = 0;
    int64_t now = 0;
    int64_t last = 0;
    int64_t start_time = GetTickUs();

    std::cout << "Initializing the arm for leader-follower example" << std::endl;
    try
    {
        //Setting up leader: each actuator in low-level mode
        base_command_leader = setup_actuators_low_level(base_leader,base_cyclic_leader,actuator_count);
        base_feedback_leader = base_cyclic_leader->Refresh(base_command_leader);

        //Setting up follower
        base_command_follower = setup_actuators_low_level(base_follower,base_cyclic_follower,actuator_count);
        base_feedback_follower = base_cyclic_follower->Refresh(base_command_follower);
        
        // Set first actuator in torque mode now that the command is equal to measure
        auto control_mode_message = k_api::ActuatorConfig::ControlModeInformation();
        control_mode_message.set_control_mode(k_api::ActuatorConfig::ControlMode::CURRENT);

        //MODIFY THIS VECTOR TO CHOOSE ACTUATORS YOU WANT TO MOVE
        //We are assumming you want to move all of them by default
        std::vector<int> moveable_actuators_id = {1,2,3,4,5,6};

        std::vector<int> moveable_actuators_idx;
        moveable_actuators_idx.reserve(moveable_actuators_id.size());

        std::vector<float> delta_position_leader_follower; //This stores the initial difference in position from leader and follower actuactors
        delta_position_leader_follower.reserve(moveable_actuators_id.size());



        // Setting up inital data and actuator control mode
        
        for (int id : moveable_actuators_id) {
            int idx = id-1;
            moveable_actuators_idx.push_back(idx); // Indexes are -1 from the actuator id

            if(id==6){
                //The last actuator has id=7, while its index is idx=5
                actuator_config->SetControlMode(control_mode_message, id+1);
            }
            else{
                actuator_config->SetControlMode(control_mode_message, id);
            }
            
            
            delta_position_leader_follower.push_back(base_feedback_leader.actuators(idx).position()-base_feedback_follower.actuators(idx).position());
        }
        
        float torque_amplification = 5.0;

        std::cout << "Running leader-follower example for " << time_duration << " seconds" << std::endl;

        // Real-time loop
        while ((GetTickUs() - start_time) < (time_duration * 1000000))
        {
            now = GetTickUs();

            if (now - last > 1000)
            {
                // Position command to first actuator is set to measured one to avoid following error to trigger
                // Bonus: When doing this instead of disabling the following error, if communication is lost and first
                //        actuator continues to move under torque command, resulting position error with command will
                //        trigger a following error and switch back the actuator in position command to hold its position

                for(int i=0;i<moveable_actuators_idx.size();i++){
                    int idx = moveable_actuators_idx.at(i);
                
                    base_command_leader.mutable_actuators(idx)->set_position(base_feedback_leader.actuators(idx).position());
                    base_command_follower.mutable_actuators(idx)->set_position(base_feedback_leader.actuators(idx).position()-delta_position_leader_follower.at(i));
                }

                //Printing position of the first actuator
                //print_position(base_feedback_leader, moveable_actuators_idx.at(0));


                // Incrementing identifier ensures actuators can reject out of time frames
                base_command_leader.set_frame_id(base_command_leader.frame_id() + 1);
                base_command_follower.set_frame_id(base_command_follower.frame_id() + 1);

                if (base_command_leader.frame_id() > 65535)
                    base_command_leader.set_frame_id(0);
                
                if (base_command_follower.frame_id() > 65535)
                    base_command_follower.set_frame_id(0);

                for (int idx = 0; idx < actuator_count; idx++)
                {
                    base_command_leader.mutable_actuators(idx)->set_command_id(base_command_leader.frame_id());
                    base_command_follower.mutable_actuators(idx)->set_command_id(base_command_follower.frame_id());
                }


                try
                {
                    base_feedback_leader = base_cyclic_leader->Refresh(base_command_leader, 0);
                    base_feedback_follower = base_cyclic_follower->Refresh(base_command_follower, 0);
                }
                catch (k_api::KDetailedException& ex)
                {
                    std::cout << "Kortex exception: " << ex.what() << std::endl;

                    std::cout << "Error sub-code: " << k_api::SubErrorCodes_Name(k_api::SubErrorCodes((ex.getErrorInfo().getError().error_sub_code()))) << std::endl;
                }
                catch (std::runtime_error& ex2)
                {
                    std::cout << "runtime error: " << ex2.what() << std::endl;
                }
                catch(...)
                {
                    std::cout << "Unknown error." << std::endl;
                }
                
                timer_count++;
                last = GetTickUs();
            }
        }

        std::cout << "Leader-follower example completed" << std::endl;

        // Set first actuator back in position 
        control_mode_message.set_control_mode(k_api::ActuatorConfig::ControlMode::POSITION);

        for(int id : moveable_actuators_id){
            if(id==6){
                //Actuator #6 has its id set to 7 while its index is 5
                actuator_config->SetControlMode(control_mode_message, id+1);
            }
            else{
                actuator_config->SetControlMode(control_mode_message, id);
            } 
            
        }

        std::cout << "Leader-follower example clean exit" << std::endl;

    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "API error: " << ex.what() << std::endl;
        return_status = false;
    }
    catch (std::runtime_error& ex2)
    {
        std::cout << "Error: " << ex2.what() << std::endl;
        return_status = false;
    }
    
    // Set the servoing mode back to Single Level
    servoing_mode.set_servoing_mode(k_api::Base::ServoingMode::SINGLE_LEVEL_SERVOING);
    base_leader->SetServoingMode(servoing_mode);
    base_follower->SetServoingMode(servoing_mode);

    // Wait for a bit
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    return return_status;
}

bool read_buttons_blocking(Robot& robot, Robot& robot2){

    auto base_cyclic = robot.getBaseCyclicClient();
    auto base = robot.getBaseClient();
    int actuator_count = base->GetActuatorCount().count();
    
    Kinova::Api::BaseCyclic::Feedback base_feedback;
    auto servoing_mode = k_api::Base::ServoingModeInformation();
    auto base_command = k_api::BaseCyclic::Command();

    // Set the base in low-level servoing mode
    servoing_mode.set_servoing_mode(k_api::Base::ServoingMode::LOW_LEVEL_SERVOING);
    base->SetServoingMode(servoing_mode);
    base_feedback = base_cyclic->RefreshFeedback();

    while(true){
        try{

            base_feedback = base_cyclic->RefreshFeedback();
            int32_t flags = base_feedback.interconnect().status_flags();
            if(button_status(flags)){
                std::cerr << "Pressed on button"  << std::endl;
                //ead(robot,robot2);
                return true;
            }

        }
        catch(const std::exception& ex)
        {
                std::cerr << "Error occurred: " << ex.what() << std::endl;
                return false;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    Robot leader = Robot("192.168.1.10","admin","admin");
    Robot follower = Robot("192.168.2.10","admin","admin");
    move_to_home_position(leader.getBaseClient());
    move_to_home_position(follower.getBaseClient());
    read_buttons_blocking(leader,follower);
    lead(leader,follower);

    return 0;
}
