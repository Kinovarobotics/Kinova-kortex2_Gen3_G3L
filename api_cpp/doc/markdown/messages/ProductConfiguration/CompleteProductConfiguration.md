# class CompleteProductConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|kin|string|Kinova Identification Number of the device|
|model|uint32|Model of the device|
|country\_code| [CountryCode](../Common/CountryCode.md#)|Country code for the device|
|assembly\_plant|string|Assembly plant of the device|
|model\_year|string|Year of the model|
|degree\_of\_freedom|uint32|Number of DOF for the device|
|base\_type|uint32|Type of base for the device|
|end\_effector\_type|uint32|End-effector type of the device|
|vision\_module\_type|uint32|Vision module type of the device|
|interface\_module\_type|uint32|Interface module type of the device|
|arm\_laterality|uint32|Arm laterality of the device|
|wrist\_type|uint32|Wrist type of the device|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|kin\(\)|const string&|void|Returns the current value of kin. If kin is not set, returns the empty string/empty bytes.|
|set\_kin\(\)|void|const string&|Sets the value of kin. After calling this, kin\(\) will return a copy of value.|
|set\_kin\(\)|void|string&&|\(C++11 and beyond\): Sets the value of kin, moving from the passed string. After calling this, kin\(\) will return a copy of value.|
|set\_kin\(\)|void|const char\*|Sets the value of kin using a C-style null-terminated string. After calling this, kin\(\) will return a copy of value.|
|mutable\_kin\(\)|string \*|void|Returns a pointer to the mutable string object that stores kin's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, kin\(\) will return whatever value is written into the given string.|
|clear\_kin\(\)|void|void|Clears the value of kin. After calling this, kin\(\) will return the empty string/empty bytes.|
|set\_allocated\_kin\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_kin\(\).|
|release\_kin\(\)|string \*|void|Releases the ownership of kin and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and kin\(\) will return the empty string/empty bytes.|
|model\(\) const|uint32|void|Returns the current value of model. If the model is not set, returns 0.|
|set\_model\(\)|void|uint32|Sets the value of model. After calling this, model\(\) will return value.|
|clear\_model\(\)|void|void|Clears the value of model. After calling this, model\(\) will return the empty string/empty bytes.|
|has\_country\_code\(\) const|bool|void|Returns true if country\_code is set.|
|country\_code\(\)|const [CountryCode](../Common/CountryCode.md#)&|void|Returns the current value of country\_code. If country\_code is not set, returns a [CountryCode](../Common/CountryCode.md#) with none of its fields set \(possibly country\_code::default\_instance\(\)\).|
|mutable\_country\_code\(\)| [CountryCode](../Common/CountryCode.md#) \*|void|Returns a pointer to the mutable [CountryCode](../Common/CountryCode.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [CountryCode](../Common/CountryCode.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [CountryCode](../Common/CountryCode.md#)\). After calling this, has\_country\_code\(\) will return true and country\_code\(\) will return a reference to the same instance of [CountryCode](../Common/CountryCode.md#).|
|clear\_country\_code\(\)|void|void|Clears the value of the field. After calling this, has\_country\_code\(\) will return false and country\_code\(\) will return the default value.|
|set\_allocated\_country\_code\(\)|void| [CountryCode](../Common/CountryCode.md#) \*|Sets the [CountryCode](../Common/CountryCode.md#) object to the field and frees the previous field value if it exists. If the [CountryCode](../Common/CountryCode.md#) pointer is not NULL, the message takes ownership of the allocated [CountryCode](../Common/CountryCode.md#) object and has\_ [CountryCode](../Common/CountryCode.md#)\(\) will return true. Otherwise, if the country\_code is NULL, the behavior is the same as calling clear\_country\_code\(\).|
|release\_country\_code\(\)| [CountryCode](../Common/CountryCode.md#) \*|void|Releases the ownership of the field and returns the pointer of the [CountryCode](../Common/CountryCode.md#) object. After calling this, caller takes the ownership of the allocated [CountryCode](../Common/CountryCode.md#) object, has\_country\_code\(\) will return false, and country\_code\(\) will return the default value.|
|assembly\_plant\(\)|const string&|void|Returns the current value of assembly\_plant. If assembly\_plant is not set, returns the empty string/empty bytes.|
|set\_assembly\_plant\(\)|void|const string&|Sets the value of assembly\_plant. After calling this, assembly\_plant\(\) will return a copy of value.|
|set\_assembly\_plant\(\)|void|string&&|\(C++11 and beyond\): Sets the value of assembly\_plant, moving from the passed string. After calling this, assembly\_plant\(\) will return a copy of value.|
|set\_assembly\_plant\(\)|void|const char\*|Sets the value of assembly\_plant using a C-style null-terminated string. After calling this, assembly\_plant\(\) will return a copy of value.|
|mutable\_assembly\_plant\(\)|string \*|void|Returns a pointer to the mutable string object that stores assembly\_plant's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, assembly\_plant\(\) will return whatever value is written into the given string.|
|clear\_assembly\_plant\(\)|void|void|Clears the value of assembly\_plant. After calling this, assembly\_plant\(\) will return the empty string/empty bytes.|
|set\_allocated\_assembly\_plant\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_assembly\_plant\(\).|
|release\_assembly\_plant\(\)|string \*|void|Releases the ownership of assembly\_plant and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and assembly\_plant\(\) will return the empty string/empty bytes.|
|model\_year\(\)|const string&|void|Returns the current value of model\_year. If model\_year is not set, returns the empty string/empty bytes.|
|set\_model\_year\(\)|void|const string&|Sets the value of model\_year. After calling this, model\_year\(\) will return a copy of value.|
|set\_model\_year\(\)|void|string&&|\(C++11 and beyond\): Sets the value of model\_year, moving from the passed string. After calling this, model\_year\(\) will return a copy of value.|
|set\_model\_year\(\)|void|const char\*|Sets the value of model\_year using a C-style null-terminated string. After calling this, model\_year\(\) will return a copy of value.|
|mutable\_model\_year\(\)|string \*|void|Returns a pointer to the mutable string object that stores model\_year's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, model\_year\(\) will return whatever value is written into the given string.|
|clear\_model\_year\(\)|void|void|Clears the value of model\_year. After calling this, model\_year\(\) will return the empty string/empty bytes.|
|set\_allocated\_model\_year\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_model\_year\(\).|
|release\_model\_year\(\)|string \*|void|Releases the ownership of model\_year and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and model\_year\(\) will return the empty string/empty bytes.|
|degree\_of\_freedom\(\)|uint32|void|Returns the current value of degree\_of\_freedom. If the degree\_of\_freedom is not set, returns 0.|
|set\_degree\_of\_freedom\(\)|void|uint32|Sets the value of degree\_of\_freedom. After calling this, degree\_of\_freedom\(\) will return value.|
|clear\_degree\_of\_freedom\(\)|void|void|Clears the value of degree\_of\_freedom. After calling this, degree\_of\_freedom\(\) will return 0.|
|base\_type\(\) const|uint32|void|Returns the current value of base\_type. If the base\_type is not set, returns 0.|
|set\_base\_type\(\)|void|uint32|Sets the value of base\_type. After calling this, base\_type\(\) will return value.|
|clear\_base\_type\(\)|void|void|Clears the value of base\_type. After calling this, base\_type\(\) will return the empty string/empty bytes.|
|end\_effector\_type\(\) const|uint32|void|Returns the current value of end\_effector\_type. If the end\_effector\_type is not set, returns 0.|
|set\_end\_effector\_type\(\)|void|uint32|Sets the value of end\_effector\_type. After calling this, end\_effector\_type\(\) will return value.|
|clear\_end\_effector\_type\(\)|void|void|Clears the value of end\_effector\_type. After calling this, end\_effector\_type\(\) will return the empty string/empty bytes.|
|vision\_module\_type\(\) const|uint32|void|Returns the current value of vision\_module\_type. If the vision\_module\_type is not set, returns 0.|
|set\_vision\_module\_type\(\)|void|uint32|Sets the value of vision\_module\_type. After calling this, vision\_module\_type\(\) will return value.|
|clear\_vision\_module\_type\(\)|void|void|Clears the value of vision\_module\_type. After calling this, vision\_module\_type\(\) will return the empty string/empty bytes.|
|interface\_module\_type\(\) const|uint32|void|Returns the current value of interface\_module\_type. If the interface\_module\_type is not set, returns 0.|
|set\_interface\_module\_type\(\)|void|uint32|Sets the value of interface\_module\_type. After calling this, interface\_module\_type\(\) will return value.|
|clear\_interface\_module\_type\(\)|void|void|Clears the value of interface\_module\_type. After calling this, interface\_module\_type\(\) will return the empty string/empty bytes.|
|arm\_laterality\(\) const|uint32|void|Returns the current value of arm\_laterality. If the arm\_laterality is not set, returns 0.|
|set\_arm\_laterality\(\)|void|uint32|Sets the value of arm\_laterality. After calling this, arm\_laterality\(\) will return value.|
|clear\_arm\_laterality\(\)|void|void|Clears the value of arm\_laterality. After calling this, arm\_laterality\(\) will return the empty string/empty bytes.|
|wrist\_type\(\) const|uint32|void|Returns the current value of wrist\_type. If the wrist\_type is not set, returns 0.|
|set\_wrist\_type\(\)|void|uint32|Sets the value of wrist\_type. After calling this, wrist\_type\(\) will return value.|
|clear\_wrist\_type\(\)|void|void|Clears the value of wrist\_type. After calling this, wrist\_type\(\) will return the empty string/empty bytes.|

**Parent topic:** [ProductConfiguration \(C++\)](../../summary_pages/ProductConfiguration.md)

