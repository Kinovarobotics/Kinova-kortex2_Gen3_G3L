# class Query

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|start\_timestamp| [Timestamp](../Common/Timestamp.md#)|Start timestamp \(set to zero to specify it\)|
|end\_timestamp| [Timestamp](../Common/Timestamp.md#)|End timestamp \(set to zero to not specify it\)|
|username|string|Queried username \(set to "" to not specify it\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_start\_timestamp\(\) const|bool|void|Returns true if start\_timestamp is set.|
|start\_timestamp\(\)|const [Timestamp](../Common/Timestamp.md#)&|void|Returns the current value of start\_timestamp. If start\_timestamp is not set, returns a [Timestamp](../Common/Timestamp.md#) with none of its fields set \(possibly start\_timestamp::default\_instance\(\)\).|
|mutable\_start\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Returns a pointer to the mutable [Timestamp](../Common/Timestamp.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Timestamp](../Common/Timestamp.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Timestamp](../Common/Timestamp.md#)\). After calling this, has\_start\_timestamp\(\) will return true and start\_timestamp\(\) will return a reference to the same instance of [Timestamp](../Common/Timestamp.md#).|
|clear\_start\_timestamp\(\)|void|void|Clears the value of the field. After calling this, has\_start\_timestamp\(\) will return false and start\_timestamp\(\) will return the default value.|
|set\_allocated\_start\_timestamp\(\)|void| [Timestamp](../Common/Timestamp.md#) \*|Sets the [Timestamp](../Common/Timestamp.md#) object to the field and frees the previous field value if it exists. If the [Timestamp](../Common/Timestamp.md#) pointer is not NULL, the message takes ownership of the allocated [Timestamp](../Common/Timestamp.md#) object and has\_ [Timestamp](../Common/Timestamp.md#)\(\) will return true. Otherwise, if the start\_timestamp is NULL, the behavior is the same as calling clear\_start\_timestamp\(\).|
|release\_start\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Timestamp](../Common/Timestamp.md#) object. After calling this, caller takes the ownership of the allocated [Timestamp](../Common/Timestamp.md#) object, has\_start\_timestamp\(\) will return false, and start\_timestamp\(\) will return the default value.|
|has\_end\_timestamp\(\) const|bool|void|Returns true if end\_timestamp is set.|
|end\_timestamp\(\)|const [Timestamp](../Common/Timestamp.md#)&|void|Returns the current value of end\_timestamp. If end\_timestamp is not set, returns a [Timestamp](../Common/Timestamp.md#) with none of its fields set \(possibly end\_timestamp::default\_instance\(\)\).|
|mutable\_end\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Returns a pointer to the mutable [Timestamp](../Common/Timestamp.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Timestamp](../Common/Timestamp.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Timestamp](../Common/Timestamp.md#)\). After calling this, has\_end\_timestamp\(\) will return true and end\_timestamp\(\) will return a reference to the same instance of [Timestamp](../Common/Timestamp.md#).|
|clear\_end\_timestamp\(\)|void|void|Clears the value of the field. After calling this, has\_end\_timestamp\(\) will return false and end\_timestamp\(\) will return the default value.|
|set\_allocated\_end\_timestamp\(\)|void| [Timestamp](../Common/Timestamp.md#) \*|Sets the [Timestamp](../Common/Timestamp.md#) object to the field and frees the previous field value if it exists. If the [Timestamp](../Common/Timestamp.md#) pointer is not NULL, the message takes ownership of the allocated [Timestamp](../Common/Timestamp.md#) object and has\_ [Timestamp](../Common/Timestamp.md#)\(\) will return true. Otherwise, if the end\_timestamp is NULL, the behavior is the same as calling clear\_end\_timestamp\(\).|
|release\_end\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Timestamp](../Common/Timestamp.md#) object. After calling this, caller takes the ownership of the allocated [Timestamp](../Common/Timestamp.md#) object, has\_end\_timestamp\(\) will return false, and end\_timestamp\(\) will return the default value.|
|username\(\)|const string&|void|Returns the current value of username. If username is not set, returns the empty string/empty bytes.|
|set\_username\(\)|void|const string&|Sets the value of username. After calling this, username\(\) will return a copy of value.|
|set\_username\(\)|void|string&&|\(C++11 and beyond\): Sets the value of username, moving from the passed string. After calling this, username\(\) will return a copy of value.|
|set\_username\(\)|void|const char\*|Sets the value of username using a C-style null-terminated string. After calling this, username\(\) will return a copy of value.|
|mutable\_username\(\)|string \*|void|Returns a pointer to the mutable string object that stores username's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, username\(\) will return whatever value is written into the given string.|
|clear\_username\(\)|void|void|Clears the value of username. After calling this, username\(\) will return the empty string/empty bytes.|
|set\_allocated\_username\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_username\(\).|
|release\_username\(\)|string \*|void|Releases the ownership of username and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and username\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

