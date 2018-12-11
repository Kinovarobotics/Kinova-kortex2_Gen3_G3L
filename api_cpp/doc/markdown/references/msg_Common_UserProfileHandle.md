# Message UserProfileHandle

This page describes the C++ Kinova::Api::Common::UserProfileHandle message.

## Overview / Purpose

Identifies a user profile

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|User profile identifier|
|permission|uint32|Must use 'Permission' as bitwise|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|identifier\(\)|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return 0.|
|permission\(\)|uint32|void|Returns the current value of permission. If the permission is not set, returns 0.|
|set\_permission\(\)|void|uint32|Sets the value of permission. After calling this, permission\(\) will return value.|
|clear\_permission\(\)|void|void|Clears the value of permission. After calling this, permission\(\) will return 0.|

**Parent topic:** [Common](../references/summary_Common.md)

