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
|oneof action\_parameters : send\_twist\_command| [TwistCommand](msg_Base_TwistCommand.md#)|Action to control the robot in velocity|
|oneof action\_parameters : send\_joint\_speeds| [JointSpeeds](msg_Base_JointSpeeds.md#)|Action to control each joint speed|
|oneof action\_parameters : reach\_pose| [ConstrainedPose](msg_Base_ConstrainedPose.md#)|Action to reach a pose|
|oneof action\_parameters : reach\_joint\_angles| [ConstrainedJointAngles](msg_Base_ConstrainedJointAngles.md#)|Action to reach a series of joint angles|
|oneof action\_parameters : toggle\_admittance\_mode| [AdmittanceMode](enm_Base_AdmittanceMode.md#)|Action to enable or disable the admittance mode|
|oneof action\_parameters : switch\_control\_mapping| [SwitchControlMapping](msg_Base_SwitchControlMapping.md#)|Action to switch the active controller map|
|oneof action\_parameters : navigate\_joints| [JointNavigationDirection](enm_Base_JointNavigationDirection.md#)|Action to select the next actuator to control in a map|
|oneof action\_parameters : navigate\_mappings| [NavigationDirection](enm_Base_NavigationDirection.md#)|Action to select a different map|
|oneof action\_parameters : change\_twist| [ChangeTwist](msg_Base_ChangeTwist.md#)|Action to change twist|
|oneof action\_parameters : change\_joint\_speeds| [ChangeJointSpeeds](msg_Base_ChangeJointSpeeds.md#)|Action to change the joint speeds individually|
|oneof action\_parameters : apply\_emergency\_stop| [EmergencyStop](msg_Base_EmergencyStop.md#)|Action to apply robot emergency stop|
|oneof action\_parameters : clear\_faults| [Faults](msg_Base_Faults.md#)|Action to clear faults. Robot will be able to move if there is no more fault \(see BaseCyclic.BaseFeedback.\[fault\_bank\_a | fault\_bank\_b\]\)|
|oneof action\_parameters : delay| [Delay](msg_Base_Delay.md#)|Action to apply a delay|
|oneof action\_parameters : execute\_action| [ActionHandle](msg_Base_ActionHandle.md#)|Action to execute an existing action|
|oneof action\_parameters : send\_gripper\_command| [GripperCommand](msg_Base_GripperCommand.md#)|Action to execute a gripper movement|
|oneof action\_parameters : stop\_action| [Stop](msg_Base_Stop.md#)|Action to stop movement|

**Parent topic:** [Base](../references/summary_Base.md)

