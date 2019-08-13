# class Timestamp

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sec|uint32|Number of seconds that have elapsed since Epoch|
|usec|uint32|Number of microseconds that have elapsed since the last second \(0-999999\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sec\(\)|uint32|void|Returns the current value of sec. If the sec is not set, returns 0.|
|set\_sec\(\)|void|uint32|Sets the value of sec. After calling this, sec\(\) will return value.|
|clear\_sec\(\)|void|void|Clears the value of sec. After calling this, sec\(\) will return 0.|
|usec\(\)|uint32|void|Returns the current value of usec. If the usec is not set, returns 0.|
|set\_usec\(\)|void|uint32|Sets the value of usec. After calling this, usec\(\) will return value.|
|clear\_usec\(\)|void|void|Clears the value of usec. After calling this, usec\(\) will return 0.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

