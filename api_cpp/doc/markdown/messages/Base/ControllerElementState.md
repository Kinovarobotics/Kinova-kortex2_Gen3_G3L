# class ControllerElementState

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [ControllerElementHandle](ControllerElementHandle.md#)|Controller element handle|
|event\_type|uint32|Type of controller element event that occured|
|axis\_value|float32|Axis value \(set between -1.0 and 1.0\); only set if 'axis' controller element, otherwise set to zero|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [ControllerElementHandle](ControllerElementHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [ControllerElementHandle](ControllerElementHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [ControllerElementHandle](ControllerElementHandle.md#) \*|void|Returns a pointer to the mutable [ControllerElementHandle](ControllerElementHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ControllerElementHandle](ControllerElementHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerElementHandle](ControllerElementHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [ControllerElementHandle](ControllerElementHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [ControllerElementHandle](ControllerElementHandle.md#) \*|Sets the [ControllerElementHandle](ControllerElementHandle.md#) object to the field and frees the previous field value if it exists. If the [ControllerElementHandle](ControllerElementHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ControllerElementHandle](ControllerElementHandle.md#) object and has\_ [ControllerElementHandle](ControllerElementHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [ControllerElementHandle](ControllerElementHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ControllerElementHandle](ControllerElementHandle.md#) object. After calling this, caller takes the ownership of the allocated [ControllerElementHandle](ControllerElementHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|event\_type\(\) const|uint32|void|Returns the current value of event\_type. If the event\_type is not set, returns 0.|
|set\_event\_type\(\)|void|uint32|Sets the value of event\_type. After calling this, event\_type\(\) will return value.|
|clear\_event\_type\(\)|void|void|Clears the value of event\_type. After calling this, event\_type\(\) will return the empty string/empty bytes.|
|axis\_value\(\)|float32|void|Returns the current value of axis\_value. If the axis\_value is not set, returns 0.|
|set\_axis\_value\(\)|void|float32|Sets the value of axis\_value. After calling this, axis\_value\(\) will return value.|
|clear\_axis\_value\(\)|void|void|Clears the value of axis\_value. After calling this, axis\_value\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

