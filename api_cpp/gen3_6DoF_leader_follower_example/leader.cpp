/*
* This code allows a follower to move to a specified position
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
#include <csignal>
#include <algorithm>

#include "arm_core_functions.hpp"

namespace k_api = Kinova::Api;

#define PORT 10000
#define PORT_REAL_TIME 10001

#ifndef DURATION
#define DURATION 0              // Duration of the example (seconds), 0 = run until Ctrl+C
#endif

float velocity = 20.0f;         // Default velocity of the actuator (degrees per seconds)
float time_duration = DURATION; // Duration of the example (seconds)

// Follower gripper control (same proportional loop as the 107-Gripper_low_level_command example)
const float GRIPPER_PROPORTIONAL_GAIN = 5.0f;      // Gripper velocity (%) per % of position error
const float GRIPPER_MINIMAL_POSITION_ERROR = 1.5f; // Position error (%) under which the gripper stops

// Set by Ctrl+C so the loop exits and the actuators are put back in position mode
volatile std::sig_atomic_t stop_requested = 0;

void handle_sigint(int)
{
    stop_requested = 1;
}


void print_position(k_api::BaseCyclic::Feedback base_feedback, int actuator_idx){

    float pos = base_feedback.actuators(actuator_idx).position();
    std::cout << "Position: " << pos << ":" << std::endl;

}

void set_positions(k_api::BaseCyclic::Command  base_command, k_api::BaseCyclic::Feedback base_feedback, int nb_actuators){

    for(int i=0; i<nb_actuators;i++){
        base_command.mutable_actuators(i)->set_position(base_feedback.actuators(i).position());
    }
}

bool lead(Robot& leader, Robot& follower, unsigned int dof)
{

    k_api::Base::BaseClient* base_leader = leader.getBaseClient();
    k_api::BaseCyclic::BaseCyclicClient* base_cyclic_leader = leader.getBaseCyclicClient();

    k_api::Base::BaseClient* base_follower = follower.getBaseClient();
    k_api::BaseCyclic::BaseCyclicClient* base_cyclic_follower = follower.getBaseCyclicClient();

    bool return_status = true;

    // Get actuator count
    unsigned int actuator_count_leader = base_leader->GetActuatorCount().count();
    unsigned int actuator_count_follower = base_follower->GetActuatorCount().count();
    // Both arms must have the number of joints passed with --dof
    if (actuator_count_leader != dof || actuator_count_follower != dof)
    {
        std::cout << "Expected two arms with " << dof << " actuators, found " << actuator_count_leader
                  << " on the leader and " << actuator_count_follower << " on the follower" << std::endl;
        return false;
    }

    move_to_named_position(base_leader, "Retract");
    move_to_named_position(base_follower, "Retract");

    // Clearing faults
    try
    {
        base_leader->ClearFaults();
        base_follower->ClearFaults();
    }
    catch(...)
    {
        std::cout << "Unable to clear robot faults" << std::endl;
        return false;
    }

    k_api::BaseCyclic::Feedback base_feedback_leader;

    k_api::BaseCyclic::Feedback base_feedback_follower;
    k_api::BaseCyclic::Command  base_command_follower;

    auto servoing_mode = k_api::Base::ServoingModeInformation();

    // The leader is hand guided in cartesian admittance mode: the robot compensates gravity and
    // moves its end effector following the forces applied by the user. It stays in single level servoing.
    auto admittance = k_api::Base::Admittance();

    int timer_count = 0;
    int64_t now = 0;
    int64_t last = 0;
    int64_t start_time = GetTickUs();

    std::cout << "Initializing the arms for leader-follower example" << std::endl;
    try
    {
        //Setting up leader: only its feedback is read, it is commanded by the user's hand
        base_feedback_leader = base_cyclic_leader->RefreshFeedback();
        std::cout << "Done leader" << std::endl;
        //Setting up follower: each actuator in low-level position mode
        base_command_follower = setup_actuators_low_level(base_follower,base_cyclic_follower,actuator_count_follower);
        base_feedback_follower = base_cyclic_follower->Refresh(base_command_follower);
        std::cout << "Done follower" << std::endl;

        // The leader gripper is opened/closed by the user with the wrist button mapping of the leader arm.
        // The follower gripper is commanded in low level to follow the leader gripper position (0 = open, 100 = closed).
        k_api::GripperCyclic::MotorCommand* gripper_command_follower = nullptr;
        bool mirror_gripper = base_feedback_leader.interconnect().gripper_feedback().motor_size() > 0
                           && base_feedback_follower.interconnect().gripper_feedback().motor_size() > 0;
        if (mirror_gripper)
        {
            base_command_follower.mutable_interconnect()->mutable_command_id()->set_identifier(0);
            gripper_command_follower = base_command_follower.mutable_interconnect()->mutable_gripper_command()->add_motor_cmd();
            gripper_command_follower->set_position(base_feedback_follower.interconnect().gripper_feedback().motor(0).position());
            gripper_command_follower->set_velocity(0.0);
            gripper_command_follower->set_force(100.0);
            std::cout << "Grippers found on both arms, the follower gripper will follow the leader gripper" << std::endl;
        }
        else
        {
            std::cout << "No gripper found on the leader and/or the follower, the grippers will not be mirrored" << std::endl;
        }

        //MODIFY THIS VECTOR TO CHOOSE ACTUATORS YOU WANT TO MOVE
        //We are assumming you want to move all of them by default
        std::vector<int> moveable_actuators_id;
        for (unsigned int id = 1; id <= dof; id++)
            moveable_actuators_id.push_back(id);
        //std::vector<int> moveable_actuators_id = {1,2,4};

        std::vector<int> moveable_actuators_idx;
        moveable_actuators_idx.reserve(moveable_actuators_id.size());

        std::vector<float> delta_position_leader_follower; //This stores the initial difference in position from leader and follower actuactors
        delta_position_leader_follower.reserve(moveable_actuators_id.size());

        // Setting up inital data

        for (int id : moveable_actuators_id) {
            int idx = id-1;
            moveable_actuators_idx.push_back(idx); // Indexes are -1 from the actuator id

            if (idx >= base_feedback_leader.actuators_size()) {
                std::cerr << "Error: idx " << idx << " is out of bounds for base_feedback_leader.actuators (size: " << base_feedback_leader.actuators_size() << ")" << std::endl;

            }
            if (idx >= base_feedback_follower.actuators_size()) {
                std::cerr << "Error: idx " << idx << " is out of bounds for base_feedback_follower.actuators (size: " << base_feedback_follower.actuators_size() << ")" << std::endl;

            }


            delta_position_leader_follower.push_back(wrap_angle_180(base_feedback_leader.actuators(idx).position()-base_feedback_follower.actuators(idx).position()));
            std::cout << "Joint " << id << " leader-follower offset: " << delta_position_leader_follower.back() << " deg" << std::endl;
        }

        // Put the leader in cartesian admittance (hand guiding) mode
        admittance.set_admittance_mode(k_api::Base::AdmittanceMode::CARTESIAN);
        base_leader->SetAdmittance(admittance);

        if (time_duration > 0)
            std::cout << "Running leader-follower example for " << time_duration << " seconds (Ctrl+C to stop early)" << std::endl;
        else
            std::cout << "Running leader-follower example until Ctrl+C is pressed" << std::endl;

        std::signal(SIGINT, handle_sigint);

        // Real-time loop
        while (!stop_requested && (time_duration <= 0 || (GetTickUs() - start_time) < (time_duration * 1000000)))
        {
            now = GetTickUs();

            if (now - last > 1000)
            {
                for(int i=0;i<moveable_actuators_idx.size();i++){
                    int idx = moveable_actuators_idx.at(i);

                    base_command_follower.mutable_actuators(idx)->set_position(wrap_angle_360(base_feedback_leader.actuators(idx).position()-delta_position_leader_follower.at(i)));
                }

                if (mirror_gripper)
                {
                    float target_position = base_feedback_leader.interconnect().gripper_feedback().motor(0).position();
                    float position_error = target_position - base_feedback_follower.interconnect().gripper_feedback().motor(0).position();
                    float gripper_velocity = 0.0f;
                    if (fabs(position_error) >= GRIPPER_MINIMAL_POSITION_ERROR)
                        gripper_velocity = std::min(100.0f, GRIPPER_PROPORTIONAL_GAIN * (float)fabs(position_error));

                    gripper_command_follower->set_position(target_position);
                    gripper_command_follower->set_velocity(gripper_velocity);
                }

                //Printing position of the first actuator
                print_position(base_feedback_leader, moveable_actuators_idx.at(0));


                // Incrementing identifier ensures actuators can reject out of time frames
                base_command_follower.set_frame_id(base_command_follower.frame_id() + 1);

                if (base_command_follower.frame_id() > 65535)
                    base_command_follower.set_frame_id(0);

                for(int idx = 0; idx < actuator_count_follower; idx++){

                    base_command_follower.mutable_actuators(idx)->set_command_id(base_command_follower.frame_id());

                }


                try
                {
                    base_feedback_leader = base_cyclic_leader->RefreshFeedback();
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

        // Stop the follower gripper where it is
        if (mirror_gripper)
        {
            gripper_command_follower->set_position(base_feedback_follower.interconnect().gripper_feedback().motor(0).position());
            gripper_command_follower->set_velocity(0.0);
            base_cyclic_follower->Refresh(base_command_follower);
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

    // Take the leader out of admittance mode so it holds its position again
    try
    {
        admittance.set_admittance_mode(k_api::Base::AdmittanceMode::DISABLED);
        base_leader->SetAdmittance(admittance);
    }
    catch (k_api::KDetailedException& ex)
    {
        std::cout << "Unable to disable leader admittance: " << ex.what() << std::endl;
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

void print_usage(const char* program_name)
{
    std::cout << "Usage: " << program_name << " [--dof 6|7]" << std::endl;
    std::cout << "  --dof   number of joints of the Gen3 arms (default: 7)" << std::endl;
}

int main(int argc, char const *argv[])
{
    // Number of joints of both arms (Gen3 6DoF or 7DoF)
    unsigned int dof = 7;
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        std::string value;
        if (arg == "-h" || arg == "--help")
        {
            print_usage(argv[0]);
            return 0;
        }
        else if (arg == "--dof" && i + 1 < argc)
            value = argv[++i];
        else if (arg.rfind("--dof=", 0) == 0)
            value = arg.substr(6);
        else
        {
            print_usage(argv[0]);
            return 1;
        }

        if (value == "6")
            dof = 6;
        else if (value == "7")
            dof = 7;
        else
        {
            std::cout << "Invalid --dof value \"" << value << "\", expected 6 or 7" << std::endl;
            return 1;
        }
    }
    std::cout << "Running with two Gen3 " << dof << "DoF arms" << std::endl;

    Robot leader = Robot("192.168.1.10","admin","admin");
    Robot follower = Robot("192.168.2.10","admin","admin");
    
    auto isOk = lead(leader,follower,dof);
    if (!isOk)
    {
        std::cout << "There has been an unexpected error in lead function." << std::endl;
    }
    return 0;
}
