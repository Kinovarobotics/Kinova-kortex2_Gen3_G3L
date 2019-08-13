# class CalibrationParameter

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|calibration\_parameter\_identifier|uint32|Calibration parameter identifier|
|signedIntValue|oneof:value int32|Signed int calibration value.|
|unsignedIntValue|oneof:value uint32|Unsigned int calibration value.|
|floatValue|oneof:value float32|Float calibration value.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|calibration\_parameter\_identifier\(\)|uint32|void|Returns the current value of calibration\_parameter\_identifier. If the calibration\_parameter\_identifier is not set, returns 0.|
|set\_calibration\_parameter\_identifier\(\)|void|uint32|Sets the value of calibration\_parameter\_identifier. After calling this, calibration\_parameter\_identifier\(\) will return value.|
|clear\_calibration\_parameter\_identifier\(\)|void|void|Clears the value of calibration\_parameter\_identifier. After calling this, calibration\_parameter\_identifier\(\) will return 0.|
|set\_signedIntValue\(\)|void|oneof:value int32|If any other oneof field in the same oneof is set, calls clear\_value\(\). Sets the value of this field and sets the oneof case to kSignedIntValue.|
|signedIntValue\(\) const|oneof:value int32|void|Returns the current value of the field if oneof case is kSignedIntValue. Otherwise, returns the default value.|
|clear\_signedIntValue\(\)|void|void|Nothing will be changed if the oneof case is not kSignedIntValue. If the oneof case is kSignedIntValue, clears the value of the field and the oneof case|
|set\_unsignedIntValue\(\)|void|oneof:value uint32|If any other oneof field in the same oneof is set, calls clear\_value\(\). Sets the value of this field and sets the oneof case to kUnsignedIntValue.|
|unsignedIntValue\(\) const|oneof:value uint32|void|Returns the current value of the field if oneof case is kUnsignedIntValue. Otherwise, returns the default value.|
|clear\_unsignedIntValue\(\)|void|void|Nothing will be changed if the oneof case is not kUnsignedIntValue. If the oneof case is kUnsignedIntValue, clears the value of the field and the oneof case|
|set\_floatValue\(\)|void|oneof:value float32|If any other oneof field in the same oneof is set, calls clear\_value\(\). Sets the value of this field and sets the oneof case to kFloatValue.|
|floatValue\(\) const|oneof:value float32|void|Returns the current value of the field if oneof case is kFloatValue. Otherwise, returns the default value.|
|clear\_floatValue\(\)|void|void|Nothing will be changed if the oneof case is not kFloatValue. If the oneof case is kFloatValue, clears the value of the field and the oneof case|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

