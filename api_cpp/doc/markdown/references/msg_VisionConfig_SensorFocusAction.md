# Message SensorFocusAction

This page describes the C++ Kinova::Api::VisionConfig::SensorFocusAction message.

## Overview / Purpose

Identifies the sensor and the focus action to perform.

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor| [Sensor](enm_VisionConfig_Sensor.md#)|The sensor on which to perform the focus action|
|focus\_action| [FocusAction](enm_VisionConfig_FocusAction.md#)|The focus action to perform on the sensor|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sensor\(\) const| [Sensor](enm_VisionConfig_Sensor.md#)|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void| [Sensor](enm_VisionConfig_Sensor.md#)|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|focus\_action\(\) const| [FocusAction](enm_VisionConfig_FocusAction.md#)|void|Returns the current value of focus\_action. If the focus\_action is not set, returns 0.|
|set\_focus\_action\(\)|void| [FocusAction](enm_VisionConfig_FocusAction.md#)|Sets the value of focus\_action. After calling this, focus\_action\(\) will return value.|
|clear\_focus\_action\(\)|void|void|Clears the value of focus\_action. After calling this, focus\_action\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

