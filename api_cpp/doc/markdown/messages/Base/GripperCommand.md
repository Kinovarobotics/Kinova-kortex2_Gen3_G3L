# class GripperCommand

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode|uint32|Mode in which to control the gripper|
|gripper| [Gripper](Gripper.md#)|Gripper movement values|
|duration|uint32|Duration constraint. If not 0, allows to set a limit \(in seconds\) to the GripperCommand|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|has\_gripper\(\) const|bool|void|Returns true if gripper is set.|
|gripper\(\)|const [Gripper](Gripper.md#)&|void|Returns the current value of gripper. If gripper is not set, returns a [Gripper](Gripper.md#) with none of its fields set \(possibly gripper::default\_instance\(\)\).|
|mutable\_gripper\(\)| [Gripper](Gripper.md#) \*|void|Returns a pointer to the mutable [Gripper](Gripper.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Gripper](Gripper.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Gripper](Gripper.md#)\). After calling this, has\_gripper\(\) will return true and gripper\(\) will return a reference to the same instance of [Gripper](Gripper.md#).|
|clear\_gripper\(\)|void|void|Clears the value of the field. After calling this, has\_gripper\(\) will return false and gripper\(\) will return the default value.|
|set\_allocated\_gripper\(\)|void| [Gripper](Gripper.md#) \*|Sets the [Gripper](Gripper.md#) object to the field and frees the previous field value if it exists. If the [Gripper](Gripper.md#) pointer is not NULL, the message takes ownership of the allocated [Gripper](Gripper.md#) object and has\_ [Gripper](Gripper.md#)\(\) will return true. Otherwise, if the gripper is NULL, the behavior is the same as calling clear\_gripper\(\).|
|release\_gripper\(\)| [Gripper](Gripper.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Gripper](Gripper.md#) object. After calling this, caller takes the ownership of the allocated [Gripper](Gripper.md#) object, has\_gripper\(\) will return false, and gripper\(\) will return the default value.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

