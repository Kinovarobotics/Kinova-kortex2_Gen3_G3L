# class JointAccelerationSoftLimits

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|control\_mode|uint32|Control mode|
|joint\_acceleration\_soft\_limits|float32|Software acceleration limits|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|control\_mode\(\) const|uint32|void|Returns the current value of control\_mode. If the control\_mode is not set, returns 0.|
|set\_control\_mode\(\)|void|uint32|Sets the value of control\_mode. After calling this, control\_mode\(\) will return value.|
|clear\_control\_mode\(\)|void|void|Clears the value of control\_mode. After calling this, control\_mode\(\) will return the empty string/empty bytes.|
|joint\_acceleration\_soft\_limits\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_acceleration\_soft\_limits\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_acceleration\_soft\_limits\_size\(\)\) yields undefined behavior.|
|set\_joint\_acceleration\_soft\_limits\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_joint\_acceleration\_soft\_limits\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_joint\_acceleration\_soft\_limits\(\)|void|void|Removes all elements from the field. After calling this, joint\_acceleration\_soft\_limits\_size\(\) will return zero.|
|joint\_acceleration\_soft\_limits\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_acceleration\_soft\_limits\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

