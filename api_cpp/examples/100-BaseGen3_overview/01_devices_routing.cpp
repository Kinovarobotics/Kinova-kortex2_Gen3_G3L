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

#include <SessionManager.h>
#include <VisionConfigClientRpc.h>
#include <DeviceConfigClientRpc.h>
#include <DeviceManagerClientRpc.h>

#include <RouterClient.h>
#include <TransportClientUdp.h>

#include <google/protobuf/text_format.h>

namespace k_api = Kinova::Api;
namespace pb = google::protobuf;

#define PORT 10000
#define IP_ADDRESS "192.168.1.10"


void example_routed_device_config(k_api::DeviceConfig::DeviceConfigClient* pDeviceConfig, k_api::DeviceManager::DeviceManagerClient* pDeviceMng)
{
    // getting all device routing information (from DeviceManagerClient service)
    printf("-- ReadAllDevices --\n\n");
    auto allDevicesInfo = pDeviceMng->ReadAllDevices();

    k_api::RouterClientSendOptions options;
    options.timeout_ms = 4000;  // (milliseconds)

    // using device routing information to route to every device (base, actuator, interconnect, etc.) in the arm base system and request general device information
    for ( auto dev : allDevicesInfo.device_handle() )
    {
        const pb::EnumDescriptor *descriptor = k_api::Common::DeviceTypes_descriptor();
        
        std::cout << "-----------------------------\n";
        std::cout << "-- " << descriptor->FindValueByNumber(dev.device_type())->name() << ": id = " << dev.device_identifier() << " --\n";
        
        std::string str;
        pb::TextFormat::PrintToString( pDeviceConfig->GetDeviceType         (dev.device_identifier(), options), &str );     std::cout << str;
        pb::TextFormat::PrintToString( pDeviceConfig->GetFirmwareVersion    (dev.device_identifier(), options), &str );     std::cout << str;
        pb::TextFormat::PrintToString( pDeviceConfig->GetBootloaderVersion  (dev.device_identifier(), options), &str );     std::cout << str;
        pb::TextFormat::PrintToString( pDeviceConfig->GetPartNumber         (dev.device_identifier(), options), &str );     std::cout << str;
        pb::TextFormat::PrintToString( pDeviceConfig->GetSerialNumber       (dev.device_identifier(), options), &str );     std::cout << str;
        pb::TextFormat::PrintToString( pDeviceConfig->GetMACAddress         (dev.device_identifier(), options), &str );     std::cout << str;
        pb::TextFormat::PrintToString( pDeviceConfig->GetPartNumberRevision (dev.device_identifier(), options), &str );     std::cout << str;
        std::cout << "\n";
    }
}


int main(int argc, char **argv)
{
    auto pTransport = new k_api::TransportClientUdp();
    pTransport->connect(IP_ADDRESS, PORT);
    auto pRouterClient = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

    // create session
    auto createSessionInfo = k_api::Session::CreateSessionInfo();
    createSessionInfo.set_username("admin");
    createSessionInfo.set_password("admin");
    createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
    createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

    auto pSessionMng = new k_api::SessionManager(pRouterClient);
    pSessionMng->CreateSession(createSessionInfo);

    auto pDeviceConfig = new k_api::DeviceConfig::DeviceConfigClient(pRouterClient);
    auto pDeviceMng = new k_api::DeviceManager::DeviceManagerClient(pRouterClient);

    example_routed_device_config(pDeviceConfig, pDeviceMng);

    pSessionMng->CloseSession();

    pTransport->disconnect();
    delete pSessionMng;
    delete pDeviceConfig;
    delete pDeviceMng;
    delete pRouterClient;
    delete pTransport;
}