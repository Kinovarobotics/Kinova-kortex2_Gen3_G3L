# class ControllerNotification

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|controller\_state|oneof:state [ControllerState](ControllerState.md#)|Used to indicate if a controller connection or disconnection event occured|You can manipulate the field controller\_state as if it were a regular field. To clear the value of controller\_state and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|
|controller\_element|oneof:state [ControllerElementState](ControllerElementState.md#)|Used to indicate if a specific button \(or axis\) was pressed \(or moved\)|You can manipulate the field controller\_element as if it were a regular field. To clear the value of controller\_element and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|
|timestamp| [Timestamp](../Common/Timestamp.md#)|Event timestamp|To set timestamp, you simply assign a value directly to a field within timestamp. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|user\_handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User that caused the controller event|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection| [Connection](../Common/Connection.md#)|Connection that caused the controller event|To set connection, you simply assign a value directly to a field within connection. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

