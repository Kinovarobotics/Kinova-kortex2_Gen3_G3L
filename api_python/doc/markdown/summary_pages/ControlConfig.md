# ControlConfig \(Python\)

This page describes the Python ControlConfig API.

## Class reference

This section describes the data classes used in this API, as well as their member values and member functions.

 **Messages** 

|Class|Description|
|-----|-----------|
|[CartesianReferenceFrameInfo](../messages/ControlConfig/CartesianReferenceFrameInfo.md#)|Cartesian reference frame|
|[CartesianTransform](../messages/ControlConfig/CartesianTransform.md#)|Defines a Cartesian transform|
|[ControlConfigurationNotification](../messages/ControlConfig/ControlConfigurationNotification.md#)|Notification about a single control configuration event|
|[GravityVector](../messages/ControlConfig/GravityVector.md#)|Defines the gravity vector in terms of the robot base frame. If not explicitly configured, it defaults to \(0, 0, -9.81\), assuming a mounting on a horizontal surface. If the robot is mounted on a wall or ceiling, the gravity vector relative to the base frame will change. The control library needs to be aware of this to accurately compensate for gravity.|
|[PayloadInformation](../messages/ControlConfig/PayloadInformation.md#)|Defines payload information|
|[Position](../messages/ControlConfig/Position.md#)|A Cartesian position|
|[ToolConfiguration](../messages/ControlConfig/ToolConfiguration.md#)|Defines a tool configuration|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[ControlConfigurationEvent](../enums/ControlConfig/ControlConfigurationEvent.md#)|Admissible control configuration events|
|[ServiceVersion](../enums/ControlConfig/ServiceVersion.md#)|Identifies ControlConfig current version|

Service to configure robot control library

 **ControlConfigClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|SetGravityVector|[Empty](../messages/Common/Empty.md#)|[GravityVector](../messages/ControlConfig/GravityVector.md#)|Sets global gravity vector in terms of base reference frame. This needs to be configured to enable control of the robot in wall or ceiling mounting of the robot.|
|GetGravityVector|[GravityVector](../messages/ControlConfig/GravityVector.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves global gravity vector|
|SetPayloadInformation|[Empty](../messages/Common/Empty.md#)|[PayloadInformation](../messages/ControlConfig/PayloadInformation.md#)|Sets payload information. This needs to be configured so that the control library can take into account the presence of the payload mass in computing the dynamics of the robot.|
|GetPayloadInformation|[PayloadInformation](../messages/ControlConfig/PayloadInformation.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves payload information|
|SetToolConfiguration|[Empty](../messages/Common/Empty.md#)|[ToolConfiguration](../messages/ControlConfig/ToolConfiguration.md#)|Sets tool configuration. This needs to be configured for two reasons. 1\) so that the control library can take into account the presence of the tool mass in computing the dynamics of the robot. 2\) so that the robot is aware of the tool frame center relative position and orientation to correctly compute and report the tool position.|
|GetToolConfiguration|[ToolConfiguration](../messages/ControlConfig/ToolConfiguration.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves tool configuration|
|OnNotificationControlConfigurationTopic|[NotificationHandle](../messages/Common/NotificationHandle.md#)|[NotificationOptions](../messages/Common/NotificationOptions.md#)|Subscribes to control configuration notifications|
|Unsubscribe|[Empty](../messages/Common/Empty.md#)|[NotificationHandle](../messages/Common/NotificationHandle.md#)|Unsubscribes client from receiving specified type of notifications|
|SetCartesianReferenceFrame|[Empty](../messages/Common/Empty.md#)|[CartesianReferenceFrameInfo](../messages/ControlConfig/CartesianReferenceFrameInfo.md#)|Defines the reference frame to use with twist and wrench commands|
|GetCartesianReferenceFrame|[CartesianReferenceFrameInfo](../messages/ControlConfig/CartesianReferenceFrameInfo.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the current reference frame used by the twist and wrench commands|

