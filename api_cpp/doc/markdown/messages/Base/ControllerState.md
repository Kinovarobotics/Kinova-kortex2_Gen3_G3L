# class ControllerState

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [ControllerHandle](ControllerHandle.md#)|Controller identifier|
|event\_type|uint32|Type of controller event that occured|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [ControllerHandle](ControllerHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [ControllerHandle](ControllerHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [ControllerHandle](ControllerHandle.md#) \*|void|Returns a pointer to the mutable [ControllerHandle](ControllerHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ControllerHandle](ControllerHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerHandle](ControllerHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [ControllerHandle](ControllerHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [ControllerHandle](ControllerHandle.md#) \*|Sets the [ControllerHandle](ControllerHandle.md#) object to the field and frees the previous field value if it exists. If the [ControllerHandle](ControllerHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ControllerHandle](ControllerHandle.md#) object and has\_ [ControllerHandle](ControllerHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [ControllerHandle](ControllerHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ControllerHandle](ControllerHandle.md#) object. After calling this, caller takes the ownership of the allocated [ControllerHandle](ControllerHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|event\_type\(\) const|uint32|void|Returns the current value of event\_type. If the event\_type is not set, returns 0.|
|set\_event\_type\(\)|void|uint32|Sets the value of event\_type. After calling this, event\_type\(\) will return value.|
|clear\_event\_type\(\)|void|void|Clears the value of event\_type. After calling this, event\_type\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

