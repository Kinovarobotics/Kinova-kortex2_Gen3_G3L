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

/**
 * Map of all Sensor strings
 */
std::map<k_api::VisionConfig::Sensor, std::string> map_all_sensor_strings =
{
    {k_api::VisionConfig::Sensor::SENSOR_UNSPECIFIED, "Unspecified sensor"},
    {k_api::VisionConfig::Sensor::SENSOR_COLOR, "Color"},
    {k_api::VisionConfig::Sensor::SENSOR_DEPTH, "Depth"},
};

/**
 * Map of all Resolution strings
 */
std::map<k_api::VisionConfig::Resolution, std::string> map_all_resolution_strings =
{
    {k_api::VisionConfig::Resolution::RESOLUTION_UNSPECIFIED, "Unspecified resolution"},
    {k_api::VisionConfig::Resolution::RESOLUTION_320x240, "320x240"},
    {k_api::VisionConfig::Resolution::RESOLUTION_424x240, "424x240"},
    {k_api::VisionConfig::Resolution::RESOLUTION_480x270, "480x270"},
    {k_api::VisionConfig::Resolution::RESOLUTION_640x480, "640x480"},
    {k_api::VisionConfig::Resolution::RESOLUTION_1280x720, "1280x720"},
    {k_api::VisionConfig::Resolution::RESOLUTION_1920x1080, "1920x1080"}
};

/*****************************
 * Example related functions *
 *****************************/

/**
 * Returns a string matching the requested sensor
 */
std::string sensor_to_string(k_api::VisionConfig::Sensor sensor)
{
    std::string str;
    std::map<k_api::VisionConfig::Sensor, std::string>::iterator iter;

    iter = map_all_sensor_strings.find(sensor);
    if (iter != map_all_sensor_strings.end())
    {
        str = iter->second;
    }
    else
    {
        str = "Unknown sensor";
    }

    return str;
}

/**
 * Returns a string matching the requested resolution
 */
std::string resolution_to_string(k_api::VisionConfig::Resolution resolution)
{
    std::string str;
    std::map<k_api::VisionConfig::Resolution, std::string>::iterator iter;

    iter = map_all_resolution_strings.find(resolution);
    if (iter != map_all_resolution_strings.end())
    {
        str = iter->second;
    }
    else
    {
        str = "Unknown resolution";
    }

    return str;
}

/**
 * Prints the intrinsic parameters on stdout
 */
void print_intrinsic_parameters(const k_api::VisionConfig::IntrinsicParameters& intrinsics)
{
    // sets display precision for floating point values
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    std::cout << "Sensor: " << intrinsics.sensor();
    std::cout << " (" << sensor_to_string(intrinsics.sensor()) << ")" << std::endl;
    std::cout << "Resolution: " << intrinsics.resolution();
    std::cout << " (" << resolution_to_string(intrinsics.resolution()) << ")" << std::endl;
    std::cout << "Principal point x: " << intrinsics.principal_point_x() << std::endl;
    std::cout << "Principal point y: " << intrinsics.principal_point_y() << std::endl;
    std::cout << "Focal length x: " << intrinsics.focal_length_x() << std::endl;
    std::cout << "Focal length y: " << intrinsics.focal_length_y() << std::endl;
    std::cout << "Distortion coefficients: [" << intrinsics.distortion_coeffs().k1() << " " \
                                              << intrinsics.distortion_coeffs().k2() << " " \
                                              << intrinsics.distortion_coeffs().p1() << " " \
                                              << intrinsics.distortion_coeffs().p2() << " " \
                                              << intrinsics.distortion_coeffs().k3() << "]" \
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
            std::cout << "Vision module found, device Id: " << vision_device_id << std::endl;
            break;
        }
    }

    return vision_device_id;
}

/**
 * Example showing how to retrieve the intrinsic parameters of the Color and Depth sensors
 */
void example_routed_vision_get_intrinsics(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::IntrinsicParameters intrinsics;
    k_api::VisionConfig::SensorIdentifier sensor_id;
    k_api::VisionConfig::IntrinsicProfileIdentifier profile_id;

    std::cout << "\n\n** Example showing how to retrieve the intrinsic parameters of the Color and Depth sensors **" << std::endl;

    std::cout << "\n-- Using Vision Config Service to get intrinsic parameters of active color resolution --" << std::endl;
    sensor_id.set_sensor(k_api::VisionConfig::SENSOR_COLOR);

    intrinsics = vision->GetIntrinsicParameters(sensor_id, device_id);
    print_intrinsic_parameters(intrinsics);

    std::cout << "\n-- Using Vision Config Service to get intrinsic parameters of active depth resolution --" << std::endl;
    sensor_id.set_sensor(k_api::VisionConfig::SENSOR_DEPTH);

    intrinsics = vision->GetIntrinsicParameters(sensor_id, device_id);
    print_intrinsic_parameters(intrinsics);

    std::cout << "\n-- Using Vision Config Service to get intrinsic parameters for color resolution 1920x1080 --" << std::endl;
    profile_id.set_sensor(k_api::VisionConfig::SENSOR_COLOR);
    profile_id.set_resolution(k_api::VisionConfig::RESOLUTION_1920x1080);

    intrinsics = vision->GetIntrinsicParametersProfile(profile_id, device_id);
    print_intrinsic_parameters(intrinsics);

    std::cout << "\n-- Using Vision Config Service to get intrinsic parameters for depth resolution 424x240 --" << std::endl;
    profile_id.set_sensor(k_api::VisionConfig::SENSOR_DEPTH);
    profile_id.set_resolution(k_api::VisionConfig::RESOLUTION_424x240);

    intrinsics = vision->GetIntrinsicParametersProfile(profile_id, device_id);
    print_intrinsic_parameters(intrinsics);
}

