# class ToolConfiguration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|tool\_transform| [CartesianTransform](CartesianTransform.md#)|Cartesian transform tool|To set tool\_transform, you simply assign a value directly to a field within tool\_transform. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|tool\_mass|float|Tool mass \(in kg\)|You can manipulate the field tool\_mass as if it were a regular field. To clear the value of tool\_mass and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|tool\_mass\_center| [Position](Position.md#)|Tool mass center position relative to the interface module reference frame|To set tool\_mass\_center, you simply assign a value directly to a field within tool\_mass\_center. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [ControlConfig \(Python\)](../../summary_pages/ControlConfig.md)

