# class GPIOIdentification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|GPIO identifier|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\) const|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return the empty string/empty bytes.|

**Parent topic:** [InterconnectConfig \(C++\)](../../summary_pages/InterconnectConfig.md)

