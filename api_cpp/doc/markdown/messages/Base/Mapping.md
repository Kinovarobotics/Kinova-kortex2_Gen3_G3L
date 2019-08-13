# class Mapping

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [MappingHandle](MappingHandle.md#)|Mapping handle \(do not set on createMapping\(\) call\)|
|name|string|Mapping friendly name|
|controller\_identifier|uint32|Associated controller identifier|
|active\_map\_group\_handle| [MapGroupHandle](MapGroupHandle.md#)|Currently active map group \(not implemented yet\)|
|map\_group\_handles| [MapGroupHandle](MapGroupHandle.md#)|Array of associated map groups \(not implemented yet\)|
|active\_map\_handle| [MapHandle](MapHandle.md#)|Currently active map|
|map\_handles| [MapHandle](MapHandle.md#)|Array of associated maps|
|application\_data|string|Application data \(reserved for use by Web App\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [MappingHandle](MappingHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [MappingHandle](MappingHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [MappingHandle](MappingHandle.md#) \*|void|Returns a pointer to the mutable [MappingHandle](MappingHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MappingHandle](MappingHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MappingHandle](MappingHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [MappingHandle](MappingHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [MappingHandle](MappingHandle.md#) \*|Sets the [MappingHandle](MappingHandle.md#) object to the field and frees the previous field value if it exists. If the [MappingHandle](MappingHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MappingHandle](MappingHandle.md#) object and has\_ [MappingHandle](MappingHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [MappingHandle](MappingHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MappingHandle](MappingHandle.md#) object. After calling this, caller takes the ownership of the allocated [MappingHandle](MappingHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|name\(\)|const string&|void|Returns the current value of name. If name is not set, returns the empty string/empty bytes.|
|set\_name\(\)|void|const string&|Sets the value of name. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|string&&|\(C++11 and beyond\): Sets the value of name, moving from the passed string. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|const char\*|Sets the value of name using a C-style null-terminated string. After calling this, name\(\) will return a copy of value.|
|mutable\_name\(\)|string \*|void|Returns a pointer to the mutable string object that stores name's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, name\(\) will return whatever value is written into the given string.|
|clear\_name\(\)|void|void|Clears the value of name. After calling this, name\(\) will return the empty string/empty bytes.|
|set\_allocated\_name\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_name\(\).|
|release\_name\(\)|string \*|void|Releases the ownership of name and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and name\(\) will return the empty string/empty bytes.|
|controller\_identifier\(\)|uint32|void|Returns the current value of controller\_identifier. If the controller\_identifier is not set, returns 0.|
|set\_controller\_identifier\(\)|void|uint32|Sets the value of controller\_identifier. After calling this, controller\_identifier\(\) will return value.|
|clear\_controller\_identifier\(\)|void|void|Clears the value of controller\_identifier. After calling this, controller\_identifier\(\) will return 0.|
|has\_active\_map\_group\_handle\(\) const|bool|void|Returns true if active\_map\_group\_handle is set.|
|active\_map\_group\_handle\(\)|const [MapGroupHandle](MapGroupHandle.md#)&|void|Returns the current value of active\_map\_group\_handle. If active\_map\_group\_handle is not set, returns a [MapGroupHandle](MapGroupHandle.md#) with none of its fields set \(possibly active\_map\_group\_handle::default\_instance\(\)\).|
|mutable\_active\_map\_group\_handle\(\)| [MapGroupHandle](MapGroupHandle.md#) \*|void|Returns a pointer to the mutable [MapGroupHandle](MapGroupHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapGroupHandle](MapGroupHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapGroupHandle](MapGroupHandle.md#)\). After calling this, has\_active\_map\_group\_handle\(\) will return true and active\_map\_group\_handle\(\) will return a reference to the same instance of [MapGroupHandle](MapGroupHandle.md#).|
|clear\_active\_map\_group\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_active\_map\_group\_handle\(\) will return false and active\_map\_group\_handle\(\) will return the default value.|
|set\_allocated\_active\_map\_group\_handle\(\)|void| [MapGroupHandle](MapGroupHandle.md#) \*|Sets the [MapGroupHandle](MapGroupHandle.md#) object to the field and frees the previous field value if it exists. If the [MapGroupHandle](MapGroupHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MapGroupHandle](MapGroupHandle.md#) object and has\_ [MapGroupHandle](MapGroupHandle.md#)\(\) will return true. Otherwise, if the active\_map\_group\_handle is NULL, the behavior is the same as calling clear\_active\_map\_group\_handle\(\).|
|release\_active\_map\_group\_handle\(\)| [MapGroupHandle](MapGroupHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapGroupHandle](MapGroupHandle.md#) object. After calling this, caller takes the ownership of the allocated [MapGroupHandle](MapGroupHandle.md#) object, has\_active\_map\_group\_handle\(\) will return false, and active\_map\_group\_handle\(\) will return the default value.|
|map\_group\_handles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|map\_group\_handles\(\) const|const [MapGroupHandle](MapGroupHandle.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, map\_group\_handles\_size\(\)\) yields undefined behavior.|
|mutable\_map\_group\_handles\(\)| [MapGroupHandle](MapGroupHandle.md#)\*|int index|Returns a pointer to the mutable [MapGroupHandle](MapGroupHandle.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, map\_group\_handles\_size\(\)\) yields undefined behavior.|
|add\_map\_group\_handles\(\)| [MapGroupHandle](MapGroupHandle.md#)\*|void|Adds a new element and returns a pointer to it. The returned [MapGroupHandle](MapGroupHandle.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapGroupHandle](MapGroupHandle.md#)\).|
|clear\_map\_group\_handles\(\)|void|void|Removes all elements from the field. After calling this, map\_group\_handles\_size\(\) will return zero.|
|map\_group\_handles\(\) const|const RepeatedPtrField< [MapGroupHandle](MapGroupHandle.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_map\_group\_handles\(\)|RepeatedPtrField< [MapGroupHandle](MapGroupHandle.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|has\_active\_map\_handle\(\) const|bool|void|Returns true if active\_map\_handle is set.|
|active\_map\_handle\(\)|const [MapHandle](MapHandle.md#)&|void|Returns the current value of active\_map\_handle. If active\_map\_handle is not set, returns a [MapHandle](MapHandle.md#) with none of its fields set \(possibly active\_map\_handle::default\_instance\(\)\).|
|mutable\_active\_map\_handle\(\)| [MapHandle](MapHandle.md#) \*|void|Returns a pointer to the mutable [MapHandle](MapHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapHandle](MapHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapHandle](MapHandle.md#)\). After calling this, has\_active\_map\_handle\(\) will return true and active\_map\_handle\(\) will return a reference to the same instance of [MapHandle](MapHandle.md#).|
|clear\_active\_map\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_active\_map\_handle\(\) will return false and active\_map\_handle\(\) will return the default value.|
|set\_allocated\_active\_map\_handle\(\)|void| [MapHandle](MapHandle.md#) \*|Sets the [MapHandle](MapHandle.md#) object to the field and frees the previous field value if it exists. If the [MapHandle](MapHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MapHandle](MapHandle.md#) object and has\_ [MapHandle](MapHandle.md#)\(\) will return true. Otherwise, if the active\_map\_handle is NULL, the behavior is the same as calling clear\_active\_map\_handle\(\).|
|release\_active\_map\_handle\(\)| [MapHandle](MapHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapHandle](MapHandle.md#) object. After calling this, caller takes the ownership of the allocated [MapHandle](MapHandle.md#) object, has\_active\_map\_handle\(\) will return false, and active\_map\_handle\(\) will return the default value.|
|map\_handles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|map\_handles\(\) const|const [MapHandle](MapHandle.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, map\_handles\_size\(\)\) yields undefined behavior.|
|mutable\_map\_handles\(\)| [MapHandle](MapHandle.md#)\*|int index|Returns a pointer to the mutable [MapHandle](MapHandle.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, map\_handles\_size\(\)\) yields undefined behavior.|
|add\_map\_handles\(\)| [MapHandle](MapHandle.md#)\*|void|Adds a new element and returns a pointer to it. The returned [MapHandle](MapHandle.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapHandle](MapHandle.md#)\).|
|clear\_map\_handles\(\)|void|void|Removes all elements from the field. After calling this, map\_handles\_size\(\) will return zero.|
|map\_handles\(\) const|const RepeatedPtrField< [MapHandle](MapHandle.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_map\_handles\(\)|RepeatedPtrField< [MapHandle](MapHandle.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|application\_data\(\)|const string&|void|Returns the current value of application\_data. If application\_data is not set, returns the empty string/empty bytes.|
|set\_application\_data\(\)|void|const string&|Sets the value of application\_data. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|string&&|\(C++11 and beyond\): Sets the value of application\_data, moving from the passed string. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|const char\*|Sets the value of application\_data using a C-style null-terminated string. After calling this, application\_data\(\) will return a copy of value.|
|mutable\_application\_data\(\)|string \*|void|Returns a pointer to the mutable string object that stores application\_data's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, application\_data\(\) will return whatever value is written into the given string.|
|clear\_application\_data\(\)|void|void|Clears the value of application\_data. After calling this, application\_data\(\) will return the empty string/empty bytes.|
|set\_allocated\_application\_data\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_application\_data\(\).|
|release\_application\_data\(\)|string \*|void|Releases the ownership of application\_data and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and application\_data\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

