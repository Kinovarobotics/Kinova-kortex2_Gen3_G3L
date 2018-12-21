# Message Feedback

This page describes the C++ Kinova::Api::BaseCyclic::Feedback message.

## Overview / Purpose

Defines the feedback provided by many modules \(base, actuactors and interconnect\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|frame\_id|uint32|Frame ID|
|base| [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#)|Base feedback|
|actuators| [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)|Actuator feedback|
|interconnect| [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#)|Interconnect feedback|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|frame\_id\(\)|uint32|void|Returns the current value of frame\_id. If the frame\_id is not set, returns 0.|
|set\_frame\_id\(\)|void|uint32|Sets the value of frame\_id. After calling this, frame\_id\(\) will return value.|
|clear\_frame\_id\(\)|void|void|Clears the value of frame\_id. After calling this, frame\_id\(\) will return 0.|
|has\_base\(\) const|bool|void|Returns true if base is set.|
|base\(\)|const [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#)&|void|Returns the current value of base. If base is not set, returns a [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) with none of its fields set \(possibly base::default\_instance\(\)\).|
|mutable\_base\(\)| [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) \*|void|Returns a pointer to the mutable [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#)\). After calling this, has\_base\(\) will return true and base\(\) will return a reference to the same instance of [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#).|
|clear\_base\(\)|void|void|Clears the value of the field. After calling this, has\_base\(\) will return false and base\(\) will return the default value.|
|set\_allocated\_base\(\)|void| [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) \*|Sets the [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) object to the field and frees the previous field value if it exists. If the [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) pointer is not NULL, the message takes ownership of the allocated [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) object and has\_ [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#)\(\) will return true. Otherwise, if the base is NULL, the behavior is the same as calling clear\_base\(\).|
|release\_base\(\)| [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) \*|void|Releases the ownership of the field and returns the pointer of the [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) object. After calling this, caller takes the ownership of the allocated [BaseFeedback](msg_BaseCyclic_BaseFeedback.md#) object, has\_base\(\) will return false, and base\(\) will return the default value.|
|actuators\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|actuators\(\) const|const [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|mutable\_actuators\(\)| [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)\*|int index|Returns a pointer to the mutable [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|add\_actuators\(\)| [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)\).|
|clear\_actuators\(\)|void|void|Removes all elements from the field. After calling this, actuators\_size\(\) will return zero.|
|actuators\(\) const|const RepeatedPtrField< [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_actuators\(\)|RepeatedPtrField< [ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|has\_interconnect\(\) const|bool|void|Returns true if interconnect is set.|
|interconnect\(\)|const [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#)&|void|Returns the current value of interconnect. If interconnect is not set, returns a [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) with none of its fields set \(possibly interconnect::default\_instance\(\)\).|
|mutable\_interconnect\(\)| [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) \*|void|Returns a pointer to the mutable [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#)\). After calling this, has\_interconnect\(\) will return true and interconnect\(\) will return a reference to the same instance of [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#).|
|clear\_interconnect\(\)|void|void|Clears the value of the field. After calling this, has\_interconnect\(\) will return false and interconnect\(\) will return the default value.|
|set\_allocated\_interconnect\(\)|void| [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) \*|Sets the [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) object to the field and frees the previous field value if it exists. If the [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) pointer is not NULL, the message takes ownership of the allocated [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) object and has\_ [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#)\(\) will return true. Otherwise, if the interconnect is NULL, the behavior is the same as calling clear\_interconnect\(\).|
|release\_interconnect\(\)| [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) \*|void|Releases the ownership of the field and returns the pointer of the [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) object. After calling this, caller takes the ownership of the allocated [InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#) object, has\_interconnect\(\) will return false, and interconnect\(\) will return the default value.|

**Parent topic:** [BaseCyclic](../references/summary_BaseCyclic.md)

