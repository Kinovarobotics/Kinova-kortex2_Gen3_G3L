# Session

This page describes the Python Kinova.Api.Session package.

## Overview / Purpose

Service to manage Sessions

## API reference

This section describes procedure calls / methods exposed by the Session package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|CloseSession|None|None|Closes an existing open session|
|CreateSession|None|[CreateSessionInfo](msg_Session_CreateSessionInfo.md#)|Creates a new session with the robot using given values for user name, session timeout value, and password|
|GetConnections|[ConnectionList](msg_Session_ConnectionList.md#)|None|Retrieves the list of connections|
|KeepAlive|None|None|Sends Keep alive to robot|

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

**Parent topic:** [KINOVA® KORTEX™ Python API Reference](../index.md#)

