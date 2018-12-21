# Message SafetyNotification

This page describes the Python Kinova.Api.Common.SafetyNotification message.

## Overview / Purpose

Message that contains a safety event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|safety\_handle| [SafetyHandle](msg_Common_SafetyHandle.md#)|Safety handle|
|value| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|New safety status|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the safety event|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the safety event|

**Parent topic:** [Common](../references/summary_Common.md)

