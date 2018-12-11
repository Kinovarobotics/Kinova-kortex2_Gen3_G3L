# Message ControllerEvent

This page describes the C++ Kinova::Api::Base::ControllerEvent message.

## Overview / Purpose

Identifies a controller event

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|input\_type| [ControllerInputType](enm_Base_ControllerInputType.md#)|Type of controller input that caused the event\_identifier|
|behavior| [ControllerBehavior](enm_Base_ControllerBehavior.md#)|Controller behavior that occured|
|input\_identifier|uint32|Controller input that caused the event|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|input\_type\(\) const| [ControllerInputType](enm_Base_ControllerInputType.md#)|void|Returns the current value of input\_type. If the input\_type is not set, returns 0.|
|set\_input\_type\(\)|void| [ControllerInputType](enm_Base_ControllerInputType.md#)|Sets the value of input\_type. After calling this, input\_type\(\) will return value.|
|clear\_input\_type\(\)|void|void|Clears the value of input\_type. After calling this, input\_type\(\) will return the empty string/empty bytes.|
|behavior\(\) const| [ControllerBehavior](enm_Base_ControllerBehavior.md#)|void|Returns the current value of behavior. If the behavior is not set, returns 0.|
|set\_behavior\(\)|void| [ControllerBehavior](enm_Base_ControllerBehavior.md#)|Sets the value of behavior. After calling this, behavior\(\) will return value.|
|clear\_behavior\(\)|void|void|Clears the value of behavior. After calling this, behavior\(\) will return the empty string/empty bytes.|
|input\_identifier\(\)|uint32|void|Returns the current value of input\_identifier. If the input\_identifier is not set, returns 0.|
|set\_input\_identifier\(\)|void|uint32|Sets the value of input\_identifier. After calling this, input\_identifier\(\) will return value.|
|clear\_input\_identifier\(\)|void|void|Clears the value of input\_identifier. After calling this, input\_identifier\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

