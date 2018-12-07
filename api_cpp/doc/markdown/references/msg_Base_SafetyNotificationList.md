# Message SafetyNotificationList

This page describes the C++ Kinova::Api::Base::SafetyNotificationList message.

## Overview / Purpose

Array of safety notifications

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|notifications| [SafetyNotification](msg_Common_SafetyNotification.md#)|Notification|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|notifications\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|notifications\(\) const|const [SafetyNotification](msg_Common_SafetyNotification.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|mutable\_notifications\(\)| [SafetyNotification](msg_Common_SafetyNotification.md#)\*|int index|Returns a pointer to the mutable [SafetyNotification](msg_Common_SafetyNotification.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|add\_notifications\(\)| [SafetyNotification](msg_Common_SafetyNotification.md#)\*|void|Adds a new element and returns a pointer to it. The returned [SafetyNotification](msg_Common_SafetyNotification.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [SafetyNotification](msg_Common_SafetyNotification.md#)\).|
|clear\_notifications\(\)|void|void|Removes all elements from the field. After calling this, notifications\_size\(\) will return zero.|
|notifications\(\) const|const RepeatedPtrField< [SafetyNotification](msg_Common_SafetyNotification.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_notifications\(\)|RepeatedPtrField< [SafetyNotification](msg_Common_SafetyNotification.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

