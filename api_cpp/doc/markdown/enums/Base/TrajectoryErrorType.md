# enum TrajectoryErrorType

## Overview / Purpose

Enumeration TrajectoryErrorType

|Enumerator|Value|Description|
|----------|-----|-----------|
|TRAJECTORY\_ERROR\_TYPE\_UNSPECIFIED|0|Unspecified error type|
|TRAJECTORY\_ERROR\_TYPE\_OUTSIDE\_WORKSPACE|1|The desired pose is outside robot workspace|
|TRAJECTORY\_ERROR\_TYPE\_ACTUATOR\_COUNT\_MISMATCH|2|The provided number of joint values does not match robot's number of actuators|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_DURATION|3|The duration exceeds a limit or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_JOINT\_NO\_MOTION|4|The robot's actuators are already at the targeted configuration|
|TRAJECTORY\_ERROR\_TYPE\_ZERO\_DISTANCE|4|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_JOINT\_SPEED|5|The joint speed exceeds a limit, initial speed does not match current robot speed or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_SPEED|5|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_LARGE\_SPEED|6|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_JOINT\_ACCELERATION|7|The joint acceleration exceeds a limit or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_ACCELERATION|7|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_TIME\_STEP|8|The time step does not match robot time step or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_TRAJECTORY\_SIZE|9|The trajectory size is outside the limits or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_LARGE\_SIZE|9|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_WRONG\_MODE|10|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_JOINT\_POSITION|11|The joint position exceeds a limit, initial joint position does not match current robot joint position or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_JOINT\_POSITION\_LIMIT|11|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_FILE\_ERROR|12|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_NO\_FILE\_IN\_MEMORY|13|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_INDEX\_OUT\_OF\_TRAJ|14|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_TRAJECTORY\_ALREADY\_RUNNING|15|The new trajectory cannot start because another trajectory is being played|
|TRAJECTORY\_ERROR\_TYPE\_ALREADY\_RUNNING|15|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_WRONG\_STARTING\_POINT|16|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_CARTESIAN\_CANNOT\_START|17|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_WRONG\_STARTING\_SPEED|18|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_POSITION|19|This enum value is deprecated and will be removed in a future release.|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_CARTESIAN\_POSITION|20|The cartesian position exceeds a limit, initial pose does not match current robot pose or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_CARTESIAN\_ORIENTATION|21|The cartesian orientation exceeds a limit, initial orientation does not match current robot orientation or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_CARTESIAN\_LINEAR\_VELOCITY|22|The cartesian linear velocity exceeds a limit or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_CARTESIAN\_ANGULAR\_VELOCITY|23|The cartesian angular velocity exceeds a limit or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_JOINT\_TORQUE|24|The joint torque exceeds a limit or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_MULTIPLE\_WAYPOINT\_TYPE\_LIST|25|The waypoints in a trajectory must be all of the same type \(cartesian or angular\)|
|TRAJECTORY\_ERROR\_TYPE\_INITIAL\_WAYPOINT\_NO\_STOP|26|The first waypoint must not have blending \(currently unused\)|
|TRAJECTORY\_ERROR\_TYPE\_FINAL\_WAYPOINT\_NO\_STOP|27|The last waypoint must not have blending|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_BLENDING\_RADIUS|28|The blending radius must be positive and not overlap other blendings or waypoint or is invalid|
|TRAJECTORY\_ERROR\_TYPE\_INVALID\_REFERENCE\_FRAME|29|The reference frame is invalid or not supported|
|TRAJECTORY\_ERROR\_TYPE\_NUMERICAL\_ERROR\_IMPOSSIBLE\_TRAJECTORY|30|The conditions \(points, velocities\) of the trajectory lead to numerical errors that make the computation impossible|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

