# class AdvancedSequenceHandle

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SequenceHandle](SequenceHandle.md#)|Sequence handle|
|in\_loop|bool| |

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [SequenceHandle](SequenceHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [SequenceHandle](SequenceHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [SequenceHandle](SequenceHandle.md#) \*|void|Returns a pointer to the mutable [SequenceHandle](SequenceHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceHandle](SequenceHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceHandle](SequenceHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [SequenceHandle](SequenceHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [SequenceHandle](SequenceHandle.md#) \*|Sets the [SequenceHandle](SequenceHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceHandle](SequenceHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceHandle](SequenceHandle.md#) object and has\_ [SequenceHandle](SequenceHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [SequenceHandle](SequenceHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceHandle](SequenceHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceHandle](SequenceHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|in\_loop\(\)|bool|void|Returns the current value of in\_loop. If the in\_loop is not set, returns 0.|
|set\_in\_loop\(\)|void|bool|Sets the value of in\_loop. After calling this, in\_loop\(\) will return value.|
|clear\_in\_loop\(\)|void|void|Clears the value of in\_loop. After calling this, in\_loop\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

