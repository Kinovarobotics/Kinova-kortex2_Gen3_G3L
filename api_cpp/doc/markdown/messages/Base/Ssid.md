# class Ssid

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|string|Wi-Fi Service Set Identifier|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\)|const string&|void|Returns the current value of identifier. If identifier is not set, returns the empty string/empty bytes.|
|set\_identifier\(\)|void|const string&|Sets the value of identifier. After calling this, identifier\(\) will return a copy of value.|
|set\_identifier\(\)|void|string&&|\(C++11 and beyond\): Sets the value of identifier, moving from the passed string. After calling this, identifier\(\) will return a copy of value.|
|set\_identifier\(\)|void|const char\*|Sets the value of identifier using a C-style null-terminated string. After calling this, identifier\(\) will return a copy of value.|
|mutable\_identifier\(\)|string \*|void|Returns a pointer to the mutable string object that stores identifier's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, identifier\(\) will return whatever value is written into the given string.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return the empty string/empty bytes.|
|set\_allocated\_identifier\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_identifier\(\).|
|release\_identifier\(\)|string \*|void|Releases the ownership of identifier and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and identifier\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

