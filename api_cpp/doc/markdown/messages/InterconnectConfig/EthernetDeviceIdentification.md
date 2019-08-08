# class EthernetDeviceIdentification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device|uint32|Ethernet device|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|device\(\) const|uint32|void|Returns the current value of device. If the device is not set, returns 0.|
|set\_device\(\)|void|uint32|Sets the value of device. After calling this, device\(\) will return value.|
|clear\_device\(\)|void|void|Clears the value of device. After calling this, device\(\) will return the empty string/empty bytes.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

