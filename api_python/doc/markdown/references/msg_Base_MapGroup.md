# Message MapGroup

This page describes the Python Kinova.Api.Base.MapGroup message.

## Overview / Purpose

Message that contains all information about a map group including the list of maps that it contains and its relationship versus other map groups \(future\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|group\_handle| [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Map group handle \(do not set on createMapGroup\(\) call\)|
|name|str|Map group friendly name|
|related\_mapping\_handle| [MappingHandle](msg_Base_MappingHandle.md#)|Mapping that this map group belongs to|
|parent\_group\_handle| [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Parent map group \(if any\)|
|children\_map\_group\_handles|Collection of [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Children map groups \(if any\)|
|map\_handles|Collection of [MapHandle](msg_Base_MapHandle.md#)|Array of maps that are included in this map group|
|application\_data|str|Application data \(reserved for use by Web App\)|

**Parent topic:** [Base](../references/summary_Base.md)

