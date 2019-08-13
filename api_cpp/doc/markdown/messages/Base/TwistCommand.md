# class TwistCommand

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|reference\_frame|uint32|The reference frame used for the twist command|
|twist| [Twist](Twist.md#)|Twist value|
|duration|uint32|Duration constrant. If not 0, allows to set a limit \(in milliseconds\) to the TwistCommand \(not implemented yet\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|reference\_frame\(\) const|uint32|void|Returns the current value of reference\_frame. If the reference\_frame is not set, returns 0.|
|set\_reference\_frame\(\)|void|uint32|Sets the value of reference\_frame. After calling this, reference\_frame\(\) will return value.|
|clear\_reference\_frame\(\)|void|void|Clears the value of reference\_frame. After calling this, reference\_frame\(\) will return the empty string/empty bytes.|
|has\_twist\(\) const|bool|void|Returns true if twist is set.|
|twist\(\)|const [Twist](Twist.md#)&|void|Returns the current value of twist. If twist is not set, returns a [Twist](Twist.md#) with none of its fields set \(possibly twist::default\_instance\(\)\).|
|mutable\_twist\(\)| [Twist](Twist.md#) \*|void|Returns a pointer to the mutable [Twist](Twist.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Twist](Twist.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Twist](Twist.md#)\). After calling this, has\_twist\(\) will return true and twist\(\) will return a reference to the same instance of [Twist](Twist.md#).|
|clear\_twist\(\)|void|void|Clears the value of the field. After calling this, has\_twist\(\) will return false and twist\(\) will return the default value.|
|set\_allocated\_twist\(\)|void| [Twist](Twist.md#) \*|Sets the [Twist](Twist.md#) object to the field and frees the previous field value if it exists. If the [Twist](Twist.md#) pointer is not NULL, the message takes ownership of the allocated [Twist](Twist.md#) object and has\_ [Twist](Twist.md#)\(\) will return true. Otherwise, if the twist is NULL, the behavior is the same as calling clear\_twist\(\).|
|release\_twist\(\)| [Twist](Twist.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Twist](Twist.md#) object. After calling this, caller takes the ownership of the allocated [Twist](Twist.md#) object, has\_twist\(\) will return false, and twist\(\) will return the default value.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

