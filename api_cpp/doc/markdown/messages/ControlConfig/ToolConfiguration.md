# class ToolConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|tool\_transform| [CartesianTransform](CartesianTransform.md#)|Cartesian transform tool|
|tool\_mass|float32|Tool mass \(in kg\)|
|tool\_mass\_center| [Position](Position.md#)|Tool mass center position relative to the interface module reference frame|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_tool\_transform\(\) const|bool|void|Returns true if tool\_transform is set.|
|tool\_transform\(\)|const [CartesianTransform](CartesianTransform.md#)&|void|Returns the current value of tool\_transform. If tool\_transform is not set, returns a [CartesianTransform](CartesianTransform.md#) with none of its fields set \(possibly tool\_transform::default\_instance\(\)\).|
|mutable\_tool\_transform\(\)| [CartesianTransform](CartesianTransform.md#) \*|void|Returns a pointer to the mutable [CartesianTransform](CartesianTransform.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [CartesianTransform](CartesianTransform.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianTransform](CartesianTransform.md#)\). After calling this, has\_tool\_transform\(\) will return true and tool\_transform\(\) will return a reference to the same instance of [CartesianTransform](CartesianTransform.md#).|
|clear\_tool\_transform\(\)|void|void|Clears the value of the field. After calling this, has\_tool\_transform\(\) will return false and tool\_transform\(\) will return the default value.|
|set\_allocated\_tool\_transform\(\)|void| [CartesianTransform](CartesianTransform.md#) \*|Sets the [CartesianTransform](CartesianTransform.md#) object to the field and frees the previous field value if it exists. If the [CartesianTransform](CartesianTransform.md#) pointer is not NULL, the message takes ownership of the allocated [CartesianTransform](CartesianTransform.md#) object and has\_ [CartesianTransform](CartesianTransform.md#)\(\) will return true. Otherwise, if the tool\_transform is NULL, the behavior is the same as calling clear\_tool\_transform\(\).|
|release\_tool\_transform\(\)| [CartesianTransform](CartesianTransform.md#) \*|void|Releases the ownership of the field and returns the pointer of the [CartesianTransform](CartesianTransform.md#) object. After calling this, caller takes the ownership of the allocated [CartesianTransform](CartesianTransform.md#) object, has\_tool\_transform\(\) will return false, and tool\_transform\(\) will return the default value.|
|tool\_mass\(\)|float32|void|Returns the current value of tool\_mass. If the tool\_mass is not set, returns 0.|
|set\_tool\_mass\(\)|void|float32|Sets the value of tool\_mass. After calling this, tool\_mass\(\) will return value.|
|clear\_tool\_mass\(\)|void|void|Clears the value of tool\_mass. After calling this, tool\_mass\(\) will return 0.|
|has\_tool\_mass\_center\(\) const|bool|void|Returns true if tool\_mass\_center is set.|
|tool\_mass\_center\(\)|const [Position](Position.md#)&|void|Returns the current value of tool\_mass\_center. If tool\_mass\_center is not set, returns a [Position](Position.md#) with none of its fields set \(possibly tool\_mass\_center::default\_instance\(\)\).|
|mutable\_tool\_mass\_center\(\)| [Position](Position.md#) \*|void|Returns a pointer to the mutable [Position](Position.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Position](Position.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Position](Position.md#)\). After calling this, has\_tool\_mass\_center\(\) will return true and tool\_mass\_center\(\) will return a reference to the same instance of [Position](Position.md#).|
|clear\_tool\_mass\_center\(\)|void|void|Clears the value of the field. After calling this, has\_tool\_mass\_center\(\) will return false and tool\_mass\_center\(\) will return the default value.|
|set\_allocated\_tool\_mass\_center\(\)|void| [Position](Position.md#) \*|Sets the [Position](Position.md#) object to the field and frees the previous field value if it exists. If the [Position](Position.md#) pointer is not NULL, the message takes ownership of the allocated [Position](Position.md#) object and has\_ [Position](Position.md#)\(\) will return true. Otherwise, if the tool\_mass\_center is NULL, the behavior is the same as calling clear\_tool\_mass\_center\(\).|
|release\_tool\_mass\_center\(\)| [Position](Position.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Position](Position.md#) object. After calling this, caller takes the ownership of the allocated [Position](Position.md#) object, has\_tool\_mass\_center\(\) will return false, and tool\_mass\_center\(\) will return the default value.|

**Parent topic:** [ControlConfig \(C++\)](../../summary_pages/ControlConfig.md)

