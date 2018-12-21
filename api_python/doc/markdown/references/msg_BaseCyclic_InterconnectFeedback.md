# Message InterconnectFeedback

This page describes the Python Kinova.Api.BaseCyclic.InterconnectFeedback message.

## Overview / Purpose

Defines the feedback provided by an interconnect module

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id|int|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|
|status\_flags|int|Status flags|
|jitter\_comm|int|Jitter from the communication \(in microseconds\)|
|position|float|Position of the gripper fingers \(0-100%\)|
|velocity|float|Velocity of the gripper fingers \(0-100%\)|
|force|float|Force of the gripper fingers \(0-100%\)|
|imu\_acceleration\_x|float|IMU Measured acceleration \(X-Axis\) of the interconnect \(in meters per second ^ squared\)|
|imu\_acceleration\_y|float|IMU Measured acceleration \(Y-Axis\) of the interconnect \(in meters per second ^ squared\)|
|imu\_acceleration\_z|float|IMU Measured acceleration \(Z-Axis\) of the interconnect \(in meters per second ^ squared\)|
|imu\_angular\_velocity\_x|float|IMU Measured angular velocity \(X-Axis\) of the interconnect \(in degrees per second\)|
|imu\_angular\_velocity\_y|float|IMU Measured angular velocity \(Y-Axis\) of the interconnect \(in degrees per second\)|
|imu\_angular\_velocity\_z|float|IMU Measured angular velocity \(Z-Axis\) of the interconnect \(in degrees per second\)|
|voltage|float|Voltage of the main board \(in Volt\)|
|temperature\_core|float|Microcontroller temperature \(in degrees Celsius\)|
|fault\_bank\_a|int|Fault bank A|
|fault\_bank\_b|int|Fault bank B|
|warning\_bank\_a|int|Warning bank A|
|warning\_bank\_b|int|Warning bank B|

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

