# class ControlLoopParameters

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|loop\_selection|int|ControlLoopSelection enum|You can manipulate the field loop\_selection as if it were a regular field. To clear the value of loop\_selection and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|error\_saturation|float|Error saturation value|You can manipulate the field error\_saturation as if it were a regular field. To clear the value of error\_saturation and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|output\_saturation|float|Output saturation value|You can manipulate the field output\_saturation as if it were a regular field. To clear the value of output\_saturation and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|kAz|float|KAz \(index 0 to 4\): denominator gains A1 to A5|You can manipulate the field kAz as if it were a regular field. To clear the value of kAz and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|kBz|float|KBz \(index 0 to 5\): numerator gains B0 to B5|You can manipulate the field kBz as if it were a regular field. To clear the value of kBz and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|error\_dead\_band|float|Error dead band value|You can manipulate the field error\_dead\_band as if it were a regular field. To clear the value of error\_dead\_band and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [ActuatorConfig \(Python\)](../../summary_pages/ActuatorConfig.md)

