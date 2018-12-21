# Enum ActionType

This page describes the C++ Kinova::Api::Base::ActionType enumeration.

## Overview / Purpose

List of admissible action types

## Enumeration definition

|Enumerator|Value|Description|
|----------|-----|-----------|
|UNSPECIFIED\_ACTION|0|Unspecified action type|
|SEND\_TWIST\_COMMAND|1|Action to control the robot in velocity|
|SEND\_JOINT\_SPEEDS|4|Action to control each joint speed|
|REACH\_POSE|6|Action to reach a pose|
|REACH\_JOINT\_ANGLES|7|Action to reach a series of joint angles|
|TOGGLE\_ADMITTANCE\_MODE|13|Action to enable or disable the admittance mode|
|SWITCH\_CONTROL\_MAPPING|16|Action to switch the active controller map|
|NAVIGATE\_JOINTS|17|Action to select the next actuator to control from control mapping|
|NAVIGATE\_MAPPINGS|18|Action to select a different map|
|CHANGE\_TWIST|22|Action to change the twist|
|CHANGE\_JOINT\_SPEEDS|23|Action to change the joint speeds individually|
|APPLY\_EMERGENCY\_STOP|28|Action to apply robot emergency stop|
|CLEAR\_FAULTS|29|Action to clear faults. Robot will be able to move if there is no more fault \(see BaseCyclic.BaseFeedback.\[fault\_bank\_a | fault\_bank\_b\]\)|
|DELAY|31|Action to apply a delay|
|EXECUTE\_ACTION|32|Action to execute an existing action|
|SEND\_GRIPPER\_COMMAND|33|Action to execute a gripper command|
|STOP\_ACTION|35|Action to stop movement|

**Parent topic:** [Base](../references/summary_Base.md)

