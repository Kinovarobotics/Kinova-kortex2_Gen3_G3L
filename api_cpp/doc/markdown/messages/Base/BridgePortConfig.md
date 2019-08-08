# class BridgePortConfig

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|target\_port|uint32|Port on target device.|
|out\_port|uint32|Port exposed on base's external interface|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|target\_port\(\)|uint32|void|Returns the current value of target\_port. If the target\_port is not set, returns 0.|
|set\_target\_port\(\)|void|uint32|Sets the value of target\_port. After calling this, target\_port\(\) will return value.|
|clear\_target\_port\(\)|void|void|Clears the value of target\_port. After calling this, target\_port\(\) will return 0.|
|out\_port\(\)|uint32|void|Returns the current value of out\_port. If the out\_port is not set, returns 0.|
|set\_out\_port\(\)|void|uint32|Sets the value of out\_port. After calling this, out\_port\(\) will return value.|
|clear\_out\_port\(\)|void|void|Clears the value of out\_port. After calling this, out\_port\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

