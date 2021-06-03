#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2021 Kinova inc. All rights reserved.
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
from kortex_api.autogen.client_stubs.BaseCyclicClientRpc import BaseCyclicClient


from kortex_api.autogen.messages import Base_pb2, BaseCyclic_pb2, Common_pb2

# Maximum allowed waiting time during actions (in seconds)
TIMEOUT_DURATION = 100

# Create closure to set an event after an END or an ABORT
def check_for_end_or_abort(e):
    """Return a closure checking for END or ABORT notifications

    Arguments:
    e -- event to signal when the action is completed
        (will be set when an END or ABORT occurs)
    """
    def check(notification, e = e):
        print("EVENT : " + \
              Base_pb2.ActionEvent.Name(notification.action_event))
        if notification.action_event == Base_pb2.ACTION_END \
        or notification.action_event == Base_pb2.ACTION_ABORT:
            e.set()
    return check
 
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
        return False

    e = threading.Event()
    notification_handle = base.OnNotificationActionTopic(
        check_for_end_or_abort(e),
        Base_pb2.NotificationOptions()
    )

    base.ExecuteActionFromReference(action_handle)
    finished = e.wait(TIMEOUT_DURATION)
    base.Unsubscribe(notification_handle)

    if finished:
        print("Safe position reached")
    else:
        print("Timeout on action notification wait")
    return finished


def populateAngularPose(jointPose,durationFactor):
    waypoint = Base_pb2.AngularWaypoint()
    waypoint.angles.extend(jointPose)
    waypoint.duration = durationFactor*5.0    
    
    return waypoint
 

def example_trajectory(base, base_cyclic):

    base_servo_mode = Base_pb2.ServoingModeInformation()
    base_servo_mode.servoing_mode = Base_pb2.SINGLE_LEVEL_SERVOING
    base.SetServoingMode(base_servo_mode)

    jointPoses = tuple(tuple())
    product = base.GetProductConfiguration()

    if(   product.model == Base_pb2.ProductConfiguration__pb2.MODEL_ID_L53 
    or product.model == Base_pb2.ProductConfiguration__pb2.MODEL_ID_L31):
        if(product.model == Base_pb2.ProductConfiguration__pb2.MODEL_ID_L31):
            jointPoses = (  (0.0,  344.0, 75.0,  360.0, 300.0, 0.0),
                            (0.0,  21.0,  145.0, 272.0, 32.0,  273.0),
                            (42.0, 334.0, 79.0,  241.0, 305.0, 56.0))
        else:
            # Binded to degrees of movement and each degrees correspond to one degree of liberty
            degreesOfFreedom = base.GetActuatorCount();

            if(degreesOfFreedom.count == 6):
                jointPoses = (  ( 360.0, 35.6, 281.8, 0.8,  23.8, 88.9 ),
                                ( 359.6, 49.1, 272.1, 0.3,  47.0, 89.1 ),
                                ( 320.5, 76.5, 335.5, 293.4, 46.1, 165.6 ),
                                ( 335.6, 38.8, 266.1, 323.9, 49.7, 117.3 ),
                                ( 320.4, 76.5, 335.5, 293.4, 46.1, 165.6 ),
                                ( 28.8,  36.7, 273.2, 40.8,  39.5, 59.8 ),
                                ( 360.0, 45.6, 251.9, 352.2, 54.3, 101.0 ))
            else:
                jointPoses = (  ( 360.0, 35.6, 180.7, 281.8, 0.8,   23.8, 88.9  ),
                                ( 359.6, 49.1, 181.0, 272.1, 0.3,   47.0, 89.1  ),
                                ( 320.5, 76.5, 166.5, 335.5, 293.4, 46.1, 165.6 ),
                                ( 335.6, 38.8, 177.0, 266.1, 323.9, 49.7, 117.3 ),
                                ( 320.4, 76.5, 166.5, 335.5, 293.4, 46.1, 165.6 ),
                                ( 28.8,  36.7, 174.7, 273.2, 40.8,  39.5, 59.8  ),
                                ( 360.0, 45.6, 171.0, 251.9, 352.2, 54.3, 101.0 ))
            
    else:
        print("Product is not compatible to run this example please contact support with KIN number bellow")
        print("Product KIN is : " + product.kin())


    waypoints = Base_pb2.WaypointList()    
    waypoints.duration = 0.0
    waypoints.use_optimal_blending = False
    
    index = 0
    for jointPose in jointPoses:
        waypoint = waypoints.waypoints.add()
        waypoint.name = "waypoint_" + str(index)
        durationFactor = 1
        # Joints/motors 5 and 7 are slower and need more time
        if(index == 4 or index == 6):
            durationFactor = 6 # Min 30 seconds
        
        waypoint.angular_waypoint.CopyFrom(populateAngularPose(jointPose, durationFactor))
        index = index + 1 
    
    
   # Verify validity of waypoints
    result = base.ValidateWaypointList(waypoints);
    if(len(result.trajectory_error_report.trajectory_error_elements) == 0):

        e = threading.Event()
        notification_handle = base.OnNotificationActionTopic(
            check_for_end_or_abort(e),
            Base_pb2.NotificationOptions()
        )

        print("Reaching angular pose trajectory...")
        
        
        base.ExecuteWaypointTrajectory(waypoints)

        print("Waiting for trajectory to finish ...")
        finished = e.wait(TIMEOUT_DURATION)
        base.Unsubscribe(notification_handle)

        if finished:
            print("Angular movement completed")
        else:
            print("Timeout on action notification wait")
        return finished
    else:
        print("Error found in trajectory") 
        print(result.trajectory_error_report)
        return finished


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
        base_cyclic = BaseCyclicClient(router)
        
        # Example core
        success = True

        success &= example_move_to_home_position(base)
        success &= example_trajectory(base, base_cyclic)
       
        return 0 if success else 1

if __name__ == "__main__":
    exit(main())
