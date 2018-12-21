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

from jaco3_armbase.UDPTransport import UDPTransport
from jaco3_armbase.RouterClient import RouterClient
from jaco3_armbase.SessionManager import SessionManager

from jaco3_armbase.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from jaco3_armbase.autogen.client_stubs.BaseClientRpc import BaseClient

from jaco3_armbase.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2

def example_api_creation():

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    transport = UDPTransport()
    transport.connect(DEVICE_IP, DEVICE_PORT)
    router = RouterClient(transport, lambda kException: print("Error during connection"))

    # create session
    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 60000  # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    print("Creating session for communication")
    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    # create requested services
    device_config_service = DeviceConfigClient(router)
    base_client_service = BaseClient(router)

    print(device_config_service.GetDeviceType())
    print(base_client_service.GetAvailableWifi())

    session_manager.CloseSession()


if __name__ == "__main__":

    # example core
    example_api_creation()
