# class ConstrainedJointAngles

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_angles| [JointAngles](JointAngles.md#)|Joint angles values|
|constraint| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)|Constraint to apply to all the joint angles \(optional\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_joint\_angles\(\) const|bool|void|Returns true if joint\_angles is set.|
|joint\_angles\(\)|const [JointAngles](JointAngles.md#)&|void|Returns the current value of joint\_angles. If joint\_angles is not set, returns a [JointAngles](JointAngles.md#) with none of its fields set \(possibly joint\_angles::default\_instance\(\)\).|
|mutable\_joint\_angles\(\)| [JointAngles](JointAngles.md#) \*|void|Returns a pointer to the mutable [JointAngles](JointAngles.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointAngles](JointAngles.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointAngles](JointAngles.md#)\). After calling this, has\_joint\_angles\(\) will return true and joint\_angles\(\) will return a reference to the same instance of [JointAngles](JointAngles.md#).|
|clear\_joint\_angles\(\)|void|void|Clears the value of the field. After calling this, has\_joint\_angles\(\) will return false and joint\_angles\(\) will return the default value.|
|set\_allocated\_joint\_angles\(\)|void| [JointAngles](JointAngles.md#) \*|Sets the [JointAngles](JointAngles.md#) object to the field and frees the previous field value if it exists. If the [JointAngles](JointAngles.md#) pointer is not NULL, the message takes ownership of the allocated [JointAngles](JointAngles.md#) object and has\_ [JointAngles](JointAngles.md#)\(\) will return true. Otherwise, if the joint\_angles is NULL, the behavior is the same as calling clear\_joint\_angles\(\).|
|release\_joint\_angles\(\)| [JointAngles](JointAngles.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointAngles](JointAngles.md#) object. After calling this, caller takes the ownership of the allocated [JointAngles](JointAngles.md#) object, has\_joint\_angles\(\) will return false, and joint\_angles\(\) will return the default value.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [JointTrajectoryConstraint](JointTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) \*|Sets the [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object and has\_ [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [JointTrajectoryConstraint](JointTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

