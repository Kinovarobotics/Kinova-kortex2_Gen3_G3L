# class ChangeWrench

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|force|float32|Linear force increment \(in Newton\)|
|torque|float32|Angular torque increment \(in Newton\*meters\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|force\(\)|float32|void|Returns the current value of force. If the force is not set, returns 0.|
|set\_force\(\)|void|float32|Sets the value of force. After calling this, force\(\) will return value.|
|clear\_force\(\)|void|void|Clears the value of force. After calling this, force\(\) will return 0.|
|torque\(\)|float32|void|Returns the current value of torque. If the torque is not set, returns 0.|
|set\_torque\(\)|void|float32|Sets the value of torque. After calling this, torque\(\) will return value.|
|clear\_torque\(\)|void|void|Clears the value of torque. After calling this, torque\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

