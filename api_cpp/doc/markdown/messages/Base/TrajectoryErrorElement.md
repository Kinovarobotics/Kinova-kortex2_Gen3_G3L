# class TrajectoryErrorElement

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|error\_type|uint32|Error type|
|error\_identifier|uint32|This field is deprecated and will be removed in a future release.|
|error\_value|float32|Erroneous value|
|min\_value|float32|Minimum permitted value|
|max\_value|float32|Maximum permitted value|
|index|uint32|Actuator index|
|message|string|Clarification message for the error|
|waypoint\_index|uint32|Waypoint index \(if it applies\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|error\_type\(\) const|uint32|void|Returns the current value of error\_type. If the error\_type is not set, returns 0.|
|set\_error\_type\(\)|void|uint32|Sets the value of error\_type. After calling this, error\_type\(\) will return value.|
|clear\_error\_type\(\)|void|void|Clears the value of error\_type. After calling this, error\_type\(\) will return the empty string/empty bytes.|
|error\_identifier\(\) const|uint32|void|Returns the current value of error\_identifier. If the error\_identifier is not set, returns 0.|
|set\_error\_identifier\(\)|void|uint32|Sets the value of error\_identifier. After calling this, error\_identifier\(\) will return value.|
|clear\_error\_identifier\(\)|void|void|Clears the value of error\_identifier. After calling this, error\_identifier\(\) will return the empty string/empty bytes.|
|error\_value\(\)|float32|void|Returns the current value of error\_value. If the error\_value is not set, returns 0.|
|set\_error\_value\(\)|void|float32|Sets the value of error\_value. After calling this, error\_value\(\) will return value.|
|clear\_error\_value\(\)|void|void|Clears the value of error\_value. After calling this, error\_value\(\) will return 0.|
|min\_value\(\)|float32|void|Returns the current value of min\_value. If the min\_value is not set, returns 0.|
|set\_min\_value\(\)|void|float32|Sets the value of min\_value. After calling this, min\_value\(\) will return value.|
|clear\_min\_value\(\)|void|void|Clears the value of min\_value. After calling this, min\_value\(\) will return 0.|
|max\_value\(\)|float32|void|Returns the current value of max\_value. If the max\_value is not set, returns 0.|
|set\_max\_value\(\)|void|float32|Sets the value of max\_value. After calling this, max\_value\(\) will return value.|
|clear\_max\_value\(\)|void|void|Clears the value of max\_value. After calling this, max\_value\(\) will return 0.|
|index\(\)|uint32|void|Returns the current value of index. If the index is not set, returns 0.|
|set\_index\(\)|void|uint32|Sets the value of index. After calling this, index\(\) will return value.|
|clear\_index\(\)|void|void|Clears the value of index. After calling this, index\(\) will return 0.|
|message\(\)|const string&|void|Returns the current value of message. If message is not set, returns the empty string/empty bytes.|
|set\_message\(\)|void|const string&|Sets the value of message. After calling this, message\(\) will return a copy of value.|
|set\_message\(\)|void|string&&|\(C++11 and beyond\): Sets the value of message, moving from the passed string. After calling this, message\(\) will return a copy of value.|
|set\_message\(\)|void|const char\*|Sets the value of message using a C-style null-terminated string. After calling this, message\(\) will return a copy of value.|
|mutable\_message\(\)|string \*|void|Returns a pointer to the mutable string object that stores message's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, message\(\) will return whatever value is written into the given string.|
|clear\_message\(\)|void|void|Clears the value of message. After calling this, message\(\) will return the empty string/empty bytes.|
|set\_allocated\_message\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_message\(\).|
|release\_message\(\)|string \*|void|Releases the ownership of message and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and message\(\) will return the empty string/empty bytes.|
|waypoint\_index\(\)|uint32|void|Returns the current value of waypoint\_index. If the waypoint\_index is not set, returns 0.|
|set\_waypoint\_index\(\)|void|uint32|Sets the value of waypoint\_index. After calling this, waypoint\_index\(\) will return value.|
|clear\_waypoint\_index\(\)|void|void|Clears the value of waypoint\_index. After calling this, waypoint\_index\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

