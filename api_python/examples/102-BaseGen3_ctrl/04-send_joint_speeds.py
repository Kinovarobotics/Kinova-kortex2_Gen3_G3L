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

import sys
import os
import time

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient
from kortex_api.autogen.client_stubs.DeviceManagerClientRpc import DeviceManagerClient
from kortex_api.autogen.client_stubs.DeviceConfigClientRpc import DeviceConfigClient

from kortex_api.autogen.messages import Session_pb2, Base_pb2, Common_pb2

def example_move_to_start_position(base):
    # Make sure the arm is in Single Level Servoing mode
    base_servo_mode = Base_pb2.ServoingModeInformation()
    base_servo_mode.servoing_mode = Base_pb2.SINGLE_LEVEL_SERVOING
    base.SetServoingMode(base_servo_mode)
    
    # Move arm to ready position
    constrained_joint_angles = Base_pb2.ConstrainedJointAngles()

    # We suppose the arm is a 7DOF
    angles = [0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.0]

    # Actuator 4 at 90 degrees
    for joint_id in range(len(angles)):
        joint_angle = constrained_joint_angles.joint_angles.joint_angles.add()
        joint_angle.joint_identifier = joint_id
        joint_angle.value = angles[joint_id]

    print("Reaching joint angles...")
    base.PlayJointTrajectory(constrained_joint_angles)

    print("Waiting 20 seconds for movement to finish ...")
    time.sleep(20)

    print("Joint angles reached")

def example_send_joint_speeds(base):

    joint_speeds = Base_pb2.JointSpeeds()

    speeds = [10.0, 0, -10.0, 0, 10.0, 0, -10.0]
    i = 0
    for speed in speeds:
        joint_speed = joint_speeds.joint_speeds.add()
        joint_speed.joint_identifier = i 
        joint_speed.value = speed
        joint_speed.duration = 0
        i = i + 1
    print ("Sending the joint speeds for 10 seconds...")
    base.SendJointSpeedsCommand(joint_speeds)
    time.sleep(10)

    
    joint_speeds_stop = Base_pb2.JointSpeeds()

    stop = [0, 0, 0, 0, 0, 0, 0]
    i = 0
    for speed in stop:
        joint_speed = joint_speeds_stop.joint_speeds.add()
        joint_speed.joint_identifier = i 
        joint_speed.value = speed
        joint_speed.duration = 0
        i = i + 1
        
    print ("Stopping the robot")
    base.SendJointSpeedsCommand(joint_speeds_stop)


def main():
    # Import the utilities helper module
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    args = utilities.parseConnectionArguments()
    
    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        # Create required services
        base = BaseClient(router)

        # Example core
        example_move_to_start_position(base)
        example_send_joint_speeds(base)

if __name__ == "__main__":
    main()
