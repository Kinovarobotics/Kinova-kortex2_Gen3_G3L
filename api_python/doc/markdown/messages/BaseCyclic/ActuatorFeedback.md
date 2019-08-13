# class ActuatorFeedback

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|command\_id|int|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|You can manipulate the field command\_id as if it were a regular field. To clear the value of command\_id and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|status\_flags|int|Status flags|You can manipulate the field status\_flags as if it were a regular field. To clear the value of status\_flags and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|jitter\_comm|int|Jitter from the communication \(in microseconds\)|You can manipulate the field jitter\_comm as if it were a regular field. To clear the value of jitter\_comm and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|position|float|Position of the actuator \(in degrees\)|You can manipulate the field position as if it were a regular field. To clear the value of position and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|velocity|float|Velocity of the actuator \(in degrees per second\)|You can manipulate the field velocity as if it were a regular field. To clear the value of velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|torque|float|Torque of the actuator \(in Newton \* meters\)|You can manipulate the field torque as if it were a regular field. To clear the value of torque and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|current\_motor|float|Current of the motor \(in Amperes\)|You can manipulate the field current\_motor as if it were a regular field. To clear the value of current\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|voltage|float|Voltage of the main board \(in Volts\)|You can manipulate the field voltage as if it were a regular field. To clear the value of voltage and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|temperature\_motor|float|Motor temperature \(maximum of the three \(3\) phase temperatures in °C\)|You can manipulate the field temperature\_motor as if it were a regular field. To clear the value of temperature\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|temperature\_core|float|Microcontroller temperature \(in degrees Celsius\)|You can manipulate the field temperature\_core as if it were a regular field. To clear the value of temperature\_core and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|fault\_bank\_a|int|Fault bank A|You can manipulate the field fault\_bank\_a as if it were a regular field. To clear the value of fault\_bank\_a and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|fault\_bank\_b|int|Fault bank B|You can manipulate the field fault\_bank\_b as if it were a regular field. To clear the value of fault\_bank\_b and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|warning\_bank\_a|int|Warning bank A|You can manipulate the field warning\_bank\_a as if it were a regular field. To clear the value of warning\_bank\_a and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|warning\_bank\_b|int|Warning bank B|You can manipulate the field warning\_bank\_b as if it were a regular field. To clear the value of warning\_bank\_b and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [BaseCyclic \(Python\)](../../summary_pages/BaseCyclic.md)

