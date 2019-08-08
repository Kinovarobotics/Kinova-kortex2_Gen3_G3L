# class Command

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|command\_id| [MessageId](MessageId.md#)|MessageId|To set command\_id, you simply assign a value directly to a field within command\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|flags|int|Command flags \(see enum CommandFlags\)|You can manipulate the field flags as if it were a regular field. To clear the value of flags and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|position|float|Desired position of the actuator \(degrees\)|You can manipulate the field position as if it were a regular field. To clear the value of position and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|velocity|float|Desired velocity of the actuator \(degrees per second\)|You can manipulate the field velocity as if it were a regular field. To clear the value of velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|torque\_joint|float|Desired torque of the actuator \(Newton-meters\)|You can manipulate the field torque\_joint as if it were a regular field. To clear the value of torque\_joint and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|current\_motor|float|Desired current of the motor \(Amperes\)|You can manipulate the field current\_motor as if it were a regular field. To clear the value of current\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [ActuatorCyclic \(Python\)](../../summary_pages/ActuatorCyclic.md)

