# class I2CReadRegisterParameter

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device|uint32|I2C device identification|
|device\_address|uint32|I2C device address|
|register\_address|uint32|I2C register address \(8 or 16 bits\)|
|register\_address\_size|uint32|I2C register address size|
|size|uint32|I2C number of bytes to read \(max 128 bytes\)|
|timeout|uint32|Request timeout in milliseconds|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|device\(\) const|uint32|void|Returns the current value of device. If the device is not set, returns 0.|
|set\_device\(\)|void|uint32|Sets the value of device. After calling this, device\(\) will return value.|
|clear\_device\(\)|void|void|Clears the value of device. After calling this, device\(\) will return the empty string/empty bytes.|
|device\_address\(\)|uint32|void|Returns the current value of device\_address. If the device\_address is not set, returns 0.|
|set\_device\_address\(\)|void|uint32|Sets the value of device\_address. After calling this, device\_address\(\) will return value.|
|clear\_device\_address\(\)|void|void|Clears the value of device\_address. After calling this, device\_address\(\) will return 0.|
|register\_address\(\)|uint32|void|Returns the current value of register\_address. If the register\_address is not set, returns 0.|
|set\_register\_address\(\)|void|uint32|Sets the value of register\_address. After calling this, register\_address\(\) will return value.|
|clear\_register\_address\(\)|void|void|Clears the value of register\_address. After calling this, register\_address\(\) will return 0.|
|register\_address\_size\(\) const|uint32|void|Returns the current value of register\_address\_size. If the register\_address\_size is not set, returns 0.|
|set\_register\_address\_size\(\)|void|uint32|Sets the value of register\_address\_size. After calling this, register\_address\_size\(\) will return value.|
|clear\_register\_address\_size\(\)|void|void|Clears the value of register\_address\_size. After calling this, register\_address\_size\(\) will return the empty string/empty bytes.|
|size\(\)|uint32|void|Returns the current value of size. If the size is not set, returns 0.|
|set\_size\(\)|void|uint32|Sets the value of size. After calling this, size\(\) will return value.|
|clear\_size\(\)|void|void|Clears the value of size. After calling this, size\(\) will return 0.|
|timeout\(\)|uint32|void|Returns the current value of timeout. If the timeout is not set, returns 0.|
|set\_timeout\(\)|void|uint32|Sets the value of timeout. After calling this, timeout\(\) will return value.|
|clear\_timeout\(\)|void|void|Clears the value of timeout. After calling this, timeout\(\) will return 0.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

