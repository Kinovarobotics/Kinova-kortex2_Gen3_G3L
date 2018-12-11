# Message MapList

This page describes the C++ Kinova::Api::Base::MapList message.

## Overview / Purpose

Array of maps

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|map\_list| [Map](msg_Base_Map.md#)|map|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|map\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|map\_list\(\) const|const [Map](msg_Base_Map.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, map\_list\_size\(\)\) yields undefined behavior.|
|mutable\_map\_list\(\)| [Map](msg_Base_Map.md#)\*|int index|Returns a pointer to the mutable [Map](msg_Base_Map.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, map\_list\_size\(\)\) yields undefined behavior.|
|add\_map\_list\(\)| [Map](msg_Base_Map.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Map](msg_Base_Map.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Map](msg_Base_Map.md#)\).|
|clear\_map\_list\(\)|void|void|Removes all elements from the field. After calling this, map\_list\_size\(\) will return zero.|
|map\_list\(\) const|const RepeatedPtrField< [Map](msg_Base_Map.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_map\_list\(\)|RepeatedPtrField< [Map](msg_Base_Map.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

