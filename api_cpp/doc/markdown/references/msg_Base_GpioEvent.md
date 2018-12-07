# Message GpioEvent

This page describes the C++ Kinova::Api::Base::GpioEvent message.

## Overview / Purpose

Identifies a GPIO event \(future\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|gpio\_state|uint32|New GPIO state|
|device\_identifier|uint32|GPIO device identifier for which this event occured|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|gpio\_state\(\) const|uint32|void|Returns the current value of gpio\_state. If the gpio\_state is not set, returns 0.|
|set\_gpio\_state\(\)|void|uint32|Sets the value of gpio\_state. After calling this, gpio\_state\(\) will return value.|
|clear\_gpio\_state\(\)|void|void|Clears the value of gpio\_state. After calling this, gpio\_state\(\) will return the empty string/empty bytes.|
|device\_identifier\(\)|uint32|void|Returns the current value of device\_identifier. If the device\_identifier is not set, returns 0.|
|set\_device\_identifier\(\)|void|uint32|Sets the value of device\_identifier. After calling this, device\_identifier\(\) will return value.|
|clear\_device\_identifier\(\)|void|void|Clears the value of device\_identifier. After calling this, device\_identifier\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

