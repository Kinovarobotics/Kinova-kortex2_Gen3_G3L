# class CalibrationResult

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|calibration\_status|uint32|Calibration status|
|calibration\_details|uint32|Additional information \(used when status is in fault\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|calibration\_status\(\) const|uint32|void|Returns the current value of calibration\_status. If the calibration\_status is not set, returns 0.|
|set\_calibration\_status\(\)|void|uint32|Sets the value of calibration\_status. After calling this, calibration\_status\(\) will return value.|
|clear\_calibration\_status\(\)|void|void|Clears the value of calibration\_status. After calling this, calibration\_status\(\) will return the empty string/empty bytes.|
|calibration\_details\(\)|uint32|void|Returns the current value of calibration\_details. If the calibration\_details is not set, returns 0.|
|set\_calibration\_details\(\)|void|uint32|Sets the value of calibration\_details. After calling this, calibration\_details\(\) will return value.|
|clear\_calibration\_details\(\)|void|void|Clears the value of calibration\_details. After calling this, calibration\_details\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

