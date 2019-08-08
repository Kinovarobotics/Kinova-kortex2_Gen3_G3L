# class CustomData

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|custom\_data\_id| [MessageId](MessageId.md#)|MessageId|
|gripper\_custom\_data| [CustomDataUnit](CustomDataUnit.md#)| |
|motor\_custom\_data| [CustomDataUnit](CustomDataUnit.md#)| |

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_custom\_data\_id\(\) const|bool|void|Returns true if custom\_data\_id is set.|
|custom\_data\_id\(\)|const [MessageId](MessageId.md#)&|void|Returns the current value of custom\_data\_id. If custom\_data\_id is not set, returns a [MessageId](MessageId.md#) with none of its fields set \(possibly custom\_data\_id::default\_instance\(\)\).|
|mutable\_custom\_data\_id\(\)| [MessageId](MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](MessageId.md#)\). After calling this, has\_custom\_data\_id\(\) will return true and custom\_data\_id\(\) will return a reference to the same instance of [MessageId](MessageId.md#).|
|clear\_custom\_data\_id\(\)|void|void|Clears the value of the field. After calling this, has\_custom\_data\_id\(\) will return false and custom\_data\_id\(\) will return the default value.|
|set\_allocated\_custom\_data\_id\(\)|void| [MessageId](MessageId.md#) \*|Sets the [MessageId](MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](MessageId.md#) object and has\_ [MessageId](MessageId.md#)\(\) will return true. Otherwise, if the custom\_data\_id is NULL, the behavior is the same as calling clear\_custom\_data\_id\(\).|
|release\_custom\_data\_id\(\)| [MessageId](MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](MessageId.md#) object, has\_custom\_data\_id\(\) will return false, and custom\_data\_id\(\) will return the default value.|
|has\_gripper\_custom\_data\(\) const|bool|void|Returns true if gripper\_custom\_data is set.|
|gripper\_custom\_data\(\)|const [CustomDataUnit](CustomDataUnit.md#)&|void|Returns the current value of gripper\_custom\_data. If gripper\_custom\_data is not set, returns a [CustomDataUnit](CustomDataUnit.md#) with none of its fields set \(possibly gripper\_custom\_data::default\_instance\(\)\).|
|mutable\_gripper\_custom\_data\(\)| [CustomDataUnit](CustomDataUnit.md#) \*|void|Returns a pointer to the mutable [CustomDataUnit](CustomDataUnit.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [CustomDataUnit](CustomDataUnit.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [CustomDataUnit](CustomDataUnit.md#)\). After calling this, has\_gripper\_custom\_data\(\) will return true and gripper\_custom\_data\(\) will return a reference to the same instance of [CustomDataUnit](CustomDataUnit.md#).|
|clear\_gripper\_custom\_data\(\)|void|void|Clears the value of the field. After calling this, has\_gripper\_custom\_data\(\) will return false and gripper\_custom\_data\(\) will return the default value.|
|set\_allocated\_gripper\_custom\_data\(\)|void| [CustomDataUnit](CustomDataUnit.md#) \*|Sets the [CustomDataUnit](CustomDataUnit.md#) object to the field and frees the previous field value if it exists. If the [CustomDataUnit](CustomDataUnit.md#) pointer is not NULL, the message takes ownership of the allocated [CustomDataUnit](CustomDataUnit.md#) object and has\_ [CustomDataUnit](CustomDataUnit.md#)\(\) will return true. Otherwise, if the gripper\_custom\_data is NULL, the behavior is the same as calling clear\_gripper\_custom\_data\(\).|
|release\_gripper\_custom\_data\(\)| [CustomDataUnit](CustomDataUnit.md#) \*|void|Releases the ownership of the field and returns the pointer of the [CustomDataUnit](CustomDataUnit.md#) object. After calling this, caller takes the ownership of the allocated [CustomDataUnit](CustomDataUnit.md#) object, has\_gripper\_custom\_data\(\) will return false, and gripper\_custom\_data\(\) will return the default value.|
|motor\_custom\_data\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|motor\_custom\_data\(\) const|const [CustomDataUnit](CustomDataUnit.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, motor\_custom\_data\_size\(\)\) yields undefined behavior.|
|mutable\_motor\_custom\_data\(\)| [CustomDataUnit](CustomDataUnit.md#)\*|int index|Returns a pointer to the mutable [CustomDataUnit](CustomDataUnit.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, motor\_custom\_data\_size\(\)\) yields undefined behavior.|
|add\_motor\_custom\_data\(\)| [CustomDataUnit](CustomDataUnit.md#)\*|void|Adds a new element and returns a pointer to it. The returned [CustomDataUnit](CustomDataUnit.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [CustomDataUnit](CustomDataUnit.md#)\).|
|clear\_motor\_custom\_data\(\)|void|void|Removes all elements from the field. After calling this, motor\_custom\_data\_size\(\) will return zero.|
|motor\_custom\_data\(\) const|const RepeatedPtrField< [CustomDataUnit](CustomDataUnit.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_motor\_custom\_data\(\)|RepeatedPtrField< [CustomDataUnit](CustomDataUnit.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [GripperCyclic \(C++\)](../../summary_pages/GripperCyclic.md)

