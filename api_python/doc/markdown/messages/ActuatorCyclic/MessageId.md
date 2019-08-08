# class MessageId

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|identifier|int|Message ID \(first 2 bytes : device ID, last 2 bytes : sequence number\). By default, set to zero|You can manipulate the field identifier as if it were a regular field. To clear the value of identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [ActuatorCyclic \(Python\)](../../summary_pages/ActuatorCyclic.md)

