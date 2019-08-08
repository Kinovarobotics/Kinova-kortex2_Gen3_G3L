# class CountryCode

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|ISO3166 country code identifier|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\) const|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return the empty string/empty bytes.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

