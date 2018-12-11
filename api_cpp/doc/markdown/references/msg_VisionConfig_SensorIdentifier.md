# Message SensorIdentifier

This page describes the C++ Kinova::Api::VisionConfig::SensorIdentifier message.

## Overview / Purpose

Identifies the sensor to configure.

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor| [Sensor](enm_VisionConfig_Sensor.md#)|Sensor|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sensor\(\) const| [Sensor](enm_VisionConfig_Sensor.md#)|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void| [Sensor](enm_VisionConfig_Sensor.md#)|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

