# Message CustomDataSelection

This page describes the C++ Kinova::Api::ActuatorConfig::CustomDataSelection message.

## Overview / Purpose

Selects a custom data

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|channel|uint32|16 channels maximum|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|channel\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|channel\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, channel\_size\(\)\) yields undefined behavior.|
|set\_channel\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_channel\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_channel\(\)|void|void|Removes all elements from the field. After calling this, channel\_size\(\) will return zero.|
|channel\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_channel\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

