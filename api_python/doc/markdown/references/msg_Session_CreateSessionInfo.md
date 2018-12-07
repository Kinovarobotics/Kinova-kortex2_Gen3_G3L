# Message CreateSessionInfo

This page describes the Python Kinova.Api.Session.CreateSessionInfo message.

## Overview / Purpose

Contains parameters to create a new session

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|username|str|User name|
|session\_inactivity\_timeout|int|Inactivity period \(in millisecond\) allowed before the session times out and closes on its own|
|password|str|Password for the user|
|connection\_inactivity\_timeout|int|Inactivity period \(in millisecond\) allowed before the robot stops any movement initiated from this session|

**Parent topic:** [Session](../references/summary_Session.md)

