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
* ######################################################################################
* # To use these examples:                                                             #
* #  - Connect to the robot's web page                                                 #
* #  - Configure the Vision Color Sensor to 1280x720 resolution                        #
* #  - Position the robot so you can easily place objects in front of the Color camera #
* #  - Select the Camera view page                                                     #
* ######################################################################################
*/

#include <SessionManager.h>
#include <DeviceManagerClientRpc.h>
#include <VisionConfigClientRpc.h>
#include <RouterClient.h>
#include <TransportClientTcp.h>

#include <thread>
#include <chrono>

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

/**
 * Returns the device identifier of the Vision module, 0 if not found
 */
uint32_t example_vision_get_device_id(k_api::DeviceManager::DeviceManagerClient* device_manager)
{
    uint32_t vision_device_id = 0;

    // gets all device routing information (from DeviceManagerClient service)
    auto all_devices_info = device_manager->ReadAllDevices();

    // uses device routing information to route to every device (base, actuator, interconnect, etc.)
    // in the armbase system and request general device information
    for ( auto dev : all_devices_info.device_handle() )
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
 * Display how to use these examples
 */
void example_display_usage()
{
    std::cout << std::endl;
    std::cout << "\t######################################################################################" << std::endl;
    std::cout << "\t# To use these examples:                                                             #" << std::endl;
    std::cout << "\t#  - Connect to the robot's web page                                                 #" << std::endl;
    std::cout << "\t#  - Configure the Vision Color Sensor to 1280x720 resolution                        #" << std::endl;
    std::cout << "\t#  - Position the robot so you can easily place objects in front of the Color camera #" << std::endl;
    std::cout << "\t#  - Select the Camera view page                                                     #" << std::endl;
    std::cout << "\t######################################################################################" << std::endl;
    std::cout << std::endl;
}

/**
 * Wait for 10 seconds, allowing to see the effects of the focus action
 */
void example_wait_for_focus_action()
{
    std::cout << "-- Waiting for 10 seconds to observe the effects of the focus action... --" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(10));
}

/**
 * Example showing how to play with the auto-focus of the Color camera
 */
void example_routed_vision_do_autofocus_action(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::SensorFocusAction sensor_focus_action;
    sensor_focus_action.set_sensor(k_api::VisionConfig::Sensor::SENSOR_COLOR);

    std::cout << "\n\n** Example showing how to play with the auto-focus of the Color camera **" << std::endl;

    std::cout << "\n-- Using Vision Config Service to disable the auto-focus --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_DISABLE_FOCUS);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Place or remove an object from the center of the camera, observe the focus doesn't change --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to enable the auto-focus --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_START_CONTINUOUS_FOCUS);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Place an object in the center of the camera, observe the focus adjusts automatically --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to pause the auto-focus --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_PAUSE_CONTINUOUS_FOCUS);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Move the object away from the center of the camera and then back, but at a different distance, observe the focus doesn't change --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to focus now --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_FOCUS_NOW);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Observe the focus tried to adjust to the object in front to the camera --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to re-enable the auto-focus --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_START_CONTINUOUS_FOCUS);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Move the object away from the center of the camera and then back, but at a different distance, observe the focus adjusts automatically --" << std::endl;
    example_wait_for_focus_action();
}

/**
 * Example showing how to set the focus of the Color camera to a X-Y point in the camera image
 */
void example_routed_vision_set_focus_point(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::SensorFocusAction sensor_focus_action;
    sensor_focus_action.set_sensor(k_api::VisionConfig::Sensor::SENSOR_COLOR);

    std::cout << "\n\n** Example showing how to set the focus of the Color camera to a X-Y point in the camera image **" << std::endl;

    std::cout << "\n-- Using Vision Config Service to set the focus point in the center of the lower right quadrant of the camera image --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_SET_FOCUS_POINT);
    sensor_focus_action.mutable_focus_point()->set_x(1280*3/4);
    sensor_focus_action.mutable_focus_point()->set_y(720*3/4);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_FOCUS_NOW);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Place an object in the center of the lower right quadrant of the camera image, observe the object gets into focus --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to set the focus point back in the middle the camera image--" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_SET_FOCUS_POINT);
    sensor_focus_action.mutable_focus_point()->set_x(1280/2);
    sensor_focus_action.mutable_focus_point()->set_y(720/2);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_FOCUS_NOW);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Place an object in the center of the camera image, observe the object gets into focus --" << std::endl;
    example_wait_for_focus_action();
}

/**
 * Example showing how to set the manual focus of the Color camera (changes the focus distance)
 */
void example_routed_vision_set_manual_focus(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::SensorFocusAction sensor_focus_action;
    sensor_focus_action.set_sensor(k_api::VisionConfig::Sensor::SENSOR_COLOR);

    std::cout << "\n\n** Example showing how to set the manual focus of the Color camera (changes the focus distance) **" << std::endl;

    std::cout << "\n-- Using Vision Config Service to set the manual focus on a very close object (close-up view) --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_SET_MANUAL_FOCUS);
    sensor_focus_action.mutable_manual_focus()->set_value(1023); // Maximum accepted value
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Place an object at around 2 inches away from the center of the camera, observe the object is in focus --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to set the manual focus on an object at a greater distance --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_SET_MANUAL_FOCUS);
    sensor_focus_action.mutable_manual_focus()->set_value(0); // Mininum accepted value
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Move the object away from the camera until it gets into focus --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to set the manual focus on a relatively close object (normal view) --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_SET_MANUAL_FOCUS);
    sensor_focus_action.mutable_manual_focus()->set_value(350);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Move the object at around 8 inches away from the center of the camera, observe the object is in focus --" << std::endl;
    example_wait_for_focus_action();

    std::cout << "\n-- Using Vision Config Service to re-enable the auto-focus --" << std::endl;
    sensor_focus_action.set_focus_action(k_api::VisionConfig::FocusAction::FOCUSACTION_START_CONTINUOUS_FOCUS);
    vision->DoSensorFocusAction(sensor_focus_action, device_id);
    std::cout << "-- Move the object away from the camera and then back, but at a different distance, observe the focus adjusts automatically --" << std::endl;
    example_wait_for_focus_action();
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
    example_display_usage();
    uint32_t vision_device_id = example_vision_get_device_id(device_manager);
    if (vision_device_id != 0)
    {
        example_routed_vision_do_autofocus_action(vision, vision_device_id);
        example_routed_vision_set_focus_point(vision, vision_device_id);
        example_routed_vision_set_manual_focus(vision, vision_device_id);
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