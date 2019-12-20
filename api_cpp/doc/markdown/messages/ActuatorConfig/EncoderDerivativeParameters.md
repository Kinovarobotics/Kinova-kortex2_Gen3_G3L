# class EncoderDerivativeParameters

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|max\_window\_width|uint32|Maximum window width|
|min\_angle|float32|Minimum angle for derivative \(degrees\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|max\_window\_width\(\)|uint32|void|Returns the current value of max\_window\_width. If the max\_window\_width is not set, returns 0.|
|set\_max\_window\_width\(\)|void|uint32|Sets the value of max\_window\_width. After calling this, max\_window\_width\(\) will return value.|
|clear\_max\_window\_width\(\)|void|void|Clears the value of max\_window\_width. After calling this, max\_window\_width\(\) will return 0.|
|min\_angle\(\)|float32|void|Returns the current value of min\_angle. If the min\_angle is not set, returns 0.|
|set\_min\_angle\(\)|void|float32|Sets the value of min\_angle. After calling this, min\_angle\(\) will return value.|
|clear\_min\_angle\(\)|void|void|Clears the value of min\_angle. After calling this, min\_angle\(\) will return 0.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

