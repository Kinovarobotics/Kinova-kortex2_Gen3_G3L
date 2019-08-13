# class Command

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id| [MessageId](MessageId.md#)|MessageId|
|flags|uint32|Flags|
|motor\_cmd| [MotorCommand](MotorCommand.md#)|Array of finger commands, one for each finger of the gripper.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_command\_id\(\) const|bool|void|Returns true if command\_id is set.|
|command\_id\(\)|const [MessageId](MessageId.md#)&|void|Returns the current value of command\_id. If command\_id is not set, returns a [MessageId](MessageId.md#) with none of its fields set \(possibly command\_id::default\_instance\(\)\).|
|mutable\_command\_id\(\)| [MessageId](MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](MessageId.md#)\). After calling this, has\_command\_id\(\) will return true and command\_id\(\) will return a reference to the same instance of [MessageId](MessageId.md#).|
|clear\_command\_id\(\)|void|void|Clears the value of the field. After calling this, has\_command\_id\(\) will return false and command\_id\(\) will return the default value.|
|set\_allocated\_command\_id\(\)|void| [MessageId](MessageId.md#) \*|Sets the [MessageId](MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](MessageId.md#) object and has\_ [MessageId](MessageId.md#)\(\) will return true. Otherwise, if the command\_id is NULL, the behavior is the same as calling clear\_command\_id\(\).|
|release\_command\_id\(\)| [MessageId](MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](MessageId.md#) object, has\_command\_id\(\) will return false, and command\_id\(\) will return the default value.|
|flags\(\)|uint32|void|Returns the current value of flags. If the flags is not set, returns 0.|
|set\_flags\(\)|void|uint32|Sets the value of flags. After calling this, flags\(\) will return value.|
|clear\_flags\(\)|void|void|Clears the value of flags. After calling this, flags\(\) will return 0.|
|motor\_cmd\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|motor\_cmd\(\) const|const [MotorCommand](MotorCommand.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, motor\_cmd\_size\(\)\) yields undefined behavior.|
|mutable\_motor\_cmd\(\)| [MotorCommand](MotorCommand.md#)\*|int index|Returns a pointer to the mutable [MotorCommand](MotorCommand.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, motor\_cmd\_size\(\)\) yields undefined behavior.|
|add\_motor\_cmd\(\)| [MotorCommand](MotorCommand.md#)\*|void|Adds a new element and returns a pointer to it. The returned [MotorCommand](MotorCommand.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [MotorCommand](MotorCommand.md#)\).|
|clear\_motor\_cmd\(\)|void|void|Removes all elements from the field. After calling this, motor\_cmd\_size\(\) will return zero.|
|motor\_cmd\(\) const|const RepeatedPtrField< [MotorCommand](MotorCommand.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_motor\_cmd\(\)|RepeatedPtrField< [MotorCommand](MotorCommand.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [GripperCyclic \(C++\)](../../summary_pages/GripperCyclic.md)

