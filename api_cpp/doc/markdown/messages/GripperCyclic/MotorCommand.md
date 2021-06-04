# class MotorCommand

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|motor\_id|uint32|Motor ID \(1, nb\_motor\)|
|position|float32|Desired position of the gripper fingers in percentage \(0-100%\)|
|velocity|float32|Desired velocity in percentage \(0-100%\) with which position will be set|
|force|float32|This field is deprecated and unused. It will be removed in a future release.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|motor\_id\(\)|uint32|void|Returns the current value of motor\_id. If the motor\_id is not set, returns 0.|
|set\_motor\_id\(\)|void|uint32|Sets the value of motor\_id. After calling this, motor\_id\(\) will return value.|
|clear\_motor\_id\(\)|void|void|Clears the value of motor\_id. After calling this, motor\_id\(\) will return 0.|
|position\(\)|float32|void|Returns the current value of position. If the position is not set, returns 0.|
|set\_position\(\)|void|float32|Sets the value of position. After calling this, position\(\) will return value.|
|clear\_position\(\)|void|void|Clears the value of position. After calling this, position\(\) will return 0.|
|velocity\(\)|float32|void|Returns the current value of velocity. If the velocity is not set, returns 0.|
|set\_velocity\(\)|void|float32|Sets the value of velocity. After calling this, velocity\(\) will return value.|
|clear\_velocity\(\)|void|void|Clears the value of velocity. After calling this, velocity\(\) will return 0.|
|force\(\)|float32|void|Returns the current value of force. If the force is not set, returns 0.|
|set\_force\(\)|void|float32|Sets the value of force. After calling this, force\(\) will return value.|
|clear\_force\(\)|void|void|Clears the value of force. After calling this, force\(\) will return 0.|

**Parent topic:** [GripperCyclic \(C++\)](../../summary_pages/GripperCyclic.md)

