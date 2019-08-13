# class FullUserProfile

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|user\_profile| [UserProfile](UserProfile.md#)|Information about the user, including its username.|
|password|string|User's password|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_user\_profile\(\) const|bool|void|Returns true if user\_profile is set.|
|user\_profile\(\)|const [UserProfile](UserProfile.md#)&|void|Returns the current value of user\_profile. If user\_profile is not set, returns a [UserProfile](UserProfile.md#) with none of its fields set \(possibly user\_profile::default\_instance\(\)\).|
|mutable\_user\_profile\(\)| [UserProfile](UserProfile.md#) \*|void|Returns a pointer to the mutable [UserProfile](UserProfile.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [UserProfile](UserProfile.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfile](UserProfile.md#)\). After calling this, has\_user\_profile\(\) will return true and user\_profile\(\) will return a reference to the same instance of [UserProfile](UserProfile.md#).|
|clear\_user\_profile\(\)|void|void|Clears the value of the field. After calling this, has\_user\_profile\(\) will return false and user\_profile\(\) will return the default value.|
|set\_allocated\_user\_profile\(\)|void| [UserProfile](UserProfile.md#) \*|Sets the [UserProfile](UserProfile.md#) object to the field and frees the previous field value if it exists. If the [UserProfile](UserProfile.md#) pointer is not NULL, the message takes ownership of the allocated [UserProfile](UserProfile.md#) object and has\_ [UserProfile](UserProfile.md#)\(\) will return true. Otherwise, if the user\_profile is NULL, the behavior is the same as calling clear\_user\_profile\(\).|
|release\_user\_profile\(\)| [UserProfile](UserProfile.md#) \*|void|Releases the ownership of the field and returns the pointer of the [UserProfile](UserProfile.md#) object. After calling this, caller takes the ownership of the allocated [UserProfile](UserProfile.md#) object, has\_user\_profile\(\) will return false, and user\_profile\(\) will return the default value.|
|password\(\)|const string&|void|Returns the current value of password. If password is not set, returns the empty string/empty bytes.|
|set\_password\(\)|void|const string&|Sets the value of password. After calling this, password\(\) will return a copy of value.|
|set\_password\(\)|void|string&&|\(C++11 and beyond\): Sets the value of password, moving from the passed string. After calling this, password\(\) will return a copy of value.|
|set\_password\(\)|void|const char\*|Sets the value of password using a C-style null-terminated string. After calling this, password\(\) will return a copy of value.|
|mutable\_password\(\)|string \*|void|Returns a pointer to the mutable string object that stores password's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, password\(\) will return whatever value is written into the given string.|
|clear\_password\(\)|void|void|Clears the value of password. After calling this, password\(\) will return the empty string/empty bytes.|
|set\_allocated\_password\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_password\(\).|
|release\_password\(\)|string \*|void|Releases the ownership of password and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and password\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

