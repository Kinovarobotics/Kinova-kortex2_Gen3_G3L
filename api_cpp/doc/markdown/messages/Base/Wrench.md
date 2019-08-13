# class Wrench

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|force\_x|float32|Linear X force \(Newtons or ratio between -1.0 and 1.0 if used with Joystick command\)|
|force\_y|float32|Linear Y force \(Newtons or ratio between -1.0 and 1.0 if used with Joystick command\)|
|force\_z|float32|Linear Z force \(Newtons or ratio between -1.0 and 1.0 if used with Joystick command\)|
|torque\_x|float32|Angular X torque \(Newton-meters or ratio between -1.0 and 1.0 if used with Joystick command\)|
|torque\_y|float32|Angular Y torque \(Newton-meters or ratio between -1.0 and 1.0 if used with Joystick command\)|
|torque\_z|float32|Angular Z torque \(Newton-meters or ratio between -1.0 and 1.0 if used with Joystick command\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|force\_x\(\)|float32|void|Returns the current value of force\_x. If the force\_x is not set, returns 0.|
|set\_force\_x\(\)|void|float32|Sets the value of force\_x. After calling this, force\_x\(\) will return value.|
|clear\_force\_x\(\)|void|void|Clears the value of force\_x. After calling this, force\_x\(\) will return 0.|
|force\_y\(\)|float32|void|Returns the current value of force\_y. If the force\_y is not set, returns 0.|
|set\_force\_y\(\)|void|float32|Sets the value of force\_y. After calling this, force\_y\(\) will return value.|
|clear\_force\_y\(\)|void|void|Clears the value of force\_y. After calling this, force\_y\(\) will return 0.|
|force\_z\(\)|float32|void|Returns the current value of force\_z. If the force\_z is not set, returns 0.|
|set\_force\_z\(\)|void|float32|Sets the value of force\_z. After calling this, force\_z\(\) will return value.|
|clear\_force\_z\(\)|void|void|Clears the value of force\_z. After calling this, force\_z\(\) will return 0.|
|torque\_x\(\)|float32|void|Returns the current value of torque\_x. If the torque\_x is not set, returns 0.|
|set\_torque\_x\(\)|void|float32|Sets the value of torque\_x. After calling this, torque\_x\(\) will return value.|
|clear\_torque\_x\(\)|void|void|Clears the value of torque\_x. After calling this, torque\_x\(\) will return 0.|
|torque\_y\(\)|float32|void|Returns the current value of torque\_y. If the torque\_y is not set, returns 0.|
|set\_torque\_y\(\)|void|float32|Sets the value of torque\_y. After calling this, torque\_y\(\) will return value.|
|clear\_torque\_y\(\)|void|void|Clears the value of torque\_y. After calling this, torque\_y\(\) will return 0.|
|torque\_z\(\)|float32|void|Returns the current value of torque\_z. If the torque\_z is not set, returns 0.|
|set\_torque\_z\(\)|void|float32|Sets the value of torque\_z. After calling this, torque\_z\(\) will return value.|
|clear\_torque\_z\(\)|void|void|Clears the value of torque\_z. After calling this, torque\_z\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

