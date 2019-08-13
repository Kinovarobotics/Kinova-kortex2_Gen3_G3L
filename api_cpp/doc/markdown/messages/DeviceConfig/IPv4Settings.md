# class IPv4Settings

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|ipv4\_address|uint32|IPv4Address|
|ipv4\_subnet\_mask|uint32|IPv4SubnetMask|
|ipv4\_default\_gateway|uint32|IPv4DefaultGateway|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|ipv4\_address\(\)|uint32|void|Returns the current value of ipv4\_address. If the ipv4\_address is not set, returns 0.|
|set\_ipv4\_address\(\)|void|uint32|Sets the value of ipv4\_address. After calling this, ipv4\_address\(\) will return value.|
|clear\_ipv4\_address\(\)|void|void|Clears the value of ipv4\_address. After calling this, ipv4\_address\(\) will return 0.|
|ipv4\_subnet\_mask\(\)|uint32|void|Returns the current value of ipv4\_subnet\_mask. If the ipv4\_subnet\_mask is not set, returns 0.|
|set\_ipv4\_subnet\_mask\(\)|void|uint32|Sets the value of ipv4\_subnet\_mask. After calling this, ipv4\_subnet\_mask\(\) will return value.|
|clear\_ipv4\_subnet\_mask\(\)|void|void|Clears the value of ipv4\_subnet\_mask. After calling this, ipv4\_subnet\_mask\(\) will return 0.|
|ipv4\_default\_gateway\(\)|uint32|void|Returns the current value of ipv4\_default\_gateway. If the ipv4\_default\_gateway is not set, returns 0.|
|set\_ipv4\_default\_gateway\(\)|void|uint32|Sets the value of ipv4\_default\_gateway. After calling this, ipv4\_default\_gateway\(\) will return value.|
|clear\_ipv4\_default\_gateway\(\)|void|void|Clears the value of ipv4\_default\_gateway. After calling this, ipv4\_default\_gateway\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

