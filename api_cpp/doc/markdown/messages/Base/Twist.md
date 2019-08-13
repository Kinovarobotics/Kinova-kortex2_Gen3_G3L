# class Twist

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|linear\_x|float32|Linear X velocity \(m/s or ratio between -1.0 and 1.0 if used with joystick command\)|
|linear\_y|float32|Linear Y velocity \(m/s or ratio between -1.0 and 1.0 if used with joystick command\)|
|linear\_z|float32|Linear Z velocity \(m/s or ratio between -1.0 and 1.0 if used with joystick command\)|
|angular\_x|float32|Angular X velocity \(deg/s or ratio between -1.0 and 1.0 if used with joystick command\)|
|angular\_y|float32|Angular Y velocity \(deg/s or ratio between -1.0 and 1.0 if used with joystick command\)|
|angular\_z|float32|Angular Z velocity \(deg/s or ratio between -1.0 and 1.0 if used with joystick command\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|linear\_x\(\)|float32|void|Returns the current value of linear\_x. If the linear\_x is not set, returns 0.|
|set\_linear\_x\(\)|void|float32|Sets the value of linear\_x. After calling this, linear\_x\(\) will return value.|
|clear\_linear\_x\(\)|void|void|Clears the value of linear\_x. After calling this, linear\_x\(\) will return 0.|
|linear\_y\(\)|float32|void|Returns the current value of linear\_y. If the linear\_y is not set, returns 0.|
|set\_linear\_y\(\)|void|float32|Sets the value of linear\_y. After calling this, linear\_y\(\) will return value.|
|clear\_linear\_y\(\)|void|void|Clears the value of linear\_y. After calling this, linear\_y\(\) will return 0.|
|linear\_z\(\)|float32|void|Returns the current value of linear\_z. If the linear\_z is not set, returns 0.|
|set\_linear\_z\(\)|void|float32|Sets the value of linear\_z. After calling this, linear\_z\(\) will return value.|
|clear\_linear\_z\(\)|void|void|Clears the value of linear\_z. After calling this, linear\_z\(\) will return 0.|
|angular\_x\(\)|float32|void|Returns the current value of angular\_x. If the angular\_x is not set, returns 0.|
|set\_angular\_x\(\)|void|float32|Sets the value of angular\_x. After calling this, angular\_x\(\) will return value.|
|clear\_angular\_x\(\)|void|void|Clears the value of angular\_x. After calling this, angular\_x\(\) will return 0.|
|angular\_y\(\)|float32|void|Returns the current value of angular\_y. If the angular\_y is not set, returns 0.|
|set\_angular\_y\(\)|void|float32|Sets the value of angular\_y. After calling this, angular\_y\(\) will return value.|
|clear\_angular\_y\(\)|void|void|Clears the value of angular\_y. After calling this, angular\_y\(\) will return 0.|
|angular\_z\(\)|float32|void|Returns the current value of angular\_z. If the angular\_z is not set, returns 0.|
|set\_angular\_z\(\)|void|float32|Sets the value of angular\_z. After calling this, angular\_z\(\) will return value.|
|clear\_angular\_z\(\)|void|void|Clears the value of angular\_z. After calling this, angular\_z\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

