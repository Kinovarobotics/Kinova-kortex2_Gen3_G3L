# class PartNumberRevision

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|part\_number\_revision|string|Part number revision|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|part\_number\_revision\(\)|const string&|void|Returns the current value of part\_number\_revision. If part\_number\_revision is not set, returns the empty string/empty bytes.|
|set\_part\_number\_revision\(\)|void|const string&|Sets the value of part\_number\_revision. After calling this, part\_number\_revision\(\) will return a copy of value.|
|set\_part\_number\_revision\(\)|void|string&&|\(C++11 and beyond\): Sets the value of part\_number\_revision, moving from the passed string. After calling this, part\_number\_revision\(\) will return a copy of value.|
|set\_part\_number\_revision\(\)|void|const char\*|Sets the value of part\_number\_revision using a C-style null-terminated string. After calling this, part\_number\_revision\(\) will return a copy of value.|
|mutable\_part\_number\_revision\(\)|string \*|void|Returns a pointer to the mutable string object that stores part\_number\_revision's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, part\_number\_revision\(\) will return whatever value is written into the given string.|
|clear\_part\_number\_revision\(\)|void|void|Clears the value of part\_number\_revision. After calling this, part\_number\_revision\(\) will return the empty string/empty bytes.|
|set\_allocated\_part\_number\_revision\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_part\_number\_revision\(\).|
|release\_part\_number\_revision\(\)|string \*|void|Releases the ownership of part\_number\_revision and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and part\_number\_revision\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

