# class WrenchCommand

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|reference\_frame|uint32|The reference frame used for the wrench command|
|mode|uint32|Mode in which the command is executed|
|wrench| [Wrench](Wrench.md#)|Wrench value|
|duration|uint32|Duration constraint. If not 0, allows to set a limit \(in milliseconds\) to the WrenchCommand|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|reference\_frame\(\) const|uint32|void|Returns the current value of reference\_frame. If the reference\_frame is not set, returns 0.|
|set\_reference\_frame\(\)|void|uint32|Sets the value of reference\_frame. After calling this, reference\_frame\(\) will return value.|
|clear\_reference\_frame\(\)|void|void|Clears the value of reference\_frame. After calling this, reference\_frame\(\) will return the empty string/empty bytes.|
|mode\(\) const|uint32|void|Returns the current value of mode. If the mode is not set, returns 0.|
|set\_mode\(\)|void|uint32|Sets the value of mode. After calling this, mode\(\) will return value.|
|clear\_mode\(\)|void|void|Clears the value of mode. After calling this, mode\(\) will return the empty string/empty bytes.|
|has\_wrench\(\) const|bool|void|Returns true if wrench is set.|
|wrench\(\)|const [Wrench](Wrench.md#)&|void|Returns the current value of wrench. If wrench is not set, returns a [Wrench](Wrench.md#) with none of its fields set \(possibly wrench::default\_instance\(\)\).|
|mutable\_wrench\(\)| [Wrench](Wrench.md#) \*|void|Returns a pointer to the mutable [Wrench](Wrench.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Wrench](Wrench.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Wrench](Wrench.md#)\). After calling this, has\_wrench\(\) will return true and wrench\(\) will return a reference to the same instance of [Wrench](Wrench.md#).|
|clear\_wrench\(\)|void|void|Clears the value of the field. After calling this, has\_wrench\(\) will return false and wrench\(\) will return the default value.|
|set\_allocated\_wrench\(\)|void| [Wrench](Wrench.md#) \*|Sets the [Wrench](Wrench.md#) object to the field and frees the previous field value if it exists. If the [Wrench](Wrench.md#) pointer is not NULL, the message takes ownership of the allocated [Wrench](Wrench.md#) object and has\_ [Wrench](Wrench.md#)\(\) will return true. Otherwise, if the wrench is NULL, the behavior is the same as calling clear\_wrench\(\).|
|release\_wrench\(\)| [Wrench](Wrench.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Wrench](Wrench.md#) object. After calling this, caller takes the ownership of the allocated [Wrench](Wrench.md#) object, has\_wrench\(\) will return false, and wrench\(\) will return the default value.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

