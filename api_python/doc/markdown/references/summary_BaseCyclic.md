# BaseCyclic

This page describes the Python Kinova.Api.BaseCyclic package.

## Overview / Purpose

Service to exchange cyclic data with base module

## API reference

This section describes procedure calls / methods exposed by the BaseCyclic package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|Refresh|[Feedback](msg_BaseCyclic_Feedback.md#)|[Command](msg_BaseCyclic_Command.md#)|Commands refresh \(with feedback\)|
|RefreshCommand|None|[Command](msg_BaseCyclic_Command.md#)|Commands refresh \(no feedback\)|
|RefreshCustomData|[CustomData](msg_BaseCyclic_CustomData.md#)|[CustomData](msg_BaseCyclic_CustomData.md#)|Gets custom data|
|RefreshFeedback|[Feedback](msg_BaseCyclic_Feedback.md#)|None|Gets feedback|

## Data types reference

This section describes the data types used in the BaseCyclic package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[ActuatorCommand](msg_BaseCyclic_ActuatorCommand.md#)|copied from ActuatorCyclic.proto|
|[ActuatorCustomData](msg_BaseCyclic_ActuatorCustomData.md#)|copied from ActuatorCyclic.proto|
|[ActuatorFeedback](msg_BaseCyclic_ActuatorFeedback.md#)|copied from ActuatorCyclic.proto|
|[BaseFeedback](msg_BaseCyclic_BaseFeedback.md#)| |
|[Command](msg_BaseCyclic_Command.md#)| |
|[CustomData](msg_BaseCyclic_CustomData.md#)|Custom development data, content varies according to debug needs|
|[Feedback](msg_BaseCyclic_Feedback.md#)| |
|[InterconnectCommand](msg_BaseCyclic_InterconnectCommand.md#)|copied from InterconnectCyclic.proto|
|[InterconnectCustomData](msg_BaseCyclic_InterconnectCustomData.md#)|copied from InterconnectCyclic.proto|
|[InterconnectFeedback](msg_BaseCyclic_InterconnectFeedback.md#)|copied from InterconnectCyclic.proto|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[ServiceVersion](enm_BaseCyclic_ServiceVersion.md#)|Enumeration used to identify BaseCyclic current version|

**Parent topic:** [KINOVA® KORTEX™ Python API Reference](../index.md#)

