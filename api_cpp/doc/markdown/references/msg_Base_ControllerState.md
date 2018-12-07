# Message ControllerState

This page describes the C++ Kinova::Api::Base::ControllerState message.

## Overview / Purpose

Indicates if a controller is connected \(or disconnected\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [ControllerHandle](msg_Base_ControllerHandle.md#)|Controller identifier|
|event\_type|uint32|Type of controller event that occured|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [ControllerHandle](msg_Base_ControllerHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [ControllerHandle](msg_Base_ControllerHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [ControllerHandle](msg_Base_ControllerHandle.md#) \*|void|Returns a pointer to the mutable [ControllerHandle](msg_Base_ControllerHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ControllerHandle](msg_Base_ControllerHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerHandle](msg_Base_ControllerHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [ControllerHandle](msg_Base_ControllerHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [ControllerHandle](msg_Base_ControllerHandle.md#) \*|Sets the [ControllerHandle](msg_Base_ControllerHandle.md#) object to the field and frees the previous field value if it exists. If the [ControllerHandle](msg_Base_ControllerHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ControllerHandle](msg_Base_ControllerHandle.md#) object and has\_ [ControllerHandle](msg_Base_ControllerHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [ControllerHandle](msg_Base_ControllerHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ControllerHandle](msg_Base_ControllerHandle.md#) object. After calling this, caller takes the ownership of the allocated [ControllerHandle](msg_Base_ControllerHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|event\_type\(\) const|uint32|void|Returns the current value of event\_type. If the event\_type is not set, returns 0.|
|set\_event\_type\(\)|void|uint32|Sets the value of event\_type. After calling this, event\_type\(\) will return value.|
|clear\_event\_type\(\)|void|void|Clears the value of event\_type. After calling this, event\_type\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base](../references/summary_Base.md)

