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

#include <SessionManager.h>
#include <DeviceConfigClientRpc.h>
#include <DeviceManagerClientRpc.h>

#include <TransportClientTcp.h>
#include <RouterClient.h>

#include <google/protobuf/text_format.h>

#include <iomanip>

#include "utilities.h"

#define PORT 10000

namespace k_api = Kinova::Api;

void example_device_routing(k_api::DeviceManager::DeviceManagerClient* device_manager, k_api::DeviceConfig::DeviceConfigClient* device_config)
{
    // Get all device routing information (from DeviceManagerClient service)
    auto allDevicesInfo = device_manager->ReadAllDevices();

    k_api::RouterClientSendOptions options;
    options.timeout_ms = 4000;  // (milliseconds)

    // Use device routing information to route to every device (base, actuator, interconnect, etc.) in the arm base system and request general device information
    for (auto device : allDevicesInfo.device_handle())
    {

        std::cout << "-----------------------------\n";
        std::cout << "-- " << k_api::Common::DeviceTypes_Name(device.device_type()) << ": id = " << device.device_identifier() << " --\n";

        std::string str;
        google::protobuf::TextFormat::PrintToString( device_config->GetDeviceType         (device.device_identifier(), options), &str );     std::cout << str;
        google::protobuf::TextFormat::PrintToString( device_config->GetFirmwareVersion    (device.device_identifier(), options), &str );     std::cout << str;
        google::protobuf::TextFormat::PrintToString( device_config->GetBootloaderVersion  (device.device_identifier(), options), &str );     std::cout << str;
        google::protobuf::TextFormat::PrintToString( device_config->GetModelNumber        (device.device_identifier(), options), &str );     std::cout << str;
        google::protobuf::TextFormat::PrintToString( device_config->GetPartNumber         (device.device_identifier(), options), &str );     std::cout << str;
        google::protobuf::TextFormat::PrintToString( device_config->GetPartNumberRevision (device.device_identifier(), options), &str );     std::cout << str;
        google::protobuf::TextFormat::PrintToString( device_config->GetSerialNumber       (device.device_identifier(), options), &str );     std::cout << str;

        // Get hexadecimal representation of MAC address
        std::string mac_address = device_config->GetMACAddress(device.device_identifier(), options).mac_address();
        std::cout << "MAC address: ";
        for(size_t i=0; i < mac_address.size(); ++i)
        {
            std::cout << std::hex << std::setw(2) << static_cast<unsigned int>(uint8_t(mac_address.c_str()[i]));
            if (i != mac_address.size() - 1)
            {
                std::cout << ":";
            }
        }
        std::cout << std::endl;
    }
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
    auto device_manager = new k_api::DeviceManager::DeviceManagerClient(router);
    auto device_config = new k_api::DeviceConfig::DeviceConfigClient(router);

    // Example core
    example_device_routing(device_manager, device_config);

    // Close API session
    session_manager->CloseSession();

    // Deactivate the router and cleanly disconnect from the transport object
    router->SetActivationStatus(false);
    transport->disconnect();

    // Destroy the API
    delete device_manager;
  	delete device_config;
    delete session_manager;
    delete router;
    delete transport;
}
