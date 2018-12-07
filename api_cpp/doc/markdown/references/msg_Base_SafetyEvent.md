# Message SafetyEvent

This page describes the C++ Kinova::Api::Base::SafetyEvent message.

## Overview / Purpose

Identifies a Safety event \(future\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|safety\_handle| [SafetyHandle](msg_Common_SafetyHandle.md#)|Safety that caused the event to occur|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_safety\_handle\(\) const|bool|void|Returns true if safety\_handle is set.|
|safety\_handle\(\)|const [SafetyHandle](msg_Common_SafetyHandle.md#)&|void|Returns the current value of safety\_handle. If safety\_handle is not set, returns a [SafetyHandle](msg_Common_SafetyHandle.md#) with none of its fields set \(possibly safety\_handle::default\_instance\(\)\).|
|mutable\_safety\_handle\(\)| [SafetyHandle](msg_Common_SafetyHandle.md#) \*|void|Returns a pointer to the mutable [SafetyHandle](msg_Common_SafetyHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyHandle](msg_Common_SafetyHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyHandle](msg_Common_SafetyHandle.md#)\). After calling this, has\_safety\_handle\(\) will return true and safety\_handle\(\) will return a reference to the same instance of [SafetyHandle](msg_Common_SafetyHandle.md#).|
|clear\_safety\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_safety\_handle\(\) will return false and safety\_handle\(\) will return the default value.|
|set\_allocated\_safety\_handle\(\)|void| [SafetyHandle](msg_Common_SafetyHandle.md#) \*|Sets the [SafetyHandle](msg_Common_SafetyHandle.md#) object to the field and frees the previous field value if it exists. If the [SafetyHandle](msg_Common_SafetyHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyHandle](msg_Common_SafetyHandle.md#) object and has\_ [SafetyHandle](msg_Common_SafetyHandle.md#)\(\) will return true. Otherwise, if the safety\_handle is NULL, the behavior is the same as calling clear\_safety\_handle\(\).|
|release\_safety\_handle\(\)| [SafetyHandle](msg_Common_SafetyHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyHandle](msg_Common_SafetyHandle.md#) object. After calling this, caller takes the ownership of the allocated [SafetyHandle](msg_Common_SafetyHandle.md#) object, has\_safety\_handle\(\) will return false, and safety\_handle\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

