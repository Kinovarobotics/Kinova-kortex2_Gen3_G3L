# class I2CData

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|data|uint8\[\]|Data byte\(s\) array \(max 128 bytes\)|
|size|uint32|Data byte\(s\) array size|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|data\(\)|const string&|void|Returns the current value of data. If data is not set, returns the empty string/empty bytes.|
|set\_data\(\)|void|const string&|Sets the value of data. After calling this, data\(\) will return a copy of value.|
|set\_data\(\)|void|string&&|\(C++11 and beyond\): Sets the value of data, moving from the passed string. After calling this, data\(\) will return a copy of value.|
|set\_data\(\)|void|const char\*|Sets the value of data using a C-style null-terminated string. After calling this, data\(\) will return a copy of value.|
|mutable\_data\(\)|string \*|void|Returns a pointer to the mutable string object that stores data's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, data\(\) will return whatever value is written into the given string.|
|clear\_data\(\)|void|void|Clears the value of data. After calling this, data\(\) will return the empty string/empty bytes.|
|set\_allocated\_data\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_data\(\).|
|release\_data\(\)|string \*|void|Releases the ownership of data and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and data\(\) will return the empty string/empty bytes.|
|size\(\)|uint32|void|Returns the current value of size. If the size is not set, returns 0.|
|set\_size\(\)|void|uint32|Sets the value of size. After calling this, size\(\) will return value.|
|clear\_size\(\)|void|void|Clears the value of size. After calling this, size\(\) will return 0.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

