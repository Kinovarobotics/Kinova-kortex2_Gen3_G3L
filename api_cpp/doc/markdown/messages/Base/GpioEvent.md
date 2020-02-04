# class GpioEvent

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|input\_type|uint32|Type of controller input that caused the event\_identifier|
|behavior|uint32|GPIO behavior that occured|
|input\_identifier|uint32|GPIO PIN ID that caused the event|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|input\_type\(\) const|uint32|void|Returns the current value of input\_type. If the input\_type is not set, returns 0.|
|set\_input\_type\(\)|void|uint32|Sets the value of input\_type. After calling this, input\_type\(\) will return value.|
|clear\_input\_type\(\)|void|void|Clears the value of input\_type. After calling this, input\_type\(\) will return the empty string/empty bytes.|
|behavior\(\) const|uint32|void|Returns the current value of behavior. If the behavior is not set, returns 0.|
|set\_behavior\(\)|void|uint32|Sets the value of behavior. After calling this, behavior\(\) will return value.|
|clear\_behavior\(\)|void|void|Clears the value of behavior. After calling this, behavior\(\) will return the empty string/empty bytes.|
|input\_identifier\(\)|uint32|void|Returns the current value of input\_identifier. If the input\_identifier is not set, returns 0.|
|set\_input\_identifier\(\)|void|uint32|Sets the value of input\_identifier. After calling this, input\_identifier\(\) will return value.|
|clear\_input\_identifier\(\)|void|void|Clears the value of input\_identifier. After calling this, input\_identifier\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

