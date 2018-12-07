# Message OperatingModeNotificationList

This page describes the C++ Kinova::Api::Base::OperatingModeNotificationList message.

## Overview / Purpose

Array of Operating mode notifications

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|notifications| [OperatingModeNotification](msg_Base_OperatingModeNotification.md#)|Notification|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|notifications\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|notifications\(\) const|const [OperatingModeNotification](msg_Base_OperatingModeNotification.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|mutable\_notifications\(\)| [OperatingModeNotification](msg_Base_OperatingModeNotification.md#)\*|int index|Returns a pointer to the mutable [OperatingModeNotification](msg_Base_OperatingModeNotification.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, notifications\_size\(\)\) yields undefined behavior.|
|add\_notifications\(\)| [OperatingModeNotification](msg_Base_OperatingModeNotification.md#)\*|void|Adds a new element and returns a pointer to it. The returned [OperatingModeNotification](msg_Base_OperatingModeNotification.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [OperatingModeNotification](msg_Base_OperatingModeNotification.md#)\).|
|clear\_notifications\(\)|void|void|Removes all elements from the field. After calling this, notifications\_size\(\) will return zero.|
|notifications\(\) const|const RepeatedPtrField< [OperatingModeNotification](msg_Base_OperatingModeNotification.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_notifications\(\)|RepeatedPtrField< [OperatingModeNotification](msg_Base_OperatingModeNotification.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

