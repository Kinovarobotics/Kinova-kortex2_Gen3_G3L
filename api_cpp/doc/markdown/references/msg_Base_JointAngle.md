# Message JointAngle

This page describes the C++ Kinova::Api::Base::JointAngle message.

## Overview / Purpose

Position of a specific joint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_identifier|uint32|Joint identifier|
|value|float32|Position \(in degrees\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|joint\_identifier\(\)|uint32|void|Returns the current value of joint\_identifier. If the joint\_identifier is not set, returns 0.|
|set\_joint\_identifier\(\)|void|uint32|Sets the value of joint\_identifier. After calling this, joint\_identifier\(\) will return value.|
|clear\_joint\_identifier\(\)|void|void|Clears the value of joint\_identifier. After calling this, joint\_identifier\(\) will return 0.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

