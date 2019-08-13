# class PreComputedJointTrajectoryElement

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_angles|float32|Angles values for all joints \(in degrees\)|
|joint\_speeds|float32|Speed values for all joints \(in degrees per second\)|
|joint\_accelerations|float32|Acceleration values for all joints \(in degrees per second^2\)|
|time\_from\_start|float32|Absolute elaspsed time since initial point \(in seconds\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|joint\_angles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_angles\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_angles\_size\(\)\) yields undefined behavior.|
|set\_joint\_angles\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_joint\_angles\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_joint\_angles\(\)|void|void|Removes all elements from the field. After calling this, joint\_angles\_size\(\) will return zero.|
|joint\_angles\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_angles\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|joint\_speeds\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_speeds\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_speeds\_size\(\)\) yields undefined behavior.|
|set\_joint\_speeds\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_joint\_speeds\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_joint\_speeds\(\)|void|void|Removes all elements from the field. After calling this, joint\_speeds\_size\(\) will return zero.|
|joint\_speeds\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_speeds\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|joint\_accelerations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_accelerations\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_accelerations\_size\(\)\) yields undefined behavior.|
|set\_joint\_accelerations\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_joint\_accelerations\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_joint\_accelerations\(\)|void|void|Removes all elements from the field. After calling this, joint\_accelerations\_size\(\) will return zero.|
|joint\_accelerations\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_accelerations\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|time\_from\_start\(\)|float32|void|Returns the current value of time\_from\_start. If the time\_from\_start is not set, returns 0.|
|set\_time\_from\_start\(\)|void|float32|Sets the value of time\_from\_start. After calling this, time\_from\_start\(\) will return value.|
|clear\_time\_from\_start\(\)|void|void|Clears the value of time\_from\_start. After calling this, time\_from\_start\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

