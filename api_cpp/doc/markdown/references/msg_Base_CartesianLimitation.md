# Message CartesianLimitation

This page describes the C++ Kinova::Api::Base::CartesianLimitation message.

## Overview / Purpose

Provides a Cartesian limitation configuration

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type| [LimitationType](enm_Base_LimitationType.md#)|Limitation type|
|translation|float32|Translation limitation|
|orientation|float32|Orientation limitation|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|type\(\) const| [LimitationType](enm_Base_LimitationType.md#)|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void| [LimitationType](enm_Base_LimitationType.md#)|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|translation\(\)|float32|void|Returns the current value of translation. If the translation is not set, returns 0.|
|set\_translation\(\)|void|float32|Sets the value of translation. After calling this, translation\(\) will return value.|
|clear\_translation\(\)|void|void|Clears the value of translation. After calling this, translation\(\) will return 0.|
|orientation\(\)|float32|void|Returns the current value of orientation. If the orientation is not set, returns 0.|
|set\_orientation\(\)|void|float32|Sets the value of orientation. After calling this, orientation\(\) will return value.|
|clear\_orientation\(\)|void|void|Clears the value of orientation. After calling this, orientation\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

