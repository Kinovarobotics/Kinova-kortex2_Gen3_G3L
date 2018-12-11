# Message SafetyConfiguration

This page describes the C++ Kinova::Api::DeviceConfig::SafetyConfiguration message.

## Overview / Purpose

Configure a safety

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SafetyHandle](msg_Common_SafetyHandle.md#)|Identifies safety to configure|
|error\_threshold|float32|Safety error threshold value|
|warning\_threshold|float32|Safety warning threshold value|
|enable| [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#)|Safety enable state|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [SafetyHandle](msg_Common_SafetyHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [SafetyHandle](msg_Common_SafetyHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [SafetyHandle](msg_Common_SafetyHandle.md#) \*|void|Returns a pointer to the mutable [SafetyHandle](msg_Common_SafetyHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyHandle](msg_Common_SafetyHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyHandle](msg_Common_SafetyHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [SafetyHandle](msg_Common_SafetyHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [SafetyHandle](msg_Common_SafetyHandle.md#) \*|Sets the [SafetyHandle](msg_Common_SafetyHandle.md#) object to the field and frees the previous field value if it exists. If the [SafetyHandle](msg_Common_SafetyHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyHandle](msg_Common_SafetyHandle.md#) object and has\_ [SafetyHandle](msg_Common_SafetyHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [SafetyHandle](msg_Common_SafetyHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyHandle](msg_Common_SafetyHandle.md#) object. After calling this, caller takes the ownership of the allocated [SafetyHandle](msg_Common_SafetyHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|error\_threshold\(\)|float32|void|Returns the current value of error\_threshold. If the error\_threshold is not set, returns 0.|
|set\_error\_threshold\(\)|void|float32|Sets the value of error\_threshold. After calling this, error\_threshold\(\) will return value.|
|clear\_error\_threshold\(\)|void|void|Clears the value of error\_threshold. After calling this, error\_threshold\(\) will return 0.|
|warning\_threshold\(\)|float32|void|Returns the current value of warning\_threshold. If the warning\_threshold is not set, returns 0.|
|set\_warning\_threshold\(\)|void|float32|Sets the value of warning\_threshold. After calling this, warning\_threshold\(\) will return value.|
|clear\_warning\_threshold\(\)|void|void|Clears the value of warning\_threshold. After calling this, warning\_threshold\(\) will return 0.|
|has\_enable\(\) const|bool|void|Returns true if enable is set.|
|enable\(\)|const [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#)&|void|Returns the current value of enable. If enable is not set, returns a [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) with none of its fields set \(possibly enable::default\_instance\(\)\).|
|mutable\_enable\(\)| [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) \*|void|Returns a pointer to the mutable [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#)\). After calling this, has\_enable\(\) will return true and enable\(\) will return a reference to the same instance of [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#).|
|clear\_enable\(\)|void|void|Clears the value of the field. After calling this, has\_enable\(\) will return false and enable\(\) will return the default value.|
|set\_allocated\_enable\(\)|void| [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) \*|Sets the [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) object to the field and frees the previous field value if it exists. If the [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) object and has\_ [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#)\(\) will return true. Otherwise, if the enable is NULL, the behavior is the same as calling clear\_enable\(\).|
|release\_enable\(\)| [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) object. After calling this, caller takes the ownership of the allocated [SafetyEnable](msg_DeviceConfig_SafetyEnable.md#) object, has\_enable\(\) will return false, and enable\(\) will return the default value.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

