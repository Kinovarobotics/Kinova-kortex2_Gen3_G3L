# Message CommandModeInformation

This page describes the C++ Kinova::Api::ActuatorConfig::CommandModeInformation message.

## Overview / Purpose

Selects command mode

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_mode| [CommandMode](enm_ActuatorConfig_CommandMode.md#)|Command mode|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|command\_mode\(\) const| [CommandMode](enm_ActuatorConfig_CommandMode.md#)|void|Returns the current value of command\_mode. If the command\_mode is not set, returns 0.|
|set\_command\_mode\(\)|void| [CommandMode](enm_ActuatorConfig_CommandMode.md#)|Sets the value of command\_mode. After calling this, command\_mode\(\) will return value.|
|clear\_command\_mode\(\)|void|void|Clears the value of command\_mode. After calling this, command\_mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

