# class ActionHandle

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|Action identifier|
|action\_type|uint32|Action type|
|permission|uint32|Permission of specified Action entity. Must use 'Kinova.Api.Common.Permission' enum.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\)|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return 0.|
|action\_type\(\) const|uint32|void|Returns the current value of action\_type. If the action\_type is not set, returns 0.|
|set\_action\_type\(\)|void|uint32|Sets the value of action\_type. After calling this, action\_type\(\) will return value.|
|clear\_action\_type\(\)|void|void|Clears the value of action\_type. After calling this, action\_type\(\) will return the empty string/empty bytes.|
|permission\(\)|uint32|void|Returns the current value of permission. If the permission is not set, returns 0.|
|set\_permission\(\)|void|uint32|Sets the value of permission. After calling this, permission\(\) will return value.|
|clear\_permission\(\)|void|void|Clears the value of permission. After calling this, permission\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

