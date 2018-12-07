# Message AxisOffsets

This page describes the C++ Kinova::Api::ActuatorConfig::AxisOffsets message.

## Overview / Purpose

Defines axis offsets

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|absolute\_offset|float32|Absolute offset value|
|relative\_offset|float32|Relative offset value|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|absolute\_offset\(\)|float32|void|Returns the current value of absolute\_offset. If the absolute\_offset is not set, returns 0.|
|set\_absolute\_offset\(\)|void|float32|Sets the value of absolute\_offset. After calling this, absolute\_offset\(\) will return value.|
|clear\_absolute\_offset\(\)|void|void|Clears the value of absolute\_offset. After calling this, absolute\_offset\(\) will return 0.|
|relative\_offset\(\)|float32|void|Returns the current value of relative\_offset. If the relative\_offset is not set, returns 0.|
|set\_relative\_offset\(\)|void|float32|Sets the value of relative\_offset. After calling this, relative\_offset\(\) will return value.|
|clear\_relative\_offset\(\)|void|void|Clears the value of relative\_offset. After calling this, relative\_offset\(\) will return 0.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

