# class Feedback

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|feedback\_id| [MessageId](MessageId.md#)|MessageId|
|status\_flags|uint32|Status flags|
|jitter\_comm|uint32|Jitter from the communication \(in microseconds\)|
|imu\_acceleration\_x|float32|IMU Measured acceleration \(X-Axis\) of the interface module \(in meters per second ^ squared\)|
|imu\_acceleration\_y|float32|IMU Measured acceleration \(Y-Axis\) of the interface module \(in meters per second ^ squared\)|
|imu\_acceleration\_z|float32|IMU Measured acceleration \(Z-Axis\) of the interface module \(in meters per second ^ squared\)|
|imu\_angular\_velocity\_x|float32|IMU Measured angular velocity \(X-Axis\) of the interface module \(in degrees per second\)|
|imu\_angular\_velocity\_y|float32|IMU Measured angular velocity \(Y-Axis\) of the interface module \(in degrees per second\)|
|imu\_angular\_velocity\_z|float32|IMU Measured angular velocity \(Z-Axis\) of the interface module \(in degrees per second\)|
|voltage|float32|Voltage of the main board \(in Volt\)|
|temperature\_core|float32|Microcontroller temperature \(in degrees Celsius\)|
|fault\_bank\_a|uint32|Fault bank A \(see InterconnectConfig.SafetyIdentifier\)|
|fault\_bank\_b|uint32|Fault bank B \(see InterconnectConfig.SafetyIdentifier\)|
|warning\_bank\_a|uint32|Warning bank A \(see InterconnectConfig.SafetyIdentifier\)|
|warning\_bank\_b|uint32|Warning bank B \(see InterconnectConfig.SafetyIdentifier\)|
|gripper\_feedback|oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#)|Gripper model tool feedback|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_feedback\_id\(\) const|bool|void|Returns true if feedback\_id is set.|
|feedback\_id\(\)|const [MessageId](MessageId.md#)&|void|Returns the current value of feedback\_id. If feedback\_id is not set, returns a [MessageId](MessageId.md#) with none of its fields set \(possibly feedback\_id::default\_instance\(\)\).|
|mutable\_feedback\_id\(\)| [MessageId](MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](MessageId.md#)\). After calling this, has\_feedback\_id\(\) will return true and feedback\_id\(\) will return a reference to the same instance of [MessageId](MessageId.md#).|
|clear\_feedback\_id\(\)|void|void|Clears the value of the field. After calling this, has\_feedback\_id\(\) will return false and feedback\_id\(\) will return the default value.|
|set\_allocated\_feedback\_id\(\)|void| [MessageId](MessageId.md#) \*|Sets the [MessageId](MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](MessageId.md#) object and has\_ [MessageId](MessageId.md#)\(\) will return true. Otherwise, if the feedback\_id is NULL, the behavior is the same as calling clear\_feedback\_id\(\).|
|release\_feedback\_id\(\)| [MessageId](MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](MessageId.md#) object, has\_feedback\_id\(\) will return false, and feedback\_id\(\) will return the default value.|
|status\_flags\(\)|uint32|void|Returns the current value of status\_flags. If the status\_flags is not set, returns 0.|
|set\_status\_flags\(\)|void|uint32|Sets the value of status\_flags. After calling this, status\_flags\(\) will return value.|
|clear\_status\_flags\(\)|void|void|Clears the value of status\_flags. After calling this, status\_flags\(\) will return 0.|
|jitter\_comm\(\)|uint32|void|Returns the current value of jitter\_comm. If the jitter\_comm is not set, returns 0.|
|set\_jitter\_comm\(\)|void|uint32|Sets the value of jitter\_comm. After calling this, jitter\_comm\(\) will return value.|
|clear\_jitter\_comm\(\)|void|void|Clears the value of jitter\_comm. After calling this, jitter\_comm\(\) will return 0.|
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
|has\_gripper\_feedback\(\) const|void|void|Returns the current value of the field if oneof case is kGripper\_feedback. Otherwise, returns oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#)::default\_instance\(\)|
|gripper\_feedback\(\) const|const oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#)&|void|Returns the current value of the field if oneof case is kGripper\_feedback|
|mutable\_gripper\_feedback\(\)|oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#)\*|void|If any other oneof field in the same oneof is set, calls clear\_tool\_feedback\(\). Sets the oneof case to kGripper\_feedback and returns a pointer to the mutable oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#) object that stores the field's value. If the oneof case was not kGripper\_feedback prior to the call, then the returned oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#)\). After calling this, has\_gripper\_feedback\(\) will return true, gripper\_feedback\(\) will return a reference to the same instance of oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#) and tool\_feedback\_case\(\) will return kGripper\_feedback|
|clear\_gripper\_feedback\(\)|void|void|Nothing will be changed if the oneof case is not kGripper\_feedback. If the oneof case equals kGripper\_feedback, frees the field and clears the oneof case. has\_gripper\_feedback\(\) will return false, gripper\_feedback\(\) will return the default value and tool\_feedback\_case\(\) will return TOOL\_FEEDBACK\_NOT\_SET.|
|set\_allocated\_gripper\_feedback\(\)|void|oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#)\*|Calls clear\_tool\_feedback\(\). If the oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#) pointer is not NULL: Sets the oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#) object to the field and sets the oneof case to kGripper\_feedback. The message takes ownership of the allocated oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#) object, has\_gripper\_feedback\(\) will return true and tool\_feedback\_case\(\) will return kGripper\_feedback. If the pointer is NULL, has\_gripper\_feedback\(\) will return false and tool\_feedback\_case\(\) will return TOOL\_FEEDBACK\_NOT\_SET. \(The behavior is like calling clear\_tool\_feedback\(\)\)|
|release\_gripper\_feedback\(\)|oneof:tool\_feedback [Feedback](../GripperCyclic/Feedback.md#)\*|void|Returns NULL if oneof case is not kGripper\_feedback. If the oneof case is kGripper\_feedback, clears the oneof case, releases the ownership of the field and returns the pointer of the tool\_feedback object. After calling this, caller takes the ownership of the allocated tool\_feedback object, has\_gripper\_feedback\(\) will return false, gripper\_feedback\(\) will return the default value and tool\_feedback\_case\(\) will return TOOL\_FEEDBACK\_NOT\_SET.|

**Parent topic:** [InterconnectCyclic \(C++\)](../../summary_pages/InterconnectCyclic.md)

