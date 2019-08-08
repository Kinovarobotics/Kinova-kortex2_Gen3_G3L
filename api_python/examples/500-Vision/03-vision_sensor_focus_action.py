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
#  - Configure the Vision Color Sensor to 1280x720 resolution                        #
#  - Position the robot so you can easily place objects in front of the Color camera #
#  - Select the Camera view page                                                     #
######################################################################################

import sys
import os
import time

from kortex_api.autogen.client_stubs.VisionConfigClientRpc import VisionConfigClient
from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, DeviceManager_pb2, VisionConfig_pb2

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
    print("\t#  - Configure the Vision Color Sensor to 1280x720 resolution                        #")
    print("\t#  - Position the robot so you can easily place objects in front of the Color camera #")
    print("\t#  - Select the Camera view page                                                     #")
    print("\t######################################################################################")
    print("\n")

#
# Wait for 10 seconds, allowing to see the effects of the focus action
#
def example_wait_for_focus_action():
    print("-- Waiting for 10 seconds to observe the effects of the focus action... --")
    time.sleep(10)

#
# Example showing how to play with the auto-focus of the Color camera
#
def example_routed_vision_do_autofocus_action(vision_config, vision_device_id):
    print("\n** Example showing how to play with the auto-focus of the Color camera **")
    sensor_focus_action = VisionConfig_pb2.SensorFocusAction()
    sensor_focus_action.sensor = VisionConfig_pb2.SENSOR_COLOR

    print("\n-- Using Vision Config Service to disable the auto-focus --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_DISABLE_FOCUS
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Place or remove an object from the center of the camera, observe the focus doesn't change --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to enable the auto-focus --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_START_CONTINUOUS_FOCUS
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Place an object in the center of the camera, observe the focus adjusts automatically --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to pause the auto-focus --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_PAUSE_CONTINUOUS_FOCUS
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Move the object away from the center of the camera and then back, but at a different distance, observe the focus doesn't change --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to focus now --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_FOCUS_NOW
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Observe the focus tried to adjust to the object in front to the camera --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to re-enable the auto-focus --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_START_CONTINUOUS_FOCUS
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Move the object away from the center of the camera and then back, but at a different distance, observe the focus adjusts automatically --")
    example_wait_for_focus_action()

#
# Example showing how to set the focus of the Color camera to a X-Y point in the camera image
#
def example_routed_vision_set_focus_point(vision_config, vision_device_id):
    print("\n** Example showing how to set the focus of the Color camera to a X-Y point in the camera image **")
    sensor_focus_action = VisionConfig_pb2.SensorFocusAction()
    sensor_focus_action.sensor = VisionConfig_pb2.SENSOR_COLOR

    print("\n-- Using Vision Config Service to set the focus point in the center of the lower right quadrant of the camera image --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_SET_FOCUS_POINT
    sensor_focus_action.focus_point.x = int(1280*3/4)
    sensor_focus_action.focus_point.y = int(720*3/4)
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_FOCUS_NOW
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Place an object in the center of the lower right quadrant of the camera image, observe the object gets into focus --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to set the focus point back in the middle the camera image--")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_SET_FOCUS_POINT
    sensor_focus_action.focus_point.x = int(1280/2)
    sensor_focus_action.focus_point.y = int(720/2)
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_FOCUS_NOW
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Place an object in the center of the camera image, observe the object gets into focus --")
    example_wait_for_focus_action()

#
# Example showing how to set the manual focus of the Color camera (changes the focus distance)
#
def example_routed_vision_set_manual_focus(vision_config, vision_device_id):
    print("\n** Example showing how to set the manual focus of the Color camera (changes the focus distance) **")
    sensor_focus_action = VisionConfig_pb2.SensorFocusAction()
    sensor_focus_action.sensor = VisionConfig_pb2.SENSOR_COLOR

    print("\n-- Using Vision Config Service to set the manual focus on a very close object (close-up view) --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_SET_MANUAL_FOCUS
    sensor_focus_action.manual_focus.value = 1023 # Maximum accepted value
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Place an object at around 2 inches away from the center of the camera, observe the object is in focus --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to set the manual focus on an object at a greater distance --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_SET_MANUAL_FOCUS
    sensor_focus_action.manual_focus.value = 0 # Mininum accepted value
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Move the object away from the camera until it gets into focus --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to set the manual focus on a relatively close object (normal view) --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_SET_MANUAL_FOCUS
    sensor_focus_action.manual_focus.value = 350
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Move the object at around 8 inches away from the center of the camera, observe the object is in focus --")
    example_wait_for_focus_action()

    print("\n-- Using Vision Config Service to re-enable the auto-focus --")
    sensor_focus_action.focus_action = VisionConfig_pb2.FOCUSACTION_START_CONTINUOUS_FOCUS
    vision_config.DoSensorFocusAction(sensor_focus_action, vision_device_id)
    print("-- Move the object away from the camera and then back, but at a different distance, observe the focus adjusts automatically --")
    example_wait_for_focus_action()

def main():
    # Import the utilities helper module
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    args = utilities.parseConnectionArguments()
    
    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        device_manager = DeviceManagerClient(router)
        vision_config = VisionConfigClient(router)

        # example core
        vision_device_id = example_vision_get_device_id(device_manager)

        if vision_device_id != 0:
            example_routed_vision_do_autofocus_action(vision_config, vision_device_id)
            example_routed_vision_set_focus_point(vision_config, vision_device_id)
            example_routed_vision_set_manual_focus(vision_config, vision_device_id)

if __name__ == "__main__":
    main()
