# Message GripperCommand

This page describes the Python Kinova.Api.Base.GripperCommand message.

## Overview / Purpose

Defines a command to control the gripper movement

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode| [GripperMode](enm_Base_GripperMode.md#)|Mode in which to control the gripper|
|gripper| [Gripper](msg_Base_Gripper.md#)|In position, admissible values for each finger is between 0 and 1.0, where 0 is closed and 1.0 is fully open. In speed or torque, admissible values for each finger is between -1.0 and 1.0, where 1.0 corresponds to maximum opening speed and -1.0 corresponds to maximum closing speed. Gripper movement values|
|duration|int|Duration constraint. If not 0, allows to set a limit \(in seconds\) to the GripperCommand|

**Parent topic:** [Base](../references/summary_Base.md)

