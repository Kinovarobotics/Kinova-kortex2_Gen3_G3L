# class ActuatorCommand

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|command\_id|int|Command ID \(first 2 bytes: device ID, last 2 bytes: sequence number\)|You can manipulate the field command\_id as if it were a regular field. To clear the value of command\_id and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|flags|int|Flags|You can manipulate the field flags as if it were a regular field. To clear the value of flags and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|position|float|Desired position of the actuator \(in degrees\)|You can manipulate the field position as if it were a regular field. To clear the value of position and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|velocity|float|Desired velocity of the actuator \(in degrees per second\)|You can manipulate the field velocity as if it were a regular field. To clear the value of velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|torque\_joint|float|Desired torque of the actuator \(in Newton \* meters\)|You can manipulate the field torque\_joint as if it were a regular field. To clear the value of torque\_joint and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|current\_motor|float|Desired current of the motor \(in Amperes\)|You can manipulate the field current\_motor as if it were a regular field. To clear the value of current\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [BaseCyclic \(Python\)](../../summary_pages/BaseCyclic.md)

