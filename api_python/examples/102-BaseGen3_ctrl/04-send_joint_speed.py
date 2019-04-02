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
from typing import Union

from google.protobuf.internal.python_message import GeneratedProtocolMessageType
from google.protobuf.pyext.cpp_message import GeneratedProtocolMessageType

from kortex_api.UDPTransport import UDPTransport
from kortex_api.RouterClient import RouterClient
from kortex_api.SessionManager import SessionManager

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient
from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient

from kortex_api.autogen.messages import Session_pb2, Base_pb2, Common_pb2


def example_single_joint(base_client_service, last_act_id):

    joint_speed = Base_pb2.JointSpeed()
    joint_speed.joint_identifier = last_act_id - 1  # Need to exclude base id
    joint_speed.value = 2.0   # Speed in degrees/second
    joint_speed.duration = 0  # Unlimited time to execute
    base_client_service.SendSelectedJointSpeedCommand(joint_speed)

    time.sleep(5)

    joint_speed.value = 0.0
    base_client_service.SendSelectedJointSpeedCommand(joint_speed)


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

    base_client_service = BaseClient(router)

    # Create required services
    device_manager_service = DeviceManagerClient(router)
    device_config_service = DeviceConfigClient(router)

    # Find the last actuator
    sub_device_info = device_manager_service.ReadAllDevices()
    last_act = 0
    last_act_id = 0
    for dev in sub_device_info.device_handle:
        if dev.device_type is Common_pb2.BIG_ACTUATOR or dev.device_type is Common_pb2.SMALL_ACTUATOR:
            if dev.order > last_act:
                last_act = dev.order
                last_act_id = dev.device_identifier

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
    example_single_joint(base_client_service, last_act_id)

    # Close API session
    session_manager.CloseSession()

    # Deactivate the router and cleanly disconnect from the transport object
    router.SetActivationStatus(False)
    transport.disconnect()
