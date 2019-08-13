# class SafetyConfigurationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|configuration| [SafetyConfiguration](SafetyConfiguration.md#)|Safety configuration|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|configuration\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|configuration\(\) const|const [SafetyConfiguration](SafetyConfiguration.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, configuration\_size\(\)\) yields undefined behavior.|
|mutable\_configuration\(\)| [SafetyConfiguration](SafetyConfiguration.md#)\*|int index|Returns a pointer to the mutable [SafetyConfiguration](SafetyConfiguration.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, configuration\_size\(\)\) yields undefined behavior.|
|add\_configuration\(\)| [SafetyConfiguration](SafetyConfiguration.md#)\*|void|Adds a new element and returns a pointer to it. The returned [SafetyConfiguration](SafetyConfiguration.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyConfiguration](SafetyConfiguration.md#)\).|
|clear\_configuration\(\)|void|void|Removes all elements from the field. After calling this, configuration\_size\(\) will return zero.|
|configuration\(\) const|const RepeatedPtrField< [SafetyConfiguration](SafetyConfiguration.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_configuration\(\)|RepeatedPtrField< [SafetyConfiguration](SafetyConfiguration.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [DeviceConfig \(C++\)](../../summary_pages/DeviceConfig.md)

