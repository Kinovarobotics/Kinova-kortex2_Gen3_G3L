# class CapSenseConfig

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode|uint32|Operational mode of the sensor|
|threshold\_a|float32|Sensitivity of the sensor A \(0-100%\).|
|threshold\_b|float32|Sensitivity of the sensor B \(0-100%\).|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|threshold\_a\(\)|float32|void|Returns the current value of threshold\_a. If the threshold\_a is not set, returns 0.|
|set\_threshold\_a\(\)|void|float32|Sets the value of threshold\_a. After calling this, threshold\_a\(\) will return value.|
|clear\_threshold\_a\(\)|void|void|Clears the value of threshold\_a. After calling this, threshold\_a\(\) will return 0.|
|threshold\_b\(\)|float32|void|Returns the current value of threshold\_b. If the threshold\_b is not set, returns 0.|
|set\_threshold\_b\(\)|void|float32|Sets the value of threshold\_b. After calling this, threshold\_b\(\) will return value.|
|clear\_threshold\_b\(\)|void|void|Clears the value of threshold\_b. After calling this, threshold\_b\(\) will return 0.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

