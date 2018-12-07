# Message ActionNotification

This page describes the C++ Kinova::Api::Base::ActionNotification message.

## Overview / Purpose

Message that contains an action event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|action\_event|uint32|Action event type|
|handle| [ActionHandle](msg_Base_ActionHandle.md#)|Identifies the action for which this event occured|
|timestamp| [Timestamp](msg_Common_Timestamp.md#)|Event timestamp|
|user\_handle| [UserProfileHandle](msg_Common_UserProfileHandle.md#)|User that caused the action event|
|abort\_details|uint32|Details if action\_event is equal to ACTION\_ABORT|
|connection| [Connection](msg_Common_Connection.md#)|Connection that caused the action event|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|action\_event\(\) const|uint32|void|Returns the current value of action\_event. If the action\_event is not set, returns 0.|
|set\_action\_event\(\)|void|uint32|Sets the value of action\_event. After calling this, action\_event\(\) will return value.|
|clear\_action\_event\(\)|void|void|Clears the value of action\_event. After calling this, action\_event\(\) will return the empty string/empty bytes.|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [ActionHandle](msg_Base_ActionHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [ActionHandle](msg_Base_ActionHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [ActionHandle](msg_Base_ActionHandle.md#) \*|void|Returns a pointer to the mutable [ActionHandle](msg_Base_ActionHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ActionHandle](msg_Base_ActionHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ActionHandle](msg_Base_ActionHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [ActionHandle](msg_Base_ActionHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [ActionHandle](msg_Base_ActionHandle.md#) \*|Sets the [ActionHandle](msg_Base_ActionHandle.md#) object to the field and frees the previous field value if it exists. If the [ActionHandle](msg_Base_ActionHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ActionHandle](msg_Base_ActionHandle.md#) object and has\_ [ActionHandle](msg_Base_ActionHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [ActionHandle](msg_Base_ActionHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ActionHandle](msg_Base_ActionHandle.md#) object. After calling this, caller takes the ownership of the allocated [ActionHandle](msg_Base_ActionHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|has\_timestamp\(\) const|bool|void|Returns true if timestamp is set.|
|timestamp\(\)|const [Timestamp](msg_Common_Timestamp.md#)&|void|Returns the current value of timestamp. If timestamp is not set, returns a [Timestamp](msg_Common_Timestamp.md#) with none of its fields set \(possibly timestamp::default\_instance\(\)\).|
|mutable\_timestamp\(\)| [Timestamp](msg_Common_Timestamp.md#) \*|void|Returns a pointer to the mutable [Timestamp](msg_Common_Timestamp.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Timestamp](msg_Common_Timestamp.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Timestamp](msg_Common_Timestamp.md#)\). After calling this, has\_timestamp\(\) will return true and timestamp\(\) will return a reference to the same instance of [Timestamp](msg_Common_Timestamp.md#).|
|clear\_timestamp\(\)|void|void|Clears the value of the field. After calling this, has\_timestamp\(\) will return false and timestamp\(\) will return the default value.|
|set\_allocated\_timestamp\(\)|void| [Timestamp](msg_Common_Timestamp.md#) \*|Sets the [Timestamp](msg_Common_Timestamp.md#) object to the field and frees the previous field value if it exists. If the [Timestamp](msg_Common_Timestamp.md#) pointer is not NULL, the message takes ownership of the allocated [Timestamp](msg_Common_Timestamp.md#) object and has\_ [Timestamp](msg_Common_Timestamp.md#)\(\) will return true. Otherwise, if the timestamp is NULL, the behavior is the same as calling clear\_timestamp\(\).|
|release\_timestamp\(\)| [Timestamp](msg_Common_Timestamp.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Timestamp](msg_Common_Timestamp.md#) object. After calling this, caller takes the ownership of the allocated [Timestamp](msg_Common_Timestamp.md#) object, has\_timestamp\(\) will return false, and timestamp\(\) will return the default value.|
|has\_user\_handle\(\) const|bool|void|Returns true if user\_handle is set.|
|user\_handle\(\)|const [UserProfileHandle](msg_Common_UserProfileHandle.md#)&|void|Returns the current value of user\_handle. If user\_handle is not set, returns a [UserProfileHandle](msg_Common_UserProfileHandle.md#) with none of its fields set \(possibly user\_handle::default\_instance\(\)\).|
|mutable\_user\_handle\(\)| [UserProfileHandle](msg_Common_UserProfileHandle.md#) \*|void|Returns a pointer to the mutable [UserProfileHandle](msg_Common_UserProfileHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [UserProfileHandle](msg_Common_UserProfileHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfileHandle](msg_Common_UserProfileHandle.md#)\). After calling this, has\_user\_handle\(\) will return true and user\_handle\(\) will return a reference to the same instance of [UserProfileHandle](msg_Common_UserProfileHandle.md#).|
|clear\_user\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_user\_handle\(\) will return false and user\_handle\(\) will return the default value.|
|set\_allocated\_user\_handle\(\)|void| [UserProfileHandle](msg_Common_UserProfileHandle.md#) \*|Sets the [UserProfileHandle](msg_Common_UserProfileHandle.md#) object to the field and frees the previous field value if it exists. If the [UserProfileHandle](msg_Common_UserProfileHandle.md#) pointer is not NULL, the message takes ownership of the allocated [UserProfileHandle](msg_Common_UserProfileHandle.md#) object and has\_ [UserProfileHandle](msg_Common_UserProfileHandle.md#)\(\) will return true. Otherwise, if the user\_handle is NULL, the behavior is the same as calling clear\_user\_handle\(\).|
|release\_user\_handle\(\)| [UserProfileHandle](msg_Common_UserProfileHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [UserProfileHandle](msg_Common_UserProfileHandle.md#) object. After calling this, caller takes the ownership of the allocated [UserProfileHandle](msg_Common_UserProfileHandle.md#) object, has\_user\_handle\(\) will return false, and user\_handle\(\) will return the default value.|
|abort\_details\(\) const|uint32|void|Returns the current value of abort\_details. If the abort\_details is not set, returns 0.|
|set\_abort\_details\(\)|void|uint32|Sets the value of abort\_details. After calling this, abort\_details\(\) will return value.|
|clear\_abort\_details\(\)|void|void|Clears the value of abort\_details. After calling this, abort\_details\(\) will return the empty string/empty bytes.|
|has\_connection\(\) const|bool|void|Returns true if connection is set.|
|connection\(\)|const [Connection](msg_Common_Connection.md#)&|void|Returns the current value of connection. If connection is not set, returns a [Connection](msg_Common_Connection.md#) with none of its fields set \(possibly connection::default\_instance\(\)\).|
|mutable\_connection\(\)| [Connection](msg_Common_Connection.md#) \*|void|Returns a pointer to the mutable [Connection](msg_Common_Connection.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Connection](msg_Common_Connection.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Connection](msg_Common_Connection.md#)\). After calling this, has\_connection\(\) will return true and connection\(\) will return a reference to the same instance of [Connection](msg_Common_Connection.md#).|
|clear\_connection\(\)|void|void|Clears the value of the field. After calling this, has\_connection\(\) will return false and connection\(\) will return the default value.|
|set\_allocated\_connection\(\)|void| [Connection](msg_Common_Connection.md#) \*|Sets the [Connection](msg_Common_Connection.md#) object to the field and frees the previous field value if it exists. If the [Connection](msg_Common_Connection.md#) pointer is not NULL, the message takes ownership of the allocated [Connection](msg_Common_Connection.md#) object and has\_ [Connection](msg_Common_Connection.md#)\(\) will return true. Otherwise, if the connection is NULL, the behavior is the same as calling clear\_connection\(\).|
|release\_connection\(\)| [Connection](msg_Common_Connection.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Connection](msg_Common_Connection.md#) object. After calling this, caller takes the ownership of the allocated [Connection](msg_Common_Connection.md#) object, has\_connection\(\) will return false, and connection\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

