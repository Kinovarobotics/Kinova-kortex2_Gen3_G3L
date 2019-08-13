# class Finger

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|finger\_identifier|uint32|Finger identifier|
|value|float32| |

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|finger\_identifier\(\)|uint32|void|Returns the current value of finger\_identifier. If the finger\_identifier is not set, returns 0.|
|set\_finger\_identifier\(\)|void|uint32|Sets the value of finger\_identifier. After calling this, finger\_identifier\(\) will return value.|
|clear\_finger\_identifier\(\)|void|void|Clears the value of finger\_identifier. After calling this, finger\_identifier\(\) will return 0.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

