# class ControllerElementHandle

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|controller\_handle| [ControllerHandle](ControllerHandle.md#)|Controller handle|To set controller\_handle, you simply assign a value directly to a field within controller\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|button|oneof:identifier int|Button identifier \(only set if 'button' controller event, otherwise zero\)|You can manipulate the field button as if it were a regular field. To clear the value of button and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|
|axis|oneof:identifier int|Axis identifier \(only set if 'axis' controller event, otherwise zero\)|You can manipulate the field axis as if it were a regular field. To clear the value of axis and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

