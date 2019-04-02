# Message ControllerNotificationList

This page describes the C++ Kinova::Api::Base::ControllerNotificationList message.

## Overview / Purpose

Array of controller notifications

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|notifications|Collection of [ControllerNotification](msg_Base_ControllerNotification.md#)|Notifications|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|notifications\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|notifications\(\) const|const [ControllerNotification](msg_Base_ControllerNotification.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|mutable\_notifications\(\)| [ControllerNotification](msg_Base_ControllerNotification.md#)\*|int index|Returns a pointer to the mutable [ControllerNotification](msg_Base_ControllerNotification.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|add\_notifications\(\)| [ControllerNotification](msg_Base_ControllerNotification.md#)\*|void|Adds a new element and returns a pointer to it. The returned [ControllerNotification](msg_Base_ControllerNotification.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [ControllerNotification](msg_Base_ControllerNotification.md#)\).|
|clear\_notifications\(\)|void|void|Removes all elements from the field. After calling this, notifications\_size\(\) will return zero.|
|notifications\(\) const|const RepeatedPtrField< [ControllerNotification](msg_Base_ControllerNotification.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_notifications\(\)|RepeatedPtrField< [ControllerNotification](msg_Base_ControllerNotification.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

