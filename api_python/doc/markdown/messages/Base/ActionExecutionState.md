# class ActionExecutionState

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|action\_event|int|Action event type|You can manipulate the field action\_event as if it were a regular field. To clear the value of action\_event and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|handle| [ActionHandle](ActionHandle.md#)|Identifies the action for which this event occured|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

