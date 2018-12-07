# DeviceManager

This page describes the Python Kinova.Api.DeviceManager package.

## Overview / Purpose

This service provides information about which devices are present

## API reference

This section describes procedure calls / methods exposed by the DeviceManager package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|ReadAllDevices|[DeviceHandles](msg_DeviceManager_DeviceHandles.md#)|None|Retrieves the list of every device that the system contains, along with its type and order within the system|

## Data types reference

This section describes the data types used in the DeviceManager package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[DeviceHandles](msg_DeviceManager_DeviceHandles.md#)|List of Device handles|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[ServiceVersion](enm_DeviceManager_ServiceVersion.md#)|Enumeration used to identify DeviceManager current version|

**Parent topic:** [KINOVA® KORTEX™ Python API Reference](../index.md#)

