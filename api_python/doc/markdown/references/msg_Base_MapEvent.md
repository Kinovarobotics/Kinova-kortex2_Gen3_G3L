# Message MapEvent

This page describes the Python Kinova.Api.Base.MapEvent message.

## Overview / Purpose

Defines a map event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|safety\_event|oneof:events [SafetyEvent](msg_Base_SafetyEvent.md#)|Mapped safety event \(future\)|
|gpio\_event|oneof:events [GpioEvent](msg_Base_GpioEvent.md#)|Mapped GPIO event \(future\)|
|controller\_event|oneof:events [ControllerEvent](msg_Base_ControllerEvent.md#)|Mapped controller event|
|name|str|Map event friendly name|

**Parent topic:** [Base](../references/summary_Base.md)

