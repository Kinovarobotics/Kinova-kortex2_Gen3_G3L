# class ArmStateNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|active\_state|int|New arm state|You can manipulate the field active\_state as if it were a regular field. To clear the value of active\_state and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the arm state event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

