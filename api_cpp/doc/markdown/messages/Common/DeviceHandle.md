# class DeviceHandle

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device\_type|uint32|Device type|
|device\_identifier|uint32|Unique device identifier \(used with other services\)|
|order|uint32|Unique value indicating the order of that device versus the others to facilitate representation|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|device\_type\(\) const|uint32|void|Returns the current value of device\_type. If the device\_type is not set, returns 0.|
|set\_device\_type\(\)|void|uint32|Sets the value of device\_type. After calling this, device\_type\(\) will return value.|
|clear\_device\_type\(\)|void|void|Clears the value of device\_type. After calling this, device\_type\(\) will return the empty string/empty bytes.|
|device\_identifier\(\)|uint32|void|Returns the current value of device\_identifier. If the device\_identifier is not set, returns 0.|
|set\_device\_identifier\(\)|void|uint32|Sets the value of device\_identifier. After calling this, device\_identifier\(\) will return value.|
|clear\_device\_identifier\(\)|void|void|Clears the value of device\_identifier. After calling this, device\_identifier\(\) will return 0.|
|order\(\)|uint32|void|Returns the current value of order. If the order is not set, returns 0.|
|set\_order\(\)|void|uint32|Sets the value of order. After calling this, order\(\) will return value.|
|clear\_order\(\)|void|void|Clears the value of order. After calling this, order\(\) will return 0.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

