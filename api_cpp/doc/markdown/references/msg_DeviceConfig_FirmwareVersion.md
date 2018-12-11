# Message FirmwareVersion

This page describes the C++ Kinova::Api::DeviceConfig::FirmwareVersion message.

## Overview / Purpose

Message specifying the firmware version for the device

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|firmware\_version|uint32|Firmware version|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|firmware\_version\(\)|uint32|void|Returns the current value of firmware\_version. If the firmware\_version is not set, returns 0.|
|set\_firmware\_version\(\)|void|uint32|Sets the value of firmware\_version. After calling this, firmware\_version\(\) will return value.|
|clear\_firmware\_version\(\)|void|void|Clears the value of firmware\_version. After calling this, firmware\_version\(\) will return 0.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

