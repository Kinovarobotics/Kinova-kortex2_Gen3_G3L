# class FullUserProfile

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|user\_profile| [UserProfile](UserProfile.md#)|Information about the user, including its username.|To set user\_profile, you simply assign a value directly to a field within user\_profile. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|password|str|User's password|You can manipulate the field password as if it were a regular field. To clear the value of password and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

