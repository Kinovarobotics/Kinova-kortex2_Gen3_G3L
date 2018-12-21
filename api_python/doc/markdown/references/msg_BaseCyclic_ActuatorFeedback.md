# Message ActuatorFeedback

This page describes the Python Kinova.Api.BaseCyclic.ActuatorFeedback message.

## Overview / Purpose

Defines the feedback provided by an actuator module

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id|int|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|
|status\_flags|int|Status flags|
|jitter\_comm|int|Jitter from the communication \(in microseconds\)|
|position|float|Position of the actuator \(in degrees\)|
|velocity|float|Velocity of the actuator \(in degrees per second\)|
|torque|float|Torque of the actuator \(in Newton \* meters\)|
|current\_motor|float|Current of the motor \(in Amperes\)|
|voltage|float|Voltage of the main board \(in Volts\)|
|temperature\_motor|float|Motor temperature \(maximum of the three \(3\) phase temperatures in °C\)|
|temperature\_core|float|Microcontroller temperature \(in degrees Celsius\)|
|fault\_bank\_a|int|Fault bank A|
|fault\_bank\_b|int|Fault bank B|
|warning\_bank\_a|int|Warning bank A|
|warning\_bank\_b|int|Warning bank B|

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

