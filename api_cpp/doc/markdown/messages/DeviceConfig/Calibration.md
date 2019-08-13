# class Calibration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|calibration\_item|uint32|Item to calibrate|
|calibration\_parameter| [CalibrationParameter](CalibrationParameter.md#)|Parameters associated to calibration item|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|calibration\_item\(\) const|uint32|void|Returns the current value of calibration\_item. If the calibration\_item is not set, returns 0.|
|set\_calibration\_item\(\)|void|uint32|Sets the value of calibration\_item. After calling this, calibration\_item\(\) will return value.|
|clear\_calibration\_item\(\)|void|void|Clears the value of calibration\_item. After calling this, calibration\_item\(\) will return the empty string/empty bytes.|
|calibration\_parameter\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|calibration\_parameter\(\) const|const [CalibrationParameter](CalibrationParameter.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, calibration\_parameter\_size\(\)\) yields undefined behavior.|
|mutable\_calibration\_parameter\(\)| [CalibrationParameter](CalibrationParameter.md#)\*|int index|Returns a pointer to the mutable [CalibrationParameter](CalibrationParameter.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, calibration\_parameter\_size\(\)\) yields undefined behavior.|
|add\_calibration\_parameter\(\)| [CalibrationParameter](CalibrationParameter.md#)\*|void|Adds a new element and returns a pointer to it. The returned [CalibrationParameter](CalibrationParameter.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [CalibrationParameter](CalibrationParameter.md#)\).|
|clear\_calibration\_parameter\(\)|void|void|Removes all elements from the field. After calling this, calibration\_parameter\_size\(\) will return zero.|
|calibration\_parameter\(\) const|const RepeatedPtrField< [CalibrationParameter](CalibrationParameter.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_calibration\_parameter\(\)|RepeatedPtrField< [CalibrationParameter](CalibrationParameter.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

