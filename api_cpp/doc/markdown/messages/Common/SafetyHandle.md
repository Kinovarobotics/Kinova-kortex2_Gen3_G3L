# class SafetyHandle

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|Safety identifier|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\)|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return 0.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

