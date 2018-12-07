# Message TwistCommand

This page describes the Python Kinova.Api.Base.TwistCommand message.

## Overview / Purpose

Defines a twist \(velocity\) command

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode|int|Mode in which the command is executed|
|twist| [Twist](msg_Base_Twist.md#)|Twist value|
|duration|int|Duration constrant. If not 0, allows to set a limit \(in seconds\) to the TwistCommand \(future\)|

**Parent topic:** [Base](../references/summary_Base.md)

