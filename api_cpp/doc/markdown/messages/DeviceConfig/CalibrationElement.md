# class CalibrationElement

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|calibration\_item|uint32|Item to get status|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|calibration\_item\(\) const|uint32|void|Returns the current value of calibration\_item. If the calibration\_item is not set, returns 0.|
|set\_calibration\_item\(\)|void|uint32|Sets the value of calibration\_item. After calling this, calibration\_item\(\) will return value.|
|clear\_calibration\_item\(\)|void|void|Clears the value of calibration\_item. After calling this, calibration\_item\(\) will return the empty string/empty bytes.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

