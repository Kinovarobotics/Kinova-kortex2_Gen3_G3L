# Message DeviceHandles

This page describes the C++ Kinova::Api::DeviceManager::DeviceHandles message.

## Overview / Purpose

List of Device handles

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|device\_handle| [DeviceHandle](msg_Common_DeviceHandle.md#)|Device handle|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|device\_handle\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|device\_handle\(\) const|const [DeviceHandle](msg_Common_DeviceHandle.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, device\_handle\_size\(\)\) yields undefined behavior.|
|mutable\_device\_handle\(\)| [DeviceHandle](msg_Common_DeviceHandle.md#)\*|int index|Returns a pointer to the mutable [DeviceHandle](msg_Common_DeviceHandle.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, device\_handle\_size\(\)\) yields undefined behavior.|
|add\_device\_handle\(\)| [DeviceHandle](msg_Common_DeviceHandle.md#)\*|void|Adds a new element and returns a pointer to it. The returned [DeviceHandle](msg_Common_DeviceHandle.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [DeviceHandle](msg_Common_DeviceHandle.md#)\).|
|clear\_device\_handle\(\)|void|void|Removes all elements from the field. After calling this, device\_handle\_size\(\) will return zero.|
|device\_handle\(\) const|const RepeatedPtrField< [DeviceHandle](msg_Common_DeviceHandle.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_device\_handle\(\)|RepeatedPtrField< [DeviceHandle](msg_Common_DeviceHandle.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [DeviceManager](../references/summary_DeviceManager.md)

