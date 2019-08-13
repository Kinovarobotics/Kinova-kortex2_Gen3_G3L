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
# Example related function
#

#
# Prints the extrinsic parameters on stdout
#
def print_extrinsic_parameters(extrinsics):
    print("Rotation matrix:")
    print("[{0: .6f} {1: .6f} {2: .6f}".format ( \
            extrinsics.rotation.row1.column1, extrinsics.rotation.row1.column2, extrinsics.rotation.row1.column3))
    print(" {0: .6f} {1: .6f} {2: .6f}".format ( \
            extrinsics.rotation.row2.column1, extrinsics.rotation.row2.column2, extrinsics.rotation.row2.column3))
    print(" {0: .6f} {1: .6f} {2: .6f}]".format ( \
            extrinsics.rotation.row3.column1, extrinsics.rotation.row3.column2, extrinsics.rotation.row3.column3))
    print("Translation vector: [{0:.6f} {1:.6f} {2:.6f}]".format( \
                                extrinsics.translation.t_x, extrinsics.translation.t_y, extrinsics.translation.t_z))

#
# Example core functions
#

#
# Returns the device identifier of the Vision module, 0 if not found
#
def example_vision_get_device_id(device_manager):
    vision_device_id = 0
    
    # getting all device routing information (from DeviceManagerClient service)
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
# Example showing how to retrieve the extrinsic parameters
#
def example_routed_vision_get_extrinsics(vision_config, vision_device_id):
    print("\n\n** Example showing how to retrieve the extrinsic parameters **")

    print("\n-- Using Vision Config Service to get extrinsic parameters --")
    extrinsics = vision_config.GetExtrinsicParameters(vision_device_id)
    print_extrinsic_parameters(extrinsics)

#
# Example showing how to set the extrinsic parameters
#
def example_routed_vision_set_extrinsics(vision_config, vision_device_id):
    extrinsics_new = VisionConfig_pb2.ExtrinsicParameters()

    print("\n\n** Example showing how to set the extrinsic parameters **")

    print("\n-- Using Vision Config Service to get current extrinsic parameters --")
    extrinsics_old = vision_config.GetExtrinsicParameters(vision_device_id)
    print_extrinsic_parameters(extrinsics_old)

    print("\n-- Using Vision Config Service to set new extrinsic parameters --")
    extrinsics_new.rotation.row1.column1 = 1.0001
    extrinsics_new.rotation.row1.column2 = 0.1
    extrinsics_new.rotation.row1.column3 = -0.01
    extrinsics_new.rotation.row2.column1 = -0.001
    extrinsics_new.rotation.row2.column2 = 1.0002
    extrinsics_new.rotation.row2.column3 = 0.0001
    extrinsics_new.rotation.row3.column1 = 0.00001
    extrinsics_new.rotation.row3.column2 = -0.000001
    extrinsics_new.rotation.row3.column3 = 1.0003
    extrinsics_new.translation.t_x = -0.026123456
    extrinsics_new.translation.t_y = -0.009876543
    extrinsics_new.translation.t_z = 0.00002
    vision_config.SetExtrinsicParameters(extrinsics_new, vision_device_id)

    print("\n-- Using Vision Config Service to get new extrinsic parameters --")
    extrinsics_reply = vision_config.GetExtrinsicParameters(vision_device_id)
    print_extrinsic_parameters(extrinsics_reply)

    print("\n-- Using Vision Config Service to set back old extrinsic parameters --")
    vision_config.SetExtrinsicParameters(extrinsics_old, vision_device_id)

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
            example_routed_vision_get_extrinsics(vision_config, vision_device_id)
            example_routed_vision_set_extrinsics(vision_config, vision_device_id)

if __name__ == "__main__":
    main()
