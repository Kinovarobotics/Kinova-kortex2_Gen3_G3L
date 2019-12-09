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

import sys
import os

from kortex_api.autogen.client_stubs.VisionConfigClientRpc import VisionConfigClient
from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, DeviceManager_pb2, VisionConfig_pb2

#
# Dictionary of all Sensor strings
#
all_sensor_strings = {
    VisionConfig_pb2.SENSOR_UNSPECIFIED : "Unspecified sensor",
    VisionConfig_pb2.SENSOR_COLOR       : "Color",
    VisionConfig_pb2.SENSOR_DEPTH       : "Depth"
}

#
# Dictionary of all Resolution strings
#
all_resolution_strings = {
    VisionConfig_pb2.RESOLUTION_UNSPECIFIED : "Unspecified resolution",
    VisionConfig_pb2.RESOLUTION_320x240     : "320x240",
    VisionConfig_pb2.RESOLUTION_424x240     : "424x240",
    VisionConfig_pb2.RESOLUTION_480x270     : "480x270",
    VisionConfig_pb2.RESOLUTION_640x480     : "640x480",
    VisionConfig_pb2.RESOLUTION_1280x720    : "1280x720",
    VisionConfig_pb2.RESOLUTION_1920x1080   : "1920x1080"
}


#
# Example related functions
#

#
# Returns a string matching the requested sensor
#
def sensor_to_string(sensor):
    return all_sensor_strings.get(sensor, "Unknown sensor")

#
# Returns a string matching the requested resolution
#
def resolution_to_string(resolution):
    return all_resolution_strings.get(resolution, "Unknown resolution")

#
# Prints the intrinsic parameters on stdout
#
def print_intrinsic_parameters(intrinsics):
    print("Sensor: {0} ({1})".format(intrinsics.sensor, sensor_to_string(intrinsics.sensor)))
    print("Resolution: {0} ({1})".format(intrinsics.resolution, resolution_to_string(intrinsics.resolution)))
    print("Principal point x: {0:.6f}".format(intrinsics.principal_point_x))
    print("Principal point y: {0:.6f}".format(intrinsics.principal_point_y))
    print("Focal length x: {0:.6f}".format(intrinsics.focal_length_x))
    print("Focal length y: {0:.6f}".format(intrinsics.focal_length_y))
    print("Distortion coefficients: [{0:.6f} {1:.6f} {2:.6f} {3:.6f} {4:.6f}]".format( \
                                    intrinsics.distortion_coeffs.k1, \
                                    intrinsics.distortion_coeffs.k2, \
                                    intrinsics.distortion_coeffs.p1, \
                                    intrinsics.distortion_coeffs.p2, \
                                    intrinsics.distortion_coeffs.k3))

#
# Example core functions
#

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
# Example showing how to retrieve the intrinsic parameters of the Color and Depth sensors
#
def example_routed_vision_get_intrinsics(vision_config, vision_device_id):
    sensor_id = VisionConfig_pb2.SensorIdentifier()
    profile_id = VisionConfig_pb2.IntrinsicProfileIdentifier()

    print("\n\n** Example showing how to retrieve the intrinsic parameters of the Color and Depth sensors **")

    print("\n-- Using Vision Config Service to get intrinsic parameters of active color resolution --")
    sensor_id.sensor = VisionConfig_pb2.SENSOR_COLOR
    intrinsics = vision_config.GetIntrinsicParameters(sensor_id, vision_device_id)
    print_intrinsic_parameters(intrinsics)

    print("\n-- Using Vision Config Service to get intrinsic parameters of active depth resolution --")
    sensor_id.sensor = VisionConfig_pb2.SENSOR_DEPTH
    intrinsics = vision_config.GetIntrinsicParameters(sensor_id, vision_device_id)
    print_intrinsic_parameters(intrinsics)

    print("\n-- Using Vision Config Service to get intrinsic parameters for color resolution 1920x1080 --")
    profile_id.sensor = VisionConfig_pb2.SENSOR_COLOR
    profile_id.resolution = VisionConfig_pb2.RESOLUTION_1920x1080
    intrinsics = vision_config.GetIntrinsicParametersProfile(profile_id, vision_device_id)
    print_intrinsic_parameters(intrinsics)

    print("\n-- Using Vision Config Service to get intrinsic parameters for depth resolution 424x240 --")
    profile_id.sensor = VisionConfig_pb2.SENSOR_DEPTH
    profile_id.resolution = VisionConfig_pb2.RESOLUTION_424x240
    intrinsics = vision_config.GetIntrinsicParametersProfile(profile_id, vision_device_id)
    print_intrinsic_parameters(intrinsics)

