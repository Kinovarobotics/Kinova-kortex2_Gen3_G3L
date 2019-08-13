# class I2CWriteRegisterParameter

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device|uint32|I2C device identification|
|device\_address|uint32|I2C device address|
|register\_address|uint32|I2C register address \(8 or 16 bits\)|
|register\_address\_size|uint32|I2C register address size|
|timeout|uint32|Request timeout in milliseconds|
|data| [I2CData](I2CData.md#)|Data to write|

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
|timeout\(\)|uint32|void|Returns the current value of timeout. If the timeout is not set, returns 0.|
|set\_timeout\(\)|void|uint32|Sets the value of timeout. After calling this, timeout\(\) will return value.|
|clear\_timeout\(\)|void|void|Clears the value of timeout. After calling this, timeout\(\) will return 0.|
|has\_data\(\) const|bool|void|Returns true if data is set.|
|data\(\)|const [I2CData](I2CData.md#)&|void|Returns the current value of data. If data is not set, returns a [I2CData](I2CData.md#) with none of its fields set \(possibly data::default\_instance\(\)\).|
|mutable\_data\(\)| [I2CData](I2CData.md#) \*|void|Returns a pointer to the mutable [I2CData](I2CData.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [I2CData](I2CData.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [I2CData](I2CData.md#)\). After calling this, has\_data\(\) will return true and data\(\) will return a reference to the same instance of [I2CData](I2CData.md#).|
|clear\_data\(\)|void|void|Clears the value of the field. After calling this, has\_data\(\) will return false and data\(\) will return the default value.|
|set\_allocated\_data\(\)|void| [I2CData](I2CData.md#) \*|Sets the [I2CData](I2CData.md#) object to the field and frees the previous field value if it exists. If the [I2CData](I2CData.md#) pointer is not NULL, the message takes ownership of the allocated [I2CData](I2CData.md#) object and has\_ [I2CData](I2CData.md#)\(\) will return true. Otherwise, if the data is NULL, the behavior is the same as calling clear\_data\(\).|
|release\_data\(\)| [I2CData](I2CData.md#) \*|void|Releases the ownership of the field and returns the pointer of the [I2CData](I2CData.md#) object. After calling this, caller takes the ownership of the allocated [I2CData](I2CData.md#) object, has\_data\(\) will return false, and data\(\) will return the default value.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

