# class PreComputedJointTrajectory

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mode|uint32|Trajectory continuity mode|
|trajectory\_elements| [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)|List of pre-computed elements composing the trajectory.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|trajectory\_elements\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|trajectory\_elements\(\) const|const [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, trajectory\_elements\_size\(\)\) yields undefined behavior.|
|mutable\_trajectory\_elements\(\)| [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)\*|int index|Returns a pointer to the mutable [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, trajectory\_elements\_size\(\)\) yields undefined behavior.|
|add\_trajectory\_elements\(\)| [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)\*|void|Adds a new element and returns a pointer to it. The returned [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)\).|
|clear\_trajectory\_elements\(\)|void|void|Removes all elements from the field. After calling this, trajectory\_elements\_size\(\) will return zero.|
|trajectory\_elements\(\) const|const RepeatedPtrField< [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_trajectory\_elements\(\)|RepeatedPtrField< [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

