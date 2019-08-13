# class TrajectoryErrorReport

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|trajectory\_error\_elements| [TrajectoryErrorElement](TrajectoryErrorElement.md#)| |

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|trajectory\_error\_elements\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|trajectory\_error\_elements\(\) const|const [TrajectoryErrorElement](TrajectoryErrorElement.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, trajectory\_error\_elements\_size\(\)\) yields undefined behavior.|
|mutable\_trajectory\_error\_elements\(\)| [TrajectoryErrorElement](TrajectoryErrorElement.md#)\*|int index|Returns a pointer to the mutable [TrajectoryErrorElement](TrajectoryErrorElement.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, trajectory\_error\_elements\_size\(\)\) yields undefined behavior.|
|add\_trajectory\_error\_elements\(\)| [TrajectoryErrorElement](TrajectoryErrorElement.md#)\*|void|Adds a new element and returns a pointer to it. The returned [TrajectoryErrorElement](TrajectoryErrorElement.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [TrajectoryErrorElement](TrajectoryErrorElement.md#)\).|
|clear\_trajectory\_error\_elements\(\)|void|void|Removes all elements from the field. After calling this, trajectory\_error\_elements\_size\(\) will return zero.|
|trajectory\_error\_elements\(\) const|const RepeatedPtrField< [TrajectoryErrorElement](TrajectoryErrorElement.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_trajectory\_error\_elements\(\)|RepeatedPtrField< [TrajectoryErrorElement](TrajectoryErrorElement.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

