# Message ConstrainedJointAngles

This page describes the C++ Kinova::Api::Base::ConstrainedJointAngles message.

## Overview / Purpose

Defines a series of joint angles value with constraint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_angles| [JointAngles](msg_Base_JointAngles.md#)|Joint angles value|
|constraint| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)|Constraint to apply to all the joint angles \(optional\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_joint\_angles\(\) const|bool|void|Returns true if joint\_angles is set.|
|joint\_angles\(\)|const [JointAngles](msg_Base_JointAngles.md#)&|void|Returns the current value of joint\_angles. If joint\_angles is not set, returns a [JointAngles](msg_Base_JointAngles.md#) with none of its fields set \(possibly joint\_angles::default\_instance\(\)\).|
|mutable\_joint\_angles\(\)| [JointAngles](msg_Base_JointAngles.md#) \*|void|Returns a pointer to the mutable [JointAngles](msg_Base_JointAngles.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointAngles](msg_Base_JointAngles.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointAngles](msg_Base_JointAngles.md#)\). After calling this, has\_joint\_angles\(\) will return true and joint\_angles\(\) will return a reference to the same instance of [JointAngles](msg_Base_JointAngles.md#).|
|clear\_joint\_angles\(\)|void|void|Clears the value of the field. After calling this, has\_joint\_angles\(\) will return false and joint\_angles\(\) will return the default value.|
|set\_allocated\_joint\_angles\(\)|void| [JointAngles](msg_Base_JointAngles.md#) \*|Sets the [JointAngles](msg_Base_JointAngles.md#) object to the field and frees the previous field value if it exists. If the [JointAngles](msg_Base_JointAngles.md#) pointer is not NULL, the message takes ownership of the allocated [JointAngles](msg_Base_JointAngles.md#) object and has\_ [JointAngles](msg_Base_JointAngles.md#)\(\) will return true. Otherwise, if the joint\_angles is NULL, the behavior is the same as calling clear\_joint\_angles\(\).|
|release\_joint\_angles\(\)| [JointAngles](msg_Base_JointAngles.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointAngles](msg_Base_JointAngles.md#) object. After calling this, caller takes the ownership of the allocated [JointAngles](msg_Base_JointAngles.md#) object, has\_joint\_angles\(\) will return false, and joint\_angles\(\) will return the default value.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) \*|Sets the [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object and has\_ [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

