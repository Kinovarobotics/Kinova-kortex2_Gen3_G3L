# class PayloadInformation

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|payload\_mass|float|Tool mass in kg|You can manipulate the field payload\_mass as if it were a regular field. To clear the value of payload\_mass and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|payload\_mass\_center| [Position](Position.md#)|Tool mass center position relative to the tool reference frame|To set payload\_mass\_center, you simply assign a value directly to a field within payload\_mass\_center. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [ControlConfig \(Python\)](../../summary_pages/ControlConfig.md)

