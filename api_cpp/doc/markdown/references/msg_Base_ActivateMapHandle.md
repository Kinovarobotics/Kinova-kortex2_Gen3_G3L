# Message ActivateMapHandle

This page describes the C++ Kinova::Api::Base::ActivateMapHandle message.

## Overview / Purpose

Specifies a new active map for the specified mapping and map group

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mapping\_handle| [MappingHandle](msg_Base_MappingHandle.md#)|Mapping that the active map is asked for|
|map\_group\_handle| [MapGroupHandle](msg_Base_MapGroupHandle.md#)|Map group that the active map is asked for \(future\)|
|map\_handle| [MapHandle](msg_Base_MapHandle.md#)|New active map|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_mapping\_handle\(\) const|bool|void|Returns true if mapping\_handle is set.|
|mapping\_handle\(\)|const [MappingHandle](msg_Base_MappingHandle.md#)&|void|Returns the current value of mapping\_handle. If mapping\_handle is not set, returns a [MappingHandle](msg_Base_MappingHandle.md#) with none of its fields set \(possibly mapping\_handle::default\_instance\(\)\).|
|mutable\_mapping\_handle\(\)| [MappingHandle](msg_Base_MappingHandle.md#) \*|void|Returns a pointer to the mutable [MappingHandle](msg_Base_MappingHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MappingHandle](msg_Base_MappingHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MappingHandle](msg_Base_MappingHandle.md#)\). After calling this, has\_mapping\_handle\(\) will return true and mapping\_handle\(\) will return a reference to the same instance of [MappingHandle](msg_Base_MappingHandle.md#).|
|clear\_mapping\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_mapping\_handle\(\) will return false and mapping\_handle\(\) will return the default value.|
|set\_allocated\_mapping\_handle\(\)|void| [MappingHandle](msg_Base_MappingHandle.md#) \*|Sets the [MappingHandle](msg_Base_MappingHandle.md#) object to the field and frees the previous field value if it exists. If the [MappingHandle](msg_Base_MappingHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MappingHandle](msg_Base_MappingHandle.md#) object and has\_ [MappingHandle](msg_Base_MappingHandle.md#)\(\) will return true. Otherwise, if the mapping\_handle is NULL, the behavior is the same as calling clear\_mapping\_handle\(\).|
|release\_mapping\_handle\(\)| [MappingHandle](msg_Base_MappingHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MappingHandle](msg_Base_MappingHandle.md#) object. After calling this, caller takes the ownership of the allocated [MappingHandle](msg_Base_MappingHandle.md#) object, has\_mapping\_handle\(\) will return false, and mapping\_handle\(\) will return the default value.|
|has\_map\_group\_handle\(\) const|bool|void|Returns true if map\_group\_handle is set.|
|map\_group\_handle\(\)|const [MapGroupHandle](msg_Base_MapGroupHandle.md#)&|void|Returns the current value of map\_group\_handle. If map\_group\_handle is not set, returns a [MapGroupHandle](msg_Base_MapGroupHandle.md#) with none of its fields set \(possibly map\_group\_handle::default\_instance\(\)\).|
|mutable\_map\_group\_handle\(\)| [MapGroupHandle](msg_Base_MapGroupHandle.md#) \*|void|Returns a pointer to the mutable [MapGroupHandle](msg_Base_MapGroupHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapGroupHandle](msg_Base_MapGroupHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapGroupHandle](msg_Base_MapGroupHandle.md#)\). After calling this, has\_map\_group\_handle\(\) will return true and map\_group\_handle\(\) will return a reference to the same instance of [MapGroupHandle](msg_Base_MapGroupHandle.md#).|
|clear\_map\_group\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_map\_group\_handle\(\) will return false and map\_group\_handle\(\) will return the default value.|
|set\_allocated\_map\_group\_handle\(\)|void| [MapGroupHandle](msg_Base_MapGroupHandle.md#) \*|Sets the [MapGroupHandle](msg_Base_MapGroupHandle.md#) object to the field and frees the previous field value if it exists. If the [MapGroupHandle](msg_Base_MapGroupHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MapGroupHandle](msg_Base_MapGroupHandle.md#) object and has\_ [MapGroupHandle](msg_Base_MapGroupHandle.md#)\(\) will return true. Otherwise, if the map\_group\_handle is NULL, the behavior is the same as calling clear\_map\_group\_handle\(\).|
|release\_map\_group\_handle\(\)| [MapGroupHandle](msg_Base_MapGroupHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapGroupHandle](msg_Base_MapGroupHandle.md#) object. After calling this, caller takes the ownership of the allocated [MapGroupHandle](msg_Base_MapGroupHandle.md#) object, has\_map\_group\_handle\(\) will return false, and map\_group\_handle\(\) will return the default value.|
|has\_map\_handle\(\) const|bool|void|Returns true if map\_handle is set.|
|map\_handle\(\)|const [MapHandle](msg_Base_MapHandle.md#)&|void|Returns the current value of map\_handle. If map\_handle is not set, returns a [MapHandle](msg_Base_MapHandle.md#) with none of its fields set \(possibly map\_handle::default\_instance\(\)\).|
|mutable\_map\_handle\(\)| [MapHandle](msg_Base_MapHandle.md#) \*|void|Returns a pointer to the mutable [MapHandle](msg_Base_MapHandle.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MapHandle](msg_Base_MapHandle.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MapHandle](msg_Base_MapHandle.md#)\). After calling this, has\_map\_handle\(\) will return true and map\_handle\(\) will return a reference to the same instance of [MapHandle](msg_Base_MapHandle.md#).|
|clear\_map\_handle\(\)|void|void|Clears the value of the field. After calling this, has\_map\_handle\(\) will return false and map\_handle\(\) will return the default value.|
|set\_allocated\_map\_handle\(\)|void| [MapHandle](msg_Base_MapHandle.md#) \*|Sets the [MapHandle](msg_Base_MapHandle.md#) object to the field and frees the previous field value if it exists. If the [MapHandle](msg_Base_MapHandle.md#) pointer is not NULL, the message takes ownership of the allocated [MapHandle](msg_Base_MapHandle.md#) object and has\_ [MapHandle](msg_Base_MapHandle.md#)\(\) will return true. Otherwise, if the map\_handle is NULL, the behavior is the same as calling clear\_map\_handle\(\).|
|release\_map\_handle\(\)| [MapHandle](msg_Base_MapHandle.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MapHandle](msg_Base_MapHandle.md#) object. After calling this, caller takes the ownership of the allocated [MapHandle](msg_Base_MapHandle.md#) object, has\_map\_handle\(\) will return false, and map\_handle\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

