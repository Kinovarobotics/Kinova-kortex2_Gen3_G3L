# Message ControlModeInformation

This page describes the C++ Kinova::Api::ActuatorConfig::ControlModeInformation message.

## Overview / Purpose

Defines the control mode

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|control\_mode| [ControlMode](enm_ActuatorConfig_ControlMode.md#)|Control mode|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|control\_mode\(\) const| [ControlMode](enm_ActuatorConfig_ControlMode.md#)|void|Returns the current value of control\_mode. If the control\_mode is not set, returns 0.|
|set\_control\_mode\(\)|void| [ControlMode](enm_ActuatorConfig_ControlMode.md#)|Sets the value of control\_mode. After calling this, control\_mode\(\) will return value.|
|clear\_control\_mode\(\)|void|void|Clears the value of control\_mode. After calling this, control\_mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

