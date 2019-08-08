# class ConstrainedOrientation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|target\_orientation| [Orientation](Orientation.md#)|Cartesian orientation|
|constraint| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)|Constraint to apply to the target orientation|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_target\_orientation\(\) const|bool|void|Returns true if target\_orientation is set.|
|target\_orientation\(\)|const [Orientation](Orientation.md#)&|void|Returns the current value of target\_orientation. If target\_orientation is not set, returns a [Orientation](Orientation.md#) with none of its fields set \(possibly target\_orientation::default\_instance\(\)\).|
|mutable\_target\_orientation\(\)| [Orientation](Orientation.md#) \*|void|Returns a pointer to the mutable [Orientation](Orientation.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Orientation](Orientation.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Orientation](Orientation.md#)\). After calling this, has\_target\_orientation\(\) will return true and target\_orientation\(\) will return a reference to the same instance of [Orientation](Orientation.md#).|
|clear\_target\_orientation\(\)|void|void|Clears the value of the field. After calling this, has\_target\_orientation\(\) will return false and target\_orientation\(\) will return the default value.|
|set\_allocated\_target\_orientation\(\)|void| [Orientation](Orientation.md#) \*|Sets the [Orientation](Orientation.md#) object to the field and frees the previous field value if it exists. If the [Orientation](Orientation.md#) pointer is not NULL, the message takes ownership of the allocated [Orientation](Orientation.md#) object and has\_ [Orientation](Orientation.md#)\(\) will return true. Otherwise, if the target\_orientation is NULL, the behavior is the same as calling clear\_target\_orientation\(\).|
|release\_target\_orientation\(\)| [Orientation](Orientation.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Orientation](Orientation.md#) object. After calling this, caller takes the ownership of the allocated [Orientation](Orientation.md#) object, has\_target\_orientation\(\) will return false, and target\_orientation\(\) will return the default value.|
|has\_constraint\(\) const|bool|void|Returns true if constraint is set.|
|constraint\(\)|const [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)&|void|Returns the current value of constraint. If constraint is not set, returns a [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) with none of its fields set \(possibly constraint::default\_instance\(\)\).|
|mutable\_constraint\(\)| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) \*|void|Returns a pointer to the mutable [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)\). After calling this, has\_constraint\(\) will return true and constraint\(\) will return a reference to the same instance of [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#).|
|clear\_constraint\(\)|void|void|Clears the value of the field. After calling this, has\_constraint\(\) will return false and constraint\(\) will return the default value.|
|set\_allocated\_constraint\(\)|void| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) \*|Sets the [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object to the field and frees the previous field value if it exists. If the [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) pointer is not NULL, the message takes ownership of the allocated [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object and has\_ [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#)\(\) will return true. Otherwise, if the constraint is NULL, the behavior is the same as calling clear\_constraint\(\).|
|release\_constraint\(\)| [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) \*|void|Releases the ownership of the field and returns the pointer of the [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object. After calling this, caller takes the ownership of the allocated [CartesianTrajectoryConstraint](CartesianTrajectoryConstraint.md#) object, has\_constraint\(\) will return false, and constraint\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

