# Message LimitationTypeIdentifier

This page describes the C++ Kinova::Api::Base::LimitationTypeIdentifier message.

## Overview / Purpose

Identifies a limitation

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type| [LimitationType](enm_Base_LimitationType.md#)|Limitation type|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|type\(\) const| [LimitationType](enm_Base_LimitationType.md#)|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void| [LimitationType](enm_Base_LimitationType.md#)|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

