# class FactoryNotification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event|uint32|Event type|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the factory event to occur|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the factory event to occur|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|event\(\) const|uint32|void|Returns the current value of event. If the event is not set, returns 0.|
|set\_event\(\)|void|uint32|Sets the value of event. After calling this, event\(\) will return value.|
|clear\_event\(\)|void|void|Clears the value of event. After calling this, event\(\) will return the empty string/empty bytes.|
|has\_timestamp\(\) const|bool|void|Returns true if timestamp is set.|
|timestamp\(\)|const [Timestamp](../Common/Timestamp.md#)&|void|Returns the current value of timestamp. If timestamp is not set, returns a [Timestamp](../Common/Timestamp.md#) with none of its fields set \(possibly timestamp::default\_instance\(\)\).|
|mutable\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Returns a pointer to the mutable [Timestamp](../Common/Timestamp.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Timestamp](../Common/Timestamp.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Timestamp](../Common/Timestamp.md#)\). After calling this, has\_timestamp\(\) will return true and timestamp\(\) will return a reference to the same instance of [Timestamp](../Common/Timestamp.md#).|
|clear\_timestamp\(\)|void|void|Clears the value of the field. After calling this, has\_timestamp\(\) will return false and timestamp\(\) will return the default value.|
|set\_allocated\_timestamp\(\)|void| [Timestamp](../Common/Timestamp.md#) \*|Sets the [Timestamp](../Common/Timestamp.md#) object to the field and frees the previous field value if it exists. If the [Timestamp](../Common/Timestamp.md#) pointer is not NULL, the message takes ownership of the allocated [Timestamp](../Common/Timestamp.md#) object and has\_ [Timestamp](../Common/Timestamp.md#)\(\) will return true. Otherwise, if the timestamp is NULL, the behavior is the same as calling clear\_timestamp\(\).|
|release\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Timestamp](../Common/Timestamp.md#) object. After calling this, caller takes the ownership of the allocated [Timestamp](../Common/Timestamp.md#) object, has\_timestamp\(\) will return false, and timestamp\(\) will return the default value.|
|has\_user\_handle\(\) const|bool|void|Returns true if user\_handle is set.|
|user\_handle\(\)|const [UserProfileHandle](../Common/UserProfileHandle.md#)&|void|Returns the current value of user\_handle. If user\_handle is not set, returns a [UserProfileHandle](../Common/UserProfileHandle.md#) with none of its fields set \(possibly user\_handle::default\_instance\(\)\).|
|mutable\_user\_handle\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|void|Returns a pointer to the mutable [UserProfileHandle](../Common/UserProfileHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [UserProfileHandle](../Common/UserProfileHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfileHandle](../Common/UserProfileHandle.md#)\). After calling this, has\_user\_handle\(\) will return true and user\_handle\(\) will return a reference to the same instance of [UserProfileHandle](../Common/UserProfileHandle.md#).|
|clear\_user\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_user\_handle\(\) will return false and user\_handle\(\) will return the default value.|
|set\_allocated\_user\_handle\(\)|void| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|Sets the [UserProfileHandle](../Common/UserProfileHandle.md#) object to the field and frees the previous field value if it exists. If the [UserProfileHandle](../Common/UserProfileHandle.md#) pointer is not NULL, the message takes ownership of the allocated [UserProfileHandle](../Common/UserProfileHandle.md#) object and has\_ [UserProfileHandle](../Common/UserProfileHandle.md#)\(\) will return true. Otherwise, if the user\_handle is NULL, the behavior is the same as calling clear\_user\_handle\(\).|
|release\_user\_handle\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [UserProfileHandle](../Common/UserProfileHandle.md#) object. After calling this, caller takes the ownership of the allocated [UserProfileHandle](../Common/UserProfileHandle.md#) object, has\_user\_handle\(\) will return false, and user\_handle\(\) will return the default value.|
|has\_connection\(\) const|bool|void|Returns true if connection is set.|
|connection\(\)|const [Connection](../Common/Connection.md#)&|void|Returns the current value of connection. If connection is not set, returns a [Connection](../Common/Connection.md#) with none of its fields set \(possibly connection::default\_instance\(\)\).|
|mutable\_connection\(\)| [Connection](../Common/Connection.md#) \*|void|Returns a pointer to the mutable [Connection](../Common/Connection.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Connection](../Common/Connection.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Connection](../Common/Connection.md#)\). After calling this, has\_connection\(\) will return true and connection\(\) will return a reference to the same instance of [Connection](../Common/Connection.md#).|
|clear\_connection\(\)|void|void|Clears the value of the field. After calling this, has\_connection\(\) will return false and connection\(\) will return the default value.|
|set\_allocated\_connection\(\)|void| [Connection](../Common/Connection.md#) \*|Sets the [Connection](../Common/Connection.md#) object to the field and frees the previous field value if it exists. If the [Connection](../Common/Connection.md#) pointer is not NULL, the message takes ownership of the allocated [Connection](../Common/Connection.md#) object and has\_ [Connection](../Common/Connection.md#)\(\) will return true. Otherwise, if the connection is NULL, the behavior is the same as calling clear\_connection\(\).|
|release\_connection\(\)| [Connection](../Common/Connection.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Connection](../Common/Connection.md#) object. After calling this, caller takes the ownership of the allocated [Connection](../Common/Connection.md#) object, has\_connection\(\) will return false, and connection\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

