# Message ActionList

This page describes the C++ Kinova::Api::Base::ActionList message.

## Overview / Purpose

Array of actions

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|action\_list|Collection of [Action](msg_Base_Action.md#)|Action|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|action\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|action\_list\(\) const|const [Action](msg_Base_Action.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, action\_list\_size\(\)\) yields undefined behavior.|
|mutable\_action\_list\(\)| [Action](msg_Base_Action.md#)\*|int index|Returns a pointer to the mutable [Action](msg_Base_Action.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, action\_list\_size\(\)\) yields undefined behavior.|
|add\_action\_list\(\)| [Action](msg_Base_Action.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Action](msg_Base_Action.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Action](msg_Base_Action.md#)\).|
|clear\_action\_list\(\)|void|void|Removes all elements from the field. After calling this, action\_list\_size\(\) will return zero.|
|action\_list\(\) const|const RepeatedPtrField< [Action](msg_Base_Action.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_action\_list\(\)|RepeatedPtrField< [Action](msg_Base_Action.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

