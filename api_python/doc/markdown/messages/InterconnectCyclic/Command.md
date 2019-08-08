# class Command

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|command\_id| [MessageId](MessageId.md#)|MessageId|To set command\_id, you simply assign a value directly to a field within command\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|flags|int|Flags|You can manipulate the field flags as if it were a regular field. To clear the value of flags and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|gripper\_command|oneof:tool\_command [Command](../GripperCyclic/Command.md#)|Gripper command|You can manipulate the field gripper\_command as if it were a regular field. To clear the value of gripper\_command and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|

**Parent topic:** [InterconnectCyclic \(Python\)](../../summary_pages/InterconnectCyclic.md)

