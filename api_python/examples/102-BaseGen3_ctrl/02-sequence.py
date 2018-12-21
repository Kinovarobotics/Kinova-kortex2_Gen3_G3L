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

from jaco3_armbase.UDPTransport import UDPTransport
from jaco3_armbase.RouterClient import RouterClient, RouterClientSendOptions
from jaco3_armbase.SessionManager import SessionManager

from jaco3_armbase.autogen.client_stubs.BaseClientRpc import BaseClient

from jaco3_armbase.autogen.messages import Session_pb2, Base_pb2

def create_angular_action():
    print("Creating angular action")

    action = Base_pb2.Action()
    action.name = "Example angular action"
    action.application_data = ""
    
    angle_value = [0, 0, 0, 0, 0, 0, 0]
    for joint_id in range(7):
        joint_angle = action.reach_joint_angles.joint_angles.joint_angles.add()
        joint_angle.value = angle_value[joint_id]

    return action


def create_cartesian_action():
    print("Creating Cartesian action")

    action = Base_pb2.Action()
    action.name = "Example cartesian action"
    action.application_data = ""
    
    cartesian_pose = action.reach_pose.target_pose
    cartesian_pose.x = 0.80     # (meters)
    cartesian_pose.y = 0        # (meters)
    cartesian_pose.z = 0.36     # (meters)
    cartesian_pose.theta_x = 10 # (degrees)
    cartesian_pose.theta_y = 90 # (degrees)
    cartesian_pose.theta_z = 10 # (degrees)

    return action


def create_sequence(router):
    print("Creating Action for Sequence")
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

    print("Create sequence on device and execute it")
    base_client_service = BaseClient(router)
    handle_sequence = base_client_service.CreateSequence(sequence)
    base_client_service.PlaySequence(handle_sequence)

    print("Waiting 30 seconds for motion to finish ...")
    time.sleep(30)
    

if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    transport = UDPTransport()
    transport.connect(DEVICE_IP, DEVICE_PORT)
    router = RouterClient(transport, lambda kException: print("Error during connection"))

    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 600000  # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)

    session_manager = SessionManager(router)
    session_manager.CreateSession(session_info)

    # example core
    create_sequence(router)
