# class Connection

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|user\_handle| [UserProfileHandle](UserProfileHandle.md#)|User profile handle, or set to zero if no user logged in|To set user\_handle, you simply assign a value directly to a field within user\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|connection\_information|str|Connection info \(e.g. IP address with port number\)|You can manipulate the field connection\_information as if it were a regular field. To clear the value of connection\_information and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|connection\_identifier|int|Connection identifier|You can manipulate the field connection\_identifier as if it were a regular field. To clear the value of connection\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Common \(Python\)](../../summary_pages/Common.md)

