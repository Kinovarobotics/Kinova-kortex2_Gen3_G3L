# class ControlConfigurationNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|event|int| |You can manipulate the field event as if it were a regular field. To clear the value of event and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the factory event to occur|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the configuration event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [ControlConfig \(Python\)](../../summary_pages/ControlConfig.md)

