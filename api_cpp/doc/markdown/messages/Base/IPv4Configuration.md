# class IPv4Configuration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|ip\_address|uint32|IPv4 address|
|subnet\_mask|uint32|IPv4 subnet mask|
|default\_gateway|uint32|Gateway IPv4 address|
|dhcp\_enabled|bool|Enable automatic \(DHCP\) IPv4 configuration. Set to true to enable DHCP instead of static configuration.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|ip\_address\(\)|uint32|void|Returns the current value of ip\_address. If the ip\_address is not set, returns 0.|
|set\_ip\_address\(\)|void|uint32|Sets the value of ip\_address. After calling this, ip\_address\(\) will return value.|
|clear\_ip\_address\(\)|void|void|Clears the value of ip\_address. After calling this, ip\_address\(\) will return 0.|
|subnet\_mask\(\)|uint32|void|Returns the current value of subnet\_mask. If the subnet\_mask is not set, returns 0.|
|set\_subnet\_mask\(\)|void|uint32|Sets the value of subnet\_mask. After calling this, subnet\_mask\(\) will return value.|
|clear\_subnet\_mask\(\)|void|void|Clears the value of subnet\_mask. After calling this, subnet\_mask\(\) will return 0.|
|default\_gateway\(\)|uint32|void|Returns the current value of default\_gateway. If the default\_gateway is not set, returns 0.|
|set\_default\_gateway\(\)|void|uint32|Sets the value of default\_gateway. After calling this, default\_gateway\(\) will return value.|
|clear\_default\_gateway\(\)|void|void|Clears the value of default\_gateway. After calling this, default\_gateway\(\) will return 0.|
|dhcp\_enabled\(\)|bool|void|Returns the current value of dhcp\_enabled. If the dhcp\_enabled is not set, returns 0.|
|set\_dhcp\_enabled\(\)|void|bool|Sets the value of dhcp\_enabled. After calling this, dhcp\_enabled\(\) will return value.|
|clear\_dhcp\_enabled\(\)|void|void|Clears the value of dhcp\_enabled. After calling this, dhcp\_enabled\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

