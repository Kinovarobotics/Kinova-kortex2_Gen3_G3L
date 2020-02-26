# class SequenceTask

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|group\_identifier|int|This field is deprecated and unused. Use task\_index in the SequenceTaskHandle instead.|You can manipulate the field group\_identifier as if it were a regular field. To clear the value of group\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|action| [Action](Action.md#)|Specifies the action to execute|To set action, you simply assign a value directly to a field within action. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|application\_data|str|Application data \(reserved for use by Web App\)|You can manipulate the field application\_data as if it were a regular field. To clear the value of application\_data and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

