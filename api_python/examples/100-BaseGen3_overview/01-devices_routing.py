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

from jaco3_armbase.UDPTransport import UDPTransport
from jaco3_armbase.RouterClient import RouterClient, RouterClientSendOptions
from jaco3_armbase.SessionManager import SessionManager

from jaco3_armbase.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from jaco3_armbase.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from jaco3_armbase.autogen.client_stubs.BaseClientRpc import BaseClient

from jaco3_armbase.autogen.messages import DeviceManager_pb2, DeviceConfig_pb2, Session_pb2, Base_pb2

from google.protobuf import json_format

def example_routed_device_config(device_manager_service, device_config_service):

    # getting all device routing information (from DeviceManagerClient service)
    print("-- ReadAllDevices --\n")
    subDevicesInfo = device_manager_service.ReadAllDevices()
    print(json_format.MessageToJson(subDevicesInfo))
    print("--------------------\n")

    options = RouterClientSendOptions()
    options.timeout_ms = 4000

    # using device routing information to route to every devices (base, actuator, interconnect, etc.) in the arm/base system and request their general device information
    for dev in subDevicesInfo.device_handle:
        deviceInfo = {}
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetDeviceType           (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetFirmwareVersion      (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetBootloaderVersion    (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetModelNumber          (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetPartNumber           (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetSerialNumber         (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetMACAddress           (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetPartNumberRevision   (dev.device_identifier, options) ) )

        print("-- sub-devices info --")
        print(" (devices id = %d)" % dev.device_identifier)
        for key, value in deviceInfo.items():
            print (str("%20s") % key + " => " + str(value))
        print("--------------------\n")


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    transport = UDPTransport()
    transport.connect(DEVICE_IP, DEVICE_PORT)
    router = RouterClient(transport, lambda kException: print("Error during connection"))

    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout =  60000 # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    device_manager_service = DeviceManagerClient(router)
    device_config_service = DeviceConfigClient(router)

    # example core
    example_routed_device_config(device_manager_service, device_config_service)

    session_manager.CloseSession()
