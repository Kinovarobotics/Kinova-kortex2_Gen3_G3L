# class CartesianWaypoint

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|pose| [Pose](Pose.md#)|Target Cartesian Pose|
|reference\_frame|uint32|The reference frame used for the goal Pose|
|maximum\_linear\_velocity|float32|Maximum linear velocity \(in m/s\) during movement \(optional\)|
|maximum\_angular\_velocity|float32|Maximum angular velocity \(in deg/s\) during movement \(optional\)|
|blending\_radius|float32|Blending radius \(in m\) to use for the movement \(if this waypoint is not an endpoint\).|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_pose\(\) const|bool|void|Returns true if pose is set.|
|pose\(\)|const [Pose](Pose.md#)&|void|Returns the current value of pose. If pose is not set, returns a [Pose](Pose.md#) with none of its fields set \(possibly pose::default\_instance\(\)\).|
|mutable\_pose\(\)| [Pose](Pose.md#) \*|void|Returns a pointer to the mutable [Pose](Pose.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Pose](Pose.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Pose](Pose.md#)\). After calling this, has\_pose\(\) will return true and pose\(\) will return a reference to the same instance of [Pose](Pose.md#).|
|clear\_pose\(\)|void|void|Clears the value of the field. After calling this, has\_pose\(\) will return false and pose\(\) will return the default value.|
|set\_allocated\_pose\(\)|void| [Pose](Pose.md#) \*|Sets the [Pose](Pose.md#) object to the field and frees the previous field value if it exists. If the [Pose](Pose.md#) pointer is not NULL, the message takes ownership of the allocated [Pose](Pose.md#) object and has\_ [Pose](Pose.md#)\(\) will return true. Otherwise, if the pose is NULL, the behavior is the same as calling clear\_pose\(\).|
|release\_pose\(\)| [Pose](Pose.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Pose](Pose.md#) object. After calling this, caller takes the ownership of the allocated [Pose](Pose.md#) object, has\_pose\(\) will return false, and pose\(\) will return the default value.|
|reference\_frame\(\) const|uint32|void|Returns the current value of reference\_frame. If the reference\_frame is not set, returns 0.|
|set\_reference\_frame\(\)|void|uint32|Sets the value of reference\_frame. After calling this, reference\_frame\(\) will return value.|
|clear\_reference\_frame\(\)|void|void|Clears the value of reference\_frame. After calling this, reference\_frame\(\) will return the empty string/empty bytes.|
|maximum\_linear\_velocity\(\)|float32|void|Returns the current value of maximum\_linear\_velocity. If the maximum\_linear\_velocity is not set, returns 0.|
|set\_maximum\_linear\_velocity\(\)|void|float32|Sets the value of maximum\_linear\_velocity. After calling this, maximum\_linear\_velocity\(\) will return value.|
|clear\_maximum\_linear\_velocity\(\)|void|void|Clears the value of maximum\_linear\_velocity. After calling this, maximum\_linear\_velocity\(\) will return 0.|
|maximum\_angular\_velocity\(\)|float32|void|Returns the current value of maximum\_angular\_velocity. If the maximum\_angular\_velocity is not set, returns 0.|
|set\_maximum\_angular\_velocity\(\)|void|float32|Sets the value of maximum\_angular\_velocity. After calling this, maximum\_angular\_velocity\(\) will return value.|
|clear\_maximum\_angular\_velocity\(\)|void|void|Clears the value of maximum\_angular\_velocity. After calling this, maximum\_angular\_velocity\(\) will return 0.|
|blending\_radius\(\)|float32|void|Returns the current value of blending\_radius. If the blending\_radius is not set, returns 0.|
|set\_blending\_radius\(\)|void|float32|Sets the value of blending\_radius. After calling this, blending\_radius\(\) will return value.|
|clear\_blending\_radius\(\)|void|void|Clears the value of blending\_radius. After calling this, blending\_radius\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

