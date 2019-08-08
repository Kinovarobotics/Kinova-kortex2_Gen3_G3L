# class SensorIdentifier

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|Sensor|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

