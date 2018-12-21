# InterconnectCyclic

This page describes the Python Kinova.Api.InterconnectCyclic package.

## Overview / Purpose

Service to exchange cyclic data with Interconnect module

## API reference

This section describes procedure calls / methods exposed by the InterconnectCyclic package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|Refresh|[Feedback](msg_InterconnectCyclic_Feedback.md#)|[Command](msg_InterconnectCyclic_Command.md#)|Send a command to the Interconnect module and receive feedback about the actual status the module|
|RefreshCommand|None|[Command](msg_InterconnectCyclic_Command.md#)|Send a command to the Interconnect module without receiving feedback|
|RefreshCustomData|[CustomData](msg_InterconnectCyclic_CustomData.md#)|[MessageId](msg_InterconnectCyclic_MessageId.md#)| |
|RefreshFeedback|[Feedback](msg_InterconnectCyclic_Feedback.md#)|[MessageId](msg_InterconnectCyclic_MessageId.md#)|Gets feedback from the Interconnect module on its status|

## Data types reference

This section describes the data types used in the InterconnectCyclic package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[Command](msg_InterconnectCyclic_Command.md#)|Defines an interconnect module command|
|[CustomData](msg_InterconnectCyclic_CustomData.md#)|Custom development data, content varies according to debug needs|
|[Feedback](msg_InterconnectCyclic_Feedback.md#)|Defines the feedback provided by an interconnect module|
|[MessageId](msg_InterconnectCyclic_MessageId.md#)|Identifies a message|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[ServiceVersion](enm_InterconnectCyclic_ServiceVersion.md#)|Enumeration used to identify InterconnectCyclic current version|

**Parent topic:** [KINOVA® KORTEX™ Python API Reference](../index.md#)

