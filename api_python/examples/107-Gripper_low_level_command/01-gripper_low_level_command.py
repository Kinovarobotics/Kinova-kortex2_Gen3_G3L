#! /usr/bin/env python3

###
# KINOVA (R) KORTEX (TM)
#
# Copyright (c) 2019 Kinova inc. All rights reserved.
#
# This software may be modified and distributed under the
# terms of the BSD 3-Clause license.
#
# Refer to the LICENSE file for details.
#
###

###
# 01-BaseGen3_gripper_lowlevel.py
# 
# Low level servoing example for the GEN3's end effector (using Robotiq's
# 2-Finger 85 or 2-Finger 140)
# 
# ABSTRACT:
# =========
# On GEN3, gripper cyclic commands have 3 parameters used to control gripper
# motion : position, velocity and force.
# 
# These 3 parameters are always sent together and cannot be used independently.
# Each parameter has absolute percentage values and their range are from 0% to
# 100%.
# 
# For gripper position, 0% is fully opened and 100% is fully closed.
# For gripper speed, 0% is fully stopped and 100% is opening/closing (depending on
# position used) at maximum speed.
# Force parameter is used as a force limit to apply when closing or opening
# the gripper. If this force limit is exceeded the gripper motion will stop.
# 0% is the lowest force limit and 100% the maximum.
# 
# DESCRIPTION OF CURRENT EXAMPLE:
# ===============================
# In this example user is asked to enter a number from 0 to 9 and the value
# entered is used to send the gripper to corresponding value (i.e.: 0=10%, 3 = 40%,
# 9 = 100%, etc.).
# 
# To control the gripper, cyclic commands are sent directly to the end effector
# to achieve position control.
# 
# A simple proportional feedback loop is used to illustrate how feedback can be
# obtained and used with Kortex API.
# 
# This loop modulates the speed sent to the gripper.
###

import sys
import os
import time

from kbhit import KBHit
from kortex_api.autogen.client_stubs.BaseClientRpc import BaseClient
from kortex_api.autogen.client_stubs.BaseCyclicClientRpc import BaseCyclicClient
from kortex_api.autogen.messages import Base_pb2
from kortex_api.autogen.messages import BaseCyclic_pb2

"""
01-BaseGen3_gripper_lowlevel.py

Low level servoing example for the GEN3's end effector (using Robotiq's
2-Finger 85 or 2-Finger 140)

ABSTRACT:
=========
On GEN3, gripper cyclic commands have 3 parameters used to control gripper
motion : position, velocity and force.

These 3 parameters are always sent together and cannot be used independently.
Each parameter has absolute percentage values and their range are from 0% to
100%.

For gripper position, 0% is fully opened and 100% is fully closed.
For gripper speed, 0% is fully stopped and 100% is opening/closing (depending on
position used) at maximum speed.
Force parameter is used as a force limit to apply when closing or opening
the gripper. If this force limit is exceeded the gripper motion will stop.
0% is the lowest force limit and 100% the maximum.

DESCRIPTION OF CURRENT EXAMPLE:
===============================
In this example user is asked to enter a number from 0 to 9 and the value
entered is used to send the gripper to corresponding value (i.e.: 0=10%, 3 = 40%,
9 = 100%, etc.).

To control the gripper, cyclic commands are sent directly to the end effector
to achieve position control.

A simple proportional feedback loop is used to illustrate how feedback can be
obtained and used with Kortex API.

This loop modulates the speed sent to the gripper.
"""

