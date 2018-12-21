# Message Command

This page describes the C++ Kinova::Api::InterconnectCyclic::Command message.

## Overview / Purpose

Defines an interconnect module command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id| [MessageId](msg_InterconnectCyclic_MessageId.md#)|MessageId|
|flags|uint32|Flags|
|position|float32|Desired position of the gripper fingers \(0-100%\)|
|velocity|float32|Desired velocity of the gripper fingers \(0-100%\)|
|force|float32|Desired force of the gripper fingers \(0-100%\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_command\_id\(\) const|bool|void|Returns true if command\_id is set.|
|command\_id\(\)|const [MessageId](msg_InterconnectCyclic_MessageId.md#)&|void|Returns the current value of command\_id. If command\_id is not set, returns a [MessageId](msg_InterconnectCyclic_MessageId.md#) with none of its fields set \(possibly command\_id::default\_instance\(\)\).|
|mutable\_command\_id\(\)| [MessageId](msg_InterconnectCyclic_MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](msg_InterconnectCyclic_MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](msg_InterconnectCyclic_MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](msg_InterconnectCyclic_MessageId.md#)\). After calling this, has\_command\_id\(\) will return true and command\_id\(\) will return a reference to the same instance of [MessageId](msg_InterconnectCyclic_MessageId.md#).|
|clear\_command\_id\(\)|void|void|Clears the value of the field. After calling this, has\_command\_id\(\) will return false and command\_id\(\) will return the default value.|
|set\_allocated\_command\_id\(\)|void| [MessageId](msg_InterconnectCyclic_MessageId.md#) \*|Sets the [MessageId](msg_InterconnectCyclic_MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](msg_InterconnectCyclic_MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](msg_InterconnectCyclic_MessageId.md#) object and has\_ [MessageId](msg_InterconnectCyclic_MessageId.md#)\(\) will return true. Otherwise, if the command\_id is NULL, the behavior is the same as calling clear\_command\_id\(\).|
|release\_command\_id\(\)| [MessageId](msg_InterconnectCyclic_MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](msg_InterconnectCyclic_MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](msg_InterconnectCyclic_MessageId.md#) object, has\_command\_id\(\) will return false, and command\_id\(\) will return the default value.|
|flags\(\)|uint32|void|Returns the current value of flags. If the flags is not set, returns 0.|
|set\_flags\(\)|void|uint32|Sets the value of flags. After calling this, flags\(\) will return value.|
|clear\_flags\(\)|void|void|Clears the value of flags. After calling this, flags\(\) will return 0.|
|position\(\)|float32|void|Returns the current value of position. If the position is not set, returns 0.|
|set\_position\(\)|void|float32|Sets the value of position. After calling this, position\(\) will return value.|
|clear\_position\(\)|void|void|Clears the value of position. After calling this, position\(\) will return 0.|
|velocity\(\)|float32|void|Returns the current value of velocity. If the velocity is not set, returns 0.|
|set\_velocity\(\)|void|float32|Sets the value of velocity. After calling this, velocity\(\) will return value.|
|clear\_velocity\(\)|void|void|Clears the value of velocity. After calling this, velocity\(\) will return 0.|
|force\(\)|float32|void|Returns the current value of force. If the force is not set, returns 0.|
|set\_force\(\)|void|float32|Sets the value of force. After calling this, force\(\) will return value.|
|clear\_force\(\)|void|void|Clears the value of force. After calling this, force\(\) will return 0.|

**Parent topic:** [InterconnectCyclic](../references/summary_InterconnectCyclic.md)

