# class OperatingModeInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|operating\_mode|uint32|Operating mode|
|device\_handle| [DeviceHandle](../Common/DeviceHandle.md#)|Device matching operating mode \(if applicable\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|operating\_mode\(\) const|uint32|void|Returns the current value of operating\_mode. If the operating\_mode is not set, returns 0.|
|set\_operating\_mode\(\)|void|uint32|Sets the value of operating\_mode. After calling this, operating\_mode\(\) will return value.|
|clear\_operating\_mode\(\)|void|void|Clears the value of operating\_mode. After calling this, operating\_mode\(\) will return the empty string/empty bytes.|
|has\_device\_handle\(\) const|bool|void|Returns true if device\_handle is set.|
|device\_handle\(\)|const [DeviceHandle](../Common/DeviceHandle.md#)&|void|Returns the current value of device\_handle. If device\_handle is not set, returns a [DeviceHandle](../Common/DeviceHandle.md#) with none of its fields set \(possibly device\_handle::default\_instance\(\)\).|
|mutable\_device\_handle\(\)| [DeviceHandle](../Common/DeviceHandle.md#) \*|void|Returns a pointer to the mutable [DeviceHandle](../Common/DeviceHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [DeviceHandle](../Common/DeviceHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [DeviceHandle](../Common/DeviceHandle.md#)\). After calling this, has\_device\_handle\(\) will return true and device\_handle\(\) will return a reference to the same instance of [DeviceHandle](../Common/DeviceHandle.md#).|
|clear\_device\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_device\_handle\(\) will return false and device\_handle\(\) will return the default value.|
|set\_allocated\_device\_handle\(\)|void| [DeviceHandle](../Common/DeviceHandle.md#) \*|Sets the [DeviceHandle](../Common/DeviceHandle.md#) object to the field and frees the previous field value if it exists. If the [DeviceHandle](../Common/DeviceHandle.md#) pointer is not NULL, the message takes ownership of the allocated [DeviceHandle](../Common/DeviceHandle.md#) object and has\_ [DeviceHandle](../Common/DeviceHandle.md#)\(\) will return true. Otherwise, if the device\_handle is NULL, the behavior is the same as calling clear\_device\_handle\(\).|
|release\_device\_handle\(\)| [DeviceHandle](../Common/DeviceHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [DeviceHandle](../Common/DeviceHandle.md#) object. After calling this, caller takes the ownership of the allocated [DeviceHandle](../Common/DeviceHandle.md#) object, has\_device\_handle\(\) will return false, and device\_handle\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

