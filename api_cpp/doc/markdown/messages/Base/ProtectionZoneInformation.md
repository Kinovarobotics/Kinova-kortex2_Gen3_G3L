# class ProtectionZoneInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event|uint32|Event type|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|event\(\) const|uint32|void|Returns the current value of event. If the event is not set, returns 0.|
|set\_event\(\)|void|uint32|Sets the value of event. After calling this, event\(\) will return value.|
|clear\_event\(\)|void|void|Clears the value of event. After calling this, event\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

