# class WaypointList

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|waypoints| [Waypoint](Waypoint.md#)|Array of waypoints|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|
|duration|float|Duration of the waypoint list \(in seconds\). If unspecified or equal to 0, optimal duration is assumed.|You can manipulate the field duration as if it were a regular field. To clear the value of duration and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|use\_optimal\_blending|bool|At validation if this value is true, the waypoint list with optimal blending will be returned.|You can manipulate the field use\_optimal\_blending as if it were a regular field. To clear the value of use\_optimal\_blending and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

