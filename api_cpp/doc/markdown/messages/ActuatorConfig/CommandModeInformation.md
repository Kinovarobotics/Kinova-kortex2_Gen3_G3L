# class CommandModeInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_mode|uint32|Command mode|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|command\_mode\(\) const|uint32|void|Returns the current value of command\_mode. If the command\_mode is not set, returns 0.|
|set\_command\_mode\(\)|void|uint32|Sets the value of command\_mode. After calling this, command\_mode\(\) will return value.|
|clear\_command\_mode\(\)|void|void|Clears the value of command\_mode. After calling this, command\_mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

