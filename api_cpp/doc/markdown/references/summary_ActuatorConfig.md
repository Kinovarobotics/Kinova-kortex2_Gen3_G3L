# ActuatorConfig

This page describes the C++ Kinova::Api::ActuatorConfig package.

## Overview / Purpose

Service to configure the actuator module.

## API reference

This section describes procedure calls / methods exposed by the ActuatorConfig package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

Every method listed below, except the notification subscription methods \(begining with 'OnNotification'\) are available in three different forms :

-   **blocking** : called using listed method name \(default\)
-   **future/promise** : called using listed method name followed by the '**\_async**' suffix
-   **regiser callback** : called using listed method name followed by the '**\_callback**' suffix

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|ClearFaults|void|void|Clears all error\(s\) and warning\(s\) \(bank A and B\)|
|GetActivatedControlLoop|[ControlLoop](msg_ActuatorConfig_ControlLoop.md#)|void|Gets activated control loop\(s\)|
|GetAxisOffsets|[AxisOffsets](msg_ActuatorConfig_AxisOffsets.md#)|void|Gets axis offsets for absolute and relative encoder|
|GetCommandMode|[CommandModeInformation](msg_ActuatorConfig_CommandModeInformation.md#)|void|Gets command mode \(config versus cyclic\)|
|GetControlLoopParameters|[ControlLoopParameters](msg_ActuatorConfig_ControlLoopParameters.md#)|[LoopSelection](msg_ActuatorConfig_LoopSelection.md#)|Gets control loop parameters|
|GetControlMode|[ControlModeInformation](msg_ActuatorConfig_ControlModeInformation.md#)|void|Gets actuator control mode|
|GetEncoderDerivativeParameters|[EncoderDerivativeParameters](msg_ActuatorConfig_EncoderDerivativeParameters.md#)|void|Gets encoder derivative parameters \(internal use only\)|
|GetSelectedCustomData|[CustomDataSelection](msg_ActuatorConfig_CustomDataSelection.md#)|void|Gets selected custom data|
|GetServoing|[Servoing](msg_ActuatorConfig_Servoing.md#)|void|Gets servoing state|
|GetTorqueOffset|[TorqueOffset](msg_ActuatorConfig_TorqueOffset.md#)|void|Gets torque offset calibration|
|GetVectorDriveParameters|[VectorDriveParameters](msg_ActuatorConfig_VectorDriveParameters.md#)|void|Gets motor drive FOC parameters \(internal use only\)|
|MoveToPosition|void|[PositionCommand](msg_ActuatorConfig_PositionCommand.md#)|Moves the actuator to the desired position|
|ReadTorqueCalibration|[TorqueCalibration](msg_ActuatorConfig_TorqueCalibration.md#)|void|Reads torque calibration parameters \(internal use only\)|
|SelectCustomData|void|[CustomDataSelection](msg_ActuatorConfig_CustomDataSelection.md#)|Selects custom data|
|SetActivatedControlLoop|void|[ControlLoop](msg_ActuatorConfig_ControlLoop.md#)|Sets activated control loop\(s\)|
|SetAxisOffsets|void|[AxisPosition](msg_ActuatorConfig_AxisPosition.md#)|Computes offsets for absolute and relative encoder|
|SetCommandMode|void|[CommandModeInformation](msg_ActuatorConfig_CommandModeInformation.md#)|Sets command mode \(config versus cyclic\)|
|SetControlLoopParameters|void|[ControlLoopParameters](msg_ActuatorConfig_ControlLoopParameters.md#)|Sets control loop parameters.|
|SetControlMode|void|[ControlModeInformation](msg_ActuatorConfig_ControlModeInformation.md#)|Sets actuator control mode|
|SetEncoderDerivativeParameters|void|[EncoderDerivativeParameters](msg_ActuatorConfig_EncoderDerivativeParameters.md#)|Sets encoder derivative parameters \(internal use only\)|
|SetServoing|void|[Servoing](msg_ActuatorConfig_Servoing.md#)|Enables or disables servoing|
|SetTorqueOffset|void|[TorqueOffset](msg_ActuatorConfig_TorqueOffset.md#)|Sets zero torque calibration|
|SetVectorDriveParameters|void|[VectorDriveParameters](msg_ActuatorConfig_VectorDriveParameters.md#)|Sets motor drive FOC parameters \(internal use only\)|
|StartFrequencyResponse|void|[FrequencyResponse](msg_ActuatorConfig_FrequencyResponse.md#)|Starts frequency response test \(internal use only\)|
|StartRampResponse|void|[RampResponse](msg_ActuatorConfig_RampResponse.md#)|Starts ramp response test \(internal use only\)|
|StartStepResponse|void|[StepResponse](msg_ActuatorConfig_StepResponse.md#)|Starts step response test \(internal use only\)|
|StopFrequencyResponse|void|void|Stops frequency response test \(internal use only\)|
|StopRampResponse|void|void|Stops ramp response test \(internal use only\)|
|StopStepResponse|void|void|Stops step response test \(internal use only\)|
|WriteTorqueCalibration|void|[TorqueCalibration](msg_ActuatorConfig_TorqueCalibration.md#)|Writes torque calibration parameters \(internal use only\)|

## Data types reference

This section describes the data types used in the ActuatorConfig package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[AxisOffsets](msg_ActuatorConfig_AxisOffsets.md#)|Defines axis offsets|
|[AxisPosition](msg_ActuatorConfig_AxisPosition.md#)|Defines an axis position|
|[CommandModeInformation](msg_ActuatorConfig_CommandModeInformation.md#)|Selects command mode|
|[ControlLoop](msg_ActuatorConfig_ControlLoop.md#)|Defines the control loop|
|[ControlLoopParameters](msg_ActuatorConfig_ControlLoopParameters.md#)|Defines control loop parameters \(discrete transfer function\)|
|[ControlModeInformation](msg_ActuatorConfig_ControlModeInformation.md#)|Defines the control mode|
|[CustomDataSelection](msg_ActuatorConfig_CustomDataSelection.md#)|Selects custom data channels content|
|[EncoderDerivativeParameters](msg_ActuatorConfig_EncoderDerivativeParameters.md#)|Defines variable window derivative parameters|
|[FrequencyResponse](msg_ActuatorConfig_FrequencyResponse.md#)|Defines frequency response|
|[LoopSelection](msg_ActuatorConfig_LoopSelection.md#)|Defines the loop selection|
|[PositionCommand](msg_ActuatorConfig_PositionCommand.md#)|Defines a position command|
|[RampResponse](msg_ActuatorConfig_RampResponse.md#)|Defines ramp response|
|[Servoing](msg_ActuatorConfig_Servoing.md#)|Enables/disables servoing|
|[StepResponse](msg_ActuatorConfig_StepResponse.md#)|Defines step response|
|[TorqueCalibration](msg_ActuatorConfig_TorqueCalibration.md#)|Defines torque calibration|
|[TorqueOffset](msg_ActuatorConfig_TorqueOffset.md#)|Defines torque offset|
|[VectorDriveParameters](msg_ActuatorConfig_VectorDriveParameters.md#)|Field-oriented control PI controller gain values|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[CommandMode](enm_ActuatorConfig_CommandMode.md#)|List of admissible command modes|
|[ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|List of admissible control loop selections|
|[ControlMode](enm_ActuatorConfig_ControlMode.md#)|List of admissible control modes|
|[CustomDataIndex](enm_ActuatorConfig_CustomDataIndex.md#)| |
|[SafetyIdentifier](enm_ActuatorConfig_SafetyIdentifier.md#)|List of admissible actuator safeties|
|[SafetyLimitType](enm_ActuatorConfig_SafetyLimitType.md#)|List of of admissible limit types|
|[ServiceVersion](enm_ActuatorConfig_ServiceVersion.md#)|Enumeration used to identify ActuatorConfig service current version|

**Parent topic:** [KINOVA® KORTEX™ C++ API Reference](../index.md#)

