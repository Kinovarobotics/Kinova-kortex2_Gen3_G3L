# class EthernetConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device|uint32|Device identification|
|enabled|bool|True if the ethernet device is enabled, false otherwise|
|speed|uint32|Speed selection|
|duplex|uint32|Duplex mode|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|device\(\) const|uint32|void|Returns the current value of device. If the device is not set, returns 0.|
|set\_device\(\)|void|uint32|Sets the value of device. After calling this, device\(\) will return value.|
|clear\_device\(\)|void|void|Clears the value of device. After calling this, device\(\) will return the empty string/empty bytes.|
|enabled\(\)|bool|void|Returns the current value of enabled. If the enabled is not set, returns 0.|
|set\_enabled\(\)|void|bool|Sets the value of enabled. After calling this, enabled\(\) will return value.|
|clear\_enabled\(\)|void|void|Clears the value of enabled. After calling this, enabled\(\) will return 0.|
|speed\(\) const|uint32|void|Returns the current value of speed. If the speed is not set, returns 0.|
|set\_speed\(\)|void|uint32|Sets the value of speed. After calling this, speed\(\) will return value.|
|clear\_speed\(\)|void|void|Clears the value of speed. After calling this, speed\(\) will return the empty string/empty bytes.|
|duplex\(\) const|uint32|void|Returns the current value of duplex. If the duplex is not set, returns 0.|
|set\_duplex\(\)|void|uint32|Sets the value of duplex. After calling this, duplex\(\) will return value.|
|clear\_duplex\(\)|void|void|Clears the value of duplex. After calling this, duplex\(\) will return the empty string/empty bytes.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

