# class JointSpeeds

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_speeds| [JointSpeed](JointSpeed.md#)|Array of joint speeds|
|duration|uint32|Duration constraint. If not 0, allows to set a limit \(in seconds\) common to every joint specified in 'joint\_speeds' \(not implemented yet\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|joint\_speeds\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_speeds\(\) const|const [JointSpeed](JointSpeed.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_speeds\_size\(\)\) yields undefined behavior.|
|mutable\_joint\_speeds\(\)| [JointSpeed](JointSpeed.md#)\*|int index|Returns a pointer to the mutable [JointSpeed](JointSpeed.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, joint\_speeds\_size\(\)\) yields undefined behavior.|
|add\_joint\_speeds\(\)| [JointSpeed](JointSpeed.md#)\*|void|Adds a new element and returns a pointer to it. The returned [JointSpeed](JointSpeed.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointSpeed](JointSpeed.md#)\).|
|clear\_joint\_speeds\(\)|void|void|Removes all elements from the field. After calling this, joint\_speeds\_size\(\) will return zero.|
|joint\_speeds\(\) const|const RepeatedPtrField< [JointSpeed](JointSpeed.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_speeds\(\)|RepeatedPtrField< [JointSpeed](JointSpeed.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

