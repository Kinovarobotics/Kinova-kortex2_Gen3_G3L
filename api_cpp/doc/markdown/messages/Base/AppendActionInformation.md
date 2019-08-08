# class AppendActionInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_handle| [SequenceHandle](SequenceHandle.md#)|Sequence to which action must be appended|
|action| [Action](Action.md#)|Action to append|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_sequence\_handle\(\) const|bool|void|Returns true if sequence\_handle is set.|
|sequence\_handle\(\)|const [SequenceHandle](SequenceHandle.md#)&|void|Returns the current value of sequence\_handle. If sequence\_handle is not set, returns a [SequenceHandle](SequenceHandle.md#) with none of its fields set \(possibly sequence\_handle::default\_instance\(\)\).|
|mutable\_sequence\_handle\(\)| [SequenceHandle](SequenceHandle.md#) \*|void|Returns a pointer to the mutable [SequenceHandle](SequenceHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceHandle](SequenceHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceHandle](SequenceHandle.md#)\). After calling this, has\_sequence\_handle\(\) will return true and sequence\_handle\(\) will return a reference to the same instance of [SequenceHandle](SequenceHandle.md#).|
|clear\_sequence\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_sequence\_handle\(\) will return false and sequence\_handle\(\) will return the default value.|
|set\_allocated\_sequence\_handle\(\)|void| [SequenceHandle](SequenceHandle.md#) \*|Sets the [SequenceHandle](SequenceHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceHandle](SequenceHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceHandle](SequenceHandle.md#) object and has\_ [SequenceHandle](SequenceHandle.md#)\(\) will return true. Otherwise, if the sequence\_handle is NULL, the behavior is the same as calling clear\_sequence\_handle\(\).|
|release\_sequence\_handle\(\)| [SequenceHandle](SequenceHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceHandle](SequenceHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceHandle](SequenceHandle.md#) object, has\_sequence\_handle\(\) will return false, and sequence\_handle\(\) will return the default value.|
|has\_action\(\) const|bool|void|Returns true if action is set.|
|action\(\)|const [Action](Action.md#)&|void|Returns the current value of action. If action is not set, returns a [Action](Action.md#) with none of its fields set \(possibly action::default\_instance\(\)\).|
|mutable\_action\(\)| [Action](Action.md#) \*|void|Returns a pointer to the mutable [Action](Action.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Action](Action.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Action](Action.md#)\). After calling this, has\_action\(\) will return true and action\(\) will return a reference to the same instance of [Action](Action.md#).|
|clear\_action\(\)|void|void|Clears the value of the field. After calling this, has\_action\(\) will return false and action\(\) will return the default value.|
|set\_allocated\_action\(\)|void| [Action](Action.md#) \*|Sets the [Action](Action.md#) object to the field and frees the previous field value if it exists. If the [Action](Action.md#) pointer is not NULL, the message takes ownership of the allocated [Action](Action.md#) object and has\_ [Action](Action.md#)\(\) will return true. Otherwise, if the action is NULL, the behavior is the same as calling clear\_action\(\).|
|release\_action\(\)| [Action](Action.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Action](Action.md#) object. After calling this, caller takes the ownership of the allocated [Action](Action.md#) object, has\_action\(\) will return false, and action\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

