# class VisionNotification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event|uint32|Vision event|
|sensor|uint32|The sensor that caused the notification \(if applicable\)|
|option|uint32|The option that caused the notification \(if applicable\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|event\(\) const|uint32|void|Returns the current value of event. If the event is not set, returns 0.|
|set\_event\(\)|void|uint32|Sets the value of event. After calling this, event\(\) will return value.|
|clear\_event\(\)|void|void|Clears the value of event. After calling this, event\(\) will return the empty string/empty bytes.|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|option\(\) const|uint32|void|Returns the current value of option. If the option is not set, returns 0.|
|set\_option\(\)|void|uint32|Sets the value of option. After calling this, option\(\) will return value.|
|clear\_option\(\)|void|void|Clears the value of option. After calling this, option\(\) will return the empty string/empty bytes.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

