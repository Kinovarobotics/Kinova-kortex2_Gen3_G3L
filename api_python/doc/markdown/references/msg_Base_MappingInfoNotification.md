# Message MappingInfoNotification

This page describes the Python Kinova.Api.Base.MappingInfoNotification message.

## Overview / Purpose

Message that contains a mapping information event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|controller\_identifier|int|Identifier of the controller|
|active\_map\_handle| [MapHandle](msg_Base_MapHandle.md#)|New active map|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the mapping information event|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the mapping information event|

**Parent topic:** [Base](../references/summary_Base.md)

