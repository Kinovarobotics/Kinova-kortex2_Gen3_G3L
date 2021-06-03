# enum ActionType

## Overview / Purpose

Enumeration ActionType

|Enumerator|Value|Description|
|----------|-----|-----------|
|UNSPECIFIED\_ACTION|0|Unspecified action type|
|SEND\_TWIST\_COMMAND|1|Control the robot in Cartesian velocity|
|SEND\_WRENCH\_COMMAND|2|Control the robot in force|
|SEND\_JOINT\_SPEEDS|4|Control each joint speed|
|REACH\_POSE|6|Reach a pose|
|REACH\_JOINT\_ANGLES|7|Reach a series of joint angles|
|TOGGLE\_ADMITTANCE\_MODE|13|Enable or disable the admittance mode|
|SNAPSHOT|14|Take a snapshot of current robot position|
|SWITCH\_CONTROL\_MAPPING|16|Switch the active controller map|
|NAVIGATE\_JOINTS|17|Select the next actuator to control from control mapping|
|NAVIGATE\_MAPPINGS|18|Select a different map|
|CHANGE\_TWIST|22|Change the twist|
|CHANGE\_JOINT\_SPEEDS|23|Change the joint speeds individually|
|CHANGE\_WRENCH|25|Change the Cartesian force|
|APPLY\_EMERGENCY\_STOP|28|Apply robot emergency stop|
|CLEAR\_FAULTS|29|Clear faults. Robot will be able to move if there is no more fault \(see BaseCyclic.BaseFeedback.\[fault\_bank\_a | fault\_bank\_b\]\)|
|TIME\_DELAY|31|Apply a delay|
|EXECUTE\_ACTION|32|Execute an existing action|
|SEND\_GRIPPER\_COMMAND|33|Send a gripper command|
|SEND\_GPIO\_COMMAND|34|Send a gpio command \(not implemented yet\)|
|STOP\_ACTION|35|Stop robot movement|
|PLAY\_PRE\_COMPUTED\_TRAJECTORY|39|Play a pre-computed trajectory|
|EXECUTE\_SEQUENCE|40|Execute an existing sequence|
|EXECUTE\_WAYPOINT\_LIST|41|Execute a trajectory defined by a series of waypoints|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

