# Message OptionInformation

This page describes the Python Kinova.Api.VisionConfig.OptionInformation message.

## Overview / Purpose

Packages information about the optional settings for the chosen sensor

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor| [Sensor](enm_VisionConfig_Sensor.md#)|The sensor \(color or depth\)|
|option| [Option](enm_VisionConfig_Option.md#)|The option|
|supported|bool|Is the option supported by the chosen sensor?|
|read\_only|bool|Is the option read-only, or can it be changed?|
|minimum|float|Minimum value for the option|
|maximum|float|Maximum value for the option|
|step|float|Step size for the option value \(if it takes on discrete values\)|
|default\_value|float|Default value for the option|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

