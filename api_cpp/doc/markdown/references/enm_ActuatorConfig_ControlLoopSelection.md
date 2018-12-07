# Enum ControlLoopSelection

This page describes the C++ Kinova::Api::ActuatorConfig::ControlLoopSelection enumeration.

## Overview / Purpose

List of admissible control loop selections

## Enumeration definition

|Enumerator|Value|Description|
|----------|-----|-----------|
|RESERVED|0|0x0 - Reserved \(internal use only\)|
|JOINT\_POSITION|1|0x1 - Joint position control \(if available\)|
|MOTOR\_POSITION|2|0x2 - Motor position control|
|JOINT\_VELOCITY|4|0x4 - Joint velocity control \(if available\)|
|MOTOR\_VELOCITY|8|0x8 - Motor velocity control|
|JOINT\_TORQUE|16|0x10 - Joint torque control|
|MOTOR\_CURRENT|32|0x20 - Motor current control|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

