# Message ConfigurationChangeNotification

This page describes the Python Kinova.Api.Base.ConfigurationChangeNotification message.

## Overview / Purpose

Message that contains a configuration change event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event| [ConfigurationNotificationEvent](enm_Base_ConfigurationNotificationEvent.md#)|Configuration event|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the configuration event|
|oneof configuration\_change : sequence\_handle| [SequenceHandle](msg_Base_SequenceHandle.md#)|Sequence for which the configuration changed|
|oneof configuration\_change : action\_handle| [ActionHandle](msg_Base_ActionHandle.md#)|Action for which the configuration changed|
|oneof configuration\_change : mapping\_handle| [MappingHandle](msg_Base_MappingHandle.md#)|Mapping for which the configuration changed|
|oneof configuration\_change : map\_group\_handle| [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Map group for which the configuration changed|
|oneof configuration\_change : map\_handle| [MapHandle](msg_Base_MapHandle.md#)|Map for which the configuration changed|
|oneof configuration\_change : user\_profile\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User Profile for which the configuration changed|
|oneof configuration\_change : protection\_zone\_handle| [ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|Protection zone for which the configuration changed|
|oneof configuration\_change : safety\_handle| [SafetyHandle](msg_Common_SafetyHandle.md#)|Safety for which the configuration changed|
|oneof configuration\_change : network\_handle| [NetworkHandle](msg_Base_NetworkHandle.md#)|Network element for which the configuration changed|
|oneof configuration\_change : ssid| [Ssid](msg_Base_Ssid.md#)|Wi-Fi instance for which the configuration changed|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the configuration event|

**Parent topic:** [Base](../references/summary_Base.md)

