# Message AdvancedSequenceHandle

This page describes the C++ Kinova::Api::Base::AdvancedSequenceHandle message.

## Overview / Purpose

Associates execution options to a sequence

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SequenceHandle](msg_Base_SequenceHandle.md#)|Sequence handle|
|in\_loop|bool|Loop execution. Set to true to play the sequence in loop, false otherwise. When a sequence is executed in loop, it will automatically go back to first task within the sequence after completing execution of last task and continue execution forever unless the sequence is explicitely stopped|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [SequenceHandle](msg_Base_SequenceHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [SequenceHandle](msg_Base_SequenceHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|void|Returns a pointer to the mutable [SequenceHandle](msg_Base_SequenceHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceHandle](msg_Base_SequenceHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceHandle](msg_Base_SequenceHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [SequenceHandle](msg_Base_SequenceHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|Sets the [SequenceHandle](msg_Base_SequenceHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceHandle](msg_Base_SequenceHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceHandle](msg_Base_SequenceHandle.md#) object and has\_ [SequenceHandle](msg_Base_SequenceHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceHandle](msg_Base_SequenceHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceHandle](msg_Base_SequenceHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|in\_loop\(\)|bool|void|Returns the current value of in\_loop. If the in\_loop is not set, returns 0.|
|set\_in\_loop\(\)|void|bool|Sets the value of in\_loop. After calling this, in\_loop\(\) will return value.|
|clear\_in\_loop\(\)|void|void|Clears the value of in\_loop. After calling this, in\_loop\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

