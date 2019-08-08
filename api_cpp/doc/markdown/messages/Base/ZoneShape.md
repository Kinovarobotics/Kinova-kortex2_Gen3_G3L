# class ZoneShape

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|shape\_type|uint32|Shape type|
|origin| [Point](Point.md#)|Origin of the protection zone shape from reference \(in meters\)|
|orientation| [RotationMatrix](RotationMatrix.md#)|Rotation matrix to provide shape orientation|
|dimensions|float32|Shape size measurement \(in meters\). If rectangular prism: x, y and z dimensions. If cylinder: radius and height. If sphere: radius|
|envelope\_thickness|float32|Thickness of envelop around shape \(in meters\). The envelop is of same shape type as the shape at its center.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|shape\_type\(\) const|uint32|void|Returns the current value of shape\_type. If the shape\_type is not set, returns 0.|
|set\_shape\_type\(\)|void|uint32|Sets the value of shape\_type. After calling this, shape\_type\(\) will return value.|
|clear\_shape\_type\(\)|void|void|Clears the value of shape\_type. After calling this, shape\_type\(\) will return the empty string/empty bytes.|
|has\_origin\(\) const|bool|void|Returns true if origin is set.|
|origin\(\)|const [Point](Point.md#)&|void|Returns the current value of origin. If origin is not set, returns a [Point](Point.md#) with none of its fields set \(possibly origin::default\_instance\(\)\).|
|mutable\_origin\(\)| [Point](Point.md#) \*|void|Returns a pointer to the mutable [Point](Point.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Point](Point.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Point](Point.md#)\). After calling this, has\_origin\(\) will return true and origin\(\) will return a reference to the same instance of [Point](Point.md#).|
|clear\_origin\(\)|void|void|Clears the value of the field. After calling this, has\_origin\(\) will return false and origin\(\) will return the default value.|
|set\_allocated\_origin\(\)|void| [Point](Point.md#) \*|Sets the [Point](Point.md#) object to the field and frees the previous field value if it exists. If the [Point](Point.md#) pointer is not NULL, the message takes ownership of the allocated [Point](Point.md#) object and has\_ [Point](Point.md#)\(\) will return true. Otherwise, if the origin is NULL, the behavior is the same as calling clear\_origin\(\).|
|release\_origin\(\)| [Point](Point.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Point](Point.md#) object. After calling this, caller takes the ownership of the allocated [Point](Point.md#) object, has\_origin\(\) will return false, and origin\(\) will return the default value.|
|has\_orientation\(\) const|bool|void|Returns true if orientation is set.|
|orientation\(\)|const [RotationMatrix](RotationMatrix.md#)&|void|Returns the current value of orientation. If orientation is not set, returns a [RotationMatrix](RotationMatrix.md#) with none of its fields set \(possibly orientation::default\_instance\(\)\).|
|mutable\_orientation\(\)| [RotationMatrix](RotationMatrix.md#) \*|void|Returns a pointer to the mutable [RotationMatrix](RotationMatrix.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [RotationMatrix](RotationMatrix.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [RotationMatrix](RotationMatrix.md#)\). After calling this, has\_orientation\(\) will return true and orientation\(\) will return a reference to the same instance of [RotationMatrix](RotationMatrix.md#).|
|clear\_orientation\(\)|void|void|Clears the value of the field. After calling this, has\_orientation\(\) will return false and orientation\(\) will return the default value.|
|set\_allocated\_orientation\(\)|void| [RotationMatrix](RotationMatrix.md#) \*|Sets the [RotationMatrix](RotationMatrix.md#) object to the field and frees the previous field value if it exists. If the [RotationMatrix](RotationMatrix.md#) pointer is not NULL, the message takes ownership of the allocated [RotationMatrix](RotationMatrix.md#) object and has\_ [RotationMatrix](RotationMatrix.md#)\(\) will return true. Otherwise, if the orientation is NULL, the behavior is the same as calling clear\_orientation\(\).|
|release\_orientation\(\)| [RotationMatrix](RotationMatrix.md#) \*|void|Releases the ownership of the field and returns the pointer of the [RotationMatrix](RotationMatrix.md#) object. After calling this, caller takes the ownership of the allocated [RotationMatrix](RotationMatrix.md#) object, has\_orientation\(\) will return false, and orientation\(\) will return the default value.|
|dimensions\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|dimensions\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, dimensions\_size\(\)\) yields undefined behavior.|
|set\_dimensions\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_dimensions\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_dimensions\(\)|void|void|Removes all elements from the field. After calling this, dimensions\_size\(\) will return zero.|
|dimensions\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_dimensions\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|envelope\_thickness\(\)|float32|void|Returns the current value of envelope\_thickness. If the envelope\_thickness is not set, returns 0.|
|set\_envelope\_thickness\(\)|void|float32|Sets the value of envelope\_thickness. After calling this, envelope\_thickness\(\) will return value.|
|clear\_envelope\_thickness\(\)|void|void|Clears the value of envelope\_thickness. After calling this, envelope\_thickness\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

