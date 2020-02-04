# class LinearTwist

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|linear|float32|Desired linear speed \(meters / second\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|linear\(\)|float32|void|Returns the current value of linear. If the linear is not set, returns 0.|
|set\_linear\(\)|void|float32|Sets the value of linear. After calling this, linear\(\) will return value.|
|clear\_linear\(\)|void|void|Clears the value of linear. After calling this, linear\(\) will return 0.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

