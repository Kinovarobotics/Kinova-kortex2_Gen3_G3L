/*
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2019 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
*/

/*
* 107-Gen3_gripper_low_level_command/01-gripper_low_level_command.cpp
*
* Low level servoing example for the GEN3's end effector (using Robotiq's
* 2-Finger 85)
*
* ABSTRACT:
* =========
* On GEN3, gripper cyclic commands have 3 parameters used to control gripper
* motion : position, velocity and force.
*
* These 3 parameters are always sent together and cannot be used independently.
* Each parameter has absolute percentage values and their range are from 0% to
* 100%.
*
* For gripper position, 0% is fully opened and 100% is fully closed.
* For gripper speed, 0% is fully stopped and 100% is opening/closing (depending on
* position used) at maximum speed.
* Force parameter is used as a force limit to apply when closing or opening
* the gripper. If this force limit is exceeded the gripper motion will stop.
* 0% is the lowest force limit and 100% the maximum.
*
* DESCRIPTION OF CURRENT EXAMPLE:
* ===============================
* In this example, 10 successive positions are sent to the gripper with a
* pause of 1 second between each position. It starts at fully opened position
* (0%) to end up at fully closed position (100%). All positions are spread
* evenly over the 0%-100%, having a positional increment of 10% each
* iteration.
*
* To control the gripper, cyclic commands are sent directly to the end effector
* to achieve position control.
*
* A simple proportional feedback loop is used to illustrate how feedback can be
* obtained and used with Kortex API.
*
* This loop modulates the speed sent to the gripper.
*/

#include <BaseClientRpc.h>
#include <BaseCyclicClientRpc.h>

#include <InterconnectConfigClientRpc.h>
#include <SessionManager.h>
#include <DeviceManagerClientRpc.h>
#include <RouterClient.h>
#include <TransportClientTcp.h>
#include <TransportClientUdp.h>

#include <thread>
#include <iostream>
#include <chrono>
#include <future>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000
#define PORT_REAL_TIME 10001

#define PROPORTIONAL_GAIN (2.2f)

#define MINIMAL_POSITION_ERROR  ((float)1.5)

///////////////////////////////////////////////////////////////////////
// class GripperLowLevel
//
// Implements methods for controlling the Gripper with low-level 
// cyclic commands.
///////////////////////////////////////////////////////////////////////
class GripperLowLevel
{
public:
    GripperLowLevel(const std::string& ip_address, int port_real_time , int port, const std::string& username = "admin", const std::string& password = "admin"):
    m_ip_address(ip_address), m_port(port), m_port_real_time(port_real_time), m_username(username), m_password(password), m_proportional_gain(0.0)
    {
        m_router                    = nullptr;
        m_router_real_time          = nullptr;
        m_transport                 = nullptr;
        m_transport_real_time       = nullptr;
        m_session_manager           = nullptr;
        m_session_manager_real_time = nullptr;
        m_base                      = nullptr;
        m_base_cyclic               = nullptr;
    }

