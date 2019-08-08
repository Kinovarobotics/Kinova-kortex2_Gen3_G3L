# class SafetyNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|safety\_handle| [SafetyHandle](SafetyHandle.md#)|Safety handle|To set safety\_handle, you simply assign a value directly to a field within safety\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|value|int|New safety status|You can manipulate the field value as if it were a regular field. To clear the value of value and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|timestamp| [Timestamp](Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](UserProfileHandle.md#)|User that caused the safety event|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection| [Connection](Connection.md#)|Connection that caused the safety event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Common \(Python\)](../../summary_pages/Common.md)