class GripperLowLevelExample:
    def __init__(self, router, router_real_time, proportional_gain = 2.0):
        """
            GripperLowLevelExample class constructor.

            Inputs:
                kortex_api.RouterClient router:            TCP router
                kortex_api.RouterClient router_real_time:  Real-time UDP router
                float proportional_gain: Proportional gain used in control loop (default value is 2.0)

            Outputs:
                None
            Notes:
                - Actuators and gripper initial position are retrieved to set initial positions
                - Actuator and gripper cyclic command objects are created in constructor. Their
                  references are used to update position and speed.
        """

        self.proportional_gain = proportional_gain

        ###########################################################################################
        # UDP and TCP sessions are used in this example.
        # TCP is used to perform the change of servoing mode
        # UDP is used for cyclic commands.
        #
        # 2 sessions have to be created: 1 for TCP and 1 for UDP
        ###########################################################################################

        self.router = router
        self.router_real_time = router_real_time

        # Create base client using TCP router
        self.base = BaseClient(self.router)

        # Create base cyclic client using UDP router.
        self.base_cyclic = BaseCyclicClient(self.router_real_time)

        # Create base cyclic command object.
        self.base_command = BaseCyclic_pb2.Command()
        self.base_command.frame_id = 0
        self.base_command.interconnect.command_id.identifier = 0
        self.base_command.interconnect.gripper_command.command_id.identifier = 0

        # Add motor command to interconnect's cyclic
        self.motorcmd = self.base_command.interconnect.gripper_command.motor_cmd.add()

        # Set gripper's initial position velocity and force
        base_feedback = self.base_cyclic.RefreshFeedback()
        self.motorcmd.position = base_feedback.interconnect.gripper_feedback.motor[0].position
        self.motorcmd.velocity = 0
        self.motorcmd.force = 100

        for actuator in base_feedback.actuators:
            self.actuator_command = self.base_command.actuators.add()
            self.actuator_command.position = actuator.position
            self.actuator_command.velocity = 0.0
            self.actuator_command.torque_joint = 0.0
            self.actuator_command.command_id = 0
            print("Position = ", actuator.position)

        # Save servoing mode before changing it
        self.previous_servoing_mode = self.base.GetServoingMode()

        # Set base in low level servoing mode
        servoing_mode_info = Base_pb2.ServoingModeInformation()
        servoing_mode_info.servoing_mode = Base_pb2.LOW_LEVEL_SERVOING
        self.base.SetServoingMode(servoing_mode_info)

    def Cleanup(self):
        """
            Restore arm's servoing mode to the one that
            was effective before running the example.

            Inputs:
                None
            Outputs:
                None
            Notes:
                None

        """
        # Restore servoing mode to the one that was in use before running the example
        self.base.SetServoingMode(self.previous_servoing_mode)


    def Goto(self, target_position):
        """
            Position gripper to a requested target position using a simple
            proportional feedback loop which changes speed according to error
            between target position and current gripper position

            Inputs:
                float target_position: position (0% - 100%) to send gripper to.
            Outputs:
                Returns True if gripper was positionned successfully, returns False
                otherwise.
            Notes:
                - This function blocks until position is reached.
                - If target position exceeds 100.0, its value is changed to 100.0.
                - If target position is below 0.0, its value is set to 0.0.
        """
        if target_position > 100.0:
            target_position = 100.0
        if target_position < 0.0:
            target_position = 0.0
        while True:
            try:
                base_feedback = self.base_cyclic.Refresh(self.base_command)

                # Calculate speed according to position error (target position VS current position)
                position_error = target_position - base_feedback.interconnect.gripper_feedback.motor[0].position

                # If positional error is small, stop gripper
                if abs(position_error) < 1.5:
                    position_error = 0
                    self.motorcmd.velocity = 0
                    self.base_cyclic.Refresh(self.base_command)
                    return True
                else:
                    self.motorcmd.velocity = self.proportional_gain * abs(position_error)
                    if self.motorcmd.velocity > 100.0:
                        self.motorcmd.velocity = 100.0
                    self.motorcmd.position = target_position

            except Exception as e:
                print("Error in refresh: " + str(e))
                return False
            time.sleep(0.001)
        return True
 
def main():
    # Import the utilities helper module
    import argparse
    sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))
    import utilities

    # Parse arguments
    parser = argparse.ArgumentParser()
    parser.add_argument("--proportional_gain", type=float, help="proportional gain used in control loop", default=2.0)
    args = utilities.parseConnectionArguments(parser)

    # Create connection to the device and get the router
    with utilities.DeviceConnection.createTcpConnection(args) as router:

        with utilities.DeviceConnection.createUdpConnection(args) as router_real_time:

            kbhit = KBHit()
            example = GripperLowLevelExample(router, router_real_time, args.proportional_gain)
            print("Press keys '0' to '9' to change gripper position. Press ESC to quit.")
            while True:
                if kbhit.kbhit():
                    ch = kbhit.getch()
                    if ord(ch) == 27:
                        break
                    elif ch >= '0' and ch <= '9':
                        target_position = (float(ch) + 1) * 10.0
                        print("Going to position %i"%(target_position))
                        example.Goto(target_position)
                        print("Target reached")
            time.sleep(0.2)
            example.Cleanup()

if __name__ == "__main__":
    main()