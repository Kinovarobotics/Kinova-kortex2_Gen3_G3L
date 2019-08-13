# class GripperCommand

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|mode|int|Mode in which to control the gripper|You can manipulate the field mode as if it were a regular field. To clear the value of mode and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|gripper| [Gripper](Gripper.md#)|Gripper movement values|To set gripper, you simply assign a value directly to a field within gripper. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|duration|int|Duration constraint. If not 0, allows to set a limit \(in seconds\) to the GripperCommand|You can manipulate the field duration as if it were a regular field. To clear the value of duration and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

