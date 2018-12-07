# Message UserNotification

This page describes the Python Kinova.Api.Base.UserNotification message.

## Overview / Purpose

Message that contains a user event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|user\_event|int|User event type|
|modified\_user| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User profile that was modified|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the user profile event \(i.e. user who changed the user profile\)|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the user profile event \(i.e. user who changed the user profile\)|

**Parent topic:** [Base](../references/summary_Base.md)

