# Message OperatingModeNotification

This page describes the Python Kinova.Api.Base.OperatingModeNotification message.

## Overview / Purpose

Message that contains an operating mode event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|operating\_mode|int|New operating mode|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the operating mode event|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the operating mode event|
|device\_handle| [DeviceHandle](msg_Common_DeviceHandle.md#)|Device matching operating mode \(if applicable\)|

**Parent topic:** [Base](../references/summary_Base.md)

