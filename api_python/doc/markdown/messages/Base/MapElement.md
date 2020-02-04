# class MapElement

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|event| [MapEvent](MapEvent.md#)|Map event that occured|To set event, you simply assign a value directly to a field within event. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|action| [Action](Action.md#)|Action to invoke upon event occurence|To set action, you simply assign a value directly to a field within action. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|name|str|Map element friendly name|You can manipulate the field name as if it were a regular field. To clear the value of name and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

