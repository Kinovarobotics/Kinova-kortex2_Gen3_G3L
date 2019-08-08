# class WifiConfiguration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|ssid| [Ssid](Ssid.md#)|SSID|To set ssid, you simply assign a value directly to a field within ssid. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|security\_key|str|Security key to used when connecting to Wi-Fi network|You can manipulate the field security\_key as if it were a regular field. To clear the value of security\_key and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|connect\_automatically|bool|Connection mode. Set to true so robot automatically connects to this Wi-Fi network at bootup, false otherwise|You can manipulate the field connect\_automatically as if it were a regular field. To clear the value of connect\_automatically and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

