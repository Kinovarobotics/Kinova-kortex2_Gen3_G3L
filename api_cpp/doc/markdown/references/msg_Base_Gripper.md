# Message Gripper

This page describes the C++ Kinova::Api::Base::Gripper message.

## Overview / Purpose

Defines a gripper movement, which is composed of a series of fingers movement

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|finger| [Finger](msg_Base_Finger.md#)|Finger movements|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|finger\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|finger\(\) const|const [Finger](msg_Base_Finger.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, finger\_size\(\)\) yields undefined behavior.|
|mutable\_finger\(\)| [Finger](msg_Base_Finger.md#)\*|int index|Returns a pointer to the mutable [Finger](msg_Base_Finger.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, finger\_size\(\)\) yields undefined behavior.|
|add\_finger\(\)| [Finger](msg_Base_Finger.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Finger](msg_Base_Finger.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Finger](msg_Base_Finger.md#)\).|
|clear\_finger\(\)|void|void|Removes all elements from the field. After calling this, finger\_size\(\) will return zero.|
|finger\(\) const|const RepeatedPtrField< [Finger](msg_Base_Finger.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_finger\(\)|RepeatedPtrField< [Finger](msg_Base_Finger.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

