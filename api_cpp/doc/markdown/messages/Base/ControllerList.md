# class ControllerList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handles| [ControllerHandle](ControllerHandle.md#)|Controller handle|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|handles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|handles\(\) const|const [ControllerHandle](ControllerHandle.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, handles\_size\(\)\) yields undefined behavior.|
|mutable\_handles\(\)| [ControllerHandle](ControllerHandle.md#)\*|int index|Returns a pointer to the mutable [ControllerHandle](ControllerHandle.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, handles\_size\(\)\) yields undefined behavior.|
|add\_handles\(\)| [ControllerHandle](ControllerHandle.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ControllerHandle](ControllerHandle.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerHandle](ControllerHandle.md#)\).|
|clear\_handles\(\)|void|void|Removes all elements from the field. After calling this, handles\_size\(\) will return zero.|
|handles\(\) const|const RepeatedPtrField< [ControllerHandle](ControllerHandle.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_handles\(\)|RepeatedPtrField< [ControllerHandle](ControllerHandle.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

