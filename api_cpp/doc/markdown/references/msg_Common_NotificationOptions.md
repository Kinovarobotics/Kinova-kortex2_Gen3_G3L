# Message NotificationOptions

This page describes the C++ Kinova::Api::Common::NotificationOptions message.

## Overview / Purpose

Specifies options associated to a Notification

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type| [NotificationType](enm_Common_NotificationType.md#)|Type of notification|
|rate\_m\_sec|uint32|Rate value \(in meters per second\) \(if applicable\)|
|threshold\_value|float32|Threshold value \(if applicable\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|type\(\) const| [NotificationType](enm_Common_NotificationType.md#)|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void| [NotificationType](enm_Common_NotificationType.md#)|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|rate\_m\_sec\(\)|uint32|void|Returns the current value of rate\_m\_sec. If the rate\_m\_sec is not set, returns 0.|
|set\_rate\_m\_sec\(\)|void|uint32|Sets the value of rate\_m\_sec. After calling this, rate\_m\_sec\(\) will return value.|
|clear\_rate\_m\_sec\(\)|void|void|Clears the value of rate\_m\_sec. After calling this, rate\_m\_sec\(\) will return 0.|
|threshold\_value\(\)|float32|void|Returns the current value of threshold\_value. If the threshold\_value is not set, returns 0.|
|set\_threshold\_value\(\)|void|float32|Sets the value of threshold\_value. After calling this, threshold\_value\(\) will return value.|
|clear\_threshold\_value\(\)|void|void|Clears the value of threshold\_value. After calling this, threshold\_value\(\) will return 0.|

**Parent topic:** [Common](../references/summary_Common.md)

