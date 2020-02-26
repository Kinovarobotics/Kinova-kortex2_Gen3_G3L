# class DesiredSpeeds

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|linear|float32|Desired linear speed \(meters / second\)|
|angular|float32|Desired angular speed \(degrees / second\)|
|joint\_speed|float32|Desired joint speeds \(degrees / second\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|linear\(\)|float32|void|Returns the current value of linear. If the linear is not set, returns 0.|
|set\_linear\(\)|void|float32|Sets the value of linear. After calling this, linear\(\) will return value.|
|clear\_linear\(\)|void|void|Clears the value of linear. After calling this, linear\(\) will return 0.|
|angular\(\)|float32|void|Returns the current value of angular. If the angular is not set, returns 0.|
|set\_angular\(\)|void|float32|Sets the value of angular. After calling this, angular\(\) will return value.|
|clear\_angular\(\)|void|void|Clears the value of angular. After calling this, angular\(\) will return 0.|
|joint\_speed\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_speed\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_speed\_size\(\)\) yields undefined behavior.|
|set\_joint\_speed\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_joint\_speed\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_joint\_speed\(\)|void|void|Removes all elements from the field. After calling this, joint\_speed\_size\(\) will return zero.|
|joint\_speed\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_speed\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

