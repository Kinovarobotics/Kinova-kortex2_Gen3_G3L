# class OptionInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|The sensor \(color or depth\)|
|option|uint32|The option|
|supported|bool|Is the option supported by the chosen sensor?|
|read\_only|bool|Is the option read-only, or can it be changed?|
|minimum|float32|Minimum value for the option|
|maximum|float32|Maximum value for the option|
|step|float32|Step size for the option value \(if it takes on discrete values\)|
|default\_value|float32|Default value for the option|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|option\(\) const|uint32|void|Returns the current value of option. If the option is not set, returns 0.|
|set\_option\(\)|void|uint32|Sets the value of option. After calling this, option\(\) will return value.|
|clear\_option\(\)|void|void|Clears the value of option. After calling this, option\(\) will return the empty string/empty bytes.|
|supported\(\)|bool|void|Returns the current value of supported. If the supported is not set, returns 0.|
|set\_supported\(\)|void|bool|Sets the value of supported. After calling this, supported\(\) will return value.|
|clear\_supported\(\)|void|void|Clears the value of supported. After calling this, supported\(\) will return 0.|
|read\_only\(\)|bool|void|Returns the current value of read\_only. If the read\_only is not set, returns 0.|
|set\_read\_only\(\)|void|bool|Sets the value of read\_only. After calling this, read\_only\(\) will return value.|
|clear\_read\_only\(\)|void|void|Clears the value of read\_only. After calling this, read\_only\(\) will return 0.|
|minimum\(\)|float32|void|Returns the current value of minimum. If the minimum is not set, returns 0.|
|set\_minimum\(\)|void|float32|Sets the value of minimum. After calling this, minimum\(\) will return value.|
|clear\_minimum\(\)|void|void|Clears the value of minimum. After calling this, minimum\(\) will return 0.|
|maximum\(\)|float32|void|Returns the current value of maximum. If the maximum is not set, returns 0.|
|set\_maximum\(\)|void|float32|Sets the value of maximum. After calling this, maximum\(\) will return value.|
|clear\_maximum\(\)|void|void|Clears the value of maximum. After calling this, maximum\(\) will return 0.|
|step\(\)|float32|void|Returns the current value of step. If the step is not set, returns 0.|
|set\_step\(\)|void|float32|Sets the value of step. After calling this, step\(\) will return value.|
|clear\_step\(\)|void|void|Clears the value of step. After calling this, step\(\) will return 0.|
|default\_value\(\)|float32|void|Returns the current value of default\_value. If the default\_value is not set, returns 0.|
|set\_default\_value\(\)|void|float32|Sets the value of default\_value. After calling this, default\_value\(\) will return value.|
|clear\_default\_value\(\)|void|void|Clears the value of default\_value. After calling this, default\_value\(\) will return 0.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

