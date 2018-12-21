# Message Command

This page describes the Python Kinova.Api.ActuatorCyclic.Command message.

## Overview / Purpose

Defines an actuator module command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id| [MessageId](msg_ActuatorCyclic_MessageId.md#)|MessageId|
|flags|int|Command flags \(see enum CommandFlags\)|
|position|float|Desired position of the actuator \(degrees\)|
|velocity|float|Desired velocity of the actuator \(degrees per second\)|
|torque\_joint|float|Desired torque of the actuator \(Newton-meters\)|
|current\_motor|float|Desired current of the motor \(Amperes\)|

**Parent topic:** [ActuatorCyclic](../references/summary_ActuatorCyclic.md)

