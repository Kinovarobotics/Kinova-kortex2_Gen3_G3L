# Message IPv4Information

This page describes the C++ Kinova::Api::Base::IPv4Information message.

## Overview / Purpose

Provides information about an IPv4 endpoint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|ip\_address|uint32|IPv4 address|
|subnet\_mask|uint32|IPv4 subnet mask|
|default\_gateway|uint32|Gateway IPv4 address|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|ip\_address\(\)|uint32|void|Returns the current value of ip\_address. If the ip\_address is not set, returns 0.|
|set\_ip\_address\(\)|void|uint32|Sets the value of ip\_address. After calling this, ip\_address\(\) will return value.|
|clear\_ip\_address\(\)|void|void|Clears the value of ip\_address. After calling this, ip\_address\(\) will return 0.|
|subnet\_mask\(\)|uint32|void|Returns the current value of subnet\_mask. If the subnet\_mask is not set, returns 0.|
|set\_subnet\_mask\(\)|void|uint32|Sets the value of subnet\_mask. After calling this, subnet\_mask\(\) will return value.|
|clear\_subnet\_mask\(\)|void|void|Clears the value of subnet\_mask. After calling this, subnet\_mask\(\) will return 0.|
|default\_gateway\(\)|uint32|void|Returns the current value of default\_gateway. If the default\_gateway is not set, returns 0.|
|set\_default\_gateway\(\)|void|uint32|Sets the value of default\_gateway. After calling this, default\_gateway\(\) will return value.|
|clear\_default\_gateway\(\)|void|void|Clears the value of default\_gateway. After calling this, default\_gateway\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

