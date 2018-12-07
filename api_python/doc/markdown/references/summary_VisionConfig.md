# VisionConfig

This page describes the Python Kinova.Api.VisionConfig package.

## Overview / Purpose

Service to configure the Vision Module

## API reference

This section describes procedure calls / methods exposed by the VisionConfig package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|DoSensorFocusAction|None|[SensorFocusAction](msg_VisionConfig_SensorFocusAction.md#)|Do a focus action|
|GetIntrinsicParameters|[IntrinsicParameters](msg_VisionConfig_IntrinsicParameters.md#)|[SensorIdentifier](msg_VisionConfig_SensorIdentifier.md#)|Gets sensor intrinsic parameters|
|GetOptionInformation|[OptionInformation](msg_VisionConfig_OptionInformation.md#)|[OptionIdentifier](msg_VisionConfig_OptionIdentifier.md#)|Reads option information from the sensor|
|GetOptionValue|[OptionValue](msg_VisionConfig_OptionValue.md#)|[OptionIdentifier](msg_VisionConfig_OptionIdentifier.md#)|Reads option value from the sensor|
|GetSensorSettings|[SensorSettings](msg_VisionConfig_SensorSettings.md#)|[SensorIdentifier](msg_VisionConfig_SensorIdentifier.md#)|Gets sensor settings \(resolution, frame rate, etc\)|
|OnNotificationVisionTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to Vision configuration notifications|
|SetOptionValue|None|[OptionValue](msg_VisionConfig_OptionValue.md#)|Writes new value to sensor option|
|SetSensorSettings|None|[SensorSettings](msg_VisionConfig_SensorSettings.md#)|Sets sensor settings \(resolution, frame rate, etc\)|

## Data types reference

This section describes the data types used in the VisionConfig package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[IntrinsicParameters](msg_VisionConfig_IntrinsicParameters.md#)|Sensor intrinsic parameters|
|[OptionIdentifier](msg_VisionConfig_OptionIdentifier.md#)|Identifies the sensor and the option to configure.|
|[OptionInformation](msg_VisionConfig_OptionInformation.md#)|Packages information about the optional settings for the chosen sensor|
|[OptionValue](msg_VisionConfig_OptionValue.md#)|Identifies the value of the particular option for the sensor.|
|[SensorFocusAction](msg_VisionConfig_SensorFocusAction.md#)|Identifies the sensor and the focus action to perform.|
|[SensorIdentifier](msg_VisionConfig_SensorIdentifier.md#)|Identifies the sensor to configure.|
|[SensorSettings](msg_VisionConfig_SensorSettings.md#)|Main settings - resolution, frame rate, bit rate - for the chosen sensor \(color or depth\).|
|[VisionNotification](msg_VisionConfig_VisionNotification.md#)|Message that contains Vision module event|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[BitRate](enm_VisionConfig_BitRate.md#)|Select the maximum encoded bit rate, in Mbps.|
|[FocusAction](enm_VisionConfig_FocusAction.md#)|Select the focus action to perform \(start/pause continuous, focus now, disable\). Supported only with Color sensor.|
|[FrameRate](enm_VisionConfig_FrameRate.md#)|Select the camera frame rate.|
|[Option](enm_VisionConfig_Option.md#)|List of admissible Vision module options. !!!!!|
|[Resolution](enm_VisionConfig_Resolution.md#)|Select the camera resolution.|
|[Sensor](enm_VisionConfig_Sensor.md#)|Select the Vision module camera sensor to configure.|
|[ServiceVersion](enm_VisionConfig_ServiceVersion.md#)|Enumeration used to identify VisionConfig current version|
|[VisionEvent](enm_VisionConfig_VisionEvent.md#)|List of admissible Vision module events.|

**Parent topic:** [KINOVA® KORTEX™ Python API Reference](../index.md#)

