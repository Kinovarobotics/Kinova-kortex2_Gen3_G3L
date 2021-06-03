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
* #  - Select the Camera view page                                                     #
* #  - Observe the effects of changing the Color sensor options                        #
* ######################################################################################
*/

#include <SessionManager.h>
#include <DeviceManagerClientRpc.h>
#include <VisionConfigClientRpc.h>
#include <DeviceConfigClientRpc.h>
#include <RouterClient.h>
#include <TransportClientTcp.h>

#include <thread>
#include <chrono>
#include <iomanip>      // for std::setprecision, std::setfill, std::setw

#include "utilities.h"

namespace k_api = Kinova::Api;

#define PORT 10000

typedef struct _option_info
{
    // int id;
    k_api::VisionConfig::Option id;
    string name;
    bool writable;
    float min_value;
    float max_value;
    float step_value;
    float default_value;
} option_info_t;

// Lists of supported options for a sensor
std::vector<option_info_t> supported_color_options;
std::vector<option_info_t> supported_depth_options;
// Empty list to use for an unsupported sensor
std::vector<option_info_t> no_options;

/**
 * Returns the device identifier of the Vision module, 0 if not found
 */
uint32_t example_vision_get_device_id(k_api::DeviceManager::DeviceManagerClient* device_manager)
{
    uint32_t vision_device_id = 0;

    // Gets all device routing information (from DeviceManagerClient service)
    auto all_devices_info = device_manager->ReadAllDevices();

    // Uses device routing information to route to every device (base, actuator, interconnect, etc.)
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
    std::cout << "\t#  - Select the Camera view page                                                     #" << std::endl;
    std::cout << "\t#  - Observe the effects of changing the Color sensor options                        #" << std::endl;
    std::cout << "\t######################################################################################" << std::endl;
    std::cout << std::endl;
}

/**
 * Get the name of a sensor
 */
string example_get_sensor_name(k_api::VisionConfig::Sensor sensor)
{
    string name;
    if (sensor == k_api::VisionConfig::Sensor::SENSOR_COLOR)
    {
        name = "COLOR";
    }
    else if (sensor == k_api::VisionConfig::Sensor::SENSOR_DEPTH)
    {
        name = "DEPTH";
    }
    else
    {
        name = "***UNSUPPORTED***";
    }
    
    return name;
}

/**
 * Get the list of supported options for a sensor
 * Each list item is a dictionary describing an option information
 */
const std::vector<option_info_t>& example_get_sensor_supported_options(k_api::VisionConfig::Sensor sensor)
{
    if (sensor == k_api::VisionConfig::Sensor::SENSOR_COLOR)
    {
        return supported_color_options;
    }
    else if (sensor == k_api::VisionConfig::Sensor::SENSOR_DEPTH)
    {
        return supported_depth_options;
    }
    else
    {
        return no_options;
    }
}

/**
 * Display the information of a specific sensor option
 */
void example_display_sensor_option_information(const option_info_t& option_info)
{
    // sets display precision for floating point values
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    std::cout << "Option id: " << std::setfill('0') << std::setw(2) << option_info.id << "  name: " << option_info.name;
    std::cout << "  is_writable: " << std::boolalpha << option_info.writable << std::endl;
    std::cout << "minimum: " << option_info.min_value << "  maximum: " << option_info.max_value << std::endl;
    std::cout << "   step: " << option_info.step_value << "  default: " << option_info.default_value << std::endl << std::endl;
}

/**
 * Add option information to a list of supported options for a sensor
 * The added item is a dictionary describing the option information, with the following fields:
 *   'id', 'name', 'writable', 'min', 'max', 'step', 'default'
 * Then, display the option information
 */
void example_add_and_display_sensor_supported_option(const k_api::VisionConfig::OptionInformation& option_info)
{
    bool display_option_info = true;
    option_info_t option_infoData = {};

    option_infoData.id = option_info.option();
    option_infoData.name = k_api::VisionConfig::Option_Name(option_info.option());
    option_infoData.writable = !option_info.read_only();
    option_infoData.min_value = option_info.minimum();
    option_infoData.max_value = option_info.maximum();
    option_infoData.step_value = option_info.step();
    option_infoData.default_value = option_info.default_value();

    if (option_info.sensor() == k_api::VisionConfig::Sensor::SENSOR_COLOR)
    {
        supported_color_options.push_back(option_infoData);
    }
    else if (option_info.sensor() == k_api::VisionConfig::Sensor::SENSOR_DEPTH)
    {
        supported_depth_options.push_back(option_infoData);
    }
    else
    {
        std::cout << "Unsupported sensor " << option_info.sensor() << " for option id " << option_info.option();
        std::cout << ", not adding to any list!" << std::endl;
        display_option_info = false;
    }

    // Display option information
    if (display_option_info)
    {
        example_display_sensor_option_information(option_infoData);
    }
}

