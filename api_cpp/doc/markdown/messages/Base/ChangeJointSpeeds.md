# class ChangeJointSpeeds

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_speeds| [JointSpeeds](JointSpeeds.md#)|Joint speeds|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_joint\_speeds\(\) const|bool|void|Returns true if joint\_speeds is set.|
|joint\_speeds\(\)|const [JointSpeeds](JointSpeeds.md#)&|void|Returns the current value of joint\_speeds. If joint\_speeds is not set, returns a [JointSpeeds](JointSpeeds.md#) with none of its fields set \(possibly joint\_speeds::default\_instance\(\)\).|
|mutable\_joint\_speeds\(\)| [JointSpeeds](JointSpeeds.md#) \*|void|Returns a pointer to the mutable [JointSpeeds](JointSpeeds.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointSpeeds](JointSpeeds.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointSpeeds](JointSpeeds.md#)\). After calling this, has\_joint\_speeds\(\) will return true and joint\_speeds\(\) will return a reference to the same instance of [JointSpeeds](JointSpeeds.md#).|
|clear\_joint\_speeds\(\)|void|void|Clears the value of the field. After calling this, has\_joint\_speeds\(\) will return false and joint\_speeds\(\) will return the default value.|
|set\_allocated\_joint\_speeds\(\)|void| [JointSpeeds](JointSpeeds.md#) \*|Sets the [JointSpeeds](JointSpeeds.md#) object to the field and frees the previous field value if it exists. If the [JointSpeeds](JointSpeeds.md#) pointer is not NULL, the message takes ownership of the allocated [JointSpeeds](JointSpeeds.md#) object and has\_ [JointSpeeds](JointSpeeds.md#)\(\) will return true. Otherwise, if the joint\_speeds is NULL, the behavior is the same as calling clear\_joint\_speeds\(\).|
|release\_joint\_speeds\(\)| [JointSpeeds](JointSpeeds.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointSpeeds](JointSpeeds.md#) object. After calling this, caller takes the ownership of the allocated [JointSpeeds](JointSpeeds.md#) object, has\_joint\_speeds\(\) will return false, and joint\_speeds\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

