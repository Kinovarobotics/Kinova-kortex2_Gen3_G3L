# class ManualFocus

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|value|uint32|Abstract value allowing to change the focus distance, between 0 \(infinity\) and 1023 \(close plane\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|value\(\)|uint32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|uint32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

