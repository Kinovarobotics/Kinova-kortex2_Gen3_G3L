# class JointTorques

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_torques| [JointTorque](JointTorque.md#)|Array of joint torque.|
|duration|uint32|Duration constraint. If not 0, allows to set a limit \(in seconds\) common to every joint specified in 'joint\_torques' \(not implemented yet\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|joint\_torques\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_torques\(\) const|const [JointTorque](JointTorque.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_torques\_size\(\)\) yields undefined behavior.|
|mutable\_joint\_torques\(\)| [JointTorque](JointTorque.md#)\*|int index|Returns a pointer to the mutable [JointTorque](JointTorque.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, joint\_torques\_size\(\)\) yields undefined behavior.|
|add\_joint\_torques\(\)| [JointTorque](JointTorque.md#)\*|void|Adds a new element and returns a pointer to it. The returned [JointTorque](JointTorque.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointTorque](JointTorque.md#)\).|
|clear\_joint\_torques\(\)|void|void|Removes all elements from the field. After calling this, joint\_torques\_size\(\) will return zero.|
|joint\_torques\(\) const|const RepeatedPtrField< [JointTorque](JointTorque.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_torques\(\)|RepeatedPtrField< [JointTorque](JointTorque.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

