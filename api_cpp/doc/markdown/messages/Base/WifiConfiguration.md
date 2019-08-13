# class WifiConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|ssid| [Ssid](Ssid.md#)|SSID|
|security\_key|string|Security key to used when connecting to Wi-Fi network|
|connect\_automatically|bool|Connection mode. Set to true so robot automatically connects to this Wi-Fi network at bootup, false otherwise|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_ssid\(\) const|bool|void|Returns true if ssid is set.|
|ssid\(\)|const [Ssid](Ssid.md#)&|void|Returns the current value of ssid. If ssid is not set, returns a [Ssid](Ssid.md#) with none of its fields set \(possibly ssid::default\_instance\(\)\).|
|mutable\_ssid\(\)| [Ssid](Ssid.md#) \*|void|Returns a pointer to the mutable [Ssid](Ssid.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Ssid](Ssid.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Ssid](Ssid.md#)\). After calling this, has\_ssid\(\) will return true and ssid\(\) will return a reference to the same instance of [Ssid](Ssid.md#).|
|clear\_ssid\(\)|void|void|Clears the value of the field. After calling this, has\_ssid\(\) will return false and ssid\(\) will return the default value.|
|set\_allocated\_ssid\(\)|void| [Ssid](Ssid.md#) \*|Sets the [Ssid](Ssid.md#) object to the field and frees the previous field value if it exists. If the [Ssid](Ssid.md#) pointer is not NULL, the message takes ownership of the allocated [Ssid](Ssid.md#) object and has\_ [Ssid](Ssid.md#)\(\) will return true. Otherwise, if the ssid is NULL, the behavior is the same as calling clear\_ssid\(\).|
|release\_ssid\(\)| [Ssid](Ssid.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Ssid](Ssid.md#) object. After calling this, caller takes the ownership of the allocated [Ssid](Ssid.md#) object, has\_ssid\(\) will return false, and ssid\(\) will return the default value.|
|security\_key\(\)|const string&|void|Returns the current value of security\_key. If security\_key is not set, returns the empty string/empty bytes.|
|set\_security\_key\(\)|void|const string&|Sets the value of security\_key. After calling this, security\_key\(\) will return a copy of value.|
|set\_security\_key\(\)|void|string&&|\(C++11 and beyond\): Sets the value of security\_key, moving from the passed string. After calling this, security\_key\(\) will return a copy of value.|
|set\_security\_key\(\)|void|const char\*|Sets the value of security\_key using a C-style null-terminated string. After calling this, security\_key\(\) will return a copy of value.|
|mutable\_security\_key\(\)|string \*|void|Returns a pointer to the mutable string object that stores security\_key's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, security\_key\(\) will return whatever value is written into the given string.|
|clear\_security\_key\(\)|void|void|Clears the value of security\_key. After calling this, security\_key\(\) will return the empty string/empty bytes.|
|set\_allocated\_security\_key\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_security\_key\(\).|
|release\_security\_key\(\)|string \*|void|Releases the ownership of security\_key and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and security\_key\(\) will return the empty string/empty bytes.|
|connect\_automatically\(\)|bool|void|Returns the current value of connect\_automatically. If the connect\_automatically is not set, returns 0.|
|set\_connect\_automatically\(\)|void|bool|Sets the value of connect\_automatically. After calling this, connect\_automatically\(\) will return value.|
|clear\_connect\_automatically\(\)|void|void|Clears the value of connect\_automatically. After calling this, connect\_automatically\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

