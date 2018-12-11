# Message SafetyInformation

This page describes the C++ Kinova::Api::DeviceConfig::SafetyInformation message.

## Overview / Purpose

Information about a particular safety

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SafetyHandle](msg_Common_SafetyHandle.md#)|Safety handle that this information is about|
|can\_change\_safety\_state|bool|True if related safety configuration can be modified|
|has\_warning\_threshold|bool|True if safety status can go in Warning|
|has\_error\_threshold|bool|True if safety status can go in Error|
|limit\_type| [SafetyLimitType](enm_DeviceConfig_SafetyLimitType.md#)|Safety limit type|
|default\_warning\_threshold|float32|Default warning threshold \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT and 'has\_warning\_threshold' is true\)|
|default\_error\_threshold|float32|Default error threshold \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT and 'has\_error\_threshold' is true\)|
|upper\_hard\_limit|float32|Maximal threshold value \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT\)|
|lower\_hard\_limit|float32|Minimal threshold value \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT\)|
|status| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|Current Safety status|
|unit| [Unit](enm_Common_Unit.md#)|Unit that the safety status is in|

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
|can\_change\_safety\_state\(\)|bool|void|Returns the current value of can\_change\_safety\_state. If the can\_change\_safety\_state is not set, returns 0.|
|set\_can\_change\_safety\_state\(\)|void|bool|Sets the value of can\_change\_safety\_state. After calling this, can\_change\_safety\_state\(\) will return value.|
|clear\_can\_change\_safety\_state\(\)|void|void|Clears the value of can\_change\_safety\_state. After calling this, can\_change\_safety\_state\(\) will return 0.|
|has\_warning\_threshold\(\)|bool|void|Returns the current value of has\_warning\_threshold. If the has\_warning\_threshold is not set, returns 0.|
|set\_has\_warning\_threshold\(\)|void|bool|Sets the value of has\_warning\_threshold. After calling this, has\_warning\_threshold\(\) will return value.|
|clear\_has\_warning\_threshold\(\)|void|void|Clears the value of has\_warning\_threshold. After calling this, has\_warning\_threshold\(\) will return 0.|
|has\_error\_threshold\(\)|bool|void|Returns the current value of has\_error\_threshold. If the has\_error\_threshold is not set, returns 0.|
|set\_has\_error\_threshold\(\)|void|bool|Sets the value of has\_error\_threshold. After calling this, has\_error\_threshold\(\) will return value.|
|clear\_has\_error\_threshold\(\)|void|void|Clears the value of has\_error\_threshold. After calling this, has\_error\_threshold\(\) will return 0.|
|limit\_type\(\) const| [SafetyLimitType](enm_DeviceConfig_SafetyLimitType.md#)|void|Returns the current value of limit\_type. If the limit\_type is not set, returns 0.|
|set\_limit\_type\(\)|void| [SafetyLimitType](enm_DeviceConfig_SafetyLimitType.md#)|Sets the value of limit\_type. After calling this, limit\_type\(\) will return value.|
|clear\_limit\_type\(\)|void|void|Clears the value of limit\_type. After calling this, limit\_type\(\) will return the empty string/empty bytes.|
|default\_warning\_threshold\(\)|float32|void|Returns the current value of default\_warning\_threshold. If the default\_warning\_threshold is not set, returns 0.|
|set\_default\_warning\_threshold\(\)|void|float32|Sets the value of default\_warning\_threshold. After calling this, default\_warning\_threshold\(\) will return value.|
|clear\_default\_warning\_threshold\(\)|void|void|Clears the value of default\_warning\_threshold. After calling this, default\_warning\_threshold\(\) will return 0.|
|default\_error\_threshold\(\)|float32|void|Returns the current value of default\_error\_threshold. If the default\_error\_threshold is not set, returns 0.|
|set\_default\_error\_threshold\(\)|void|float32|Sets the value of default\_error\_threshold. After calling this, default\_error\_threshold\(\) will return value.|
|clear\_default\_error\_threshold\(\)|void|void|Clears the value of default\_error\_threshold. After calling this, default\_error\_threshold\(\) will return 0.|
|upper\_hard\_limit\(\)|float32|void|Returns the current value of upper\_hard\_limit. If the upper\_hard\_limit is not set, returns 0.|
|set\_upper\_hard\_limit\(\)|void|float32|Sets the value of upper\_hard\_limit. After calling this, upper\_hard\_limit\(\) will return value.|
|clear\_upper\_hard\_limit\(\)|void|void|Clears the value of upper\_hard\_limit. After calling this, upper\_hard\_limit\(\) will return 0.|
|lower\_hard\_limit\(\)|float32|void|Returns the current value of lower\_hard\_limit. If the lower\_hard\_limit is not set, returns 0.|
|set\_lower\_hard\_limit\(\)|void|float32|Sets the value of lower\_hard\_limit. After calling this, lower\_hard\_limit\(\) will return value.|
|clear\_lower\_hard\_limit\(\)|void|void|Clears the value of lower\_hard\_limit. After calling this, lower\_hard\_limit\(\) will return 0.|
|status\(\) const| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|void|Returns the current value of status. If the status is not set, returns 0.|
|set\_status\(\)|void| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|Sets the value of status. After calling this, status\(\) will return value.|
|clear\_status\(\)|void|void|Clears the value of status. After calling this, status\(\) will return the empty string/empty bytes.|
|unit\(\) const| [Unit](enm_Common_Unit.md#)|void|Returns the current value of unit. If the unit is not set, returns 0.|
|set\_unit\(\)|void| [Unit](enm_Common_Unit.md#)|Sets the value of unit. After calling this, unit\(\) will return value.|
|clear\_unit\(\)|void|void|Clears the value of unit. After calling this, unit\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

