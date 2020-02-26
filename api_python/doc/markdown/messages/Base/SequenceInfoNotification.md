# class SequenceInfoNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|event\_identifier|int|Sequence event type|You can manipulate the field event\_identifier as if it were a regular field. To clear the value of event\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|sequence\_handle| [SequenceHandle](SequenceHandle.md#)|Handle of the sequence that this event refers to|To set sequence\_handle, you simply assign a value directly to a field within sequence\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|task\_index|int|Task index|You can manipulate the field task\_index as if it were a regular field. To clear the value of task\_index and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|group\_identifier|int|This field is deprecated and unused. Use task\_index instead.|You can manipulate the field group\_identifier as if it were a regular field. To clear the value of group\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the sequence event|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|abort\_details|int|Details if event\_identifier is equal to ABORT|You can manipulate the field abort\_details as if it were a regular field. To clear the value of abort\_details and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the sequence event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

