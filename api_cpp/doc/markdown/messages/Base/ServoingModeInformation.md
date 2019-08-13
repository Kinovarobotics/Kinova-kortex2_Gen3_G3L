# class ServoingModeInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|servoing\_mode|uint32|Servoing mode|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|servoing\_mode\(\) const|uint32|void|Returns the current value of servoing\_mode. If the servoing\_mode is not set, returns 0.|
|set\_servoing\_mode\(\)|void|uint32|Sets the value of servoing\_mode. After calling this, servoing\_mode\(\) will return value.|
|clear\_servoing\_mode\(\)|void|void|Clears the value of servoing\_mode. After calling this, servoing\_mode\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

