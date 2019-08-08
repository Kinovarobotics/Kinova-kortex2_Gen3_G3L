# class ConnectionList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|connection| [Connection](../Common/Connection.md#)|Connection|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|connection\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|connection\(\) const|const [Connection](../Common/Connection.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, connection\_size\(\)\) yields undefined behavior.|
|mutable\_connection\(\)| [Connection](../Common/Connection.md#)\*|int index|Returns a pointer to the mutable [Connection](../Common/Connection.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, connection\_size\(\)\) yields undefined behavior.|
|add\_connection\(\)| [Connection](../Common/Connection.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Connection](../Common/Connection.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Connection](../Common/Connection.md#)\).|
|clear\_connection\(\)|void|void|Removes all elements from the field. After calling this, connection\_size\(\) will return zero.|
|connection\(\) const|const RepeatedPtrField< [Connection](../Common/Connection.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_connection\(\)|RepeatedPtrField< [Connection](../Common/Connection.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Session \(C++\)](../../summary_pages/Session.md)

