# class CreateSessionInfo

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|username|string|User name|
|session\_inactivity\_timeout|uint32|Inactivity period \(in milliseconds\) allowed before the session times out and closes on its own|
|password|string|Password for the user|
|connection\_inactivity\_timeout|uint32|Inactivity period \(in milliseconds\) allowed before the robot stops any movements initiated from this session|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|username\(\)|const string&|void|Returns the current value of username. If username is not set, returns the empty string/empty bytes.|
|set\_username\(\)|void|const string&|Sets the value of username. After calling this, username\(\) will return a copy of value.|
|set\_username\(\)|void|string&&|\(C++11 and beyond\): Sets the value of username, moving from the passed string. After calling this, username\(\) will return a copy of value.|
|set\_username\(\)|void|const char\*|Sets the value of username using a C-style null-terminated string. After calling this, username\(\) will return a copy of value.|
|mutable\_username\(\)|string \*|void|Returns a pointer to the mutable string object that stores username's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, username\(\) will return whatever value is written into the given string.|
|clear\_username\(\)|void|void|Clears the value of username. After calling this, username\(\) will return the empty string/empty bytes.|
|set\_allocated\_username\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_username\(\).|
|release\_username\(\)|string \*|void|Releases the ownership of username and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and username\(\) will return the empty string/empty bytes.|
|session\_inactivity\_timeout\(\)|uint32|void|Returns the current value of session\_inactivity\_timeout. If the session\_inactivity\_timeout is not set, returns 0.|
|set\_session\_inactivity\_timeout\(\)|void|uint32|Sets the value of session\_inactivity\_timeout. After calling this, session\_inactivity\_timeout\(\) will return value.|
|clear\_session\_inactivity\_timeout\(\)|void|void|Clears the value of session\_inactivity\_timeout. After calling this, session\_inactivity\_timeout\(\) will return 0.|
|password\(\)|const string&|void|Returns the current value of password. If password is not set, returns the empty string/empty bytes.|
|set\_password\(\)|void|const string&|Sets the value of password. After calling this, password\(\) will return a copy of value.|
|set\_password\(\)|void|string&&|\(C++11 and beyond\): Sets the value of password, moving from the passed string. After calling this, password\(\) will return a copy of value.|
|set\_password\(\)|void|const char\*|Sets the value of password using a C-style null-terminated string. After calling this, password\(\) will return a copy of value.|
|mutable\_password\(\)|string \*|void|Returns a pointer to the mutable string object that stores password's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, password\(\) will return whatever value is written into the given string.|
|clear\_password\(\)|void|void|Clears the value of password. After calling this, password\(\) will return the empty string/empty bytes.|
|set\_allocated\_password\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_password\(\).|
|release\_password\(\)|string \*|void|Releases the ownership of password and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and password\(\) will return the empty string/empty bytes.|
|connection\_inactivity\_timeout\(\)|uint32|void|Returns the current value of connection\_inactivity\_timeout. If the connection\_inactivity\_timeout is not set, returns 0.|
|set\_connection\_inactivity\_timeout\(\)|void|uint32|Sets the value of connection\_inactivity\_timeout. After calling this, connection\_inactivity\_timeout\(\) will return value.|
|clear\_connection\_inactivity\_timeout\(\)|void|void|Clears the value of connection\_inactivity\_timeout. After calling this, connection\_inactivity\_timeout\(\) will return 0.|

**Parent topic:** [Session \(C++\)](../../summary_pages/Session.md)

