# Message UserProfileList

This page describes the C++ Kinova::Api::Base::UserProfileList message.

## Overview / Purpose

Array of user profiles

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|user\_profiles| [UserProfile](msg_Base_UserProfile.md#)|User profile|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|user\_profiles\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|user\_profiles\(\) const|const [UserProfile](msg_Base_UserProfile.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, user\_profiles\_size\(\)\) yields undefined behavior.|
|mutable\_user\_profiles\(\)| [UserProfile](msg_Base_UserProfile.md#)\*|int index|Returns a pointer to the mutable [UserProfile](msg_Base_UserProfile.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, user\_profiles\_size\(\)\) yields undefined behavior.|
|add\_user\_profiles\(\)| [UserProfile](msg_Base_UserProfile.md#)\*|void|Adds a new element and returns a pointer to it. The returned [UserProfile](msg_Base_UserProfile.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [UserProfile](msg_Base_UserProfile.md#)\).|
|clear\_user\_profiles\(\)|void|void|Removes all elements from the field. After calling this, user\_profiles\_size\(\) will return zero.|
|user\_profiles\(\) const|const RepeatedPtrField< [UserProfile](msg_Base_UserProfile.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_user\_profiles\(\)|RepeatedPtrField< [UserProfile](msg_Base_UserProfile.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

