# Message Delay

This page describes the C++ Kinova::Api::Base::Delay message.

## Overview / Purpose

Defines an action to apply a delay

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|duration|uint32|Delay \(in seconds\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

