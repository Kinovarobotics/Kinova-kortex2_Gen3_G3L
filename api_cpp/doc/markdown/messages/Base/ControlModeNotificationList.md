# class ControlModeNotificationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|notifications| [ControlModeNotification](ControlModeNotification.md#)|Notification|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|notifications\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|notifications\(\) const|const [ControlModeNotification](ControlModeNotification.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|mutable\_notifications\(\)| [ControlModeNotification](ControlModeNotification.md#)\*|int index|Returns a pointer to the mutable [ControlModeNotification](ControlModeNotification.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|add\_notifications\(\)| [ControlModeNotification](ControlModeNotification.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ControlModeNotification](ControlModeNotification.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControlModeNotification](ControlModeNotification.md#)\).|
|clear\_notifications\(\)|void|void|Removes all elements from the field. After calling this, notifications\_size\(\) will return zero.|
|notifications\(\) const|const RepeatedPtrField< [ControlModeNotification](ControlModeNotification.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_notifications\(\)|RepeatedPtrField< [ControlModeNotification](ControlModeNotification.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

