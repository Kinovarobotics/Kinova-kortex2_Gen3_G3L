# class Sequence

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [SequenceHandle](SequenceHandle.md#)|Sequence handle|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|name|str|Sequence name|You can manipulate the field name as if it were a regular field. To clear the value of name and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|application\_data|str|Application data \(reserved for use by Web App\)|You can manipulate the field application\_data as if it were a regular field. To clear the value of application\_data and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|tasks| [SequenceTask](SequenceTask.md#)|Array of tasks that this sequence contains|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

