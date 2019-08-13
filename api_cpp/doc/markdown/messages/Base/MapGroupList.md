# class MapGroupList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|map\_groups| [MapGroup](MapGroup.md#)|Map group|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|map\_groups\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|map\_groups\(\) const|const [MapGroup](MapGroup.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, map\_groups\_size\(\)\) yields undefined behavior.|
|mutable\_map\_groups\(\)| [MapGroup](MapGroup.md#)\*|int index|Returns a pointer to the mutable [MapGroup](MapGroup.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, map\_groups\_size\(\)\) yields undefined behavior.|
|add\_map\_groups\(\)| [MapGroup](MapGroup.md#)\*|void|Adds a new element and returns a pointer to it. The returned [MapGroup](MapGroup.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapGroup](MapGroup.md#)\).|
|clear\_map\_groups\(\)|void|void|Removes all elements from the field. After calling this, map\_groups\_size\(\) will return zero.|
|map\_groups\(\) const|const RepeatedPtrField< [MapGroup](MapGroup.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_map\_groups\(\)|RepeatedPtrField< [MapGroup](MapGroup.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

