# class FocusPoint

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|x|uint32|Pixel value on the X axis, between 0 and the current resolution width - 1|
|y|uint32|Pixel value on the Y axis, between 0 and the current resolution height - 1|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|x\(\)|uint32|void|Returns the current value of x. If the x is not set, returns 0.|
|set\_x\(\)|void|uint32|Sets the value of x. After calling this, x\(\) will return value.|
|clear\_x\(\)|void|void|Clears the value of x. After calling this, x\(\) will return 0.|
|y\(\)|uint32|void|Returns the current value of y. If the y is not set, returns 0.|
|set\_y\(\)|void|uint32|Sets the value of y. After calling this, y\(\) will return value.|
|clear\_y\(\)|void|void|Clears the value of y. After calling this, y\(\) will return 0.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

