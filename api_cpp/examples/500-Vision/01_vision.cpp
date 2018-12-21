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
#include <DeviceManagerClientRpc.h>
#include <VisionConfigClientRpc.h>

#include <RouterClient.h>
#include <TransportClientUdp.h>

namespace k_api = Kinova::Api;
namespace pb = google::protobuf;

#define PORT 10000
#define IP_ADDRESS "192.168.1.10"

void example_routed_vision(k_api::DeviceManager::DeviceManagerClient* pDeviceMng, k_api::VisionConfig::VisionConfigClient* pVision)
{
    // gets all device routing information (from DeviceManagerClient service)
    printf("-- ReadAllDevices --\n\n");
    auto allDevicesInfo = pDeviceMng->ReadAllDevices();

    // uses device routing information to route to every device (base, actuator, interconnect, etc.) in the armbase system and request general device information
    for ( auto dev : allDevicesInfo.device_handle() )
    {
        if ( dev.device_type() == k_api::Common::DeviceTypes::VISION )
        {
            printf("-- Using Vision Config Service to get intrinsic parameters --\n");
            k_api::VisionConfig::SensorIdentifier sensorId;
            sensorId.set_sensor(k_api::VisionConfig::SENSOR_COLOR);

            auto intrinsicValue = pVision->GetIntrinsicParameters(sensorId, dev.device_identifier());

            std::cout << "Width: " << intrinsicValue.width() << std::endl;
            std::cout << "Height: " << intrinsicValue.height() << std::endl;
            std::cout << "Principal point x: " << intrinsicValue.principal_point_x() << std::endl;
            std::cout << "Principal point y: " << intrinsicValue.principal_point_y() << std::endl;
            std::cout << "focal lenght x: " << intrinsicValue.focal_length_x() << std::endl;
            std::cout << "focal lenght y: " << intrinsicValue.focal_length_y() << std::endl;

            break;
        }
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
    createSessionInfo.set_session_inactivity_timeout(60000);
    createSessionInfo.set_connection_inactivity_timeout(2000);

    auto pSessionMng = new k_api::SessionManager(pRouterClient);
    pSessionMng->CreateSession(createSessionInfo);

    auto pDeviceMng = new k_api::DeviceManager::DeviceManagerClient(pRouterClient);
    auto pVision = new k_api::VisionConfig::VisionConfigClient(pRouterClient);

    example_routed_vision(pDeviceMng, pVision);

    pSessionMng->CloseSession();

    pTransport->disconnect();
    delete pSessionMng;
    delete pDeviceMng;
    delete pVision;
    delete pRouterClient;
    delete pTransport;
}