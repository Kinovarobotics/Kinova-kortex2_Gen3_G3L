# Message ProtectionZoneHandle

This page describes the C++ Kinova::Api::Base::ProtectionZoneHandle message.

## Overview / Purpose

Identifies a protection zone

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|Protection zone identifier|
|permission|uint32|Permission of specified Proctection zone entity. Must use 'Kinova.Api.Common.Permission' enum.|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|identifier\(\)|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return 0.|
|permission\(\)|uint32|void|Returns the current value of permission. If the permission is not set, returns 0.|
|set\_permission\(\)|void|uint32|Sets the value of permission. After calling this, permission\(\) will return value.|
|clear\_permission\(\)|void|void|Clears the value of permission. After calling this, permission\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

