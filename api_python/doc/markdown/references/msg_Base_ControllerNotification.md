# Message ControllerNotification

This page describes the Python Kinova.Api.Base.ControllerNotification message.

## Overview / Purpose

Message that contains a controller event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|oneof state : controller\_state| [ControllerState](msg_Base_ControllerState.md#)|Used to indicate if a controller connection or disconnection event occured|
|oneof state : controller\_element| [ControllerElementState](msg_Base_ControllerElementState.md#)|Used to indicate if a specifif button \(or axis\) was pressed \(or moved\) \(future\)|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the controller event|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the controller event|

**Parent topic:** [Base](../references/summary_Base.md)

