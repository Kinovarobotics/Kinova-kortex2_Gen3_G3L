# class JointTrajectoryConstraint

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type|uint32|Joint trajectory constraint type|
|value|float32|Constraint value \(in seconds or in meters per second depending on constraint type\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|type\(\) const|uint32|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void|uint32|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

