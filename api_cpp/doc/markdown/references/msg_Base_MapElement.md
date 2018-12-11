# Message MapElement

This page describes the C++ Kinova::Api::Base::MapElement message.

## Overview / Purpose

Associates a map event to map action

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event| [MapEvent](msg_Base_MapEvent.md#)|Map event that occured|
|action| [Action](msg_Base_Action.md#)|Action to invoke upon event occurence|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_event\(\) const|bool|void|Returns true if event is set.|
|event\(\)|const [MapEvent](msg_Base_MapEvent.md#)&|void|Returns the current value of event. If event is not set, returns a [MapEvent](msg_Base_MapEvent.md#) with none of its fields set \(possibly event::default\_instance\(\)\).|
|mutable\_event\(\)| [MapEvent](msg_Base_MapEvent.md#) \*|void|Returns a pointer to the mutable [MapEvent](msg_Base_MapEvent.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapEvent](msg_Base_MapEvent.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapEvent](msg_Base_MapEvent.md#)\). After calling this, has\_event\(\) will return true and event\(\) will return a reference to the same instance of [MapEvent](msg_Base_MapEvent.md#).|
|clear\_event\(\)|void|void|Clears the value of the field. After calling this, has\_event\(\) will return false and event\(\) will return the default value.|
|set\_allocated\_event\(\)|void| [MapEvent](msg_Base_MapEvent.md#) \*|Sets the [MapEvent](msg_Base_MapEvent.md#) object to the field and frees the previous field value if it exists. If the [MapEvent](msg_Base_MapEvent.md#) pointer is not NULL, the message takes ownership of the allocated [MapEvent](msg_Base_MapEvent.md#) object and has\_ [MapEvent](msg_Base_MapEvent.md#)\(\) will return true. Otherwise, if the event is NULL, the behavior is the same as calling clear\_event\(\).|
|release\_event\(\)| [MapEvent](msg_Base_MapEvent.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapEvent](msg_Base_MapEvent.md#) object. After calling this, caller takes the ownership of the allocated [MapEvent](msg_Base_MapEvent.md#) object, has\_event\(\) will return false, and event\(\) will return the default value.|
|has\_action\(\) const|bool|void|Returns true if action is set.|
|action\(\)|const [Action](msg_Base_Action.md#)&|void|Returns the current value of action. If action is not set, returns a [Action](msg_Base_Action.md#) with none of its fields set \(possibly action::default\_instance\(\)\).|
|mutable\_action\(\)| [Action](msg_Base_Action.md#) \*|void|Returns a pointer to the mutable [Action](msg_Base_Action.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Action](msg_Base_Action.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Action](msg_Base_Action.md#)\). After calling this, has\_action\(\) will return true and action\(\) will return a reference to the same instance of [Action](msg_Base_Action.md#).|
|clear\_action\(\)|void|void|Clears the value of the field. After calling this, has\_action\(\) will return false and action\(\) will return the default value.|
|set\_allocated\_action\(\)|void| [Action](msg_Base_Action.md#) \*|Sets the [Action](msg_Base_Action.md#) object to the field and frees the previous field value if it exists. If the [Action](msg_Base_Action.md#) pointer is not NULL, the message takes ownership of the allocated [Action](msg_Base_Action.md#) object and has\_ [Action](msg_Base_Action.md#)\(\) will return true. Otherwise, if the action is NULL, the behavior is the same as calling clear\_action\(\).|
|release\_action\(\)| [Action](msg_Base_Action.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Action](msg_Base_Action.md#) object. After calling this, caller takes the ownership of the allocated [Action](msg_Base_Action.md#) object, has\_action\(\) will return false, and action\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

