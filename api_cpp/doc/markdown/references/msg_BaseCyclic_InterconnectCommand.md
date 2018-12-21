# Message InterconnectCommand

This page describes the C++ Kinova::Api::BaseCyclic::InterconnectCommand message.

## Overview / Purpose

Defines an interconnect module command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id|uint32|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|
|flags|uint32|Flags|
|position|float32|Desired position of the gripper fingers \(0-100%\)|
|velocity|float32|Desired velocity of the gripper fingers \(0-100%\)|
|force|float32|Desired force of the gripper fingers \(0-100%\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|command\_id\(\)|uint32|void|Returns the current value of command\_id. If the command\_id is not set, returns 0.|
|set\_command\_id\(\)|void|uint32|Sets the value of command\_id. After calling this, command\_id\(\) will return value.|
|clear\_command\_id\(\)|void|void|Clears the value of command\_id. After calling this, command\_id\(\) will return 0.|
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

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

