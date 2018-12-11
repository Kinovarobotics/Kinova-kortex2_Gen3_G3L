# Message CustomData

This page describes the C++ Kinova::Api::BaseCyclic::CustomData message.

## Overview / Purpose

Custom development data, content varies according to debug needs

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|frame\_id|uint32|Frame ID|
|custom\_data\_0|uint32|Custom data word 0|
|custom\_data\_1|uint32|Custom data word 1|
|custom\_data\_2|uint32|Custom data word 2|
|custom\_data\_3|uint32|Custom data word 3|
|custom\_data\_4|uint32|Custom data word 4|
|custom\_data\_5|uint32|Custom data word 5|
|custom\_data\_6|uint32|Custom data word 6|
|custom\_data\_7|uint32|Custom data word 7|
|actuators\_custom\_data| [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)|Actuator custom data \(repeated\)|
|interconnect\_custom\_data| [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#)|Interconnect custom data|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|frame\_id\(\)|uint32|void|Returns the current value of frame\_id. If the frame\_id is not set, returns 0.|
|set\_frame\_id\(\)|void|uint32|Sets the value of frame\_id. After calling this, frame\_id\(\) will return value.|
|clear\_frame\_id\(\)|void|void|Clears the value of frame\_id. After calling this, frame\_id\(\) will return 0.|
|custom\_data\_0\(\)|uint32|void|Returns the current value of custom\_data\_0. If the custom\_data\_0 is not set, returns 0.|
|set\_custom\_data\_0\(\)|void|uint32|Sets the value of custom\_data\_0. After calling this, custom\_data\_0\(\) will return value.|
|clear\_custom\_data\_0\(\)|void|void|Clears the value of custom\_data\_0. After calling this, custom\_data\_0\(\) will return 0.|
|custom\_data\_1\(\)|uint32|void|Returns the current value of custom\_data\_1. If the custom\_data\_1 is not set, returns 0.|
|set\_custom\_data\_1\(\)|void|uint32|Sets the value of custom\_data\_1. After calling this, custom\_data\_1\(\) will return value.|
|clear\_custom\_data\_1\(\)|void|void|Clears the value of custom\_data\_1. After calling this, custom\_data\_1\(\) will return 0.|
|custom\_data\_2\(\)|uint32|void|Returns the current value of custom\_data\_2. If the custom\_data\_2 is not set, returns 0.|
|set\_custom\_data\_2\(\)|void|uint32|Sets the value of custom\_data\_2. After calling this, custom\_data\_2\(\) will return value.|
|clear\_custom\_data\_2\(\)|void|void|Clears the value of custom\_data\_2. After calling this, custom\_data\_2\(\) will return 0.|
|custom\_data\_3\(\)|uint32|void|Returns the current value of custom\_data\_3. If the custom\_data\_3 is not set, returns 0.|
|set\_custom\_data\_3\(\)|void|uint32|Sets the value of custom\_data\_3. After calling this, custom\_data\_3\(\) will return value.|
|clear\_custom\_data\_3\(\)|void|void|Clears the value of custom\_data\_3. After calling this, custom\_data\_3\(\) will return 0.|
|custom\_data\_4\(\)|uint32|void|Returns the current value of custom\_data\_4. If the custom\_data\_4 is not set, returns 0.|
|set\_custom\_data\_4\(\)|void|uint32|Sets the value of custom\_data\_4. After calling this, custom\_data\_4\(\) will return value.|
|clear\_custom\_data\_4\(\)|void|void|Clears the value of custom\_data\_4. After calling this, custom\_data\_4\(\) will return 0.|
|custom\_data\_5\(\)|uint32|void|Returns the current value of custom\_data\_5. If the custom\_data\_5 is not set, returns 0.|
|set\_custom\_data\_5\(\)|void|uint32|Sets the value of custom\_data\_5. After calling this, custom\_data\_5\(\) will return value.|
|clear\_custom\_data\_5\(\)|void|void|Clears the value of custom\_data\_5. After calling this, custom\_data\_5\(\) will return 0.|
|custom\_data\_6\(\)|uint32|void|Returns the current value of custom\_data\_6. If the custom\_data\_6 is not set, returns 0.|
|set\_custom\_data\_6\(\)|void|uint32|Sets the value of custom\_data\_6. After calling this, custom\_data\_6\(\) will return value.|
|clear\_custom\_data\_6\(\)|void|void|Clears the value of custom\_data\_6. After calling this, custom\_data\_6\(\) will return 0.|
|custom\_data\_7\(\)|uint32|void|Returns the current value of custom\_data\_7. If the custom\_data\_7 is not set, returns 0.|
|set\_custom\_data\_7\(\)|void|uint32|Sets the value of custom\_data\_7. After calling this, custom\_data\_7\(\) will return value.|
|clear\_custom\_data\_7\(\)|void|void|Clears the value of custom\_data\_7. After calling this, custom\_data\_7\(\) will return 0.|
|actuators\_custom\_data\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|actuators\_custom\_data\(\) const|const [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_custom\_data\_size\(\)\) yields undefined behavior.|
|mutable\_actuators\_custom\_data\(\)| [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)\*|int index|Returns a pointer to the mutable [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_custom\_data\_size\(\)\) yields undefined behavior.|
|add\_actuators\_custom\_data\(\)| [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)\).|
|clear\_actuators\_custom\_data\(\)|void|void|Removes all elements from the field. After calling this, actuators\_custom\_data\_size\(\) will return zero.|
|actuators\_custom\_data\(\) const|const RepeatedPtrField< [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_actuators\_custom\_data\(\)|RepeatedPtrField< [ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|has\_interconnect\_custom\_data\(\) const|bool|void|Returns true if interconnect\_custom\_data is set.|
|interconnect\_custom\_data\(\)|const [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#)&|void|Returns the current value of interconnect\_custom\_data. If interconnect\_custom\_data is not set, returns a [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) with none of its fields set \(possibly interconnect\_custom\_data::default\_instance\(\)\).|
|mutable\_interconnect\_custom\_data\(\)| [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) \*|void|Returns a pointer to the mutable [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#)\). After calling this, has\_interconnect\_custom\_data\(\) will return true and interconnect\_custom\_data\(\) will return a reference to the same instance of [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#).|
|clear\_interconnect\_custom\_data\(\)|void|void|Clears the value of the field. After calling this, has\_interconnect\_custom\_data\(\) will return false and interconnect\_custom\_data\(\) will return the default value.|
|set\_allocated\_interconnect\_custom\_data\(\)|void| [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) \*|Sets the [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) object to the field and frees the previous field value if it exists. If the [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) pointer is not NULL, the message takes ownership of the allocated [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) object and has\_ [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#)\(\) will return true. Otherwise, if the interconnect\_custom\_data is NULL, the behavior is the same as calling clear\_interconnect\_custom\_data\(\).|
|release\_interconnect\_custom\_data\(\)| [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) \*|void|Releases the ownership of the field and returns the pointer of the [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) object. After calling this, caller takes the ownership of the allocated [InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#) object, has\_interconnect\_custom\_data\(\) will return false, and interconnect\_custom\_data\(\) will return the default value.|

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

