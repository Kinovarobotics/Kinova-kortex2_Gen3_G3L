# Message SafetyInformationList

This page describes the C++ Kinova::Api::DeviceConfig::SafetyInformationList message.

## Overview / Purpose

Array of safety information

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|information| [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)| |

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|information\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|information\(\) const|const [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, information\_size\(\)\) yields undefined behavior.|
|mutable\_information\(\)| [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)\*|int index|Returns a pointer to the mutable [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, information\_size\(\)\) yields undefined behavior.|
|add\_information\(\)| [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)\*|void|Adds a new element and returns a pointer to it. The returned [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)\).|
|clear\_information\(\)|void|void|Removes all elements from the field. After calling this, information\_size\(\) will return zero.|
|information\(\) const|const RepeatedPtrField< [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_information\(\)|RepeatedPtrField< [SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [DeviceConfig](../references/summary_DeviceConfig.md)

