#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2019 Kinova inc. All rights reserved.
#
# This software may be modified and distributed
# under the terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

######################################################################################
# To use these examples:                                                             #
#  - Connect to the robot's web page                                                 #
#  - Select the Camera view page                                                     #
#  - Observe the effects of changing the Color sensor options                        #
######################################################################################

import sys
import os
import time

from kortex_api.autogen.client_stubs.VisionConfigClientRpc import VisionConfigClient
from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, DeviceManager_pb2, VisionConfig_pb2

# Lists of supported options for a sensor
supported_color_options = []
supported_depth_options = []

#
# Returns the device identifier of the Vision module, 0 if not found
#
def example_vision_get_device_id(device_manager):
    vision_device_id = 0
    
    # Getting all device routing information (from DeviceManagerClient service)
    all_devices_info = device_manager.ReadAllDevices()

    vision_handles = [ hd for hd in all_devices_info.device_handle if hd.device_type == DeviceConfig_pb2.VISION ]
    if len(vision_handles) == 0:
        print("Error: there is no vision device registered in the devices info")
    elif len(vision_handles) > 1:
        print("Error: there are more than one vision device registered in the devices info")
    else:
        handle = vision_handles[0]
        vision_device_id = handle.device_identifier
        print("Vision module found, device Id: {0}".format(vision_device_id))

    return vision_device_id

#
# Display how to use these examples
#
def example_display_usage():
    print("\n")
    print("\t######################################################################################")
    print("\t# To use these examples:                                                             #")
    print("\t#  - Connect to the robot's web page                                                 #")
    print("\t#  - Select the Camera view page                                                     #")
    print("\t#  - Observe the effects of changing the Color sensor options                        #")
    print("\t######################################################################################")
    print("\n")

#
# Get the name of a sensor
#
def example_get_sensor_name(sensor):
    if sensor == VisionConfig_pb2.SENSOR_COLOR:
        name = "COLOR"
    elif sensor == VisionConfig_pb2.SENSOR_DEPTH:
        name = "DEPTH"
    else:
        name = "***UNSUPPORTED***"
    return name

#
# Get the list of supported options for a sensor
# Each list item is a dictionary describing an option information
#
def example_get_sensor_supported_options(sensor):
    if sensor == VisionConfig_pb2.SENSOR_COLOR:
        supported_option = supported_color_options
    elif sensor == VisionConfig_pb2.SENSOR_DEPTH:
        supported_option = supported_depth_options
    else:
        supported_option = []
    return supported_option

#
# Display the information of a specific sensor option
#
def example_display_sensor_option_information(option_info):
    print("Option id: {0:02d}  name: {1}  is_writable: {2}\n" \
        "minimum: {3:0.06f}  maximum: {4:0.06f}\n" \
        "   step: {5:0.06f}  default: {6:0.06f}\n" \
        .format(option_info['id'], option_info['name'], option_info['writable'], \
        option_info['min'], option_info['max'], option_info['step'], option_info['default']))

#
# Add option information to a list of supported options for a sensor
# The added item is a dictionary describing the option information, with the following fields:
#   'id', 'name', 'writable', 'min', 'max', 'step', 'default'
# Then, display the option information
#
def example_add_and_display_sensor_supported_option(option_info):
    display_option_info = True
    option_info_dict = {}

    option_info_dict['id'] = option_info.option
    option_info_dict['name'] = VisionConfig_pb2.Option.Name(option_info.option)
    option_info_dict['writable'] = True if int(option_info.read_only) == 0 else False
    option_info_dict['min'] = option_info.minimum
    option_info_dict['max'] = option_info.maximum
    option_info_dict['step'] = option_info.step
    option_info_dict['default'] = option_info.default_value

    if option_info.sensor == VisionConfig_pb2.SENSOR_COLOR:
        supported_color_options.append(option_info_dict)
    elif option_info.sensor == VisionConfig_pb2.SENSOR_DEPTH:
        supported_depth_options.append(option_info_dict)
    else:
        print("Unsupported sensor {0} for option id {1}, not adding to any list!".format(option_info.sensor, option_info.option))
        display_option_info = False

    # Display option information
    if display_option_info:
        example_display_sensor_option_information(option_info_dict)

