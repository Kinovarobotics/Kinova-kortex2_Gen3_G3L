# class ModelNumber

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|model\_number|string|Model number of size 25 including null character|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|model\_number\(\)|const string&|void|Returns the current value of model\_number. If model\_number is not set, returns the empty string/empty bytes.|
|set\_model\_number\(\)|void|const string&|Sets the value of model\_number. After calling this, model\_number\(\) will return a copy of value.|
|set\_model\_number\(\)|void|string&&|\(C++11 and beyond\): Sets the value of model\_number, moving from the passed string. After calling this, model\_number\(\) will return a copy of value.|
|set\_model\_number\(\)|void|const char\*|Sets the value of model\_number using a C-style null-terminated string. After calling this, model\_number\(\) will return a copy of value.|
|mutable\_model\_number\(\)|string \*|void|Returns a pointer to the mutable string object that stores model\_number's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, model\_number\(\) will return whatever value is written into the given string.|
|clear\_model\_number\(\)|void|void|Clears the value of model\_number. After calling this, model\_number\(\) will return the empty string/empty bytes.|
|set\_allocated\_model\_number\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_model\_number\(\).|
|release\_model\_number\(\)|string \*|void|Releases the ownership of model\_number and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and model\_number\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

