# Message ActionNotification

This page describes the Python Kinova.Api.Base.ActionNotification message.

## Overview / Purpose

Message that contains an action event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|action\_event|int|Action event type|
|handle| [ActionHandle](msg_Base_ActionHandle.md#)|Identifies the action for which this event occured|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the action event|
|abort\_details|int|Details if action\_event is equal to ACTION\_ABORT|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the action event|

**Parent topic:** [Base](../references/summary_Base.md)

