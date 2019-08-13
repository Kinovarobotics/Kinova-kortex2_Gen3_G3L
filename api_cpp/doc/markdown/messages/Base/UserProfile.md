# class UserProfile

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User handle \(no need to set it with CreateUserProfile\(\)\)|
|username|string|Username, which is used to connect to robot \(or login via Web App\)|
|firstname|string|User's first name|
|lastname|string|User's last name|
|application\_data|string|Application data \(reserved for use by Web App\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [UserProfileHandle](../Common/UserProfileHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [UserProfileHandle](../Common/UserProfileHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|void|Returns a pointer to the mutable [UserProfileHandle](../Common/UserProfileHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [UserProfileHandle](../Common/UserProfileHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfileHandle](../Common/UserProfileHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [UserProfileHandle](../Common/UserProfileHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|Sets the [UserProfileHandle](../Common/UserProfileHandle.md#) object to the field and frees the previous field value if it exists. If the [UserProfileHandle](../Common/UserProfileHandle.md#) pointer is not NULL, the message takes ownership of the allocated [UserProfileHandle](../Common/UserProfileHandle.md#) object and has\_ [UserProfileHandle](../Common/UserProfileHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [UserProfileHandle](../Common/UserProfileHandle.md#) object. After calling this, caller takes the ownership of the allocated [UserProfileHandle](../Common/UserProfileHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|username\(\)|const string&|void|Returns the current value of username. If username is not set, returns the empty string/empty bytes.|
|set\_username\(\)|void|const string&|Sets the value of username. After calling this, username\(\) will return a copy of value.|
|set\_username\(\)|void|string&&|\(C++11 and beyond\): Sets the value of username, moving from the passed string. After calling this, username\(\) will return a copy of value.|
|set\_username\(\)|void|const char\*|Sets the value of username using a C-style null-terminated string. After calling this, username\(\) will return a copy of value.|
|mutable\_username\(\)|string \*|void|Returns a pointer to the mutable string object that stores username's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, username\(\) will return whatever value is written into the given string.|
|clear\_username\(\)|void|void|Clears the value of username. After calling this, username\(\) will return the empty string/empty bytes.|
|set\_allocated\_username\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_username\(\).|
|release\_username\(\)|string \*|void|Releases the ownership of username and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and username\(\) will return the empty string/empty bytes.|
|firstname\(\)|const string&|void|Returns the current value of firstname. If firstname is not set, returns the empty string/empty bytes.|
|set\_firstname\(\)|void|const string&|Sets the value of firstname. After calling this, firstname\(\) will return a copy of value.|
|set\_firstname\(\)|void|string&&|\(C++11 and beyond\): Sets the value of firstname, moving from the passed string. After calling this, firstname\(\) will return a copy of value.|
|set\_firstname\(\)|void|const char\*|Sets the value of firstname using a C-style null-terminated string. After calling this, firstname\(\) will return a copy of value.|
|mutable\_firstname\(\)|string \*|void|Returns a pointer to the mutable string object that stores firstname's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, firstname\(\) will return whatever value is written into the given string.|
|clear\_firstname\(\)|void|void|Clears the value of firstname. After calling this, firstname\(\) will return the empty string/empty bytes.|
|set\_allocated\_firstname\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_firstname\(\).|
|release\_firstname\(\)|string \*|void|Releases the ownership of firstname and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and firstname\(\) will return the empty string/empty bytes.|
|lastname\(\)|const string&|void|Returns the current value of lastname. If lastname is not set, returns the empty string/empty bytes.|
|set\_lastname\(\)|void|const string&|Sets the value of lastname. After calling this, lastname\(\) will return a copy of value.|
|set\_lastname\(\)|void|string&&|\(C++11 and beyond\): Sets the value of lastname, moving from the passed string. After calling this, lastname\(\) will return a copy of value.|
|set\_lastname\(\)|void|const char\*|Sets the value of lastname using a C-style null-terminated string. After calling this, lastname\(\) will return a copy of value.|
|mutable\_lastname\(\)|string \*|void|Returns a pointer to the mutable string object that stores lastname's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, lastname\(\) will return whatever value is written into the given string.|
|clear\_lastname\(\)|void|void|Clears the value of lastname. After calling this, lastname\(\) will return the empty string/empty bytes.|
|set\_allocated\_lastname\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_lastname\(\).|
|release\_lastname\(\)|string \*|void|Releases the ownership of lastname and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and lastname\(\) will return the empty string/empty bytes.|
|application\_data\(\)|const string&|void|Returns the current value of application\_data. If application\_data is not set, returns the empty string/empty bytes.|
|set\_application\_data\(\)|void|const string&|Sets the value of application\_data. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|string&&|\(C++11 and beyond\): Sets the value of application\_data, moving from the passed string. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|const char\*|Sets the value of application\_data using a C-style null-terminated string. After calling this, application\_data\(\) will return a copy of value.|
|mutable\_application\_data\(\)|string \*|void|Returns a pointer to the mutable string object that stores application\_data's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, application\_data\(\) will return whatever value is written into the given string.|
|clear\_application\_data\(\)|void|void|Clears the value of application\_data. After calling this, application\_data\(\) will return the empty string/empty bytes.|
|set\_allocated\_application\_data\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_application\_data\(\).|
|release\_application\_data\(\)|string \*|void|Releases the ownership of application\_data and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and application\_data\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

