# class NotificationOptions

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|type|uint32|Type of notification|
|rate\_m\_sec|uint32|Rate value \(in meters per second\) \(if applicable\)|
|threshold\_value|float32|Threshold value \(if applicable\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|type\(\) const|uint32|void|Returns the current value of type. If the type is not set, returns 0.|
|set\_type\(\)|void|uint32|Sets the value of type. After calling this, type\(\) will return value.|
|clear\_type\(\)|void|void|Clears the value of type. After calling this, type\(\) will return the empty string/empty bytes.|
|rate\_m\_sec\(\)|uint32|void|Returns the current value of rate\_m\_sec. If the rate\_m\_sec is not set, returns 0.|
|set\_rate\_m\_sec\(\)|void|uint32|Sets the value of rate\_m\_sec. After calling this, rate\_m\_sec\(\) will return value.|
|clear\_rate\_m\_sec\(\)|void|void|Clears the value of rate\_m\_sec. After calling this, rate\_m\_sec\(\) will return 0.|
|threshold\_value\(\)|float32|void|Returns the current value of threshold\_value. If the threshold\_value is not set, returns 0.|
|set\_threshold\_value\(\)|void|float32|Sets the value of threshold\_value. After calling this, threshold\_value\(\) will return value.|
|clear\_threshold\_value\(\)|void|void|Clears the value of threshold\_value. After calling this, threshold\_value\(\) will return 0.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

