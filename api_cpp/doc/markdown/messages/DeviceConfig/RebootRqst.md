# class RebootRqst

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|delay|uint32|Bootloader delay|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|delay\(\)|uint32|void|Returns the current value of delay. If the delay is not set, returns 0.|
|set\_delay\(\)|void|uint32|Sets the value of delay. After calling this, delay\(\) will return value.|
|clear\_delay\(\)|void|void|Clears the value of delay. After calling this, delay\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

