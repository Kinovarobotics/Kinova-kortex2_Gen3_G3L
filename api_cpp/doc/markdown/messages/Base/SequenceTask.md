# class SequenceTask

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|group\_identifier|uint32|This field is deprecated and unused. Use task\_index in the SequenceTaskHandle instead.|
|action| [Action](Action.md#)|Specifies the action to execute|
|application\_data|string|Application data \(reserved for use by Web App\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|group\_identifier\(\)|uint32|void|Returns the current value of group\_identifier. If the group\_identifier is not set, returns 0.|
|set\_group\_identifier\(\)|void|uint32|Sets the value of group\_identifier. After calling this, group\_identifier\(\) will return value.|
|clear\_group\_identifier\(\)|void|void|Clears the value of group\_identifier. After calling this, group\_identifier\(\) will return 0.|
|has\_action\(\) const|bool|void|Returns true if action is set.|
|action\(\)|const [Action](Action.md#)&|void|Returns the current value of action. If action is not set, returns a [Action](Action.md#) with none of its fields set \(possibly action::default\_instance\(\)\).|
|mutable\_action\(\)| [Action](Action.md#) \*|void|Returns a pointer to the mutable [Action](Action.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [Action](Action.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [Action](Action.md#)\). After calling this, has\_action\(\) will return true and action\(\) will return a reference to the same instance of [Action](Action.md#).|
|clear\_action\(\)|void|void|Clears the value of the field. After calling this, has\_action\(\) will return false and action\(\) will return the default value.|
|set\_allocated\_action\(\)|void| [Action](Action.md#) \*|Sets the [Action](Action.md#) object to the field and frees the previous field value if it exists. If the [Action](Action.md#) pointer is not NULL, the message takes ownership of the allocated [Action](Action.md#) object and has\_ [Action](Action.md#)\(\) will return true. Otherwise, if the action is NULL, the behavior is the same as calling clear\_action\(\).|
|release\_action\(\)| [Action](Action.md#) \*|void|Releases the ownership of the field and returns the pointer of the [Action](Action.md#) object. After calling this, caller takes the ownership of the allocated [Action](Action.md#) object, has\_action\(\) will return false, and action\(\) will return the default value.|
|application\_data\(\)|const string&|void|Returns the current value of application\_data. If application\_data is not set, returns the empty string/empty bytes.|
|set\_application\_data\(\)|void|const string&|Sets the value of application\_data. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|string&&|\(C++11 and beyond\): Sets the value of application\_data, moving from the passed string. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|const char\*|Sets the value of application\_data using a C-style null-terminated string. After calling this, application\_data\(\) will return a copy of value.|
|mutable\_application\_data\(\)|string \*|void|Returns a pointer to the mutable string object that stores application\_data's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, application\_data\(\) will return whatever value is written into the given string.|
|clear\_application\_data\(\)|void|void|Clears the value of application\_data. After calling this, application\_data\(\) will return the empty string/empty bytes.|
|set\_allocated\_application\_data\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_application\_data\(\).|
|release\_application\_data\(\)|string \*|void|Releases the ownership of application\_data and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and application\_data\(\) will return the empty string/empty bytes.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

