# class SafetyConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SafetyHandle](../Common/SafetyHandle.md#)|Handle to safety to configure|
|error\_threshold|float32|Safety error threshold value|
|warning\_threshold|float32|Safety warning threshold value|
|enable| [SafetyEnable](SafetyEnable.md#)|Safety enable state|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [SafetyHandle](../Common/SafetyHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [SafetyHandle](../Common/SafetyHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [SafetyHandle](../Common/SafetyHandle.md#) \*|void|Returns a pointer to the mutable [SafetyHandle](../Common/SafetyHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyHandle](../Common/SafetyHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyHandle](../Common/SafetyHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [SafetyHandle](../Common/SafetyHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [SafetyHandle](../Common/SafetyHandle.md#) \*|Sets the [SafetyHandle](../Common/SafetyHandle.md#) object to the field and frees the previous field value if it exists. If the [SafetyHandle](../Common/SafetyHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyHandle](../Common/SafetyHandle.md#) object and has\_ [SafetyHandle](../Common/SafetyHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [SafetyHandle](../Common/SafetyHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyHandle](../Common/SafetyHandle.md#) object. After calling this, caller takes the ownership of the allocated [SafetyHandle](../Common/SafetyHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|error\_threshold\(\)|float32|void|Returns the current value of error\_threshold. If the error\_threshold is not set, returns 0.|
|set\_error\_threshold\(\)|void|float32|Sets the value of error\_threshold. After calling this, error\_threshold\(\) will return value.|
|clear\_error\_threshold\(\)|void|void|Clears the value of error\_threshold. After calling this, error\_threshold\(\) will return 0.|
|warning\_threshold\(\)|float32|void|Returns the current value of warning\_threshold. If the warning\_threshold is not set, returns 0.|
|set\_warning\_threshold\(\)|void|float32|Sets the value of warning\_threshold. After calling this, warning\_threshold\(\) will return value.|
|clear\_warning\_threshold\(\)|void|void|Clears the value of warning\_threshold. After calling this, warning\_threshold\(\) will return 0.|
|has\_enable\(\) const|bool|void|Returns true if enable is set.|
|enable\(\)|const [SafetyEnable](SafetyEnable.md#)&|void|Returns the current value of enable. If enable is not set, returns a [SafetyEnable](SafetyEnable.md#) with none of its fields set \(possibly enable::default\_instance\(\)\).|
|mutable\_enable\(\)| [SafetyEnable](SafetyEnable.md#) \*|void|Returns a pointer to the mutable [SafetyEnable](SafetyEnable.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyEnable](SafetyEnable.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyEnable](SafetyEnable.md#)\). After calling this, has\_enable\(\) will return true and enable\(\) will return a reference to the same instance of [SafetyEnable](SafetyEnable.md#).|
|clear\_enable\(\)|void|void|Clears the value of the field. After calling this, has\_enable\(\) will return false and enable\(\) will return the default value.|
|set\_allocated\_enable\(\)|void| [SafetyEnable](SafetyEnable.md#) \*|Sets the [SafetyEnable](SafetyEnable.md#) object to the field and frees the previous field value if it exists. If the [SafetyEnable](SafetyEnable.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyEnable](SafetyEnable.md#) object and has\_ [SafetyEnable](SafetyEnable.md#)\(\) will return true. Otherwise, if the enable is NULL, the behavior is the same as calling clear\_enable\(\).|
|release\_enable\(\)| [SafetyEnable](SafetyEnable.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyEnable](SafetyEnable.md#) object. After calling this, caller takes the ownership of the allocated [SafetyEnable](SafetyEnable.md#) object, has\_enable\(\) will return false, and enable\(\) will return the default value.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

