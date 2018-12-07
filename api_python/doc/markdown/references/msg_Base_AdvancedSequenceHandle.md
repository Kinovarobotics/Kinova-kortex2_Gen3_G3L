# Message AdvancedSequenceHandle

This page describes the Python Kinova.Api.Base.AdvancedSequenceHandle message.

## Overview / Purpose

Associates execution options to a sequence

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SequenceHandle](msg_Base_SequenceHandle.md#)|Sequence handle|
|in\_loop|bool|Loop execution. Set to true to play the sequence in loop, false otherwise. When a sequence is executed in loop, it will automatically go back to first task within the sequence after completing execution of last task and continue execution forever unless the sequence is explicitely stopped|

**Parent topic:** [Base](../references/summary_Base.md)

