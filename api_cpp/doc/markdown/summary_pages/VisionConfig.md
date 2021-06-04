# VisionConfig \(C++\)

This page describes the C++ VisionConfig API.

## RPC reference

This section describes the existing RPCs used in this API.

Service to configure the Vision Module

 **VisionConfigClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|SetSensorSettings|[Empty](../messages/Common/Empty.md#)|[SensorSettings](../messages/VisionConfig/SensorSettings.md#)|Sets sensor settings \(resolution, frame rate, etc\)|
|GetSensorSettings|[SensorSettings](../messages/VisionConfig/SensorSettings.md#)|[SensorIdentifier](../messages/VisionConfig/SensorIdentifier.md#)|Retrieves sensor settings \(resolution, frame rate, etc\)|
|GetOptionValue|[OptionValue](../messages/VisionConfig/OptionValue.md#)|[OptionIdentifier](../messages/VisionConfig/OptionIdentifier.md#)|Retrieves option value from the sensor|
|SetOptionValue|[Empty](../messages/Common/Empty.md#)|[OptionValue](../messages/VisionConfig/OptionValue.md#)|Writes new value to sensor option|
|GetOptionInformation|[OptionInformation](../messages/VisionConfig/OptionInformation.md#)|[OptionIdentifier](../messages/VisionConfig/OptionIdentifier.md#)|Retrieves option information from the sensor|
|OnNotificationVisionTopic|[NotificationHandle](../messages/Common/NotificationHandle.md#)|[NotificationOptions](../messages/Common/NotificationOptions.md#)|Subscribes to Vision configuration notifications|
|DoSensorFocusAction|[Empty](../messages/Common/Empty.md#)|[SensorFocusAction](../messages/VisionConfig/SensorFocusAction.md#)|Do a focus action|
|GetIntrinsicParameters|[IntrinsicParameters](../messages/VisionConfig/IntrinsicParameters.md#)|[SensorIdentifier](../messages/VisionConfig/SensorIdentifier.md#)|Retrieves sensor intrinsic parameters|
|GetIntrinsicParametersProfile|[IntrinsicParameters](../messages/VisionConfig/IntrinsicParameters.md#)|[IntrinsicProfileIdentifier](../messages/VisionConfig/IntrinsicProfileIdentifier.md#)|Retrieves sensor intrinsic parameters for a specific profile|
|SetIntrinsicParameters|[Empty](../messages/Common/Empty.md#)|[IntrinsicParameters](../messages/VisionConfig/IntrinsicParameters.md#)|Sets sensor intrinsic parameters|
|GetExtrinsicParameters|[ExtrinsicParameters](../messages/VisionConfig/ExtrinsicParameters.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves sensor extrinsic parameters|
|SetExtrinsicParameters|[Empty](../messages/Common/Empty.md#)|[ExtrinsicParameters](../messages/VisionConfig/ExtrinsicParameters.md#)|Sets sensor extrinsic parameters|

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[DistortionCoefficients](../messages/VisionConfig/DistortionCoefficients.md#)|Distortion coefficients for sensor intrinsic parameters|
|[ExtrinsicParameters](../messages/VisionConfig/ExtrinsicParameters.md#)|Sensor extrinsic parameters|
|[FocusPoint](../messages/VisionConfig/FocusPoint.md#)|Focus point in the X-Y coordinates of the image|
|[IntrinsicParameters](../messages/VisionConfig/IntrinsicParameters.md#)|Sensor intrinsic parameters|
|[IntrinsicProfileIdentifier](../messages/VisionConfig/IntrinsicProfileIdentifier.md#)|Intrisic parameters profile to retrieve|
|[ManualFocus](../messages/VisionConfig/ManualFocus.md#)|Abstract value that affects the focus distance|
|[OptionIdentifier](../messages/VisionConfig/OptionIdentifier.md#)|Sensor and the option to configure|
|[OptionInformation](../messages/VisionConfig/OptionInformation.md#)|Information about the optional settings for the chosen sensor|
|[OptionValue](../messages/VisionConfig/OptionValue.md#)|Value of the particular option for the sensor|
|[RotationMatrix](../messages/VisionConfig/RotationMatrix.md#)|Representation of a 3x3 rotation matrix. To be a valid rotation matrix, the rows must be orthonormal \(the rows must each have norm of 1 and the row vectors must be orthogonal to each other\). The determinant must also be +1.|
|[RotationMatrixRow](../messages/VisionConfig/RotationMatrixRow.md#)|Single row of a 3x3 rotation matrix. To be a valid possible row of a rotation matrix, the norm of the row must be 1 \(the sum of the squares of the row elements has to equal 1\).|
|[SensorFocusAction](../messages/VisionConfig/SensorFocusAction.md#)|Focus action to perform for the specified sensor|
|[SensorIdentifier](../messages/VisionConfig/SensorIdentifier.md#)|Sensor to configure|
|[SensorSettings](../messages/VisionConfig/SensorSettings.md#)|Main sensor settings - resolution, frame rate, bit rate - for the chosen sensor \(color or depth\).|
|[TranslationVector](../messages/VisionConfig/TranslationVector.md#)|Provides a 3x1 translation vector configuration|
|[VisionNotification](../messages/VisionConfig/VisionNotification.md#)|Notification about a single vision module event|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[BitRate](../enums/VisionConfig/BitRate.md#)|Maximum encoded bit rate, in Mbps|
|[FocusAction](../enums/VisionConfig/FocusAction.md#)|Focus action to perform \(start/pause continuous, focus now, disable\). Supported only with Color sensor.|
|[FrameRate](../enums/VisionConfig/FrameRate.md#)|Sensor frame rate|
|[Option](../enums/VisionConfig/Option.md#)|Admissible vision module sensor options. Note that some options are only available for the color sensor and some are only available for the depth sensor.|
|[Resolution](../enums/VisionConfig/Resolution.md#)|Sensor resolution. Note that some settings are only for the color sensor and some are only for the depth sensor.|
|[Sensor](../enums/VisionConfig/Sensor.md#)|Vision module sensor to configure|
|[ServiceVersion](../enums/VisionConfig/ServiceVersion.md#)|Identifies VisionConfig service current version|
|[VisionEvent](../enums/VisionConfig/VisionEvent.md#)|Admissible Vision module events.|

