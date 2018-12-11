# Message ControlLoopParameters

This page describes the Python Kinova.Api.ActuatorConfig.ControlLoopParameters message.

## Overview / Purpose

Defines control loop parameters \(discrete transfer function\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|loop\_selection| [ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|ControlLoopSelection enum|
|error\_saturation|float|Error saturation value|
|output\_saturation|float|Output saturation value|
|kAz|float|KAz \(index 0 to 4\): denominator gains A1 to A5|
|kBz|float|KBz \(index 0 to 5\): numerator gains B0 to B5|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

