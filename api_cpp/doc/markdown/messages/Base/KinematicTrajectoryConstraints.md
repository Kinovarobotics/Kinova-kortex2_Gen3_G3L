# class KinematicTrajectoryConstraints

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|angular\_velocities|float32|Angular velocities for each actuator \(in deg/s\)|
|linear\_velocity|float32|Linear velocity \(in m/s\)|
|angular\_velocity|float32|Angular velocity \(in deg/s\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|angular\_velocities\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|angular\_velocities\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, angular\_velocities\_size\(\)\) yields undefined behavior.|
|set\_angular\_velocities\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_angular\_velocities\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_angular\_velocities\(\)|void|void|Removes all elements from the field. After calling this, angular\_velocities\_size\(\) will return zero.|
|angular\_velocities\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_angular\_velocities\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|linear\_velocity\(\)|float32|void|Returns the current value of linear\_velocity. If the linear\_velocity is not set, returns 0.|
|set\_linear\_velocity\(\)|void|float32|Sets the value of linear\_velocity. After calling this, linear\_velocity\(\) will return value.|
|clear\_linear\_velocity\(\)|void|void|Clears the value of linear\_velocity. After calling this, linear\_velocity\(\) will return 0.|
|angular\_velocity\(\)|float32|void|Returns the current value of angular\_velocity. If the angular\_velocity is not set, returns 0.|
|set\_angular\_velocity\(\)|void|float32|Sets the value of angular\_velocity. After calling this, angular\_velocity\(\) will return value.|
|clear\_angular\_velocity\(\)|void|void|Clears the value of angular\_velocity. After calling this, angular\_velocity\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

