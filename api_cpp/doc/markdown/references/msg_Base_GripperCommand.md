# Message GripperCommand

This page describes the C++ Kinova::Api::Base::GripperCommand message.

## Overview / Purpose

Defines a command to control the gripper movement

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode|uint32|Mode in which to control the gripper|
|gripper| [Gripper](msg_Base_Gripper.md#)|In position, admissible values for each finger is between 0 and 1.0, where 0 is closed and 1.0 is fully open. In speed or torque, admissible values for each finger is between -1.0 and 1.0, where 1.0 corresponds to maximum opening speed and -1.0 corresponds to maximum closing speed. Gripper movement values|
|duration|uint32|Duration constraint. If not 0, allows to set a limit \(in seconds\) to the GripperCommand|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|has\_gripper\(\) const|bool|void|Returns true if gripper is set.|
|gripper\(\)|const [Gripper](msg_Base_Gripper.md#)&|void|Returns the current value of gripper. If gripper is not set, returns a [Gripper](msg_Base_Gripper.md#) with none of its fields set \(possibly gripper::default\_instance\(\)\).|
|mutable\_gripper\(\)| [Gripper](msg_Base_Gripper.md#) \*|void|Returns a pointer to the mutable [Gripper](msg_Base_Gripper.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Gripper](msg_Base_Gripper.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Gripper](msg_Base_Gripper.md#)\). After calling this, has\_gripper\(\) will return true and gripper\(\) will return a reference to the same instance of [Gripper](msg_Base_Gripper.md#).|
|clear\_gripper\(\)|void|void|Clears the value of the field. After calling this, has\_gripper\(\) will return false and gripper\(\) will return the default value.|
|set\_allocated\_gripper\(\)|void| [Gripper](msg_Base_Gripper.md#) \*|Sets the [Gripper](msg_Base_Gripper.md#) object to the field and frees the previous field value if it exists. If the [Gripper](msg_Base_Gripper.md#) pointer is not NULL, the message takes ownership of the allocated [Gripper](msg_Base_Gripper.md#) object and has\_ [Gripper](msg_Base_Gripper.md#)\(\) will return true. Otherwise, if the gripper is NULL, the behavior is the same as calling clear\_gripper\(\).|
|release\_gripper\(\)| [Gripper](msg_Base_Gripper.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Gripper](msg_Base_Gripper.md#) object. After calling this, caller takes the ownership of the allocated [Gripper](msg_Base_Gripper.md#) object, has\_gripper\(\) will return false, and gripper\(\) will return the default value.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

