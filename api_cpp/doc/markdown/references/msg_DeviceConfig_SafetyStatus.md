# Message SafetyStatus

This page describes the C++ Kinova::Api::DeviceConfig::SafetyStatus message.

## Overview / Purpose

Provides safety status

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|value| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|Safety status \(e.g. in error, warning or normal state\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|value\(\) const| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

