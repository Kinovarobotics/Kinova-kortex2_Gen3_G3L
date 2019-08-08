# class WifiInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|ssid| [Ssid](Ssid.md#)|SSID|
|security\_type|uint32|Wi-Fi security type|
|encryption\_type|uint32|Wi-Fi encryption type|
|signal\_quality|uint32|Wi-Fi signal quality|
|signal\_strength|int32|Wi-Fi signal power in dBm|
|frequency|uint32|Wi-Fi operating frequency \(channel\) in MHz|
|channel|uint32|Wi-Fi operating channel|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_ssid\(\) const|bool|void|Returns true if ssid is set.|
|ssid\(\)|const [Ssid](Ssid.md#)&|void|Returns the current value of ssid. If ssid is not set, returns a [Ssid](Ssid.md#) with none of its fields set \(possibly ssid::default\_instance\(\)\).|
|mutable\_ssid\(\)| [Ssid](Ssid.md#) \*|void|Returns a pointer to the mutable [Ssid](Ssid.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Ssid](Ssid.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Ssid](Ssid.md#)\). After calling this, has\_ssid\(\) will return true and ssid\(\) will return a reference to the same instance of [Ssid](Ssid.md#).|
|clear\_ssid\(\)|void|void|Clears the value of the field. After calling this, has\_ssid\(\) will return false and ssid\(\) will return the default value.|
|set\_allocated\_ssid\(\)|void| [Ssid](Ssid.md#) \*|Sets the [Ssid](Ssid.md#) object to the field and frees the previous field value if it exists. If the [Ssid](Ssid.md#) pointer is not NULL, the message takes ownership of the allocated [Ssid](Ssid.md#) object and has\_ [Ssid](Ssid.md#)\(\) will return true. Otherwise, if the ssid is NULL, the behavior is the same as calling clear\_ssid\(\).|
|release\_ssid\(\)| [Ssid](Ssid.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Ssid](Ssid.md#) object. After calling this, caller takes the ownership of the allocated [Ssid](Ssid.md#) object, has\_ssid\(\) will return false, and ssid\(\) will return the default value.|
|security\_type\(\)|uint32|void|Returns the current value of security\_type. If the security\_type is not set, returns 0.|
|set\_security\_type\(\)|void|uint32|Sets the value of security\_type. After calling this, security\_type\(\) will return value.|
|clear\_security\_type\(\)|void|void|Clears the value of security\_type. After calling this, security\_type\(\) will return 0.|
|encryption\_type\(\)|uint32|void|Returns the current value of encryption\_type. If the encryption\_type is not set, returns 0.|
|set\_encryption\_type\(\)|void|uint32|Sets the value of encryption\_type. After calling this, encryption\_type\(\) will return value.|
|clear\_encryption\_type\(\)|void|void|Clears the value of encryption\_type. After calling this, encryption\_type\(\) will return 0.|
|signal\_quality\(\) const|uint32|void|Returns the current value of signal\_quality. If the signal\_quality is not set, returns 0.|
|set\_signal\_quality\(\)|void|uint32|Sets the value of signal\_quality. After calling this, signal\_quality\(\) will return value.|
|clear\_signal\_quality\(\)|void|void|Clears the value of signal\_quality. After calling this, signal\_quality\(\) will return the empty string/empty bytes.|
|signal\_strength\(\)|int32|void|Returns the current value of signal\_strength. If the signal\_strength is not set, returns 0.|
|set\_signal\_strength\(\)|void|int32|Sets the value of signal\_strength. After calling this, signal\_strength\(\) will return value.|
|clear\_signal\_strength\(\)|void|void|Clears the value of signal\_strength. After calling this, signal\_strength\(\) will return 0.|
|frequency\(\)|uint32|void|Returns the current value of frequency. If the frequency is not set, returns 0.|
|set\_frequency\(\)|void|uint32|Sets the value of frequency. After calling this, frequency\(\) will return value.|
|clear\_frequency\(\)|void|void|Clears the value of frequency. After calling this, frequency\(\) will return 0.|
|channel\(\)|uint32|void|Returns the current value of channel. If the channel is not set, returns 0.|
|set\_channel\(\)|void|uint32|Sets the value of channel. After calling this, channel\(\) will return value.|
|clear\_channel\(\)|void|void|Clears the value of channel. After calling this, channel\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

