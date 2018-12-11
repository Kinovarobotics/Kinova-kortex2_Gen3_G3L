# Message RobotEventNotification

This page describes the Python Kinova.Api.Base.RobotEventNotification message.

## Overview / Purpose

Message that contains a robot event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event| [RobotEvent](enm_Base_RobotEvent.md#)|Robot event type|
|handle| [DeviceHandle](msg_Common_DeviceHandle.md#)|Identifier of the hardware device connected or disconnected|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the robot event to occur|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the robot event to occur|

**Parent topic:** [Base](../references/summary_Base.md)

