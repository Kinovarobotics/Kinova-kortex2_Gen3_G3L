# Message SwitchControlMapping

This page describes the Python Kinova.Api.Base.SwitchControlMapping message.

## Overview / Purpose

Defines an action to switch the active controller map

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|controller\_identifier|int|Identifier of the controller for which changing the active map is requested|
|map\_group\_handle| [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Identifier of the map group for which the active map needs to change|
|map\_handle| [MapHandle](msg_Base_MapHandle.md#)|New active map|

**Parent topic:** [Base](../references/summary_Base.md)

