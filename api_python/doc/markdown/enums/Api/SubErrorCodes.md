# Enum SubErrorCodes

## Overview / Purpose

Enumeration SubErrorCodes

|Enumerator|Value|Description|
|----------|-----|-----------|
|SUB\_ERROR\_NONE|0|No sub error|
|METHOD\_FAILED|1|Method returned a failure status \(generic error\)|
|UNIMPLEMENTED|2|Unimplemented method|
|INVALID\_PARAM|3|Invalid parameter|
|UNSUPPORTED\_SERVICE|4|Service not recognized|
|UNSUPPORTED\_METHOD|5|Method not recognized|
|TOO\_LARGE\_ENCODED\_FRAME\_BUFFER|6|Encoded frame bigger than what transport permits|
|FRAME\_ENCODING\_ERR|7|Unable to encode frame|
|FRAME\_DECODING\_ERR|8|Unable to decode frame|
|INCOMPATIBLE\_HEADER\_VERSION|9|Frame header version differs from what is expected and is considered incompatible|
|UNSUPPORTED\_FRAME\_TYPE|10|Unrecognized frame type|
|UNREGISTERED\_NOTIFICATION\_RECEIVED|11|Server receiving unregistered notification|
|INVALID\_SESSION|12|Session not recognized|
|PAYLOAD\_DECODING\_ERR|13|Unable to decode payload|
|UNREGISTERED\_FRAME\_RECEIVED|14|Client received a response for which it did not send an RPC call|
|INVALID\_PASSWORD|15|Password does not match specified user|
|USER\_NOT\_FOUND|16|Unrecognized user|
|ENTITY\_NOT\_FOUND|17|Cannot find entity|
|ROBOT\_MOVEMENT\_IN\_PROGRESS|18|Robot refuses new control command because robot movement in progress|
|ROBOT\_NOT\_MOVING|19|Robot refuses stop command because robot is not moving|
|NO\_MORE\_STORAGE\_SPACE|20|Unable to execute because no more storage|
|ROBOT\_NOT\_READY|21|Robot initialization is not complete|
|ROBOT\_IN\_FAULT|22|Robot in fault|
|ROBOT\_IN\_MAINTENANCE|23|Robot in maintenance|
|ROBOT\_IN\_UPDATE\_MODE|24|Robot in update|
|ROBOT\_IN\_EMERGENCY\_STOP|25|Robot in emergency stop state|
|SINGLE\_LEVEL\_SERVOING|26|Robot is in single-level servoing mode|
|LOW\_LEVEL\_SERVOING|27|Robot is in low-level servoing mode|
|MAPPING\_GROUP\_NON\_ROOT|28|Trying to add a non-root MapGroup to Mapping|
|MAPPING\_INVALID\_GROUP|29|Trying to add an invalid or non-existent MapGroup to Mapping|
|MAPPING\_INVALID\_MAP|30|Trying to add an invalid or non-existent Map to Mapping|
|MAP\_GROUP\_INVALID\_MAP|31|Trying to add an invalid or non-existent Map to MapGroup|
|MAP\_GROUP\_INVALID\_PARENT|32|Trying to add a MapGroup under an invalid parent|
|MAP\_GROUP\_INVALID\_CHILD|33|Trying to add an invalid or non-existent to MapGroup|
|MAP\_GROUP\_INVALID\_MOVE|34|Trying to change a MapGroup's parent: move not supported|
|MAP\_IN\_USE|35|Deleting a Map used in a Mapping or MapGroup|
|WIFI\_CONNECT\_ERROR|36|Unable to connect to specified Wifi network|
|UNSUPPORTED\_NETWORK\_TYPE|37|Unsupported network type|
|TOO\_LARGE\_ENCODED\_PAYLOAD\_BUFFER|38|Encoded payload bigger than what transport permits|
|UPDATE\_PERMISSION\_DENIED|39|Attempting update command on non-updatable entity|
|DELETE\_PERMISSION\_DENIED|40|Attempting delete command on non-deletable entity|
|DATABASE\_ERROR|41|Internal DB error|
|UNSUPPORTED\_OPTION|42|Option not supported|
|UNSUPPORTED\_RESOLUTION|43|Resolution not supported|
|UNSUPPORTED\_FRAME\_RATE|44|Frame rate not supported|
|UNSUPPORTED\_BIT\_RATE|45|Bit rate not supported|
|UNSUPPORTED\_ACTION|46|Action not supported \(generic, when an action is not supported for a particular item\)|
|UNSUPPORTED\_FOCUS\_ACTION|47|Focus action not supported|
|VALUE\_IS\_ABOVE\_MAXIMUM|48|Specified value is above the supported maximum|
|VALUE\_IS\_BELOW\_MINIMUM|49|Specified value is below the supported minimum|
|DEVICE\_DISCONNECTED|50|Device is not connected|
|DEVICE\_NOT\_READY|51|Device is not ready|
|INVALID\_DEVICE|52|Device id is invalid during bridging|
|SAFETY\_THRESHOLD\_REACHED|53|Safety threshold is reached therefore safety is on|
|INVALID\_USER\_SESSION\_ACCESS|54|Service or function access not allowed: out of session or level access|
|CONTROL\_MANUAL\_STOP|55|Manually stopped sequence or action|
|CONTROL\_OUTSIDE\_WORKSPACE|56|Commanded Cartesian position is outside of robot workspace|
|CONTROL\_ACTUATOR\_COUNT\_MISMATCH|57|Number of constraint sent does not correspond to number of actuator \(ex: joint speed\)|
|CONTROL\_INVALID\_DURATION|58|Duration constraint is too short. The robot would need out of limit speeds/accelerations to reach this duration.|
|CONTROL\_INVALID\_SPEED|59|Speed constraint is negative|
|CONTROL\_LARGE\_SPEED|60|Speed constraint is too high \(exceed speed limit of leads to high acceleration\)|
|CONTROL\_INVALID\_ACCELERATION|61|Speed constraint is too high or duration constraint too short and leads to high acceleration|
|CONTROL\_INVALID\_TIME\_STEP|62|Refresh rate is smaller than the duration of the trajectory|
|CONTROL\_LARGE\_SIZE|63|Duration of the trajectory is more than 100s. The length of the trajectory is limited to 100000 points to avoid saturating the base memory.|
|CONTROL\_WRONG\_MODE|64|Control mode is not a trajectory mode|
|CONTROL\_JOINT\_POSITION\_LIMIT|65|Commanded configuration contains at least one actuator which is out of its physical limits|
|CONTROL\_NO\_FILE\_IN\_MEMORY|66|Trajectory is not computed and try to be started|
|CONTROL\_INDEX\_OUT\_OF\_TRAJECTORY|67|Attempting to read a point of the trajectory with an index higher than the number of point in trajectory point list.|
|CONTROL\_ALREADY\_RUNNING|68|Trajectory is already running|
|CONTROL\_WRONG\_STARTING\_POINT|69|Robot is not on the first point of the trajectory when we try to start the trajectory. This can happen if there is a motion between the moment when trajectory is computed and when it is started.|
|CONTROL\_CARTESIAN\_CANNOT\_START|70|Cannot start|
|CONTROL\_UNDEFINED\_CONSTRAINT|71|Kontrol library is not initialized|
|CONTROL\_UNINITIALIZED|72|Contraint sent is not defined|
|CONTROL\_NO\_ACTION|73|Action does not exist|
|CONTROL\_UNDEFINED|74|Undefined error|
|WRONG\_SERVOING\_MODE|75|Robot is in not in the right servoing mode|
|CONTROL\_WRONG\_STARTING\_SPEED|76|Robot is not at the right speed when starting a new trajectory.|
|USERNAME\_LENGTH\_EXCEEDED|100|User profile username length exceeds maximum allowed length|
|FIRSTNAME\_LENGTH\_EXCEEDED|101|User profile first name length exceeds maximum allowed length|
|LASTNAME\_LENGTH\_EXCEEDED|102|User profile last name length exceeds maximum allowed length|
|PASSWORD\_LENGTH\_EXCEEDED|103|User profile password length exceeds maximum allowed length|
|USERNAME\_ALREADY\_EXISTS|104|User profile username already in use by another profile|
|USERNAME\_EMPTY|105|User profile empty username not allowed|
|PASSWORD\_NOT\_CHANGED|106|Change password both passwords are the same|
|MAXIMUM\_USER\_PROFILES\_USED|107|Maximum number of user profiles in use|
|ROUTER\_UNVAILABLE|108|The client router is currently unavailable. This can happen if an API method is called after the router has been deactivated via the method SetActivationStatus.|
|ADDRESS\_NOT\_IN\_VALID\_RANGE|120|IP Address not valid against netmask|
|ADDRESS\_NOT\_CONFIGURABLE|121|IP Address not configurable on specified interface|
|SESSION\_NOT\_IN\_CONTROL|130|Trying to perform command from a non-controlling session in single-level mode|
|METHOD\_TIMEOUT|131|Timeout occured during method execution|
|UNSUPPORTED\_ROBOT\_CONFIGURATION|132|Product Configuration setter method failed because changing this parameter is unsupported on your robot model|
|NVRAM\_READ\_FAIL|133|Failed to read in NVRAM.|
|NVRAM\_WRITE\_FAIL|134|Failed to write in NVRAM.|
|NETWORK\_NO\_ADDRESS\_ASSIGNED|135|The specified interface has no assigned IP|
|READ\_PERMISSION\_DENIED|136|Attempting read command on unreadable entity|
|CONTROLLER\_INVALID\_MAPPING|137|Attempting to assign an unsuited mapping to controller|
|ACTION\_IN\_USE|138|Attempting to delete an Action used by another entity|
|SEND\_FAILED|139|An error occured when trying to send the message \(Transport error\)|
|CONTROL\_WAYPOINT\_TRAJECTORY\_ABORTED|140|Waypoint trajectory sequence aborted by kontrol library|
|CONTROL\_PERMISSION\_DENIED|141|Permission to execute a routine from the kontrol interface denied|

**Parent topic:** [Api \(Python\)](../../summary_pages/Api.md)

