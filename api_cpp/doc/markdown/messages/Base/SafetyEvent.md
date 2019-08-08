# class SafetyEvent

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|safety\_handle| [SafetyHandle](../Common/SafetyHandle.md#)|Safety that caused the event to occur|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_safety\_handle\(\) const|bool|void|Returns true if safety\_handle is set.|
|safety\_handle\(\)|const [SafetyHandle](../Common/SafetyHandle.md#)&|void|Returns the current value of safety\_handle. If safety\_handle is not set, returns a [SafetyHandle](../Common/SafetyHandle.md#) with none of its fields set \(possibly safety\_handle::default\_instance\(\)\).|
|mutable\_safety\_handle\(\)| [SafetyHandle](../Common/SafetyHandle.md#) \*|void|Returns a pointer to the mutable [SafetyHandle](../Common/SafetyHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyHandle](../Common/SafetyHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyHandle](../Common/SafetyHandle.md#)\). After calling this, has\_safety\_handle\(\) will return true and safety\_handle\(\) will return a reference to the same instance of [SafetyHandle](../Common/SafetyHandle.md#).|
|clear\_safety\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_safety\_handle\(\) will return false and safety\_handle\(\) will return the default value.|
|set\_allocated\_safety\_handle\(\)|void| [SafetyHandle](../Common/SafetyHandle.md#) \*|Sets the [SafetyHandle](../Common/SafetyHandle.md#) object to the field and frees the previous field value if it exists. If the [SafetyHandle](../Common/SafetyHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyHandle](../Common/SafetyHandle.md#) object and has\_ [SafetyHandle](../Common/SafetyHandle.md#)\(\) will return true. Otherwise, if the safety\_handle is NULL, the behavior is the same as calling clear\_safety\_handle\(\).|
|release\_safety\_handle\(\)| [SafetyHandle](../Common/SafetyHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyHandle](../Common/SafetyHandle.md#) object. After calling this, caller takes the ownership of the allocated [SafetyHandle](../Common/SafetyHandle.md#) object, has\_safety\_handle\(\) will return false, and safety\_handle\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

