# Message TwistCommand

This page describes the C++ Kinova::Api::Base::TwistCommand message.

## Overview / Purpose

Defines a twist \(velocity\) command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode| [TwistMode](enm_Base_TwistMode.md#)|Mode in which the command is executed|
|twist| [Twist](msg_Base_Twist.md#)|Twist value|
|duration|uint32|Duration constrant. If not 0, allows to set a limit \(in seconds\) to the TwistCommand \(future\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|mode\(\) const| [TwistMode](enm_Base_TwistMode.md#)|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void| [TwistMode](enm_Base_TwistMode.md#)|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|has\_twist\(\) const|bool|void|Returns true if twist is set.|
|twist\(\)|const [Twist](msg_Base_Twist.md#)&|void|Returns the current value of twist. If twist is not set, returns a [Twist](msg_Base_Twist.md#) with none of its fields set \(possibly twist::default\_instance\(\)\).|
|mutable\_twist\(\)| [Twist](msg_Base_Twist.md#) \*|void|Returns a pointer to the mutable [Twist](msg_Base_Twist.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Twist](msg_Base_Twist.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Twist](msg_Base_Twist.md#)\). After calling this, has\_twist\(\) will return true and twist\(\) will return a reference to the same instance of [Twist](msg_Base_Twist.md#).|
|clear\_twist\(\)|void|void|Clears the value of the field. After calling this, has\_twist\(\) will return false and twist\(\) will return the default value.|
|set\_allocated\_twist\(\)|void| [Twist](msg_Base_Twist.md#) \*|Sets the [Twist](msg_Base_Twist.md#) object to the field and frees the previous field value if it exists. If the [Twist](msg_Base_Twist.md#) pointer is not NULL, the message takes ownership of the allocated [Twist](msg_Base_Twist.md#) object and has\_ [Twist](msg_Base_Twist.md#)\(\) will return true. Otherwise, if the twist is NULL, the behavior is the same as calling clear\_twist\(\).|
|release\_twist\(\)| [Twist](msg_Base_Twist.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Twist](msg_Base_Twist.md#) object. After calling this, caller takes the ownership of the allocated [Twist](msg_Base_Twist.md#) object, has\_twist\(\) will return false, and twist\(\) will return the default value.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

