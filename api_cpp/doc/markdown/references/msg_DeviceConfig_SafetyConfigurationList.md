# Message SafetyConfigurationList

This page describes the C++ Kinova::Api::DeviceConfig::SafetyConfigurationList message.

## Overview / Purpose

Array of safety configuration

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|configuration| [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)|Safety configuration|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|configuration\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|configuration\(\) const|const [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, configuration\_size\(\)\) yields undefined behavior.|
|mutable\_configuration\(\)| [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)\*|int index|Returns a pointer to the mutable [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, configuration\_size\(\)\) yields undefined behavior.|
|add\_configuration\(\)| [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)\*|void|Adds a new element and returns a pointer to it. The returned [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)\).|
|clear\_configuration\(\)|void|void|Removes all elements from the field. After calling this, configuration\_size\(\) will return zero.|
|configuration\(\) const|const RepeatedPtrField< [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_configuration\(\)|RepeatedPtrField< [SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

