# Message Mapping

This page describes the Python Kinova.Api.Base.Mapping message.

## Overview / Purpose

Message that contains all information about a mapping including the controller to which it is associated, the array of map groups it contains, the currently active map group, the array of maps it contains and the currently active map

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [MappingHandle](msg_Base_MappingHandle.md#)|Mapping handle \(do not set on createMapping\(\) call\)|
|name|str|Mapping friendly name|
|controller\_identifier|int|Associated controller identifier|
|active\_map\_group\_handle| [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Currently active map group \(future\)|
|map\_group\_handles|Collection of [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Array of associated map groups \(future\)|
|active\_map\_handle| [MapHandle](msg_Base_MapHandle.md#)|Currently active map|
|map\_handles|Collection of [MapHandle](msg_Base_MapHandle.md#)|Array of associated maps|
|application\_data|str|Application data \(reserved for use by Web App\)|

**Parent topic:** [Base](../references/summary_Base.md)

