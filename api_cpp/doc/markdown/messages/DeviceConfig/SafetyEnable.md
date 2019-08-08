# class SafetyEnable

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SafetyHandle](../Common/SafetyHandle.md#)|Handle to safety to enable or disable|
|enable|bool|Safety enable state|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [SafetyHandle](../Common/SafetyHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [SafetyHandle](../Common/SafetyHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [SafetyHandle](../Common/SafetyHandle.md#) \*|void|Returns a pointer to the mutable [SafetyHandle](../Common/SafetyHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyHandle](../Common/SafetyHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyHandle](../Common/SafetyHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [SafetyHandle](../Common/SafetyHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [SafetyHandle](../Common/SafetyHandle.md#) \*|Sets the [SafetyHandle](../Common/SafetyHandle.md#) object to the field and frees the previous field value if it exists. If the [SafetyHandle](../Common/SafetyHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyHandle](../Common/SafetyHandle.md#) object and has\_ [SafetyHandle](../Common/SafetyHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [SafetyHandle](../Common/SafetyHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyHandle](../Common/SafetyHandle.md#) object. After calling this, caller takes the ownership of the allocated [SafetyHandle](../Common/SafetyHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|enable\(\)|bool|void|Returns the current value of enable. If the enable is not set, returns 0.|
|set\_enable\(\)|void|bool|Sets the value of enable. After calling this, enable\(\) will return value.|
|clear\_enable\(\)|void|void|Clears the value of enable. After calling this, enable\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

