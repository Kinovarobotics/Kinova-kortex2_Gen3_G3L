# class CapSenseConfig

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|identifier|uint32|MessageId|
|mode|uint32|Operational mode of the sensor|
|threshold\_a|float32|Threshold of the sensor A \(successive detection count to trigger a change of state\)|
|threshold\_b|float32|Threshold of the sensor B \(successive detection count to trigger a change of state\)|
|sensitivity\_a|float32|Sensitivity of the sensor A \(picofarad\)|
|sensitivity\_b|float32|Sensitivity of the sensor B \(picofarad\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|identifier\(\)|uint32|void|Returns the current value of identifier. If the identifier is not set, returns 0.|
|set\_identifier\(\)|void|uint32|Sets the value of identifier. After calling this, identifier\(\) will return value.|
|clear\_identifier\(\)|void|void|Clears the value of identifier. After calling this, identifier\(\) will return 0.|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|threshold\_a\(\)|float32|void|Returns the current value of threshold\_a. If the threshold\_a is not set, returns 0.|
|set\_threshold\_a\(\)|void|float32|Sets the value of threshold\_a. After calling this, threshold\_a\(\) will return value.|
|clear\_threshold\_a\(\)|void|void|Clears the value of threshold\_a. After calling this, threshold\_a\(\) will return 0.|
|threshold\_b\(\)|float32|void|Returns the current value of threshold\_b. If the threshold\_b is not set, returns 0.|
|set\_threshold\_b\(\)|void|float32|Sets the value of threshold\_b. After calling this, threshold\_b\(\) will return value.|
|clear\_threshold\_b\(\)|void|void|Clears the value of threshold\_b. After calling this, threshold\_b\(\) will return 0.|
|sensitivity\_a\(\)|float32|void|Returns the current value of sensitivity\_a. If the sensitivity\_a is not set, returns 0.|
|set\_sensitivity\_a\(\)|void|float32|Sets the value of sensitivity\_a. After calling this, sensitivity\_a\(\) will return value.|
|clear\_sensitivity\_a\(\)|void|void|Clears the value of sensitivity\_a. After calling this, sensitivity\_a\(\) will return 0.|
|sensitivity\_b\(\)|float32|void|Returns the current value of sensitivity\_b. If the sensitivity\_b is not set, returns 0.|
|set\_sensitivity\_b\(\)|void|float32|Sets the value of sensitivity\_b. After calling this, sensitivity\_b\(\) will return value.|
|clear\_sensitivity\_b\(\)|void|void|Clears the value of sensitivity\_b. After calling this, sensitivity\_b\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

