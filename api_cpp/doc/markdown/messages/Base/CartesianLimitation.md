# class CartesianLimitation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type|uint32|Limitation type|
|translation|float32|Translation limitation|
|orientation|float32|Orientation limitation|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|type\(\) const|uint32|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void|uint32|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|translation\(\)|float32|void|Returns the current value of translation. If the translation is not set, returns 0.|
|set\_translation\(\)|void|float32|Sets the value of translation. After calling this, translation\(\) will return value.|
|clear\_translation\(\)|void|void|Clears the value of translation. After calling this, translation\(\) will return 0.|
|orientation\(\)|float32|void|Returns the current value of orientation. If the orientation is not set, returns 0.|
|set\_orientation\(\)|void|float32|Sets the value of orientation. After calling this, orientation\(\) will return value.|
|clear\_orientation\(\)|void|void|Clears the value of orientation. After calling this, orientation\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

