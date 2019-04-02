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
from kortex_api.RouterClient import RouterClient, RouterClientSendOptions
from kortex_api.SessionManager import SessionManager

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import Session_pb2, Base_pb2

def create_angular_action():
    print("\nCreating angular action")

    action = Base_pb2.Action()
    action.name = "Example angular action"
    action.application_data = ""
    
    angle_value = [0, 0, 0, 0, 0, 0, 0]
    for joint_id in range(7):
        joint_angle = action.reach_joint_angles.joint_angles.joint_angles.add()
        joint_angle.value = angle_value[joint_id]

    return action


def create_cartesian_action():
    print("\nCreating Cartesian action")

    action = Base_pb2.Action()
    action.name = "Example Cartesian action"
    action.application_data = ""
    
    cartesian_pose = action.reach_pose.target_pose
    cartesian_pose.x = 0.80     # (meters)
    cartesian_pose.y = 0        # (meters)
    cartesian_pose.z = 0.36     # (meters)
    cartesian_pose.theta_x = 10 # (degrees)
    cartesian_pose.theta_y = 90 # (degrees)
    cartesian_pose.theta_z = 10 # (degrees)

    return action


def example_create_sequence(base_client_service):
    print("\nCreating Action for Sequence")

    angular_action = create_angular_action()
    cartesian_action = create_cartesian_action()

    print("Creating Sequence")
    sequence = Base_pb2.Sequence()
    sequence.name = "Example sequence"

    print("Appending Actions to Sequence")
    task_1 = sequence.tasks.add()
    task_1.group_identifier = 0
    task_1.action.CopyFrom(angular_action)
    
    task_2 = sequence.tasks.add()
    task_2.group_identifier = 1 # sequence elements with same group_id are played at the same time
    task_2.action.CopyFrom(cartesian_action)

    print("Creating sequence on device and executing it")
    handle_sequence = base_client_service.CreateSequence(sequence)
    base_client_service.PlaySequence(handle_sequence)

    print("Waiting 30 seconds for movement to finish ...")
    time.sleep(30)

    print("Sequence completed")


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
    example_create_sequence(base_client_service)

    # Close API session
    session_manager.CloseSession()

    # Deactivate the router and cleanly disconnect from the transport object
    router.SetActivationStatus(False)
    transport.disconnect()
