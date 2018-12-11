# Message FullIPv4Configuration

This page describes the C++ Kinova::Api::Base::FullIPv4Configuration message.

## Overview / Purpose

Provides an IPv4 configuration for a specific network

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [NetworkHandle](msg_Base_NetworkHandle.md#)|Network handle|
|ipv4\_configuration| [IPv4Configuration](msg_Base_IPv4Configuration.md#)|IPv4 configuration|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [NetworkHandle](msg_Base_NetworkHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [NetworkHandle](msg_Base_NetworkHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [NetworkHandle](msg_Base_NetworkHandle.md#) \*|void|Returns a pointer to the mutable [NetworkHandle](msg_Base_NetworkHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [NetworkHandle](msg_Base_NetworkHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [NetworkHandle](msg_Base_NetworkHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [NetworkHandle](msg_Base_NetworkHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [NetworkHandle](msg_Base_NetworkHandle.md#) \*|Sets the [NetworkHandle](msg_Base_NetworkHandle.md#) object to the field and frees the previous field value if it exists. If the [NetworkHandle](msg_Base_NetworkHandle.md#) pointer is not NULL, the message takes ownership of the allocated [NetworkHandle](msg_Base_NetworkHandle.md#) object and has\_ [NetworkHandle](msg_Base_NetworkHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [NetworkHandle](msg_Base_NetworkHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [NetworkHandle](msg_Base_NetworkHandle.md#) object. After calling this, caller takes the ownership of the allocated [NetworkHandle](msg_Base_NetworkHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|has\_ipv4\_configuration\(\) const|bool|void|Returns true if ipv4\_configuration is set.|
|ipv4\_configuration\(\)|const [IPv4Configuration](msg_Base_IPv4Configuration.md#)&|void|Returns the current value of ipv4\_configuration. If ipv4\_configuration is not set, returns a [IPv4Configuration](msg_Base_IPv4Configuration.md#) with none of its fields set \(possibly ipv4\_configuration::default\_instance\(\)\).|
|mutable\_ipv4\_configuration\(\)| [IPv4Configuration](msg_Base_IPv4Configuration.md#) \*|void|Returns a pointer to the mutable [IPv4Configuration](msg_Base_IPv4Configuration.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [IPv4Configuration](msg_Base_IPv4Configuration.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [IPv4Configuration](msg_Base_IPv4Configuration.md#)\). After calling this, has\_ipv4\_configuration\(\) will return true and ipv4\_configuration\(\) will return a reference to the same instance of [IPv4Configuration](msg_Base_IPv4Configuration.md#).|
|clear\_ipv4\_configuration\(\)|void|void|Clears the value of the field. After calling this, has\_ipv4\_configuration\(\) will return false and ipv4\_configuration\(\) will return the default value.|
|set\_allocated\_ipv4\_configuration\(\)|void| [IPv4Configuration](msg_Base_IPv4Configuration.md#) \*|Sets the [IPv4Configuration](msg_Base_IPv4Configuration.md#) object to the field and frees the previous field value if it exists. If the [IPv4Configuration](msg_Base_IPv4Configuration.md#) pointer is not NULL, the message takes ownership of the allocated [IPv4Configuration](msg_Base_IPv4Configuration.md#) object and has\_ [IPv4Configuration](msg_Base_IPv4Configuration.md#)\(\) will return true. Otherwise, if the ipv4\_configuration is NULL, the behavior is the same as calling clear\_ipv4\_configuration\(\).|
|release\_ipv4\_configuration\(\)| [IPv4Configuration](msg_Base_IPv4Configuration.md#) \*|void|Releases the ownership of the field and returns the pointer of the [IPv4Configuration](msg_Base_IPv4Configuration.md#) object. After calling this, caller takes the ownership of the allocated [IPv4Configuration](msg_Base_IPv4Configuration.md#) object, has\_ipv4\_configuration\(\) will return false, and ipv4\_configuration\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

