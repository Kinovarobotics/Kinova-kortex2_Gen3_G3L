# class KinematicLimitsList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|kinematic\_limits\_list| [KinematicLimits](KinematicLimits.md#)|List of kinematic limits|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|kinematic\_limits\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|kinematic\_limits\_list\(\) const|const [KinematicLimits](KinematicLimits.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, kinematic\_limits\_list\_size\(\)\) yields undefined behavior.|
|mutable\_kinematic\_limits\_list\(\)| [KinematicLimits](KinematicLimits.md#)\*|int index|Returns a pointer to the mutable [KinematicLimits](KinematicLimits.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, kinematic\_limits\_list\_size\(\)\) yields undefined behavior.|
|add\_kinematic\_limits\_list\(\)| [KinematicLimits](KinematicLimits.md#)\*|void|Adds a new element and returns a pointer to it. The returned [KinematicLimits](KinematicLimits.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [KinematicLimits](KinematicLimits.md#)\).|
|clear\_kinematic\_limits\_list\(\)|void|void|Removes all elements from the field. After calling this, kinematic\_limits\_list\_size\(\) will return zero.|
|kinematic\_limits\_list\(\) const|const RepeatedPtrField< [KinematicLimits](KinematicLimits.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_kinematic\_limits\_list\(\)|RepeatedPtrField< [KinematicLimits](KinematicLimits.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

