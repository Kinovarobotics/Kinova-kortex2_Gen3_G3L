# class CommunicationInterfaceConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type|uint32|Network type \(e.g. Wi-Fi, Wired Ethernet\)|
|enable|bool|Enable configuration. Set to true to enable network, false otherwise|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|type\(\) const|uint32|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void|uint32|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|enable\(\)|bool|void|Returns the current value of enable. If the enable is not set, returns 0.|
|set\_enable\(\)|void|bool|Sets the value of enable. After calling this, enable\(\) will return value.|
|clear\_enable\(\)|void|void|Clears the value of enable. After calling this, enable\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

