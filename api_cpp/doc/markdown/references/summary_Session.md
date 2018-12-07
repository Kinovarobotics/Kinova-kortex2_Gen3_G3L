# Session

This page describes the C++ Kinova::Api::Session package.

## Overview / Purpose

Service to manage Sessions

## API reference

This section describes procedure calls / methods exposed by the Session package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

Every method listed below, except the notification subscription methods \(begining with 'OnNotification'\) are available in three different forms :

-   **blocking** : called using listed method name \(default\)
-   **future/promise** : called using listed method name followed by the '**\_async**' suffix
-   **regiser callback** : called using listed method name followed by the '**\_callback**' suffix

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|CloseSession|void|void|Closes an existing open session|
|CreateSession|void|[CreateSessionInfo](msg_Session_CreateSessionInfo.md#)|Creates a new session with the robot using given values for user name, session timeout value, and password|
|GetConnections|[ConnectionList](msg_Session_ConnectionList.md#)|void|Retrieves the list of connections|
|KeepAlive|void|void|Sends Keep alive to robot|

## Data types reference

This section describes the data types used in the Session package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[ConnectionList](msg_Session_ConnectionList.md#)|Message used to retrieve a list of connections|
|[CreateSessionInfo](msg_Session_CreateSessionInfo.md#)|Contains parameters to create a new session|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[ServiceVersion](enm_Session_ServiceVersion.md#)|Enumeration used to identify Session current version|

**Parent topic:** [KINOVA® KORTEX™ C++ API Reference](../index.md#)

