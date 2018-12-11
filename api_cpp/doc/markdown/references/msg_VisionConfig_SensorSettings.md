# Message SensorSettings

This page describes the C++ Kinova::Api::VisionConfig::SensorSettings message.

## Overview / Purpose

Main settings - resolution, frame rate, bit rate - for the chosen sensor \(color or depth\).

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor| [Sensor](enm_VisionConfig_Sensor.md#)|The sensor \(color or depth\)|
|resolution| [Resolution](enm_VisionConfig_Resolution.md#)|The resolution setting|
|frame\_rate| [FrameRate](enm_VisionConfig_FrameRate.md#)|Frame rate setting|
|bit\_rate| [BitRate](enm_VisionConfig_BitRate.md#)|Maximum encoded bit rate|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sensor\(\) const| [Sensor](enm_VisionConfig_Sensor.md#)|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void| [Sensor](enm_VisionConfig_Sensor.md#)|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|resolution\(\) const| [Resolution](enm_VisionConfig_Resolution.md#)|void|Returns the current value of resolution. If the resolution is not set, returns 0.|
|set\_resolution\(\)|void| [Resolution](enm_VisionConfig_Resolution.md#)|Sets the value of resolution. After calling this, resolution\(\) will return value.|
|clear\_resolution\(\)|void|void|Clears the value of resolution. After calling this, resolution\(\) will return the empty string/empty bytes.|
|frame\_rate\(\) const| [FrameRate](enm_VisionConfig_FrameRate.md#)|void|Returns the current value of frame\_rate. If the frame\_rate is not set, returns 0.|
|set\_frame\_rate\(\)|void| [FrameRate](enm_VisionConfig_FrameRate.md#)|Sets the value of frame\_rate. After calling this, frame\_rate\(\) will return value.|
|clear\_frame\_rate\(\)|void|void|Clears the value of frame\_rate. After calling this, frame\_rate\(\) will return the empty string/empty bytes.|
|bit\_rate\(\) const| [BitRate](enm_VisionConfig_BitRate.md#)|void|Returns the current value of bit\_rate. If the bit\_rate is not set, returns 0.|
|set\_bit\_rate\(\)|void| [BitRate](enm_VisionConfig_BitRate.md#)|Sets the value of bit\_rate. After calling this, bit\_rate\(\) will return value.|
|clear\_bit\_rate\(\)|void|void|Clears the value of bit\_rate. After calling this, bit\_rate\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

