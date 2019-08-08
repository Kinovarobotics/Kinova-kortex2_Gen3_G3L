# class ControlLoop

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|control\_loop|uint32|Use ControlLoopSelection enum values to form bitmask|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|control\_loop\(\)|uint32|void|Returns the current value of control\_loop. If the control\_loop is not set, returns 0.|
|set\_control\_loop\(\)|void|uint32|Sets the value of control\_loop. After calling this, control\_loop\(\) will return value.|
|clear\_control\_loop\(\)|void|void|Clears the value of control\_loop. After calling this, control\_loop\(\) will return 0.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

