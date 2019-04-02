# Message MapEvent

This page describes the Python Kinova.Api.Base.MapEvent message.

## Overview / Purpose

Defines a map event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|oneof events : safety\_event| [SafetyEvent](msg_Base_SafetyEvent.md#)|Mapped safety event \(future\)|
|oneof events : gpio\_event| [GpioEvent](msg_Base_GpioEvent.md#)|Mapped GPIO event \(future\)|
|oneof events : controller\_event| [ControllerEvent](msg_Base_ControllerEvent.md#)|Mapped controller event|
|name|str|Map event friendly name|

**Parent topic:** [Base](../references/summary_Base.md)

