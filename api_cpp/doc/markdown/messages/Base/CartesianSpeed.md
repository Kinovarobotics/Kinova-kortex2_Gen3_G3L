# class CartesianSpeed

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|translation|float32|Translation speed \(in meters per second\)|
|orientation|float32|Orientation speed \(in degrees per second\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|translation\(\)|float32|void|Returns the current value of translation. If the translation is not set, returns 0.|
|set\_translation\(\)|void|float32|Sets the value of translation. After calling this, translation\(\) will return value.|
|clear\_translation\(\)|void|void|Clears the value of translation. After calling this, translation\(\) will return 0.|
|orientation\(\)|float32|void|Returns the current value of orientation. If the orientation is not set, returns 0.|
|set\_orientation\(\)|void|float32|Sets the value of orientation. After calling this, orientation\(\) will return value.|
|clear\_orientation\(\)|void|void|Clears the value of orientation. After calling this, orientation\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

