# class I2CConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device|uint32|I2C device identification|
|enabled|bool|True if I2C device is enabled, false otherwise|
|mode|uint32|Mode|
|addressing|uint32|Addressing mode|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|device\(\) const|uint32|void|Returns the current value of device. If the device is not set, returns 0.|
|set\_device\(\)|void|uint32|Sets the value of device. After calling this, device\(\) will return value.|
|clear\_device\(\)|void|void|Clears the value of device. After calling this, device\(\) will return the empty string/empty bytes.|
|enabled\(\)|bool|void|Returns the current value of enabled. If the enabled is not set, returns 0.|
|set\_enabled\(\)|void|bool|Sets the value of enabled. After calling this, enabled\(\) will return value.|
|clear\_enabled\(\)|void|void|Clears the value of enabled. After calling this, enabled\(\) will return 0.|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|addressing\(\) const|uint32|void|Returns the current value of addressing. If the addressing is not set, returns 0.|
|set\_addressing\(\)|void|uint32|Sets the value of addressing. After calling this, addressing\(\) will return value.|
|clear\_addressing\(\)|void|void|Clears the value of addressing. After calling this, addressing\(\) will return the empty string/empty bytes.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

