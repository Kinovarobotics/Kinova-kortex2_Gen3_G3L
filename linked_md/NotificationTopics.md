# Subscribing to Notifications

In order to receive notifications on a topic, a program must subscribe to it using the following syntax:

C++
```
service->OnNotification<$TopicName$>(callback, NotificationOptions)
```

Python
```
service.OnNotification<$TopicName$>(callback, NotificationOptions)
```

Where:
* `service` is the API service responsible for publishing
* `<$TopicName$>` should be replaced by the appropriate topic name
* `callback` is a user-defined callback function
* `NotificationOptions` is an empty NotificationOptions object

Below is a list of all the topics made available by each service.

## List of available Notification Topics

|Service|Topic name|Description|Example|
|----------|-----|-----------|--------|
|Base|ConfigurationChangeTopic|Publishes on any configuration change|Action is modified|
|Base|MappingInfoTopic|Publishes on Controler mapping change|Set user-defined XBox controller mapping|
|Base|OperatingModeTopic|Publishes on Operating mode change|Robot operating mode switches to UPDATING_DEVICE_MODE|
|Base|SequenceInfoTopic|Publishes on Sequence progress|Sequence current action is COMPLETE|
|Base|ProtectionZoneTopic|Publishes on interaction with Protection Zones| Protection zone is entered|
|Base|UserTopic|Publishes on User activity| User Logged in|
|Base|ControllerTopic|Publishes on Controller activity| XBox controller axis 1 set to -1|
|Base|ActionTopic|Publishes on Action activity|Action is started|
|Base|RobotEventTopic|Publishes on Robot Event|Tool was disconnected|
|Base|ServoingModeTopic|Publishes on Servoing mode change|Robot is set to LOW_LEVEL servoing|
|Base|FactoryTopic|Publishes on Factory activity|Factory reset is complete|
|Base|NetworkTopic|Publishes on Network activity|Connected to Wi-Fi network|
|Base|ArmStateTopic|Publishes on Arm State activity| Arm state changes to ARMSTATE_SERVOING_PLAYING_SEQUENCE|
|ControlConfig|ControlConfigurationTopic|Publishes on Control Configuration change|Gravity vector was changed|
|ControlConfig|ControlModeTopic|Publishes on Control mode event|Switch control mode to joystick|
|DeviceConfig|SafetyTopic|Publishes on Safety-related activity|Robot error was raised|
|VisionConfig|VisionTopic|Publishes on vision configuration change|Focus action complete|