# class ControllerConfigurationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|controller\_configurations| [ControllerConfiguration](ControllerConfiguration.md#)|List of controller configurations|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|controller\_configurations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|controller\_configurations\(\) const|const [ControllerConfiguration](ControllerConfiguration.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, controller\_configurations\_size\(\)\) yields undefined behavior.|
|mutable\_controller\_configurations\(\)| [ControllerConfiguration](ControllerConfiguration.md#)\*|int index|Returns a pointer to the mutable [ControllerConfiguration](ControllerConfiguration.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, controller\_configurations\_size\(\)\) yields undefined behavior.|
|add\_controller\_configurations\(\)| [ControllerConfiguration](ControllerConfiguration.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ControllerConfiguration](ControllerConfiguration.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerConfiguration](ControllerConfiguration.md#)\).|
|clear\_controller\_configurations\(\)|void|void|Removes all elements from the field. After calling this, controller\_configurations\_size\(\) will return zero.|
|controller\_configurations\(\) const|const RepeatedPtrField< [ControllerConfiguration](ControllerConfiguration.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_controller\_configurations\(\)|RepeatedPtrField< [ControllerConfiguration](ControllerConfiguration.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

