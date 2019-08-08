# class MapGroup

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|group\_handle| [MapGroupHandle](MapGroupHandle.md#)|Map group handle \(do not set on createMapGroup\(\) call\)|To set group\_handle, you simply assign a value directly to a field within group\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|name|str|Map group friendly name|You can manipulate the field name as if it were a regular field. To clear the value of name and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|related\_mapping\_handle| [MappingHandle](MappingHandle.md#)|Mapping that this map group belongs to|To set related\_mapping\_handle, you simply assign a value directly to a field within related\_mapping\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|parent\_group\_handle| [MapGroupHandle](MapGroupHandle.md#)|Parent map group \(if any\)|To set parent\_group\_handle, you simply assign a value directly to a field within parent\_group\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|children\_map\_group\_handles| [MapGroupHandle](MapGroupHandle.md#)|Children map groups \(if any\)|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|
|map\_handles| [MapHandle](MapHandle.md#)|Array of maps that are included in this map group|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|
|application\_data|str|Application data \(reserved for use by Web App\)|You can manipulate the field application\_data as if it were a regular field. To clear the value of application\_data and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

