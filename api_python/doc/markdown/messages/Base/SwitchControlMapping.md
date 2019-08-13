# class SwitchControlMapping

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|controller\_identifier|int|Identifier of the controller for which changing the active map is requested|You can manipulate the field controller\_identifier as if it were a regular field. To clear the value of controller\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|map\_group\_handle| [MapGroupHandle](MapGroupHandle.md#)|Reference to the map group for which the active map needs to change|To set map\_group\_handle, you simply assign a value directly to a field within map\_group\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|map\_handle| [MapHandle](MapHandle.md#)|Reference to new active map|To set map\_handle, you simply assign a value directly to a field within map\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

