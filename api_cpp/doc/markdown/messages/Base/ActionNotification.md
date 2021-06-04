# class ActionNotification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|action\_event|uint32|Action event type|
|handle| [ActionHandle](ActionHandle.md#)|Identifies the action for which this event occured|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the action event|
|abort\_details|uint32|Details if action\_event is equal to ACTION\_ABORT|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the action event|
|trajectory\_info| [TrajectoryInfo](TrajectoryInfo.md#)|Additional information from the current action|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|action\_event\(\) const|uint32|void|Returns the current value of action\_event. If the action\_event is not set, returns 0.|
|set\_action\_event\(\)|void|uint32|Sets the value of action\_event. After calling this, action\_event\(\) will return value.|
|clear\_action\_event\(\)|void|void|Clears the value of action\_event. After calling this, action\_event\(\) will return the empty string/empty bytes.|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [ActionHandle](ActionHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [ActionHandle](ActionHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [ActionHandle](ActionHandle.md#) \*|void|Returns a pointer to the mutable [ActionHandle](ActionHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ActionHandle](ActionHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActionHandle](ActionHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [ActionHandle](ActionHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [ActionHandle](ActionHandle.md#) \*|Sets the [ActionHandle](ActionHandle.md#) object to the field and frees the previous field value if it exists. If the [ActionHandle](ActionHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ActionHandle](ActionHandle.md#) object and has\_ [ActionHandle](ActionHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [ActionHandle](ActionHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ActionHandle](ActionHandle.md#) object. After calling this, caller takes the ownership of the allocated [ActionHandle](ActionHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
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
|abort\_details\(\) const|uint32|void|Returns the current value of abort\_details. If the abort\_details is not set, returns 0.|
|set\_abort\_details\(\)|void|uint32|Sets the value of abort\_details. After calling this, abort\_details\(\) will return value.|
|clear\_abort\_details\(\)|void|void|Clears the value of abort\_details. After calling this, abort\_details\(\) will return the empty string/empty bytes.|
|has\_connection\(\) const|bool|void|Returns true if connection is set.|
|connection\(\)|const [Connection](../Common/Connection.md#)&|void|Returns the current value of connection. If connection is not set, returns a [Connection](../Common/Connection.md#) with none of its fields set \(possibly connection::default\_instance\(\)\).|
|mutable\_connection\(\)| [Connection](../Common/Connection.md#) \*|void|Returns a pointer to the mutable [Connection](../Common/Connection.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Connection](../Common/Connection.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Connection](../Common/Connection.md#)\). After calling this, has\_connection\(\) will return true and connection\(\) will return a reference to the same instance of [Connection](../Common/Connection.md#).|
|clear\_connection\(\)|void|void|Clears the value of the field. After calling this, has\_connection\(\) will return false and connection\(\) will return the default value.|
|set\_allocated\_connection\(\)|void| [Connection](../Common/Connection.md#) \*|Sets the [Connection](../Common/Connection.md#) object to the field and frees the previous field value if it exists. If the [Connection](../Common/Connection.md#) pointer is not NULL, the message takes ownership of the allocated [Connection](../Common/Connection.md#) object and has\_ [Connection](../Common/Connection.md#)\(\) will return true. Otherwise, if the connection is NULL, the behavior is the same as calling clear\_connection\(\).|
|release\_connection\(\)| [Connection](../Common/Connection.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Connection](../Common/Connection.md#) object. After calling this, caller takes the ownership of the allocated [Connection](../Common/Connection.md#) object, has\_connection\(\) will return false, and connection\(\) will return the default value.|
|trajectory\_info\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|trajectory\_info\(\) const|const [TrajectoryInfo](TrajectoryInfo.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, trajectory\_info\_size\(\)\) yields undefined behavior.|
|mutable\_trajectory\_info\(\)| [TrajectoryInfo](TrajectoryInfo.md#)\*|int index|Returns a pointer to the mutable [TrajectoryInfo](TrajectoryInfo.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, trajectory\_info\_size\(\)\) yields undefined behavior.|
|add\_trajectory\_info\(\)| [TrajectoryInfo](TrajectoryInfo.md#)\*|void|Adds a new element and returns a pointer to it. The returned [TrajectoryInfo](TrajectoryInfo.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [TrajectoryInfo](TrajectoryInfo.md#)\).|
|clear\_trajectory\_info\(\)|void|void|Removes all elements from the field. After calling this, trajectory\_info\_size\(\) will return zero.|
|trajectory\_info\(\) const|const RepeatedPtrField< [TrajectoryInfo](TrajectoryInfo.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_trajectory\_info\(\)|RepeatedPtrField< [TrajectoryInfo](TrajectoryInfo.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

