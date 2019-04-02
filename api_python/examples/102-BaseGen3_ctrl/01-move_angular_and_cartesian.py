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
from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient

from kortex_api.autogen.messages import Session_pb2, Base_pb2, Common_pb2


def example_angular_action_movement(base_client_service):
    print("\nStarting angular action movement ...")

    action = Base_pb2.Action()
    action.name = "Example angular action movement"
    action.application_data = ""

    act_count = base_client_service.GetActuatorCount()

    # Place arm straight up
    for joint_id in range(act_count.count):
        joint_angle = action.reach_joint_angles.joint_angles.joint_angles.add()
        joint_angle.joint_identifier = joint_id
        joint_angle.value = 0

    print("Executing action")
    base_client_service.ExecuteAction(action)

    print("Waiting 20 seconds for movement to finish ...")
    time.sleep(20)

    print("Angular movement completed")


def example_cartesian_action_movement(base_client_service):
    print("\nStarting Cartesian action movement ...")

    action = Base_pb2.Action()
    action.name = "Example Cartesian action movement"
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

    print("Waiting 20 seconds for movement to finish ...")
    time.sleep(20)

    print("Cartesian movement completed")


def example_angular_trajectory_movement(base_client_service):
    print("\nStarting angular trajectory ...")

    constrained_joint_angles = Base_pb2.ConstrainedJointAngles()

    act_count = base_client_service.GetActuatorCount()

    # Place arm straight up
    for joint_id in range(act_count.count):
        joint_angle = constrained_joint_angles.joint_angles.joint_angles.add()
        joint_angle.joint_identifier = joint_id
        joint_angle.value = 0

    print("Executing trajectory")
    base_client_service.PlayJointTrajectory(constrained_joint_angles)

    print("Waiting 20 seconds for movement to finish ...")
    time.sleep(20)

    print("Angular trajectory completed")


def example_cartesian_trajectory_movement(base_client_service):
    print("\nStarting Cartesian trajectory ...")

    constrained_pose = Base_pb2.ConstrainedPose()

    cartesian_pose = constrained_pose.target_pose
    cartesian_pose.x = 0.80     # (meters)
    cartesian_pose.y = 0        # (meters)
    cartesian_pose.z = 0.36     # (meters)
    cartesian_pose.theta_x = 10 # (degrees)
    cartesian_pose.theta_y = 90 # (degrees)
    cartesian_pose.theta_z = 10 # (degrees)

    print("Executing trajectory")
    base_client_service.PlayCartesianTrajectory(constrained_pose)

    print("Waiting 20 seconds for movement to finish ...")
    time.sleep(20)

    print("Cartesian trajectory completed")


if __name__ == "__main__":

    DEVICE_IP = "192.168.1.10"
    DEVICE_PORT = 10000

    # Setup API
    errorCallback = lambda kException: print("_________ callback error _________ {}".format(kException))
    transport = UDPTransport()
    router = RouterClient(transport, errorCallback)
    transport.connect(DEVICE_IP, DEVICE_PORT)

    # Create session
    print("\nCreating session for communication")
    session_info = Session_pb2.CreateSessionInfo()
    session_info.username = 'admin'
    session_info.password = 'admin'
    session_info.session_inactivity_timeout = 60000   # (milliseconds)
    session_info.connection_inactivity_timeout = 2000 # (milliseconds)
    print("Session created")

    session_manager = SessionManager(router)   
    session_manager.CreateSession(session_info)

    # Create required services
    base_client_service = BaseClient(router)
    device_manager_service = DeviceManagerClient(router)

    # Find the number of actuator in angular action and trajectory
    sub_device_info = device_manager_service.ReadAllDevices()
    act_count = 0
    for dev in sub_device_info.device_handle:
        if dev.device_type is Common_pb2.BIG_ACTUATOR or dev.device_type is Common_pb2.SMALL_ACTUATOR:
            act_count += 1

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
    example_angular_action_movement(base_client_service)
    example_cartesian_action_movement(base_client_service)
    example_angular_trajectory_movement(base_client_service)
    example_cartesian_trajectory_movement(base_client_service)

    # Close API session
    session_manager.CloseSession()

    # Deactivate the router and cleanly disconnect from the transport object
    router.SetActivationStatus(False)
    transport.disconnect()
