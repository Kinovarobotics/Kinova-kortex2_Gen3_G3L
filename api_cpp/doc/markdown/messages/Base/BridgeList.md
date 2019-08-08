# class BridgeList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|bridgeConfig| [BridgeConfig](BridgeConfig.md#)|List of bridge configuration.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|bridgeConfig\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|bridgeConfig\(\) const|const [BridgeConfig](BridgeConfig.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, bridgeConfig\_size\(\)\) yields undefined behavior.|
|mutable\_bridgeConfig\(\)| [BridgeConfig](BridgeConfig.md#)\*|int index|Returns a pointer to the mutable [BridgeConfig](BridgeConfig.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, bridgeConfig\_size\(\)\) yields undefined behavior.|
|add\_bridgeConfig\(\)| [BridgeConfig](BridgeConfig.md#)\*|void|Adds a new element and returns a pointer to it. The returned [BridgeConfig](BridgeConfig.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [BridgeConfig](BridgeConfig.md#)\).|
|clear\_bridgeConfig\(\)|void|void|Removes all elements from the field. After calling this, bridgeConfig\_size\(\) will return zero.|
|bridgeConfig\(\) const|const RepeatedPtrField< [BridgeConfig](BridgeConfig.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_bridgeConfig\(\)|RepeatedPtrField< [BridgeConfig](BridgeConfig.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

