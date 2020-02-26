# class FirmwareBundleVersions

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|main\_bundle\_version|string|Version of the main bundle|
|components\_versions| [FirmwareComponentVersion](FirmwareComponentVersion.md#)|List containing all components of the bundle|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|main\_bundle\_version\(\)|const string&|void|Returns the current value of main\_bundle\_version. If main\_bundle\_version is not set, returns the empty string/empty bytes.|
|set\_main\_bundle\_version\(\)|void|const string&|Sets the value of main\_bundle\_version. After calling this, main\_bundle\_version\(\) will return a copy of value.|
|set\_main\_bundle\_version\(\)|void|string&&|\(C++11 and beyond\): Sets the value of main\_bundle\_version, moving from the passed string. After calling this, main\_bundle\_version\(\) will return a copy of value.|
|set\_main\_bundle\_version\(\)|void|const char\*|Sets the value of main\_bundle\_version using a C-style null-terminated string. After calling this, main\_bundle\_version\(\) will return a copy of value.|
|mutable\_main\_bundle\_version\(\)|string \*|void|Returns a pointer to the mutable string object that stores main\_bundle\_version's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, main\_bundle\_version\(\) will return whatever value is written into the given string.|
|clear\_main\_bundle\_version\(\)|void|void|Clears the value of main\_bundle\_version. After calling this, main\_bundle\_version\(\) will return the empty string/empty bytes.|
|set\_allocated\_main\_bundle\_version\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_main\_bundle\_version\(\).|
|release\_main\_bundle\_version\(\)|string \*|void|Releases the ownership of main\_bundle\_version and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and main\_bundle\_version\(\) will return the empty string/empty bytes.|
|components\_versions\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|components\_versions\(\) const|const [FirmwareComponentVersion](FirmwareComponentVersion.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, components\_versions\_size\(\)\) yields undefined behavior.|
|mutable\_components\_versions\(\)| [FirmwareComponentVersion](FirmwareComponentVersion.md#)\*|int index|Returns a pointer to the mutable [FirmwareComponentVersion](FirmwareComponentVersion.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, components\_versions\_size\(\)\) yields undefined behavior.|
|add\_components\_versions\(\)| [FirmwareComponentVersion](FirmwareComponentVersion.md#)\*|void|Adds a new element and returns a pointer to it. The returned [FirmwareComponentVersion](FirmwareComponentVersion.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [FirmwareComponentVersion](FirmwareComponentVersion.md#)\).|
|clear\_components\_versions\(\)|void|void|Removes all elements from the field. After calling this, components\_versions\_size\(\) will return zero.|
|components\_versions\(\) const|const RepeatedPtrField< [FirmwareComponentVersion](FirmwareComponentVersion.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_components\_versions\(\)|RepeatedPtrField< [FirmwareComponentVersion](FirmwareComponentVersion.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

