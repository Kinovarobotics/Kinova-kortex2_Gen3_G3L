# class VectorDriveParameters

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|kpq|float32|Quadrature axis current proportional gain|
|kiq|float32|Quadrature axis current integral gain|
|kpd|float32|Direct axis current proportional gain|
|kid|float32|Direct axis current integral gain|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|kpq\(\)|float32|void|Returns the current value of kpq. If the kpq is not set, returns 0.|
|set\_kpq\(\)|void|float32|Sets the value of kpq. After calling this, kpq\(\) will return value.|
|clear\_kpq\(\)|void|void|Clears the value of kpq. After calling this, kpq\(\) will return 0.|
|kiq\(\)|float32|void|Returns the current value of kiq. If the kiq is not set, returns 0.|
|set\_kiq\(\)|void|float32|Sets the value of kiq. After calling this, kiq\(\) will return value.|
|clear\_kiq\(\)|void|void|Clears the value of kiq. After calling this, kiq\(\) will return 0.|
|kpd\(\)|float32|void|Returns the current value of kpd. If the kpd is not set, returns 0.|
|set\_kpd\(\)|void|float32|Sets the value of kpd. After calling this, kpd\(\) will return value.|
|clear\_kpd\(\)|void|void|Clears the value of kpd. After calling this, kpd\(\) will return 0.|
|kid\(\)|float32|void|Returns the current value of kid. If the kid is not set, returns 0.|
|set\_kid\(\)|void|float32|Sets the value of kid. After calling this, kid\(\) will return value.|
|clear\_kid\(\)|void|void|Clears the value of kid. After calling this, kid\(\) will return 0.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

