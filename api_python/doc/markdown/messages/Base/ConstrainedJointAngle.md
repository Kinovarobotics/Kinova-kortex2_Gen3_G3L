# class ConstrainedJointAngle

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|joint\_identifier|int|Joint identifier \(use device\_identifier\)|You can manipulate the field joint\_identifier as if it were a regular field. To clear the value of joint\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|value|float|Joint value \(in degrees\)|You can manipulate the field value as if it were a regular field. To clear the value of value and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|constraint| [JointTrajectoryConstraint](JointTrajectoryConstraint.md#)|Constraint to apply to the joint angle \(optional\)|To set constraint, you simply assign a value directly to a field within constraint. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

