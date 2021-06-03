# class GpioCommand

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|port\_identifier|uint32|Gpio port identifier \(0 == base expansion port\)|
|pin\_identifier|uint32|Gpio pin identifier|
|action|uint32|Action to perform on gpio|
|period|uint32|Period, in ms, of GPIO action \(applicable only for pulse commands\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|port\_identifier\(\)|uint32|void|Returns the current value of port\_identifier. If the port\_identifier is not set, returns 0.|
|set\_port\_identifier\(\)|void|uint32|Sets the value of port\_identifier. After calling this, port\_identifier\(\) will return value.|
|clear\_port\_identifier\(\)|void|void|Clears the value of port\_identifier. After calling this, port\_identifier\(\) will return 0.|
|pin\_identifier\(\)|uint32|void|Returns the current value of pin\_identifier. If the pin\_identifier is not set, returns 0.|
|set\_pin\_identifier\(\)|void|uint32|Sets the value of pin\_identifier. After calling this, pin\_identifier\(\) will return value.|
|clear\_pin\_identifier\(\)|void|void|Clears the value of pin\_identifier. After calling this, pin\_identifier\(\) will return 0.|
|action\(\) const|uint32|void|Returns the current value of action. If the action is not set, returns 0.|
|set\_action\(\)|void|uint32|Sets the value of action. After calling this, action\(\) will return value.|
|clear\_action\(\)|void|void|Clears the value of action. After calling this, action\(\) will return the empty string/empty bytes.|
|period\(\)|uint32|void|Returns the current value of period. If the period is not set, returns 0.|
|set\_period\(\)|void|uint32|Sets the value of period. After calling this, period\(\) will return value.|
|clear\_period\(\)|void|void|Clears the value of period. After calling this, period\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

