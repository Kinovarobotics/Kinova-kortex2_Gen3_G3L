# class GPIOConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|GPIO identifier|
|mode|uint32|Mode|
|pull|uint32|Pull mode|
|default\_value|uint32|Default value at power on|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\) const|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return the empty string/empty bytes.|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|pull\(\) const|uint32|void|Returns the current value of pull. If the pull is not set, returns 0.|
|set\_pull\(\)|void|uint32|Sets the value of pull. After calling this, pull\(\) will return value.|
|clear\_pull\(\)|void|void|Clears the value of pull. After calling this, pull\(\) will return the empty string/empty bytes.|
|default\_value\(\) const|uint32|void|Returns the current value of default\_value. If the default\_value is not set, returns 0.|
|set\_default\_value\(\)|void|uint32|Sets the value of default\_value. After calling this, default\_value\(\) will return value.|
|clear\_default\_value\(\)|void|void|Clears the value of default\_value. After calling this, default\_value\(\) will return the empty string/empty bytes.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