#
# For all sensor options, set their value based on the specified range
#
def example_set_sensor_options_values_by_range(sensor, value_range, vision_config, vision_device_id):
    option_value = VisionConfig_pb2.OptionValue()
    sensor_options = example_get_sensor_supported_options(sensor)
    option_value.sensor = sensor

    for option in sensor_options:
        if option['writable']:
            try:
                option_value.option = option['id']
                option_value.value = option[value_range]
                vision_config.SetOptionValue(option_value, vision_device_id)
                print("Set value ({0:0.06f}) for option '{1}'".format(option_value.value, option['name']))
            except Exception as ex:
                print("Failed to set {0} value for option '{1}': {2}".format(value_range, option['name'], str(ex)))

#
# For all sensor options, validate their value based on the specified range
#
def example_validate_sensor_options_values_by_range(sensor, value_range, vision_config, vision_device_id):
    option_identifier = VisionConfig_pb2.OptionIdentifier()
    option_value_reply = VisionConfig_pb2.OptionValue()
    sensor_options = example_get_sensor_supported_options(sensor)
    option_identifier.sensor = sensor

    for option in sensor_options:
        if option['writable']:
            try:
                option_identifier.option = option['id']
                option_value_reply = vision_config.GetOptionValue(option_identifier, vision_device_id)
                print("Confirm received value ({0:0.06f}) for option '{1}' --> {2}" \
                    .format(option_value_reply.value, option['name'], \
                    "OK" if option_value_reply.value == option[value_range] else "*** FAILED ***"))
            except Exception as ex:
                print("Failed to get value for option '{0}': {1}".format(option['name'], str(ex)))


#
# Example showing how to get the sensors options information
# Note: This function must be called in order to fill up the lists of sensors supported options
#
def example_routed_vision_get_option_information(vision_config, vision_device_id):
    print("\n** Example showing how to get the sensors options information **")
    sensors = VisionConfig_pb2.Sensor.values()[1:]
    options = VisionConfig_pb2.Option.values()[1:]
    option_identifier = VisionConfig_pb2.OptionIdentifier()

    # For all sensors, determine which options are supported and populate specific list
    for sensor in sensors:
        option_identifier.sensor = sensor
        sensor_name = example_get_sensor_name(sensor)
        print("\n-- Using Vision Config Service to get information for all {0} sensor options --".format(sensor_name))
        for option in options:
            try:
                option_identifier.option = option
                option_info = vision_config.GetOptionInformation(option_identifier, vision_device_id)
                if option_info.sensor == sensor and option_info.option == option:
                    if int(option_info.supported) == 1:
                        example_add_and_display_sensor_supported_option(option_info)
                else:
                    print("Unexpected mismatch of sensor or option in returned information for option id {0}!".format(option))
            except Exception:
                # The option is simply not supported
                pass

#
# Example showing how to get the sensors options values
#
def example_routed_vision_get_sensor_options_values(vision_config, vision_device_id):
    print("\n** Example showing how to get the sensors options values **")
    sensors = VisionConfig_pb2.Sensor.values()[1:]
    option_identifier = VisionConfig_pb2.OptionIdentifier()

    # For all sensors, get their supported options value
    for sensor in sensors:
        option_identifier.sensor = sensor
        sensor_name = example_get_sensor_name(sensor)
        sensor_options = example_get_sensor_supported_options(sensor)
        print("\n-- Using Vision Config Service to get value for all {0} sensor options --".format(sensor_name))
        for option in sensor_options:
            try:
                option_identifier.option = option['id']
                option_value = vision_config.GetOptionValue(option_identifier, vision_device_id)
                print("Option '{0}' has value {1:0.06f}".format(option['name'], option_value.value))
            except Exception as ex:
                print("Failed to get value of option '{0}': {1}".format(option['name'], str(ex)))
        print("")

