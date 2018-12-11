# Message GripperRequest

This page describes the C++ Kinova::Api::Base::GripperRequest message.

## Overview / Purpose

Message used to request the current gripper movement in either position, force or speed

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode| [GripperMode](enm_Base_GripperMode.md#)|Mode for which the gripper movement status is requested|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|mode\(\) const| [GripperMode](enm_Base_GripperMode.md#)|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void| [GripperMode](enm_Base_GripperMode.md#)|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

