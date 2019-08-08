# class TorqueCalibration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|global\_gain|float32|Global gain value|
|global\_offset|float32|Global offset value|
|gain|float32|Gain \(index 0 to 3\)|
|offset|float32|Offset \(index 0 to 3\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|global\_gain\(\)|float32|void|Returns the current value of global\_gain. If the global\_gain is not set, returns 0.|
|set\_global\_gain\(\)|void|float32|Sets the value of global\_gain. After calling this, global\_gain\(\) will return value.|
|clear\_global\_gain\(\)|void|void|Clears the value of global\_gain. After calling this, global\_gain\(\) will return 0.|
|global\_offset\(\)|float32|void|Returns the current value of global\_offset. If the global\_offset is not set, returns 0.|
|set\_global\_offset\(\)|void|float32|Sets the value of global\_offset. After calling this, global\_offset\(\) will return value.|
|clear\_global\_offset\(\)|void|void|Clears the value of global\_offset. After calling this, global\_offset\(\) will return 0.|
|gain\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|gain\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, gain\_size\(\)\) yields undefined behavior.|
|set\_gain\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_gain\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_gain\(\)|void|void|Removes all elements from the field. After calling this, gain\_size\(\) will return zero.|
|gain\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_gain\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|offset\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|offset\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, offset\_size\(\)\) yields undefined behavior.|
|set\_offset\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_offset\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_offset\(\)|void|void|Removes all elements from the field. After calling this, offset\_size\(\) will return zero.|
|offset\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_offset\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [ActuatorConfig \(C++\)](../../summary_pages/ActuatorConfig.md)

