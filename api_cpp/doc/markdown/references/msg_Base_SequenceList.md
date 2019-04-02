# Message SequenceList

This page describes the C++ Kinova::Api::Base::SequenceList message.

## Overview / Purpose

Array of sequences

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sequence\_list|Collection of [Sequence](msg_Base_Sequence.md#)|Sequence|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sequence\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|sequence\_list\(\) const|const [Sequence](msg_Base_Sequence.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_list\_size\(\)\) yields undefined behavior.|
|mutable\_sequence\_list\(\)| [Sequence](msg_Base_Sequence.md#)\*|int index|Returns a pointer to the mutable [Sequence](msg_Base_Sequence.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, sequence\_list\_size\(\)\) yields undefined behavior.|
|add\_sequence\_list\(\)| [Sequence](msg_Base_Sequence.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Sequence](msg_Base_Sequence.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Sequence](msg_Base_Sequence.md#)\).|
|clear\_sequence\_list\(\)|void|void|Removes all elements from the field. After calling this, sequence\_list\_size\(\) will return zero.|
|sequence\_list\(\) const|const RepeatedPtrField< [Sequence](msg_Base_Sequence.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_sequence\_list\(\)|RepeatedPtrField< [Sequence](msg_Base_Sequence.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

