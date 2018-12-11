# Message ServoingModeInformation

This page describes the C++ Kinova::Api::Base::ServoingModeInformation message.

## Overview / Purpose

Provides information about the servoing mode

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|servoing\_mode| [ServoingMode](enm_Base_ServoingMode.md#)|Servoing mode|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|servoing\_mode\(\) const| [ServoingMode](enm_Base_ServoingMode.md#)|void|Returns the current value of servoing\_mode. If the servoing\_mode is not set, returns 0.|
|set\_servoing\_mode\(\)|void| [ServoingMode](enm_Base_ServoingMode.md#)|Sets the value of servoing\_mode. After calling this, servoing\_mode\(\) will return value.|
|clear\_servoing\_mode\(\)|void|void|Clears the value of servoing\_mode. After calling this, servoing\_mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

