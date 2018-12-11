# Message RequestedActionType

This page describes the C++ Kinova::Api::Base::RequestedActionType message.

## Overview / Purpose

Message used to request all action instances of a specific action type

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|action\_type| [ActionType](enm_Base_ActionType.md#)|Action type|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|action\_type\(\) const| [ActionType](enm_Base_ActionType.md#)|void|Returns the current value of action\_type. If the action\_type is not set, returns 0.|
|set\_action\_type\(\)|void| [ActionType](enm_Base_ActionType.md#)|Sets the value of action\_type. After calling this, action\_type\(\) will return value.|
|clear\_action\_type\(\)|void|void|Clears the value of action\_type. After calling this, action\_type\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