/**
 * From the given option information, return the value requested by the range
 */
float example_get_option_value_by_range(const option_info_t& option_info, const string& value_range)
{
    float value;

    if (value_range == "min")
    {
        value = option_info.min_value;
    }
    else if (value_range == "max")
    {
        value = option_info.max_value;
    }
    else if (value_range == "default")
    {
        value = option_info.default_value;
    }
    else
    {
        value = 0.0f;
    }

    return value;
}

/**
 * For all sensor options, set their value based on the specified range
 */
void example_set_sensor_options_values_by_range(k_api::VisionConfig::Sensor sensor, const string& value_range,
                                                k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::OptionValue option_value;
    const std::vector<option_info_t>& sensor_options = example_get_sensor_supported_options(sensor);
    std::vector<option_info_t>::const_iterator iter_options;

    option_value.set_sensor(sensor);

    for (iter_options = sensor_options.begin(); iter_options != sensor_options.end(); ++iter_options)
    {
        if (iter_options->writable)
        {
            try
            {
                option_value.set_option(iter_options->id);
                option_value.set_value(example_get_option_value_by_range(*iter_options, value_range));
                vision->SetOptionValue(option_value, device_id);
                std::cout << "Set value (" << option_value.value() << ") for option '" << iter_options->name << "'" << std::endl;
            }
            catch(const std::exception& ex)
            {
                std::cout << "Failed to set " << value_range << " value for option '" << iter_options->name << "': " << ex.what() << std::endl;
            }
        }
    }
}

/**
 * For all sensor options, validate their value based on the specified range
 */
void example_validate_sensor_options_values_by_range(k_api::VisionConfig::Sensor sensor, const string& value_range,
                                                     k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    k_api::VisionConfig::OptionIdentifier option_identifier;
    k_api::VisionConfig::OptionValue option_value_reply;
    const std::vector<option_info_t>& sensor_options = example_get_sensor_supported_options(sensor);
    std::vector<option_info_t>::const_iterator iter_options;

    option_identifier.set_sensor(sensor);

    for (iter_options = sensor_options.begin(); iter_options != sensor_options.end(); ++iter_options)
    {
        if (iter_options->writable)
        {
            try
            {
                option_identifier.set_option(iter_options->id);
                option_value_reply = vision->GetOptionValue(option_identifier, device_id);
                std::cout << "Confirm received value (" << option_value_reply.value() << ") for option '" << iter_options->name << "' --> ";
                std::cout << (option_value_reply.value() == example_get_option_value_by_range(*iter_options, value_range) ? "OK" : "*** FAILED ***");
                std::cout << std::endl;
            }
            catch(const std::exception& ex)
            {
                std::cout << "Failed to get value for option '" << iter_options->name << "': " << ex.what() << std::endl;
            }
        }
    }
}

/**
 * Example showing how to get the sensors options information
 * Note: This function must be called in order to fill up the lists of sensors supported options
 */
