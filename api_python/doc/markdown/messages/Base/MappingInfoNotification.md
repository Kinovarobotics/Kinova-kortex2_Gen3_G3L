# class MappingInfoNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|controller\_identifier|int|Identifier of the controller|You can manipulate the field controller\_identifier as if it were a regular field. To clear the value of controller\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|active\_map\_handle| [MapHandle](MapHandle.md#)|New active map|To set active\_map\_handle, you simply assign a value directly to a field within active\_map\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the mapping information event|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the mapping information event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|mapping\_handle| [MappingHandle](MappingHandle.md#)|Mapping for which the map was activated|To set mapping\_handle, you simply assign a value directly to a field within mapping\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

