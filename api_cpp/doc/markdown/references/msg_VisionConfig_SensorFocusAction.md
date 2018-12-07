# Message SensorFocusAction

This page describes the C++ Kinova::Api::VisionConfig::SensorFocusAction message.

## Overview / Purpose

Identifies the sensor and the focus action to perform.

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|The sensor on which to perform the focus action|
|focus\_action|uint32|The focus action to perform on the sensor|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|focus\_action\(\) const|uint32|void|Returns the current value of focus\_action. If the focus\_action is not set, returns 0.|
|set\_focus\_action\(\)|void|uint32|Sets the value of focus\_action. After calling this, focus\_action\(\) will return value.|
|clear\_focus\_action\(\)|void|void|Clears the value of focus\_action. After calling this, focus\_action\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

