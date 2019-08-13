# class ConstrainedJointAngle

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_identifier|uint32|Joint identifier \(use device\_identifier\)|
|value|float32|Joint value \(in degrees\)|
|constraint| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)|Constraint to apply to the joint angle \(optional\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|joint\_identifier\(\)|uint32|void|Returns the current value of joint\_identifier. If the joint\_identifier is not set, returns 0.|
|set\_joint\_identifier\(\)|void|uint32|Sets the value of joint\_identifier. After calling this, joint\_identifier\(\) will return value.|
|clear\_joint\_identifier\(\)|void|void|Clears the value of joint\_identifier. After calling this, joint\_identifier\(\) will return 0.|
|value\(\)|float32|void|Returns the current value of value. If the value is not set, returns 0.|
|set\_value\(\)|void|float32|Sets the value of value. After calling this, value\(\) will return value.|
|clear\_value\(\)|void|void|Clears the value of value. After calling this, value\(\) will return 0.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [JointTrajectoryConstraint](JointTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) \*|Sets the [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object and has\_ [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

