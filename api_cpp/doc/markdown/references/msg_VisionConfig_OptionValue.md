# Message OptionValue

This page describes the C++ Kinova::Api::VisionConfig::OptionValue message.

## Overview / Purpose

Identifies the value of the particular option for the sensor.

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor| [Sensor](enm_VisionConfig_Sensor.md#)|The sensor to configure \(color or depth\)|
|option| [Option](enm_VisionConfig_Option.md#)|The option to configure|
|value|float32|The desired value for the option|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sensor\(\) const| [Sensor](enm_VisionConfig_Sensor.md#)|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void| [Sensor](enm_VisionConfig_Sensor.md#)|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|option\(\) const| [Option](enm_VisionConfig_Option.md#)|void|Returns the current value of option. If the option is not set, returns 0.|
|set\_option\(\)|void| [Option](enm_VisionConfig_Option.md#)|Sets the value of option. After calling this, option\(\) will return value.|
|clear\_option\(\)|void|void|Clears the value of option. After calling this, option\(\) will return the empty string/empty bytes.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

