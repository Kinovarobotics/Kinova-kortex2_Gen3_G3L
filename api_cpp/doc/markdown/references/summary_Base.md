# Base

This page describes the C++ Kinova::Api::Base package.

## Overview / Purpose

Base module service

## API reference

This section describes procedure calls / methods exposed by the Base package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

Every method listed below, except the notification subscription methods \(begining with 'OnNotification'\) are available in three different forms :

-   **blocking** : called using listed method name \(default\)
-   **future/promise** : called using listed method name followed by the '**\_async**' suffix
-   **regiser callback** : called using listed method name followed by the '**\_callback**' suffix

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|ActivateMap|void|[ActivateMapHandle](msg_Base_ActivateMapHandle.md#)|Makes the specified map active within the specified map group and mapping|
|AddWifiConfiguration|void|[WifiConfiguration](msg_Base_WifiConfiguration.md#)|Configures a specific Wi-Fi network|
|ApplyEmergencyStop|void|void|Stops robot movement|
|ChangePassword|void|[PasswordChange](msg_Base_PasswordChange.md#)|Changes the password of an existing user|
|ClearFaults|void|void|Clears robot stop. Robot is permitted to move again.|
|ConnectWifi|void|[Ssid](msg_Base_Ssid.md#)|Connects robot to specified Wi-Fi network|
|CreateAction|[ActionHandle](msg_Base_ActionHandle.md#)|[Action](msg_Base_Action.md#)|Creates an action|
|CreateMap|[MapHandle](msg_Base_MapHandle.md#)|[Map](msg_Base_Map.md#)|Creates a new map \(future\)|
|CreateMapping|[MappingHandle](msg_Base_MappingHandle.md#)|[Mapping](msg_Base_Mapping.md#)|Creates a mapping \(future\)|
|CreateProtectionZone|[ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|[ProtectionZone](msg_Base_ProtectionZone.md#)|Creates a protection zone|
|CreateSequence|[SequenceHandle](msg_Base_SequenceHandle.md#)|[Sequence](msg_Base_Sequence.md#)|Creates a new sequence|
|CreateUserProfile|[UserProfileHandle](msg_Common_UserProfileHandle.md#)|[FullUserProfile](msg_Base_FullUserProfile.md#)|Creates a user profile|
|DeleteAction|void|[ActionHandle](msg_Base_ActionHandle.md#)|Deletes an existing action|
|DeleteAllSequenceTasks|void|[SequenceHandle](msg_Base_SequenceHandle.md#)|Deletes all tasks from the specified sequence|
|DeleteProtectionZone|void|[ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|Deletes an existing protection zone|
|DeleteSequence|void|[SequenceHandle](msg_Base_SequenceHandle.md#)|Deletes an existing sequence|
|DeleteSequenceTask|void|[SequenceTaskHandle](msg_Base_SequenceTaskHandle.md#)|Deletes a specific task from the specified sequence|
|DeleteUserProfile|void|[UserProfileHandle](msg_Common_UserProfileHandle.md#)|Deletes an existing user profile|
|DeleteWifiConfiguration|void|[Ssid](msg_Base_Ssid.md#)|Deletes a specific Wi-Fi network|
|DisconnectWifi|void|void|Disconnects the robot from currently connected Wi-Fi network|
|ExecuteAction|void|[Action](msg_Base_Action.md#)|Asks the robot to execute the specified action|
|ExecuteActionFromReference|void|[ActionHandle](msg_Base_ActionHandle.md#)|Asks the robot to execute the specified existing action|
|GetActionExecutionState|[ActionExecutionState](msg_Base_ActionExecutionState.md#)|void|Retrieves the action execution state \(future\)|
|GetActiveMap|void|[MappingHandle](msg_Base_MappingHandle.md#)|Retrieves currently active map associated with specified mapping \(future\)|
|GetActuatorCount|[ActuatorInformation](msg_Base_ActuatorInformation.md#)|void|Retrieves the number of actuators|
|GetAllConfiguredWifis|[WifiConfigurationList](msg_Base_WifiConfigurationList.md#)|void|Retrieves the list of configured Wi-Fi networks|
|GetAllConnectedControllers|[ControllerList](msg_Base_ControllerList.md#)|void|Retrieves the list of all connected controllers|
|GetArmState|[ArmStateInformation](msg_Base_ArmStateInformation.md#)|void|Retrieves current arm state|
|GetAvailableWifi|[WifiInformationList](msg_Base_WifiInformationList.md#)|void|Retrieves the list of available Wi-Fi networks|
|GetCommandedCartesianPose|[Pose](msg_Base_Pose.md#)|void|Retrieves the commanded Cartesian pose \(future\)|
|GetCommandedGripperMovement|[Gripper](msg_Base_Gripper.md#)|[GripperRequest](msg_Base_GripperRequest.md#)|Retrieves the desired gripper movement \(future\)|
|GetCommandedJointAngles|[JointAngles](msg_Base_JointAngles.md#)|void|Retrieves the desired joint angles, that is the desired joint angle for each joint \(future\)|
|GetCommandedJointSpeeds|[JointSpeeds](msg_Base_JointSpeeds.md#)|void|Retrieves the desired joint speeds, that is the desired speed for each joint \(future\)|
|GetCommandedTwist|[Twist](msg_Base_Twist.md#)|void|Retrieves the desired twist command \(future\)|
|GetConfiguredWifi|[WifiConfiguration](msg_Base_WifiConfiguration.md#)|[Ssid](msg_Base_Ssid.md#)|Retrieves a configured Wi-Fi network|
|GetConnectedWifiInformation|[WifiInformation](msg_Base_WifiInformation.md#)|void|Gets information about the connected Wi-Fi network|
|GetControllerState|[ControllerState](msg_Base_ControllerState.md#)|[ControllerHandle](msg_Base_ControllerHandle.md#)|Retrieves the state of a specific controller|
|GetControlMode|[ControlModeInformation](msg_Base_ControlModeInformation.md#)|void|Retrieves current control mode|
|GetCountryCode|[CountryCode](msg_Base_CountryCode.md#)|void|Retrieves country code|
|GetFwdKinematics|[TransformationMatrix](msg_Base_TransformationMatrix.md#)|void|Retrieves the forward kinematics that corresponds to specified transformation matrix \(future\)|
|GetIPv4Configuration|[IPv4Configuration](msg_Base_IPv4Configuration.md#)|[NetworkHandle](msg_Base_NetworkHandle.md#)|Retrieves the IPv4 network configuration for the specified network adapter|
|GetIPv4Information|[IPv4Information](msg_Base_IPv4Information.md#)|[NetworkHandle](msg_Base_NetworkHandle.md#)|Retrieves the IPv4 network information for the specified network adapter|
|GetMeasuredCartesianPose|[Pose](msg_Base_Pose.md#)|void|Retrieves the currently measured pose, that is the position and orientation that the robot is currently in|
|GetMeasuredGripperMovement|[Gripper](msg_Base_Gripper.md#)|[GripperRequest](msg_Base_GripperRequest.md#)|Retrieves the current gripper movement, that is the current gripper position, force or speed \(future\)|
|GetMeasuredJointAngles|[JointAngles](msg_Base_JointAngles.md#)|void|Retrieves the currently measured joint angles, that is the current position of each joint|
|GetMeasuredJointSpeeds|[JointSpeeds](msg_Base_JointSpeeds.md#)|void|Retrieves the currently measured joint speeds, that is the current speed of each joint \(future\)|
|GetMeasuredTwist|[Twist](msg_Base_Twist.md#)|void|Retrieves the currently measured twist command, that is the current linear and angular robot velocity \(future\)|
|GetOperatingMode|[OperatingModeInformation](msg_Base_OperatingModeInformation.md#)|void|Retrieves current operating mode|
|GetProtectionZoneState|[ProtectionZoneInformation](msg_Base_ProtectionZoneInformation.md#)|[ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|Retrieves the last state of the robot versus the specified protection zone \(future\)|
|GetSequenceState|[SequenceInformation](msg_Base_SequenceInformation.md#)|[SequenceHandle](msg_Base_SequenceHandle.md#)|Retrieves the last sequence state \(future\)|
|GetServoingMode|[ServoingModeInformation](msg_Base_ServoingModeInformation.md#)|void|Retrieves current servoing mode|
|GetTargetedCartesianPose|[Pose](msg_Base_Pose.md#)|void|Retrieves the targeted Cartesian pose \(future\)|
|GetWifiInformation|[WifiInformation](msg_Base_WifiInformation.md#)|[Ssid](msg_Base_Ssid.md#)|Retrieves information about a specific Wi-Fi network|
|IsCommunicationInterfaceEnable|[CommunicationInterfaceConfiguration](msg_Base_CommunicationInterfaceConfiguration.md#)|[NetworkHandle](msg_Base_NetworkHandle.md#)|Determines if the specified communication interface is enabled \(or disabled\)|
|OnNotificationActionTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to action notifications|
|OnNotificationArmStateTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to arm state notifications|
|OnNotificationConfigurationChangeTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to configuration change notifications|
|OnNotificationControllerTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to controller notifications|
|OnNotificationControlModeTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to control mode notifications|
|OnNotificationFactoryTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to factory notifications|
|OnNotificationMappingInfoTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to mapping information notifications|
|OnNotificationNetworkTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to network event notifications|
|OnNotificationOperatingModeTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to operating mode notifications|
|OnNotificationProtectionZoneTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to protection zone notifications \(future\)|
|OnNotificationRobotEventTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to robot event notifications|
|OnNotificationSequenceInfoTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to sequence information notifications|
|OnNotificationServoingModeTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to servoing mode notifications|
|OnNotificationUserTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to user notifications|
|Pause|void|void|Pauses robot movement \(future\)|
|PauseAction|void|void|Pauses the currently executed action. ResumeAction can be invoked afterwards|
|PauseSequence|void|void|Pauses execution of currently playing sequence|
|PlayAdvancedSequence|void|[AdvancedSequenceHandle](msg_Base_AdvancedSequenceHandle.md#)|Plays an existing sequence with options|
|PlayCartesianTrajectory|void|[ConstrainedPose](msg_Base_ConstrainedPose.md#)|Moves to the specifed pose|
|PlayCartesianTrajectoryOrientation|void|[ConstrainedOrientation](msg_Base_ConstrainedOrientation.md#)|Moves to the specifed orientation|
|PlayCartesianTrajectoryPosition|void|[ConstrainedPosition](msg_Base_ConstrainedPosition.md#)|Moves to the specifed position|
|PlayJointTrajectory|void|[ConstrainedJointAngles](msg_Base_ConstrainedJointAngles.md#)|Moves to the specifed joint angles|
|PlaySelectedJointTrajectory|void|[ConstrainedJointAngle](msg_Base_ConstrainedJointAngle.md#)|Moves specifed joint to the specifed joint angle|
|PlaySequence|void|[SequenceHandle](msg_Base_SequenceHandle.md#)|Plays an existing sequence|
|ReadAction|[Action](msg_Base_Action.md#)|[ActionHandle](msg_Base_ActionHandle.md#)|Retrieves an existing action|
|ReadAllActions|[ActionList](msg_Base_ActionList.md#)|[RequestedActionType](msg_Base_RequestedActionType.md#)|Retrieves all existing actions|
|ReadAllMappings|[MappingList](msg_Base_MappingList.md#)|void|Retrieves all mappings|
|ReadAllMaps|[MapList](msg_Base_MapList.md#)|[MappingHandle](msg_Base_MappingHandle.md#)|Retrieves all maps associated to the specified mapping|
|ReadAllProtectionZones|[ProtectionZoneList](msg_Base_ProtectionZoneList.md#)|void|Retrieves all protection zones|
|ReadAllSequences|[SequenceList](msg_Base_SequenceList.md#)|void|Retrieves all existing sequences|
|ReadAllUserProfiles|[UserProfileList](msg_Base_UserProfileList.md#)|void|Retrieves all user profiles|
|ReadAllUsers|[UserList](msg_Base_UserList.md#)|void|Retrieves the list of user handles|
|ReadMapping|[Mapping](msg_Base_Mapping.md#)|[MappingHandle](msg_Base_MappingHandle.md#)|Retrieves an existing mapping|
|ReadProtectionZone|[ProtectionZone](msg_Base_ProtectionZone.md#)|[ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|Retrieves an existing protection zone|
|ReadSequence|[Sequence](msg_Base_Sequence.md#)|[SequenceHandle](msg_Base_SequenceHandle.md#)|Reads an existing sequence|
|ReadUserProfile|[UserProfile](msg_Base_UserProfile.md#)|[UserProfileHandle](msg_Common_UserProfileHandle.md#)|Retrieves an existing user profile|
|Reboot|void|void|Reboots robot|
|RestoreFactorySettings|void|void|Deletes all configurations and reverts settings to their factory defaults \(except network settings\)|
|RestoreNetworkFactorySettings|void|void|Reverts network settings to their factory defaults and predefined user profiles to their default passwords \(future\)|
|Resume|void|void|Resumes robot movement \(future\)|
|ResumeAction|void|void|Resumes execution of the currently paused action|
|ResumeSequence|void|void|Resumes execution of currently paused sequence|
|SendGripperCommand|void|[GripperCommand](msg_Base_GripperCommand.md#)|Sends a command to move the gripper|
|SendJointSpeedsCommmand|void|[JointSpeeds](msg_Base_JointSpeeds.md#)|Sends a joint speeds command, that is the desired speed of one or many joints|
|SendSelectedJointSpeedCommand|void|[JointSpeed](msg_Base_JointSpeed.md#)|Sends a speed command for a specific joint|
|SendTwistCommand|void|[TwistCommand](msg_Base_TwistCommand.md#)|Sends a twist command|
|SetAdmittance|void|[Admittance](msg_Base_Admittance.md#)|Sets the robot in admittance mode|
|SetCommunicationInterfaceEnable|void|[CommunicationInterfaceConfiguration](msg_Base_CommunicationInterfaceConfiguration.md#)|Enables \(or disables\) the specified communication interface|
|SetCountryCode|void|[CountryCode](msg_Base_CountryCode.md#)|Sets country code|
|SetIPv4Configuration|void|[FullIPv4Configuration](msg_Base_FullIPv4Configuration.md#)|Modifies the IPv4 network configuration for the specified network adapter|
|SetOperatingMode|void|[OperatingModeInformation](msg_Base_OperatingModeInformation.md#)|Sets a new operating mode. Only Maintenance, Update and Run modes are permitted.|
|SetServoingMode|void|[ServoingModeInformation](msg_Base_ServoingModeInformation.md#)|Sets the servoing mode|
|SetTwistWrenchReferenceFrame|void|[CartesianReferenceFrameRequest](msg_Base_CartesianReferenceFrameRequest.md#)|Defines the reference frame to use with twist and wrench commands|
|StartWifiScan|void|void|Initiates wifi scanning|
|StopAction|void|void|Stops the currently executed action. ResumeAction cannot be invoked afterwards|
|StopSequence|void|void|Stops execution of currently playing sequence|
|Unsubscribe|void|[NotificationHandle](msg_Common_NotificationHandle.md#)|Unsubscribes client from receiving specified types of notifications|
|UpdateAction|void|[Action](msg_Base_Action.md#)|Update an existing action|
|UpdateProtectionZone|void|[ProtectionZone](msg_Base_ProtectionZone.md#)|Updates an existing protection zone|
|UpdateSequence|void|[Sequence](msg_Base_Sequence.md#)|Updates an existing sequence|
|UpdateUserProfile|void|[UserProfile](msg_Base_UserProfile.md#)|Updates an existing user profile|

## Data types reference

This section describes the data types used in the Base package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[Action](msg_Base_Action.md#)|Defines an action|
|[ActionExecutionState](msg_Base_ActionExecutionState.md#)|Indicates the execution state of an action \(future\)|
|[ActionHandle](msg_Base_ActionHandle.md#)|Identifies an action|
|[ActionList](msg_Base_ActionList.md#)|Array of actions|
|[ActionNotification](msg_Base_ActionNotification.md#)|Message that contains an action event|
|[ActionNotificationList](msg_Base_ActionNotificationList.md#)|Array of action notifications|
|[ActivateMapHandle](msg_Base_ActivateMapHandle.md#)|Specifies a new active map for the specified mapping and map group|
|[ActuatorInformation](msg_Base_ActuatorInformation.md#)|Provides information about actuators|
|[Admittance](msg_Base_Admittance.md#)|Defines the admittance mode|
|[AdvancedSequenceHandle](msg_Base_AdvancedSequenceHandle.md#)|Associates execution options to a sequence|
|[AppendActionInformation](msg_Base_AppendActionInformation.md#)|Appends an action to an existing sequence \(future\)|
|[ArmStateInformation](msg_Base_ArmStateInformation.md#)|Provides information about the arm state|
|[ArmStateNotification](msg_Base_ArmStateNotification.md#)|Message that contains a arm state event|
|[CartesianLimitation](msg_Base_CartesianLimitation.md#)|Provides a Cartesian limitation configuration|
|[CartesianLimitationList](msg_Base_CartesianLimitationList.md#)|Array of Cartesian limitations|
|[CartesianReferenceFrameRequest](msg_Base_CartesianReferenceFrameRequest.md#)|Defines a Cartesian reference frame|
|[CartesianSpeed](msg_Base_CartesianSpeed.md#)|Defines a Cartesian speed|
|[CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)|Defines a Cartesian trajectory constraint that can be applied when controlling in Cartesian trajectory mode|
|[ChangeJointSpeeds](msg_Base_ChangeJointSpeeds.md#)|Defines an action to increase \(or reduce\) the maximum angular velocity per joint by a specific increment|
|[ChangeTwist](msg_Base_ChangeTwist.md#)|Defines an action to increase \(or reduce\) the maximum Cartesian velocity by a specific increment|
|[CommunicationInterfaceConfiguration](msg_Base_CommunicationInterfaceConfiguration.md#)|Enables or disables a specific communication interface \(e.g. Wi-Fi, Wired Ethernet\)|
|[ConfigurationChangeNotification](msg_Base_ConfigurationChangeNotification.md#)|Message that contains a configuration change event|
|[ConfigurationChangeNotificationList](msg_Base_ConfigurationChangeNotificationList.md#)|Array of configuration change notifications|
|[ConstrainedJointAngle](msg_Base_ConstrainedJointAngle.md#)|Defines a single joint angle value with constraint|
|[ConstrainedJointAngles](msg_Base_ConstrainedJointAngles.md#)|Defines a series of joint angles value with constraint|
|[ConstrainedOrientation](msg_Base_ConstrainedOrientation.md#)|Defines a Cartesian orientation with constraint|
|[ConstrainedPose](msg_Base_ConstrainedPose.md#)|Defines a Cartesian pose with constraint|
|[ConstrainedPosition](msg_Base_ConstrainedPosition.md#)|Defines a Cartesian position with constraint|
|[ControlModeInformation](msg_Base_ControlModeInformation.md#)|Provides control mode information|
|[ControlModeNotification](msg_Base_ControlModeNotification.md#)|Message that contains a control mode event|
|[ControlModeNotificationList](msg_Base_ControlModeNotificationList.md#)|Array of control mode notifications|
|[ControllerElementHandle](msg_Base_ControllerElementHandle.md#)|Identifies a specific button \(or axis\) of a controller|
|[ControllerElementState](msg_Base_ControllerElementState.md#)|Indicates if a specific button \(or axis\) was pressed \(or moved\)|
|[ControllerEvent](msg_Base_ControllerEvent.md#)|Identifies a controller event|
|[ControllerHandle](msg_Base_ControllerHandle.md#)|Identifies a specific controller|
|[ControllerList](msg_Base_ControllerList.md#)|Array of controllers|
|[ControllerNotification](msg_Base_ControllerNotification.md#)|Message that contains a controller event|
|[ControllerNotificationList](msg_Base_ControllerNotificationList.md#)|Array of controller notifications|
|[ControllerState](msg_Base_ControllerState.md#)|Indicates if a controller is connected \(or disconnected\)|
|[CountryCode](msg_Base_CountryCode.md#)|Country code|
|[Delay](msg_Base_Delay.md#)|Defines an action to apply a delay|
|[EmergencyStop](msg_Base_EmergencyStop.md#)|Defines an action to force an emergency of the robot|
|[FactoryNotification](msg_Base_FactoryNotification.md#)|Message that contains a factory event|
|[Faults](msg_Base_Faults.md#)|Defines an action to clear faults|
|[Finger](msg_Base_Finger.md#)|Defines a finger movement|
|[FullIPv4Configuration](msg_Base_FullIPv4Configuration.md#)|Provides an IPv4 configuration for a specific network|
|[FullUserProfile](msg_Base_FullUserProfile.md#)|Provides complete infomation about a user. Used when creating a user profile.|
|[GpioEvent](msg_Base_GpioEvent.md#)|Identifies a GPIO event \(future\)|
|[Gripper](msg_Base_Gripper.md#)|Defines a gripper movement, which is composed of a series of fingers movement|
|[GripperCommand](msg_Base_GripperCommand.md#)|Defines a command to control the gripper movement|
|[GripperRequest](msg_Base_GripperRequest.md#)|Message used to request the current gripper movement in either position, force or speed|
|[IPv4Configuration](msg_Base_IPv4Configuration.md#)|Provides an IPv4 configuration|
|[IPv4Information](msg_Base_IPv4Information.md#)|Provides information about an IPv4 endpoint|
|[JointAngle](msg_Base_JointAngle.md#)|Position of a specific joint|
|[JointAngles](msg_Base_JointAngles.md#)|Position of a series of joints|
|[JointLimitation](msg_Base_JointLimitation.md#)|Defines a joint limitation|
|[JointLimitationTypeIdentifier](msg_Base_JointLimitationTypeIdentifier.md#)|Identifies a joint limitation for a specific joint|
|[JointLimitationValue](msg_Base_JointLimitationValue.md#)|Defines joint limitation value|
|[JointLimitationValueList](msg_Base_JointLimitationValueList.md#)|List of joint limitations|
|[JointSpeed](msg_Base_JointSpeed.md#)|Defines the speed of a specific joint|
|[JointSpeeds](msg_Base_JointSpeeds.md#)|Defines a series of joint speeds|
|[JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)|Defines a joint trajectory constraint that can be applied when controlling a joint in trajectory mode|
|[LimitationTypeIdentifier](msg_Base_LimitationTypeIdentifier.md#)|Identifies a limitation|
|[Map](msg_Base_Map.md#)|Defines a map as an array of map elements|
|[MapElement](msg_Base_MapElement.md#)|Associates a map event to map action|
|[MapEvent](msg_Base_MapEvent.md#)|Defines a map event|
|[MapGroup](msg_Base_MapGroup.md#)|Message that contains all information about a map group including the list of maps that it contains and its relationship versus other map groups \(future\)|
|[MapGroupHandle](msg_Base_MapGroupHandle.md#)|Identifies a map group \(future\)|
|[MapGroupList](msg_Base_MapGroupList.md#)|Array of map groups \(future\)|
|[MapHandle](msg_Base_MapHandle.md#)|Identifies a map|
|[MapList](msg_Base_MapList.md#)|Array of maps|
|[Mapping](msg_Base_Mapping.md#)|Message that contains all information about a mapping including the controller to which it is associated, the array of map groups it contains, the currently active map group, the array of maps it contains and the currently active map|
|[MappingHandle](msg_Base_MappingHandle.md#)|Identifies a Mapping|
|[MappingInfoNotification](msg_Base_MappingInfoNotification.md#)|Message that contains a mapping information event|
|[MappingInfoNotificationList](msg_Base_MappingInfoNotificationList.md#)|Array of mapping information notifications|
|[MappingList](msg_Base_MappingList.md#)|Array of mappings|
|[NetworkHandle](msg_Base_NetworkHandle.md#)|Identifies a network|
|[NetworkNotification](msg_Base_NetworkNotification.md#)|Message that contains a network event|
|[NetworkNotificationList](msg_Base_NetworkNotificationList.md#)|Array of network event notifications|
|[OperatingModeInformation](msg_Base_OperatingModeInformation.md#)|Provides information about the operating mode|
|[OperatingModeNotification](msg_Base_OperatingModeNotification.md#)|Message that contains an operating mode event|
|[OperatingModeNotificationList](msg_Base_OperatingModeNotificationList.md#)|Array of Operating mode notifications|
|[Orientation](msg_Base_Orientation.md#)|Defines a Cartesian orientation|
|[PasswordChange](msg_Base_PasswordChange.md#)|Provides information to change a user's password|
|[Point](msg_Base_Point.md#)|Identifies a Cartesian point|
|[Pose](msg_Base_Pose.md#)|Defines a Cartesian pose|
|[Position](msg_Base_Position.md#)|Defines a Cartesian position|
|[ProtectionZone](msg_Base_ProtectionZone.md#)|Provides a protection zone configuration|
|[ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|Identifies a protection zone|
|[ProtectionZoneInformation](msg_Base_ProtectionZoneInformation.md#)|Provides information about a protection zone|
|[ProtectionZoneList](msg_Base_ProtectionZoneList.md#)|Array of protection zones|
|[ProtectionZoneNotification](msg_Base_ProtectionZoneNotification.md#)|Message that contains a protection zone event|
|[ProtectionZoneNotificationList](msg_Base_ProtectionZoneNotificationList.md#)|Array of protection zone notifications|
|[Query](msg_Base_Query.md#)|Specifies the parameters of an event log query \(future\)|
|[RequestedActionType](msg_Base_RequestedActionType.md#)|Message used to request all action instances of a specific action type|
|[RobotEventNotification](msg_Base_RobotEventNotification.md#)|Message that contains a robot event|
|[RobotEventNotificationList](msg_Base_RobotEventNotificationList.md#)|Array of robot event notifications|
|[RotationMatrix](msg_Base_RotationMatrix.md#)|Provides a 3x3 rotation matrix configuration|
|[RotationMatrixRow](msg_Base_RotationMatrixRow.md#)|Provides the rotation matrix configuration of a single row|
|[SafetyEvent](msg_Base_SafetyEvent.md#)|Identifies a Safety event \(future\)|
|[SafetyNotificationList](msg_Base_SafetyNotificationList.md#)|Array of safety notifications|
|[Sequence](msg_Base_Sequence.md#)|Provides information about a sequence|
|[SequenceHandle](msg_Base_SequenceHandle.md#)|Identifies a sequence|
|[SequenceInfoNotification](msg_Base_SequenceInfoNotification.md#)|Message that contains a sequence information event|
|[SequenceInfoNotificationList](msg_Base_SequenceInfoNotificationList.md#)|Array of sequence information notifications|
|[SequenceInformation](msg_Base_SequenceInformation.md#)|Provides information about a sequence|
|[SequenceList](msg_Base_SequenceList.md#)|Array of sequences|
|[SequenceTask](msg_Base_SequenceTask.md#)|Provides information about a task inside a sequence|
|[SequenceTaskHandle](msg_Base_SequenceTaskHandle.md#)|Identifies a task inside a sequence|
|[ServoingModeInformation](msg_Base_ServoingModeInformation.md#)|Provides information about the servoing mode|
|[ServoingModeNotification](msg_Base_ServoingModeNotification.md#)|Message that contains a servoing mode event|
|[ServoingModeNotificationList](msg_Base_ServoingModeNotificationList.md#)|Array of servoing mode notifications|
|[Ssid](msg_Base_Ssid.md#)|Identifies a Wi-Fi SSID|
|[Stop](msg_Base_Stop.md#)|Defines an action to stop robot movement|
|[SwitchControlMapping](msg_Base_SwitchControlMapping.md#)|Defines an action to switch the active controller map|
|[SystemTime](msg_Base_SystemTime.md#)|Identifies the system time \(future\)|
|[Timeout](msg_Base_Timeout.md#)|Defines a specific timeout|
|[TransformationMatrix](msg_Base_TransformationMatrix.md#)|Defines a transformation matrix|
|[TransformationRow](msg_Base_TransformationRow.md#)|Defines a transformation matrix row|
|[Twist](msg_Base_Twist.md#)|Defines a twist \(velocity\)|
|[TwistCommand](msg_Base_TwistCommand.md#)|Defines a twist \(velocity\) command|
|[UserList](msg_Base_UserList.md#)|Array of user handles|
|[UserNotification](msg_Base_UserNotification.md#)|Message that contains a user event|
|[UserNotificationList](msg_Base_UserNotificationList.md#)|Array of user notifications|
|[UserProfile](msg_Base_UserProfile.md#)|Provides information about a user|
|[UserProfileList](msg_Base_UserProfileList.md#)|Array of user profiles|
|[WifiConfiguration](msg_Base_WifiConfiguration.md#)|Provides a Wi-Fi Configuration|
|[WifiConfigurationList](msg_Base_WifiConfigurationList.md#)|Array of Wi-Fi configuration|
|[WifiInformation](msg_Base_WifiInformation.md#)|Provides information about a specific Wi-Fi network|
|[WifiInformationList](msg_Base_WifiInformationList.md#)|Array of Wi-Fi information|
|[ZoneShape](msg_Base_ZoneShape.md#)|Provides a protection zone shape description|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[ActionEvent](enm_Base_ActionEvent.md#)|List of admissible action event types|
|[ActionType](enm_Base_ActionType.md#)|List of admissible action types|
|[AdmittanceMode](enm_Base_AdmittanceMode.md#)|List of admissible admittance modes|
|[BackupEvent](enm_Base_BackupEvent.md#)|List of admissible backup events \(future\)|
|[CartesianReferenceFrame](enm_Base_CartesianReferenceFrame.md#)|List of admissible Cartesian reference frame modes|
|[ConfigurationNotificationEvent](enm_Base_ConfigurationNotificationEvent.md#)|List of admissible configuration events|
|[ControlMode](enm_Base_ControlMode.md#)|List of admissible robot control modes|
|[ControllerBehavior](enm_Base_ControllerBehavior.md#)|List of admissible controller input behaviors|
|[ControllerElementEventType](enm_Base_ControllerElementEventType.md#)|List of admissible controller element event types|
|[ControllerEventType](enm_Base_ControllerEventType.md#)|List of admissible controller event types|
|[ControllerInputType](enm_Base_ControllerInputType.md#)|List of admissible controller input types|
|[ControllerType](enm_Base_ControllerType.md#)|List of admissible controller types|
|[CountryCodeIdentifier](enm_Base_CountryCodeIdentifier.md#)|list of supported ISO3166 country identifiers|
|[EventIdSequenceInfoNotification](enm_Base_EventIdSequenceInfoNotification.md#)|List of admissible sequence event types|
|[FactoryEvent](enm_Base_FactoryEvent.md#)|List of admissible factory events|
|[GpioState](enm_Base_GpioState.md#)|List of admissible GPIO states \(future\)|
|[GripperMode](enm_Base_GripperMode.md#)|List of admissible gripper control mode|
|[JointNavigationDirection](enm_Base_JointNavigationDirection.md#)|List of admissible joint navigation directions|
|[JointTrajectoryConstraintType](enm_Base_JointTrajectoryConstraintType.md#)|List of admissible constraint types that can be applied when controlling a joint in trajectory mode|
|[LedState](enm_Base_LedState.md#)|List of admissible LED states \(future\)|
|[LimitationType](enm_Base_LimitationType.md#)|List of admisible limitation types|
|[NavigationDirection](enm_Base_NavigationDirection.md#)|List of admissible map navigation directions|
|[NetworkEvent](enm_Base_NetworkEvent.md#)|List of admissible network events|
|[NetworkType](enm_Base_NetworkType.md#)|List of admissible network types|
|[OperatingMode](enm_Base_OperatingMode.md#)|List of admissible robot operating modes \(used to report robot firmware upgrade current state\)|
|[ProtectionZoneEvent](enm_Base_ProtectionZoneEvent.md#)|List of admissible protection zone events|
|[RobotEvent](enm_Base_RobotEvent.md#)|List of admissible robot events|
|[SafetyIdentifier](enm_Base_SafetyIdentifier.md#)|List of admissible Base safeties. Used with BaseCyclic.BaseFeedback.\[fault\_bank\_a - fault\_bank\_b - warning\_bank\_a - warning\_bank\_b\]|
|[ServiceVersion](enm_Base_ServiceVersion.md#)|Enumeration used to identify Base service current version|
|[ServoingMode](enm_Base_ServoingMode.md#)|List of admissible servoing modes|
|[ShapeType](enm_Base_ShapeType.md#)|List of admissible protection zone shape types|
|[SignalQuality](enm_Base_SignalQuality.md#)|List of admissible signal quality values|
|[SoundType](enm_Base_SoundType.md#)|List of admissible sound types \(future\)|
|[TwistMode](enm_Base_TwistMode.md#)|List of admissible twist \(velocity\) modes|
|[UserEvent](enm_Base_UserEvent.md#)|List of admissible user event types|
|[WifiEncryptionType](enm_Base_WifiEncryptionType.md#)|List of admissible Wi-Fi encryption types|
|[WifiSecurityType](enm_Base_WifiSecurityType.md#)|List of admissible Wi-Fi Security types|
|[Xbox360AnalogInputIdentifier](enm_Base_Xbox360AnalogInputIdentifier.md#)|List of admissible XBOX360 analog inputs|
|[Xbox360DigitalInputIdentifier](enm_Base_Xbox360DigitalInputIdentifier.md#)|List of admissible XBOX360 digital inputs|

**Parent topic:** [KINOVA® KORTEX™ C++ API Reference](../index.md#)

