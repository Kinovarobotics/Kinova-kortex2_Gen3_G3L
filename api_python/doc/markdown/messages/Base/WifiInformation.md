# class WifiInformation

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|ssid| [Ssid](Ssid.md#)|SSID|To set ssid, you simply assign a value directly to a field within ssid. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|security\_type|int|Wi-Fi security type|You can manipulate the field security\_type as if it were a regular field. To clear the value of security\_type and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|encryption\_type|int|Wi-Fi encryption type|You can manipulate the field encryption\_type as if it were a regular field. To clear the value of encryption\_type and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|signal\_quality|int|Wi-Fi signal quality|You can manipulate the field signal\_quality as if it were a regular field. To clear the value of signal\_quality and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|signal\_strength|int|Wi-Fi signal power in dBm|You can manipulate the field signal\_strength as if it were a regular field. To clear the value of signal\_strength and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|frequency|int|Wi-Fi operating frequency \(channel\) in MHz|You can manipulate the field frequency as if it were a regular field. To clear the value of frequency and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|channel|int|Wi-Fi operating channel|You can manipulate the field channel as if it were a regular field. To clear the value of channel and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

