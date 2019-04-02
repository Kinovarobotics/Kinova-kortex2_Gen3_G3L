# Message MappingList

This page describes the C++ Kinova::Api::Base::MappingList message.

## Overview / Purpose

Array of mappings

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|mappings|Collection of [Mapping](msg_Base_Mapping.md#)|Mapping|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|mappings\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|mappings\(\) const|const [Mapping](msg_Base_Mapping.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, mappings\_size\(\)\) yields undefined behavior.|
|mutable\_mappings\(\)| [Mapping](msg_Base_Mapping.md#)\*|int index|Returns a pointer to the mutable [Mapping](msg_Base_Mapping.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, mappings\_size\(\)\) yields undefined behavior.|
|add\_mappings\(\)| [Mapping](msg_Base_Mapping.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Mapping](msg_Base_Mapping.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Mapping](msg_Base_Mapping.md#)\).|
|clear\_mappings\(\)|void|void|Removes all elements from the field. After calling this, mappings\_size\(\) will return zero.|
|mappings\(\) const|const RepeatedPtrField< [Mapping](msg_Base_Mapping.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_mappings\(\)|RepeatedPtrField< [Mapping](msg_Base_Mapping.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

