# Message TransformationMatrix

This page describes the C++ Kinova::Api::Base::TransformationMatrix message.

## Overview / Purpose

Defines a transformation matrix

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|r0| [TransformationRow](msg_Base_TransformationRow.md#)|First transformation row|
|r1| [TransformationRow](msg_Base_TransformationRow.md#)|Second transformation row|
|r2| [TransformationRow](msg_Base_TransformationRow.md#)|Third transformation row|
|r3| [TransformationRow](msg_Base_TransformationRow.md#)|Fourth transformation row|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_r0\(\) const|bool|void|Returns true if r0 is set.|
|r0\(\)|const [TransformationRow](msg_Base_TransformationRow.md#)&|void|Returns the current value of r0. If r0 is not set, returns a [TransformationRow](msg_Base_TransformationRow.md#) with none of its fields set \(possibly r0::default\_instance\(\)\).|
|mutable\_r0\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Returns a pointer to the mutable [TransformationRow](msg_Base_TransformationRow.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [TransformationRow](msg_Base_TransformationRow.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [TransformationRow](msg_Base_TransformationRow.md#)\). After calling this, has\_r0\(\) will return true and r0\(\) will return a reference to the same instance of [TransformationRow](msg_Base_TransformationRow.md#).|
|clear\_r0\(\)|void|void|Clears the value of the field. After calling this, has\_r0\(\) will return false and r0\(\) will return the default value.|
|set\_allocated\_r0\(\)|void| [TransformationRow](msg_Base_TransformationRow.md#) \*|Sets the [TransformationRow](msg_Base_TransformationRow.md#) object to the field and frees the previous field value if it exists. If the [TransformationRow](msg_Base_TransformationRow.md#) pointer is not NULL, the message takes ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object and has\_ [TransformationRow](msg_Base_TransformationRow.md#)\(\) will return true. Otherwise, if the r0 is NULL, the behavior is the same as calling clear\_r0\(\).|
|release\_r0\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Releases the ownership of the field and returns the pointer of the [TransformationRow](msg_Base_TransformationRow.md#) object. After calling this, caller takes the ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object, has\_r0\(\) will return false, and r0\(\) will return the default value.|
|has\_r1\(\) const|bool|void|Returns true if r1 is set.|
|r1\(\)|const [TransformationRow](msg_Base_TransformationRow.md#)&|void|Returns the current value of r1. If r1 is not set, returns a [TransformationRow](msg_Base_TransformationRow.md#) with none of its fields set \(possibly r1::default\_instance\(\)\).|
|mutable\_r1\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Returns a pointer to the mutable [TransformationRow](msg_Base_TransformationRow.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [TransformationRow](msg_Base_TransformationRow.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [TransformationRow](msg_Base_TransformationRow.md#)\). After calling this, has\_r1\(\) will return true and r1\(\) will return a reference to the same instance of [TransformationRow](msg_Base_TransformationRow.md#).|
|clear\_r1\(\)|void|void|Clears the value of the field. After calling this, has\_r1\(\) will return false and r1\(\) will return the default value.|
|set\_allocated\_r1\(\)|void| [TransformationRow](msg_Base_TransformationRow.md#) \*|Sets the [TransformationRow](msg_Base_TransformationRow.md#) object to the field and frees the previous field value if it exists. If the [TransformationRow](msg_Base_TransformationRow.md#) pointer is not NULL, the message takes ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object and has\_ [TransformationRow](msg_Base_TransformationRow.md#)\(\) will return true. Otherwise, if the r1 is NULL, the behavior is the same as calling clear\_r1\(\).|
|release\_r1\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Releases the ownership of the field and returns the pointer of the [TransformationRow](msg_Base_TransformationRow.md#) object. After calling this, caller takes the ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object, has\_r1\(\) will return false, and r1\(\) will return the default value.|
|has\_r2\(\) const|bool|void|Returns true if r2 is set.|
|r2\(\)|const [TransformationRow](msg_Base_TransformationRow.md#)&|void|Returns the current value of r2. If r2 is not set, returns a [TransformationRow](msg_Base_TransformationRow.md#) with none of its fields set \(possibly r2::default\_instance\(\)\).|
|mutable\_r2\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Returns a pointer to the mutable [TransformationRow](msg_Base_TransformationRow.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [TransformationRow](msg_Base_TransformationRow.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [TransformationRow](msg_Base_TransformationRow.md#)\). After calling this, has\_r2\(\) will return true and r2\(\) will return a reference to the same instance of [TransformationRow](msg_Base_TransformationRow.md#).|
|clear\_r2\(\)|void|void|Clears the value of the field. After calling this, has\_r2\(\) will return false and r2\(\) will return the default value.|
|set\_allocated\_r2\(\)|void| [TransformationRow](msg_Base_TransformationRow.md#) \*|Sets the [TransformationRow](msg_Base_TransformationRow.md#) object to the field and frees the previous field value if it exists. If the [TransformationRow](msg_Base_TransformationRow.md#) pointer is not NULL, the message takes ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object and has\_ [TransformationRow](msg_Base_TransformationRow.md#)\(\) will return true. Otherwise, if the r2 is NULL, the behavior is the same as calling clear\_r2\(\).|
|release\_r2\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Releases the ownership of the field and returns the pointer of the [TransformationRow](msg_Base_TransformationRow.md#) object. After calling this, caller takes the ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object, has\_r2\(\) will return false, and r2\(\) will return the default value.|
|has\_r3\(\) const|bool|void|Returns true if r3 is set.|
|r3\(\)|const [TransformationRow](msg_Base_TransformationRow.md#)&|void|Returns the current value of r3. If r3 is not set, returns a [TransformationRow](msg_Base_TransformationRow.md#) with none of its fields set \(possibly r3::default\_instance\(\)\).|
|mutable\_r3\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Returns a pointer to the mutable [TransformationRow](msg_Base_TransformationRow.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [TransformationRow](msg_Base_TransformationRow.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [TransformationRow](msg_Base_TransformationRow.md#)\). After calling this, has\_r3\(\) will return true and r3\(\) will return a reference to the same instance of [TransformationRow](msg_Base_TransformationRow.md#).|
|clear\_r3\(\)|void|void|Clears the value of the field. After calling this, has\_r3\(\) will return false and r3\(\) will return the default value.|
|set\_allocated\_r3\(\)|void| [TransformationRow](msg_Base_TransformationRow.md#) \*|Sets the [TransformationRow](msg_Base_TransformationRow.md#) object to the field and frees the previous field value if it exists. If the [TransformationRow](msg_Base_TransformationRow.md#) pointer is not NULL, the message takes ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object and has\_ [TransformationRow](msg_Base_TransformationRow.md#)\(\) will return true. Otherwise, if the r3 is NULL, the behavior is the same as calling clear\_r3\(\).|
|release\_r3\(\)| [TransformationRow](msg_Base_TransformationRow.md#) \*|void|Releases the ownership of the field and returns the pointer of the [TransformationRow](msg_Base_TransformationRow.md#) object. After calling this, caller takes the ownership of the allocated [TransformationRow](msg_Base_TransformationRow.md#) object, has\_r3\(\) will return false, and r3\(\) will return the default value.|

**Parent topic:** [Base](../references/summary_Base.md)

