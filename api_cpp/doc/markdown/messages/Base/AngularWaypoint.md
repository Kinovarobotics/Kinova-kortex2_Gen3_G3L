# class AngularWaypoint

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|angles|float32|Target position \(in deg\)|
|maximum\_velocities|float32|Maximum velocities for each actuator \(in deg/s\) during movement \(optional\)|
|duration|float32|Duration to reach this waypoint from the previous position \(in seconds\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|angles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|angles\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, angles\_size\(\)\) yields undefined behavior.|
|set\_angles\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_angles\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_angles\(\)|void|void|Removes all elements from the field. After calling this, angles\_size\(\) will return zero.|
|angles\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_angles\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|maximum\_velocities\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|maximum\_velocities\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, maximum\_velocities\_size\(\)\) yields undefined behavior.|
|set\_maximum\_velocities\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_maximum\_velocities\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_maximum\_velocities\(\)|void|void|Removes all elements from the field. After calling this, maximum\_velocities\_size\(\) will return zero.|
|maximum\_velocities\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_maximum\_velocities\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|duration\(\)|float32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|float32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

