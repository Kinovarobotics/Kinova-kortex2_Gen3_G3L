# Message Finger

This page describes the C++ Kinova::Api::Base::Finger message.

## Overview / Purpose

Defines a finger movement

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|finger\_identifier|uint32|Finger identifier|
|value|float32|In position, admissible values for each finger is between 0 and 1.0, where 0 is closed and 1.0 is fully open. In speed or torque, admissible values for each finger is between -1.0 and 1.0, where 1.0 corresponds to maximum opening speed and -1.0 corresponds to maximum closing speed.|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|finger\_identifier\(\)|uint32|void|Returns the current value of finger\_identifier. If the finger\_identifier is not set, returns 0.|
|set\_finger\_identifier\(\)|void|uint32|Sets the value of finger\_identifier. After calling this, finger\_identifier\(\) will return value.|
|clear\_finger\_identifier\(\)|void|void|Clears the value of finger\_identifier. After calling this, finger\_identifier\(\) will return 0.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

