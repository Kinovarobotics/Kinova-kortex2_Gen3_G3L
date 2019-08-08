# class SafetyEnable

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [SafetyHandle](../Common/SafetyHandle.md#)|Handle to safety to enable or disable|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|enable|bool|Safety enable state|You can manipulate the field enable as if it were a regular field. To clear the value of enable and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [DeviceConfig \(Python\)](../../summary_pages/DeviceConfig.md)

