# class MotorCommand

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|motor\_id|int|Motor ID \(1, nb\_motor\)|You can manipulate the field motor\_id as if it were a regular field. To clear the value of motor\_id and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|position|float|Desired position of the gripper fingers in percentage \(0-100%\)|You can manipulate the field position as if it were a regular field. To clear the value of position and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|velocity|float|Desired velocity in percentage \(0-100%\) with which position will be set|You can manipulate the field velocity as if it were a regular field. To clear the value of velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|force|float|This field is deprecated and unused. It will be removed in a future release.|You can manipulate the field force as if it were a regular field. To clear the value of force and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [GripperCyclic \(Python\)](../../summary_pages/GripperCyclic.md)

