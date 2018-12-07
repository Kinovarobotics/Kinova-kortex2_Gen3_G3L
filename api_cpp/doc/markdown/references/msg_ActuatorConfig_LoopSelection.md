# Message LoopSelection

This page describes the C++ Kinova::Api::ActuatorConfig::LoopSelection message.

## Overview / Purpose

Defines the loop selection

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|loop\_selection|uint32|ControlLoopSelection enum|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|loop\_selection\(\) const|uint32|void|Returns the current value of loop\_selection. If the loop\_selection is not set, returns 0.|
|set\_loop\_selection\(\)|void|uint32|Sets the value of loop\_selection. After calling this, loop\_selection\(\) will return value.|
|clear\_loop\_selection\(\)|void|void|Clears the value of loop\_selection. After calling this, loop\_selection\(\) will return the empty string/empty bytes.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

