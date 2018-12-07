# Message ControllerElementHandle

This page describes the C++ Kinova::Api::Base::ControllerElementHandle message.

## Overview / Purpose

Identifies a specific button \(or axis\) of a controller

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|controller\_handle| [ControllerHandle](msg_Base_ControllerHandle.md#)|Controller handle|
|button|oneof:identifier uint32|Button identifier \(only set if 'button' controller event, otherwise zero\)|
|axis|oneof:identifier uint32|Axis identifier \(only set if 'axis' controller event, otherwise zero\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_controller\_handle\(\) const|bool|void|Returns true if controller\_handle is set.|
|controller\_handle\(\)|const [ControllerHandle](msg_Base_ControllerHandle.md#)&|void|Returns the current value of controller\_handle. If controller\_handle is not set, returns a [ControllerHandle](msg_Base_ControllerHandle.md#) with none of its fields set \(possibly controller\_handle::default\_instance\(\)\).|
|mutable\_controller\_handle\(\)| [ControllerHandle](msg_Base_ControllerHandle.md#) \*|void|Returns a pointer to the mutable [ControllerHandle](msg_Base_ControllerHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ControllerHandle](msg_Base_ControllerHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerHandle](msg_Base_ControllerHandle.md#)\). After calling this, has\_controller\_handle\(\) will return true and controller\_handle\(\) will return a reference to the same instance of [ControllerHandle](msg_Base_ControllerHandle.md#).|
|clear\_controller\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_controller\_handle\(\) will return false and controller\_handle\(\) will return the default value.|
|set\_allocated\_controller\_handle\(\)|void| [ControllerHandle](msg_Base_ControllerHandle.md#) \*|Sets the [ControllerHandle](msg_Base_ControllerHandle.md#) object to the field and frees the previous field value if it exists. If the [ControllerHandle](msg_Base_ControllerHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ControllerHandle](msg_Base_ControllerHandle.md#) object and has\_ [ControllerHandle](msg_Base_ControllerHandle.md#)\(\) will return true. Otherwise, if the controller\_handle is NULL, the behavior is the same as calling clear\_controller\_handle\(\).|
|release\_controller\_handle\(\)| [ControllerHandle](msg_Base_ControllerHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ControllerHandle](msg_Base_ControllerHandle.md#) object. After calling this, caller takes the ownership of the allocated [ControllerHandle](msg_Base_ControllerHandle.md#) object, has\_controller\_handle\(\) will return false, and controller\_handle\(\) will return the default value.|
|set\_button\(\)|void|oneof:identifier uint32|If any other oneof field in the same oneof is set, calls clear\_identifier\(\). Sets the value of this field and sets the oneof case to kButton.|
|button\(\) const|oneof:identifier uint32|void|Returns the current value of the field if oneof case is kButton. Otherwise, returns the default value.|
|clear\_button\(\)|void|void|Nothing will be changed if the oneof case is not kButton. If the oneof case is kButton, clears the value of the field and the oneof case|
|set\_axis\(\)|void|oneof:identifier uint32|If any other oneof field in the same oneof is set, calls clear\_identifier\(\). Sets the value of this field and sets the oneof case to kAxis.|
|axis\(\) const|oneof:identifier uint32|void|Returns the current value of the field if oneof case is kAxis. Otherwise, returns the default value.|
|clear\_axis\(\)|void|void|Nothing will be changed if the oneof case is not kAxis. If the oneof case is kAxis, clears the value of the field and the oneof case|

**Parent topic:** [Base](../references/summary_Base.md)

