#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2019 Kinova inc. All rights reserved.
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
import threading

from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient

from kortex_api.autogen.messages import Base_pb2, Common_pb2

# Position of the protection zone (in meters)
PROTECTION_ZONE_POS =  [0.75, 0.0, 0.4]

# Size of the protection zone (in meters)
PROTECTION_ZONE_DIMENSIONS = [0.05, 0.3, 0.4]

# Theta values of the protection zone movement (in degrees)
PROTECTION_ZONE_MOVEMENT_THETAS = [90.0, 0.0, 90.0]

# Waiting time between actions (in milliseconds)
ACTION_WAITING_TIME = 1

# Create closure to set finished to true after an END or an ABORT
def check_for_end_or_abort(e):
    """Return a closure checking for END or ABORT notifications

    Arguments:
    finished -- list of bool to affect the result (of size 1)
                (will be set to True when an END or ABORT occurs)
    """
    def check(notification, e = e):
        print("EVENT : " + \
              Base_pb2.ActionEvent.Name(notification.action_event))
        if notification.action_event == Base_pb2.ACTION_END \
        or notification.action_event == Base_pb2.ACTION_ABORT:
            e.set()
    return check
 
def move_to_home_position(base):
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
        sys.exit(1)

    e = threading.Event()
    notification_handle = base.OnNotificationActionTopic(
        check_for_end_or_abort(e),
        Base_pb2.NotificationOptions()
    )

    base.ExecuteActionFromReference(action_handle)

    e.wait()

    base.Unsubscribe(notification_handle)

def move_to_protection_zone(base):
    
    command = Base_pb2.TwistCommand()

    command.reference_frame = Base_pb2.CARTESIAN_REFERENCE_FRAME_BASE
    command.duration = 0

    twist = command.twist
    twist.linear_x = 0.05
    twist.linear_y = 0
    twist.linear_z = 0
    twist.angular_x = 0
    twist.angular_y = 0
    twist.angular_z = 0

    print ("Moving towards the protection zone for 4 seconds...")
    base.SendTwistCommand(command)

    # Let time for twist to be executed
    time.sleep(4)

    print ("Stopping the robot...")
    base.Stop()
    time.sleep(1)

def move_in_front_of_protection_zone(base):
    
    print("Starting Cartesian action movement ...")
    action = Base_pb2.Action()
    action.name = "Example Cartesian action movement"
    action.application_data = ""
 
    cartesian_pose = action.reach_pose.target_pose
    cartesian_pose.x = PROTECTION_ZONE_POS[0] - 0.1     # (meters)
    cartesian_pose.y = PROTECTION_ZONE_POS[1]           # (meters)
    cartesian_pose.z = PROTECTION_ZONE_POS[2]           # (meters)
    cartesian_pose.theta_x = PROTECTION_ZONE_MOVEMENT_THETAS[0] # (degrees)
    cartesian_pose.theta_y = PROTECTION_ZONE_MOVEMENT_THETAS[1] # (degrees)
    cartesian_pose.theta_z = PROTECTION_ZONE_MOVEMENT_THETAS[2] # (degrees)

    e = threading.Event()
    notification_handle = base.OnNotificationActionTopic(
        check_for_end_or_abort(e),
        Base_pb2.NotificationOptions()
    )

    print("Executing action")
    base.ExecuteAction(action)

    print("Waiting for movement to finish ...")
    e.wait()

    print("Cartesian movement completed")

    base.Unsubscribe(notification_handle)

def print_protection_zones(base):

    all_protection_zones = base.ReadAllProtectionZones()

    print("PROTECTION ZONES")
    for protection_zone in all_protection_zones.protection_zones:
        message = "Protection Zone : " + protection_zone.name + \
        " Origin : [ " \
        + str(protection_zone.shape.origin.x) + " "\
        + str(protection_zone.shape.origin.y) + " "\
        + str(protection_zone.shape.origin.z) \
        + " ] Dimensions : [ "
        for dim in protection_zone.shape.dimensions:
            message += str(dim) + " "
        message += "]"
        print(message)

def create_protection_zone(base):

    zone = Base_pb2.ProtectionZone()

    zone.name = "Example Protection Zone"
    zone.is_enabled = True
    shape = zone.shape
    shape.shape_type = Base_pb2.RECTANGULAR_PRISM

    point = shape.origin
    point.x = PROTECTION_ZONE_POS[0]
    point.y = PROTECTION_ZONE_POS[1]
    point.z = PROTECTION_ZONE_POS[2]
    shape.dimensions.append(PROTECTION_ZONE_DIMENSIONS[0])
    shape.dimensions.append(PROTECTION_ZONE_DIMENSIONS[1])
    shape.dimensions.append(PROTECTION_ZONE_DIMENSIONS[2])

    shape.orientation.row1.column1 = 1.0
    shape.orientation.row2.column2 = 1.0
    shape.orientation.row3.column3 = 1.0

    return base.CreateProtectionZone(zone)

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

        # Move to initial position
        move_to_home_position(base)

        # Move without the protection zone
        print_protection_zones(base)
        move_in_front_of_protection_zone(base)
        move_to_protection_zone(base)
        move_to_home_position(base)

        # Move with the protection zone
        print_protection_zones(base)
        move_in_front_of_protection_zone(base)

        # Add the protection zone
        handle = create_protection_zone(base)

        move_to_protection_zone(base)
        move_to_home_position(base)

        # Delete the protection zone
        base.DeleteProtectionZone(handle)

        # Print final protection zones
        # The example protection zone should be removed
        print_protection_zones(base)

if __name__ == "__main__":
    main()
