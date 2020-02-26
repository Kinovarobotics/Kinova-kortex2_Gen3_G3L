# class KinematicLimits

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|control\_mode|uint32|Control mode|
|twist\_linear|float32|Linear twist limits|
|twist\_angular|float32|Angular twist limits|
|joint\_speed\_limits|float32|Joint speed limits|
|joint\_acceleration\_limits|float32|Joint Acceleration limits|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|control\_mode\(\) const|uint32|void|Returns the current value of control\_mode. If the control\_mode is not set, returns 0.|
|set\_control\_mode\(\)|void|uint32|Sets the value of control\_mode. After calling this, control\_mode\(\) will return value.|
|clear\_control\_mode\(\)|void|void|Clears the value of control\_mode. After calling this, control\_mode\(\) will return the empty string/empty bytes.|
|twist\_linear\(\)|float32|void|Returns the current value of twist\_linear. If the twist\_linear is not set, returns 0.|
|set\_twist\_linear\(\)|void|float32|Sets the value of twist\_linear. After calling this, twist\_linear\(\) will return value.|
|clear\_twist\_linear\(\)|void|void|Clears the value of twist\_linear. After calling this, twist\_linear\(\) will return 0.|
|twist\_angular\(\)|float32|void|Returns the current value of twist\_angular. If the twist\_angular is not set, returns 0.|
|set\_twist\_angular\(\)|void|float32|Sets the value of twist\_angular. After calling this, twist\_angular\(\) will return value.|
|clear\_twist\_angular\(\)|void|void|Clears the value of twist\_angular. After calling this, twist\_angular\(\) will return 0.|
|joint\_speed\_limits\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_speed\_limits\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_speed\_limits\_size\(\)\) yields undefined behavior.|
|set\_joint\_speed\_limits\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_joint\_speed\_limits\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_joint\_speed\_limits\(\)|void|void|Removes all elements from the field. After calling this, joint\_speed\_limits\_size\(\) will return zero.|
|joint\_speed\_limits\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_speed\_limits\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|joint\_acceleration\_limits\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_acceleration\_limits\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_acceleration\_limits\_size\(\)\) yields undefined behavior.|
|set\_joint\_acceleration\_limits\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_joint\_acceleration\_limits\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_joint\_acceleration\_limits\(\)|void|void|Removes all elements from the field. After calling this, joint\_acceleration\_limits\_size\(\) will return zero.|
|joint\_acceleration\_limits\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_acceleration\_limits\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

