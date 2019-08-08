# class EncoderDerivativeParameters

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|max\_window\_width|uint32|Maximum window width|
|min\_encoder\_tick\_count|uint32|Minimum encoder tick count|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|max\_window\_width\(\)|uint32|void|Returns the current value of max\_window\_width. If the max\_window\_width is not set, returns 0.|
|set\_max\_window\_width\(\)|void|uint32|Sets the value of max\_window\_width. After calling this, max\_window\_width\(\) will return value.|
|clear\_max\_window\_width\(\)|void|void|Clears the value of max\_window\_width. After calling this, max\_window\_width\(\) will return 0.|
|min\_encoder\_tick\_count\(\)|uint32|void|Returns the current value of min\_encoder\_tick\_count. If the min\_encoder\_tick\_count is not set, returns 0.|
|set\_min\_encoder\_tick\_count\(\)|void|uint32|Sets the value of min\_encoder\_tick\_count. After calling this, min\_encoder\_tick\_count\(\) will return value.|
|clear\_min\_encoder\_tick\_count\(\)|void|void|Clears the value of min\_encoder\_tick\_count. After calling this, min\_encoder\_tick\_count\(\) will return 0.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

