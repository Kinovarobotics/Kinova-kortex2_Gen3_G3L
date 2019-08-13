# class CustomData

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|custom\_data\_id| [MessageId](MessageId.md#)|MessageId|To set custom\_data\_id, you simply assign a value directly to a field within custom\_data\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|gripper\_custom\_data| [CustomDataUnit](CustomDataUnit.md#)| |To set gripper\_custom\_data, you simply assign a value directly to a field within gripper\_custom\_data. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|motor\_custom\_data| [CustomDataUnit](CustomDataUnit.md#)| |Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [GripperCyclic \(Python\)](../../summary_pages/GripperCyclic.md)

