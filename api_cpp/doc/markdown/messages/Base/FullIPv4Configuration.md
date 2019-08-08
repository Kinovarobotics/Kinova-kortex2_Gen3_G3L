# class FullIPv4Configuration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [NetworkHandle](NetworkHandle.md#)|Network handle|
|ipv4\_configuration| [IPv4Configuration](IPv4Configuration.md#)|IPv4 configuration|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [NetworkHandle](NetworkHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [NetworkHandle](NetworkHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [NetworkHandle](NetworkHandle.md#) \*|void|Returns a pointer to the mutable [NetworkHandle](NetworkHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [NetworkHandle](NetworkHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [NetworkHandle](NetworkHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [NetworkHandle](NetworkHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [NetworkHandle](NetworkHandle.md#) \*|Sets the [NetworkHandle](NetworkHandle.md#) object to the field and frees the previous field value if it exists. If the [NetworkHandle](NetworkHandle.md#) pointer is not NULL, the message takes ownership of the allocated [NetworkHandle](NetworkHandle.md#) object and has\_ [NetworkHandle](NetworkHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [NetworkHandle](NetworkHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [NetworkHandle](NetworkHandle.md#) object. After calling this, caller takes the ownership of the allocated [NetworkHandle](NetworkHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|has\_ipv4\_configuration\(\) const|bool|void|Returns true if ipv4\_configuration is set.|
|ipv4\_configuration\(\)|const [IPv4Configuration](IPv4Configuration.md#)&|void|Returns the current value of ipv4\_configuration. If ipv4\_configuration is not set, returns a [IPv4Configuration](IPv4Configuration.md#) with none of its fields set \(possibly ipv4\_configuration::default\_instance\(\)\).|
|mutable\_ipv4\_configuration\(\)| [IPv4Configuration](IPv4Configuration.md#) \*|void|Returns a pointer to the mutable [IPv4Configuration](IPv4Configuration.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [IPv4Configuration](IPv4Configuration.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [IPv4Configuration](IPv4Configuration.md#)\). After calling this, has\_ipv4\_configuration\(\) will return true and ipv4\_configuration\(\) will return a reference to the same instance of [IPv4Configuration](IPv4Configuration.md#).|
|clear\_ipv4\_configuration\(\)|void|void|Clears the value of the field. After calling this, has\_ipv4\_configuration\(\) will return false and ipv4\_configuration\(\) will return the default value.|
|set\_allocated\_ipv4\_configuration\(\)|void| [IPv4Configuration](IPv4Configuration.md#) \*|Sets the [IPv4Configuration](IPv4Configuration.md#) object to the field and frees the previous field value if it exists. If the [IPv4Configuration](IPv4Configuration.md#) pointer is not NULL, the message takes ownership of the allocated [IPv4Configuration](IPv4Configuration.md#) object and has\_ [IPv4Configuration](IPv4Configuration.md#)\(\) will return true. Otherwise, if the ipv4\_configuration is NULL, the behavior is the same as calling clear\_ipv4\_configuration\(\).|
|release\_ipv4\_configuration\(\)| [IPv4Configuration](IPv4Configuration.md#) \*|void|Releases the ownership of the field and returns the pointer of the [IPv4Configuration](IPv4Configuration.md#) object. After calling this, caller takes the ownership of the allocated [IPv4Configuration](IPv4Configuration.md#) object, has\_ipv4\_configuration\(\) will return false, and ipv4\_configuration\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

