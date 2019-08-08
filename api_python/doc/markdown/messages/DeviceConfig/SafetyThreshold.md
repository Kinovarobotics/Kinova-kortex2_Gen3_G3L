# class SafetyThreshold

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [SafetyHandle](../Common/SafetyHandle.md#)|Identifies safety to configure|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|value|float|Safety threshold value|You can manipulate the field value as if it were a regular field. To clear the value of value and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [DeviceConfig \(Python\)](../../summary_pages/DeviceConfig.md)

