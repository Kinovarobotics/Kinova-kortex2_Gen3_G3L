# Message Sequence

This page describes the C++ Kinova::Api::Base::Sequence message.

## Overview / Purpose

Provides information about a sequence

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handle| [SequenceHandle](msg_Base_SequenceHandle.md#)|Sequence handle|
|name|string|Sequence name|
|application\_data|string|Application data \(reserved for use by Web App\)|
|tasks| [SequenceTask](msg_Base_SequenceTask.md#)|Array of tasks that this sequence contains|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_handle\(\) const|bool|void|Returns true if handle is set.|
|handle\(\)|const [SequenceHandle](msg_Base_SequenceHandle.md#)&|void|Returns the current value of handle. If handle is not set, returns a [SequenceHandle](msg_Base_SequenceHandle.md#) with none of its fields set \(possibly handle::default\_instance\(\)\).|
|mutable\_handle\(\)| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|void|Returns a pointer to the mutable [SequenceHandle](msg_Base_SequenceHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [SequenceHandle](msg_Base_SequenceHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceHandle](msg_Base_SequenceHandle.md#)\). After calling this, has\_handle\(\) will return true and handle\(\) will return a reference to the same instance of [SequenceHandle](msg_Base_SequenceHandle.md#).|
|clear\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_handle\(\) will return false and handle\(\) will return the default value.|
|set\_allocated\_handle\(\)|void| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|Sets the [SequenceHandle](msg_Base_SequenceHandle.md#) object to the field and frees the previous field value if it exists. If the [SequenceHandle](msg_Base_SequenceHandle.md#) pointer is not NULL, the message takes ownership of the allocated [SequenceHandle](msg_Base_SequenceHandle.md#) object and has\_ [SequenceHandle](msg_Base_SequenceHandle.md#)\(\) will return true. Otherwise, if the handle is NULL, the behavior is the same as calling clear\_handle\(\).|
|release\_handle\(\)| [SequenceHandle](msg_Base_SequenceHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [SequenceHandle](msg_Base_SequenceHandle.md#) object. After calling this, caller takes the ownership of the allocated [SequenceHandle](msg_Base_SequenceHandle.md#) object, has\_handle\(\) will return false, and handle\(\) will return the default value.|
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
|tasks\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|tasks\(\) const|const [SequenceTask](msg_Base_SequenceTask.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, tasks\_size\(\)\) yields undefined behavior.|
|mutable\_tasks\(\)| [SequenceTask](msg_Base_SequenceTask.md#)\*|int index|Returns a pointer to the mutable [SequenceTask](msg_Base_SequenceTask.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, tasks\_size\(\)\) yields undefined behavior.|
|add\_tasks\(\)| [SequenceTask](msg_Base_SequenceTask.md#)\*|void|Adds a new element and returns a pointer to it. The returned [SequenceTask](msg_Base_SequenceTask.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [SequenceTask](msg_Base_SequenceTask.md#)\).|
|clear\_tasks\(\)|void|void|Removes all elements from the field. After calling this, tasks\_size\(\) will return zero.|
|tasks\(\) const|const RepeatedPtrField< [SequenceTask](msg_Base_SequenceTask.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_tasks\(\)|RepeatedPtrField< [SequenceTask](msg_Base_SequenceTask.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

