# class Command

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|frame\_id|int|Frame ID|You can manipulate the field frame\_id as if it were a regular field. To clear the value of frame\_id and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|actuators| [ActuatorCommand](ActuatorCommand.md#)|Actuator command \(repeated\)|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|
|interconnect| [Command](../InterconnectCyclic/Command.md#)|Interface command|To set interconnect, you simply assign a value directly to a field within interconnect. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [BaseCyclic \(Python\)](../../summary_pages/BaseCyclic.md)

