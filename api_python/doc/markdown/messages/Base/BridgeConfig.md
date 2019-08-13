# class BridgeConfig

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|device\_identifier|int|Identifier of the device to which the bridge is connecting.|You can manipulate the field device\_identifier as if it were a regular field. To clear the value of device\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|bridgetype|int|Bridge type.|You can manipulate the field bridgetype as if it were a regular field. To clear the value of bridgetype and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|port\_config| [BridgePortConfig](BridgePortConfig.md#)|Port configuration. If used to enable port bridging, it is optional. If no port config is given defaults for bridge type is used.|To set port\_config, you simply assign a value directly to a field within port\_config. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|bridge\_id| [BridgeIdentifier](BridgeIdentifier.md#)|Bridge identifier. Not used when creating bridge. It is used when retrieving configuration.|To set bridge\_id, you simply assign a value directly to a field within bridge\_id. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

