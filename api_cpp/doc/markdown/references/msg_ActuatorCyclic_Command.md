# Message Command

This page describes the C++ Kinova::Api::ActuatorCyclic::Command message.

## Overview / Purpose

Defines an actuator module command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id| [MessageId](msg_ActuatorCyclic_MessageId.md#)|MessageId|
|flags|uint32|Command flags \(see enum CommandFlags\)|
|position|float32|Desired position of the actuator \(degrees\)|
|velocity|float32|Desired velocity of the actuator \(degrees per second\)|
|torque\_joint|float32|Desired torque of the actuator \(Newton-meters\)|
|current\_motor|float32|Desired current of the motor \(Amperes\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_command\_id\(\) const|bool|void|Returns true if command\_id is set.|
|command\_id\(\)|const [MessageId](msg_ActuatorCyclic_MessageId.md#)&|void|Returns the current value of command\_id. If command\_id is not set, returns a [MessageId](msg_ActuatorCyclic_MessageId.md#) with none of its fields set \(possibly command\_id::default\_instance\(\)\).|
|mutable\_command\_id\(\)| [MessageId](msg_ActuatorCyclic_MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](msg_ActuatorCyclic_MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](msg_ActuatorCyclic_MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](msg_ActuatorCyclic_MessageId.md#)\). After calling this, has\_command\_id\(\) will return true and command\_id\(\) will return a reference to the same instance of [MessageId](msg_ActuatorCyclic_MessageId.md#).|
|clear\_command\_id\(\)|void|void|Clears the value of the field. After calling this, has\_command\_id\(\) will return false and command\_id\(\) will return the default value.|
|set\_allocated\_command\_id\(\)|void| [MessageId](msg_ActuatorCyclic_MessageId.md#) \*|Sets the [MessageId](msg_ActuatorCyclic_MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](msg_ActuatorCyclic_MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](msg_ActuatorCyclic_MessageId.md#) object and has\_ [MessageId](msg_ActuatorCyclic_MessageId.md#)\(\) will return true. Otherwise, if the command\_id is NULL, the behavior is the same as calling clear\_command\_id\(\).|
|release\_command\_id\(\)| [MessageId](msg_ActuatorCyclic_MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](msg_ActuatorCyclic_MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](msg_ActuatorCyclic_MessageId.md#) object, has\_command\_id\(\) will return false, and command\_id\(\) will return the default value.|
|flags\(\)|uint32|void|Returns the current value of flags. If the flags is not set, returns 0.|
|set\_flags\(\)|void|uint32|Sets the value of flags. After calling this, flags\(\) will return value.|
|clear\_flags\(\)|void|void|Clears the value of flags. After calling this, flags\(\) will return 0.|
|position\(\)|float32|void|Returns the current value of position. If the position is not set, returns 0.|
|set\_position\(\)|void|float32|Sets the value of position. After calling this, position\(\) will return value.|
|clear\_position\(\)|void|void|Clears the value of position. After calling this, position\(\) will return 0.|
|velocity\(\)|float32|void|Returns the current value of velocity. If the velocity is not set, returns 0.|
|set\_velocity\(\)|void|float32|Sets the value of velocity. After calling this, velocity\(\) will return value.|
|clear\_velocity\(\)|void|void|Clears the value of velocity. After calling this, velocity\(\) will return 0.|
|torque\_joint\(\)|float32|void|Returns the current value of torque\_joint. If the torque\_joint is not set, returns 0.|
|set\_torque\_joint\(\)|void|float32|Sets the value of torque\_joint. After calling this, torque\_joint\(\) will return value.|
|clear\_torque\_joint\(\)|void|void|Clears the value of torque\_joint. After calling this, torque\_joint\(\) will return 0.|
|current\_motor\(\)|float32|void|Returns the current value of current\_motor. If the current\_motor is not set, returns 0.|
|set\_current\_motor\(\)|void|float32|Sets the value of current\_motor. After calling this, current\_motor\(\) will return value.|
|clear\_current\_motor\(\)|void|void|Clears the value of current\_motor. After calling this, current\_motor\(\) will return 0.|

**Parent topic:** [ActuatorCyclic](../references/summary_ActuatorCyclic.md)

