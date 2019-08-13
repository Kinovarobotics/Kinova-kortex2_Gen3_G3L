# class ActionExecutionState

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|action\_event|uint32|Action event type|
|handle| [ActionHandle](ActionHandle.md#)|Identifies the action for which this event occured|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|action\_event\(\) const|uint32|void|Returns the current value of action\_event. If the action\_event is not set, returns 0.|
|set\_action\_event\(\)|void|uint32|Sets the value of action\_event. After calling this, action\_event\(\) will return value.|
|clear\_action\_event\(\)|void|void|Clears the value of action\_event. After calling this, action\_event\(\) will return the empty string/empty bytes.|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [ActionHandle](ActionHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [ActionHandle](ActionHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [ActionHandle](ActionHandle.md#) \*|void|Returns a pointer to the mutable [ActionHandle](ActionHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ActionHandle](ActionHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActionHandle](ActionHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [ActionHandle](ActionHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [ActionHandle](ActionHandle.md#) \*|Sets the [ActionHandle](ActionHandle.md#) object to the field and frees the previous field value if it exists. If the [ActionHandle](ActionHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ActionHandle](ActionHandle.md#) object and has\_ [ActionHandle](ActionHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [ActionHandle](ActionHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ActionHandle](ActionHandle.md#) object. After calling this, caller takes the ownership of the allocated [ActionHandle](ActionHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

