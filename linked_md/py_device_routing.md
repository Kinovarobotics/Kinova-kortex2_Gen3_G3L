<!--
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2019 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
-->

<h1>Device routing</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Device Manager Service](#srv-devMng)
	- [Service description](#devMng-description)
	- [Good to know](#devMng-gtk)
	- [Example](#devMng-example)
- [Device Config](#srv-devConfig)
	- [Service description](#devConfig-description)
	- [Good to know](#devConfig-gtk)
	- [Example](#devConfig-example)
- [Other Services](#other)
	- [Example](#other-example)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
Device routing is a mechanism that allows you to send commands to a specific device using the connection with the base.  This is done by specifying the *device_identifier* when sending a command through a service. The service doesn't need to be implemented by the base.

In other words, a command can be sent to a sub device, using a service known ony by the sub device (e.g.: ``ActuatorConfigClientRpc``) as long as the *device_identifier* is specified in the command parameters.

To obtain the *device_identifier* you need to use the **Device Manager** service.

<a id="markdown-srv-devMgn" name="srv-devMng"></a>
## Device Manager service

<a id="markdown-devMng-description" name="devMng-description"></a>
### Service description
The sole purpose of the **Device Manager** service is to return a device handle list containing handles for all devices present.

<a id="markdown-devMng-gtk" name="devMng-gtk"></a>
### Good to know
- The device handle list returned by ``ReadAllDevices()`` is *not* in alphabetical order.

<a id="markdown-devMng-example" name="devMng-example"></a>
### Example

```python
# API initialisation
device_manager_service = DeviceManagerClient(router)
subDevicesInfo = device_manager_service.ReadAllDevices()
```


<a id="markdown-srv-devConfig" name="srv-devConfig"></a>
## Device Config

<a id="markdown-devConfig-description" name="devConfig-description"></a>
### Service description
The **Device Config** service provides information about the interrogate device: device type, firmware version, manufacturing information and hardware revision.

<a id="markdown-devConfig-gtk" name="devConfig-gtk"></a>
### Good to know
- Device order is *not* guaranteed when calling ``ReadAllDevices``.
- Device handles also have the fields *device_type* and *order*. 

<a id="markdown-devConfig-example" name="devConfig-example"></a>
### Example
```python
# Api initialisation
device_manager_service = DeviceManagerClient(router)
# getting all device routing information (from DeviceManagerClient service)
print("-- ReadAllDevices --\n")
subDevicesInfo = device_manager_service.ReadAllDevices()
print(json_format.MessageToJson(subDevicesInfo))
print("--------------------\n")

# using device routing information to route to every devices (base, actuator, interconnect, etc.) in the arm/base system
for dev in subDevicesInfo.device_handle:
    deviceInfo = {}
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetDeviceType           (dev.device_identifier, options) ) )
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetFirmwareVersion      (dev.device_identifier, options) ) )
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetBootloaderVersion    (dev.device_identifier, options) ) )
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetModelNumber          (dev.device_identifier, options) ) )
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetPartNumber           (dev.device_identifier, options) ) )
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetSerialNumber         (dev.device_identifier, options) ) )
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetMACAddress           (dev.device_identifier, options) ) )
    deviceInfo.update( json_format.MessageToDict( device_config_service.GetPartNumberRevision   (dev.device_identifier, options) ) )
```

<a id="markdown-other" name="other"></a>
## Other Services

The *device_identifier* can be used with other services to directly interrogate a device.

<a id="markdown-example" name="other-example"></a>
### Example

```python
# API initialisation
device_manager_service = DeviceManagerClient(router)
# getting all device routing information (from DeviceManagerClient service)
allDevicesInfo = device_manager_service.ReadAllDevices()

vision_handles = [ hd for hd in allDevicesInfo.device_handle if hd.device_type == DeviceConfig_pb2.VISION ]
if len(vision_handles) == 0:
    print("error: there is no vision device register in the devices infos")
elif len(vision_handles) > 1:
    print("error: there are more than one vision device register in the devices infos")
else:
    handle = vision_handles[0]

sensor_id = VisionConfig_pb2.SensorIdentifier()
sensor_id.sensor = VisionConfig_pb2.SENSOR_COLOR

intrinsic_value = vision_config_service.GetIntrinsicParameters(sensor_id, handle.device_identifier)

print("Width: {0}".format(intrinsic_value.width))
print("Height: {0}".format(intrinsic_value.height))
print("Principal point x: {0}".format(intrinsic_value.principal_point_x))
print("Principal point y: {0}".format(intrinsic_value.principal_point_y))
print("Focal length x: {0}".format(intrinsic_value.focal_length_x))
print("Focal length y: {0}".format(intrinsic_value.focal_length_y))

```