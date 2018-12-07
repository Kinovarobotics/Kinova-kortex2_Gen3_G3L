# Message SensorIdentifier

This page describes the C++ Kinova::Api::VisionConfig::SensorIdentifier message.

## Overview / Purpose

Identifies the sensor to configure.

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|Sensor|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

