# class GpioPinConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|pin\_id|uint32|Pin identifier|
|pin\_property|uint32|Pin property \(read only\)|
|output\_enable|bool|Pin is configured as output if set to TRUE. If output is enabled, input events are masked.|
|default\_output\_value|bool|Default output pin value. This is the value set when pin is initialized \(TRUE == high / FALSE == low\).|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|pin\_id\(\)|uint32|void|Returns the current value of pin\_id. If the pin\_id is not set, returns 0.|
|set\_pin\_id\(\)|void|uint32|Sets the value of pin\_id. After calling this, pin\_id\(\) will return value.|
|clear\_pin\_id\(\)|void|void|Clears the value of pin\_id. After calling this, pin\_id\(\) will return 0.|
|pin\_property\(\) const|uint32|void|Returns the current value of pin\_property. If the pin\_property is not set, returns 0.|
|set\_pin\_property\(\)|void|uint32|Sets the value of pin\_property. After calling this, pin\_property\(\) will return value.|
|clear\_pin\_property\(\)|void|void|Clears the value of pin\_property. After calling this, pin\_property\(\) will return the empty string/empty bytes.|
|output\_enable\(\)|bool|void|Returns the current value of output\_enable. If the output\_enable is not set, returns 0.|
|set\_output\_enable\(\)|void|bool|Sets the value of output\_enable. After calling this, output\_enable\(\) will return value.|
|clear\_output\_enable\(\)|void|void|Clears the value of output\_enable. After calling this, output\_enable\(\) will return 0.|
|default\_output\_value\(\)|bool|void|Returns the current value of default\_output\_value. If the default\_output\_value is not set, returns 0.|
|set\_default\_output\_value\(\)|void|bool|Sets the value of default\_output\_value. After calling this, default\_output\_value\(\) will return value.|
|clear\_default\_output\_value\(\)|void|void|Clears the value of default\_output\_value. After calling this, default\_output\_value\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

