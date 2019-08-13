# class Feedback

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|frame\_id|uint32|Frame ID|
|base| [BaseFeedback](BaseFeedback.md#)|Base feedback|
|actuators| [ActuatorFeedback](ActuatorFeedback.md#)|Actuator feedback|
|interconnect| [Feedback](../InterconnectCyclic/Feedback.md#)|Interface feedback|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|frame\_id\(\)|uint32|void|Returns the current value of frame\_id. If the frame\_id is not set, returns 0.|
|set\_frame\_id\(\)|void|uint32|Sets the value of frame\_id. After calling this, frame\_id\(\) will return value.|
|clear\_frame\_id\(\)|void|void|Clears the value of frame\_id. After calling this, frame\_id\(\) will return 0.|
|has\_base\(\) const|bool|void|Returns true if base is set.|
|base\(\)|const [BaseFeedback](BaseFeedback.md#)&|void|Returns the current value of base. If base is not set, returns a [BaseFeedback](BaseFeedback.md#) with none of its fields set \(possibly base::default\_instance\(\)\).|
|mutable\_base\(\)| [BaseFeedback](BaseFeedback.md#) \*|void|Returns a pointer to the mutable [BaseFeedback](BaseFeedback.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [BaseFeedback](BaseFeedback.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [BaseFeedback](BaseFeedback.md#)\). After calling this, has\_base\(\) will return true and base\(\) will return a reference to the same instance of [BaseFeedback](BaseFeedback.md#).|
|clear\_base\(\)|void|void|Clears the value of the field. After calling this, has\_base\(\) will return false and base\(\) will return the default value.|
|set\_allocated\_base\(\)|void| [BaseFeedback](BaseFeedback.md#) \*|Sets the [BaseFeedback](BaseFeedback.md#) object to the field and frees the previous field value if it exists. If the [BaseFeedback](BaseFeedback.md#) pointer is not NULL, the message takes ownership of the allocated [BaseFeedback](BaseFeedback.md#) object and has\_ [BaseFeedback](BaseFeedback.md#)\(\) will return true. Otherwise, if the base is NULL, the behavior is the same as calling clear\_base\(\).|
|release\_base\(\)| [BaseFeedback](BaseFeedback.md#) \*|void|Releases the ownership of the field and returns the pointer of the [BaseFeedback](BaseFeedback.md#) object. After calling this, caller takes the ownership of the allocated [BaseFeedback](BaseFeedback.md#) object, has\_base\(\) will return false, and base\(\) will return the default value.|
|actuators\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|actuators\(\) const|const [ActuatorFeedback](ActuatorFeedback.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|mutable\_actuators\(\)| [ActuatorFeedback](ActuatorFeedback.md#)\*|int index|Returns a pointer to the mutable [ActuatorFeedback](ActuatorFeedback.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, actuators\_size\(\)\) yields undefined behavior.|
|add\_actuators\(\)| [ActuatorFeedback](ActuatorFeedback.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ActuatorFeedback](ActuatorFeedback.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActuatorFeedback](ActuatorFeedback.md#)\).|
|clear\_actuators\(\)|void|void|Removes all elements from the field. After calling this, actuators\_size\(\) will return zero.|
|actuators\(\) const|const RepeatedPtrField< [ActuatorFeedback](ActuatorFeedback.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_actuators\(\)|RepeatedPtrField< [ActuatorFeedback](ActuatorFeedback.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|has\_interconnect\(\) const|bool|void|Returns true if interconnect is set.|
|interconnect\(\)|const [Feedback](../InterconnectCyclic/Feedback.md#)&|void|Returns the current value of interconnect. If interconnect is not set, returns a [Feedback](../InterconnectCyclic/Feedback.md#) with none of its fields set \(possibly interconnect::default\_instance\(\)\).|
|mutable\_interconnect\(\)| [Feedback](../InterconnectCyclic/Feedback.md#) \*|void|Returns a pointer to the mutable [Feedback](../InterconnectCyclic/Feedback.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Feedback](../InterconnectCyclic/Feedback.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Feedback](../InterconnectCyclic/Feedback.md#)\). After calling this, has\_interconnect\(\) will return true and interconnect\(\) will return a reference to the same instance of [Feedback](../InterconnectCyclic/Feedback.md#).|
|clear\_interconnect\(\)|void|void|Clears the value of the field. After calling this, has\_interconnect\(\) will return false and interconnect\(\) will return the default value.|
|set\_allocated\_interconnect\(\)|void| [Feedback](../InterconnectCyclic/Feedback.md#) \*|Sets the [Feedback](../InterconnectCyclic/Feedback.md#) object to the field and frees the previous field value if it exists. If the [Feedback](../InterconnectCyclic/Feedback.md#) pointer is not NULL, the message takes ownership of the allocated [Feedback](../InterconnectCyclic/Feedback.md#) object and has\_ [Feedback](../InterconnectCyclic/Feedback.md#)\(\) will return true. Otherwise, if the interconnect is NULL, the behavior is the same as calling clear\_interconnect\(\).|
|release\_interconnect\(\)| [Feedback](../InterconnectCyclic/Feedback.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Feedback](../InterconnectCyclic/Feedback.md#) object. After calling this, caller takes the ownership of the allocated [Feedback](../InterconnectCyclic/Feedback.md#) object, has\_interconnect\(\) will return false, and interconnect\(\) will return the default value.|

**Parent topic:** [BaseCyclic \(C++\)](../../summary_pages/BaseCyclic.md)

