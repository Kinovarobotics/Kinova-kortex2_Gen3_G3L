# class Mapping

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [MappingHandle](MappingHandle.md#)|Mapping handle \(do not set on createMapping\(\) call\)|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|name|str|Mapping friendly name|You can manipulate the field name as if it were a regular field. To clear the value of name and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|controller\_identifier|int|Associated controller identifier|You can manipulate the field controller\_identifier as if it were a regular field. To clear the value of controller\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|active\_map\_group\_handle| [MapGroupHandle](MapGroupHandle.md#)|Currently active map group \(not implemented yet\)|To set active\_map\_group\_handle, you simply assign a value directly to a field within active\_map\_group\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|map\_group\_handles| [MapGroupHandle](MapGroupHandle.md#)|Array of associated map groups \(not implemented yet\)|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|
|active\_map\_handle| [MapHandle](MapHandle.md#)|Currently active map|To set active\_map\_handle, you simply assign a value directly to a field within active\_map\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|map\_handles| [MapHandle](MapHandle.md#)|Array of associated maps|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|
|application\_data|str|Application data \(reserved for use by Web App\)|You can manipulate the field application\_data as if it were a regular field. To clear the value of application\_data and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

