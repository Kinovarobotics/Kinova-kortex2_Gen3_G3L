# class Gripper

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|finger| [Finger](Finger.md#)|Finger movements|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|finger\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|finger\(\) const|const [Finger](Finger.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, finger\_size\(\)\) yields undefined behavior.|
|mutable\_finger\(\)| [Finger](Finger.md#)\*|int index|Returns a pointer to the mutable [Finger](Finger.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, finger\_size\(\)\) yields undefined behavior.|
|add\_finger\(\)| [Finger](Finger.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Finger](Finger.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Finger](Finger.md#)\).|
|clear\_finger\(\)|void|void|Removes all elements from the field. After calling this, finger\_size\(\) will return zero.|
|finger\(\) const|const RepeatedPtrField< [Finger](Finger.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_finger\(\)|RepeatedPtrField< [Finger](Finger.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

