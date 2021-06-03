# class IKData

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|cartesian\_pose| [Pose](Pose.md#)|Cartesian pose of the end effector used to calculate the corresponding joint angles|
|guess| [JointAngles](JointAngles.md#)|Initial guess for the joint angles|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_cartesian\_pose\(\) const|bool|void|Returns true if cartesian\_pose is set.|
|cartesian\_pose\(\)|const [Pose](Pose.md#)&|void|Returns the current value of cartesian\_pose. If cartesian\_pose is not set, returns a [Pose](Pose.md#) with none of its fields set \(possibly cartesian\_pose::default\_instance\(\)\).|
|mutable\_cartesian\_pose\(\)| [Pose](Pose.md#) \*|void|Returns a pointer to the mutable [Pose](Pose.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Pose](Pose.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Pose](Pose.md#)\). After calling this, has\_cartesian\_pose\(\) will return true and cartesian\_pose\(\) will return a reference to the same instance of [Pose](Pose.md#).|
|clear\_cartesian\_pose\(\)|void|void|Clears the value of the field. After calling this, has\_cartesian\_pose\(\) will return false and cartesian\_pose\(\) will return the default value.|
|set\_allocated\_cartesian\_pose\(\)|void| [Pose](Pose.md#) \*|Sets the [Pose](Pose.md#) object to the field and frees the previous field value if it exists. If the [Pose](Pose.md#) pointer is not NULL, the message takes ownership of the allocated [Pose](Pose.md#) object and has\_ [Pose](Pose.md#)\(\) will return true. Otherwise, if the cartesian\_pose is NULL, the behavior is the same as calling clear\_cartesian\_pose\(\).|
|release\_cartesian\_pose\(\)| [Pose](Pose.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Pose](Pose.md#) object. After calling this, caller takes the ownership of the allocated [Pose](Pose.md#) object, has\_cartesian\_pose\(\) will return false, and cartesian\_pose\(\) will return the default value.|
|has\_guess\(\) const|bool|void|Returns true if guess is set.|
|guess\(\)|const [JointAngles](JointAngles.md#)&|void|Returns the current value of guess. If guess is not set, returns a [JointAngles](JointAngles.md#) with none of its fields set \(possibly guess::default\_instance\(\)\).|
|mutable\_guess\(\)| [JointAngles](JointAngles.md#) \*|void|Returns a pointer to the mutable [JointAngles](JointAngles.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [JointAngles](JointAngles.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointAngles](JointAngles.md#)\). After calling this, has\_guess\(\) will return true and guess\(\) will return a reference to the same instance of [JointAngles](JointAngles.md#).|
|clear\_guess\(\)|void|void|Clears the value of the field. After calling this, has\_guess\(\) will return false and guess\(\) will return the default value.|
|set\_allocated\_guess\(\)|void| [JointAngles](JointAngles.md#) \*|Sets the [JointAngles](JointAngles.md#) object to the field and frees the previous field value if it exists. If the [JointAngles](JointAngles.md#) pointer is not NULL, the message takes ownership of the allocated [JointAngles](JointAngles.md#) object and has\_ [JointAngles](JointAngles.md#)\(\) will return true. Otherwise, if the guess is NULL, the behavior is the same as calling clear\_guess\(\).|
|release\_guess\(\)| [JointAngles](JointAngles.md#) \*|void|Releases the ownership of the field and returns the pointer of the [JointAngles](JointAngles.md#) object. After calling this, caller takes the ownership of the allocated [JointAngles](JointAngles.md#) object, has\_guess\(\) will return false, and guess\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

