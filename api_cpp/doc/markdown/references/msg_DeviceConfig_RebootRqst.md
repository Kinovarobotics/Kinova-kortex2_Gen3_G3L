# Message RebootRqst

This page describes the C++ Kinova::Api::DeviceConfig::RebootRqst message.

## Overview / Purpose

Reboot request with bootloader delay

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|delay|uint32|Bootloader delay|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|delay\(\)|uint32|void|Returns the current value of delay. If the delay is not set, returns 0.|
|set\_delay\(\)|void|uint32|Sets the value of delay. After calling this, delay\(\) will return value.|
|clear\_delay\(\)|void|void|Clears the value of delay. After calling this, delay\(\) will return 0.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

