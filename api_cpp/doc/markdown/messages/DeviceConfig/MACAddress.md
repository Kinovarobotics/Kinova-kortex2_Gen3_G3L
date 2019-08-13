# class MACAddress

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mac\_address|uint8\[\]|MAC address|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|mac\_address\(\)|const string&|void|Returns the current value of mac\_address. If mac\_address is not set, returns the empty string/empty bytes.|
|set\_mac\_address\(\)|void|const string&|Sets the value of mac\_address. After calling this, mac\_address\(\) will return a copy of value.|
|set\_mac\_address\(\)|void|string&&|\(C++11 and beyond\): Sets the value of mac\_address, moving from the passed string. After calling this, mac\_address\(\) will return a copy of value.|
|set\_mac\_address\(\)|void|const char\*|Sets the value of mac\_address using a C-style null-terminated string. After calling this, mac\_address\(\) will return a copy of value.|
|mutable\_mac\_address\(\)|string \*|void|Returns a pointer to the mutable string object that stores mac\_address's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, mac\_address\(\) will return whatever value is written into the given string.|
|clear\_mac\_address\(\)|void|void|Clears the value of mac\_address. After calling this, mac\_address\(\) will return the empty string/empty bytes.|
|set\_allocated\_mac\_address\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_mac\_address\(\).|
|release\_mac\_address\(\)|string \*|void|Releases the ownership of mac\_address and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and mac\_address\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

