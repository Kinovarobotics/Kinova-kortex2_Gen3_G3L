# class I2CReadParameter

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device|uint32|I2C device identification|
|device\_address|uint32|I2C device address|
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
|size\(\)|uint32|void|Returns the current value of size. If the size is not set, returns 0.|
|set\_size\(\)|void|uint32|Sets the value of size. After calling this, size\(\) will return value.|
|clear\_size\(\)|void|void|Clears the value of size. After calling this, size\(\) will return 0.|
|timeout\(\)|uint32|void|Returns the current value of timeout. If the timeout is not set, returns 0.|
|set\_timeout\(\)|void|uint32|Sets the value of timeout. After calling this, timeout\(\) will return value.|
|clear\_timeout\(\)|void|void|Clears the value of timeout. After calling this, timeout\(\) will return 0.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

