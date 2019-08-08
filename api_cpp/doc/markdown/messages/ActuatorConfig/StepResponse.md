# class StepResponse

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|loop\_selection|uint32|ControlLoopSelection enum|
|amplitude|float32|Amplitude value|
|step\_delay|float32|Step delay value|
|duration|float32|Duration \(in seconds\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|loop\_selection\(\) const|uint32|void|Returns the current value of loop\_selection. If the loop\_selection is not set, returns 0.|
|set\_loop\_selection\(\)|void|uint32|Sets the value of loop\_selection. After calling this, loop\_selection\(\) will return value.|
|clear\_loop\_selection\(\)|void|void|Clears the value of loop\_selection. After calling this, loop\_selection\(\) will return the empty string/empty bytes.|
|amplitude\(\)|float32|void|Returns the current value of amplitude. If the amplitude is not set, returns 0.|
|set\_amplitude\(\)|void|float32|Sets the value of amplitude. After calling this, amplitude\(\) will return value.|
|clear\_amplitude\(\)|void|void|Clears the value of amplitude. After calling this, amplitude\(\) will return 0.|
|step\_delay\(\)|float32|void|Returns the current value of step\_delay. If the step\_delay is not set, returns 0.|
|set\_step\_delay\(\)|void|float32|Sets the value of step\_delay. After calling this, step\_delay\(\) will return value.|
|clear\_step\_delay\(\)|void|void|Clears the value of step\_delay. After calling this, step\_delay\(\) will return 0.|
|duration\(\)|float32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|float32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

