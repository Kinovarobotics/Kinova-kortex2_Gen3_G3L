# class CartesianLimitationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|limitations| [CartesianLimitation](CartesianLimitation.md#)|Limitation|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|limitations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|limitations\(\) const|const [CartesianLimitation](CartesianLimitation.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, limitations\_size\(\)\) yields undefined behavior.|
|mutable\_limitations\(\)| [CartesianLimitation](CartesianLimitation.md#)\*|int index|Returns a pointer to the mutable [CartesianLimitation](CartesianLimitation.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, limitations\_size\(\)\) yields undefined behavior.|
|add\_limitations\(\)| [CartesianLimitation](CartesianLimitation.md#)\*|void|Adds a new element and returns a pointer to it. The returned [CartesianLimitation](CartesianLimitation.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianLimitation](CartesianLimitation.md#)\).|
|clear\_limitations\(\)|void|void|Removes all elements from the field. After calling this, limitations\_size\(\) will return zero.|
|limitations\(\) const|const RepeatedPtrField< [CartesianLimitation](CartesianLimitation.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_limitations\(\)|RepeatedPtrField< [CartesianLimitation](CartesianLimitation.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