#
# Example showing how to set the intrinsic parameters of the Color and Depth sensors
#
def example_routed_vision_set_intrinsics(vision_config, vision_device_id):
    profile_id = VisionConfig_pb2.IntrinsicProfileIdentifier()
    intrinsics_new = VisionConfig_pb2.IntrinsicParameters()

    print("\n\n** Example showing how to set the intrinsic parameters of the Color and Depth sensors **")

    print("\n-- Using Vision Config Service to get current intrinsic parameters for color resolution 640x480 --")
    profile_id.sensor = VisionConfig_pb2.SENSOR_COLOR
    profile_id.resolution = VisionConfig_pb2.RESOLUTION_640x480
    intrinsics_old = vision_config.GetIntrinsicParametersProfile(profile_id, vision_device_id)
    print_intrinsic_parameters(intrinsics_old)

    print("\n-- Using Vision Config Service to set new intrinsic parameters for color resolution 640x480 --")
    intrinsics_new.sensor = profile_id.sensor
    intrinsics_new.resolution = profile_id.resolution
    intrinsics_new.principal_point_x = 640 / 2 + 0.123456
    intrinsics_new.principal_point_y = 480 / 2 + 1.789012
    intrinsics_new.focal_length_x = 650.567890
    intrinsics_new.focal_length_y = 651.112233
    intrinsics_new.distortion_coeffs.k1 = 0.2
    intrinsics_new.distortion_coeffs.k2 = 0.05
    intrinsics_new.distortion_coeffs.p1 = 1.2
    intrinsics_new.distortion_coeffs.p2 = 0.999999
    intrinsics_new.distortion_coeffs.k3 = 0.001
    vision_config.SetIntrinsicParameters(intrinsics_new, vision_device_id)

    print("\n-- Using Vision Config Service to get new intrinsic parameters for color resolution 640x480 --")
    intrinsics_reply = vision_config.GetIntrinsicParametersProfile(profile_id, vision_device_id)
    print_intrinsic_parameters(intrinsics_reply)

    print("\n-- Using Vision Config Service to set back old intrinsic parameters for color resolution 640x480 --")
    vision_config.SetIntrinsicParameters(intrinsics_old, vision_device_id)


    print("\n-- Using Vision Config Service to get current intrinsic parameters for depth resolution 424x240 --")
    profile_id.sensor = VisionConfig_pb2.SENSOR_DEPTH
    profile_id.resolution = VisionConfig_pb2.RESOLUTION_424x240
    intrinsics_old = vision_config.GetIntrinsicParametersProfile(profile_id, vision_device_id)
    print_intrinsic_parameters(intrinsics_old)

    print("\n-- Using Vision Config Service to set new intrinsic parameters for depth resolution 424x240 --")
    intrinsics_new.sensor = profile_id.sensor
    intrinsics_new.resolution = profile_id.resolution
    intrinsics_new.principal_point_x = 424 / 2 + 0.123456
    intrinsics_new.principal_point_y = 240 / 2 + 1.789012
    intrinsics_new.focal_length_x = 315.567890
    intrinsics_new.focal_length_y = 317.112233
    intrinsics_new.distortion_coeffs.k1 = 0.425
    intrinsics_new.distortion_coeffs.k2 = 1.735102
    intrinsics_new.distortion_coeffs.p1 = 0.1452
    intrinsics_new.distortion_coeffs.p2 = 0.767574
    intrinsics_new.distortion_coeffs.k3 = 2.345678
    vision_config.SetIntrinsicParameters(intrinsics_new, vision_device_id)

    print("\n-- Using Vision Config Service to get new intrinsic parameters for depth resolution 424x240 --")
    intrinsics_reply = vision_config.GetIntrinsicParametersProfile(profile_id, vision_device_id)
    print_intrinsic_parameters(intrinsics_reply)

    print("\n-- Using Vision Config Service to set back old intrinsic parameters for depth resolution 424x240 --")
    vision_config.SetIntrinsicParameters(intrinsics_old, vision_device_id)

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
            example_routed_vision_get_intrinsics(vision_config, vision_device_id)
            example_routed_vision_set_intrinsics(vision_config, vision_device_id)

if __name__ == "__main__":
    main()