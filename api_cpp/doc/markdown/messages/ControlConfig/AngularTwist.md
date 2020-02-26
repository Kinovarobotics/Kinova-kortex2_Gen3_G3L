# class AngularTwist

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|angular|float32|Desired angular speed \(degrees / second\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|angular\(\)|float32|void|Returns the current value of angular. If the angular is not set, returns 0.|
|set\_angular\(\)|void|float32|Sets the value of angular. After calling this, angular\(\) will return value.|
|clear\_angular\(\)|void|void|Clears the value of angular. After calling this, angular\(\) will return 0.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

