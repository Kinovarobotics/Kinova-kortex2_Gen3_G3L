# Message CartesianTrajectoryConstraint

This page describes the C++ Kinova::Api::Base::CartesianTrajectoryConstraint message.

## Overview / Purpose

Defines a Cartesian trajectory constraint that can be applied when controlling in Cartesian trajectory mode

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|speed|oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#)|Speed constraint \(in meters per second\)|
|duration|oneof:type float32|Duration constraint \(in meters per second\) \(future\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|has\_speed\(\) const|void|void|Returns the current value of the field if oneof case is kSpeed. Otherwise, returns oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#)::default\_instance\(\)|
|speed\(\) const|const oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#)&|void|Returns the current value of the field if oneof case is kSpeed|
|mutable\_speed\(\)|oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#)\*|void|If any other oneof field in the same oneof is set, calls clear\_type\(\). Sets the oneof case to kSpeed and returns a pointer to the mutable oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#) object that stores the field's value. If the oneof case was not kSpeed prior to the call, then the returned oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#)\). After calling this, has\_speed\(\) will return true, speed\(\) will return a reference to the same instance of oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#) and type\_case\(\) will return kSpeed|
|clear\_speed\(\)|void|void|Nothing will be changed if the oneof case is not kSpeed. If the oneof case equals kSpeed, frees the field and clears the oneof case. has\_speed\(\) will return false, speed\(\) will return the default value and type\_case\(\) will return TYPE\_NOT\_SET.|
|set\_allocated\_speed\(\)|void|oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#)\*|Calls clear\_type\(\). If the oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#) pointer is not NULL: Sets the oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#) object to the field and sets the oneof case to kSpeed. The message takes ownership of the allocated oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#) object, has\_speed\(\) will return true and type\_case\(\) will return kSpeed. If the pointer is NULL, has\_speed\(\) will return false and type\_case\(\) will return TYPE\_NOT\_SET. \(The behavior is like calling clear\_type\(\)\)|
|release\_speed\(\)|oneof:type [CartesianSpeed](msg_Base_CartesianSpeed.md#)\*|void|Returns NULL if oneof case is not kSpeed. If the oneof case is kSpeed, clears the oneof case, releases the ownership of the field and returns the pointer of the type object. After calling this, caller takes the ownership of the allocated type object, has\_speed\(\) will return false, speed\(\) will return the default value and type\_case\(\) will return TYPE\_NOT\_SET.|
|set\_duration\(\)|void|oneof:type float32|If any other oneof field in the same oneof is set, calls clear\_type\(\). Sets the value of this field and sets the oneof case to kDuration.|
|duration\(\) const|oneof:type float32|void|Returns the current value of the field if oneof case is kDuration. Otherwise, returns the default value.|
|clear\_duration\(\)|void|void|Nothing will be changed if the oneof case is not kDuration. If the oneof case is kDuration, clears the value of the field and the oneof case|

**Parent topic:** [Base](../references/summary_Base.md)

