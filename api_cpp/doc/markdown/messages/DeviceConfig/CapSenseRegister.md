# class CapSenseRegister

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|address|uint32|Register address|
|value|uint32|Register value|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|address\(\)|uint32|void|Returns the current value of address. If the address is not set, returns 0.|
|set\_address\(\)|void|uint32|Sets the value of address. After calling this, address\(\) will return value.|
|clear\_address\(\)|void|void|Clears the value of address. After calling this, address\(\) will return 0.|
|value\(\)|uint32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|uint32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

