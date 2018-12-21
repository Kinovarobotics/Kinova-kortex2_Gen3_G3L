# Message ConstrainedJointAngle

This page describes the Python Kinova.Api.Base.ConstrainedJointAngle message.

## Overview / Purpose

Defines a single joint angle value with constraint

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_identifier|int|Joint identifier \(use device\_identifier\)|
|value|float|Joint value \(in degrees\)|
|constraint| [JointTrajectoryConstraint](msg_Base_JointTrajectoryConstraint.md#)|Constraint to apply to the joint angle \(optional\)|

**Parent topic:** [Base](../references/summary_Base.md)

