# class ControllerNotificationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|notifications| [ControllerNotification](ControllerNotification.md#)|Notifications|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|notifications\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|notifications\(\) const|const [ControllerNotification](ControllerNotification.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|mutable\_notifications\(\)| [ControllerNotification](ControllerNotification.md#)\*|int index|Returns a pointer to the mutable [ControllerNotification](ControllerNotification.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|add\_notifications\(\)| [ControllerNotification](ControllerNotification.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ControllerNotification](ControllerNotification.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerNotification](ControllerNotification.md#)\).|
|clear\_notifications\(\)|void|void|Removes all elements from the field. After calling this, notifications\_size\(\) will return zero.|
|notifications\(\) const|const RepeatedPtrField< [ControllerNotification](ControllerNotification.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_notifications\(\)|RepeatedPtrField< [ControllerNotification](ControllerNotification.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

