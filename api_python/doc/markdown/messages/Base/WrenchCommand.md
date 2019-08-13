# class WrenchCommand

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|reference\_frame|int|The reference frame used for the wrench command|You can manipulate the field reference\_frame as if it were a regular field. To clear the value of reference\_frame and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|mode|int|Mode in which the command is executed|You can manipulate the field mode as if it were a regular field. To clear the value of mode and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|wrench| [Wrench](Wrench.md#)|Wrench value|To set wrench, you simply assign a value directly to a field within wrench. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|duration|int|Duration constraint. If not 0, allows to set a limit \(in milliseconds\) to the WrenchCommand|You can manipulate the field duration as if it were a regular field. To clear the value of duration and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

