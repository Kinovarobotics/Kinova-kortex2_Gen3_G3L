# class PasswordChange

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User handle|
|old\_password|string|Current password|
|new\_password|string|New password|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [UserProfileHandle](../Common/UserProfileHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [UserProfileHandle](../Common/UserProfileHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|void|Returns a pointer to the mutable [UserProfileHandle](../Common/UserProfileHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [UserProfileHandle](../Common/UserProfileHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfileHandle](../Common/UserProfileHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [UserProfileHandle](../Common/UserProfileHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|Sets the [UserProfileHandle](../Common/UserProfileHandle.md#) object to the field and frees the previous field value if it exists. If the [UserProfileHandle](../Common/UserProfileHandle.md#) pointer is not NULL, the message takes ownership of the allocated [UserProfileHandle](../Common/UserProfileHandle.md#) object and has\_ [UserProfileHandle](../Common/UserProfileHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [UserProfileHandle](../Common/UserProfileHandle.md#) object. After calling this, caller takes the ownership of the allocated [UserProfileHandle](../Common/UserProfileHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|old\_password\(\)|const string&|void|Returns the current value of old\_password. If old\_password is not set, returns the empty string/empty bytes.|
|set\_old\_password\(\)|void|const string&|Sets the value of old\_password. After calling this, old\_password\(\) will return a copy of value.|
|set\_old\_password\(\)|void|string&&|\(C++11 and beyond\): Sets the value of old\_password, moving from the passed string. After calling this, old\_password\(\) will return a copy of value.|
|set\_old\_password\(\)|void|const char\*|Sets the value of old\_password using a C-style null-terminated string. After calling this, old\_password\(\) will return a copy of value.|
|mutable\_old\_password\(\)|string \*|void|Returns a pointer to the mutable string object that stores old\_password's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, old\_password\(\) will return whatever value is written into the given string.|
|clear\_old\_password\(\)|void|void|Clears the value of old\_password. After calling this, old\_password\(\) will return the empty string/empty bytes.|
|set\_allocated\_old\_password\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_old\_password\(\).|
|release\_old\_password\(\)|string \*|void|Releases the ownership of old\_password and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and old\_password\(\) will return the empty string/empty bytes.|
|new\_password\(\)|const string&|void|Returns the current value of new\_password. If new\_password is not set, returns the empty string/empty bytes.|
|set\_new\_password\(\)|void|const string&|Sets the value of new\_password. After calling this, new\_password\(\) will return a copy of value.|
|set\_new\_password\(\)|void|string&&|\(C++11 and beyond\): Sets the value of new\_password, moving from the passed string. After calling this, new\_password\(\) will return a copy of value.|
|set\_new\_password\(\)|void|const char\*|Sets the value of new\_password using a C-style null-terminated string. After calling this, new\_password\(\) will return a copy of value.|
|mutable\_new\_password\(\)|string \*|void|Returns a pointer to the mutable string object that stores new\_password's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, new\_password\(\) will return whatever value is written into the given string.|
|clear\_new\_password\(\)|void|void|Clears the value of new\_password. After calling this, new\_password\(\) will return the empty string/empty bytes.|
|set\_allocated\_new\_password\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_new\_password\(\).|
|release\_new\_password\(\)|string \*|void|Releases the ownership of new\_password and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and new\_password\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

