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

from kortex_api.UDPTransport import UDPTransport
from kortex_api.RouterClient import RouterClient, RouterClientSendOptions
from kortex_api.SessionManager import SessionManager

from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import Common_pb2, DeviceManager_pb2, DeviceConfig_pb2, Session_pb2, Base_pb2

from google.protobuf import json_format

def example_routed_device_config(device_manager_service, device_config_service):

    # Get all device routing information (from DeviceManagerClient service)
    print("-- ReadAllDevices --\n")
    allDevicesInfo = device_manager_service.ReadAllDevices()

    # Uncomment next line to print 'allDevicesInfo' in JSON format
    # print(json_format.MessageToJson(allDevicesInfo))

    options = RouterClientSendOptions()
    options.timeout_ms = 4000

    # Use device routing information to route to every devices (base, actuator, interconnect, etc.) in the arm/base system and request their general device information
    for dev in allDevicesInfo.device_handle:
        deviceInfo = {}
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetDeviceType           (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetFirmwareVersion      (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetBootloaderVersion    (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetModelNumber          (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetPartNumber           (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetPartNumberRevision   (dev.device_identifier, options) ) )
        deviceInfo.update( json_format.MessageToDict( device_config_service.GetSerialNumber         (dev.device_identifier, options) ) )

        # Get hexadecimal representation of MAC address
        macAddress_hexstr = ""
        for b in device_config_service.GetMACAddress(dev.device_identifier, options).mac_address : macAddress_hexstr += "%02X" % b
        deviceInfo.update( { "macAddress": macAddress_hexstr } )

        print("-----------------------------")
        print("-- {}: id = {} --".format(Common_pb2._DEVICETYPES.values_by_number[dev.device_type].name, dev.device_identifier))
        for key, value in deviceInfo.items():
            print(str("%20s") % key + " => " + str(value))


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    # Setup API
    errorCallback = lambda kException: print("_________ callback error _________ {}".format(kException))
    transport = UDPTransport()
    router = RouterClient(transport, errorCallback)
    transport.connect(DEVICE_IP, DEVICE_PORT)

    # Create session
    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout =  60000  # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    # Create required services
    device_manager_service = DeviceManagerClient(router)
    device_config_service = DeviceConfigClient(router)

    # Example core
    example_routed_device_config(device_manager_service, device_config_service)

    # Close API session
    session_manager.CloseSession()

    # Deactivate the router and cleanly disconnect from the transport object
    router.SetActivationStatus(False)
    transport.disconnect()
