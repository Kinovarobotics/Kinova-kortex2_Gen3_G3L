# Message ConfigurationChangeNotification

This page describes the Python Kinova.Api.Base.ConfigurationChangeNotification message.

## Overview / Purpose

Message that contains a configuration change event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event|int|Configuration event|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the configuration event|
|sequence\_handle|oneof:configuration\_change [SequenceHandle](msg_Base_SequenceHandle.md#)|Sequence for which the configuration changed|
|action\_handle|oneof:configuration\_change [ActionHandle](msg_Base_ActionHandle.md#)|Action for which the configuration changed|
|mapping\_handle|oneof:configuration\_change [MappingHandle](msg_Base_MappingHandle.md#)|Mapping for which the configuration changed|
|map\_group\_handle|oneof:configuration\_change [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Map group for which the configuration changed|
|map\_handle|oneof:configuration\_change [MapHandle](msg_Base_MapHandle.md#)|Map for which the configuration changed|
|user\_profile\_handle|oneof:configuration\_change [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User Profile for which the configuration changed|
|protection\_zone\_handle|oneof:configuration\_change [ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|Protection zone for which the configuration changed|
|safety\_handle|oneof:configuration\_change [SafetyHandle](msg_Common_SafetyHandle.md#)|Safety for which the configuration changed|
|network\_handle|oneof:configuration\_change [NetworkHandle](msg_Base_NetworkHandle.md#)|Network element for which the configuration changed|
|ssid|oneof:configuration\_change [Ssid](msg_Base_Ssid.md#)|Wi-Fi instance for which the configuration changed|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the configuration event|

**Parent topic:** [Base](../references/summary_Base.md)

