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

import time

from kortex_api.UDPTransport import UDPTransport
from kortex_api.RouterClient import RouterClient
from kortex_api.SessionManager import SessionManager

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import Session_pb2, Base_pb2


def example_twist_command(base_client_service):

    command = Base_pb2.TwistCommand()

    command.mode = Base_pb2.UNSPECIFIED_TWIST_MODE
    command.duration = 2  # Unlimited time to execute

    twist = command.twist
    twist.linear_x = 0
    twist.linear_y = 0
    twist.linear_z = 0
    twist.angular_x = 0
    twist.angular_y = 0
    twist.angular_z = 2
    base_client_service.SendTwistCommand(command)

    # Let time for twist to be executed
    time.sleep(5)

    # Send all 0 to make it stop
    twist.linear_x = 0
    twist.linear_y = 0
    twist.linear_z = 0
    twist.angular_x = 0
    twist.angular_y = 0
    twist.angular_z = 0
    base_client_service.SendTwistCommand(command)


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
    session_info.session_inactivity_timeout = 600000  # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    # Create required services
    base_client_service = BaseClient(router)

    # Move arm to ready position
    print("\nMoving the arm to a safe position before executing example")
    action_type = Base_pb2.RequestedActionType()
    action_type.action_type = Base_pb2.REACH_JOINT_ANGLES
    action_list = base_client_service.ReadAllActions(action_type)
    action_handle = None
    for action in action_list.action_list:
        if action.name == "Home":
            action_handle = action.handle

    if action_handle == None:
        import sys
        print("\nCan't reach safe position. Exiting")
        sys.exit(0)

    base_client_service.ExecuteActionFromReference(action_handle)
    time.sleep(20) # Leave time to action to complete

    # Example core
    example_twist_command(base_client_service)

    # Close API session
    session_manager.CloseSession()

    # Deactivate the router and cleanly disconnect from the transport object
    router.SetActivationStatus(False)
    transport.disconnect()
