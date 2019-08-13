# class SafetyNotification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|safety\_handle| [SafetyHandle](SafetyHandle.md#)|Safety handle|
|value|uint32|New safety status|
|timestamp| [Timestamp](Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](UserProfileHandle.md#)|User that caused the safety event|
|connection| [Connection](Connection.md#)|Connection that caused the safety event|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_safety\_handle\(\) const|bool|void|Returns true if safety\_handle is set.|
|safety\_handle\(\)|const [SafetyHandle](SafetyHandle.md#)&|void|Returns the current value of safety\_handle. If safety\_handle is not set, returns a [SafetyHandle](SafetyHandle.md#) with none of its fields set \(possibly safety\_handle::default\_instance\(\)\).|
|mutable\_safety\_handle\(\)| [SafetyHandle](SafetyHandle.md#) \*|void|Returns a pointer to the mutable [SafetyHandle](SafetyHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SafetyHandle](SafetyHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyHandle](SafetyHandle.md#)\). After calling this, has\_safety\_handle\(\) will return true and safety\_handle\(\) will return a reference to the same instance of [SafetyHandle](SafetyHandle.md#).|
|clear\_safety\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_safety\_handle\(\) will return false and safety\_handle\(\) will return the default value.|
|set\_allocated\_safety\_handle\(\)|void| [SafetyHandle](SafetyHandle.md#) \*|Sets the [SafetyHandle](SafetyHandle.md#) object to the field and frees the previous field value if it exists. If the [SafetyHandle](SafetyHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SafetyHandle](SafetyHandle.md#) object and has\_ [SafetyHandle](SafetyHandle.md#)\(\) will return true. Otherwise, if the safety\_handle is NULL, the behavior is the same as calling clear\_safety\_handle\(\).|
|release\_safety\_handle\(\)| [SafetyHandle](SafetyHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SafetyHandle](SafetyHandle.md#) object. After calling this, caller takes the ownership of the allocated [SafetyHandle](SafetyHandle.md#) object, has\_safety\_handle\(\) will return false, and safety\_handle\(\) will return the default value.|
|value\(\) const|uint32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|uint32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return the empty string/empty bytes.|
|has\_timestamp\(\) const|bool|void|Returns true if timestamp is set.|
|timestamp\(\)|const [Timestamp](Timestamp.md#)&|void|Returns the current value of timestamp. If timestamp is not set, returns a [Timestamp](Timestamp.md#) with none of its fields set \(possibly timestamp::default\_instance\(\)\).|
|mutable\_timestamp\(\)| [Timestamp](Timestamp.md#) \*|void|Returns a pointer to the mutable [Timestamp](Timestamp.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Timestamp](Timestamp.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Timestamp](Timestamp.md#)\). After calling this, has\_timestamp\(\) will return true and timestamp\(\) will return a reference to the same instance of [Timestamp](Timestamp.md#).|
|clear\_timestamp\(\)|void|void|Clears the value of the field. After calling this, has\_timestamp\(\) will return false and timestamp\(\) will return the default value.|
|set\_allocated\_timestamp\(\)|void| [Timestamp](Timestamp.md#) \*|Sets the [Timestamp](Timestamp.md#) object to the field and frees the previous field value if it exists. If the [Timestamp](Timestamp.md#) pointer is not NULL, the message takes ownership of the allocated [Timestamp](Timestamp.md#) object and has\_ [Timestamp](Timestamp.md#)\(\) will return true. Otherwise, if the timestamp is NULL, the behavior is the same as calling clear\_timestamp\(\).|
|release\_timestamp\(\)| [Timestamp](Timestamp.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Timestamp](Timestamp.md#) object. After calling this, caller takes the ownership of the allocated [Timestamp](Timestamp.md#) object, has\_timestamp\(\) will return false, and timestamp\(\) will return the default value.|
|has\_user\_handle\(\) const|bool|void|Returns true if user\_handle is set.|
|user\_handle\(\)|const [UserProfileHandle](UserProfileHandle.md#)&|void|Returns the current value of user\_handle. If user\_handle is not set, returns a [UserProfileHandle](UserProfileHandle.md#) with none of its fields set \(possibly user\_handle::default\_instance\(\)\).|
|mutable\_user\_handle\(\)| [UserProfileHandle](UserProfileHandle.md#) \*|void|Returns a pointer to the mutable [UserProfileHandle](UserProfileHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [UserProfileHandle](UserProfileHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfileHandle](UserProfileHandle.md#)\). After calling this, has\_user\_handle\(\) will return true and user\_handle\(\) will return a reference to the same instance of [UserProfileHandle](UserProfileHandle.md#).|
|clear\_user\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_user\_handle\(\) will return false and user\_handle\(\) will return the default value.|
|set\_allocated\_user\_handle\(\)|void| [UserProfileHandle](UserProfileHandle.md#) \*|Sets the [UserProfileHandle](UserProfileHandle.md#) object to the field and frees the previous field value if it exists. If the [UserProfileHandle](UserProfileHandle.md#) pointer is not NULL, the message takes ownership of the allocated [UserProfileHandle](UserProfileHandle.md#) object and has\_ [UserProfileHandle](UserProfileHandle.md#)\(\) will return true. Otherwise, if the user\_handle is NULL, the behavior is the same as calling clear\_user\_handle\(\).|
|release\_user\_handle\(\)| [UserProfileHandle](UserProfileHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [UserProfileHandle](UserProfileHandle.md#) object. After calling this, caller takes the ownership of the allocated [UserProfileHandle](UserProfileHandle.md#) object, has\_user\_handle\(\) will return false, and user\_handle\(\) will return the default value.|
|has\_connection\(\) const|bool|void|Returns true if connection is set.|
|connection\(\)|const [Connection](Connection.md#)&|void|Returns the current value of connection. If connection is not set, returns a [Connection](Connection.md#) with none of its fields set \(possibly connection::default\_instance\(\)\).|
|mutable\_connection\(\)| [Connection](Connection.md#) \*|void|Returns a pointer to the mutable [Connection](Connection.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Connection](Connection.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Connection](Connection.md#)\). After calling this, has\_connection\(\) will return true and connection\(\) will return a reference to the same instance of [Connection](Connection.md#).|
|clear\_connection\(\)|void|void|Clears the value of the field. After calling this, has\_connection\(\) will return false and connection\(\) will return the default value.|
|set\_allocated\_connection\(\)|void| [Connection](Connection.md#) \*|Sets the [Connection](Connection.md#) object to the field and frees the previous field value if it exists. If the [Connection](Connection.md#) pointer is not NULL, the message takes ownership of the allocated [Connection](Connection.md#) object and has\_ [Connection](Connection.md#)\(\) will return true. Otherwise, if the connection is NULL, the behavior is the same as calling clear\_connection\(\).|
|release\_connection\(\)| [Connection](Connection.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Connection](Connection.md#) object. After calling this, caller takes the ownership of the allocated [Connection](Connection.md#) object, has\_connection\(\) will return false, and connection\(\) will return the default value.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

