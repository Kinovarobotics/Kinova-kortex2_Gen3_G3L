# Message ConstrainedPose

This page describes the C++ Kinova::Api::Base::ConstrainedPose message.

## Overview / Purpose

Defines a Cartesian pose with constraint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|target\_pose| [Pose](msg_Base_Pose.md#)|Cartesian pose|
|constraint| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)|Constraint to apply to the target pose|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_target\_pose\(\) const|bool|void|Returns true if target\_pose is set.|
|target\_pose\(\)|const [Pose](msg_Base_Pose.md#)&|void|Returns the current value of target\_pose. If target\_pose is not set, returns a [Pose](msg_Base_Pose.md#) with none of its fields set \(possibly target\_pose::default\_instance\(\)\).|
|mutable\_target\_pose\(\)| [Pose](msg_Base_Pose.md#) \*|void|Returns a pointer to the mutable [Pose](msg_Base_Pose.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Pose](msg_Base_Pose.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Pose](msg_Base_Pose.md#)\). After calling this, has\_target\_pose\(\) will return true and target\_pose\(\) will return a reference to the same instance of [Pose](msg_Base_Pose.md#).|
|clear\_target\_pose\(\)|void|void|Clears the value of the field. After calling this, has\_target\_pose\(\) will return false and target\_pose\(\) will return the default value.|
|set\_allocated\_target\_pose\(\)|void| [Pose](msg_Base_Pose.md#) \*|Sets the [Pose](msg_Base_Pose.md#) object to the field and frees the previous field value if it exists. If the [Pose](msg_Base_Pose.md#) pointer is not NULL, the message takes ownership of the allocated [Pose](msg_Base_Pose.md#) object and has\_ [Pose](msg_Base_Pose.md#)\(\) will return true. Otherwise, if the target\_pose is NULL, the behavior is the same as calling clear\_target\_pose\(\).|
|release\_target\_pose\(\)| [Pose](msg_Base_Pose.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Pose](msg_Base_Pose.md#) object. After calling this, caller takes the ownership of the allocated [Pose](msg_Base_Pose.md#) object, has\_target\_pose\(\) will return false, and target\_pose\(\) will return the default value.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) \*|Sets the [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object and has\_ [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [CartesianTrajectoryConstraint](msg_Base_CartesianTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

