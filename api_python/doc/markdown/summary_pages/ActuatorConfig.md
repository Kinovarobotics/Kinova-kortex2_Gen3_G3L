# ActuatorConfig \(Python\)

This page describes the Python ActuatorConfig API.

## RPC reference

This section describes the existing RPCs used in this API.

Service to configure actuators

 **ActuatorConfigClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|GetAxisOffsets|[AxisOffsets](../messages/ActuatorConfig/AxisOffsets.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves axis offsets for absolute and relative encoder|
|SetAxisOffsets|[Empty](../messages/Common/Empty.md#)|[AxisPosition](../messages/ActuatorConfig/AxisPosition.md#)|Sets offsets for absolute and relative encoder Invoking this method shall invalidate arm calibration if one exists. This method is for kinova usage only.|
|ReadTorqueCalibration|[TorqueCalibration](../messages/ActuatorConfig/TorqueCalibration.md#)|[Empty](../messages/Common/Empty.md#)|Reads torque calibration parameters \(internal use only\)|
|WriteTorqueCalibration|[Empty](../messages/Common/Empty.md#)|[TorqueCalibration](../messages/ActuatorConfig/TorqueCalibration.md#)|Writes torque calibration parameters \(internal use only\)|
|SetTorqueOffset|[Empty](../messages/Common/Empty.md#)|[TorqueOffset](../messages/ActuatorConfig/TorqueOffset.md#)|Sets zero torque calibration|
|GetControlMode|[ControlModeInformation](../messages/ActuatorConfig/ControlModeInformation.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves actuator control mode|
|SetControlMode|[Empty](../messages/Common/Empty.md#)|[ControlModeInformation](../messages/ActuatorConfig/ControlModeInformation.md#)|Sets actuator control mode|
|GetActivatedControlLoop|[ControlLoop](../messages/ActuatorConfig/ControlLoop.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves activated control loop\(s\)|
|SetActivatedControlLoop|[Empty](../messages/Common/Empty.md#)|[ControlLoop](../messages/ActuatorConfig/ControlLoop.md#)|Sets activated control loop\(s\)|
|GetVectorDriveParameters|[VectorDriveParameters](../messages/ActuatorConfig/VectorDriveParameters.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves motor drive FOC parameters \(internal use only\)|
|SetVectorDriveParameters|[Empty](../messages/Common/Empty.md#)|[VectorDriveParameters](../messages/ActuatorConfig/VectorDriveParameters.md#)|Sets motor drive FOC parameters \(internal use only\)|
|GetEncoderDerivativeParameters|[EncoderDerivativeParameters](../messages/ActuatorConfig/EncoderDerivativeParameters.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves encoder derivative parameters \(internal use only\)|
|SetEncoderDerivativeParameters|[Empty](../messages/Common/Empty.md#)|[EncoderDerivativeParameters](../messages/ActuatorConfig/EncoderDerivativeParameters.md#)|Sets encoder derivative parameters \(internal use only\)|
|GetControlLoopParameters|[ControlLoopParameters](../messages/ActuatorConfig/ControlLoopParameters.md#)|[LoopSelection](../messages/ActuatorConfig/LoopSelection.md#)|Retrieves control loop parameters|
|SetControlLoopParameters|[Empty](../messages/Common/Empty.md#)|[ControlLoopParameters](../messages/ActuatorConfig/ControlLoopParameters.md#)|Sets control loop parameters|
|StartFrequencyResponse|[Empty](../messages/Common/Empty.md#)|[FrequencyResponse](../messages/ActuatorConfig/FrequencyResponse.md#)|Starts frequency response test \(internal use only\)|
|StopFrequencyResponse|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Stops frequency response test \(internal use only\)|
|StartStepResponse|[Empty](../messages/Common/Empty.md#)|[StepResponse](../messages/ActuatorConfig/StepResponse.md#)|Starts step response test \(internal use only\)|
|StopStepResponse|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Stops step response test \(internal use only\)|
|StartRampResponse|[Empty](../messages/Common/Empty.md#)|[RampResponse](../messages/ActuatorConfig/RampResponse.md#)|Starts ramp response test \(internal use only\)|
|StopRampResponse|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Stops ramp response test \(internal use only\)|
|SelectCustomData|[Empty](../messages/Common/Empty.md#)|[CustomDataSelection](../messages/ActuatorConfig/CustomDataSelection.md#)|Selects custom data|
|GetSelectedCustomData|[CustomDataSelection](../messages/ActuatorConfig/CustomDataSelection.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves selected custom data|
|SetCommandMode|[Empty](../messages/Common/Empty.md#)|[CommandModeInformation](../messages/ActuatorConfig/CommandModeInformation.md#)|Sets command mode \(config versus cyclic\)|
|ClearFaults|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Clears all error\(s\) and warning\(s\) \(bank A and B\)|
|SetServoing|[Empty](../messages/Common/Empty.md#)|[Servoing](../messages/ActuatorConfig/Servoing.md#)|Enables or disables servoing|
|MoveToPosition|[Empty](../messages/Common/Empty.md#)|[PositionCommand](../messages/ActuatorConfig/PositionCommand.md#)|Moves the actuator to the desired position|
|GetCommandMode|[CommandModeInformation](../messages/ActuatorConfig/CommandModeInformation.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves command mode \(config versus cyclic\)|
|GetServoing|[Servoing](../messages/ActuatorConfig/Servoing.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves servoing state|
|GetTorqueOffset|[TorqueOffset](../messages/ActuatorConfig/TorqueOffset.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves torque offset calibration|
|SetCoggingFeedforwardMode|[Empty](../messages/Common/Empty.md#)|[CoggingFeedforwardModeInformation](../messages/ActuatorConfig/CoggingFeedforwardModeInformation.md#)|Sets cogging feedforward mode|
|GetCoggingFeedforwardMode|[CoggingFeedforwardModeInformation](../messages/ActuatorConfig/CoggingFeedforwardModeInformation.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves cogging feedforward mode|

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[AxisOffsets](../messages/ActuatorConfig/AxisOffsets.md#)|Axis offsets|
|[AxisPosition](../messages/ActuatorConfig/AxisPosition.md#)|Axis position|
|[CoggingFeedforwardModeInformation](../messages/ActuatorConfig/CoggingFeedforwardModeInformation.md#)|Cogging feedforward mode|
|[CommandModeInformation](../messages/ActuatorConfig/CommandModeInformation.md#)|Command mode|
|[ControlLoop](../messages/ActuatorConfig/ControlLoop.md#)|Control loop|
|[ControlLoopParameters](../messages/ActuatorConfig/ControlLoopParameters.md#)|Control loop parameters \(discrete transfer function\)|
|[ControlModeInformation](../messages/ActuatorConfig/ControlModeInformation.md#)|Control mode information|
|[CustomDataSelection](../messages/ActuatorConfig/CustomDataSelection.md#)|Selected custom data channels content|
|[EncoderDerivativeParameters](../messages/ActuatorConfig/EncoderDerivativeParameters.md#)|Variable window derivative parameters|
|[FrequencyResponse](../messages/ActuatorConfig/FrequencyResponse.md#)|Frequency response|
|[LoopSelection](../messages/ActuatorConfig/LoopSelection.md#)|Defines the loop selection|
|[PositionCommand](../messages/ActuatorConfig/PositionCommand.md#)|Angular position command for an actuator|
|[RampResponse](../messages/ActuatorConfig/RampResponse.md#)|Ramp response|
|[Servoing](../messages/ActuatorConfig/Servoing.md#)|Enables/disables servoing|
|[StepResponse](../messages/ActuatorConfig/StepResponse.md#)|Step response|
|[TorqueCalibration](../messages/ActuatorConfig/TorqueCalibration.md#)|Torque calibration settings|
|[TorqueOffset](../messages/ActuatorConfig/TorqueOffset.md#)|Defines torque offset|
|[VectorDriveParameters](../messages/ActuatorConfig/VectorDriveParameters.md#)|Field-oriented control PI controller gain values|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[CoggingFeedforwardMode](../enums/ActuatorConfig/CoggingFeedforwardMode.md#)|Admissable cogging feedforward modes|
|[CommandMode](../enums/ActuatorConfig/CommandMode.md#)|Admissible command modes|
|[ControlLoopSelection](../enums/ActuatorConfig/ControlLoopSelection.md#)|Admissible control loop selections|
|[ControlMode](../enums/ActuatorConfig/ControlMode.md#)|Admissible control modes|
|[CustomDataIndex](../enums/ActuatorConfig/CustomDataIndex.md#)|Custom data options|
|[SafetyIdentifierBankA](../enums/ActuatorConfig/SafetyIdentifierBankA.md#)|Admissible bank A actuator safeties|
|[SafetyLimitType](../enums/ActuatorConfig/SafetyLimitType.md#)|Admissible limit types|
|[ServiceVersion](../enums/ActuatorConfig/ServiceVersion.md#)|Identifies ActuatorConfig service current version|

