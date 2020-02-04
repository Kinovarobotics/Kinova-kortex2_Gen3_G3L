# class SequenceTaskConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_task\_handle| [SequenceTaskHandle](SequenceTaskHandle.md#)|Sequence Handle and index of task to update|
|sequence\_task| [SequenceTask](SequenceTask.md#)|Configuration information on task to be updated|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_sequence\_task\_handle\(\) const|bool|void|Returns true if sequence\_task\_handle is set.|
|sequence\_task\_handle\(\)|const [SequenceTaskHandle](SequenceTaskHandle.md#)&|void|Returns the current value of sequence\_task\_handle. If sequence\_task\_handle is not set, returns a [SequenceTaskHandle](SequenceTaskHandle.md#) with none of its fields set \(possibly sequence\_task\_handle::default\_instance\(\)\).|
|mutable\_sequence\_task\_handle\(\)| [SequenceTaskHandle](SequenceTaskHandle.md#) \*|void|Returns a pointer to the mutable [SequenceTaskHandle](SequenceTaskHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceTaskHandle](SequenceTaskHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceTaskHandle](SequenceTaskHandle.md#)\). After calling this, has\_sequence\_task\_handle\(\) will return true and sequence\_task\_handle\(\) will return a reference to the same instance of [SequenceTaskHandle](SequenceTaskHandle.md#).|
|clear\_sequence\_task\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_sequence\_task\_handle\(\) will return false and sequence\_task\_handle\(\) will return the default value.|
|set\_allocated\_sequence\_task\_handle\(\)|void| [SequenceTaskHandle](SequenceTaskHandle.md#) \*|Sets the [SequenceTaskHandle](SequenceTaskHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceTaskHandle](SequenceTaskHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceTaskHandle](SequenceTaskHandle.md#) object and has\_ [SequenceTaskHandle](SequenceTaskHandle.md#)\(\) will return true. Otherwise, if the sequence\_task\_handle is NULL, the behavior is the same as calling clear\_sequence\_task\_handle\(\).|
|release\_sequence\_task\_handle\(\)| [SequenceTaskHandle](SequenceTaskHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceTaskHandle](SequenceTaskHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceTaskHandle](SequenceTaskHandle.md#) object, has\_sequence\_task\_handle\(\) will return false, and sequence\_task\_handle\(\) will return the default value.|
|has\_sequence\_task\(\) const|bool|void|Returns true if sequence\_task is set.|
|sequence\_task\(\)|const [SequenceTask](SequenceTask.md#)&|void|Returns the current value of sequence\_task. If sequence\_task is not set, returns a [SequenceTask](SequenceTask.md#) with none of its fields set \(possibly sequence\_task::default\_instance\(\)\).|
|mutable\_sequence\_task\(\)| [SequenceTask](SequenceTask.md#) \*|void|Returns a pointer to the mutable [SequenceTask](SequenceTask.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceTask](SequenceTask.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceTask](SequenceTask.md#)\). After calling this, has\_sequence\_task\(\) will return true and sequence\_task\(\) will return a reference to the same instance of [SequenceTask](SequenceTask.md#).|
|clear\_sequence\_task\(\)|void|void|Clears the value of the field. After calling this, has\_sequence\_task\(\) will return false and sequence\_task\(\) will return the default value.|
|set\_allocated\_sequence\_task\(\)|void| [SequenceTask](SequenceTask.md#) \*|Sets the [SequenceTask](SequenceTask.md#) object to the field and frees the previous field value if it exists. If the [SequenceTask](SequenceTask.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceTask](SequenceTask.md#) object and has\_ [SequenceTask](SequenceTask.md#)\(\) will return true. Otherwise, if the sequence\_task is NULL, the behavior is the same as calling clear\_sequence\_task\(\).|
|release\_sequence\_task\(\)| [SequenceTask](SequenceTask.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceTask](SequenceTask.md#) object. After calling this, caller takes the ownership of the allocated [SequenceTask](SequenceTask.md#) object, has\_sequence\_task\(\) will return false, and sequence\_task\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

