# Message JointLimitationValueList

This page describes the C++ Kinova::Api::Base::JointLimitationValueList message.

## Overview / Purpose

List of joint limitations

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_limitation\_values|Collection of [JointLimitationValue](msg_Base_JointLimitationValue.md#)|Joint limitation|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|joint\_limitation\_values\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_limitation\_values\(\) const|const [JointLimitationValue](msg_Base_JointLimitationValue.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_limitation\_values\_size\(\)\) yields undefined behavior.|
|mutable\_joint\_limitation\_values\(\)| [JointLimitationValue](msg_Base_JointLimitationValue.md#)\*|int index|Returns a pointer to the mutable [JointLimitationValue](msg_Base_JointLimitationValue.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, joint\_limitation\_values\_size\(\)\) yields undefined behavior.|
|add\_joint\_limitation\_values\(\)| [JointLimitationValue](msg_Base_JointLimitationValue.md#)\*|void|Adds a new element and returns a pointer to it. The returned [JointLimitationValue](msg_Base_JointLimitationValue.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointLimitationValue](msg_Base_JointLimitationValue.md#)\).|
|clear\_joint\_limitation\_values\(\)|void|void|Removes all elements from the field. After calling this, joint\_limitation\_values\_size\(\) will return zero.|
|joint\_limitation\_values\(\) const|const RepeatedPtrField< [JointLimitationValue](msg_Base_JointLimitationValue.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_limitation\_values\(\)|RepeatedPtrField< [JointLimitationValue](msg_Base_JointLimitationValue.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