void example_routed_vision_get_option_information(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    int sensor_index;
    int option_index;
    k_api::VisionConfig::OptionIdentifier option_identifier;
    k_api::VisionConfig::OptionInformation option_info;
    string sensor_name;

    std::cout << "\n** Example showing how to get the sensors options information **" << std::endl;

    // For all sensors, determine which options are supported and populate specific list
    for (sensor_index = k_api::VisionConfig::Sensor_MIN+1; sensor_index <= k_api::VisionConfig::Sensor_MAX; sensor_index++)
    {
        option_identifier.set_sensor(static_cast<k_api::VisionConfig::Sensor> (sensor_index));
        sensor_name = example_get_sensor_name(static_cast<k_api::VisionConfig::Sensor> (sensor_index));
        std::cout << "\n-- Using Vision Config Service to get information for all " << sensor_name << " sensor options --" << std::endl;
        for (option_index = k_api::VisionConfig::Option_MIN+1; option_index <= k_api::VisionConfig::Option_MAX; option_index++)
        {
            try
            {
                option_identifier.set_option(static_cast<k_api::VisionConfig::Option> (option_index));
                option_info = vision->GetOptionInformation(option_identifier, device_id);
                if (option_info.sensor() == static_cast<k_api::VisionConfig::Sensor> (sensor_index) &&
                    option_info.option() == static_cast<k_api::VisionConfig::Option> (option_index))
                {
                    if (option_info.supported())
                    {
                        example_add_and_display_sensor_supported_option(option_info);
                    }
                }
                else
                {
                    std::cout << "Unexpected mismatch of sensor or option in returned information for option id ";
                    std::cout << option_index << "!" << std::endl;
                }
            }
            catch(const std::exception& ex)
            {
                // The option is simply not supported
            }
        }
    }
}

/**
 * Example showing how to get the sensors options values
 */
