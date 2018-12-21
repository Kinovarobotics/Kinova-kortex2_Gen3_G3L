# Message ConstrainedJointAngle

This page describes the C++ Kinova::Api::Base::ConstrainedJointAngle message.

## Overview / Purpose

Defines a single joint angle value with constraint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_identifier|uint32|Joint identifier \(use device\_identifier\)|
|value|float32|Joint value \(in degrees\)|
|constraint| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)|Constraint to apply to the joint angle \(optional\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|joint\_identifier\(\)|uint32|void|Returns the current value of joint\_identifier. If the joint\_identifier is not set, returns 0.|
|set\_joint\_identifier\(\)|void|uint32|Sets the value of joint\_identifier. After calling this, joint\_identifier\(\) will return value.|
|clear\_joint\_identifier\(\)|void|void|Clears the value of joint\_identifier. After calling this, joint\_identifier\(\) will return 0.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) \*|Sets the [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object and has\_ [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

