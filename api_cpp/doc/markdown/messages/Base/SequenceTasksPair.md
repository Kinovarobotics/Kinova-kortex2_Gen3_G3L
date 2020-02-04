# class SequenceTasksPair

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_handle| [SequenceHandle](SequenceHandle.md#)|Sequence handle|
|first\_task\_index|uint32|Index of first task|
|second\_task\_index|uint32|Index of second task|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_sequence\_handle\(\) const|bool|void|Returns true if sequence\_handle is set.|
|sequence\_handle\(\)|const [SequenceHandle](SequenceHandle.md#)&|void|Returns the current value of sequence\_handle. If sequence\_handle is not set, returns a [SequenceHandle](SequenceHandle.md#) with none of its fields set \(possibly sequence\_handle::default\_instance\(\)\).|
|mutable\_sequence\_handle\(\)| [SequenceHandle](SequenceHandle.md#) \*|void|Returns a pointer to the mutable [SequenceHandle](SequenceHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceHandle](SequenceHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceHandle](SequenceHandle.md#)\). After calling this, has\_sequence\_handle\(\) will return true and sequence\_handle\(\) will return a reference to the same instance of [SequenceHandle](SequenceHandle.md#).|
|clear\_sequence\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_sequence\_handle\(\) will return false and sequence\_handle\(\) will return the default value.|
|set\_allocated\_sequence\_handle\(\)|void| [SequenceHandle](SequenceHandle.md#) \*|Sets the [SequenceHandle](SequenceHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceHandle](SequenceHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceHandle](SequenceHandle.md#) object and has\_ [SequenceHandle](SequenceHandle.md#)\(\) will return true. Otherwise, if the sequence\_handle is NULL, the behavior is the same as calling clear\_sequence\_handle\(\).|
|release\_sequence\_handle\(\)| [SequenceHandle](SequenceHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceHandle](SequenceHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceHandle](SequenceHandle.md#) object, has\_sequence\_handle\(\) will return false, and sequence\_handle\(\) will return the default value.|
|first\_task\_index\(\)|uint32|void|Returns the current value of first\_task\_index. If the first\_task\_index is not set, returns 0.|
|set\_first\_task\_index\(\)|void|uint32|Sets the value of first\_task\_index. After calling this, first\_task\_index\(\) will return value.|
|clear\_first\_task\_index\(\)|void|void|Clears the value of first\_task\_index. After calling this, first\_task\_index\(\) will return 0.|
|second\_task\_index\(\)|uint32|void|Returns the current value of second\_task\_index. If the second\_task\_index is not set, returns 0.|
|set\_second\_task\_index\(\)|void|uint32|Sets the value of second\_task\_index. After calling this, second\_task\_index\(\) will return value.|
|clear\_second\_task\_index\(\)|void|void|Clears the value of second\_task\_index. After calling this, second\_task\_index\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

