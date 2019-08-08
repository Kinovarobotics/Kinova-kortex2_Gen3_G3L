# class FirmwareVersion

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|firmware\_version|uint32|Firmware version|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|firmware\_version\(\)|uint32|void|Returns the current value of firmware\_version. If the firmware\_version is not set, returns 0.|
|set\_firmware\_version\(\)|void|uint32|Sets the value of firmware\_version. After calling this, firmware\_version\(\) will return value.|
|clear\_firmware\_version\(\)|void|void|Clears the value of firmware\_version. After calling this, firmware\_version\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

