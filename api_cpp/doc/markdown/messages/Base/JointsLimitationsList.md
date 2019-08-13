# class JointsLimitationsList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joints\_limitations| [JointLimitation](JointLimitation.md#)|Joints Limitations|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|joints\_limitations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joints\_limitations\(\) const|const [JointLimitation](JointLimitation.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joints\_limitations\_size\(\)\) yields undefined behavior.|
|mutable\_joints\_limitations\(\)| [JointLimitation](JointLimitation.md#)\*|int index|Returns a pointer to the mutable [JointLimitation](JointLimitation.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, joints\_limitations\_size\(\)\) yields undefined behavior.|
|add\_joints\_limitations\(\)| [JointLimitation](JointLimitation.md#)\*|void|Adds a new element and returns a pointer to it. The returned [JointLimitation](JointLimitation.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointLimitation](JointLimitation.md#)\).|
|clear\_joints\_limitations\(\)|void|void|Removes all elements from the field. After calling this, joints\_limitations\_size\(\) will return zero.|
|joints\_limitations\(\) const|const RepeatedPtrField< [JointLimitation](JointLimitation.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joints\_limitations\(\)|RepeatedPtrField< [JointLimitation](JointLimitation.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

