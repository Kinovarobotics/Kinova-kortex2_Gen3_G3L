# class ExtrinsicParameters

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|rotation| [RotationMatrix](RotationMatrix.md#)|The rotation matrix from depth sensor reference frame to color sensor reference frame|
|translation| [TranslationVector](TranslationVector.md#)|The translation vector from depth sensor reference frame to color sensor reference frame|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_rotation\(\) const|bool|void|Returns true if rotation is set.|
|rotation\(\)|const [RotationMatrix](RotationMatrix.md#)&|void|Returns the current value of rotation. If rotation is not set, returns a [RotationMatrix](RotationMatrix.md#) with none of its fields set \(possibly rotation::default\_instance\(\)\).|
|mutable\_rotation\(\)| [RotationMatrix](RotationMatrix.md#) \*|void|Returns a pointer to the mutable [RotationMatrix](RotationMatrix.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [RotationMatrix](RotationMatrix.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [RotationMatrix](RotationMatrix.md#)\). After calling this, has\_rotation\(\) will return true and rotation\(\) will return a reference to the same instance of [RotationMatrix](RotationMatrix.md#).|
|clear\_rotation\(\)|void|void|Clears the value of the field. After calling this, has\_rotation\(\) will return false and rotation\(\) will return the default value.|
|set\_allocated\_rotation\(\)|void| [RotationMatrix](RotationMatrix.md#) \*|Sets the [RotationMatrix](RotationMatrix.md#) object to the field and frees the previous field value if it exists. If the [RotationMatrix](RotationMatrix.md#) pointer is not NULL, the message takes ownership of the allocated [RotationMatrix](RotationMatrix.md#) object and has\_ [RotationMatrix](RotationMatrix.md#)\(\) will return true. Otherwise, if the rotation is NULL, the behavior is the same as calling clear\_rotation\(\).|
|release\_rotation\(\)| [RotationMatrix](RotationMatrix.md#) \*|void|Releases the ownership of the field and returns the pointer of the [RotationMatrix](RotationMatrix.md#) object. After calling this, caller takes the ownership of the allocated [RotationMatrix](RotationMatrix.md#) object, has\_rotation\(\) will return false, and rotation\(\) will return the default value.|
|has\_translation\(\) const|bool|void|Returns true if translation is set.|
|translation\(\)|const [TranslationVector](TranslationVector.md#)&|void|Returns the current value of translation. If translation is not set, returns a [TranslationVector](TranslationVector.md#) with none of its fields set \(possibly translation::default\_instance\(\)\).|
|mutable\_translation\(\)| [TranslationVector](TranslationVector.md#) \*|void|Returns a pointer to the mutable [TranslationVector](TranslationVector.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [TranslationVector](TranslationVector.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [TranslationVector](TranslationVector.md#)\). After calling this, has\_translation\(\) will return true and translation\(\) will return a reference to the same instance of [TranslationVector](TranslationVector.md#).|
|clear\_translation\(\)|void|void|Clears the value of the field. After calling this, has\_translation\(\) will return false and translation\(\) will return the default value.|
|set\_allocated\_translation\(\)|void| [TranslationVector](TranslationVector.md#) \*|Sets the [TranslationVector](TranslationVector.md#) object to the field and frees the previous field value if it exists. If the [TranslationVector](TranslationVector.md#) pointer is not NULL, the message takes ownership of the allocated [TranslationVector](TranslationVector.md#) object and has\_ [TranslationVector](TranslationVector.md#)\(\) will return true. Otherwise, if the translation is NULL, the behavior is the same as calling clear\_translation\(\).|
|release\_translation\(\)| [TranslationVector](TranslationVector.md#) \*|void|Releases the ownership of the field and returns the pointer of the [TranslationVector](TranslationVector.md#) object. After calling this, caller takes the ownership of the allocated [TranslationVector](TranslationVector.md#) object, has\_translation\(\) will return false, and translation\(\) will return the default value.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

