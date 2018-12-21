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

from jaco3_armbase.autogen.client_stubs.BaseClientRpc import BaseClient
from jaco3_armbase.autogen.messages import Base_pb2

from jaco3_armbase.SessionManager import SessionManager
from jaco3_armbase.autogen.messages import Session_pb2


def angular_movement(base_client_service):
    print("Starting angular motion ...")

    action = Base_pb2.Action()
    action.name = "Example angular motion"
    action.application_data = ""
    
    angle_value = [0, 0, 0, 0, 0, 0, 0] # arm straight up
    for joint_id in range(7):
        joint_angle = action.reach_joint_angles.joint_angles.joint_angles.add()
        joint_angle.joint_identifier = joint_id
        joint_angle.value = angle_value[joint_id]

    print("Executing action")
    base_client_service.ExecuteAction(action)

    print("Waiting 10 seconds to finish movement...")
    time.sleep(10)

    print("Angular movement finish")


def cartesian_movement(base_client_service):
    print("Starting Cartesian motion ...")

    action = Base_pb2.Action()
    action.name = "Example Cartesian motion"
    action.application_data = ""

    cartesian_pose = action.reach_pose.target_pose
    cartesian_pose.x = 0.80     # (meters)
    cartesian_pose.y = 0        # (meters)
    cartesian_pose.z = 0.36     # (meters)
    cartesian_pose.theta_x = 10 # (degrees)
    cartesian_pose.theta_y = 90 # (degrees)
    cartesian_pose.theta_z = 10 # (degrees)

    print("Executing action")
    base_client_service.ExecuteAction(action)

    print("Waiting 20 seconds for motion to finish ...")
    time.sleep(20)

    print("Cartesian motion ended")


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    transport = UDPTransport()
    transport.connect(DEVICE_IP, DEVICE_PORT)
    router = RouterClient(transport, lambda kException: print("Error during connection"))

    print("Creating Session for communication")
    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 60000   # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)
    print("Session created")

    session_manager_service = SessionManager(router)   
    session_manager_service.CreateSession(session_info)

    print("Waiting 7.5 seconds before trying to take control of the robot...")
    time.sleep(7.5)

    base_client_service = BaseClient(router)

    angular_movement(base_client_service)

    cartesian_movement(base_client_service)

    session_manager_service.CloseSession()
