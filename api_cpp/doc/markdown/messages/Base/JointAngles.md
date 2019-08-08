# class JointAngles

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_angles| [JointAngle](JointAngle.md#)|Array of joint angles|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|joint\_angles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_angles\(\) const|const [JointAngle](JointAngle.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_angles\_size\(\)\) yields undefined behavior.|
|mutable\_joint\_angles\(\)| [JointAngle](JointAngle.md#)\*|int index|Returns a pointer to the mutable [JointAngle](JointAngle.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, joint\_angles\_size\(\)\) yields undefined behavior.|
|add\_joint\_angles\(\)| [JointAngle](JointAngle.md#)\*|void|Adds a new element and returns a pointer to it. The returned [JointAngle](JointAngle.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointAngle](JointAngle.md#)\).|
|clear\_joint\_angles\(\)|void|void|Removes all elements from the field. After calling this, joint\_angles\_size\(\) will return zero.|
|joint\_angles\(\) const|const RepeatedPtrField< [JointAngle](JointAngle.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_angles\(\)|RepeatedPtrField< [JointAngle](JointAngle.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

