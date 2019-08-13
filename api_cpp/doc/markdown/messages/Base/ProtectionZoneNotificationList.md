# class ProtectionZoneNotificationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|notifications| [ProtectionZoneNotification](ProtectionZoneNotification.md#)|Notification|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|notifications\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|notifications\(\) const|const [ProtectionZoneNotification](ProtectionZoneNotification.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|mutable\_notifications\(\)| [ProtectionZoneNotification](ProtectionZoneNotification.md#)\*|int index|Returns a pointer to the mutable [ProtectionZoneNotification](ProtectionZoneNotification.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|add\_notifications\(\)| [ProtectionZoneNotification](ProtectionZoneNotification.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ProtectionZoneNotification](ProtectionZoneNotification.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ProtectionZoneNotification](ProtectionZoneNotification.md#)\).|
|clear\_notifications\(\)|void|void|Removes all elements from the field. After calling this, notifications\_size\(\) will return zero.|
|notifications\(\) const|const RepeatedPtrField< [ProtectionZoneNotification](ProtectionZoneNotification.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_notifications\(\)|RepeatedPtrField< [ProtectionZoneNotification](ProtectionZoneNotification.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

