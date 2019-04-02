# Message ControllerList

This page describes the C++ Kinova::Api::Base::ControllerList message.

## Overview / Purpose

Array of controllers

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|handles|Collection of [ControllerHandle](msg_Base_ControllerHandle.md#)|Controller handle|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|handles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|handles\(\) const|const [ControllerHandle](msg_Base_ControllerHandle.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, handles\_size\(\)\) yields undefined behavior.|
|mutable\_handles\(\)| [ControllerHandle](msg_Base_ControllerHandle.md#)\*|int index|Returns a pointer to the mutable [ControllerHandle](msg_Base_ControllerHandle.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, handles\_size\(\)\) yields undefined behavior.|
|add\_handles\(\)| [ControllerHandle](msg_Base_ControllerHandle.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ControllerHandle](msg_Base_ControllerHandle.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerHandle](msg_Base_ControllerHandle.md#)\).|
|clear\_handles\(\)|void|void|Removes all elements from the field. After calling this, handles\_size\(\) will return zero.|
|handles\(\) const|const RepeatedPtrField< [ControllerHandle](msg_Base_ControllerHandle.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_handles\(\)|RepeatedPtrField< [ControllerHandle](msg_Base_ControllerHandle.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

