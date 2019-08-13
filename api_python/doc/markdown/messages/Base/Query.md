# class Query

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|start\_timestamp| [Timestamp](../Common/Timestamp.md#)|Start timestamp \(set to zero to specify it\)|To set start\_timestamp, you simply assign a value directly to a field within start\_timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|end\_timestamp| [Timestamp](../Common/Timestamp.md#)|End timestamp \(set to zero to not specify it\)|To set end\_timestamp, you simply assign a value directly to a field within end\_timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|username|str|Queried username \(set to "" to not specify it\)|You can manipulate the field username as if it were a regular field. To clear the value of username and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

