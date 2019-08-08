# class PayloadInformation

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|payload\_mass|float32|Tool mass in kg|
|payload\_mass\_center| [Position](Position.md#)|Tool mass center position relative to the tool reference frame|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|payload\_mass\(\)|float32|void|Returns the current value of payload\_mass. If the payload\_mass is not set, returns 0.|
|set\_payload\_mass\(\)|void|float32|Sets the value of payload\_mass. After calling this, payload\_mass\(\) will return value.|
|clear\_payload\_mass\(\)|void|void|Clears the value of payload\_mass. After calling this, payload\_mass\(\) will return 0.|
|has\_payload\_mass\_center\(\) const|bool|void|Returns true if payload\_mass\_center is set.|
|payload\_mass\_center\(\)|const [Position](Position.md#)&|void|Returns the current value of payload\_mass\_center. If payload\_mass\_center is not set, returns a [Position](Position.md#) with none of its fields set \(possibly payload\_mass\_center::default\_instance\(\)\).|
|mutable\_payload\_mass\_center\(\)| [Position](Position.md#) \*|void|Returns a pointer to the mutable [Position](Position.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Position](Position.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Position](Position.md#)\). After calling this, has\_payload\_mass\_center\(\) will return true and payload\_mass\_center\(\) will return a reference to the same instance of [Position](Position.md#).|
|clear\_payload\_mass\_center\(\)|void|void|Clears the value of the field. After calling this, has\_payload\_mass\_center\(\) will return false and payload\_mass\_center\(\) will return the default value.|
|set\_allocated\_payload\_mass\_center\(\)|void| [Position](Position.md#) \*|Sets the [Position](Position.md#) object to the field and frees the previous field value if it exists. If the [Position](Position.md#) pointer is not NULL, the message takes ownership of the allocated [Position](Position.md#) object and has\_ [Position](Position.md#)\(\) will return true. Otherwise, if the payload\_mass\_center is NULL, the behavior is the same as calling clear\_payload\_mass\_center\(\).|
|release\_payload\_mass\_center\(\)| [Position](Position.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Position](Position.md#) object. After calling this, caller takes the ownership of the allocated [Position](Position.md#) object, has\_payload\_mass\_center\(\) will return false, and payload\_mass\_center\(\) will return the default value.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

