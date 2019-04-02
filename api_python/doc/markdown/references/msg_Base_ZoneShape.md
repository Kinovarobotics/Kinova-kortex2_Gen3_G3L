# Message ZoneShape

This page describes the Python Kinova.Api.Base.ZoneShape message.

## Overview / Purpose

Provides a protection zone shape description

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|shape\_type| [ShapeType](enm_Base_ShapeType.md#)|Shape type|
|origin| [Point](msg_Base_Point.md#)|Origin of the protection zone shape from reference \(in meters\)|
|orientation| [RotationMatrix](msg_Base_RotationMatrix.md#)|Rotation matrix to provide shape orientation|
|dimensions|Collection of float|Shape size measurement \(in meters\). If rectangular prism: x, y and z dimensions. If cylinder: radius and height. If sphere: radius|
|envelope\_thickness|float|Thickness of envelop around shape \(in meters\). The envelop is of same shape type as the shape at its center.|

**Parent topic:** [Base](../references/summary_Base.md)

