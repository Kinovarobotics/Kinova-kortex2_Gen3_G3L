# class OptionIdentifier

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|The sensor to configure|
|option|uint32|The option to configure on the sensor|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|option\(\) const|uint32|void|Returns the current value of option. If the option is not set, returns 0.|
|set\_option\(\)|void|uint32|Sets the value of option. After calling this, option\(\) will return value.|
|clear\_option\(\)|void|void|Clears the value of option. After calling this, option\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

