# Message RunMode

This page describes the C++ Kinova::Api::DeviceConfig::RunMode message.

## Overview / Purpose

Message specifying the run mode

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|run\_mode| [RunModes](enm_DeviceConfig_RunModes.md#)|Run mode|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|run\_mode\(\) const| [RunModes](enm_DeviceConfig_RunModes.md#)|void|Returns the current value of run\_mode. If the run\_mode is not set, returns 0.|
|set\_run\_mode\(\)|void| [RunModes](enm_DeviceConfig_RunModes.md#)|Sets the value of run\_mode. After calling this, run\_mode\(\) will return value.|
|clear\_run\_mode\(\)|void|void|Clears the value of run\_mode. After calling this, run\_mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

