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

import sys
import os

from kortex_api.TCPTransport import TCPTransport
from kortex_api.RouterClient import RouterClient
from kortex_api.SessionManager import SessionManager

from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import DeviceConfig_pb2, Session_pb2, Base_pb2

def example_api_creation(args):
    '''
    This function creates all required objects and connections to use the arm's services.
    It is easier to use the DeviceConnection utility class to create the router and then 
    create the services you need (as done in the other examples).
    However, if you want to create all objects yourself, this function tells you how to do it.
    '''

    PORT = 10000

    # Setup API
    error_callback = lambda kException: print("_________ callback error _________ {}".format(kException))
    transport = TCPTransport()
    router = RouterClient(transport, error_callback)
    transport.connect(args.ip, PORT)

    # Create session
    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = args.username
    session_info.password = args.password
    session_info.session_inactivity_timeout = 60000   # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    print("Creating session for communication")
    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)
    print("Session created")

    # Create required services
    device_config = DeviceConfigClient(router)
    base = BaseClient(router)

    print(device_config.GetDeviceType())
    print(base.GetArmState())

    # Close API session
    session_manager.CloseSession()

    # Disconnect from the transport object
    transport.disconnect()

def main():
    # Import the utilities helper module
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    args = utilities.parseConnectionArguments()

    # Example core
    example_api_creation(args)
    
if __name__ == "__main__":
    main()