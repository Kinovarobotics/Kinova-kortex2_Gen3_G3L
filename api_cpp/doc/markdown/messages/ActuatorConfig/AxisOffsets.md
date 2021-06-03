# class AxisOffsets

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|absolute\_offset|float32|Absolute offset value \(degrees\)|
|relative\_offset|float32|Relative offset value \(degrees\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|absolute\_offset\(\)|float32|void|Returns the current value of absolute\_offset. If the absolute\_offset is not set, returns 0.|
|set\_absolute\_offset\(\)|void|float32|Sets the value of absolute\_offset. After calling this, absolute\_offset\(\) will return value.|
|clear\_absolute\_offset\(\)|void|void|Clears the value of absolute\_offset. After calling this, absolute\_offset\(\) will return 0.|
|relative\_offset\(\)|float32|void|Returns the current value of relative\_offset. If the relative\_offset is not set, returns 0.|
|set\_relative\_offset\(\)|void|float32|Sets the value of relative\_offset. After calling this, relative\_offset\(\) will return value.|
|clear\_relative\_offset\(\)|void|void|Clears the value of relative\_offset. After calling this, relative\_offset\(\) will return 0.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

