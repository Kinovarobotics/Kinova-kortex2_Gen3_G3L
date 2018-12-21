# Message Servoing

This page describes the C++ Kinova::Api::ActuatorConfig::Servoing message.

## Overview / Purpose

Enables/disables servoing

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|enabled|bool|Servoing enabled|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|enabled\(\)|bool|void|Returns the current value of enabled. If the enabled is not set, returns 0.|
|set\_enabled\(\)|void|bool|Sets the value of enabled. After calling this, enabled\(\) will return value.|
|clear\_enabled\(\)|void|void|Clears the value of enabled. After calling this, enabled\(\) will return 0.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

