# class UserNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|user\_event|int|User event type|You can manipulate the field user\_event as if it were a regular field. To clear the value of user\_event and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|modified\_user| [UserProfileHandle](../Common/UserProfileHandle.md#)|User profile that was modified|To set modified\_user, you simply assign a value directly to a field within modified\_user. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the user profile event \(i.e. user who changed the user profile\)|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the user profile event \(i.e. user who changed the user profile\)|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

