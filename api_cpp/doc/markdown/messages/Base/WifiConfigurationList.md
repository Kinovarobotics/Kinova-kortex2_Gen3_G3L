# class WifiConfigurationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|wifi\_configuration\_list| [WifiConfiguration](WifiConfiguration.md#)|Wi-Fi configurations|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|wifi\_configuration\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|wifi\_configuration\_list\(\) const|const [WifiConfiguration](WifiConfiguration.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, wifi\_configuration\_list\_size\(\)\) yields undefined behavior.|
|mutable\_wifi\_configuration\_list\(\)| [WifiConfiguration](WifiConfiguration.md#)\*|int index|Returns a pointer to the mutable [WifiConfiguration](WifiConfiguration.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, wifi\_configuration\_list\_size\(\)\) yields undefined behavior.|
|add\_wifi\_configuration\_list\(\)| [WifiConfiguration](WifiConfiguration.md#)\*|void|Adds a new element and returns a pointer to it. The returned [WifiConfiguration](WifiConfiguration.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [WifiConfiguration](WifiConfiguration.md#)\).|
|clear\_wifi\_configuration\_list\(\)|void|void|Removes all elements from the field. After calling this, wifi\_configuration\_list\_size\(\) will return zero.|
|wifi\_configuration\_list\(\) const|const RepeatedPtrField< [WifiConfiguration](WifiConfiguration.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_wifi\_configuration\_list\(\)|RepeatedPtrField< [WifiConfiguration](WifiConfiguration.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

