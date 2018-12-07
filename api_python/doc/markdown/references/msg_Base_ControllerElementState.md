# Message ControllerElementState

This page describes the Python Kinova.Api.Base.ControllerElementState message.

## Overview / Purpose

Indicates if a specific button \(or axis\) was pressed \(or moved\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [ControllerElementHandle](msg_Base_ControllerElementHandle.md#)|Controller element handle|
|event\_type|int|Type of controller element event that occured|
|axis\_value|float|Axis value \(set between -1.0 and 1.0\); only set if 'axis' controller element, otherwise set to zero|

**Parent topic:** [Base](../references/summary_Base.md)

