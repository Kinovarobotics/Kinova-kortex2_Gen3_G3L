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
#include <DeviceManagerClientRpc.h>
#include <VisionConfigClientRpc.h>

#include <RouterClient.h>
#include <TransportClientTcp.h>

#include <iomanip>      // for std::setprecision

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

/*****************************
 * Example related functions *
 *****************************/

/**
 * Prints the extrinsic parameters on stdout
 */
void print_extrinsic_parameters(const k_api::VisionConfig::ExtrinsicParameters& extrinsics)
{
    // sets display precision for floating point values
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    std::cout << "Rotation matrix:\n[" << std::setw(9) << extrinsics.rotation().row1().column1() << " " \
                                       << std::setw(9) << extrinsics.rotation().row1().column2() << " " \
                                       << std::setw(9) << extrinsics.rotation().row1().column3() << "\n " \
                                       << std::setw(9) << extrinsics.rotation().row2().column1() << " " \
                                       << std::setw(9) << extrinsics.rotation().row2().column2() << " " \
                                       << std::setw(9) << extrinsics.rotation().row2().column3() << "\n " \
                                       << std::setw(9) << extrinsics.rotation().row3().column1() << " " \
                                       << std::setw(9) << extrinsics.rotation().row3().column2() << " " \
                                       << std::setw(9) << extrinsics.rotation().row3().column3() << "]" \
                                       << std::endl;
    std::cout << "Translation vector: [" << extrinsics.translation().t_x() << " " \
                                         << extrinsics.translation().t_y() << " " \
                                         << extrinsics.translation().t_z() << "]" \
                                         << std::endl;
}

/**************************
 * Example core functions *
 **************************/

/**
 * Returns the device identifier of the Vision module, 0 if not found
 */
uint32_t example_vision_get_device_id(k_api::DeviceManager::DeviceManagerClient* device_manager)
{
    uint32_t vision_device_id = 0;

    // gets all device routing information (from DeviceManagerClient service)
    auto allDevicesInfo = device_manager->ReadAllDevices();

    // uses device routing information to route to every device (base, actuator, interconnect, etc.)
    // in the armbase system and request general device information
    for ( auto dev : allDevicesInfo.device_handle() )
    {
        if ( dev.device_type() == k_api::Common::DeviceTypes::VISION )
        {
            vision_device_id = dev.device_identifier();
            std::cout << "Vision module found, device Id: " << vision_device_id <<std::endl;
            break;
        }
    }

    return vision_device_id;
}

/**
 * Example showing how to retrieve the extrinsic parameters
 */
void example_routed_vision_get_extrinsics(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::ExtrinsicParameters extrinsics;

    std::cout << "\n\n** Example showing how to retrieve the extrinsic parameters **" << std::endl;

    std::cout << "\n-- Using Vision Config Service to get the extrinsic parameters --" << std::endl;
    extrinsics = vision->GetExtrinsicParameters(device_id);
    print_extrinsic_parameters(extrinsics);
}

/**
 * Example showing how to set the extrinsic parameters
 */
void example_routed_vision_set_extrinsics(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::ExtrinsicParameters extrinsics_old;
    k_api::VisionConfig::ExtrinsicParameters extrinsics_new;
    k_api::VisionConfig::ExtrinsicParameters extrinsics_reply;

    std::cout << "\n\n** Example showing how to set the extrinsic parameters **" << std::endl;

    std::cout << "\n-- Using Vision Config Service to get current extrinsic parameters --" << std::endl;
    extrinsics_old = vision->GetExtrinsicParameters(device_id);
    print_extrinsic_parameters(extrinsics_old);

    std::cout << "\n-- Using Vision Config Service to set new extrinsic parameters --" << std::endl;
    extrinsics_new.mutable_rotation()->mutable_row1()->set_column1(1.0001f);
    extrinsics_new.mutable_rotation()->mutable_row1()->set_column2(0.1f);
    extrinsics_new.mutable_rotation()->mutable_row1()->set_column3(-0.01f);
    extrinsics_new.mutable_rotation()->mutable_row2()->set_column1(-0.001f);
    extrinsics_new.mutable_rotation()->mutable_row2()->set_column2(1.0002f);
    extrinsics_new.mutable_rotation()->mutable_row2()->set_column3(0.0001f);
    extrinsics_new.mutable_rotation()->mutable_row3()->set_column1(0.00001f);
    extrinsics_new.mutable_rotation()->mutable_row3()->set_column2(-0.000001f);
    extrinsics_new.mutable_rotation()->mutable_row3()->set_column3(1.0003f);
    extrinsics_new.mutable_translation()->set_t_x(-0.026123456f);
    extrinsics_new.mutable_translation()->set_t_y(-0.009876543f);
    extrinsics_new.mutable_translation()->set_t_z(0.00002f);
    vision->SetExtrinsicParameters(extrinsics_new, device_id);

    std::cout << "\n-- Using Vision Config Service to get new extrinsic parameters --" << std::endl;
    extrinsics_reply = vision->GetExtrinsicParameters(device_id);
    print_extrinsic_parameters(extrinsics_reply);

    std::cout << "\n-- Using Vision Config Service to set back old extrinsic parameters --" << std::endl;
    vision->SetExtrinsicParameters(extrinsics_old, device_id);
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
    auto vision = new k_api::VisionConfig::VisionConfigClient(router);
    auto device_manager = new k_api::DeviceManager::DeviceManagerClient(router);

    // Example core
    uint32_t vision_device_id = example_vision_get_device_id(device_manager);

    if (vision_device_id != 0)
    {
        example_routed_vision_get_extrinsics(vision, vision_device_id);
        example_routed_vision_set_extrinsics(vision, vision_device_id);
    }
    else
    {
        std::cout << "Error : No Vision module found!" << std::endl;
    }

    // Close API session
    session_manager->CloseSession();

    // Deactivate the router and cleanly disconnect from the transport object
    router->SetActivationStatus(false);
    transport->disconnect();

    // Destroy the API
    delete vision;
    delete device_manager;
    delete session_manager;
    delete router;
    delete transport;
}