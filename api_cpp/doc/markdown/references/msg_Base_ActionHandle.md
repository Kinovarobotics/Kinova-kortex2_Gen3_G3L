# Message ActionHandle

This page describes the C++ Kinova::Api::Base::ActionHandle message.

## Overview / Purpose

Identifies an action

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|Action identifier|
|action\_type| [ActionType](enm_Base_ActionType.md#)|Action type|
|permission|uint32|Permission of specified Action entity. Must use 'Kinova.Api.Common.Permission' enum.|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|identifier\(\)|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return 0.|
|action\_type\(\) const| [ActionType](enm_Base_ActionType.md#)|void|Returns the current value of action\_type. If the action\_type is not set, returns 0.|
|set\_action\_type\(\)|void| [ActionType](enm_Base_ActionType.md#)|Sets the value of action\_type. After calling this, action\_type\(\) will return value.|
|clear\_action\_type\(\)|void|void|Clears the value of action\_type. After calling this, action\_type\(\) will return the empty string/empty bytes.|
|permission\(\)|uint32|void|Returns the current value of permission. If the permission is not set, returns 0.|
|set\_permission\(\)|void|uint32|Sets the value of permission. After calling this, permission\(\) will return value.|
|clear\_permission\(\)|void|void|Clears the value of permission. After calling this, permission\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

