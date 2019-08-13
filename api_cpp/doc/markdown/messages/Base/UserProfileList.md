# class UserProfileList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|user\_profiles| [UserProfile](UserProfile.md#)|User profile|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|user\_profiles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|user\_profiles\(\) const|const [UserProfile](UserProfile.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, user\_profiles\_size\(\)\) yields undefined behavior.|
|mutable\_user\_profiles\(\)| [UserProfile](UserProfile.md#)\*|int index|Returns a pointer to the mutable [UserProfile](UserProfile.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, user\_profiles\_size\(\)\) yields undefined behavior.|
|add\_user\_profiles\(\)| [UserProfile](UserProfile.md#)\*|void|Adds a new element and returns a pointer to it. The returned [UserProfile](UserProfile.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfile](UserProfile.md#)\).|
|clear\_user\_profiles\(\)|void|void|Removes all elements from the field. After calling this, user\_profiles\_size\(\) will return zero.|
|user\_profiles\(\) const|const RepeatedPtrField< [UserProfile](UserProfile.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_user\_profiles\(\)|RepeatedPtrField< [UserProfile](UserProfile.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

