# Message CommunicationInterfaceConfiguration

This page describes the C++ Kinova::Api::Base::CommunicationInterfaceConfiguration message.

## Overview / Purpose

Enables or disables a specific communication interface \(e.g. Wi-Fi, Wired Ethernet\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type| [NetworkType](enm_Base_NetworkType.md#)|Network type \(e.g. Wi-Fi, Wired Ethernet\)|
|enable|bool|Enable configuration. Set to true to enable network, false otherwise|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|type\(\) const| [NetworkType](enm_Base_NetworkType.md#)|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void| [NetworkType](enm_Base_NetworkType.md#)|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|enable\(\)|bool|void|Returns the current value of enable. If the enable is not set, returns 0.|
|set\_enable\(\)|void|bool|Sets the value of enable. After calling this, enable\(\) will return value.|
|clear\_enable\(\)|void|void|Clears the value of enable. After calling this, enable\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

