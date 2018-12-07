# Message ProtectionZoneNotification

This page describes the Python Kinova.Api.Base.ProtectionZoneNotification message.

## Overview / Purpose

Message that contains a protection zone event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event|int|Event type|
|handle| [ProtectionZoneHandle](msg_Base_ProtectionZoneHandle.md#)|Handle of the protection zone that this event refers to|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the protection zone event to occur|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the protection zone event to occur|

**Parent topic:** [Base](../references/summary_Base.md)

