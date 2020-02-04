# class BaseFeedback

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|active\_state\_connection\_identifier|uint32|Connection identifier of the last processed command which triggered an arm state change|
|active\_state|uint32|Active state of the arm|
|arm\_voltage|float32|Arm voltage \(in Volts\)|
|arm\_current|float32|Arm current \(in Amperes\)|
|temperature\_cpu|float32|CPU temperature \(in degree Celsius\)|
|temperature\_ambient|float32|Ambient temperature \(in degree Celsius\)|
|imu\_acceleration\_x|float32|IMU Measured acceleration \(X-Axis\) of the base \(in meters per second squared\)|
|imu\_acceleration\_y|float32|IMU Measured acceleration \(Y-Axis\) of the base \(in meters per second squared\)|
|imu\_acceleration\_z|float32|IMU Measured acceleration \(Z-Axis\) of the base \(in meters per second squared\)|
|imu\_angular\_velocity\_x|float32|IMU Measured angular velocity \(X-Axis\) of the base \(in degrees per second\)|
|imu\_angular\_velocity\_y|float32|IMU Measured angular velocity \(Y-Axis\) of the base \(in degrees per second\)|
|imu\_angular\_velocity\_z|float32|IMU Measured angular velocity \(Z-Axis\) of the base \(in degrees per second\)|
|tool\_pose\_x|float32|Measured Cartesian position \(X-Axis\) of the tool \(in meters\)|
|tool\_pose\_y|float32|Measured Cartesian position \(Y-Axis\) of the tool \(in meters\)|
|tool\_pose\_z|float32|Measured Cartesian position \(Z-Axis\) of the tool \(in meters\)|
|tool\_pose\_theta\_x|float32|Measured Cartesian orientation \(X-Axis\) of the tool \(in degrees\)|
|tool\_pose\_theta\_y|float32|Measured Cartesian orientation \(Y-Axis\) of the tool \(in degrees\)|
|tool\_pose\_theta\_z|float32|Measured Cartesian orientation \(Z-Axis\) of the tool \(in degrees\)|
|tool\_twist\_linear\_x|float32|Measured Cartesian linear velocity \(X-Axis\) of the tool \(in meters per second\)|
|tool\_twist\_linear\_y|float32|Measured Cartesian linear velocity \(Y-Axis\) of the tool \(in meters per second\)|
|tool\_twist\_linear\_z|float32|Measured Cartesian linear velocity \(Z-Axis\) of the tool \(in meters per second\)|
|tool\_twist\_angular\_x|float32|Measured Cartesian angular velocity \(X-Axis\) of the tool \(in degrees per second\)|
|tool\_twist\_angular\_y|float32|Measured Cartesian angular velocity \(Y-Axis\) of the tool \(in degrees per second\)|
|tool\_twist\_angular\_z|float32|Measured Cartesian angular velocity \(Z-Axis\) of the tool \(in degrees per second\)|
|tool\_external\_wrench\_force\_x|float32|Computed force in X-Axis from external wrench \(in Newton\)|
|tool\_external\_wrench\_force\_y|float32|Computed force in Y-Axis from external wrench \(in Newton\)|
|tool\_external\_wrench\_force\_z|float32|Computed force in Z-Axis from external wrench \(in Newton\)|
|tool\_external\_wrench\_torque\_x|float32|Computed torque about X-axis from external wrench \(in Newton-meters\)|
|tool\_external\_wrench\_torque\_y|float32|Computed torque about Y-axis from external wrench \(in Newton-meters\)|
|tool\_external\_wrench\_torque\_z|float32|Computed torque about Z-axis from external wrench \(in Newton-meters\)|
|fault\_bank\_a|uint32|The arm fault flags bank A \(0 if no fault\) see Base.SafetyIdentifier|
|fault\_bank\_b|uint32|The arm fault flags bank B \(0 if no fault\) see Base.SafetyIdentifier|
|warning\_bank\_a|uint32|The arm warning flags bank A \(0 if no warning\) see Base.SafetyIdentifier|
|warning\_bank\_b|uint32|The arm warning flags bank B \(0 if no warning\) see Base.SafetyIdentifier|
|commanded\_tool\_pose\_x|float32|Commanded Cartesian position \(X-Axis\) of the tool \(in meters\)|
|commanded\_tool\_pose\_y|float32|Commanded Cartesian position \(Y-Axis\) of the tool \(in meters\)|
|commanded\_tool\_pose\_z|float32|Commanded Cartesian position \(Z-Axis\) of the tool \(in meters\)|
|commanded\_tool\_pose\_theta\_x|float32|Commanded Cartesian orientation \(X-Axis\) of the tool \(in degrees\)|
|commanded\_tool\_pose\_theta\_y|float32|Commanded Cartesian orientation \(Y-Axis\) of the tool \(in degrees\)|
|commanded\_tool\_pose\_theta\_z|float32|Commanded Cartesian orientation \(Z-Axis\) of the tool \(in degrees\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|active\_state\_connection\_identifier\(\)|uint32|void|Returns the current value of active\_state\_connection\_identifier. If the active\_state\_connection\_identifier is not set, returns 0.|
|set\_active\_state\_connection\_identifier\(\)|void|uint32|Sets the value of active\_state\_connection\_identifier. After calling this, active\_state\_connection\_identifier\(\) will return value.|
|clear\_active\_state\_connection\_identifier\(\)|void|void|Clears the value of active\_state\_connection\_identifier. After calling this, active\_state\_connection\_identifier\(\) will return 0.|
|active\_state\(\) const|uint32|void|Returns the current value of active\_state. If the active\_state is not set, returns 0.|
|set\_active\_state\(\)|void|uint32|Sets the value of active\_state. After calling this, active\_state\(\) will return value.|
|clear\_active\_state\(\)|void|void|Clears the value of active\_state. After calling this, active\_state\(\) will return the empty string/empty bytes.|
|arm\_voltage\(\)|float32|void|Returns the current value of arm\_voltage. If the arm\_voltage is not set, returns 0.|
|set\_arm\_voltage\(\)|void|float32|Sets the value of arm\_voltage. After calling this, arm\_voltage\(\) will return value.|
|clear\_arm\_voltage\(\)|void|void|Clears the value of arm\_voltage. After calling this, arm\_voltage\(\) will return 0.|
|arm\_current\(\)|float32|void|Returns the current value of arm\_current. If the arm\_current is not set, returns 0.|
|set\_arm\_current\(\)|void|float32|Sets the value of arm\_current. After calling this, arm\_current\(\) will return value.|
|clear\_arm\_current\(\)|void|void|Clears the value of arm\_current. After calling this, arm\_current\(\) will return 0.|
|temperature\_cpu\(\)|float32|void|Returns the current value of temperature\_cpu. If the temperature\_cpu is not set, returns 0.|
|set\_temperature\_cpu\(\)|void|float32|Sets the value of temperature\_cpu. After calling this, temperature\_cpu\(\) will return value.|
|clear\_temperature\_cpu\(\)|void|void|Clears the value of temperature\_cpu. After calling this, temperature\_cpu\(\) will return 0.|
|temperature\_ambient\(\)|float32|void|Returns the current value of temperature\_ambient. If the temperature\_ambient is not set, returns 0.|
|set\_temperature\_ambient\(\)|void|float32|Sets the value of temperature\_ambient. After calling this, temperature\_ambient\(\) will return value.|
|clear\_temperature\_ambient\(\)|void|void|Clears the value of temperature\_ambient. After calling this, temperature\_ambient\(\) will return 0.|
|imu\_acceleration\_x\(\)|float32|void|Returns the current value of imu\_acceleration\_x. If the imu\_acceleration\_x is not set, returns 0.|
|set\_imu\_acceleration\_x\(\)|void|float32|Sets the value of imu\_acceleration\_x. After calling this, imu\_acceleration\_x\(\) will return value.|
|clear\_imu\_acceleration\_x\(\)|void|void|Clears the value of imu\_acceleration\_x. After calling this, imu\_acceleration\_x\(\) will return 0.|
|imu\_acceleration\_y\(\)|float32|void|Returns the current value of imu\_acceleration\_y. If the imu\_acceleration\_y is not set, returns 0.|
|set\_imu\_acceleration\_y\(\)|void|float32|Sets the value of imu\_acceleration\_y. After calling this, imu\_acceleration\_y\(\) will return value.|
|clear\_imu\_acceleration\_y\(\)|void|void|Clears the value of imu\_acceleration\_y. After calling this, imu\_acceleration\_y\(\) will return 0.|
|imu\_acceleration\_z\(\)|float32|void|Returns the current value of imu\_acceleration\_z. If the imu\_acceleration\_z is not set, returns 0.|
|set\_imu\_acceleration\_z\(\)|void|float32|Sets the value of imu\_acceleration\_z. After calling this, imu\_acceleration\_z\(\) will return value.|
|clear\_imu\_acceleration\_z\(\)|void|void|Clears the value of imu\_acceleration\_z. After calling this, imu\_acceleration\_z\(\) will return 0.|
|imu\_angular\_velocity\_x\(\)|float32|void|Returns the current value of imu\_angular\_velocity\_x. If the imu\_angular\_velocity\_x is not set, returns 0.|
|set\_imu\_angular\_velocity\_x\(\)|void|float32|Sets the value of imu\_angular\_velocity\_x. After calling this, imu\_angular\_velocity\_x\(\) will return value.|
|clear\_imu\_angular\_velocity\_x\(\)|void|void|Clears the value of imu\_angular\_velocity\_x. After calling this, imu\_angular\_velocity\_x\(\) will return 0.|
|imu\_angular\_velocity\_y\(\)|float32|void|Returns the current value of imu\_angular\_velocity\_y. If the imu\_angular\_velocity\_y is not set, returns 0.|
|set\_imu\_angular\_velocity\_y\(\)|void|float32|Sets the value of imu\_angular\_velocity\_y. After calling this, imu\_angular\_velocity\_y\(\) will return value.|
|clear\_imu\_angular\_velocity\_y\(\)|void|void|Clears the value of imu\_angular\_velocity\_y. After calling this, imu\_angular\_velocity\_y\(\) will return 0.|
|imu\_angular\_velocity\_z\(\)|float32|void|Returns the current value of imu\_angular\_velocity\_z. If the imu\_angular\_velocity\_z is not set, returns 0.|
|set\_imu\_angular\_velocity\_z\(\)|void|float32|Sets the value of imu\_angular\_velocity\_z. After calling this, imu\_angular\_velocity\_z\(\) will return value.|
|clear\_imu\_angular\_velocity\_z\(\)|void|void|Clears the value of imu\_angular\_velocity\_z. After calling this, imu\_angular\_velocity\_z\(\) will return 0.|
|tool\_pose\_x\(\)|float32|void|Returns the current value of tool\_pose\_x. If the tool\_pose\_x is not set, returns 0.|
|set\_tool\_pose\_x\(\)|void|float32|Sets the value of tool\_pose\_x. After calling this, tool\_pose\_x\(\) will return value.|
|clear\_tool\_pose\_x\(\)|void|void|Clears the value of tool\_pose\_x. After calling this, tool\_pose\_x\(\) will return 0.|
|tool\_pose\_y\(\)|float32|void|Returns the current value of tool\_pose\_y. If the tool\_pose\_y is not set, returns 0.|
|set\_tool\_pose\_y\(\)|void|float32|Sets the value of tool\_pose\_y. After calling this, tool\_pose\_y\(\) will return value.|
|clear\_tool\_pose\_y\(\)|void|void|Clears the value of tool\_pose\_y. After calling this, tool\_pose\_y\(\) will return 0.|
|tool\_pose\_z\(\)|float32|void|Returns the current value of tool\_pose\_z. If the tool\_pose\_z is not set, returns 0.|
|set\_tool\_pose\_z\(\)|void|float32|Sets the value of tool\_pose\_z. After calling this, tool\_pose\_z\(\) will return value.|
|clear\_tool\_pose\_z\(\)|void|void|Clears the value of tool\_pose\_z. After calling this, tool\_pose\_z\(\) will return 0.|
|tool\_pose\_theta\_x\(\)|float32|void|Returns the current value of tool\_pose\_theta\_x. If the tool\_pose\_theta\_x is not set, returns 0.|
|set\_tool\_pose\_theta\_x\(\)|void|float32|Sets the value of tool\_pose\_theta\_x. After calling this, tool\_pose\_theta\_x\(\) will return value.|
|clear\_tool\_pose\_theta\_x\(\)|void|void|Clears the value of tool\_pose\_theta\_x. After calling this, tool\_pose\_theta\_x\(\) will return 0.|
|tool\_pose\_theta\_y\(\)|float32|void|Returns the current value of tool\_pose\_theta\_y. If the tool\_pose\_theta\_y is not set, returns 0.|
|set\_tool\_pose\_theta\_y\(\)|void|float32|Sets the value of tool\_pose\_theta\_y. After calling this, tool\_pose\_theta\_y\(\) will return value.|
|clear\_tool\_pose\_theta\_y\(\)|void|void|Clears the value of tool\_pose\_theta\_y. After calling this, tool\_pose\_theta\_y\(\) will return 0.|
|tool\_pose\_theta\_z\(\)|float32|void|Returns the current value of tool\_pose\_theta\_z. If the tool\_pose\_theta\_z is not set, returns 0.|
|set\_tool\_pose\_theta\_z\(\)|void|float32|Sets the value of tool\_pose\_theta\_z. After calling this, tool\_pose\_theta\_z\(\) will return value.|
|clear\_tool\_pose\_theta\_z\(\)|void|void|Clears the value of tool\_pose\_theta\_z. After calling this, tool\_pose\_theta\_z\(\) will return 0.|
|tool\_twist\_linear\_x\(\)|float32|void|Returns the current value of tool\_twist\_linear\_x. If the tool\_twist\_linear\_x is not set, returns 0.|
|set\_tool\_twist\_linear\_x\(\)|void|float32|Sets the value of tool\_twist\_linear\_x. After calling this, tool\_twist\_linear\_x\(\) will return value.|
|clear\_tool\_twist\_linear\_x\(\)|void|void|Clears the value of tool\_twist\_linear\_x. After calling this, tool\_twist\_linear\_x\(\) will return 0.|
|tool\_twist\_linear\_y\(\)|float32|void|Returns the current value of tool\_twist\_linear\_y. If the tool\_twist\_linear\_y is not set, returns 0.|
|set\_tool\_twist\_linear\_y\(\)|void|float32|Sets the value of tool\_twist\_linear\_y. After calling this, tool\_twist\_linear\_y\(\) will return value.|
|clear\_tool\_twist\_linear\_y\(\)|void|void|Clears the value of tool\_twist\_linear\_y. After calling this, tool\_twist\_linear\_y\(\) will return 0.|
|tool\_twist\_linear\_z\(\)|float32|void|Returns the current value of tool\_twist\_linear\_z. If the tool\_twist\_linear\_z is not set, returns 0.|
|set\_tool\_twist\_linear\_z\(\)|void|float32|Sets the value of tool\_twist\_linear\_z. After calling this, tool\_twist\_linear\_z\(\) will return value.|
|clear\_tool\_twist\_linear\_z\(\)|void|void|Clears the value of tool\_twist\_linear\_z. After calling this, tool\_twist\_linear\_z\(\) will return 0.|
|tool\_twist\_angular\_x\(\)|float32|void|Returns the current value of tool\_twist\_angular\_x. If the tool\_twist\_angular\_x is not set, returns 0.|
|set\_tool\_twist\_angular\_x\(\)|void|float32|Sets the value of tool\_twist\_angular\_x. After calling this, tool\_twist\_angular\_x\(\) will return value.|
|clear\_tool\_twist\_angular\_x\(\)|void|void|Clears the value of tool\_twist\_angular\_x. After calling this, tool\_twist\_angular\_x\(\) will return 0.|
|tool\_twist\_angular\_y\(\)|float32|void|Returns the current value of tool\_twist\_angular\_y. If the tool\_twist\_angular\_y is not set, returns 0.|
|set\_tool\_twist\_angular\_y\(\)|void|float32|Sets the value of tool\_twist\_angular\_y. After calling this, tool\_twist\_angular\_y\(\) will return value.|
|clear\_tool\_twist\_angular\_y\(\)|void|void|Clears the value of tool\_twist\_angular\_y. After calling this, tool\_twist\_angular\_y\(\) will return 0.|
|tool\_twist\_angular\_z\(\)|float32|void|Returns the current value of tool\_twist\_angular\_z. If the tool\_twist\_angular\_z is not set, returns 0.|
|set\_tool\_twist\_angular\_z\(\)|void|float32|Sets the value of tool\_twist\_angular\_z. After calling this, tool\_twist\_angular\_z\(\) will return value.|
|clear\_tool\_twist\_angular\_z\(\)|void|void|Clears the value of tool\_twist\_angular\_z. After calling this, tool\_twist\_angular\_z\(\) will return 0.|
|tool\_external\_wrench\_force\_x\(\)|float32|void|Returns the current value of tool\_external\_wrench\_force\_x. If the tool\_external\_wrench\_force\_x is not set, returns 0.|
|set\_tool\_external\_wrench\_force\_x\(\)|void|float32|Sets the value of tool\_external\_wrench\_force\_x. After calling this, tool\_external\_wrench\_force\_x\(\) will return value.|
|clear\_tool\_external\_wrench\_force\_x\(\)|void|void|Clears the value of tool\_external\_wrench\_force\_x. After calling this, tool\_external\_wrench\_force\_x\(\) will return 0.|
|tool\_external\_wrench\_force\_y\(\)|float32|void|Returns the current value of tool\_external\_wrench\_force\_y. If the tool\_external\_wrench\_force\_y is not set, returns 0.|
|set\_tool\_external\_wrench\_force\_y\(\)|void|float32|Sets the value of tool\_external\_wrench\_force\_y. After calling this, tool\_external\_wrench\_force\_y\(\) will return value.|
|clear\_tool\_external\_wrench\_force\_y\(\)|void|void|Clears the value of tool\_external\_wrench\_force\_y. After calling this, tool\_external\_wrench\_force\_y\(\) will return 0.|
|tool\_external\_wrench\_force\_z\(\)|float32|void|Returns the current value of tool\_external\_wrench\_force\_z. If the tool\_external\_wrench\_force\_z is not set, returns 0.|
|set\_tool\_external\_wrench\_force\_z\(\)|void|float32|Sets the value of tool\_external\_wrench\_force\_z. After calling this, tool\_external\_wrench\_force\_z\(\) will return value.|
|clear\_tool\_external\_wrench\_force\_z\(\)|void|void|Clears the value of tool\_external\_wrench\_force\_z. After calling this, tool\_external\_wrench\_force\_z\(\) will return 0.|
|tool\_external\_wrench\_torque\_x\(\)|float32|void|Returns the current value of tool\_external\_wrench\_torque\_x. If the tool\_external\_wrench\_torque\_x is not set, returns 0.|
|set\_tool\_external\_wrench\_torque\_x\(\)|void|float32|Sets the value of tool\_external\_wrench\_torque\_x. After calling this, tool\_external\_wrench\_torque\_x\(\) will return value.|
|clear\_tool\_external\_wrench\_torque\_x\(\)|void|void|Clears the value of tool\_external\_wrench\_torque\_x. After calling this, tool\_external\_wrench\_torque\_x\(\) will return 0.|
|tool\_external\_wrench\_torque\_y\(\)|float32|void|Returns the current value of tool\_external\_wrench\_torque\_y. If the tool\_external\_wrench\_torque\_y is not set, returns 0.|
|set\_tool\_external\_wrench\_torque\_y\(\)|void|float32|Sets the value of tool\_external\_wrench\_torque\_y. After calling this, tool\_external\_wrench\_torque\_y\(\) will return value.|
|clear\_tool\_external\_wrench\_torque\_y\(\)|void|void|Clears the value of tool\_external\_wrench\_torque\_y. After calling this, tool\_external\_wrench\_torque\_y\(\) will return 0.|
|tool\_external\_wrench\_torque\_z\(\)|float32|void|Returns the current value of tool\_external\_wrench\_torque\_z. If the tool\_external\_wrench\_torque\_z is not set, returns 0.|
|set\_tool\_external\_wrench\_torque\_z\(\)|void|float32|Sets the value of tool\_external\_wrench\_torque\_z. After calling this, tool\_external\_wrench\_torque\_z\(\) will return value.|
|clear\_tool\_external\_wrench\_torque\_z\(\)|void|void|Clears the value of tool\_external\_wrench\_torque\_z. After calling this, tool\_external\_wrench\_torque\_z\(\) will return 0.|
|fault\_bank\_a\(\)|uint32|void|Returns the current value of fault\_bank\_a. If the fault\_bank\_a is not set, returns 0.|
|set\_fault\_bank\_a\(\)|void|uint32|Sets the value of fault\_bank\_a. After calling this, fault\_bank\_a\(\) will return value.|
|clear\_fault\_bank\_a\(\)|void|void|Clears the value of fault\_bank\_a. After calling this, fault\_bank\_a\(\) will return 0.|
|fault\_bank\_b\(\)|uint32|void|Returns the current value of fault\_bank\_b. If the fault\_bank\_b is not set, returns 0.|
|set\_fault\_bank\_b\(\)|void|uint32|Sets the value of fault\_bank\_b. After calling this, fault\_bank\_b\(\) will return value.|
|clear\_fault\_bank\_b\(\)|void|void|Clears the value of fault\_bank\_b. After calling this, fault\_bank\_b\(\) will return 0.|
|warning\_bank\_a\(\)|uint32|void|Returns the current value of warning\_bank\_a. If the warning\_bank\_a is not set, returns 0.|
|set\_warning\_bank\_a\(\)|void|uint32|Sets the value of warning\_bank\_a. After calling this, warning\_bank\_a\(\) will return value.|
|clear\_warning\_bank\_a\(\)|void|void|Clears the value of warning\_bank\_a. After calling this, warning\_bank\_a\(\) will return 0.|
|warning\_bank\_b\(\)|uint32|void|Returns the current value of warning\_bank\_b. If the warning\_bank\_b is not set, returns 0.|
|set\_warning\_bank\_b\(\)|void|uint32|Sets the value of warning\_bank\_b. After calling this, warning\_bank\_b\(\) will return value.|
|clear\_warning\_bank\_b\(\)|void|void|Clears the value of warning\_bank\_b. After calling this, warning\_bank\_b\(\) will return 0.|
|commanded\_tool\_pose\_x\(\)|float32|void|Returns the current value of commanded\_tool\_pose\_x. If the commanded\_tool\_pose\_x is not set, returns 0.|
|set\_commanded\_tool\_pose\_x\(\)|void|float32|Sets the value of commanded\_tool\_pose\_x. After calling this, commanded\_tool\_pose\_x\(\) will return value.|
|clear\_commanded\_tool\_pose\_x\(\)|void|void|Clears the value of commanded\_tool\_pose\_x. After calling this, commanded\_tool\_pose\_x\(\) will return 0.|
|commanded\_tool\_pose\_y\(\)|float32|void|Returns the current value of commanded\_tool\_pose\_y. If the commanded\_tool\_pose\_y is not set, returns 0.|
|set\_commanded\_tool\_pose\_y\(\)|void|float32|Sets the value of commanded\_tool\_pose\_y. After calling this, commanded\_tool\_pose\_y\(\) will return value.|
|clear\_commanded\_tool\_pose\_y\(\)|void|void|Clears the value of commanded\_tool\_pose\_y. After calling this, commanded\_tool\_pose\_y\(\) will return 0.|
|commanded\_tool\_pose\_z\(\)|float32|void|Returns the current value of commanded\_tool\_pose\_z. If the commanded\_tool\_pose\_z is not set, returns 0.|
|set\_commanded\_tool\_pose\_z\(\)|void|float32|Sets the value of commanded\_tool\_pose\_z. After calling this, commanded\_tool\_pose\_z\(\) will return value.|
|clear\_commanded\_tool\_pose\_z\(\)|void|void|Clears the value of commanded\_tool\_pose\_z. After calling this, commanded\_tool\_pose\_z\(\) will return 0.|
|commanded\_tool\_pose\_theta\_x\(\)|float32|void|Returns the current value of commanded\_tool\_pose\_theta\_x. If the commanded\_tool\_pose\_theta\_x is not set, returns 0.|
|set\_commanded\_tool\_pose\_theta\_x\(\)|void|float32|Sets the value of commanded\_tool\_pose\_theta\_x. After calling this, commanded\_tool\_pose\_theta\_x\(\) will return value.|
|clear\_commanded\_tool\_pose\_theta\_x\(\)|void|void|Clears the value of commanded\_tool\_pose\_theta\_x. After calling this, commanded\_tool\_pose\_theta\_x\(\) will return 0.|
|commanded\_tool\_pose\_theta\_y\(\)|float32|void|Returns the current value of commanded\_tool\_pose\_theta\_y. If the commanded\_tool\_pose\_theta\_y is not set, returns 0.|
|set\_commanded\_tool\_pose\_theta\_y\(\)|void|float32|Sets the value of commanded\_tool\_pose\_theta\_y. After calling this, commanded\_tool\_pose\_theta\_y\(\) will return value.|
|clear\_commanded\_tool\_pose\_theta\_y\(\)|void|void|Clears the value of commanded\_tool\_pose\_theta\_y. After calling this, commanded\_tool\_pose\_theta\_y\(\) will return 0.|
|commanded\_tool\_pose\_theta\_z\(\)|float32|void|Returns the current value of commanded\_tool\_pose\_theta\_z. If the commanded\_tool\_pose\_theta\_z is not set, returns 0.|
|set\_commanded\_tool\_pose\_theta\_z\(\)|void|float32|Sets the value of commanded\_tool\_pose\_theta\_z. After calling this, commanded\_tool\_pose\_theta\_z\(\) will return value.|
|clear\_commanded\_tool\_pose\_theta\_z\(\)|void|void|Clears the value of commanded\_tool\_pose\_theta\_z. After calling this, commanded\_tool\_pose\_theta\_z\(\) will return 0.|

**Parent topic:** [BaseCyclic \(C++\)](../../summary_pages/BaseCyclic.md)

