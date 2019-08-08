# class BridgeResult

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|bridge\_id| [BridgeIdentifier](BridgeIdentifier.md#)|ID of the bridge on which operation was performed|To set bridge\_id, you simply assign a value directly to a field within bridge\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|status|int|Result code of operation.|You can manipulate the field status as if it were a regular field. To clear the value of status and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

