# class SwitchControlMapping

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|controller\_identifier|uint32|Identifier of the controller for which changing the active map is requested|
|map\_group\_handle| [MapGroupHandle](MapGroupHandle.md#)|Reference to the map group for which the active map needs to change|
|map\_handle| [MapHandle](MapHandle.md#)|Reference to new active map|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|controller\_identifier\(\)|uint32|void|Returns the current value of controller\_identifier. If the controller\_identifier is not set, returns 0.|
|set\_controller\_identifier\(\)|void|uint32|Sets the value of controller\_identifier. After calling this, controller\_identifier\(\) will return value.|
|clear\_controller\_identifier\(\)|void|void|Clears the value of controller\_identifier. After calling this, controller\_identifier\(\) will return 0.|
|has\_map\_group\_handle\(\) const|bool|void|Returns true if map\_group\_handle is set.|
|map\_group\_handle\(\)|const [MapGroupHandle](MapGroupHandle.md#)&|void|Returns the current value of map\_group\_handle. If map\_group\_handle is not set, returns a [MapGroupHandle](MapGroupHandle.md#) with none of its fields set \(possibly map\_group\_handle::default\_instance\(\)\).|
|mutable\_map\_group\_handle\(\)| [MapGroupHandle](MapGroupHandle.md#) \*|void|Returns a pointer to the mutable [MapGroupHandle](MapGroupHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapGroupHandle](MapGroupHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapGroupHandle](MapGroupHandle.md#)\). After calling this, has\_map\_group\_handle\(\) will return true and map\_group\_handle\(\) will return a reference to the same instance of [MapGroupHandle](MapGroupHandle.md#).|
|clear\_map\_group\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_map\_group\_handle\(\) will return false and map\_group\_handle\(\) will return the default value.|
|set\_allocated\_map\_group\_handle\(\)|void| [MapGroupHandle](MapGroupHandle.md#) \*|Sets the [MapGroupHandle](MapGroupHandle.md#) object to the field and frees the previous field value if it exists. If the [MapGroupHandle](MapGroupHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MapGroupHandle](MapGroupHandle.md#) object and has\_ [MapGroupHandle](MapGroupHandle.md#)\(\) will return true. Otherwise, if the map\_group\_handle is NULL, the behavior is the same as calling clear\_map\_group\_handle\(\).|
|release\_map\_group\_handle\(\)| [MapGroupHandle](MapGroupHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapGroupHandle](MapGroupHandle.md#) object. After calling this, caller takes the ownership of the allocated [MapGroupHandle](MapGroupHandle.md#) object, has\_map\_group\_handle\(\) will return false, and map\_group\_handle\(\) will return the default value.|
|has\_map\_handle\(\) const|bool|void|Returns true if map\_handle is set.|
|map\_handle\(\)|const [MapHandle](MapHandle.md#)&|void|Returns the current value of map\_handle. If map\_handle is not set, returns a [MapHandle](MapHandle.md#) with none of its fields set \(possibly map\_handle::default\_instance\(\)\).|
|mutable\_map\_handle\(\)| [MapHandle](MapHandle.md#) \*|void|Returns a pointer to the mutable [MapHandle](MapHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapHandle](MapHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapHandle](MapHandle.md#)\). After calling this, has\_map\_handle\(\) will return true and map\_handle\(\) will return a reference to the same instance of [MapHandle](MapHandle.md#).|
|clear\_map\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_map\_handle\(\) will return false and map\_handle\(\) will return the default value.|
|set\_allocated\_map\_handle\(\)|void| [MapHandle](MapHandle.md#) \*|Sets the [MapHandle](MapHandle.md#) object to the field and frees the previous field value if it exists. If the [MapHandle](MapHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MapHandle](MapHandle.md#) object and has\_ [MapHandle](MapHandle.md#)\(\) will return true. Otherwise, if the map\_handle is NULL, the behavior is the same as calling clear\_map\_handle\(\).|
|release\_map\_handle\(\)| [MapHandle](MapHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapHandle](MapHandle.md#) object. After calling this, caller takes the ownership of the allocated [MapHandle](MapHandle.md#) object, has\_map\_handle\(\) will return false, and map\_handle\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

