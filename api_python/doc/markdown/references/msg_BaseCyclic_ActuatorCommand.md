# Message ActuatorCommand

This page describes the Python Kinova.Api.BaseCyclic.ActuatorCommand message.

## Overview / Purpose

Defines an actuator module command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id|int|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|
|flags|int|Flags|
|position|float|Desired position of the actuator \(in degrees\)|
|velocity|float|Desired velocity of the actuator \(in degrees per second\)|
|torque\_joint|float|Desired torque of the actuator \(in Newton \* meters\)|
|current\_motor|float|Desired current of the motor \(in Amperes\)|

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

