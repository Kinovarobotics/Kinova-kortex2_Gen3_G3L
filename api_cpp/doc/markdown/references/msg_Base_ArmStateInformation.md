# Message ArmStateInformation

This page describes the C++ Kinova::Api::Base::ArmStateInformation message.

## Overview / Purpose

Provides information about the arm state

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|active\_state| [ArmState](enm_Common_ArmState.md#)|Arm active state|
|connection| [Connection](msg_Common_Connection.md#)|Connection information of the last processed command which triggered an arm state change|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|active\_state\(\) const| [ArmState](enm_Common_ArmState.md#)|void|Returns the current value of active\_state. If the active\_state is not set, returns 0.|
|set\_active\_state\(\)|void| [ArmState](enm_Common_ArmState.md#)|Sets the value of active\_state. After calling this, active\_state\(\) will return value.|
|clear\_active\_state\(\)|void|void|Clears the value of active\_state. After calling this, active\_state\(\) will return the empty string/empty bytes.|
|has\_connection\(\) const|bool|void|Returns true if connection is set.|
|connection\(\)|const [Connection](msg_Common_Connection.md#)&|void|Returns the current value of connection. If connection is not set, returns a [Connection](msg_Common_Connection.md#) with none of its fields set \(possibly connection::default\_instance\(\)\).|
|mutable\_connection\(\)| [Connection](msg_Common_Connection.md#) \*|void|Returns a pointer to the mutable [Connection](msg_Common_Connection.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Connection](msg_Common_Connection.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Connection](msg_Common_Connection.md#)\). After calling this, has\_connection\(\) will return true and connection\(\) will return a reference to the same instance of [Connection](msg_Common_Connection.md#).|
|clear\_connection\(\)|void|void|Clears the value of the field. After calling this, has\_connection\(\) will return false and connection\(\) will return the default value.|
|set\_allocated\_connection\(\)|void| [Connection](msg_Common_Connection.md#) \*|Sets the [Connection](msg_Common_Connection.md#) object to the field and frees the previous field value if it exists. If the [Connection](msg_Common_Connection.md#) pointer is not NULL, the message takes ownership of the allocated [Connection](msg_Common_Connection.md#) object and has\_ [Connection](msg_Common_Connection.md#)\(\) will return true. Otherwise, if the connection is NULL, the behavior is the same as calling clear\_connection\(\).|
|release\_connection\(\)| [Connection](msg_Common_Connection.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Connection](msg_Common_Connection.md#) object. After calling this, caller takes the ownership of the allocated [Connection](msg_Common_Connection.md#) object, has\_connection\(\) will return false, and connection\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

