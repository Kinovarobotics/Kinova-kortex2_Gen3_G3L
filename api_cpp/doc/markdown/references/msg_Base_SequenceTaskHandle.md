# Message SequenceTaskHandle

This page describes the C++ Kinova::Api::Base::SequenceTaskHandle message.

## Overview / Purpose

Identifies a task inside a sequence

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_handle| [SequenceHandle](msg_Base_SequenceHandle.md#)|Sequence handle|
|task\_index|uint32|Task index inside the sequence|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_sequence\_handle\(\) const|bool|void|Returns true if sequence\_handle is set.|
|sequence\_handle\(\)|const [SequenceHandle](msg_Base_SequenceHandle.md#)&|void|Returns the current value of sequence\_handle. If sequence\_handle is not set, returns a [SequenceHandle](msg_Base_SequenceHandle.md#) with none of its fields set \(possibly sequence\_handle::default\_instance\(\)\).|
|mutable\_sequence\_handle\(\)| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|void|Returns a pointer to the mutable [SequenceHandle](msg_Base_SequenceHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceHandle](msg_Base_SequenceHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceHandle](msg_Base_SequenceHandle.md#)\). After calling this, has\_sequence\_handle\(\) will return true and sequence\_handle\(\) will return a reference to the same instance of [SequenceHandle](msg_Base_SequenceHandle.md#).|
|clear\_sequence\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_sequence\_handle\(\) will return false and sequence\_handle\(\) will return the default value.|
|set\_allocated\_sequence\_handle\(\)|void| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|Sets the [SequenceHandle](msg_Base_SequenceHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceHandle](msg_Base_SequenceHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceHandle](msg_Base_SequenceHandle.md#) object and has\_ [SequenceHandle](msg_Base_SequenceHandle.md#)\(\) will return true. Otherwise, if the sequence\_handle is NULL, the behavior is the same as calling clear\_sequence\_handle\(\).|
|release\_sequence\_handle\(\)| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceHandle](msg_Base_SequenceHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceHandle](msg_Base_SequenceHandle.md#) object, has\_sequence\_handle\(\) will return false, and sequence\_handle\(\) will return the default value.|
|task\_index\(\)|uint32|void|Returns the current value of task\_index. If the task\_index is not set, returns 0.|
|set\_task\_index\(\)|void|uint32|Sets the value of task\_index. After calling this, task\_index\(\) will return value.|
|clear\_task\_index\(\)|void|void|Clears the value of task\_index. After calling this, task\_index\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

