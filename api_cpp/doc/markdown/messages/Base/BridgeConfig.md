# class BridgeConfig

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device\_identifier|uint32|Identifier of the device to which the bridge is connecting.|
|bridgetype|uint32|Bridge type.|
|port\_config| [BridgePortConfig](BridgePortConfig.md#)|Port configuration. If used to enable port bridging, it is optional. If no port config is given defaults for bridge type is used.|
|bridge\_id| [BridgeIdentifier](BridgeIdentifier.md#)|Bridge identifier. Not used when creating bridge. It is used when retrieving configuration.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|device\_identifier\(\)|uint32|void|Returns the current value of device\_identifier. If the device\_identifier is not set, returns 0.|
|set\_device\_identifier\(\)|void|uint32|Sets the value of device\_identifier. After calling this, device\_identifier\(\) will return value.|
|clear\_device\_identifier\(\)|void|void|Clears the value of device\_identifier. After calling this, device\_identifier\(\) will return 0.|
|bridgetype\(\) const|uint32|void|Returns the current value of bridgetype. If the bridgetype is not set, returns 0.|
|set\_bridgetype\(\)|void|uint32|Sets the value of bridgetype. After calling this, bridgetype\(\) will return value.|
|clear\_bridgetype\(\)|void|void|Clears the value of bridgetype. After calling this, bridgetype\(\) will return the empty string/empty bytes.|
|has\_port\_config\(\) const|bool|void|Returns true if port\_config is set.|
|port\_config\(\)|const [BridgePortConfig](BridgePortConfig.md#)&|void|Returns the current value of port\_config. If port\_config is not set, returns a [BridgePortConfig](BridgePortConfig.md#) with none of its fields set \(possibly port\_config::default\_instance\(\)\).|
|mutable\_port\_config\(\)| [BridgePortConfig](BridgePortConfig.md#) \*|void|Returns a pointer to the mutable [BridgePortConfig](BridgePortConfig.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [BridgePortConfig](BridgePortConfig.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [BridgePortConfig](BridgePortConfig.md#)\). After calling this, has\_port\_config\(\) will return true and port\_config\(\) will return a reference to the same instance of [BridgePortConfig](BridgePortConfig.md#).|
|clear\_port\_config\(\)|void|void|Clears the value of the field. After calling this, has\_port\_config\(\) will return false and port\_config\(\) will return the default value.|
|set\_allocated\_port\_config\(\)|void| [BridgePortConfig](BridgePortConfig.md#) \*|Sets the [BridgePortConfig](BridgePortConfig.md#) object to the field and frees the previous field value if it exists. If the [BridgePortConfig](BridgePortConfig.md#) pointer is not NULL, the message takes ownership of the allocated [BridgePortConfig](BridgePortConfig.md#) object and has\_ [BridgePortConfig](BridgePortConfig.md#)\(\) will return true. Otherwise, if the port\_config is NULL, the behavior is the same as calling clear\_port\_config\(\).|
|release\_port\_config\(\)| [BridgePortConfig](BridgePortConfig.md#) \*|void|Releases the ownership of the field and returns the pointer of the [BridgePortConfig](BridgePortConfig.md#) object. After calling this, caller takes the ownership of the allocated [BridgePortConfig](BridgePortConfig.md#) object, has\_port\_config\(\) will return false, and port\_config\(\) will return the default value.|
|has\_bridge\_id\(\) const|bool|void|Returns true if bridge\_id is set.|
|bridge\_id\(\)|const [BridgeIdentifier](BridgeIdentifier.md#)&|void|Returns the current value of bridge\_id. If bridge\_id is not set, returns a [BridgeIdentifier](BridgeIdentifier.md#) with none of its fields set \(possibly bridge\_id::default\_instance\(\)\).|
|mutable\_bridge\_id\(\)| [BridgeIdentifier](BridgeIdentifier.md#) \*|void|Returns a pointer to the mutable [BridgeIdentifier](BridgeIdentifier.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [BridgeIdentifier](BridgeIdentifier.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [BridgeIdentifier](BridgeIdentifier.md#)\). After calling this, has\_bridge\_id\(\) will return true and bridge\_id\(\) will return a reference to the same instance of [BridgeIdentifier](BridgeIdentifier.md#).|
|clear\_bridge\_id\(\)|void|void|Clears the value of the field. After calling this, has\_bridge\_id\(\) will return false and bridge\_id\(\) will return the default value.|
|set\_allocated\_bridge\_id\(\)|void| [BridgeIdentifier](BridgeIdentifier.md#) \*|Sets the [BridgeIdentifier](BridgeIdentifier.md#) object to the field and frees the previous field value if it exists. If the [BridgeIdentifier](BridgeIdentifier.md#) pointer is not NULL, the message takes ownership of the allocated [BridgeIdentifier](BridgeIdentifier.md#) object and has\_ [BridgeIdentifier](BridgeIdentifier.md#)\(\) will return true. Otherwise, if the bridge\_id is NULL, the behavior is the same as calling clear\_bridge\_id\(\).|
|release\_bridge\_id\(\)| [BridgeIdentifier](BridgeIdentifier.md#) \*|void|Releases the ownership of the field and returns the pointer of the [BridgeIdentifier](BridgeIdentifier.md#) object. After calling this, caller takes the ownership of the allocated [BridgeIdentifier](BridgeIdentifier.md#) object, has\_bridge\_id\(\) will return false, and bridge\_id\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

