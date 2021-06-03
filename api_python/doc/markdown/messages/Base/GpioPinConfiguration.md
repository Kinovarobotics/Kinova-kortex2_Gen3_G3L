# class GpioPinConfiguration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|pin\_id|int|Pin identifier|You can manipulate the field pin\_id as if it were a regular field. To clear the value of pin\_id and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|pin\_property|int|Pin property \(read only\)|You can manipulate the field pin\_property as if it were a regular field. To clear the value of pin\_property and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|output\_enable|bool|Pin is configured as output if set to TRUE. If output is enabled, input events are masked.|You can manipulate the field output\_enable as if it were a regular field. To clear the value of output\_enable and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|default\_output\_value|bool|Default output pin value. This is the value set when pin is initialized \(TRUE == high / FALSE == low\).|You can manipulate the field default\_output\_value as if it were a regular field. To clear the value of default\_output\_value and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

