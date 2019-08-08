# class ActivateMapHandle

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mapping\_handle| [MappingHandle](MappingHandle.md#)|Mapping that the active map is asked for|
|map\_group\_handle| [MapGroupHandle](MapGroupHandle.md#)|Map group that the active map is asked for \(not implemented yet\)|
|map\_handle| [MapHandle](MapHandle.md#)|New active map|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_mapping\_handle\(\) const|bool|void|Returns true if mapping\_handle is set.|
|mapping\_handle\(\)|const [MappingHandle](MappingHandle.md#)&|void|Returns the current value of mapping\_handle. If mapping\_handle is not set, returns a [MappingHandle](MappingHandle.md#) with none of its fields set \(possibly mapping\_handle::default\_instance\(\)\).|
|mutable\_mapping\_handle\(\)| [MappingHandle](MappingHandle.md#) \*|void|Returns a pointer to the mutable [MappingHandle](MappingHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MappingHandle](MappingHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MappingHandle](MappingHandle.md#)\). After calling this, has\_mapping\_handle\(\) will return true and mapping\_handle\(\) will return a reference to the same instance of [MappingHandle](MappingHandle.md#).|
|clear\_mapping\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_mapping\_handle\(\) will return false and mapping\_handle\(\) will return the default value.|
|set\_allocated\_mapping\_handle\(\)|void| [MappingHandle](MappingHandle.md#) \*|Sets the [MappingHandle](MappingHandle.md#) object to the field and frees the previous field value if it exists. If the [MappingHandle](MappingHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MappingHandle](MappingHandle.md#) object and has\_ [MappingHandle](MappingHandle.md#)\(\) will return true. Otherwise, if the mapping\_handle is NULL, the behavior is the same as calling clear\_mapping\_handle\(\).|
|release\_mapping\_handle\(\)| [MappingHandle](MappingHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MappingHandle](MappingHandle.md#) object. After calling this, caller takes the ownership of the allocated [MappingHandle](MappingHandle.md#) object, has\_mapping\_handle\(\) will return false, and mapping\_handle\(\) will return the default value.|
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