    ~GripperLowLevel()
    {
        // Restore servoing mode.
        if (m_base)
        {
            m_base->SetServoingMode(m_previous_servoing_mode);
        }
        
        // Close API sessions
        if (m_session_manager)
        {
            m_session_manager->CloseSession();
        }
        if (m_session_manager_real_time)
        {
            m_session_manager_real_time->CloseSession();
        }

        // Deactivate the router and cleanly disconnect from the transport object
        m_router->SetActivationStatus(false);
        m_transport->disconnect();
        m_router_real_time->SetActivationStatus(false);
        m_transport_real_time->disconnect();

        // Destroy the API
        delete m_base;
        delete m_base_cyclic;
        delete m_session_manager;
        delete m_session_manager_real_time;
        delete m_router;
        delete m_router_real_time;
        delete m_transport;
        delete m_transport_real_time;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // void Init(float proportional_gain = 2.0)
    //
    //      Initializes gripper object. Connection is made to the base using credentials given at object's
    //      construction.
    // INPUT:
    //      float fProportionnal:   Proportional gain to be used when using the position loop (default value = 2.0)
    //
    // OUTPUT:
    //      None.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Init(float proportional_gain = 2.0)
    {
        m_proportional_gain = proportional_gain;

        ///////////////////////////////////////////////////////////////////////////////////////////
        // UDP and TCP sessions are used in this example.
        // TCP is used to perform the change of servoing mode
        // UDP is used for cyclic commands.
        //
        // 2 sessions have to be created: 1 for TCP and 1 for UDP
        ///////////////////////////////////////////////////////////////////////////////////////////

        // TCP transport and router
        m_transport = new k_api::TransportClientTcp();
        m_transport->connect(m_ip_address, m_port);
        m_router = new k_api::RouterClient(m_transport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

        // UDP transport and router
        m_transport_real_time = new k_api::TransportClientUdp();
        m_transport_real_time->connect(m_ip_address, m_port_real_time);
        m_router_real_time = new k_api::RouterClient(m_transport_real_time, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

        // Set session data connection information
        auto createSessionInfo = k_api::Session::CreateSessionInfo();
        createSessionInfo.set_username(m_username);
        createSessionInfo.set_password(m_password);
        createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
        createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

        std::cout << "Creating sessions for communication" << std::endl;

        // Session manager service wrapper
        m_session_manager = new k_api::SessionManager(m_router);
        m_session_manager->CreateSession(createSessionInfo);

        m_session_manager_real_time = new k_api::SessionManager(m_router_real_time);
        m_session_manager_real_time->CreateSession(createSessionInfo);

        // Although TCP can be used, it is best to use UDP router for cyclic
        m_base_cyclic = new k_api::BaseCyclic::BaseCyclicClient(m_router_real_time);

        // Base client can only be operated on a TCP connection
        m_base = new k_api::Base::BaseClient(m_router);

        // Get previous servoing mode
        m_previous_servoing_mode = m_base->GetServoingMode();

        // Set arm in low level servoing mode
        k_api::Base::ServoingModeInformation servoing_info;
        servoing_info.set_servoing_mode(k_api::Base::LOW_LEVEL_SERVOING);
        m_base->SetServoingMode(servoing_info);

        // Get the feedback from the robot
        k_api::BaseCyclic::Feedback base_feedback;
        base_feedback = m_base_cyclic->RefreshFeedback();

        // This is how to get the gripper's actual position from the base feedback
        float gripper_initial_position = base_feedback.interconnect().gripper_feedback().motor()[0].position();

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Initialize actuator commands to current position.
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        for (auto actuator : base_feedback.actuators())
        {
            k_api::BaseCyclic::ActuatorCommand* actuator_command;
            actuator_command = m_base_command.mutable_actuators()->Add();
            actuator_command->set_position(actuator.position());
            actuator_command->set_velocity(0.0);
            actuator_command->set_torque_joint(0.0);
            actuator_command->set_command_id(0);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // Initialize interconnect command to current gripper position.
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        m_base_command.mutable_interconnect()->mutable_command_id()->set_identifier(0);

        m_gripper_motor_command = m_base_command.mutable_interconnect()->mutable_gripper_command()->add_motor_cmd();
        m_gripper_motor_command->set_position(gripper_initial_position );
        m_gripper_motor_command->set_velocity(0.0);
        m_gripper_motor_command->set_force(100.0);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // void GoTo(float target_position)
    //
    //      Sends the gripper to a target position using a feed back loop made with base cyclic command.
    //      The method blocks until position is reached.
    //      The feedback loop used is a simple proportional loop.
    // INPUT:
    //      float target_position:  Target gripper position in percent (100.0 = fully closed, 0.0 = fully open)
    //
    // OUTPUT:
    //      Returns true if operation completed successfully, false otherwise.
    //
    // NOTES:
    //      - This method blocks until the requested position is reached.
    //      - If target position exceeds 100.0, its value is changed to 100.0.
    //      - If target position is below 0.0, its value is set to 0.0.
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    bool GoTo(float target_position)
    {
        k_api::BaseCyclic::Feedback base_feedback;
        float position_error;
        if (target_position > 100.0)
        {
            target_position = 100.0;
        }
        if (target_position < 0.0)
        {
            target_position = 0.0;
        }

        while (true)
        {
            try
            {
                float velocity;
                float actual_position;

                // Refresh cyclic data (send command and get feedback)
                base_feedback = m_base_cyclic->Refresh(m_base_command);
                actual_position = base_feedback.interconnect().gripper_feedback().motor()[0].position();

                position_error = target_position - actual_position;

                if (fabs(position_error) < MINIMAL_POSITION_ERROR)
                {
                    m_gripper_motor_command->set_velocity(0.0);
                    m_base_cyclic->Refresh(m_base_command);
                    break;
                }

                velocity = m_proportional_gain * fabs(position_error);
                if (velocity > 100.0)
                {
                    velocity = 100.0;
                }
                
                m_gripper_motor_command->set_position(target_position);
                m_gripper_motor_command->set_velocity(velocity);
            }
            catch(const std::exception& ex)
            {
                std::cerr << "Error occurred: " << ex.what() << std::endl;
                return false;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
        // If we get here, operation completed successfully.
        return true;
    }

private:
    k_api::TransportClientTcp*            m_transport;
    k_api::TransportClientUdp*            m_transport_real_time;
    k_api::RouterClient*                  m_router;
    k_api::RouterClient*                  m_router_real_time;
    k_api::SessionManager*                m_session_manager;
    k_api::SessionManager*                m_session_manager_real_time;
    k_api::Base::BaseClient*              m_base;
    k_api::BaseCyclic::BaseCyclicClient*  m_base_cyclic;

    k_api::BaseCyclic::Command            m_base_command;
    k_api::GripperCyclic::MotorCommand*   m_gripper_motor_command;
    std::string                           m_username;
    std::string                           m_password;
    std::string                           m_ip_address;
    int                                   m_port_real_time;
    int                                   m_port;
    k_api::Base::ServoingModeInformation  m_previous_servoing_mode;
    float                                 m_proportional_gain;
};

int main(int argc, char **argv)
{
    auto parsed_args = ParseExampleArguments(argc, argv);

    GripperLowLevel* gripper_low_level;
    gripper_low_level = new GripperLowLevel(parsed_args.ip_address, PORT_REAL_TIME, PORT,  parsed_args.username, parsed_args.password);
    gripper_low_level->Init(PROPORTIONAL_GAIN);

    // Example core
    // Implements a sample gripper low level servoing example
    std::cout << "GripperLowLevel object initialized" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    for (float position = 0.0; position <= 100.0; position+=10.0)
    {
        std::cout << "Going to position : " << position << std::endl;
        gripper_low_level->GoTo(position);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    delete gripper_low_level;

    return 0;
};