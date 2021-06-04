# class GpioConfigurationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|port\_configurations| [GpioConfiguration](GpioConfiguration.md#)|Port configuration list|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|port\_configurations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|port\_configurations\(\) const|const [GpioConfiguration](GpioConfiguration.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, port\_configurations\_size\(\)\) yields undefined behavior.|
|mutable\_port\_configurations\(\)| [GpioConfiguration](GpioConfiguration.md#)\*|int index|Returns a pointer to the mutable [GpioConfiguration](GpioConfiguration.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, port\_configurations\_size\(\)\) yields undefined behavior.|
|add\_port\_configurations\(\)| [GpioConfiguration](GpioConfiguration.md#)\*|void|Adds a new element and returns a pointer to it. The returned [GpioConfiguration](GpioConfiguration.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [GpioConfiguration](GpioConfiguration.md#)\).|
|clear\_port\_configurations\(\)|void|void|Removes all elements from the field. After calling this, port\_configurations\_size\(\) will return zero.|
|port\_configurations\(\) const|const RepeatedPtrField< [GpioConfiguration](GpioConfiguration.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_port\_configurations\(\)|RepeatedPtrField< [GpioConfiguration](GpioConfiguration.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

