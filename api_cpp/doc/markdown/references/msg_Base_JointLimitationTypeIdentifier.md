# Message JointLimitationTypeIdentifier

This page describes the C++ Kinova::Api::Base::JointLimitationTypeIdentifier message.

## Overview / Purpose

Identifies a joint limitation for a specific joint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device\_identifier|uint32|Joint device identifier|
|type|uint32|Joint limitation type|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|device\_identifier\(\)|uint32|void|Returns the current value of device\_identifier. If the device\_identifier is not set, returns 0.|
|set\_device\_identifier\(\)|void|uint32|Sets the value of device\_identifier. After calling this, device\_identifier\(\) will return value.|
|clear\_device\_identifier\(\)|void|void|Clears the value of device\_identifier. After calling this, device\_identifier\(\) will return 0.|
|type\(\) const|uint32|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void|uint32|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

