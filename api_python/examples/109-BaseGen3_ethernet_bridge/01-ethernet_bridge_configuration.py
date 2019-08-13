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
import time

from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.InterconnectConfigClientRpc import InterconnectConfigClient
from kortex_api.autogen.messages import Session_pb2, Base_pb2, Common_pb2, InterconnectConfig_pb2, DeviceManager_pb2


class EthernetBridgeConfigurationExample:
    def __init__(self, router):
        # Create required services        
        self.interconnect_config = InterconnectConfigClient(router)
        self.device_manager = DeviceManagerClient(router)
        
        self.interconnect_device_id = self.GetDeviceIdFromDevType(Common_pb2.INTERCONNECT, 0)
        if (self.interconnect_device_id is None):
            print ("Could not find the Interconnect in the device list, exiting...")
            sys.exit(0)

    def GetDeviceIdFromDevType(self, device_type, device_index = 0):
        devices = self.device_manager.ReadAllDevices()

        current_index = 0
        for device in devices.device_handle:
            if device.device_type == device_type:
                if current_index == device_index:
                    print ("Found the Interconnect on device identifier {}".format(device.device_identifier))
                    return device.device_identifier
                current_index += 1
        return None

    def EnableEthernetBridge(self):

        # Configure the Interconnect to enable the bridge
        ethernet_configuration = InterconnectConfig_pb2.EthernetConfiguration()
        ethernet_configuration.device = InterconnectConfig_pb2.ETHERNET_DEVICE_EXPANSION
        ethernet_configuration.enabled = True
        ethernet_configuration.speed = InterconnectConfig_pb2.ETHERNET_SPEED_100M
        ethernet_configuration.duplex = InterconnectConfig_pb2.ETHERNET_DUPLEX_FULL
        try:
            self.interconnect_config.SetEthernetConfiguration(ethernet_configuration, self.interconnect_device_id)
        except Exception as e:
            print ("An unexpected error occured : {}".format(e))

def main():
    # Import the utilities helper module
    import argparse
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--interface_name", type=str, help="Name of the network interface connected to the arm")
    parser.add_argument("--device_ip_address", type=str, help="IP address of the device connected to the arm (must be in sub-network 10.20.0.0/24")
    args = utilities.parseConnectionArguments(parser)

    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        example = EthernetBridgeConfigurationExample(router)
        example.EnableEthernetBridge()

if __name__ == "__main__":
    main()
