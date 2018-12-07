# Message Feedback

This page describes the Python Kinova.Api.ActuatorCyclic.Feedback message.

## Overview / Purpose

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|feedback\_id| [MessageId](msg_ActuatorCyclic_MessageId.md#)|MessageId|
|status\_flags|int|Status flags|
|jitter\_comm|int|Jitter from the communication in μs|
|position|float|Position of the actuator in °|
|velocity|float|Angular velocity of the actuator in °/s|
|torque|float|Torque of the actuator in N·m|
|current\_motor|float|Current of the motor in A|
|voltage|float|Voltage of the main board in V|
|temperature\_motor|float|Motor temperature \(maximum of the three \(3\) phase temperatures in °C\)|
|temperature\_core|float|Microcontroller temperature in °C|
|fault\_bank\_a|int|Bank A Fault \(see ActuatorConfig.SafetyIdentifier\)|
|fault\_bank\_b|int|Bank B Fault \(see ActuatorConfig.SafetyIdentifier\)|
|warning\_bank\_a|int|Bank A Warning \(see ActuatorConfig.SafetyIdentifier\)|
|warning\_bank\_b|int|Bank B Warning \(see ActuatorConfig.SafetyIdentifier\)|

**Parent topic:** [ActuatorCyclic](../references/summary_ActuatorCyclic.md)

