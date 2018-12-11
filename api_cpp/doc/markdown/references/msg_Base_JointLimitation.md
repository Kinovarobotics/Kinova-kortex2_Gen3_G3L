# Message JointLimitation

This page describes the C++ Kinova::Api::Base::JointLimitation message.

## Overview / Purpose

Defines a joint limitation

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device\_identifier|uint32|Joint device identifier|
|limitation\_value| [JointLimitationValue](msg_Base_JointLimitationValue.md#)|Joint limitation value|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|device\_identifier\(\)|uint32|void|Returns the current value of device\_identifier. If the device\_identifier is not set, returns 0.|
|set\_device\_identifier\(\)|void|uint32|Sets the value of device\_identifier. After calling this, device\_identifier\(\) will return value.|
|clear\_device\_identifier\(\)|void|void|Clears the value of device\_identifier. After calling this, device\_identifier\(\) will return 0.|
|has\_limitation\_value\(\) const|bool|void|Returns true if limitation\_value is set.|
|limitation\_value\(\)|const [JointLimitationValue](msg_Base_JointLimitationValue.md#)&|void|Returns the current value of limitation\_value. If limitation\_value is not set, returns a [JointLimitationValue](msg_Base_JointLimitationValue.md#) with none of its fields set \(possibly limitation\_value::default\_instance\(\)\).|
|mutable\_limitation\_value\(\)| [JointLimitationValue](msg_Base_JointLimitationValue.md#) \*|void|Returns a pointer to the mutable [JointLimitationValue](msg_Base_JointLimitationValue.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointLimitationValue](msg_Base_JointLimitationValue.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointLimitationValue](msg_Base_JointLimitationValue.md#)\). After calling this, has\_limitation\_value\(\) will return true and limitation\_value\(\) will return a reference to the same instance of [JointLimitationValue](msg_Base_JointLimitationValue.md#).|
|clear\_limitation\_value\(\)|void|void|Clears the value of the field. After calling this, has\_limitation\_value\(\) will return false and limitation\_value\(\) will return the default value.|
|set\_allocated\_limitation\_value\(\)|void| [JointLimitationValue](msg_Base_JointLimitationValue.md#) \*|Sets the [JointLimitationValue](msg_Base_JointLimitationValue.md#) object to the field and frees the previous field value if it exists. If the [JointLimitationValue](msg_Base_JointLimitationValue.md#) pointer is not NULL, the message takes ownership of the allocated [JointLimitationValue](msg_Base_JointLimitationValue.md#) object and has\_ [JointLimitationValue](msg_Base_JointLimitationValue.md#)\(\) will return true. Otherwise, if the limitation\_value is NULL, the behavior is the same as calling clear\_limitation\_value\(\).|
|release\_limitation\_value\(\)| [JointLimitationValue](msg_Base_JointLimitationValue.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointLimitationValue](msg_Base_JointLimitationValue.md#) object. After calling this, caller takes the ownership of the allocated [JointLimitationValue](msg_Base_JointLimitationValue.md#) object, has\_limitation\_value\(\) will return false, and limitation\_value\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

