# class MapElement

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event| [MapEvent](MapEvent.md#)|Map event that occured|
|action| [Action](Action.md#)|Action to invoke upon event occurence|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_event\(\) const|bool|void|Returns true if event is set.|
|event\(\)|const [MapEvent](MapEvent.md#)&|void|Returns the current value of event. If event is not set, returns a [MapEvent](MapEvent.md#) with none of its fields set \(possibly event::default\_instance\(\)\).|
|mutable\_event\(\)| [MapEvent](MapEvent.md#) \*|void|Returns a pointer to the mutable [MapEvent](MapEvent.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapEvent](MapEvent.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapEvent](MapEvent.md#)\). After calling this, has\_event\(\) will return true and event\(\) will return a reference to the same instance of [MapEvent](MapEvent.md#).|
|clear\_event\(\)|void|void|Clears the value of the field. After calling this, has\_event\(\) will return false and event\(\) will return the default value.|
|set\_allocated\_event\(\)|void| [MapEvent](MapEvent.md#) \*|Sets the [MapEvent](MapEvent.md#) object to the field and frees the previous field value if it exists. If the [MapEvent](MapEvent.md#) pointer is not NULL, the message takes ownership of the allocated [MapEvent](MapEvent.md#) object and has\_ [MapEvent](MapEvent.md#)\(\) will return true. Otherwise, if the event is NULL, the behavior is the same as calling clear\_event\(\).|
|release\_event\(\)| [MapEvent](MapEvent.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapEvent](MapEvent.md#) object. After calling this, caller takes the ownership of the allocated [MapEvent](MapEvent.md#) object, has\_event\(\) will return false, and event\(\) will return the default value.|
|has\_action\(\) const|bool|void|Returns true if action is set.|
|action\(\)|const [Action](Action.md#)&|void|Returns the current value of action. If action is not set, returns a [Action](Action.md#) with none of its fields set \(possibly action::default\_instance\(\)\).|
|mutable\_action\(\)| [Action](Action.md#) \*|void|Returns a pointer to the mutable [Action](Action.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Action](Action.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Action](Action.md#)\). After calling this, has\_action\(\) will return true and action\(\) will return a reference to the same instance of [Action](Action.md#).|
|clear\_action\(\)|void|void|Clears the value of the field. After calling this, has\_action\(\) will return false and action\(\) will return the default value.|
|set\_allocated\_action\(\)|void| [Action](Action.md#) \*|Sets the [Action](Action.md#) object to the field and frees the previous field value if it exists. If the [Action](Action.md#) pointer is not NULL, the message takes ownership of the allocated [Action](Action.md#) object and has\_ [Action](Action.md#)\(\) will return true. Otherwise, if the action is NULL, the behavior is the same as calling clear\_action\(\).|
|release\_action\(\)| [Action](Action.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Action](Action.md#) object. After calling this, caller takes the ownership of the allocated [Action](Action.md#) object, has\_action\(\) will return false, and action\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

