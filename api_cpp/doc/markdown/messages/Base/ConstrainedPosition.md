# class ConstrainedPosition

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|target\_position| [Position](Position.md#)|Cartesian position|
|constraint| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)|Constraint to apply to the target position|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_target\_position\(\) const|bool|void|Returns true if target\_position is set.|
|target\_position\(\)|const [Position](Position.md#)&|void|Returns the current value of target\_position. If target\_position is not set, returns a [Position](Position.md#) with none of its fields set \(possibly target\_position::default\_instance\(\)\).|
|mutable\_target\_position\(\)| [Position](Position.md#) \*|void|Returns a pointer to the mutable [Position](Position.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Position](Position.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Position](Position.md#)\). After calling this, has\_target\_position\(\) will return true and target\_position\(\) will return a reference to the same instance of [Position](Position.md#).|
|clear\_target\_position\(\)|void|void|Clears the value of the field. After calling this, has\_target\_position\(\) will return false and target\_position\(\) will return the default value.|
|set\_allocated\_target\_position\(\)|void| [Position](Position.md#) \*|Sets the [Position](Position.md#) object to the field and frees the previous field value if it exists. If the [Position](Position.md#) pointer is not NULL, the message takes ownership of the allocated [Position](Position.md#) object and has\_ [Position](Position.md#)\(\) will return true. Otherwise, if the target\_position is NULL, the behavior is the same as calling clear\_target\_position\(\).|
|release\_target\_position\(\)| [Position](Position.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Position](Position.md#) object. After calling this, caller takes the ownership of the allocated [Position](Position.md#) object, has\_target\_position\(\) will return false, and target\_position\(\) will return the default value.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) \*|Sets the [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object and has\_ [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

