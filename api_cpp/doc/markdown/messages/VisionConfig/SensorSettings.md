# class SensorSettings

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|The sensor \(color or depth\)|
|resolution|uint32|The resolution setting|
|frame\_rate|uint32|Frame rate setting|
|bit\_rate|uint32|Maximum encoded bit rate|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|resolution\(\) const|uint32|void|Returns the current value of resolution. If the resolution is not set, returns 0.|
|set\_resolution\(\)|void|uint32|Sets the value of resolution. After calling this, resolution\(\) will return value.|
|clear\_resolution\(\)|void|void|Clears the value of resolution. After calling this, resolution\(\) will return the empty string/empty bytes.|
|frame\_rate\(\) const|uint32|void|Returns the current value of frame\_rate. If the frame\_rate is not set, returns 0.|
|set\_frame\_rate\(\)|void|uint32|Sets the value of frame\_rate. After calling this, frame\_rate\(\) will return value.|
|clear\_frame\_rate\(\)|void|void|Clears the value of frame\_rate. After calling this, frame\_rate\(\) will return the empty string/empty bytes.|
|bit\_rate\(\) const|uint32|void|Returns the current value of bit\_rate. If the bit\_rate is not set, returns 0.|
|set\_bit\_rate\(\)|void|uint32|Sets the value of bit\_rate. After calling this, bit\_rate\(\) will return value.|
|clear\_bit\_rate\(\)|void|void|Clears the value of bit\_rate. After calling this, bit\_rate\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

