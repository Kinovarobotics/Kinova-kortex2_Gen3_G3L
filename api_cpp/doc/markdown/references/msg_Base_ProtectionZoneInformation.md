# Message ProtectionZoneInformation

This page describes the C++ Kinova::Api::Base::ProtectionZoneInformation message.

## Overview / Purpose

Provides information about a protection zone

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event| [ProtectionZoneEvent](enm_Base_ProtectionZoneEvent.md#)|Event type|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|event\(\) const| [ProtectionZoneEvent](enm_Base_ProtectionZoneEvent.md#)|void|Returns the current value of event. If the event is not set, returns 0.|
|set\_event\(\)|void| [ProtectionZoneEvent](enm_Base_ProtectionZoneEvent.md#)|Sets the value of event. After calling this, event\(\) will return value.|
|clear\_event\(\)|void|void|Clears the value of event. After calling this, event\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

