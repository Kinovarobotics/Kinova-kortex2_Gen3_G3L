# class Map

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [MapHandle](MapHandle.md#)|Map handle \(do not set on createMap\(\) call\)|
|name|string|Map friendly name|
|elements| [MapElement](MapElement.md#)|Array of map elements|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [MapHandle](MapHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [MapHandle](MapHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [MapHandle](MapHandle.md#) \*|void|Returns a pointer to the mutable [MapHandle](MapHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapHandle](MapHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapHandle](MapHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [MapHandle](MapHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [MapHandle](MapHandle.md#) \*|Sets the [MapHandle](MapHandle.md#) object to the field and frees the previous field value if it exists. If the [MapHandle](MapHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MapHandle](MapHandle.md#) object and has\_ [MapHandle](MapHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [MapHandle](MapHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapHandle](MapHandle.md#) object. After calling this, caller takes the ownership of the allocated [MapHandle](MapHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|name\(\)|const string&|void|Returns the current value of name. If name is not set, returns the empty string/empty bytes.|
|set\_name\(\)|void|const string&|Sets the value of name. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|string&&|\(C++11 and beyond\): Sets the value of name, moving from the passed string. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|const char\*|Sets the value of name using a C-style null-terminated string. After calling this, name\(\) will return a copy of value.|
|mutable\_name\(\)|string \*|void|Returns a pointer to the mutable string object that stores name's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, name\(\) will return whatever value is written into the given string.|
|clear\_name\(\)|void|void|Clears the value of name. After calling this, name\(\) will return the empty string/empty bytes.|
|set\_allocated\_name\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_name\(\).|
|release\_name\(\)|string \*|void|Releases the ownership of name and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and name\(\) will return the empty string/empty bytes.|
|elements\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|elements\(\) const|const [MapElement](MapElement.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, elements\_size\(\)\) yields undefined behavior.|
|mutable\_elements\(\)| [MapElement](MapElement.md#)\*|int index|Returns a pointer to the mutable [MapElement](MapElement.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, elements\_size\(\)\) yields undefined behavior.|
|add\_elements\(\)| [MapElement](MapElement.md#)\*|void|Adds a new element and returns a pointer to it. The returned [MapElement](MapElement.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapElement](MapElement.md#)\).|
|clear\_elements\(\)|void|void|Removes all elements from the field. After calling this, elements\_size\(\) will return zero.|
|elements\(\) const|const RepeatedPtrField< [MapElement](MapElement.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_elements\(\)|RepeatedPtrField< [MapElement](MapElement.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

