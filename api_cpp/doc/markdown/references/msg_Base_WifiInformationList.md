# Message WifiInformationList

This page describes the C++ Kinova::Api::Base::WifiInformationList message.

## Overview / Purpose

Array of Wi-Fi information

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|wifi\_information\_list| [WifiInformation](msg_Base_WifiInformation.md#)|Wi-Fi information|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|wifi\_information\_list\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|wifi\_information\_list\(\) const|const [WifiInformation](msg_Base_WifiInformation.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, wifi\_information\_list\_size\(\)\) yields undefined behavior.|
|mutable\_wifi\_information\_list\(\)| [WifiInformation](msg_Base_WifiInformation.md#)\*|int index|Returns a pointer to the mutable [WifiInformation](msg_Base_WifiInformation.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, wifi\_information\_list\_size\(\)\) yields undefined behavior.|
|add\_wifi\_information\_list\(\)| [WifiInformation](msg_Base_WifiInformation.md#)\*|void|Adds a new element and returns a pointer to it. The returned [WifiInformation](msg_Base_WifiInformation.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [WifiInformation](msg_Base_WifiInformation.md#)\).|
|clear\_wifi\_information\_list\(\)|void|void|Removes all elements from the field. After calling this, wifi\_information\_list\_size\(\) will return zero.|
|wifi\_information\_list\(\) const|const RepeatedPtrField< [WifiInformation](msg_Base_WifiInformation.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_wifi\_information\_list\(\)|RepeatedPtrField< [WifiInformation](msg_Base_WifiInformation.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|

**Parent topic:** [Base](../references/summary_Base.md)

