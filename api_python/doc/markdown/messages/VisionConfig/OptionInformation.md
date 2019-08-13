# class OptionInformation

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|sensor|int|The sensor \(color or depth\)|You can manipulate the field sensor as if it were a regular field. To clear the value of sensor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|option|int|The option|You can manipulate the field option as if it were a regular field. To clear the value of option and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|supported|bool|Is the option supported by the chosen sensor?|You can manipulate the field supported as if it were a regular field. To clear the value of supported and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|read\_only|bool|Is the option read-only, or can it be changed?|You can manipulate the field read\_only as if it were a regular field. To clear the value of read\_only and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|minimum|float|Minimum value for the option|You can manipulate the field minimum as if it were a regular field. To clear the value of minimum and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|maximum|float|Maximum value for the option|You can manipulate the field maximum as if it were a regular field. To clear the value of maximum and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|step|float|Step size for the option value \(if it takes on discrete values\)|You can manipulate the field step as if it were a regular field. To clear the value of step and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|default\_value|float|Default value for the option|You can manipulate the field default\_value as if it were a regular field. To clear the value of default\_value and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [VisionConfig \(Python\)](../../summary_pages/VisionConfig.md)

