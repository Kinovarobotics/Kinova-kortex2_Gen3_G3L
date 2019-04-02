#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2018 Kinova inc. All rights reserved.
#
# This software may be modified and distributed
# under the under the terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

from kortex_api.UDPTransport import UDPTransport
from kortex_api.RouterClient import RouterClient
from kortex_api.SessionManager import SessionManager

from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2

def example_api_creation():

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
    session_info.session_inactivity_timeout = 60000   # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    print("Creating session for communication")
    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)
    print("Session created")

    # Create required services
    device_config_service = DeviceConfigClient(router)
    base_client_service = BaseClient(router)

    print(device_config_service.GetDeviceType())
    print(base_client_service.GetAvailableWifi())

    # Close API session
    session_manager.CloseSession()

    # Deactivate the router and cleanly disconnect from the transport object
    router.SetActivationStatus(False)
    transport.disconnect()


if __name__ == "__main__":

    # Example core
    example_api_creation()
