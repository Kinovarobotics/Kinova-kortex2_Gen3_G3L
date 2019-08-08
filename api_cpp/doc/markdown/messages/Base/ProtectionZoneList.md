# class ProtectionZoneList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|protection\_zones| [ProtectionZone](ProtectionZone.md#)|Protection zone|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|protection\_zones\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|protection\_zones\(\) const|const [ProtectionZone](ProtectionZone.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, protection\_zones\_size\(\)\) yields undefined behavior.|
|mutable\_protection\_zones\(\)| [ProtectionZone](ProtectionZone.md#)\*|int index|Returns a pointer to the mutable [ProtectionZone](ProtectionZone.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, protection\_zones\_size\(\)\) yields undefined behavior.|
|add\_protection\_zones\(\)| [ProtectionZone](ProtectionZone.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ProtectionZone](ProtectionZone.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ProtectionZone](ProtectionZone.md#)\).|
|clear\_protection\_zones\(\)|void|void|Removes all elements from the field. After calling this, protection\_zones\_size\(\) will return zero.|
|protection\_zones\(\) const|const RepeatedPtrField< [ProtectionZone](ProtectionZone.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_protection\_zones\(\)|RepeatedPtrField< [ProtectionZone](ProtectionZone.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

