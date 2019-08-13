# class OperatingModeNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|operating\_mode|int|New operating mode|You can manipulate the field operating\_mode as if it were a regular field. To clear the value of operating\_mode and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the operating mode event|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the operating mode event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|device\_handle| [DeviceHandle](../Common/DeviceHandle.md#)|Device matching operating mode \(if applicable\)|To set device\_handle, you simply assign a value directly to a field within device\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

