# Message SequenceInformation

This page describes the C++ Kinova::Api::Base::SequenceInformation message.

## Overview / Purpose

Provides information about a sequence

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|event\_identifier|uint32|Sequence event type|
|task\_index|uint32|Task index|
|task\_identifier|uint32|Task identifier|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|event\_identifier\(\) const|uint32|void|Returns the current value of event\_identifier. If the event\_identifier is not set, returns 0.|
|set\_event\_identifier\(\)|void|uint32|Sets the value of event\_identifier. After calling this, event\_identifier\(\) will return value.|
|clear\_event\_identifier\(\)|void|void|Clears the value of event\_identifier. After calling this, event\_identifier\(\) will return the empty string/empty bytes.|
|task\_index\(\)|uint32|void|Returns the current value of task\_index. If the task\_index is not set, returns 0.|
|set\_task\_index\(\)|void|uint32|Sets the value of task\_index. After calling this, task\_index\(\) will return value.|
|clear\_task\_index\(\)|void|void|Clears the value of task\_index. After calling this, task\_index\(\) will return 0.|
|task\_identifier\(\)|uint32|void|Returns the current value of task\_identifier. If the task\_identifier is not set, returns 0.|
|set\_task\_identifier\(\)|void|uint32|Sets the value of task\_identifier. After calling this, task\_identifier\(\) will return value.|
|clear\_task\_identifier\(\)|void|void|Clears the value of task\_identifier. After calling this, task\_identifier\(\) will return 0.|

**Parent topic:** [Base](../references/summary_Base.md)

