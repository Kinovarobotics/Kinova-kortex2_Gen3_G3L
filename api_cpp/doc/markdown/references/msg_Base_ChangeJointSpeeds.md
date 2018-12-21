# Message ChangeJointSpeeds

This page describes the C++ Kinova::Api::Base::ChangeJointSpeeds message.

## Overview / Purpose

Defines an action to increase \(or reduce\) the maximum angular velocity per joint by a specific increment

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_speeds| [JointSpeeds](msg_Base_JointSpeeds.md#)|Joint speeds|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_joint\_speeds\(\) const|bool|void|Returns true if joint\_speeds is set.|
|joint\_speeds\(\)|const [JointSpeeds](msg_Base_JointSpeeds.md#)&|void|Returns the current value of joint\_speeds. If joint\_speeds is not set, returns a [JointSpeeds](msg_Base_JointSpeeds.md#) with none of its fields set \(possibly joint\_speeds::default\_instance\(\)\).|
|mutable\_joint\_speeds\(\)| [JointSpeeds](msg_Base_JointSpeeds.md#) \*|void|Returns a pointer to the mutable [JointSpeeds](msg_Base_JointSpeeds.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointSpeeds](msg_Base_JointSpeeds.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointSpeeds](msg_Base_JointSpeeds.md#)\). After calling this, has\_joint\_speeds\(\) will return true and joint\_speeds\(\) will return a reference to the same instance of [JointSpeeds](msg_Base_JointSpeeds.md#).|
|clear\_joint\_speeds\(\)|void|void|Clears the value of the field. After calling this, has\_joint\_speeds\(\) will return false and joint\_speeds\(\) will return the default value.|
|set\_allocated\_joint\_speeds\(\)|void| [JointSpeeds](msg_Base_JointSpeeds.md#) \*|Sets the [JointSpeeds](msg_Base_JointSpeeds.md#) object to the field and frees the previous field value if it exists. If the [JointSpeeds](msg_Base_JointSpeeds.md#) pointer is not NULL, the message takes ownership of the allocated [JointSpeeds](msg_Base_JointSpeeds.md#) object and has\_ [JointSpeeds](msg_Base_JointSpeeds.md#)\(\) will return true. Otherwise, if the joint\_speeds is NULL, the behavior is the same as calling clear\_joint\_speeds\(\).|
|release\_joint\_speeds\(\)| [JointSpeeds](msg_Base_JointSpeeds.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointSpeeds](msg_Base_JointSpeeds.md#) object. After calling this, caller takes the ownership of the allocated [JointSpeeds](msg_Base_JointSpeeds.md#) object, has\_joint\_speeds\(\) will return false, and joint\_speeds\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

