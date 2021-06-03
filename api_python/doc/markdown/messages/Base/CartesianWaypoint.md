# class CartesianWaypoint

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|pose| [Pose](Pose.md#)|Target Cartesian Pose|To set pose, you simply assign a value directly to a field within pose. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|reference\_frame|int|The reference frame used for the goal Pose|You can manipulate the field reference\_frame as if it were a regular field. To clear the value of reference\_frame and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|maximum\_linear\_velocity|float|Maximum linear velocity \(in m/s\) during movement \(optional\)|You can manipulate the field maximum\_linear\_velocity as if it were a regular field. To clear the value of maximum\_linear\_velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|maximum\_angular\_velocity|float|Maximum angular velocity \(in deg/s\) during movement \(optional\)|You can manipulate the field maximum\_angular\_velocity as if it were a regular field. To clear the value of maximum\_angular\_velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|blending\_radius|float|Blending radius \(in m\) to use for the movement \(if this waypoint is not an endpoint\).|You can manipulate the field blending\_radius as if it were a regular field. To clear the value of blending\_radius and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

