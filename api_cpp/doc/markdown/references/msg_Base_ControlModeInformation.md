# Message ControlModeInformation

This page describes the C++ Kinova::Api::Base::ControlModeInformation message.

## Overview / Purpose

Provides control mode information

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode| [ControlMode](enm_Base_ControlMode.md#)|Control mode|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|mode\(\) const| [ControlMode](enm_Base_ControlMode.md#)|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void| [ControlMode](enm_Base_ControlMode.md#)|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

