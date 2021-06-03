# Common \(Python\)

This page describes the Python Common API.

## RPC reference

This section describes the existing RPCs used in this API.

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[Connection](../messages/Common/Connection.md#)|Connection between a user and the robot|
|[CountryCode](../messages/Common/CountryCode.md#)|Country code|
|[DeviceHandle](../messages/Common/DeviceHandle.md#)|Reference to a specific device|
|[Empty](../messages/Common/Empty.md#)|Message used when no information needs to be exchanged between client application and robot, and vice versa|
|[NotificationHandle](../messages/Common/NotificationHandle.md#)|Reference to a specific notification topic|
|[NotificationOptions](../messages/Common/NotificationOptions.md#)|Specifies options associated to a notification|
|[SafetyHandle](../messages/Common/SafetyHandle.md#)|Reference to a specific safety|
|[SafetyNotification](../messages/Common/SafetyNotification.md#)|Notification about a single safety event|
|[Timestamp](../messages/Common/Timestamp.md#)|Timestamp based on Epoch \(00:00:00 Thursday, January 1, 1970\)|
|[UARTConfiguration](../messages/Common/UARTConfiguration.md#)|UART configuration details|
|[UARTDeviceIdentification](../messages/Common/UARTDeviceIdentification.md#)|UART port id identification|
|[UserProfileHandle](../messages/Common/UserProfileHandle.md#)|Reference to a user profile|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[ArmState](../enums/Common/ArmState.md#)|Admissible robot arm states|
|[CartesianReferenceFrame](../enums/Common/CartesianReferenceFrame.md#)|Admissible Cartesian reference frame modes|
|[CountryCodeIdentifier](../enums/Common/CountryCodeIdentifier.md#)|Supported ISO3166 country identifiers|
|[DeviceTypes](../enums/Common/DeviceTypes.md#)|Admissible device types|
|[NotificationType](../enums/Common/NotificationType.md#)|Admissible notification types|
|[Permission](../enums/Common/Permission.md#)|Admissible permissions. Used as bitfields|
|[SafetyStatusValue](../enums/Common/SafetyStatusValue.md#)|Admissible safety statuses|
|[UARTParity](../enums/Common/UARTParity.md#)|Admissible UART parity mode|
|[UARTSpeed](../enums/Common/UARTSpeed.md#)|Admissible UART baudrates|
|[UARTStopBits](../enums/Common/UARTStopBits.md#)|Admissible UART stop bits|
|[UARTWordLength](../enums/Common/UARTWordLength.md#)|Admissible UART word lengths|
|[Unit](../enums/Common/Unit.md#)|Admissible units used throughout API methods|

