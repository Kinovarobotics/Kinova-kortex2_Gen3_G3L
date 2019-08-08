# class ActionList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|action\_list| [Action](Action.md#)|Action|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|action\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|action\_list\(\) const|const [Action](Action.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, action\_list\_size\(\)\) yields undefined behavior.|
|mutable\_action\_list\(\)| [Action](Action.md#)\*|int index|Returns a pointer to the mutable [Action](Action.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, action\_list\_size\(\)\) yields undefined behavior.|
|add\_action\_list\(\)| [Action](Action.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Action](Action.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Action](Action.md#)\).|
|clear\_action\_list\(\)|void|void|Removes all elements from the field. After calling this, action\_list\_size\(\) will return zero.|
|action\_list\(\) const|const RepeatedPtrField< [Action](Action.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_action\_list\(\)|RepeatedPtrField< [Action](Action.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

