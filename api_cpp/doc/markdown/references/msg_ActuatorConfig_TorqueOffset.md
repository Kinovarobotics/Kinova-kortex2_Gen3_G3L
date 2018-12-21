# Message TorqueOffset

This page describes the C++ Kinova::Api::ActuatorConfig::TorqueOffset message.

## Overview / Purpose

Defines torque offset

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|torque\_offset|float32|Torque offset value|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|torque\_offset\(\)|float32|void|Returns the current value of torque\_offset. If the torque\_offset is not set, returns 0.|
|set\_torque\_offset\(\)|void|float32|Sets the value of torque\_offset. After calling this, torque\_offset\(\) will return value.|
|clear\_torque\_offset\(\)|void|void|Clears the value of torque\_offset. After calling this, torque\_offset\(\) will return 0.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

