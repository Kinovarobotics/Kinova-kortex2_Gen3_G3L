# Enum TrajectoryErrorType

## Overview / Purpose

Enumeration TrajectoryErrorType

|Enumerator|Value|Description|
|----------|-----|-----------|
|TRAJECTORY\_ERROR\_TYPE\_UNSPECIFIED|0|Unspecified error type|
|TRAJECTORY\_ERROR\_TYPE\_OUTSIDE\_WORKSPACE|1|The trajectory point is outside robot workspace|
|TRAJECTORY\_ERROR\_TYPE\_ACTUATOR\_COUNT\_MISMATCH|2|There is an actuator count mismatch with the robot|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_DURATION|3|The trajectory has an invalid duration|
|TRAJECTORY\_ERROR\_TYPE\_ZERO\_DISTANCE|4|The trajectory does not move the robot because the delta is either zero or too small|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_SPEED|5|The speed for a trajectory point for an actuator is invalid|
|TRAJECTORY\_ERROR\_TYPE\_LARGE\_SPEED|6|The speed for a trajectory point for an actuator exceeds its limit|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_ACCELERATION|7|The acceleration for a trajectory point for an actuator is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_TIME\_STEP|8|The time step for a trajectory point is invalid|
|TRAJECTORY\_ERROR\_TYPE\_LARGE\_SIZE|9|The trajectory is too large|
|TRAJECTORY\_ERROR\_TYPE\_WRONG\_MODE|10|The robot is not currently in Trajectory Control mode|
|TRAJECTORY\_ERROR\_TYPE\_JOINT\_POSITION\_LIMIT|11|The position limit for a trajectory point for an actuator is exceeded|
|TRAJECTORY\_ERROR\_TYPE\_FILE\_ERROR|12|An internal file error was encountered|
|TRAJECTORY\_ERROR\_TYPE\_NO\_FILE\_IN\_MEMORY|13|An internal file memory error was encountered|
|TRAJECTORY\_ERROR\_TYPE\_INDEX\_OUT\_OF\_TRAJ|14|The index for a trajectory point is invalid|
|TRAJECTORY\_ERROR\_TYPE\_ALREADY\_RUNNING|15|A trajectory is already running|
|TRAJECTORY\_ERROR\_TYPE\_WRONG\_STARTING\_POINT|16|The difference between the trajectory's starting point and the current position is too large|
|TRAJECTORY\_ERROR\_TYPE\_CARTESIAN\_CANNOT\_START|17|The cartesian trajectory is not able to start|
|TRAJECTORY\_ERROR\_TYPE\_WRONG\_STARTING\_SPEED|18|The difference between the trajectory's starting speed and the current speed is too large|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_POSITION|19|The position for a trajectory point for an actuator is invalid|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

