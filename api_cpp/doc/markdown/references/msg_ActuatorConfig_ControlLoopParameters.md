# Message ControlLoopParameters

This page describes the C++ Kinova::Api::ActuatorConfig::ControlLoopParameters message.

## Overview / Purpose

Defines control loop parameters \(discrete transfer function\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|loop\_selection| [ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|ControlLoopSelection enum|
|error\_saturation|float32|Error saturation value|
|output\_saturation|float32|Output saturation value|
|kAz|float32|KAz \(index 0 to 4\): denominator gains A1 to A5|
|kBz|float32|KBz \(index 0 to 5\): numerator gains B0 to B5|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|loop\_selection\(\) const| [ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|void|Returns the current value of loop\_selection. If the loop\_selection is not set, returns 0.|
|set\_loop\_selection\(\)|void| [ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|Sets the value of loop\_selection. After calling this, loop\_selection\(\) will return value.|
|clear\_loop\_selection\(\)|void|void|Clears the value of loop\_selection. After calling this, loop\_selection\(\) will return the empty string/empty bytes.|
|error\_saturation\(\)|float32|void|Returns the current value of error\_saturation. If the error\_saturation is not set, returns 0.|
|set\_error\_saturation\(\)|void|float32|Sets the value of error\_saturation. After calling this, error\_saturation\(\) will return value.|
|clear\_error\_saturation\(\)|void|void|Clears the value of error\_saturation. After calling this, error\_saturation\(\) will return 0.|
|output\_saturation\(\)|float32|void|Returns the current value of output\_saturation. If the output\_saturation is not set, returns 0.|
|set\_output\_saturation\(\)|void|float32|Sets the value of output\_saturation. After calling this, output\_saturation\(\) will return value.|
|clear\_output\_saturation\(\)|void|void|Clears the value of output\_saturation. After calling this, output\_saturation\(\) will return 0.|
|kAz\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|kAz\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, kAz\_size\(\)\) yields undefined behavior.|
|set\_kAz\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_kAz\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_kAz\(\)|void|void|Removes all elements from the field. After calling this, kAz\_size\(\) will return zero.|
|kAz\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_kAz\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|kBz\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|kBz\(\) const|int|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, kBz\_size\(\)\) yields undefined behavior.|
|set\_kBz\(\)|void|\(int index, int32 value\)|Sets the value of the element at the given zero-based index.|
|add\_kBz\(\)|void|\(int32 value\)|Appends a new element to the field with the given value.|
|clear\_kBz\(\)|void|void|Removes all elements from the field. After calling this, kBz\_size\(\) will return zero.|
|kBz\(\) const|const RepeatedField<int32\>&|void|Returns the underlying RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_kBz\(\)|RepeatedField<int32\>\*|void|Returns a pointer to the underlying mutable RepeatedField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

