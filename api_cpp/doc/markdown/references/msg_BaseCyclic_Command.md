# Message Command

This page describes the C++ Kinova::Api::BaseCyclic::Command message.

## Overview / Purpose

Defines a command for many modules \(actuactors and interconnect\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|frame\_id|uint32|Frame ID|
|actuators| [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)|Actuator command \(repeated\)|
|interconnect| [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#)|Interconnect command|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|frame\_id\(\)|uint32|void|Returns the current value of frame\_id. If the frame\_id is not set, returns 0.|
|set\_frame\_id\(\)|void|uint32|Sets the value of frame\_id. After calling this, frame\_id\(\) will return value.|
|clear\_frame\_id\(\)|void|void|Clears the value of frame\_id. After calling this, frame\_id\(\) will return 0.|
|actuators\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|actuators\(\) const|const [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|mutable\_actuators\(\)| [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)\*|int index|Returns a pointer to the mutable [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|add\_actuators\(\)| [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)\).|
|clear\_actuators\(\)|void|void|Removes all elements from the field. After calling this, actuators\_size\(\) will return zero.|
|actuators\(\) const|const RepeatedPtrField< [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_actuators\(\)|RepeatedPtrField< [ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|has\_interconnect\(\) const|bool|void|Returns true if interconnect is set.|
|interconnect\(\)|const [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#)&|void|Returns the current value of interconnect. If interconnect is not set, returns a [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) with none of its fields set \(possibly interconnect::default\_instance\(\)\).|
|mutable\_interconnect\(\)| [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) \*|void|Returns a pointer to the mutable [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#)\). After calling this, has\_interconnect\(\) will return true and interconnect\(\) will return a reference to the same instance of [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#).|
|clear\_interconnect\(\)|void|void|Clears the value of the field. After calling this, has\_interconnect\(\) will return false and interconnect\(\) will return the default value.|
|set\_allocated\_interconnect\(\)|void| [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) \*|Sets the [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) object to the field and frees the previous field value if it exists. If the [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) pointer is not NULL, the message takes ownership of the allocated [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) object and has\_ [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#)\(\) will return true. Otherwise, if the interconnect is NULL, the behavior is the same as calling clear\_interconnect\(\).|
|release\_interconnect\(\)| [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) \*|void|Releases the ownership of the field and returns the pointer of the [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) object. After calling this, caller takes the ownership of the allocated [InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#) object, has\_interconnect\(\) will return false, and interconnect\(\) will return the default value.|

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

