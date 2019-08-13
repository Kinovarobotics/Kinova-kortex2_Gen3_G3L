# class PartNumber

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|part\_number|string|Part number of size 25 including null character|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|part\_number\(\)|const string&|void|Returns the current value of part\_number. If part\_number is not set, returns the empty string/empty bytes.|
|set\_part\_number\(\)|void|const string&|Sets the value of part\_number. After calling this, part\_number\(\) will return a copy of value.|
|set\_part\_number\(\)|void|string&&|\(C++11 and beyond\): Sets the value of part\_number, moving from the passed string. After calling this, part\_number\(\) will return a copy of value.|
|set\_part\_number\(\)|void|const char\*|Sets the value of part\_number using a C-style null-terminated string. After calling this, part\_number\(\) will return a copy of value.|
|mutable\_part\_number\(\)|string \*|void|Returns a pointer to the mutable string object that stores part\_number's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, part\_number\(\) will return whatever value is written into the given string.|
|clear\_part\_number\(\)|void|void|Clears the value of part\_number. After calling this, part\_number\(\) will return the empty string/empty bytes.|
|set\_allocated\_part\_number\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_part\_number\(\).|
|release\_part\_number\(\)|string \*|void|Releases the ownership of part\_number and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and part\_number\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

