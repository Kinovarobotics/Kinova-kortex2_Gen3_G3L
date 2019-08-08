# class Feedback

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|feedback\_id| [MessageId](MessageId.md#)|MessageId|
|status\_flags|uint32|Status flags \(see GripperConfig.RobotiqGripperStatusFlags\)|
|fault\_bank\_a|uint32|Fault bank A \(see GripperConfig.SafetyIdentifier\)|
|fault\_bank\_b|uint32|Fault bank B \(see GripperConfig.SafetyIdentifier\)|
|warning\_bank\_a|uint32|Warning bank A \(see GripperConfig.SafetyIdentifier\)|
|warning\_bank\_b|uint32|Warning bank B \(see GripperConfig.SafetyIdentifier\)|
|motor| [MotorFeedback](MotorFeedback.md#)| |

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_feedback\_id\(\) const|bool|void|Returns true if feedback\_id is set.|
|feedback\_id\(\)|const [MessageId](MessageId.md#)&|void|Returns the current value of feedback\_id. If feedback\_id is not set, returns a [MessageId](MessageId.md#) with none of its fields set \(possibly feedback\_id::default\_instance\(\)\).|
|mutable\_feedback\_id\(\)| [MessageId](MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](MessageId.md#)\). After calling this, has\_feedback\_id\(\) will return true and feedback\_id\(\) will return a reference to the same instance of [MessageId](MessageId.md#).|
|clear\_feedback\_id\(\)|void|void|Clears the value of the field. After calling this, has\_feedback\_id\(\) will return false and feedback\_id\(\) will return the default value.|
|set\_allocated\_feedback\_id\(\)|void| [MessageId](MessageId.md#) \*|Sets the [MessageId](MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](MessageId.md#) object and has\_ [MessageId](MessageId.md#)\(\) will return true. Otherwise, if the feedback\_id is NULL, the behavior is the same as calling clear\_feedback\_id\(\).|
|release\_feedback\_id\(\)| [MessageId](MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](MessageId.md#) object, has\_feedback\_id\(\) will return false, and feedback\_id\(\) will return the default value.|
|status\_flags\(\)|uint32|void|Returns the current value of status\_flags. If the status\_flags is not set, returns 0.|
|set\_status\_flags\(\)|void|uint32|Sets the value of status\_flags. After calling this, status\_flags\(\) will return value.|
|clear\_status\_flags\(\)|void|void|Clears the value of status\_flags. After calling this, status\_flags\(\) will return 0.|
|fault\_bank\_a\(\)|uint32|void|Returns the current value of fault\_bank\_a. If the fault\_bank\_a is not set, returns 0.|
|set\_fault\_bank\_a\(\)|void|uint32|Sets the value of fault\_bank\_a. After calling this, fault\_bank\_a\(\) will return value.|
|clear\_fault\_bank\_a\(\)|void|void|Clears the value of fault\_bank\_a. After calling this, fault\_bank\_a\(\) will return 0.|
|fault\_bank\_b\(\)|uint32|void|Returns the current value of fault\_bank\_b. If the fault\_bank\_b is not set, returns 0.|
|set\_fault\_bank\_b\(\)|void|uint32|Sets the value of fault\_bank\_b. After calling this, fault\_bank\_b\(\) will return value.|
|clear\_fault\_bank\_b\(\)|void|void|Clears the value of fault\_bank\_b. After calling this, fault\_bank\_b\(\) will return 0.|
|warning\_bank\_a\(\)|uint32|void|Returns the current value of warning\_bank\_a. If the warning\_bank\_a is not set, returns 0.|
|set\_warning\_bank\_a\(\)|void|uint32|Sets the value of warning\_bank\_a. After calling this, warning\_bank\_a\(\) will return value.|
|clear\_warning\_bank\_a\(\)|void|void|Clears the value of warning\_bank\_a. After calling this, warning\_bank\_a\(\) will return 0.|
|warning\_bank\_b\(\)|uint32|void|Returns the current value of warning\_bank\_b. If the warning\_bank\_b is not set, returns 0.|
|set\_warning\_bank\_b\(\)|void|uint32|Sets the value of warning\_bank\_b. After calling this, warning\_bank\_b\(\) will return value.|
|clear\_warning\_bank\_b\(\)|void|void|Clears the value of warning\_bank\_b. After calling this, warning\_bank\_b\(\) will return 0.|
|motor\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|motor\(\) const|const [MotorFeedback](MotorFeedback.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, motor\_size\(\)\) yields undefined behavior.|
|mutable\_motor\(\)| [MotorFeedback](MotorFeedback.md#)\*|int index|Returns a pointer to the mutable [MotorFeedback](MotorFeedback.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, motor\_size\(\)\) yields undefined behavior.|
|add\_motor\(\)| [MotorFeedback](MotorFeedback.md#)\*|void|Adds a new element and returns a pointer to it. The returned [MotorFeedback](MotorFeedback.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [MotorFeedback](MotorFeedback.md#)\).|
|clear\_motor\(\)|void|void|Removes all elements from the field. After calling this, motor\_size\(\) will return zero.|
|motor\(\) const|const RepeatedPtrField< [MotorFeedback](MotorFeedback.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_motor\(\)|RepeatedPtrField< [MotorFeedback](MotorFeedback.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [GripperCyclic \(C++\)](../../summary_pages/GripperCyclic.md)

