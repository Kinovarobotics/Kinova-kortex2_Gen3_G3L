# class Command

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|frame\_id|uint32|Frame ID|
|actuators| [ActuatorCommand](ActuatorCommand.md#)|Actuator command \(repeated\)|
|interconnect| [Command](../InterconnectCyclic/Command.md#)|Interface command|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|frame\_id\(\)|uint32|void|Returns the current value of frame\_id. If the frame\_id is not set, returns 0.|
|set\_frame\_id\(\)|void|uint32|Sets the value of frame\_id. After calling this, frame\_id\(\) will return value.|
|clear\_frame\_id\(\)|void|void|Clears the value of frame\_id. After calling this, frame\_id\(\) will return 0.|
|actuators\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|actuators\(\) const|const [ActuatorCommand](ActuatorCommand.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|mutable\_actuators\(\)| [ActuatorCommand](ActuatorCommand.md#)\*|int index|Returns a pointer to the mutable [ActuatorCommand](ActuatorCommand.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|add\_actuators\(\)| [ActuatorCommand](ActuatorCommand.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ActuatorCommand](ActuatorCommand.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActuatorCommand](ActuatorCommand.md#)\).|
|clear\_actuators\(\)|void|void|Removes all elements from the field. After calling this, actuators\_size\(\) will return zero.|
|actuators\(\) const|const RepeatedPtrField< [ActuatorCommand](ActuatorCommand.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_actuators\(\)|RepeatedPtrField< [ActuatorCommand](ActuatorCommand.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|has\_interconnect\(\) const|bool|void|Returns true if interconnect is set.|
|interconnect\(\)|const [Command](../InterconnectCyclic/Command.md#)&|void|Returns the current value of interconnect. If interconnect is not set, returns a [Command](../InterconnectCyclic/Command.md#) with none of its fields set \(possibly interconnect::default\_instance\(\)\).|
|mutable\_interconnect\(\)| [Command](../InterconnectCyclic/Command.md#) \*|void|Returns a pointer to the mutable [Command](../InterconnectCyclic/Command.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Command](../InterconnectCyclic/Command.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Command](../InterconnectCyclic/Command.md#)\). After calling this, has\_interconnect\(\) will return true and interconnect\(\) will return a reference to the same instance of [Command](../InterconnectCyclic/Command.md#).|
|clear\_interconnect\(\)|void|void|Clears the value of the field. After calling this, has\_interconnect\(\) will return false and interconnect\(\) will return the default value.|
|set\_allocated\_interconnect\(\)|void| [Command](../InterconnectCyclic/Command.md#) \*|Sets the [Command](../InterconnectCyclic/Command.md#) object to the field and frees the previous field value if it exists. If the [Command](../InterconnectCyclic/Command.md#) pointer is not NULL, the message takes ownership of the allocated [Command](../InterconnectCyclic/Command.md#) object and has\_ [Command](../InterconnectCyclic/Command.md#)\(\) will return true. Otherwise, if the interconnect is NULL, the behavior is the same as calling clear\_interconnect\(\).|
|release\_interconnect\(\)| [Command](../InterconnectCyclic/Command.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Command](../InterconnectCyclic/Command.md#) object. After calling this, caller takes the ownership of the allocated [Command](../InterconnectCyclic/Command.md#) object, has\_interconnect\(\) will return false, and interconnect\(\) will return the default value.|

**Parent topic:** [BaseCyclic \(C++\)](../../summary_pages/BaseCyclic.md)

