# class Feedback

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|feedback\_id| [MessageId](MessageId.md#)|MessageId|To set feedback\_id, you simply assign a value directly to a field within feedback\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|status\_flags|int|Status flags \(see enum StatusFlags for the rest\)|You can manipulate the field status\_flags as if it were a regular field. To clear the value of status\_flags and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|jitter\_comm|int|Jitter from the communication in μs|You can manipulate the field jitter\_comm as if it were a regular field. To clear the value of jitter\_comm and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|position|float|Position of the actuator \(degrees\)|You can manipulate the field position as if it were a regular field. To clear the value of position and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|velocity|float|Angular velocity of the actuator \(degrees per second\)|You can manipulate the field velocity as if it were a regular field. To clear the value of velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|torque|float|Torque of the actuator \(Newton meter\)|You can manipulate the field torque as if it were a regular field. To clear the value of torque and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|current\_motor|float|Current of the motor \(Amperes\)|You can manipulate the field current\_motor as if it were a regular field. To clear the value of current\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|voltage|float|Voltage of the main board in \(Volt\)|You can manipulate the field voltage as if it were a regular field. To clear the value of voltage and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|temperature\_motor|float|Motor temperature \(average of the three \(3\) temperatures \(degrees Celsius\)\)|You can manipulate the field temperature\_motor as if it were a regular field. To clear the value of temperature\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|temperature\_core|float|Microcontroller temperature in \(degrees Celsius\)|You can manipulate the field temperature\_core as if it were a regular field. To clear the value of temperature\_core and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|fault\_bank\_a|int|Bank A Fault \(see ActuatorConfig.SafetyIdentifier\)|You can manipulate the field fault\_bank\_a as if it were a regular field. To clear the value of fault\_bank\_a and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|fault\_bank\_b|int|Bank B Fault \(see ActuatorConfig.SafetyIdentifier\)|You can manipulate the field fault\_bank\_b as if it were a regular field. To clear the value of fault\_bank\_b and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|warning\_bank\_a|int|Bank A Warning \(see ActuatorConfig.SafetyIdentifier\)|You can manipulate the field warning\_bank\_a as if it were a regular field. To clear the value of warning\_bank\_a and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|warning\_bank\_b|int|Bank B Warning \(see ActuatorConfig.SafetyIdentifier\)|You can manipulate the field warning\_bank\_b as if it were a regular field. To clear the value of warning\_bank\_b and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [ActuatorCyclic \(Python\)](../../summary_pages/ActuatorCyclic.md)

