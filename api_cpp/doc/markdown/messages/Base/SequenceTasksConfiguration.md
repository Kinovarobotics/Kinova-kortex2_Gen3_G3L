# class SequenceTasksConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_task\_handle| [SequenceTaskHandle](SequenceTaskHandle.md#)|Sequence Handle and task index as the insertion point|
|sequence\_tasks| [SequenceTask](SequenceTask.md#)|Tasks to be inserted|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_sequence\_task\_handle\(\) const|bool|void|Returns true if sequence\_task\_handle is set.|
|sequence\_task\_handle\(\)|const [SequenceTaskHandle](SequenceTaskHandle.md#)&|void|Returns the current value of sequence\_task\_handle. If sequence\_task\_handle is not set, returns a [SequenceTaskHandle](SequenceTaskHandle.md#) with none of its fields set \(possibly sequence\_task\_handle::default\_instance\(\)\).|
|mutable\_sequence\_task\_handle\(\)| [SequenceTaskHandle](SequenceTaskHandle.md#) \*|void|Returns a pointer to the mutable [SequenceTaskHandle](SequenceTaskHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceTaskHandle](SequenceTaskHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceTaskHandle](SequenceTaskHandle.md#)\). After calling this, has\_sequence\_task\_handle\(\) will return true and sequence\_task\_handle\(\) will return a reference to the same instance of [SequenceTaskHandle](SequenceTaskHandle.md#).|
|clear\_sequence\_task\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_sequence\_task\_handle\(\) will return false and sequence\_task\_handle\(\) will return the default value.|
|set\_allocated\_sequence\_task\_handle\(\)|void| [SequenceTaskHandle](SequenceTaskHandle.md#) \*|Sets the [SequenceTaskHandle](SequenceTaskHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceTaskHandle](SequenceTaskHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceTaskHandle](SequenceTaskHandle.md#) object and has\_ [SequenceTaskHandle](SequenceTaskHandle.md#)\(\) will return true. Otherwise, if the sequence\_task\_handle is NULL, the behavior is the same as calling clear\_sequence\_task\_handle\(\).|
|release\_sequence\_task\_handle\(\)| [SequenceTaskHandle](SequenceTaskHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceTaskHandle](SequenceTaskHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceTaskHandle](SequenceTaskHandle.md#) object, has\_sequence\_task\_handle\(\) will return false, and sequence\_task\_handle\(\) will return the default value.|
|sequence\_tasks\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|sequence\_tasks\(\) const|const [SequenceTask](SequenceTask.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_tasks\_size\(\)\) yields undefined behavior.|
|mutable\_sequence\_tasks\(\)| [SequenceTask](SequenceTask.md#)\*|int index|Returns a pointer to the mutable [SequenceTask](SequenceTask.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_tasks\_size\(\)\) yields undefined behavior.|
|add\_sequence\_tasks\(\)| [SequenceTask](SequenceTask.md#)\*|void|Adds a new element and returns a pointer to it. The returned [SequenceTask](SequenceTask.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceTask](SequenceTask.md#)\).|
|clear\_sequence\_tasks\(\)|void|void|Removes all elements from the field. After calling this, sequence\_tasks\_size\(\) will return zero.|
|sequence\_tasks\(\) const|const RepeatedPtrField< [SequenceTask](SequenceTask.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_sequence\_tasks\(\)|RepeatedPtrField< [SequenceTask](SequenceTask.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

