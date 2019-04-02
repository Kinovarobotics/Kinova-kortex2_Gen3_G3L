# Message JointSpeeds

This page describes the C++ Kinova::Api::Base::JointSpeeds message.

## Overview / Purpose

Defines a series of joint speeds

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|joint\_speeds|Collection of [JointSpeed](msg_Base_JointSpeed.md#)|Array of joint speed|
|duration|uint32|Duration constraint. If not 0, allows to set a limit \(in seconds\) common to every joint specified in 'joint\_speeds' \(future\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|joint\_speeds\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|joint\_speeds\(\) const|const [JointSpeed](msg_Base_JointSpeed.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, joint\_speeds\_size\(\)\) yields undefined behavior.|
|mutable\_joint\_speeds\(\)| [JointSpeed](msg_Base_JointSpeed.md#)\*|int index|Returns a pointer to the mutable [JointSpeed](msg_Base_JointSpeed.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, joint\_speeds\_size\(\)\) yields undefined behavior.|
|add\_joint\_speeds\(\)| [JointSpeed](msg_Base_JointSpeed.md#)\*|void|Adds a new element and returns a pointer to it. The returned [JointSpeed](msg_Base_JointSpeed.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [JointSpeed](msg_Base_JointSpeed.md#)\).|
|clear\_joint\_speeds\(\)|void|void|Removes all elements from the field. After calling this, joint\_speeds\_size\(\) will return zero.|
|joint\_speeds\(\) const|const RepeatedPtrField< [JointSpeed](msg_Base_JointSpeed.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_joint\_speeds\(\)|RepeatedPtrField< [JointSpeed](msg_Base_JointSpeed.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|duration\(\)|uint32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|uint32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

