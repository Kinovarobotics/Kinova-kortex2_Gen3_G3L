# Message Action

This page describes the Python Kinova.Api.Base.Action message.

## Overview / Purpose

Defines an action

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [ActionHandle](msg_Base_ActionHandle.md#)|Action handle \(useful when updating an existing action\)|
|name|str|Action friendly name|
|application\_data|str|Application data \(reserved for use by Web App\)|
|send\_twist\_command|oneof:action\_parameters [TwistCommand](msg_Base_TwistCommand.md#)|Action to control the robot in velocity|
|send\_joint\_speeds|oneof:action\_parameters [JointSpeeds](msg_Base_JointSpeeds.md#)|Action to control each joint speed|
|reach\_pose|oneof:action\_parameters [ConstrainedPose](msg_Base_ConstrainedPose.md#)|Action to reach a pose|
|reach\_joint\_angles|oneof:action\_parameters [ConstrainedJointAngles](msg_Base_ConstrainedJointAngles.md#)|Action to reach a series of joint angles|
|toggle\_admittance\_mode|oneof:action\_parameters int|Action to enable or disable the admittance mode|
|switch\_control\_mapping|oneof:action\_parameters [SwitchControlMapping](msg_Base_SwitchControlMapping.md#)|Action to switch the active controller map|
|navigate\_joints|oneof:action\_parameters int|Action to select the next actuator to control in a map|
|navigate\_mappings|oneof:action\_parameters int|Action to select a different map|
|change\_twist|oneof:action\_parameters [ChangeTwist](msg_Base_ChangeTwist.md#)|Action to change twist|
|change\_joint\_speeds|oneof:action\_parameters [ChangeJointSpeeds](msg_Base_ChangeJointSpeeds.md#)|Action to change the joint speeds individually|
|apply\_emergency\_stop|oneof:action\_parameters [EmergencyStop](msg_Base_EmergencyStop.md#)|Action to apply robot emergency stop|
|clear\_faults|oneof:action\_parameters [Faults](msg_Base_Faults.md#)|Action to clear faults. Robot will be able to move if there is no more fault \(see BaseCyclic.BaseFeedback.\[fault\_bank\_a | fault\_bank\_b\]\)|
|delay|oneof:action\_parameters [Delay](msg_Base_Delay.md#)|Action to apply a delay|
|execute\_action|oneof:action\_parameters [ActionHandle](msg_Base_ActionHandle.md#)|Action to execute an existing action|
|send\_gripper\_command|oneof:action\_parameters [GripperCommand](msg_Base_GripperCommand.md#)|Action to execute a gripper movement|
|stop\_action|oneof:action\_parameters [Stop](msg_Base_Stop.md#)|Action to stop movement|

**Parent topic:** [Base](../references/summary_Base.md)

