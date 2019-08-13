# class MotorFeedback

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|motor\_id|int|Motor ID \(1, nb\_motor\)|You can manipulate the field motor\_id as if it were a regular field. To clear the value of motor\_id and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|position|float|Position of the gripper fingers in percentage \(0-100%\)|You can manipulate the field position as if it were a regular field. To clear the value of position and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|velocity|float|Velocity of the gripper fingers in percentage \(0-100%\)|You can manipulate the field velocity as if it were a regular field. To clear the value of velocity and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|current\_motor|float|Current comsumed by the gripper motor \(mA\)|You can manipulate the field current\_motor as if it were a regular field. To clear the value of current\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|voltage|float|Motor Voltage \(V\)|You can manipulate the field voltage as if it were a regular field. To clear the value of voltage and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|temperature\_motor|float|Motor temperature. \(degrees Celsius\)|You can manipulate the field temperature\_motor as if it were a regular field. To clear the value of temperature\_motor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [GripperCyclic \(Python\)](../../summary_pages/GripperCyclic.md)

