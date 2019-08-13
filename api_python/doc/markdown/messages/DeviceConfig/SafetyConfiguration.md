# class SafetyConfiguration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [SafetyHandle](../Common/SafetyHandle.md#)|Handle to safety to configure|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|error\_threshold|float|Safety error threshold value|You can manipulate the field error\_threshold as if it were a regular field. To clear the value of error\_threshold and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|warning\_threshold|float|Safety warning threshold value|You can manipulate the field warning\_threshold as if it were a regular field. To clear the value of warning\_threshold and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|enable| [SafetyEnable](SafetyEnable.md#)|Safety enable state|To set enable, you simply assign a value directly to a field within enable. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [DeviceConfig \(Python\)](../../summary_pages/DeviceConfig.md)

