# class MessageId

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|Message ID \(first 2 bytes : device ID, last 2 bytes : sequence number\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\)|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return 0.|

**Parent topic:** [InterconnectCyclic \(C++\)](../../summary_pages/InterconnectCyclic.md)

