# class MappingList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mappings| [Mapping](Mapping.md#)|Mapping|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|mappings\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|mappings\(\) const|const [Mapping](Mapping.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, mappings\_size\(\)\) yields undefined behavior.|
|mutable\_mappings\(\)| [Mapping](Mapping.md#)\*|int index|Returns a pointer to the mutable [Mapping](Mapping.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, mappings\_size\(\)\) yields undefined behavior.|
|add\_mappings\(\)| [Mapping](Mapping.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Mapping](Mapping.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Mapping](Mapping.md#)\).|
|clear\_mappings\(\)|void|void|Removes all elements from the field. After calling this, mappings\_size\(\) will return zero.|
|mappings\(\) const|const RepeatedPtrField< [Mapping](Mapping.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_mappings\(\)|RepeatedPtrField< [Mapping](Mapping.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

