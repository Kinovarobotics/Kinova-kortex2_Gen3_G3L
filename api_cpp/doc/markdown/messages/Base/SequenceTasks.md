# class SequenceTasks

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_tasks| [SequenceTask](SequenceTask.md#)|List of tasks|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sequence\_tasks\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|sequence\_tasks\(\) const|const [SequenceTask](SequenceTask.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_tasks\_size\(\)\) yields undefined behavior.|
|mutable\_sequence\_tasks\(\)| [SequenceTask](SequenceTask.md#)\*|int index|Returns a pointer to the mutable [SequenceTask](SequenceTask.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_tasks\_size\(\)\) yields undefined behavior.|
|add\_sequence\_tasks\(\)| [SequenceTask](SequenceTask.md#)\*|void|Adds a new element and returns a pointer to it. The returned [SequenceTask](SequenceTask.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceTask](SequenceTask.md#)\).|
|clear\_sequence\_tasks\(\)|void|void|Removes all elements from the field. After calling this, sequence\_tasks\_size\(\) will return zero.|
|sequence\_tasks\(\) const|const RepeatedPtrField< [SequenceTask](SequenceTask.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_sequence\_tasks\(\)|RepeatedPtrField< [SequenceTask](SequenceTask.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