void example_routed_vision_get_sensor_options_values(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    int sensor_index;
    k_api::VisionConfig::OptionIdentifier option_identifier;
    k_api::VisionConfig::OptionValue option_value;
    string sensor_name;
    std::vector<option_info_t>::const_iterator iter_options;

    std::cout << "\n** Example showing how to get the sensors options values **" << std::endl;

    // sets display precision for floating point values
    std::cout << std::fixed;
    std::cout << std::setprecision(6);

    // For all sensors, get their supported options value
    for (sensor_index = k_api::VisionConfig::Sensor_MIN+1; sensor_index <= k_api::VisionConfig::Sensor_MAX; sensor_index++)
    {
        option_identifier.set_sensor(static_cast<k_api::VisionConfig::Sensor> (sensor_index));
        sensor_name = example_get_sensor_name(static_cast<k_api::VisionConfig::Sensor> (sensor_index));
        const std::vector<option_info_t>& sensor_options = example_get_sensor_supported_options(static_cast<k_api::VisionConfig::Sensor> (sensor_index));
        std::cout << "\n-- Using Vision Config Service to get value for all " << sensor_name << " sensor options --" << std::endl;
        for (iter_options = sensor_options.begin(); iter_options != sensor_options.end(); ++iter_options)
        {
            try
            {
                option_identifier.set_option(iter_options->id);
                option_value = vision->GetOptionValue(option_identifier, device_id);
                std::cout << "Option '" << iter_options->name << "' has value " << option_value.value() << std::endl;
            }
            catch(const std::exception& ex)
            {
                std::cout << "Failed to get value of option '"<< iter_options->name << "': " << ex.what() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

/**
 * Example showing how to set the sensors options values
 */
void example_routed_vision_set_sensor_options_values(k_api::VisionConfig::VisionConfigClient* vision, uint32_t device_id)
{
    int sensor_index;
    string sensor_name;
    std::vector<string> value_ranges = {"max", "default"};
    std::vector<string>::iterator iter_value_ranges;

    std::cout << "\n** Example showing how to set the sensors options values **" << std::endl;

    // Set display precision for floating point values
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    
    // For all sensors, set and confirm options values
    for (iter_value_ranges = value_ranges.begin(); iter_value_ranges != value_ranges.end(); ++iter_value_ranges)
    {
        for (sensor_index = k_api::VisionConfig::Sensor_MIN+1; sensor_index <= k_api::VisionConfig::Sensor_MAX; sensor_index++)
        {
            sensor_name = example_get_sensor_name(static_cast<k_api::VisionConfig::Sensor> (sensor_index));

            std::cout << "\n-- Using Vision Config Service to set " << *iter_value_ranges << " value for all " << sensor_name;
            std::cout << " sensor options --" << std::endl;
            example_set_sensor_options_values_by_range(static_cast<k_api::VisionConfig::Sensor> (sensor_index), *iter_value_ranges, vision, device_id);

            std::cout << "\n-- Using Vision Config Service to confirm " << *iter_value_ranges << " value was set for all " << sensor_name;
            std::cout << " sensor options --" << std::endl;
            example_validate_sensor_options_values_by_range(static_cast<k_api::VisionConfig::Sensor> (sensor_index), *iter_value_ranges, vision, device_id);

            if (static_cast<k_api::VisionConfig::Sensor> (sensor_index) == k_api::VisionConfig::Sensor::SENSOR_COLOR)
            {
                std::cout << "\n-- Waiting for 5 seconds to observe the effects of the new COLOR sensor options values... --" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(5));
            }
            else
            {
                std::cout << std::endl;
            }
        }
    }
}

/**
 * Example confirming that sensors options values are restored upon a reboot of the Vision module
 */
void example_routed_vision_confirm_saved_sensor_options_values(k_api::VisionConfig::VisionConfigClient* vision, k_api::DeviceConfig::DeviceConfigClient* device_config, uint32_t device_id)
{
    int sensor_index;
    string sensor_name;
    std::vector<string> value_ranges = {"min", "default"};
    std::vector<string>::iterator iter_value_ranges;

    std::cout << "\n** Example confirming that sensors options values are restored upon a reboot of the Vision module **" << std::endl;

    // Set display precision for floating point values
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    
    // For all sensors, set and confirm options values
    for (iter_value_ranges = value_ranges.begin(); iter_value_ranges != value_ranges.end(); ++iter_value_ranges)
    {
        for (sensor_index = k_api::VisionConfig::Sensor_MIN+1; sensor_index <= k_api::VisionConfig::Sensor_MAX; sensor_index++)
        {
            sensor_name = example_get_sensor_name(static_cast<k_api::VisionConfig::Sensor> (sensor_index));

            std::cout << "\n-- Using Vision Config Service to set " << *iter_value_ranges << " value for all " << sensor_name;
            std::cout << " sensor options --" << std::endl;
            example_set_sensor_options_values_by_range(static_cast<k_api::VisionConfig::Sensor> (sensor_index), *iter_value_ranges, vision, device_id);

            std::cout << "\n-- Using Vision Config Service to confirm " << *iter_value_ranges << " value was set for all " << sensor_name;
            std::cout << " sensor options --" << std::endl;
            example_validate_sensor_options_values_by_range(static_cast<k_api::VisionConfig::Sensor> (sensor_index), *iter_value_ranges, vision, device_id);
        }

        // If we just set the options' minimum value, reboot the Vision module device
        if (*iter_value_ranges == "min")
        {
            // Reboot with a delay
            int delayToReboot_ms = 5000;
            k_api::DeviceConfig::RebootRqst rebootRequest;
            rebootRequest.set_delay(delayToReboot_ms);
            std::cout << "\n-- Using Device Config Service to reboot the Vision module in " << delayToReboot_ms << " milliseconds. ";
            std::cout << "Please wait... --" << std::endl;
            device_config->RebootRequest(rebootRequest, device_id);

            // Wait until the Vision module is rebooted completely
            int waitAfterRebootSec = 35 + (delayToReboot_ms / 1000);
            std::this_thread::sleep_for(std::chrono::seconds(waitAfterRebootSec));

            // For all sensors, confirm their option values were restored
            for (sensor_index = k_api::VisionConfig::Sensor_MIN+1; sensor_index <= k_api::VisionConfig::Sensor_MAX; sensor_index++)
            {
                sensor_name = example_get_sensor_name(static_cast<k_api::VisionConfig::Sensor> (sensor_index));

                std::cout << "\n-- Using Vision Config Service to confirm " << *iter_value_ranges << " value was restored after reboot for all ";
                std::cout << sensor_name << " sensor options --" << std::endl;
                example_validate_sensor_options_values_by_range(static_cast<k_api::VisionConfig::Sensor> (sensor_index), *iter_value_ranges, vision, device_id);
            }
        }
        else
        {
            std::cout << std::endl;
        }
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
    auto vision = new k_api::VisionConfig::VisionConfigClient(router);
    auto device_manager = new k_api::DeviceManager::DeviceManagerClient(router);
    auto device_config = new k_api::DeviceConfig::DeviceConfigClient(router);

    // Example core
    example_display_usage();
    uint32_t vision_device_id = example_vision_get_device_id(device_manager);

    if (vision_device_id != 0)
    {
        example_routed_vision_get_option_information(vision, vision_device_id);
        example_routed_vision_get_sensor_options_values(vision, vision_device_id);
        example_routed_vision_set_sensor_options_values(vision, vision_device_id);
        example_routed_vision_confirm_saved_sensor_options_values(vision, device_config, vision_device_id);
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
    delete device_config;
    delete session_manager;
    delete router;
    delete transport;
}