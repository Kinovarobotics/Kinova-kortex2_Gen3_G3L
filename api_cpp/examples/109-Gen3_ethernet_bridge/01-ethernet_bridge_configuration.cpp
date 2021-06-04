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

#include <InterconnectConfig.pb.h>
#include <InterconnectConfigClientRpc.h>
#include <SessionManager.h>
#include <DeviceManagerClientRpc.h>
#include <RouterClient.h>
#include <TransportClientTcp.h>
#include <iostream>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

///////////////////////////////////////////////////////////////////////
// class EthernetBridgeConfigurationExample
//
// Implements methods for enabling the Ethernet routing to an external
// device through the robot's base
///////////////////////////////////////////////////////////////////////

class EthernetBridgeConfigurationExample
{
public:
    EthernetBridgeConfigurationExample(const std::string& ip_address, int port, const std::string& username = "admin", const std::string& password = "admin"):
    m_ip_address(ip_address), m_username(username), m_password(password), m_port(port), m_interconnect_device_id(0)
    {
        m_router              = nullptr;
        m_transport           = nullptr;
        m_session_manager     = nullptr;
        m_device_manager      = nullptr;
        m_interconnect_config = nullptr;
    }

    ~EthernetBridgeConfigurationExample()
    {
        // Close API session
        m_session_manager->CloseSession();

        // Deactivate the router and cleanly disconnect from the transport object
        m_router->SetActivationStatus(false);
        m_transport->disconnect();

        // Destroy the API
        delete m_interconnect_config;
        delete m_device_manager;
        delete m_session_manager;
        delete m_router;
        delete m_transport;
    }

    void Init()
    {
        std::cout << "Initizalizing the API..." << std::endl;
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
        m_device_manager      = new k_api::DeviceManager::DeviceManagerClient(m_router);
        m_interconnect_config = new k_api::InterconnectConfig::InterconnectConfigClient(m_router);

        m_interconnect_device_id = GetDeviceIdFromDevType(k_api::Common::INTERCONNECT, 0);
        std::cout << "Done initizalizing the API." << std::endl;
    }

    uint32_t GetDeviceIdFromDevType(k_api::Common::DeviceTypes device_type, uint32_t device_index)
    {
        auto device_handles = m_device_manager->ReadAllDevices();
        uint32_t current_index = 0;
        for (auto device_handle : device_handles.device_handle() )
        {
            if (device_handle.device_type() == device_type)
            {
                if (current_index == device_index)
                {
                    return device_handle.device_identifier();
                }
                ++current_index;
            }
        }
        return 0;
    }

    void EnableEthernetBridge()
    {
        std::cout << "Configuring and enabling the Ethernet bridge..." << std::endl;
        k_api::InterconnectConfig::EthernetConfiguration ethernet_configuration;
        ethernet_configuration.set_device(k_api::InterconnectConfig::ETHERNET_DEVICE_EXPANSION);
        ethernet_configuration.set_enabled(true);
        ethernet_configuration.set_speed(k_api::InterconnectConfig::ETHERNET_SPEED_100M);
        ethernet_configuration.set_duplex(k_api::InterconnectConfig::ETHERNET_DUPLEX_FULL);

        try 
        {
            m_interconnect_config->SetEthernetConfiguration(ethernet_configuration, m_interconnect_device_id);
        }
        catch(k_api::KDetailedException& e)
        {
            std::cout << "An unexpected error occured : " << e.what() << std::endl;
            return;
        }
        
        std::cout << "Done configuring the Ethernet bridge." << std::endl;
    }

private:
    k_api::RouterClient*                                    m_router;
    k_api::TransportClientTcp*                              m_transport;
    k_api::SessionManager*                                  m_session_manager;
    k_api::DeviceManager::DeviceManagerClient*              m_device_manager;
    k_api::InterconnectConfig::InterconnectConfigClient*    m_interconnect_config;

    std::string                                             m_username;
    std::string                                             m_password;
    std::string                                             m_ip_address;
    int                                                     m_port;
    uint32_t                                                m_interconnect_device_id;
};

// Example core
int main(int argc, char **argv)
{
    auto parsed_args = ParseExampleArguments(argc, argv);

    EthernetBridgeConfigurationExample* ethernet_bridge;
    ethernet_bridge = new EthernetBridgeConfigurationExample(parsed_args.ip_address , PORT, parsed_args.username, parsed_args.password);
    ethernet_bridge->Init();

    ethernet_bridge->EnableEthernetBridge();

    delete ethernet_bridge;

    return 0;
}
