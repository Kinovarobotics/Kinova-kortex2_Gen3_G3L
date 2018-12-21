# Message BaseFeedback

This page describes the Python Kinova.Api.BaseCyclic.BaseFeedback message.

## Overview / Purpose

Defines the feedback provided by the base module

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|active\_state\_connection\_identifier|int|Connection identifier of the last processed command which triggered an arm state change|
|active\_state| [ArmState](enm_Common_ArmState.md#)|Active state of the arm|
|arm\_voltage|float|Arm voltage \(in Volts\)|
|arm\_current|float|Arm current \(in Amperes\)|
|temperature\_cpu|float|CPU temperature \(in degree Celcius\)|
|temperature\_ambient|float|Ambient temperature \(in degree Celcius\)|
|imu\_acceleration\_x|float|IMU Measured acceleration \(X-Axis\) of the base \(in meters per second squared\)|
|imu\_acceleration\_y|float|IMU Measured acceleration \(Y-Axis\) of the base \(in meters per second squared\)|
|imu\_acceleration\_z|float|IMU Measured acceleration \(Z-Axis\) of the base \(in meters per second squared\)|
|imu\_angular\_velocity\_x|float|IMU Measured angular velocity \(X-Axis\) of the base \(in degrees per second\)|
|imu\_angular\_velocity\_y|float|IMU Measured angular velocity \(Y-Axis\) of the base \(in degrees per second\)|
|imu\_angular\_velocity\_z|float|IMU Measured angular velocity \(Z-Axis\) of the base \(in degrees per second\)|
|tool\_pose\_x|float|Measured Cartesian position \(X-Axis\) of the End Effector \(EE\) \(in meters\)|
|tool\_pose\_y|float|Measured Cartesian position \(Y-Axis\) of the End Effector \(EE\) \(in meters\)|
|tool\_pose\_z|float|Measured Cartesian position \(Z-Axis\) of the End Effector \(EE\) \(in meters\)|
|tool\_pose\_theta\_x|float|Measured Cartesian orientation \(X-Axis\) of the End Effector \(EE\) \(in degrees\)|
|tool\_pose\_theta\_y|float|Measured Cartesian orientation \(Y-Axis\) of the End Effector \(EE\) \(in degrees\)|
|tool\_pose\_theta\_z|float|Measured Cartesian orientation \(Z-Axis\) of the End Effector \(EE\) \(in degrees\)|
|tool\_twist\_linear\_x|float|Measured Cartesian linear velocity \(X-Axis\) of the End Effector \(EE\) \(in meters\)|
|tool\_twist\_linear\_y|float|Measured Cartesian linear velocity \(Y-Axis\) of the End Effector \(EE\) \(in meters\)|
|tool\_twist\_linear\_z|float|Measured Cartesian linear velocity \(Z-Axis\) of the End Effector \(EE\) \(in meters\)|
|tool\_twist\_angular\_x|float|Measured Cartesian angular velocity \(X-Axis\) of the End Effector \(EE\) \(in degrees per second\)|
|tool\_twist\_angular\_y|float|Measured Cartesian angular velocity \(Y-Axis\) of the End Effector \(EE\) \(in degrees per second\)|
|tool\_twist\_angular\_z|float|Measured Cartesian angular velocity \(Z-Axis\) of the End Effector \(EE\) \(in degrees per second\)|
|tool\_external\_wrench\_force\_x|float|Calculated force in X-Axis from external wrench \(in Newton\)|
|tool\_external\_wrench\_force\_y|float|Calculated force in Y-Axis from external wrench \(in Newton\)|
|tool\_external\_wrench\_force\_z|float|Calculated force in Z-Axis from external wrench \(in Newton\)|
|tool\_external\_wrench\_torque\_x|float|Calculated torque about X-axis from external wrench \(in Newton \* meters\)|
|tool\_external\_wrench\_torque\_y|float|Calculated torque about Y-axis from external wrench \(in Newton \* meters\)|
|tool\_external\_wrench\_torque\_z|float|Calculated torque about Z-axis from external wrench \(in Newton \* meters\)|
|fault\_bank\_a|int|The arm fault flags bank A \(0 if no fault\) see Base.SafetyIdentifier|
|fault\_bank\_b|int|The arm fault flags bank B \(0 if no fault\) see Base.SafetyIdentifier|
|warning\_bank\_a|int|The arm warning flags bank A \(0 if no warning\) see Base.SafetyIdentifier|
|warning\_bank\_b|int|The arm warning flags bank B \(0 if no warning\) see Base.SafetyIdentifier|

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

