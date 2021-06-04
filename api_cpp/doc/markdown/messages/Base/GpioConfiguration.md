# class GpioConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|port\_number|uint32|Port number \(Base extension port is port 0\)|
|pin\_configurations| [GpioPinConfiguration](GpioPinConfiguration.md#)|Pin configuration list|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|port\_number\(\)|uint32|void|Returns the current value of port\_number. If the port\_number is not set, returns 0.|
|set\_port\_number\(\)|void|uint32|Sets the value of port\_number. After calling this, port\_number\(\) will return value.|
|clear\_port\_number\(\)|void|void|Clears the value of port\_number. After calling this, port\_number\(\) will return 0.|
|pin\_configurations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|pin\_configurations\(\) const|const [GpioPinConfiguration](GpioPinConfiguration.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, pin\_configurations\_size\(\)\) yields undefined behavior.|
|mutable\_pin\_configurations\(\)| [GpioPinConfiguration](GpioPinConfiguration.md#)\*|int index|Returns a pointer to the mutable [GpioPinConfiguration](GpioPinConfiguration.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, pin\_configurations\_size\(\)\) yields undefined behavior.|
|add\_pin\_configurations\(\)| [GpioPinConfiguration](GpioPinConfiguration.md#)\*|void|Adds a new element and returns a pointer to it. The returned [GpioPinConfiguration](GpioPinConfiguration.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [GpioPinConfiguration](GpioPinConfiguration.md#)\).|
|clear\_pin\_configurations\(\)|void|void|Removes all elements from the field. After calling this, pin\_configurations\_size\(\) will return zero.|
|pin\_configurations\(\) const|const RepeatedPtrField< [GpioPinConfiguration](GpioPinConfiguration.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_pin\_configurations\(\)|RepeatedPtrField< [GpioPinConfiguration](GpioPinConfiguration.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

