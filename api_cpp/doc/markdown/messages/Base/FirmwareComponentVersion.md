# class FirmwareComponentVersion

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|name|string|Name of the component|
|version|string|Version of the component|
|device\_id|uint32|Device id of the component|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|name\(\)|const string&|void|Returns the current value of name. If name is not set, returns the empty string/empty bytes.|
|set\_name\(\)|void|const string&|Sets the value of name. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|string&&|\(C++11 and beyond\): Sets the value of name, moving from the passed string. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|const char\*|Sets the value of name using a C-style null-terminated string. After calling this, name\(\) will return a copy of value.|
|mutable\_name\(\)|string \*|void|Returns a pointer to the mutable string object that stores name's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, name\(\) will return whatever value is written into the given string.|
|clear\_name\(\)|void|void|Clears the value of name. After calling this, name\(\) will return the empty string/empty bytes.|
|set\_allocated\_name\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_name\(\).|
|release\_name\(\)|string \*|void|Releases the ownership of name and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and name\(\) will return the empty string/empty bytes.|
|version\(\)|const string&|void|Returns the current value of version. If version is not set, returns the empty string/empty bytes.|
|set\_version\(\)|void|const string&|Sets the value of version. After calling this, version\(\) will return a copy of value.|
|set\_version\(\)|void|string&&|\(C++11 and beyond\): Sets the value of version, moving from the passed string. After calling this, version\(\) will return a copy of value.|
|set\_version\(\)|void|const char\*|Sets the value of version using a C-style null-terminated string. After calling this, version\(\) will return a copy of value.|
|mutable\_version\(\)|string \*|void|Returns a pointer to the mutable string object that stores version's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, version\(\) will return whatever value is written into the given string.|
|clear\_version\(\)|void|void|Clears the value of version. After calling this, version\(\) will return the empty string/empty bytes.|
|set\_allocated\_version\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_version\(\).|
|release\_version\(\)|string \*|void|Releases the ownership of version and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and version\(\) will return the empty string/empty bytes.|
|device\_id\(\)|uint32|void|Returns the current value of device\_id. If the device\_id is not set, returns 0.|
|set\_device\_id\(\)|void|uint32|Sets the value of device\_id. After calling this, device\_id\(\) will return value.|
|clear\_device\_id\(\)|void|void|Clears the value of device\_id. After calling this, device\_id\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

