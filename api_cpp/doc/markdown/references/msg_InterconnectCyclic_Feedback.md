# Message Feedback

This page describes the C++ Kinova::Api::InterconnectCyclic::Feedback message.

## Overview / Purpose

Defines the feedback provided by an interconnect module

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|feedback\_id| [MessageId](msg_InterconnectCyclic_MessageId.md#)|MessageId|
|status\_flags|uint32|Status flags|
|jitter\_comm|uint32|Jitter from the communication \(in microsecond\)|
|position|float32|Position of the gripper fingers \(0-100%\)|
|velocity|float32|Velocity of the gripper fingers \(0-100%\)|
|force|float32|Force of the gripper fingers \(0-100%\)|
|imu\_acceleration\_x|float32|IMU Measured acceleration \(X-Axis\) of the interconnect \(in meters per second ^ squared\)|
|imu\_acceleration\_y|float32|IMU Measured acceleration \(Y-Axis\) of the interconnect \(in meters per second ^ squared\)|
|imu\_acceleration\_z|float32|IMU Measured acceleration \(Z-Axis\) of the interconnect \(in meters per second ^ squared\)|
|imu\_angular\_velocity\_x|float32|IMU Measured angular velocity \(X-Axis\) of the interconnect \(in degrees per second\)|
|imu\_angular\_velocity\_y|float32|IMU Measured angular velocity \(Y-Axis\) of the interconnect \(in degrees per second\)|
|imu\_angular\_velocity\_z|float32|IMU Measured angular velocity \(Z-Axis\) of the interconnect \(in degrees per second\)|
|voltage|float32|Voltage of the main board \(in Volt\)|
|temperature\_core|float32|Microcontroller temperature \(in degrees Celsius\)|
|fault\_bank\_a|uint32|Fault bank A \(see InterconnectConfig.SafetyIdentifier\)|
|fault\_bank\_b|uint32|Fault bank B \(see InterconnectConfig.SafetyIdentifier\)|
|warning\_bank\_a|uint32|Warning bank A \(see InterconnectConfig.SafetyIdentifier\)|
|warning\_bank\_b|uint32|Warning bank B \(see InterconnectConfig.SafetyIdentifier\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_feedback\_id\(\) const|bool|void|Returns true if feedback\_id is set.|
|feedback\_id\(\)|const [MessageId](msg_InterconnectCyclic_MessageId.md#)&|void|Returns the current value of feedback\_id. If feedback\_id is not set, returns a [MessageId](msg_InterconnectCyclic_MessageId.md#) with none of its fields set \(possibly feedback\_id::default\_instance\(\)\).|
|mutable\_feedback\_id\(\)| [MessageId](msg_InterconnectCyclic_MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](msg_InterconnectCyclic_MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](msg_InterconnectCyclic_MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](msg_InterconnectCyclic_MessageId.md#)\). After calling this, has\_feedback\_id\(\) will return true and feedback\_id\(\) will return a reference to the same instance of [MessageId](msg_InterconnectCyclic_MessageId.md#).|
|clear\_feedback\_id\(\)|void|void|Clears the value of the field. After calling this, has\_feedback\_id\(\) will return false and feedback\_id\(\) will return the default value.|
|set\_allocated\_feedback\_id\(\)|void| [MessageId](msg_InterconnectCyclic_MessageId.md#) \*|Sets the [MessageId](msg_InterconnectCyclic_MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](msg_InterconnectCyclic_MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](msg_InterconnectCyclic_MessageId.md#) object and has\_ [MessageId](msg_InterconnectCyclic_MessageId.md#)\(\) will return true. Otherwise, if the feedback\_id is NULL, the behavior is the same as calling clear\_feedback\_id\(\).|
|release\_feedback\_id\(\)| [MessageId](msg_InterconnectCyclic_MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](msg_InterconnectCyclic_MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](msg_InterconnectCyclic_MessageId.md#) object, has\_feedback\_id\(\) will return false, and feedback\_id\(\) will return the default value.|
|status\_flags\(\)|uint32|void|Returns the current value of status\_flags. If the status\_flags is not set, returns 0.|
|set\_status\_flags\(\)|void|uint32|Sets the value of status\_flags. After calling this, status\_flags\(\) will return value.|
|clear\_status\_flags\(\)|void|void|Clears the value of status\_flags. After calling this, status\_flags\(\) will return 0.|
|jitter\_comm\(\)|uint32|void|Returns the current value of jitter\_comm. If the jitter\_comm is not set, returns 0.|
|set\_jitter\_comm\(\)|void|uint32|Sets the value of jitter\_comm. After calling this, jitter\_comm\(\) will return value.|
|clear\_jitter\_comm\(\)|void|void|Clears the value of jitter\_comm. After calling this, jitter\_comm\(\) will return 0.|
|position\(\)|float32|void|Returns the current value of position. If the position is not set, returns 0.|
|set\_position\(\)|void|float32|Sets the value of position. After calling this, position\(\) will return value.|
|clear\_position\(\)|void|void|Clears the value of position. After calling this, position\(\) will return 0.|
|velocity\(\)|float32|void|Returns the current value of velocity. If the velocity is not set, returns 0.|
|set\_velocity\(\)|void|float32|Sets the value of velocity. After calling this, velocity\(\) will return value.|
|clear\_velocity\(\)|void|void|Clears the value of velocity. After calling this, velocity\(\) will return 0.|
|force\(\)|float32|void|Returns the current value of force. If the force is not set, returns 0.|
|set\_force\(\)|void|float32|Sets the value of force. After calling this, force\(\) will return value.|
|clear\_force\(\)|void|void|Clears the value of force. After calling this, force\(\) will return 0.|
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
|voltage\(\)|float32|void|Returns the current value of voltage. If the voltage is not set, returns 0.|
|set\_voltage\(\)|void|float32|Sets the value of voltage. After calling this, voltage\(\) will return value.|
|clear\_voltage\(\)|void|void|Clears the value of voltage. After calling this, voltage\(\) will return 0.|
|temperature\_core\(\)|float32|void|Returns the current value of temperature\_core. If the temperature\_core is not set, returns 0.|
|set\_temperature\_core\(\)|void|float32|Sets the value of temperature\_core. After calling this, temperature\_core\(\) will return value.|
|clear\_temperature\_core\(\)|void|void|Clears the value of temperature\_core. After calling this, temperature\_core\(\) will return 0.|
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

**Parent topic:** [InterconnectCyclic](../references/summary_InterconnectCyclic.md)

