# class TwistCommand

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|reference\_frame|int|The reference frame used for the twist command|You can manipulate the field reference\_frame as if it were a regular field. To clear the value of reference\_frame and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|twist| [Twist](Twist.md#)|Twist value|To set twist, you simply assign a value directly to a field within twist. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|duration|int|Duration constrant. If not 0, allows to set a limit \(in milliseconds\) to the TwistCommand \(not implemented yet\)|You can manipulate the field duration as if it were a regular field. To clear the value of duration and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

