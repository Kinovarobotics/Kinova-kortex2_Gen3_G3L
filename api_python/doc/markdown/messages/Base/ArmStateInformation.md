# class ArmStateInformation

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|active\_state|int|Arm active state|You can manipulate the field active\_state as if it were a regular field. To clear the value of active\_state and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|connection| [Connection](../Common/Connection.md#)|Connection information of the last processed command which triggered an arm state change|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

