# class ControllerHandle

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type|uint32|Controller device type|
|controller\_identifier|uint32|Controller device identifier|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|type\(\) const|uint32|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void|uint32|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|controller\_identifier\(\)|uint32|void|Returns the current value of controller\_identifier. If the controller\_identifier is not set, returns 0.|
|set\_controller\_identifier\(\)|void|uint32|Sets the value of controller\_identifier. After calling this, controller\_identifier\(\) will return value.|
|clear\_controller\_identifier\(\)|void|void|Clears the value of controller\_identifier. After calling this, controller\_identifier\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

