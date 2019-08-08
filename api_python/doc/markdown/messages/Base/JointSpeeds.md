# class JointSpeeds

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|joint\_speeds| [JointSpeed](JointSpeed.md#)|Array of joint speeds|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|
|duration|int|Duration constraint. If not 0, allows to set a limit \(in seconds\) common to every joint specified in 'joint\_speeds' \(not implemented yet\)|You can manipulate the field duration as if it were a regular field. To clear the value of duration and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

