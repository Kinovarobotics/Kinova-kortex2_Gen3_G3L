# class ControllerConfiguration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [ControllerHandle](ControllerHandle.md#)|Controller identifier|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|name|str|Controller friendly name|You can manipulate the field name as if it were a regular field. To clear the value of name and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|active\_mapping\_handle| [MappingHandle](MappingHandle.md#)|Mapping that is active on this controller|To set active\_mapping\_handle, you simply assign a value directly to a field within active\_mapping\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|analog\_input\_identifier\_enum|str|Name that identifies the enum used to interpret the ‘analog\_input\_identifier’ field \(for example in ControllerEvent\). Thus 'analog\_input\_identifier\_enum' shall take the name of an existing enum \(ex. Xbox360AnalogInputIdentifier\)|You can manipulate the field analog\_input\_identifier\_enum as if it were a regular field. To clear the value of analog\_input\_identifier\_enum and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|digital\_input\_identifier\_enum|str|Name that identifies the enum used to interpret the ‘digital\_input\_identifier’ field \(for example in ControllerEvent\). Thus 'digital\_input\_identifier\_enum' shall take the name of an existing enum \(ex. Xbox360DigitalInputIdentifier, WristDigitalInputIdentifier\)|You can manipulate the field digital\_input\_identifier\_enum as if it were a regular field. To clear the value of digital\_input\_identifier\_enum and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

