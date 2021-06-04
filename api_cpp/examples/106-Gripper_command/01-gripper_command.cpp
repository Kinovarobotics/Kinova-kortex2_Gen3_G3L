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

#include <BaseClientRpc.h>
#include <InterconnectConfigClientRpc.h>
#include <SessionManager.h>
#include <DeviceManagerClientRpc.h>
#include <RouterClient.h>
#include <TransportClientTcp.h>
#include <thread>
#include <iostream>
#include <chrono>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

///////////////////////////////////////////////////////////////////////
// class GripperCommandExample
//
// Implements a sample Gripper command application.
///////////////////////////////////////////////////////////////////////
class GripperCommandExample
{
public:
    GripperCommandExample(const std::string& ip_address, int port, const std::string& username = "admin", const std::string& password = "admin"):
    m_ip_address(ip_address), m_username(username), m_password(password), m_port(port)
    {
        m_router              = nullptr;
        m_transport           = nullptr;
        m_session_manager     = nullptr;
        m_device_manager      = nullptr;
        m_base                = nullptr;

        m_is_init             = false;
    }

    ~GripperCommandExample()
    {
        // Close API session
        m_session_manager->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        m_router->SetActivationStatus(false);
        m_transport->disconnect();

        // Destroy the API
        delete m_base;
        delete m_device_manager;
        delete m_session_manager;
        delete m_router;
        delete m_transport;
    }

    void Init()
    {
        if (m_is_init)
        {
            return;
        }
        m_transport = new k_api::TransportClientTcp();
        m_transport->connect(m_ip_address, m_port);
        m_router = new k_api::RouterClient(m_transport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });
        
        // Set session data connection information
        auto createSessionInfo = k_api::Session::CreateSessionInfo();
        createSessionInfo.set_username(m_username);
        createSessionInfo.set_password(m_password);
        createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
        createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

        // Session manager service wrapper
        m_session_manager = new k_api::SessionManager(m_router);
        m_session_manager->CreateSession(createSessionInfo);

        // Create services
        m_device_manager = new k_api::DeviceManager::DeviceManagerClient(m_router);
        m_base          = new k_api::Base::BaseClient(m_router);
        
        m_is_init = true;
    }

    bool Run()
    {
        if (m_is_init == false)
        {
            return false;
        }
        std::cout << "Performing gripper test in position..." << std::endl;

        k_api::Base::GripperCommand gripper_command;

        gripper_command.set_mode(k_api::Base::GRIPPER_POSITION);

        auto finger = gripper_command.mutable_gripper()->add_finger();
        finger->set_finger_identifier(1);
        for (float position = 0.0; position < 1.0; position += 0.1)
        {
            std::cout << "Setting position to " << position << std::endl;
            finger->set_value(position);
            m_base->SendGripperCommand(gripper_command);
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

        std::cout << "Opening gripper using speed command..." << std::endl;
        gripper_command.set_mode(k_api::Base::GRIPPER_SPEED);
        finger->set_value(0.1);
        m_base->SendGripperCommand(gripper_command);
        k_api::Base::Gripper gripper_feedback;
        k_api::Base::GripperRequest gripper_request;
        bool is_motion_completed = false;
        gripper_request.set_mode(k_api::Base::GRIPPER_POSITION);
        while(!is_motion_completed)
        {
            float position =0.0f;
            gripper_feedback = m_base->GetMeasuredGripperMovement(gripper_request);

            if (gripper_feedback.finger_size())
            {
                position = gripper_feedback.finger(0).value();
                cout << "Reported position : " << position << std::endl;
            }

            if (position < 0.01f)
            {
                is_motion_completed = true;
            }
        }

        std::cout << "Closing gripper using speed command..." << std::endl;
        finger->set_value(-0.1);
        m_base->SendGripperCommand(gripper_command);
        is_motion_completed = false;
        gripper_request.set_mode(k_api::Base::GRIPPER_SPEED);
        while(!is_motion_completed)
        {
            float speed = 0.0;
            gripper_feedback = m_base->GetMeasuredGripperMovement(gripper_request);
            if (gripper_feedback.finger_size())
            {
                speed = gripper_feedback.finger(0).value();
                cout << "Reported speed : " << speed  << std::endl;
            }

            if (speed == 0.0f)
            {
                is_motion_completed = true;
            }

        }
        return true;
    }

private:

    k_api::RouterClient*                         m_router;
    k_api::TransportClientTcp*                   m_transport;
    k_api::SessionManager*                       m_session_manager;
    k_api::Base::BaseClient*                     m_base;
    k_api::DeviceManager::DeviceManagerClient*   m_device_manager;
    bool                                         m_is_init;
    std::string                                  m_username;
    std::string                                  m_password;
    std::string                                  m_ip_address;
    int                                          m_port;
};

int main(int argc, char **argv)
{
    auto parsed_args = ParseExampleArguments(argc, argv);

    GripperCommandExample* gripper_command_example;
    gripper_command_example = new GripperCommandExample(parsed_args.ip_address, PORT, parsed_args.username, parsed_args.password);
    gripper_command_example->Init();
    gripper_command_example->Run();
    delete gripper_command_example;

    return 0;
};