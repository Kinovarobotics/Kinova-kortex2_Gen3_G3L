# class PasswordChange

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User handle|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|old\_password|str|Current password|You can manipulate the field old\_password as if it were a regular field. To clear the value of old\_password and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|new\_password|str|New password|You can manipulate the field new\_password as if it were a regular field. To clear the value of new\_password and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

