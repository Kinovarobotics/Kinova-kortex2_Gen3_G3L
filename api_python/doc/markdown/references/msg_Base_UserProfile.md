# Message UserProfile

This page describes the Python Kinova.Api.Base.UserProfile message.

## Overview / Purpose

Provides information about a user

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User handle \(no need to set it with CreateUserProfile\(\)|
|username|str|Username, which is used to connect to robot \(or login via Web App\)|
|firstname|str|User's first name|
|lastname|str|User's last name|
|application\_data|str|Application data \(reserved for use by Web App\)|

**Parent topic:** [Base](../references/summary_Base.md)

