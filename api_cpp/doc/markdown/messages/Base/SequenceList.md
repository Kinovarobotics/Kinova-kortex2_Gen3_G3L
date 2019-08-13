# class SequenceList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_list| [Sequence](Sequence.md#)|Sequence|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sequence\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|sequence\_list\(\) const|const [Sequence](Sequence.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_list\_size\(\)\) yields undefined behavior.|
|mutable\_sequence\_list\(\)| [Sequence](Sequence.md#)\*|int index|Returns a pointer to the mutable [Sequence](Sequence.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_list\_size\(\)\) yields undefined behavior.|
|add\_sequence\_list\(\)| [Sequence](Sequence.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Sequence](Sequence.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Sequence](Sequence.md#)\).|
|clear\_sequence\_list\(\)|void|void|Removes all elements from the field. After calling this, sequence\_list\_size\(\) will return zero.|
|sequence\_list\(\) const|const RepeatedPtrField< [Sequence](Sequence.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_sequence\_list\(\)|RepeatedPtrField< [Sequence](Sequence.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

