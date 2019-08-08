# class I2CReadRegisterParameter

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|device|int|I2C device identification|You can manipulate the field device as if it were a regular field. To clear the value of device and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|device\_address|int|I2C device address|You can manipulate the field device\_address as if it were a regular field. To clear the value of device\_address and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|register\_address|int|I2C register address \(8 or 16 bits\)|You can manipulate the field register\_address as if it were a regular field. To clear the value of register\_address and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|register\_address\_size|int|I2C register address size|You can manipulate the field register\_address\_size as if it were a regular field. To clear the value of register\_address\_size and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|size|int|I2C number of bytes to read \(max 128 bytes\)|You can manipulate the field size as if it were a regular field. To clear the value of size and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|timeout|int|Request timeout in milliseconds|You can manipulate the field timeout as if it were a regular field. To clear the value of timeout and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [InterconnectConfig \(Python\)](../../summary_pages/InterconnectConfig.md)

