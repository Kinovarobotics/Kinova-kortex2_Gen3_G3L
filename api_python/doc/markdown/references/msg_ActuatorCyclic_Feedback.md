# Message Feedback

This page describes the Python Kinova.Api.ActuatorCyclic.Feedback message.

## Overview / Purpose

Defines the feedback provided by an actuator module

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|feedback\_id| [MessageId](msg_ActuatorCyclic_MessageId.md#)|MessageId|
|status\_flags|int|Status flags \(see enum SatatusFlags for the rest\)|
|jitter\_comm|int|Jitter from the communication in μs|
|position|float|Position of the actuator \(degrees\)|
|velocity|float|Angular velocity of the actuator \(degrees per second\)|
|torque|float|Torque of the actuator \(Newton meter\)|
|current\_motor|float|Current of the motor \(Amperes\)|
|voltage|float|Voltage of the main board in \(Volt\)|
|temperature\_motor|float|Motor temperature \(average of the three \(3\) temperatures \(degrees Celsius\)\)|
|temperature\_core|float|Microcontroller temperature in \(degrees Celsius\)|
|fault\_bank\_a|int|Bank A Fault \(see ActuatorConfig.SafetyIdentifier\)|
|fault\_bank\_b|int|Bank B Fault \(see ActuatorConfig.SafetyIdentifier\)|
|warning\_bank\_a|int|Bank A Warning \(see ActuatorConfig.SafetyIdentifier\)|
|warning\_bank\_b|int|Bank B Warning \(see ActuatorConfig.SafetyIdentifier\)|

**Parent topic:** [ActuatorCyclic](../references/summary_ActuatorCyclic.md)

