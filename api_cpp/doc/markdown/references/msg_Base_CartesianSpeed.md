# Message CartesianSpeed

This page describes the C++ Kinova::Api::Base::CartesianSpeed message.

## Overview / Purpose

Defines a Cartesian speed

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|translation|float32|Translation speed \(in meters per second\)|
|orientation|float32|Orientation speed \(in degrees per second\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|translation\(\)|float32|void|Returns the current value of translation. If the translation is not set, returns 0.|
|set\_translation\(\)|void|float32|Sets the value of translation. After calling this, translation\(\) will return value.|
|clear\_translation\(\)|void|void|Clears the value of translation. After calling this, translation\(\) will return 0.|
|orientation\(\)|float32|void|Returns the current value of orientation. If the orientation is not set, returns 0.|
|set\_orientation\(\)|void|float32|Sets the value of orientation. After calling this, orientation\(\) will return value.|
|clear\_orientation\(\)|void|void|Clears the value of orientation. After calling this, orientation\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

