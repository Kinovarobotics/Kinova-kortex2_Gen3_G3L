# Message JointLimitationValue

This page describes the C++ Kinova::Api::Base::JointLimitationValue message.

## Overview / Purpose

Defines joint limitation value

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type| [LimitationType](enm_Base_LimitationType.md#)|Limitation type|
|value|float32|Limitation value|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|type\(\) const| [LimitationType](enm_Base_LimitationType.md#)|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void| [LimitationType](enm_Base_LimitationType.md#)|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

