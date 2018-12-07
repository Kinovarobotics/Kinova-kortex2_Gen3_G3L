# Message PositionCommand

This page describes the C++ Kinova::Api::ActuatorConfig::PositionCommand message.

## Overview / Purpose

Defines a position command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|position|float32|Position value|
|velocity|float32|Velocity value|
|acceleration|float32|Acceleration value|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|position\(\)|float32|void|Returns the current value of position. If the position is not set, returns 0.|
|set\_position\(\)|void|float32|Sets the value of position. After calling this, position\(\) will return value.|
|clear\_position\(\)|void|void|Clears the value of position. After calling this, position\(\) will return 0.|
|velocity\(\)|float32|void|Returns the current value of velocity. If the velocity is not set, returns 0.|
|set\_velocity\(\)|void|float32|Sets the value of velocity. After calling this, velocity\(\) will return value.|
|clear\_velocity\(\)|void|void|Clears the value of velocity. After calling this, velocity\(\) will return 0.|
|acceleration\(\)|float32|void|Returns the current value of acceleration. If the acceleration is not set, returns 0.|
|set\_acceleration\(\)|void|float32|Sets the value of acceleration. After calling this, acceleration\(\) will return value.|
|clear\_acceleration\(\)|void|void|Clears the value of acceleration. After calling this, acceleration\(\) will return 0.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

