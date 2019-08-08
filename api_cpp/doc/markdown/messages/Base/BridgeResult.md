# class BridgeResult

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|bridge\_id| [BridgeIdentifier](BridgeIdentifier.md#)|ID of the bridge on which operation was performed|
|status|uint32|Result code of operation.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_bridge\_id\(\) const|bool|void|Returns true if bridge\_id is set.|
|bridge\_id\(\)|const [BridgeIdentifier](BridgeIdentifier.md#)&|void|Returns the current value of bridge\_id. If bridge\_id is not set, returns a [BridgeIdentifier](BridgeIdentifier.md#) with none of its fields set \(possibly bridge\_id::default\_instance\(\)\).|
|mutable\_bridge\_id\(\)| [BridgeIdentifier](BridgeIdentifier.md#) \*|void|Returns a pointer to the mutable [BridgeIdentifier](BridgeIdentifier.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [BridgeIdentifier](BridgeIdentifier.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [BridgeIdentifier](BridgeIdentifier.md#)\). After calling this, has\_bridge\_id\(\) will return true and bridge\_id\(\) will return a reference to the same instance of [BridgeIdentifier](BridgeIdentifier.md#).|
|clear\_bridge\_id\(\)|void|void|Clears the value of the field. After calling this, has\_bridge\_id\(\) will return false and bridge\_id\(\) will return the default value.|
|set\_allocated\_bridge\_id\(\)|void| [BridgeIdentifier](BridgeIdentifier.md#) \*|Sets the [BridgeIdentifier](BridgeIdentifier.md#) object to the field and frees the previous field value if it exists. If the [BridgeIdentifier](BridgeIdentifier.md#) pointer is not NULL, the message takes ownership of the allocated [BridgeIdentifier](BridgeIdentifier.md#) object and has\_ [BridgeIdentifier](BridgeIdentifier.md#)\(\) will return true. Otherwise, if the bridge\_id is NULL, the behavior is the same as calling clear\_bridge\_id\(\).|
|release\_bridge\_id\(\)| [BridgeIdentifier](BridgeIdentifier.md#) \*|void|Releases the ownership of the field and returns the pointer of the [BridgeIdentifier](BridgeIdentifier.md#) object. After calling this, caller takes the ownership of the allocated [BridgeIdentifier](BridgeIdentifier.md#) object, has\_bridge\_id\(\) will return false, and bridge\_id\(\) will return the default value.|
|status\(\) const|uint32|void|Returns the current value of status. If the status is not set, returns 0.|
|set\_status\(\)|void|uint32|Sets the value of status. After calling this, status\(\) will return value.|
|clear\_status\(\)|void|void|Clears the value of status. After calling this, status\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