#
# Example showing how to set the sensors options values
#
def example_routed_vision_set_sensor_options_values(vision_config, vision_device_id):
    print("\n** Example showing how to set the sensors options values **")
    sensors = VisionConfig_pb2.Sensor.values()[1:]

    # For all sensors, set and confirm options values
    for value_range in ['max', 'default']:
        for sensor in sensors:
            sensor_name = example_get_sensor_name(sensor)

            print("\n-- Using Vision Config Service to set {0} value for all {1} sensor options --".format(value_range, sensor_name))
            example_set_sensor_options_values_by_range(sensor, value_range, vision_config, vision_device_id)

            print("\n-- Using Vision Config Service to confirm {0} value was set for all {1} sensor options --".format(value_range, sensor_name))
            example_validate_sensor_options_values_by_range(sensor, value_range, vision_config, vision_device_id)

            if sensor == VisionConfig_pb2.SENSOR_COLOR:
                print("\n-- Waiting for 5 seconds to observe the effects of the new COLOR sensor options values... --")
                time.sleep(5)
            else:
                print("")

#
# Example confirming that sensors options values are restored upon a reboot of the Vision module
#
def example_routed_vision_confirm_saved_sensor_options_values(vision_config, device_config, vision_device_id):
    print("\n** Example confirming that sensors options values are restored upon a reboot of the Vision module **")
    sensors = VisionConfig_pb2.Sensor.values()[1:]

    # For all sensors, set and confirm options values
    for value_range in ['min', 'default']:
        for sensor in sensors:
            sensor_name = example_get_sensor_name(sensor)

            print("\n-- Using Vision Config Service to set {0} value for all {1} sensor options --".format(value_range, sensor_name))
            example_set_sensor_options_values_by_range(sensor, value_range, vision_config, vision_device_id)

            print("\n-- Using Vision Config Service to confirm {0} value was set for all {1} sensor options --".format(value_range, sensor_name))
            example_validate_sensor_options_values_by_range(sensor, value_range, vision_config, vision_device_id)

        # If we just set the options' minimum value, reboot the Vision module device
        if value_range == "min":
            # Reboot with a delay
            delay_to_reboot_ms = 5000
            reboot_request = DeviceConfig_pb2.RebootRqst()
            reboot_request.delay = delay_to_reboot_ms
            print("\n-- Using Device Config Service to reboot the Vision module in {0} milliseconds. Please wait... --".format(delay_to_reboot_ms))
            device_config.RebootRequest(reboot_request, vision_device_id)

            # Wait until the Vision module is rebooted completely
            wait_after_reboot_sec = 35 + (delay_to_reboot_ms / 1000)
            time.sleep(wait_after_reboot_sec)

            # For all sensors, confirm their option values were restored
            for sensor in sensors:
                sensor_name = example_get_sensor_name(sensor)

                print("\n-- Using Vision Config Service to confirm {0} value was restored after reboot for all {1} sensor options --".format(value_range, sensor_name))
                example_validate_sensor_options_values_by_range(sensor, value_range, vision_config, vision_device_id)
        else:
            print("")

def main():
    # Import the utilities helper module
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    args = utilities.parseConnectionArguments()
    
    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        device_manager = DeviceManagerClient(router)
        device_config = DeviceConfigClient(router)
        vision_config = VisionConfigClient(router)

        # example core
        vision_device_id = example_vision_get_device_id(device_manager)

        if vision_device_id != 0:
            example_routed_vision_get_option_information(vision_config, vision_device_id)
            example_routed_vision_get_sensor_options_values(vision_config, vision_device_id)
            example_routed_vision_set_sensor_options_values(vision_config, vision_device_id)
            example_routed_vision_confirm_saved_sensor_options_values(vision_config, device_config, vision_device_id)

if __name__ == "__main__":
    main()
            