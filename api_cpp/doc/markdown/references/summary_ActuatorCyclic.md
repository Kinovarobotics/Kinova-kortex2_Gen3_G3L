# ActuatorCyclic

This page describes the C++ Kinova::Api::ActuatorCyclic package.

## Overview / Purpose

Service to exchange cyclic data with actuator module

## API reference

This section describes procedure calls / methods exposed by the ActuatorCyclic package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

Every method listed below, except the notification subscription methods \(begining with 'OnNotification'\) are available in three different forms :

-   **blocking** : called using listed method name \(default\)
-   **future/promise** : called using listed method name followed by the '**\_async**' suffix
-   **regiser callback** : called using listed method name followed by the '**\_callback**' suffix

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|Refresh|[Feedback](msg_ActuatorCyclic_Feedback.md#)|[Command](msg_ActuatorCyclic_Command.md#)|Commands refresh \(with feedback\)|
|RefreshCommand|void|[Command](msg_ActuatorCyclic_Command.md#)|Commands refresh \(no feedback\)|
|RefreshCustomData|[CustomData](msg_ActuatorCyclic_CustomData.md#)|[MessageId](msg_ActuatorCyclic_MessageId.md#)|Gets custom data|
|RefreshFeedback|[Feedback](msg_ActuatorCyclic_Feedback.md#)|[MessageId](msg_ActuatorCyclic_MessageId.md#)|Gets feedback|

## Data types reference

This section describes the data types used in the ActuatorCyclic package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[Command](msg_ActuatorCyclic_Command.md#)|Defines an actuator module command|
|[CustomData](msg_ActuatorCyclic_CustomData.md#)|Custom development data, content varies according to debug needs|
|[Feedback](msg_ActuatorCyclic_Feedback.md#)|Defines the feedback provided by an actuator module|
|[MessageId](msg_ActuatorCyclic_MessageId.md#)|Provides a message identifier|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[CommandFlags](enm_ActuatorCyclic_CommandFlags.md#)|Enumeration used to identify actuator commands|
|[ServiceVersion](enm_ActuatorCyclic_ServiceVersion.md#)|Enumeration used to identify ActuatorCyclic current version|
|[StatusFlags](enm_ActuatorCyclic_StatusFlags.md#)|Enumeration used to identify actuator status|

**Parent topic:** [KINOVA® KORTEX™ C++ API Reference](../index.md#)

