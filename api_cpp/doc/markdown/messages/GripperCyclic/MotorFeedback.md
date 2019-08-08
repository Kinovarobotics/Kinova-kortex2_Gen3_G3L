# class MotorFeedback

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|motor\_id|uint32|Motor ID \(1, nb\_motor\)|
|position|float32|Position of the gripper fingers in percentage \(0-100%\)|
|velocity|float32|Velocity of the gripper fingers in percentage \(0-100%\)|
|current\_motor|float32|Current comsumed by the gripper motor \(mA\)|
|voltage|float32|Motor Voltage \(V\)|
|temperature\_motor|float32|Motor temperature. \(degrees Celsius\)|

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
|current\_motor\(\)|float32|void|Returns the current value of current\_motor. If the current\_motor is not set, returns 0.|
|set\_current\_motor\(\)|void|float32|Sets the value of current\_motor. After calling this, current\_motor\(\) will return value.|
|clear\_current\_motor\(\)|void|void|Clears the value of current\_motor. After calling this, current\_motor\(\) will return 0.|
|voltage\(\)|float32|void|Returns the current value of voltage. If the voltage is not set, returns 0.|
|set\_voltage\(\)|void|float32|Sets the value of voltage. After calling this, voltage\(\) will return value.|
|clear\_voltage\(\)|void|void|Clears the value of voltage. After calling this, voltage\(\) will return 0.|
|temperature\_motor\(\)|float32|void|Returns the current value of temperature\_motor. If the temperature\_motor is not set, returns 0.|
|set\_temperature\_motor\(\)|void|float32|Sets the value of temperature\_motor. After calling this, temperature\_motor\(\) will return value.|
|clear\_temperature\_motor\(\)|void|void|Clears the value of temperature\_motor. After calling this, temperature\_motor\(\) will return 0.|

**Parent topic:** [GripperCyclic \(C++\)](../../summary_pages/GripperCyclic.md)

