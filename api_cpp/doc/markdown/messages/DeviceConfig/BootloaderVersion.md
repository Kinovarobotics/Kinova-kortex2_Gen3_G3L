# class BootloaderVersion

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|bootloader\_version|uint32|Bootloader version|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|bootloader\_version\(\)|uint32|void|Returns the current value of bootloader\_version. If the bootloader\_version is not set, returns 0.|
|set\_bootloader\_version\(\)|void|uint32|Sets the value of bootloader\_version. After calling this, bootloader\_version\(\) will return value.|
|clear\_bootloader\_version\(\)|void|void|Clears the value of bootloader\_version. After calling this, bootloader\_version\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

