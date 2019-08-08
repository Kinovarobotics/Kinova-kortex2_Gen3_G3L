# class ProtectionZone

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [ProtectionZoneHandle](ProtectionZoneHandle.md#)|Protection zone handle|
|name|string|Protection zone friendly name|
|application\_data|string|Application data \(reserved for use by Web App\)|
|is\_enabled|bool|True if protection zone is enabled, false otherwise|
|shape| [ZoneShape](ZoneShape.md#)|Protection zone shape|
|limitations| [CartesianLimitation](CartesianLimitation.md#)|List of Cartesian limitation|
|envelope\_limitations| [CartesianLimitation](CartesianLimitation.md#)|List of Cartesian limitation of the envelop|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [ProtectionZoneHandle](ProtectionZoneHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [ProtectionZoneHandle](ProtectionZoneHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [ProtectionZoneHandle](ProtectionZoneHandle.md#) \*|void|Returns a pointer to the mutable [ProtectionZoneHandle](ProtectionZoneHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ProtectionZoneHandle](ProtectionZoneHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ProtectionZoneHandle](ProtectionZoneHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [ProtectionZoneHandle](ProtectionZoneHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [ProtectionZoneHandle](ProtectionZoneHandle.md#) \*|Sets the [ProtectionZoneHandle](ProtectionZoneHandle.md#) object to the field and frees the previous field value if it exists. If the [ProtectionZoneHandle](ProtectionZoneHandle.md#) pointer is not NULL, the message takes ownership of the allocated [ProtectionZoneHandle](ProtectionZoneHandle.md#) object and has\_ [ProtectionZoneHandle](ProtectionZoneHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [ProtectionZoneHandle](ProtectionZoneHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ProtectionZoneHandle](ProtectionZoneHandle.md#) object. After calling this, caller takes the ownership of the allocated [ProtectionZoneHandle](ProtectionZoneHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
|name\(\)|const string&|void|Returns the current value of name. If name is not set, returns the empty string/empty bytes.|
|set\_name\(\)|void|const string&|Sets the value of name. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|string&&|\(C++11 and beyond\): Sets the value of name, moving from the passed string. After calling this, name\(\) will return a copy of value.|
|set\_name\(\)|void|const char\*|Sets the value of name using a C-style null-terminated string. After calling this, name\(\) will return a copy of value.|
|mutable\_name\(\)|string \*|void|Returns a pointer to the mutable string object that stores name's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, name\(\) will return whatever value is written into the given string.|
|clear\_name\(\)|void|void|Clears the value of name. After calling this, name\(\) will return the empty string/empty bytes.|
|set\_allocated\_name\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_name\(\).|
|release\_name\(\)|string \*|void|Releases the ownership of name and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and name\(\) will return the empty string/empty bytes.|
|application\_data\(\)|const string&|void|Returns the current value of application\_data. If application\_data is not set, returns the empty string/empty bytes.|
|set\_application\_data\(\)|void|const string&|Sets the value of application\_data. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|string&&|\(C++11 and beyond\): Sets the value of application\_data, moving from the passed string. After calling this, application\_data\(\) will return a copy of value.|
|set\_application\_data\(\)|void|const char\*|Sets the value of application\_data using a C-style null-terminated string. After calling this, application\_data\(\) will return a copy of value.|
|mutable\_application\_data\(\)|string \*|void|Returns a pointer to the mutable string object that stores application\_data's value. If the field was not set prior to the call, then the returned string will be empty. After calling this, application\_data\(\) will return whatever value is written into the given string.|
|clear\_application\_data\(\)|void|void|Clears the value of application\_data. After calling this, application\_data\(\) will return the empty string/empty bytes.|
|set\_allocated\_application\_data\(\)|void|string\*|Sets the string object to the field and frees the previous field value if it exists. If the string pointer is not NULL, the message takes ownership of the allocated string object. The message is free to delete the allocated string object at any time, so references to the object may be invalidated. Otherwise, if the value is NULL, the behavior is the same as calling clear\_application\_data\(\).|
|release\_application\_data\(\)|string \*|void|Releases the ownership of application\_data and returns the pointer of the string object. After calling this, caller takes the ownership of the allocated string object and application\_data\(\) will return the empty string/empty bytes.|
|is\_enabled\(\)|bool|void|Returns the current value of is\_enabled. If the is\_enabled is not set, returns 0.|
|set\_is\_enabled\(\)|void|bool|Sets the value of is\_enabled. After calling this, is\_enabled\(\) will return value.|
|clear\_is\_enabled\(\)|void|void|Clears the value of is\_enabled. After calling this, is\_enabled\(\) will return 0.|
|has\_shape\(\) const|bool|void|Returns true if shape is set.|
|shape\(\)|const [ZoneShape](ZoneShape.md#)&|void|Returns the current value of shape. If shape is not set, returns a [ZoneShape](ZoneShape.md#) with none of its fields set \(possibly shape::default\_instance\(\)\).|
|mutable\_shape\(\)| [ZoneShape](ZoneShape.md#) \*|void|Returns a pointer to the mutable [ZoneShape](ZoneShape.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [ZoneShape](ZoneShape.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [ZoneShape](ZoneShape.md#)\). After calling this, has\_shape\(\) will return true and shape\(\) will return a reference to the same instance of [ZoneShape](ZoneShape.md#).|
|clear\_shape\(\)|void|void|Clears the value of the field. After calling this, has\_shape\(\) will return false and shape\(\) will return the default value.|
|set\_allocated\_shape\(\)|void| [ZoneShape](ZoneShape.md#) \*|Sets the [ZoneShape](ZoneShape.md#) object to the field and frees the previous field value if it exists. If the [ZoneShape](ZoneShape.md#) pointer is not NULL, the message takes ownership of the allocated [ZoneShape](ZoneShape.md#) object and has\_ [ZoneShape](ZoneShape.md#)\(\) will return true. Otherwise, if the shape is NULL, the behavior is the same as calling clear\_shape\(\).|
|release\_shape\(\)| [ZoneShape](ZoneShape.md#) \*|void|Releases the ownership of the field and returns the pointer of the [ZoneShape](ZoneShape.md#) object. After calling this, caller takes the ownership of the allocated [ZoneShape](ZoneShape.md#) object, has\_shape\(\) will return false, and shape\(\) will return the default value.|
|limitations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|limitations\(\) const|const [CartesianLimitation](CartesianLimitation.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, limitations\_size\(\)\) yields undefined behavior.|
|mutable\_limitations\(\)| [CartesianLimitation](CartesianLimitation.md#)\*|int index|Returns a pointer to the mutable [CartesianLimitation](CartesianLimitation.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, limitations\_size\(\)\) yields undefined behavior.|
|add\_limitations\(\)| [CartesianLimitation](CartesianLimitation.md#)\*|void|Adds a new element and returns a pointer to it. The returned [CartesianLimitation](CartesianLimitation.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianLimitation](CartesianLimitation.md#)\).|
|clear\_limitations\(\)|void|void|Removes all elements from the field. After calling this, limitations\_size\(\) will return zero.|
|limitations\(\) const|const RepeatedPtrField< [CartesianLimitation](CartesianLimitation.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_limitations\(\)|RepeatedPtrField< [CartesianLimitation](CartesianLimitation.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|envelope\_limitations\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|envelope\_limitations\(\) const|const [CartesianLimitation](CartesianLimitation.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, envelope\_limitations\_size\(\)\) yields undefined behavior.|
|mutable\_envelope\_limitations\(\)| [CartesianLimitation](CartesianLimitation.md#)\*|int index|Returns a pointer to the mutable [CartesianLimitation](CartesianLimitation.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, envelope\_limitations\_size\(\)\) yields undefined behavior.|
|add\_envelope\_limitations\(\)| [CartesianLimitation](CartesianLimitation.md#)\*|void|Adds a new element and returns a pointer to it. The returned [CartesianLimitation](CartesianLimitation.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [CartesianLimitation](CartesianLimitation.md#)\).|
|clear\_envelope\_limitations\(\)|void|void|Removes all elements from the field. After calling this, envelope\_limitations\_size\(\) will return zero.|
|envelope\_limitations\(\) const|const RepeatedPtrField< [CartesianLimitation](CartesianLimitation.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_envelope\_limitations\(\)|RepeatedPtrField< [CartesianLimitation](CartesianLimitation.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

