# class ActionNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|action\_event|int|Action event type|You can manipulate the field action\_event as if it were a regular field. To clear the value of action\_event and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|handle| [ActionHandle](ActionHandle.md#)|Identifies the action for which this event occured|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the action event|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|abort\_details|int|Details if action\_event is equal to ACTION\_ABORT|You can manipulate the field abort\_details as if it were a regular field. To clear the value of abort\_details and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the action event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

