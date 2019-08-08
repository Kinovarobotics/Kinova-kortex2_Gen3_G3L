# class RotationMatrix

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|row1| [RotationMatrixRow](RotationMatrixRow.md#)|First rotation matrix row|
|row2| [RotationMatrixRow](RotationMatrixRow.md#)|Second rotation matrix row|
|row3| [RotationMatrixRow](RotationMatrixRow.md#)|Third rotation matrix row|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_row1\(\) const|bool|void|Returns true if row1 is set.|
|row1\(\)|const [RotationMatrixRow](RotationMatrixRow.md#)&|void|Returns the current value of row1. If row1 is not set, returns a [RotationMatrixRow](RotationMatrixRow.md#) with none of its fields set \(possibly row1::default\_instance\(\)\).|
|mutable\_row1\(\)| [RotationMatrixRow](RotationMatrixRow.md#) \*|void|Returns a pointer to the mutable [RotationMatrixRow](RotationMatrixRow.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [RotationMatrixRow](RotationMatrixRow.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [RotationMatrixRow](RotationMatrixRow.md#)\). After calling this, has\_row1\(\) will return true and row1\(\) will return a reference to the same instance of [RotationMatrixRow](RotationMatrixRow.md#).|
|clear\_row1\(\)|void|void|Clears the value of the field. After calling this, has\_row1\(\) will return false and row1\(\) will return the default value.|
|set\_allocated\_row1\(\)|void| [RotationMatrixRow](RotationMatrixRow.md#) \*|Sets the [RotationMatrixRow](RotationMatrixRow.md#) object to the field and frees the previous field value if it exists. If the [RotationMatrixRow](RotationMatrixRow.md#) pointer is not NULL, the message takes ownership of the allocated [RotationMatrixRow](RotationMatrixRow.md#) object and has\_ [RotationMatrixRow](RotationMatrixRow.md#)\(\) will return true. Otherwise, if the row1 is NULL, the behavior is the same as calling clear\_row1\(\).|
|release\_row1\(\)| [RotationMatrixRow](RotationMatrixRow.md#) \*|void|Releases the ownership of the field and returns the pointer of the [RotationMatrixRow](RotationMatrixRow.md#) object. After calling this, caller takes the ownership of the allocated [RotationMatrixRow](RotationMatrixRow.md#) object, has\_row1\(\) will return false, and row1\(\) will return the default value.|
|has\_row2\(\) const|bool|void|Returns true if row2 is set.|
|row2\(\)|const [RotationMatrixRow](RotationMatrixRow.md#)&|void|Returns the current value of row2. If row2 is not set, returns a [RotationMatrixRow](RotationMatrixRow.md#) with none of its fields set \(possibly row2::default\_instance\(\)\).|
|mutable\_row2\(\)| [RotationMatrixRow](RotationMatrixRow.md#) \*|void|Returns a pointer to the mutable [RotationMatrixRow](RotationMatrixRow.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [RotationMatrixRow](RotationMatrixRow.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [RotationMatrixRow](RotationMatrixRow.md#)\). After calling this, has\_row2\(\) will return true and row2\(\) will return a reference to the same instance of [RotationMatrixRow](RotationMatrixRow.md#).|
|clear\_row2\(\)|void|void|Clears the value of the field. After calling this, has\_row2\(\) will return false and row2\(\) will return the default value.|
|set\_allocated\_row2\(\)|void| [RotationMatrixRow](RotationMatrixRow.md#) \*|Sets the [RotationMatrixRow](RotationMatrixRow.md#) object to the field and frees the previous field value if it exists. If the [RotationMatrixRow](RotationMatrixRow.md#) pointer is not NULL, the message takes ownership of the allocated [RotationMatrixRow](RotationMatrixRow.md#) object and has\_ [RotationMatrixRow](RotationMatrixRow.md#)\(\) will return true. Otherwise, if the row2 is NULL, the behavior is the same as calling clear\_row2\(\).|
|release\_row2\(\)| [RotationMatrixRow](RotationMatrixRow.md#) \*|void|Releases the ownership of the field and returns the pointer of the [RotationMatrixRow](RotationMatrixRow.md#) object. After calling this, caller takes the ownership of the allocated [RotationMatrixRow](RotationMatrixRow.md#) object, has\_row2\(\) will return false, and row2\(\) will return the default value.|
|has\_row3\(\) const|bool|void|Returns true if row3 is set.|
|row3\(\)|const [RotationMatrixRow](RotationMatrixRow.md#)&|void|Returns the current value of row3. If row3 is not set, returns a [RotationMatrixRow](RotationMatrixRow.md#) with none of its fields set \(possibly row3::default\_instance\(\)\).|
|mutable\_row3\(\)| [RotationMatrixRow](RotationMatrixRow.md#) \*|void|Returns a pointer to the mutable [RotationMatrixRow](RotationMatrixRow.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [RotationMatrixRow](RotationMatrixRow.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [RotationMatrixRow](RotationMatrixRow.md#)\). After calling this, has\_row3\(\) will return true and row3\(\) will return a reference to the same instance of [RotationMatrixRow](RotationMatrixRow.md#).|
|clear\_row3\(\)|void|void|Clears the value of the field. After calling this, has\_row3\(\) will return false and row3\(\) will return the default value.|
|set\_allocated\_row3\(\)|void| [RotationMatrixRow](RotationMatrixRow.md#) \*|Sets the [RotationMatrixRow](RotationMatrixRow.md#) object to the field and frees the previous field value if it exists. If the [RotationMatrixRow](RotationMatrixRow.md#) pointer is not NULL, the message takes ownership of the allocated [RotationMatrixRow](RotationMatrixRow.md#) object and has\_ [RotationMatrixRow](RotationMatrixRow.md#)\(\) will return true. Otherwise, if the row3 is NULL, the behavior is the same as calling clear\_row3\(\).|
|release\_row3\(\)| [RotationMatrixRow](RotationMatrixRow.md#) \*|void|Releases the ownership of the field and returns the pointer of the [RotationMatrixRow](RotationMatrixRow.md#) object. After calling this, caller takes the ownership of the allocated [RotationMatrixRow](RotationMatrixRow.md#) object, has\_row3\(\) will return false, and row3\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

