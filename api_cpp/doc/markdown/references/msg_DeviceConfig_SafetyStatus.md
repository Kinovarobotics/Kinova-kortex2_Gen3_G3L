# Message SafetyStatus

This page describes the C++ Kinova::Api::DeviceConfig::SafetyStatus message.

## Overview / Purpose

Provides safety status

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|value|uint32|Safety status \(ex. in error, warning or normal state\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|value\(\) const|uint32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|uint32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

