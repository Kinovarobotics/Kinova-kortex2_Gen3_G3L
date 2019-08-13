# class RampResponse

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|loop\_selection|uint32|ControlLoopSelection enum|
|slope|float32|Slope value|
|ramp\_delay|float32|Ramp delay value|
|duration|float32|Duration \(in seconds\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|loop\_selection\(\) const|uint32|void|Returns the current value of loop\_selection. If the loop\_selection is not set, returns 0.|
|set\_loop\_selection\(\)|void|uint32|Sets the value of loop\_selection. After calling this, loop\_selection\(\) will return value.|
|clear\_loop\_selection\(\)|void|void|Clears the value of loop\_selection. After calling this, loop\_selection\(\) will return the empty string/empty bytes.|
|slope\(\)|float32|void|Returns the current value of slope. If the slope is not set, returns 0.|
|set\_slope\(\)|void|float32|Sets the value of slope. After calling this, slope\(\) will return value.|
|clear\_slope\(\)|void|void|Clears the value of slope. After calling this, slope\(\) will return 0.|
|ramp\_delay\(\)|float32|void|Returns the current value of ramp\_delay. If the ramp\_delay is not set, returns 0.|
|set\_ramp\_delay\(\)|void|float32|Sets the value of ramp\_delay. After calling this, ramp\_delay\(\) will return value.|
|clear\_ramp\_delay\(\)|void|void|Clears the value of ramp\_delay. After calling this, ramp\_delay\(\) will return 0.|
|duration\(\)|float32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|float32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

