# Message SafetyInformation

This page describes the Python Kinova.Api.DeviceConfig.SafetyInformation message.

## Overview / Purpose

Information about a particular safety

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SafetyHandle](msg_Common_SafetyHandle.md#)|Safety handle that this information is about|
|can\_change\_safety\_state|bool|True if related safety configuration can be modified|
|has\_warning\_threshold|bool|True if safety status can go in Warning|
|has\_error\_threshold|bool|True if safety status can go in Error|
|limit\_type| [SafetyLimitType](enm_DeviceConfig_SafetyLimitType.md#)|Safety limit type|
|default\_warning\_threshold|float|Default warning threshold \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT and 'has\_warning\_threshold' is true\)|
|default\_error\_threshold|float|Default error threshold \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT and 'has\_error\_threshold' is true\)|
|upper\_hard\_limit|float|Maximal threshold value \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT\)|
|lower\_hard\_limit|float|Minimal threshold value \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT\)|
|status| [SafetyStatusValue](enm_Common_SafetyStatusValue.md#)|Current Safety status|
|unit| [Unit](enm_Common_Unit.md#)|Unit that the safety status is in|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

