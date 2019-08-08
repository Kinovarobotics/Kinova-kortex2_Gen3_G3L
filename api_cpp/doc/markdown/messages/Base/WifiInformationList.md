# class WifiInformationList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|wifi\_information\_list| [WifiInformation](WifiInformation.md#)|Wi-Fi information|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|wifi\_information\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|wifi\_information\_list\(\) const|const [WifiInformation](WifiInformation.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, wifi\_information\_list\_size\(\)\) yields undefined behavior.|
|mutable\_wifi\_information\_list\(\)| [WifiInformation](WifiInformation.md#)\*|int index|Returns a pointer to the mutable [WifiInformation](WifiInformation.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, wifi\_information\_list\_size\(\)\) yields undefined behavior.|
|add\_wifi\_information\_list\(\)| [WifiInformation](WifiInformation.md#)\*|void|Adds a new element and returns a pointer to it. The returned [WifiInformation](WifiInformation.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [WifiInformation](WifiInformation.md#)\).|
|clear\_wifi\_information\_list\(\)|void|void|Removes all elements from the field. After calling this, wifi\_information\_list\_size\(\) will return zero.|
|wifi\_information\_list\(\) const|const RepeatedPtrField< [WifiInformation](WifiInformation.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_wifi\_information\_list\(\)|RepeatedPtrField< [WifiInformation](WifiInformation.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

