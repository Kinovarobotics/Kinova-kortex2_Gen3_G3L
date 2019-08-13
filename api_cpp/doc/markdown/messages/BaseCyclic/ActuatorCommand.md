# class ActuatorCommand

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id|uint32|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|
|flags|uint32|Flags|
|position|float32|Desired position of the actuator \(in degrees\)|
|velocity|float32|Desired velocity of the actuator \(in degrees per second\)|
|torque\_joint|float32|Desired torque of the actuator \(in Newton \* meters\)|
|current\_motor|float32|Desired current of the motor \(in Amperes\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|command\_id\(\)|uint32|void|Returns the current value of command\_id. If the command\_id is not set, returns 0.|
|set\_command\_id\(\)|void|uint32|Sets the value of command\_id. After calling this, command\_id\(\) will return value.|
|clear\_command\_id\(\)|void|void|Clears the value of command\_id. After calling this, command\_id\(\) will return 0.|
|flags\(\)|uint32|void|Returns the current value of flags. If the flags is not set, returns 0.|
|set\_flags\(\)|void|uint32|Sets the value of flags. After calling this, flags\(\) will return value.|
|clear\_flags\(\)|void|void|Clears the value of flags. After calling this, flags\(\) will return 0.|
|position\(\)|float32|void|Returns the current value of position. If the position is not set, returns 0.|
|set\_position\(\)|void|float32|Sets the value of position. After calling this, position\(\) will return value.|
|clear\_position\(\)|void|void|Clears the value of position. After calling this, position\(\) will return 0.|
|velocity\(\)|float32|void|Returns the current value of velocity. If the velocity is not set, returns 0.|
|set\_velocity\(\)|void|float32|Sets the value of velocity. After calling this, velocity\(\) will return value.|
|clear\_velocity\(\)|void|void|Clears the value of velocity. After calling this, velocity\(\) will return 0.|
|torque\_joint\(\)|float32|void|Returns the current value of torque\_joint. If the torque\_joint is not set, returns 0.|
|set\_torque\_joint\(\)|void|float32|Sets the value of torque\_joint. After calling this, torque\_joint\(\) will return value.|
|clear\_torque\_joint\(\)|void|void|Clears the value of torque\_joint. After calling this, torque\_joint\(\) will return 0.|
|current\_motor\(\)|float32|void|Returns the current value of current\_motor. If the current\_motor is not set, returns 0.|
|set\_current\_motor\(\)|void|float32|Sets the value of current\_motor. After calling this, current\_motor\(\) will return value.|
|clear\_current\_motor\(\)|void|void|Clears the value of current\_motor. After calling this, current\_motor\(\) will return 0.|

**Parent topic:** [BaseCyclic \(C++\)](../../summary_pages/BaseCyclic.md)

