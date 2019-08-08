# class Connection

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|user\_handle| [UserProfileHandle](UserProfileHandle.md#)|User profile handle, or set to zero if no user logged in|
|connection\_information|string|Connection info \(e.g. IP address with port number\)|
|connection\_identifier|uint32|Connection identifier|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_user\_handle\(\) const|bool|void|Returns true if user\_handle is set.|
|user\_handle\(\)|const [UserProfileHandle](UserProfileHandle.md#)&|void|Returns the current value of user\_handle. If user\_handle is not set, returns a [UserProfileHandle](UserProfileHandle.md#) with none of its fields set \(possibly user\_handle::default\_instance\(\)\).|
|mutable\_user\_handle\(\)| [UserProfileHandle](UserProfileHandle.md#) \*|void|Returns a pointer to the mutable [UserProfileHandle](UserProfileHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [UserProfileHandle](UserProfileHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfileHandle](UserProfileHandle.md#)\). After calling this, has\_user\_handle\(\) will return true and user\_handle\(\) will return a reference to the same instance of [UserProfileHandle](UserProfileHandle.md#).|
|clear\_user\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_user\_handle\(\) will return false and user\_handle\(\) will return the default value.|
|set\_allocated\_user\_handle\(\)|void| [UserProfileHandle](UserProfileHandle.md#) \*|Sets the [UserProfileHandle](UserProfileHandle.md#) object to the field and frees the previous field value if it exists. If the [UserProfileHandle](UserProfileHandle.md#) pointer is not NULL, the message takes ownership of the allocated [UserProfileHandle](UserProfileHandle.md#) object and has\_ [UserProfileHandle](UserProfileHandle.md#)\(\) will return true. Otherwise, if the user\_handle is NULL, the behavior is the same as calling clear\_user\_handle\(\).|
|release\_user\_handle\(\)| [UserProfileHandle](UserProfileHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [UserProfileHandle](UserProfileHandle.md#) object. After calling this, caller takes the ownership of the allocated [UserProfileHandle](UserProfileHandle.md#) object, has\_user\_handle\(\) will return false, and user\_handle\(\) will return the default value.|
|connection\_information\(\)|const string&|void|Returns the current value of connection\_information. If connection\_information is not set, returns the empty string/empty bytes.|
|set\_connection\_information\(\)|void|const string&|Sets the value of connection\_information. After calling this, connection\_information\(\) will return a copy of value.|
|set\_connection\_information\(\)|void|string&&|\(C++11 and beyond\): Sets the value of connection\_information, moving from the passed string. After calling this, connection\_information\(\) will return a copy of value.|
|set\_connection\_information\(\)|void|const char\*|Sets the value of connection\_information using a C-style null-terminated string. After calling this, connection\_information\(\) will return a copy of value.|
|mutable\_connection\_information\(\)|string \*|void|Returns a pointer to the mutable string object that stores connection\_information's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, connection\_information\(\) will return whatever value is written into the given string.|
|clear\_connection\_information\(\)|void|void|Clears the value of connection\_information. After calling this, connection\_information\(\) will return the empty string/empty bytes.|
|set\_allocated\_connection\_information\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_connection\_information\(\).|
|release\_connection\_information\(\)|string \*|void|Releases the ownership of connection\_information and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and connection\_information\(\) will return the empty string/empty bytes.|
|connection\_identifier\(\)|uint32|void|Returns the current value of connection\_identifier. If the connection\_identifier is not set, returns 0.|
|set\_connection\_identifier\(\)|void|uint32|Sets the value of connection\_identifier. After calling this, connection\_identifier\(\) will return value.|
|clear\_connection\_identifier\(\)|void|void|Clears the value of connection\_identifier. After calling this, connection\_identifier\(\) will return 0.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

