# Message ConstrainedOrientation

This page describes the C++ Kinova::Api::Base::ConstrainedOrientation message.

## Overview / Purpose

Defines a Cartesian orientation with constraint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|target\_orientation| [Orientation](msg_Base_Orientation.md#)|Cartesian orientation|
|constraint| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)|Constraint to apply to the target orientation|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_target\_orientation\(\) const|bool|void|Returns true if target\_orientation is set.|
|target\_orientation\(\)|const [Orientation](msg_Base_Orientation.md#)&|void|Returns the current value of target\_orientation. If target\_orientation is not set, returns a [Orientation](msg_Base_Orientation.md#) with none of its fields set \(possibly target\_orientation::default\_instance\(\)\).|
|mutable\_target\_orientation\(\)| [Orientation](msg_Base_Orientation.md#) \*|void|Returns a pointer to the mutable [Orientation](msg_Base_Orientation.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Orientation](msg_Base_Orientation.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Orientation](msg_Base_Orientation.md#)\). After calling this, has\_target\_orientation\(\) will return true and target\_orientation\(\) will return a reference to the same instance of [Orientation](msg_Base_Orientation.md#).|
|clear\_target\_orientation\(\)|void|void|Clears the value of the field. After calling this, has\_target\_orientation\(\) will return false and target\_orientation\(\) will return the default value.|
|set\_allocated\_target\_orientation\(\)|void| [Orientation](msg_Base_Orientation.md#) \*|Sets the [Orientation](msg_Base_Orientation.md#) object to the field and frees the previous field value if it exists. If the [Orientation](msg_Base_Orientation.md#) pointer is not NULL, the message takes ownership of the allocated [Orientation](msg_Base_Orientation.md#) object and has\_ [Orientation](msg_Base_Orientation.md#)\(\) will return true. Otherwise, if the target\_orientation is NULL, the behavior is the same as calling clear\_target\_orientation\(\).|
|release\_target\_orientation\(\)| [Orientation](msg_Base_Orientation.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Orientation](msg_Base_Orientation.md#) object. After calling this, caller takes the ownership of the allocated [Orientation](msg_Base_Orientation.md#) object, has\_target\_orientation\(\) will return false, and target\_orientation\(\) will return the default value.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) \*|Sets the [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object and has\_ [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

