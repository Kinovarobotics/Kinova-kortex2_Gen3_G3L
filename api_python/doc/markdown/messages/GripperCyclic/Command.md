# class Command

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|command\_id| [MessageId](MessageId.md#)|MessageId|To set command\_id, you simply assign a value directly to a field within command\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|flags|int|Flags|You can manipulate the field flags as if it were a regular field. To clear the value of flags and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|motor\_cmd| [MotorCommand](MotorCommand.md#)|Array of finger commands, one for each finger of the gripper.|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [GripperCyclic \(Python\)](../../summary_pages/GripperCyclic.md)

