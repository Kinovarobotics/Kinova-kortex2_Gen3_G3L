# Message SequenceInfoNotification

This page describes the Python Kinova.Api.Base.SequenceInfoNotification message.

## Overview / Purpose

Message that contains a sequence information event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event\_identifier|int|Sequence event type|
|sequence\_handle| [SequenceHandle](msg_Base_SequenceHandle.md#)|Handle of the sequence that this event refers to|
|task\_index|int|Task index|
|group\_identifier|int|Specifies the order in which this task must be executed|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the sequence event|
|abort\_details|int|Details if event\_identifier is equal to ABORT|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the sequence event|

**Parent topic:** [Base](../references/summary_Base.md)

