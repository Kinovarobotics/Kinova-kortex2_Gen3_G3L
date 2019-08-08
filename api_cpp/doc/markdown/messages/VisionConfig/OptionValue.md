# class OptionValue

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|The sensor to configure \(color or depth\)|
|option|uint32|The option to configure|
|value|float32|The desired value for the option|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|option\(\) const|uint32|void|Returns the current value of option. If the option is not set, returns 0.|
|set\_option\(\)|void|uint32|Sets the value of option. After calling this, option\(\) will return value.|
|clear\_option\(\)|void|void|Clears the value of option. After calling this, option\(\) will return the empty string/empty bytes.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

