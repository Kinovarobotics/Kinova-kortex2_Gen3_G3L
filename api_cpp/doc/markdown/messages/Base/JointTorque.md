# class JointTorque

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_identifier|uint32|Joint identifier|
|value|float32|Joint speed \(in Newton\*meters\)|
|duration|uint32|Duration constraint. If not 0, allows to set a limit \(in seconds\) to the JointTorque \(not implemented yet\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|joint\_identifier\(\)|uint32|void|Returns the current value of joint\_identifier. If the joint\_identifier is not set, returns 0.|
|set\_joint\_identifier\(\)|void|uint32|Sets the value of joint\_identifier. After calling this, joint\_identifier\(\) will return value.|
|clear\_joint\_identifier\(\)|void|void|Clears the value of joint\_identifier. After calling this, joint\_identifier\(\) will return 0.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

