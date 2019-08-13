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
import sys
import os

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import Session_pb2, Base_pb2

#
# Example related functions
#

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

#
#
# Example core functions
#

def example_move_to_home_position(base):
    # Make sure the arm is in Single Level Servoing mode
    base_servo_mode = Base_pb2.ServoingModeInformation()
    base_servo_mode.servoing_mode = Base_pb2.SINGLE_LEVEL_SERVOING
    base.SetServoingMode(base_servo_mode)
    
    # Move arm to ready position
    print("Moving the arm to a safe position")
    action_type = Base_pb2.RequestedActionType()
    action_type.action_type = Base_pb2.REACH_JOINT_ANGLES
    action_list = base.ReadAllActions(action_type)
    action_handle = None
    for action in action_list.action_list:
        if action.name == "Home":
            action_handle = action.handle

    if action_handle == None:
        print("Can't reach safe position. Exiting")
        sys.exit(0)

    base.ExecuteActionFromReference(action_handle)
    time.sleep(20) # Leave time to action to complete

def example_create_sequence(base):
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

    print("Creating sequence on device and executing it")
    handle_sequence = base.CreateSequence(sequence)
    base.PlaySequence(handle_sequence)

    print("Waiting 30 seconds for movement to finish ...")
    time.sleep(30)

    print("Sequence completed")

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
        example_move_to_home_position(base)
        example_create_sequence(base)

if __name__ == "__main__":
    main()