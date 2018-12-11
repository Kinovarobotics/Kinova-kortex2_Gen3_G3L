# Message VisionNotification

This page describes the C++ Kinova::Api::VisionConfig::VisionNotification message.

## Overview / Purpose

Message that contains Vision module event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event| [VisionEvent](enm_VisionConfig_VisionEvent.md#)|Vision event|
|sensor| [Sensor](enm_VisionConfig_Sensor.md#)|The sensor that caused the notification \(if applicable\)|
|option| [Option](enm_VisionConfig_Option.md#)|The option that caused the notification \(if applicable\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|event\(\) const| [VisionEvent](enm_VisionConfig_VisionEvent.md#)|void|Returns the current value of event. If the event is not set, returns 0.|
|set\_event\(\)|void| [VisionEvent](enm_VisionConfig_VisionEvent.md#)|Sets the value of event. After calling this, event\(\) will return value.|
|clear\_event\(\)|void|void|Clears the value of event. After calling this, event\(\) will return the empty string/empty bytes.|
|sensor\(\) const| [Sensor](enm_VisionConfig_Sensor.md#)|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void| [Sensor](enm_VisionConfig_Sensor.md#)|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|option\(\) const| [Option](enm_VisionConfig_Option.md#)|void|Returns the current value of option. If the option is not set, returns 0.|
|set\_option\(\)|void| [Option](enm_VisionConfig_Option.md#)|Sets the value of option. After calling this, option\(\) will return value.|
|clear\_option\(\)|void|void|Clears the value of option. After calling this, option\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

