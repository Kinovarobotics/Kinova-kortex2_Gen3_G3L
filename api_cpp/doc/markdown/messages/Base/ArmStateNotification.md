# class ArmStateNotification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|active\_state|uint32|New arm state|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the arm state event|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|active\_state\(\) const|uint32|void|Returns the current value of active\_state. If the active\_state is not set, returns 0.|
|set\_active\_state\(\)|void|uint32|Sets the value of active\_state. After calling this, active\_state\(\) will return value.|
|clear\_active\_state\(\)|void|void|Clears the value of active\_state. After calling this, active\_state\(\) will return the empty string/empty bytes.|
|has\_timestamp\(\) const|bool|void|Returns true if timestamp is set.|
|timestamp\(\)|const [Timestamp](../Common/Timestamp.md#)&|void|Returns the current value of timestamp. If timestamp is not set, returns a [Timestamp](../Common/Timestamp.md#) with none of its fields set \(possibly timestamp::default\_instance\(\)\).|
|mutable\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Returns a pointer to the mutable [Timestamp](../Common/Timestamp.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Timestamp](../Common/Timestamp.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Timestamp](../Common/Timestamp.md#)\). After calling this, has\_timestamp\(\) will return true and timestamp\(\) will return a reference to the same instance of [Timestamp](../Common/Timestamp.md#).|
|clear\_timestamp\(\)|void|void|Clears the value of the field. After calling this, has\_timestamp\(\) will return false and timestamp\(\) will return the default value.|
|set\_allocated\_timestamp\(\)|void| [Timestamp](../Common/Timestamp.md#) \*|Sets the [Timestamp](../Common/Timestamp.md#) object to the field and frees the previous field value if it exists. If the [Timestamp](../Common/Timestamp.md#) pointer is not NULL, the message takes ownership of the allocated [Timestamp](../Common/Timestamp.md#) object and has\_ [Timestamp](../Common/Timestamp.md#)\(\) will return true. Otherwise, if the timestamp is NULL, the behavior is the same as calling clear\_timestamp\(\).|
|release\_timestamp\(\)| [Timestamp](../Common/Timestamp.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Timestamp](../Common/Timestamp.md#) object. After calling this, caller takes the ownership of the allocated [Timestamp](../Common/Timestamp.md#) object, has\_timestamp\(\) will return false, and timestamp\(\) will return the default value.|
|has\_connection\(\) const|bool|void|Returns true if connection is set.|
|connection\(\)|const [Connection](../Common/Connection.md#)&|void|Returns the current value of connection. If connection is not set, returns a [Connection](../Common/Connection.md#) with none of its fields set \(possibly connection::default\_instance\(\)\).|
|mutable\_connection\(\)| [Connection](../Common/Connection.md#) \*|void|Returns a pointer to the mutable [Connection](../Common/Connection.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Connection](../Common/Connection.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Connection](../Common/Connection.md#)\). After calling this, has\_connection\(\) will return true and connection\(\) will return a reference to the same instance of [Connection](../Common/Connection.md#).|
|clear\_connection\(\)|void|void|Clears the value of the field. After calling this, has\_connection\(\) will return false and connection\(\) will return the default value.|
|set\_allocated\_connection\(\)|void| [Connection](../Common/Connection.md#) \*|Sets the [Connection](../Common/Connection.md#) object to the field and frees the previous field value if it exists. If the [Connection](../Common/Connection.md#) pointer is not NULL, the message takes ownership of the allocated [Connection](../Common/Connection.md#) object and has\_ [Connection](../Common/Connection.md#)\(\) will return true. Otherwise, if the connection is NULL, the behavior is the same as calling clear\_connection\(\).|
|release\_connection\(\)| [Connection](../Common/Connection.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Connection](../Common/Connection.md#) object. After calling this, caller takes the ownership of the allocated [Connection](../Common/Connection.md#) object, has\_connection\(\) will return false, and connection\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

