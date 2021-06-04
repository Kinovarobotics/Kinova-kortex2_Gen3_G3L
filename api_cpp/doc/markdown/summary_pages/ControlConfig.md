# ControlConfig \(C++\)

This page describes the C++ ControlConfig API.

## RPC reference

This section describes the existing RPCs used in this API.

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
|GetControlMode|[ControlModeInformation](../messages/ControlConfig/ControlModeInformation.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves current control mode|
|SetJointSpeedSoftLimits|[Empty](../messages/Common/Empty.md#)|[JointSpeedSoftLimits](../messages/ControlConfig/JointSpeedSoftLimits.md#)|Set the software joint speed limits.|
|SetTwistLinearSoftLimit|[Empty](../messages/Common/Empty.md#)|[TwistLinearSoftLimit](../messages/ControlConfig/TwistLinearSoftLimit.md#)|Set the software twist linear limit.|
|SetTwistAngularSoftLimit|[Empty](../messages/Common/Empty.md#)|[TwistAngularSoftLimit](../messages/ControlConfig/TwistAngularSoftLimit.md#)|Set the software twist angular limit.|
|SetJointAccelerationSoftLimits|[Empty](../messages/Common/Empty.md#)|[JointAccelerationSoftLimits](../messages/ControlConfig/JointAccelerationSoftLimits.md#)|Set the software joint acceleration limits.|
|GetKinematicHardLimits|[KinematicLimits](../messages/ControlConfig/KinematicLimits.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves angular and twist hard limits.|
|GetKinematicSoftLimits|[KinematicLimits](../messages/ControlConfig/KinematicLimits.md#)|[ControlModeInformation](../messages/ControlConfig/ControlModeInformation.md#)|Retrieves the software kinematic limits for a specific control mode.|
|GetAllKinematicSoftLimits|[KinematicLimitsList](../messages/ControlConfig/KinematicLimitsList.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the software kinematic limits for all control modes.|
|SetDesiredLinearTwist|[Empty](../messages/Common/Empty.md#)|[LinearTwist](../messages/ControlConfig/LinearTwist.md#)|Set the desired linear twist when using the joystick.|
|SetDesiredAngularTwist|[Empty](../messages/Common/Empty.md#)|[AngularTwist](../messages/ControlConfig/AngularTwist.md#)|Set the desired angular twist when using the joystick.|
|SetDesiredJointSpeeds|[Empty](../messages/Common/Empty.md#)|[JointSpeeds](../messages/ControlConfig/JointSpeeds.md#)|Set the desired joint speeds when using the joystick in angular mode.|
|GetDesiredSpeeds|[DesiredSpeeds](../messages/ControlConfig/DesiredSpeeds.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the desired joystick speeds|
|ResetGravityVector|[GravityVector](../messages/ControlConfig/GravityVector.md#)|[Empty](../messages/Common/Empty.md#)|Resets gravity vector to default values|
|ResetPayloadInformation|[PayloadInformation](../messages/ControlConfig/PayloadInformation.md#)|[Empty](../messages/Common/Empty.md#)|Resets payload information to default values|
|ResetToolConfiguration|[ToolConfiguration](../messages/ControlConfig/ToolConfiguration.md#)|[Empty](../messages/Common/Empty.md#)|Resets tool configuration to default values|
|ResetJointSpeedSoftLimits|[JointSpeedSoftLimits](../messages/ControlConfig/JointSpeedSoftLimits.md#)|[ControlModeInformation](../messages/ControlConfig/ControlModeInformation.md#)|Resets joint speed soft limits to default values|
|ResetTwistLinearSoftLimit|[TwistLinearSoftLimit](../messages/ControlConfig/TwistLinearSoftLimit.md#)|[ControlModeInformation](../messages/ControlConfig/ControlModeInformation.md#)|Resets twist linear soft limit to default value|
|ResetTwistAngularSoftLimit|[TwistAngularSoftLimit](../messages/ControlConfig/TwistAngularSoftLimit.md#)|[ControlModeInformation](../messages/ControlConfig/ControlModeInformation.md#)|Resets twist angular soft limit to default value|
|ResetJointAccelerationSoftLimits|[JointAccelerationSoftLimits](../messages/ControlConfig/JointAccelerationSoftLimits.md#)|[ControlModeInformation](../messages/ControlConfig/ControlModeInformation.md#)|Resets joint acceleration soft limits to default values|
|OnNotificationControlModeTopic|[NotificationHandle](../messages/Common/NotificationHandle.md#)|[NotificationOptions](../messages/Common/NotificationOptions.md#)|Subscribes to control mode topic for notifications|

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[AngularTwist](../messages/ControlConfig/AngularTwist.md#)|Desired Joystick angular speed.|
|[CartesianReferenceFrameInfo](../messages/ControlConfig/CartesianReferenceFrameInfo.md#)|Cartesian reference frame|
|[CartesianTransform](../messages/ControlConfig/CartesianTransform.md#)|Defines a Cartesian transform|
|[ControlConfigurationNotification](../messages/ControlConfig/ControlConfigurationNotification.md#)|Notification about a single control configuration event|
|[ControlModeInformation](../messages/ControlConfig/ControlModeInformation.md#)|Control mode information|
|[ControlModeNotification](../messages/ControlConfig/ControlModeNotification.md#)|Notification about a single control mode event|
|[DesiredSpeeds](../messages/ControlConfig/DesiredSpeeds.md#)|Desired Joystick speeds.|
|[GravityVector](../messages/ControlConfig/GravityVector.md#)|Defines the gravity vector in terms of the robot base frame. If not explicitly configured, it defaults to \(0, 0, -9.81\), assuming a mounting on a horizontal surface. If the robot is mounted on a wall or ceiling, the gravity vector relative to the base frame will change. The control library needs to be aware of this to accurately compensate for gravity.|
|[JointAccelerationSoftLimits](../messages/ControlConfig/JointAccelerationSoftLimits.md#)|Software Joint acceleration limits|
|[JointSpeedSoftLimits](../messages/ControlConfig/JointSpeedSoftLimits.md#)|Software joint speed limits|
|[JointSpeeds](../messages/ControlConfig/JointSpeeds.md#)|Desired Joystick joint speeds.|
|[KinematicLimits](../messages/ControlConfig/KinematicLimits.md#)|Kinematic limits|
|[KinematicLimitsList](../messages/ControlConfig/KinematicLimitsList.md#)|Kinematic limits|
|[LinearTwist](../messages/ControlConfig/LinearTwist.md#)|Desired Joystick linear speed.|
|[PayloadInformation](../messages/ControlConfig/PayloadInformation.md#)|Defines payload information|
|[Position](../messages/ControlConfig/Position.md#)|A Cartesian position|
|[ToolConfiguration](../messages/ControlConfig/ToolConfiguration.md#)|Defines a tool configuration|
|[TwistAngularSoftLimit](../messages/ControlConfig/TwistAngularSoftLimit.md#)|Software twist angular speed limit|
|[TwistLinearSoftLimit](../messages/ControlConfig/TwistLinearSoftLimit.md#)|Software twist linear speed limit|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[ControlConfigurationEvent](../enums/ControlConfig/ControlConfigurationEvent.md#)|Admissible control configuration events|
|[ControlMode](../enums/ControlConfig/ControlMode.md#)|Admissible robot control modes|
|[ServiceVersion](../enums/ControlConfig/ServiceVersion.md#)|Identifies ControlConfig current version|