/**
 * Example showing how to set the intrinsic parameters of the Color and Depth sensors
 */
void example_routed_vision_set_intrinsics(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::IntrinsicParameters intrinsics_old;
    k_api::VisionConfig::IntrinsicParameters intrinsics_new;
    k_api::VisionConfig::IntrinsicParameters intrinsics_reply;
    k_api::VisionConfig::IntrinsicProfileIdentifier profile_id;

    std::cout << "\n\n** Example showing how to set the intrinsic parameters of the Color and Depth sensors **" << std::endl;

    std::cout << "\n-- Using Vision Config Service to get current intrinsic parameters for color resolution 640x480 --" << std::endl;
    profile_id.set_sensor(k_api::VisionConfig::SENSOR_COLOR);
    profile_id.set_resolution(k_api::VisionConfig::RESOLUTION_640x480);
    intrinsics_old = vision->GetIntrinsicParametersProfile(profile_id, device_id);
    print_intrinsic_parameters(intrinsics_old);

    std::cout << "\n-- Using Vision Config Service to set new intrinsic parameters for color resolution 640x480 --" << std::endl;
    intrinsics_new.set_sensor(profile_id.sensor());
    intrinsics_new.set_resolution(profile_id.resolution());
    intrinsics_new.set_principal_point_x(640 / 2 + 0.123456f);
    intrinsics_new.set_principal_point_y(480 / 2 + 1.789012f);
    intrinsics_new.set_focal_length_x(650.567890f);
    intrinsics_new.set_focal_length_y(651.112233f);
    intrinsics_new.mutable_distortion_coeffs()->set_k1(0.2f);
    intrinsics_new.mutable_distortion_coeffs()->set_k2(0.05f);
    intrinsics_new.mutable_distortion_coeffs()->set_p1(1.2f);
    intrinsics_new.mutable_distortion_coeffs()->set_p2(0.999999f);
    intrinsics_new.mutable_distortion_coeffs()->set_k3(0.001f);
    vision->SetIntrinsicParameters(intrinsics_new, device_id);

    std::cout << "\n-- Using Vision Config Service to get new intrinsic parameters for color resolution 640x480 --" << std::endl;
    intrinsics_reply = vision->GetIntrinsicParametersProfile(profile_id, device_id);
    print_intrinsic_parameters(intrinsics_reply);

    std::cout << "\n-- Using Vision Config Service to set back old intrinsic parameters for color resolution 640x480 --" << std::endl;
    vision->SetIntrinsicParameters(intrinsics_old, device_id);


    std::cout << "\n-- Using Vision Config Service to get current intrinsic parameters for depth resolution 424x240 --" << std::endl;
    profile_id.set_sensor(k_api::VisionConfig::SENSOR_DEPTH);
    profile_id.set_resolution(k_api::VisionConfig::RESOLUTION_424x240);
    intrinsics_old = vision->GetIntrinsicParametersProfile(profile_id, device_id);
    print_intrinsic_parameters(intrinsics_old);

    std::cout << "\n-- Using Vision Config Service to set new intrinsic parameters for depth resolution 424x240 --" << std::endl;
    intrinsics_new.set_sensor(profile_id.sensor());
    intrinsics_new.set_resolution(profile_id.resolution());
    intrinsics_new.set_principal_point_x(424 / 2 + 0.123456f);
    intrinsics_new.set_principal_point_y(240 / 2 + 1.789012f);
    intrinsics_new.set_focal_length_x(315.567890f);
    intrinsics_new.set_focal_length_y(317.112233f);
    intrinsics_new.mutable_distortion_coeffs()->set_k1(0.425f);
    intrinsics_new.mutable_distortion_coeffs()->set_k2(1.735102f);
    intrinsics_new.mutable_distortion_coeffs()->set_p1(0.1452f);
    intrinsics_new.mutable_distortion_coeffs()->set_p2(0.767574f);
    intrinsics_new.mutable_distortion_coeffs()->set_k3(2.345678f);
    vision->SetIntrinsicParameters(intrinsics_new, device_id);

    std::cout << "\n-- Using Vision Config Service to get new intrinsic parameters for depth resolution 424x240 --" << std::endl;
    intrinsics_reply = vision->GetIntrinsicParametersProfile(profile_id, device_id);
    print_intrinsic_parameters(intrinsics_reply);

    std::cout << "\n-- Using Vision Config Service to set back old intrinsic parameters for depth resolution 424x240 --" << std::endl;
    vision->SetIntrinsicParameters(intrinsics_old, device_id);
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
        example_routed_vision_get_intrinsics(vision, vision_device_id);
        example_routed_vision_set_intrinsics(vision, vision_device_id);
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