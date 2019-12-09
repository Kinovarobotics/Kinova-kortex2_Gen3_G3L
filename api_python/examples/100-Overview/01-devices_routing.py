#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2018 Kinova inc. All rights reserved.
#
# This software may be modified and distributed
# under the terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

import sys
import os

from kortex_api.RouterClient import RouterClientSendOptions

from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import Common_pb2, DeviceManager_pb2, DeviceConfig_pb2, Session_pb2, Base_pb2, ProductConfiguration_pb2

from google.protobuf import json_format

def example_routed_device_config(device_manager, device_config):

    # Get all device routing information (from DeviceManagerClient service)
    all_devices_info = device_manager.ReadAllDevices()

    # Uncomment next line to print 'all_devices_info' in JSON format
    # print(json_format.MessageToJson(all_devices_info))

    options = RouterClientSendOptions()
    options.timeout_ms = 4000

    # Use device routing information to route to every devices (base, actuator, interconnect, etc.) in the arm/base system and request their general device information
    for dev in all_devices_info.device_handle:
        device_info = {}
        device_info.update( json_format.MessageToDict( device_config.GetDeviceType           (dev.device_identifier, options) ) )
        device_info.update( json_format.MessageToDict( device_config.GetFirmwareVersion      (dev.device_identifier, options) ) )
        device_info.update( json_format.MessageToDict( device_config.GetBootloaderVersion    (dev.device_identifier, options) ) )
        device_info.update( json_format.MessageToDict( device_config.GetModelNumber          (dev.device_identifier, options) ) )
        device_info.update( json_format.MessageToDict( device_config.GetPartNumber           (dev.device_identifier, options) ) )
        device_info.update( json_format.MessageToDict( device_config.GetPartNumberRevision   (dev.device_identifier, options) ) )
        device_info.update( json_format.MessageToDict( device_config.GetSerialNumber         (dev.device_identifier, options) ) )

        # Get hexadecimal representation of MAC address
        macAddress_hexstr = ""
        for b in device_config.GetMACAddress(dev.device_identifier, options).mac_address:
                macAddress_hexstr += "%02X:" % b
        macAddress_hexstr = macAddress_hexstr[:-1] # remove last ':'
        device_info.update( { "macAddress": macAddress_hexstr } )

        print("-----------------------------")
        print("-- {}: id = {} --".format(Common_pb2._DEVICETYPES.values_by_number[dev.device_type].name, dev.device_identifier))
        for key, value in device_info.items():
            print(str("%20s") % key + ": " + str(value))

def main():
    # Import the utilities helper module
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    args = utilities.parseConnectionArguments()
    
    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        # Create required services
        device_manager = DeviceManagerClient(router)
        device_config = DeviceConfigClient(router)

        # Example core
        example_routed_device_config(device_manager, device_config)

if __name__ == "__main__":
    main()
    