# class UserList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|user\_handles| [UserProfileHandle](../Common/UserProfileHandle.md#)|User handle|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|user\_handles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|user\_handles\(\) const|const [UserProfileHandle](../Common/UserProfileHandle.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, user\_handles\_size\(\)\) yields undefined behavior.|
|mutable\_user\_handles\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#)\*|int index|Returns a pointer to the mutable [UserProfileHandle](../Common/UserProfileHandle.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, user\_handles\_size\(\)\) yields undefined behavior.|
|add\_user\_handles\(\)| [UserProfileHandle](../Common/UserProfileHandle.md#)\*|void|Adds a new element and returns a pointer to it. The returned [UserProfileHandle](../Common/UserProfileHandle.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfileHandle](../Common/UserProfileHandle.md#)\).|
|clear\_user\_handles\(\)|void|void|Removes all elements from the field. After calling this, user\_handles\_size\(\) will return zero.|
|user\_handles\(\) const|const RepeatedPtrField< [UserProfileHandle](../Common/UserProfileHandle.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_user\_handles\(\)|RepeatedPtrField< [UserProfileHandle](../Common/UserProfileHandle.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

