# class TwistLimitation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|linear|float32|Linear limitation|
|angular|float32|Angular limitation|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|linear\(\)|float32|void|Returns the current value of linear. If the linear is not set, returns 0.|
|set\_linear\(\)|void|float32|Sets the value of linear. After calling this, linear\(\) will return value.|
|clear\_linear\(\)|void|void|Clears the value of linear. After calling this, linear\(\) will return 0.|
|angular\(\)|float32|void|Returns the current value of angular. If the angular is not set, returns 0.|
|set\_angular\(\)|void|float32|Sets the value of angular. After calling this, angular\(\) will return value.|
|clear\_angular\(\)|void|void|Clears the value of angular. After calling this, angular\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

