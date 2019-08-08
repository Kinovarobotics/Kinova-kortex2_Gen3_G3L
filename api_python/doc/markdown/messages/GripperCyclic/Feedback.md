# class Feedback

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|feedback\_id| [MessageId](MessageId.md#)|MessageId|To set feedback\_id, you simply assign a value directly to a field within feedback\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|status\_flags|int|Status flags \(see GripperConfig.RobotiqGripperStatusFlags\)|You can manipulate the field status\_flags as if it were a regular field. To clear the value of status\_flags and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|fault\_bank\_a|int|Fault bank A \(see GripperConfig.SafetyIdentifier\)|You can manipulate the field fault\_bank\_a as if it were a regular field. To clear the value of fault\_bank\_a and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|fault\_bank\_b|int|Fault bank B \(see GripperConfig.SafetyIdentifier\)|You can manipulate the field fault\_bank\_b as if it were a regular field. To clear the value of fault\_bank\_b and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|warning\_bank\_a|int|Warning bank A \(see GripperConfig.SafetyIdentifier\)|You can manipulate the field warning\_bank\_a as if it were a regular field. To clear the value of warning\_bank\_a and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|warning\_bank\_b|int|Warning bank B \(see GripperConfig.SafetyIdentifier\)|You can manipulate the field warning\_bank\_b as if it were a regular field. To clear the value of warning\_bank\_b and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|motor| [MotorFeedback](MotorFeedback.md#)| |Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [GripperCyclic \(Python\)](../../summary_pages/GripperCyclic.md)

