# class Feedback

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|feedback\_id| [MessageId](MessageId.md#)|MessageId|
|status\_flags|uint32|Status flags \(see enum StatusFlags for the rest\)|
|jitter\_comm|uint32|Jitter from the communication in μs|
|position|float32|Position of the actuator \(degrees\)|
|velocity|float32|Angular velocity of the actuator \(degrees per second\)|
|torque|float32|Torque of the actuator \(Newton meter\)|
|current\_motor|float32|Current of the motor \(Amperes\)|
|voltage|float32|Voltage of the main board in \(Volt\)|
|temperature\_motor|float32|Motor temperature \(average of the three \(3\) temperatures \(degrees Celsius\)\)|
|temperature\_core|float32|Microcontroller temperature in \(degrees Celsius\)|
|fault\_bank\_a|uint32|Bank A Fault \(see ActuatorConfig.SafetyIdentifier\)|
|fault\_bank\_b|uint32|Bank B Fault \(see ActuatorConfig.SafetyIdentifier\)|
|warning\_bank\_a|uint32|Bank A Warning \(see ActuatorConfig.SafetyIdentifier\)|
|warning\_bank\_b|uint32|Bank B Warning \(see ActuatorConfig.SafetyIdentifier\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_feedback\_id\(\) const|bool|void|Returns true if feedback\_id is set.|
|feedback\_id\(\)|const [MessageId](MessageId.md#)&|void|Returns the current value of feedback\_id. If feedback\_id is not set, returns a [MessageId](MessageId.md#) with none of its fields set \(possibly feedback\_id::default\_instance\(\)\).|
|mutable\_feedback\_id\(\)| [MessageId](MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](MessageId.md#)\). After calling this, has\_feedback\_id\(\) will return true and feedback\_id\(\) will return a reference to the same instance of [MessageId](MessageId.md#).|
|clear\_feedback\_id\(\)|void|void|Clears the value of the field. After calling this, has\_feedback\_id\(\) will return false and feedback\_id\(\) will return the default value.|
|set\_allocated\_feedback\_id\(\)|void| [MessageId](MessageId.md#) \*|Sets the [MessageId](MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](MessageId.md#) object and has\_ [MessageId](MessageId.md#)\(\) will return true. Otherwise, if the feedback\_id is NULL, the behavior is the same as calling clear\_feedback\_id\(\).|
|release\_feedback\_id\(\)| [MessageId](MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](MessageId.md#) object, has\_feedback\_id\(\) will return false, and feedback\_id\(\) will return the default value.|
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

**Parent topic:** [ActuatorCyclic \(C++\)](../../summary_pages/ActuatorCyclic.md)

