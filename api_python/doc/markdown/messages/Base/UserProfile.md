# class UserProfile

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [UserProfileHandle](../Common/UserProfileHandle.md#)|User handle \(no need to set it with CreateUserProfile\(\)\)|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|username|str|Username, which is used to connect to robot \(or login via Web App\)|You can manipulate the field username as if it were a regular field. To clear the value of username and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|firstname|str|User's first name|You can manipulate the field firstname as if it were a regular field. To clear the value of firstname and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|lastname|str|User's last name|You can manipulate the field lastname as if it were a regular field. To clear the value of lastname and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|application\_data|str|Application data \(reserved for use by Web App\)|You can manipulate the field application\_data as if it were a regular field. To clear the value of application\_data and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

