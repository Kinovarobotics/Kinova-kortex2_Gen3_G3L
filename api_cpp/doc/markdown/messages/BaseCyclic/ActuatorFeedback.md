# class ActuatorFeedback

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id|uint32|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|
|status\_flags|uint32|Status flags|
|jitter\_comm|uint32|Jitter from the communication \(in microseconds\)|
|position|float32|Position of the actuator \(in degrees\)|
|velocity|float32|Velocity of the actuator \(in degrees per second\)|
|torque|float32|Torque of the actuator \(in Newton \* meters\)|
|current\_motor|float32|Current of the motor \(in Amperes\)|
|voltage|float32|Voltage of the main board \(in Volts\)|
|temperature\_motor|float32|Motor temperature \(maximum of the three \(3\) phase temperatures in °C\)|
|temperature\_core|float32|Microcontroller temperature \(in degrees Celsius\)|
|fault\_bank\_a|uint32|Fault bank A|
|fault\_bank\_b|uint32|Fault bank B|
|warning\_bank\_a|uint32|Warning bank A|
|warning\_bank\_b|uint32|Warning bank B|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|command\_id\(\)|uint32|void|Returns the current value of command\_id. If the command\_id is not set, returns 0.|
|set\_command\_id\(\)|void|uint32|Sets the value of command\_id. After calling this, command\_id\(\) will return value.|
|clear\_command\_id\(\)|void|void|Clears the value of command\_id. After calling this, command\_id\(\) will return 0.|
|status\_flags\(\)|uint32|void|Returns the current value of status\_flags. If the status\_flags is not set, returns 0.|
|set\_status\_flags\(\)|void|uint32|Sets the value of status\_flags. After calling this, status\_flags\(\) will return value.|
|clear\_status\_flags\(\)|void|void|Clears the value of status\_flags. After calling this, status\_flags\(\) will return 0.|
|jitter\_comm\(\)|uint32|void|Returns the current value of jitter\_comm. If the jitter\_comm is not set, returns 0.|
|set\_jitter\_comm\(\)|void|uint32|Sets the value of jitter\_comm. After calling this, jitter\_comm\(\) will return value.|
|clear\_jitter\_comm\(\)|void|void|Clears the value of jitter\_comm. After calling this, jitter\_comm\(\) will return 0.|
|position\(\)|float32|void|Returns the current value of position. If the position is not set, returns 0.|
|set\_position\(\)|void|float32|Sets the value of position. After calling this, position\(\) will return value.|
|clear\_position\(\)|void|void|Clears the value of position. After calling this, position\(\) will return 0.|
|velocity\(\)|float32|void|Returns the current value of velocity. If the velocity is not set, returns 0.|
|set\_velocity\(\)|void|float32|Sets the value of velocity. After calling this, velocity\(\) will return value.|
|clear\_velocity\(\)|void|void|Clears the value of velocity. After calling this, velocity\(\) will return 0.|
|torque\(\)|float32|void|Returns the current value of torque. If the torque is not set, returns 0.|
|set\_torque\(\)|void|float32|Sets the value of torque. After calling this, torque\(\) will return value.|
|clear\_torque\(\)|void|void|Clears the value of torque. After calling this, torque\(\) will return 0.|
|current\_motor\(\)|float32|void|Returns the current value of current\_motor. If the current\_motor is not set, returns 0.|
|set\_current\_motor\(\)|void|float32|Sets the value of current\_motor. After calling this, current\_motor\(\) will return value.|
|clear\_current\_motor\(\)|void|void|Clears the value of current\_motor. After calling this, current\_motor\(\) will return 0.|
|voltage\(\)|float32|void|Returns the current value of voltage. If the voltage is not set, returns 0.|
|set\_voltage\(\)|void|float32|Sets the value of voltage. After calling this, voltage\(\) will return value.|
|clear\_voltage\(\)|void|void|Clears the value of voltage. After calling this, voltage\(\) will return 0.|
|temperature\_motor\(\)|float32|void|Returns the current value of temperature\_motor. If the temperature\_motor is not set, returns 0.|
|set\_temperature\_motor\(\)|void|float32|Sets the value of temperature\_motor. After calling this, temperature\_motor\(\) will return value.|
|clear\_temperature\_motor\(\)|void|void|Clears the value of temperature\_motor. After calling this, temperature\_motor\(\) will return 0.|
|temperature\_core\(\)|float32|void|Returns the current value of temperature\_core. If the temperature\_core is not set, returns 0.|
|set\_temperature\_core\(\)|void|float32|Sets the value of temperature\_core. After calling this, temperature\_core\(\) will return value.|
|clear\_temperature\_core\(\)|void|void|Clears the value of temperature\_core. After calling this, temperature\_core\(\) will return 0.|
|fault\_bank\_a\(\)|uint32|void|Returns the current value of fault\_bank\_a. If the fault\_bank\_a is not set, returns 0.|
|set\_fault\_bank\_a\(\)|void|uint32|Sets the value of fault\_bank\_a. After calling this, fault\_bank\_a\(\) will return value.|
|clear\_fault\_bank\_a\(\)|void|void|Clears the value of fault\_bank\_a. After calling this, fault\_bank\_a\(\) will return 0.|
|fault\_bank\_b\(\)|uint32|void|Returns the current value of fault\_bank\_b. If the fault\_bank\_b is not set, returns 0.|
|set\_fault\_bank\_b\(\)|void|uint32|Sets the value of fault\_bank\_b. After calling this, fault\_bank\_b\(\) will return value.|
|clear\_fault\_bank\_b\(\)|void|void|Clears the value of fault\_bank\_b. After calling this, fault\_bank\_b\(\) will return 0.|
|warning\_bank\_a\(\)|uint32|void|Returns the current value of warning\_bank\_a. If the warning\_bank\_a is not set, returns 0.|
|set\_warning\_bank\_a\(\)|void|uint32|Sets the value of warning\_bank\_a. After calling this, warning\_bank\_a\(\) will return value.|
|clear\_warning\_bank\_a\(\)|void|void|Clears the value of warning\_bank\_a. After calling this, warning\_bank\_a\(\) will return 0.|
|warning\_bank\_b\(\)|uint32|void|Returns the current value of warning\_bank\_b. If the warning\_bank\_b is not set, returns 0.|
|set\_warning\_bank\_b\(\)|void|uint32|Sets the value of warning\_bank\_b. After calling this, warning\_bank\_b\(\) will return value.|
|clear\_warning\_bank\_b\(\)|void|void|Clears the value of warning\_bank\_b. After calling this, warning\_bank\_b\(\) will return 0.|

**Parent topic:** [BaseCyclic \(C++\)](../../summary_pages/BaseCyclic.md)

