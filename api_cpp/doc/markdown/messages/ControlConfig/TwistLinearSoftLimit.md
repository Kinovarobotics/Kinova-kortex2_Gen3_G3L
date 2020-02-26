# class TwistLinearSoftLimit

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|control\_mode|uint32|Control mode|
|twist\_linear\_soft\_limit|float32|Software linear twist limit|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|control\_mode\(\) const|uint32|void|Returns the current value of control\_mode. If the control\_mode is not set, returns 0.|
|set\_control\_mode\(\)|void|uint32|Sets the value of control\_mode. After calling this, control\_mode\(\) will return value.|
|clear\_control\_mode\(\)|void|void|Clears the value of control\_mode. After calling this, control\_mode\(\) will return the empty string/empty bytes.|
|twist\_linear\_soft\_limit\(\)|float32|void|Returns the current value of twist\_linear\_soft\_limit. If the twist\_linear\_soft\_limit is not set, returns 0.|
|set\_twist\_linear\_soft\_limit\(\)|void|float32|Sets the value of twist\_linear\_soft\_limit. After calling this, twist\_linear\_soft\_limit\(\) will return value.|
|clear\_twist\_linear\_soft\_limit\(\)|void|void|Clears the value of twist\_linear\_soft\_limit. After calling this, twist\_linear\_soft\_limit\(\) will return 0.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

