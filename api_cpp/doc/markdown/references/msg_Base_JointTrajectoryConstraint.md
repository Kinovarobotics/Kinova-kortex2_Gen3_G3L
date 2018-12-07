# Message JointTrajectoryConstraint

This page describes the C++ Kinova::Api::Base::JointTrajectoryConstraint message.

## Overview / Purpose

Defines a joint trajectory constraint that can be applied when controlling a joint in trajectory mode

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type|uint32|Joint trajectory constraint type|
|value|float32|Constraint value \(in seconds or in meters per second depending on constraint type\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|type\(\) const|uint32|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void|uint32|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

