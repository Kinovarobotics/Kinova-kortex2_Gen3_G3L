# Message SafetyThreshold

This page describes the C++ Kinova::Api::DeviceConfig::SafetyThreshold message.

## Overview / Purpose

Configure threshold of a specific safety

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SafetyHandle](msg_Common_SafetyHandle.md#)|Identifies safety to configure|
|value|float32|Safety threshold value|

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
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

