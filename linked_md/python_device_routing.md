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
- [Device Manager service](#service-device-manager)
	- [Service description](#devMng-description)
	- [Good to know](#devMng-gtk)
	- [Example](#devMng-example)
- [Device Config service](#srv-devConfig)
	- [Service description](#devConfig-description)
	- [Good to know](#devConfig-gtk)
	- [Example](#devConfig-example)
- [Other Services](#other)
	- [Example](#other-example)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
Device routing is a mechanism that allows you to send commands to a specific device using the connection with the base.  This is done by specifying the *device_identifier* when sending a command through a service. The service doesn't need to be implemented by the base.

In other words, a command can be sent to a sub device, using a service known ony by the sub device (e.g.: ``ActuatorConfigClient``) as long as the *device_identifier* is specified in the command parameters.

To obtain the *device_identifier* you need to use the **Device Manager** service.

<a id="markdown-srv-devMgn" name="service-device-manager"></a>
## Device Manager service

<a id="markdown-devMng-description" name="devMng-description"></a>
### Service description
The sole purpose of the **Device Manager** service is to return a device handle list containing handles for all devices present using the method `ReadAllDevices()`.

<a id="markdown-devMng-gtk" name="devMng-gtk"></a>
### Good to know
- The device handle list returned by `ReadAllDevices()` is *not* in any specific device order
- Device handles also have the fields `device_type` and `order` 

<a id="markdown-devMng-example" name="devMng-example"></a>
### Example

```python
# API initialisation
device_manager = DeviceManagerClient(router)
subDevicesInfo = device_manager.ReadAllDevices()
```


<a id="markdown-srv-devConfig" name="srv-devConfig"></a>
## Device Config service

<a id="markdown-devConfig-description" name="devConfig-description"></a>
### Service description
The `DeviceConfig` service provides information about the interrogated device: 
- device type
- firmware and bootloader version
- model, part, and serial number
- MAC address and 
- hardware revision


<a id="markdown-devConfig-example" name="devConfig-example"></a>
### Example
```python
# Api initialisation
device_manager = DeviceManagerClient(router)
device_config = DeviceConfigClient(router)

# Get all device routing information (from DeviceManagerClient service)
all_devices_info = device_manager.ReadAllDevices()

options = RouterClientSendOptions()
options.timeout_ms = 4000

# Use device routing information to route to every devices (base, actuator, interconnect, etc.) in the arm/base system and request their general device information
for dev in all_devices_info.device_handle:
    device_info = {}
    device_info.update( json_format.MessageToDict( device_config.GetDeviceType           (dev.device_identifier, options) ) )
    device_info.update( json_format.MessageToDict( device_config.GetFirmwareVersion      (dev.device_identifier, options) ) )
    device_info.update( json_format.MessageToDict( device_config.GetBootloaderVersion    (dev.device_identifier, options) ) )
    device_info.update( json_format.MessageToDict( device_config.GetModelNumber          (dev.device_identifier, options) ) )
    device_info.update( json_format.MessageToDict( device_config.GetPartNumber           (dev.device_identifier, options) ) )
    device_info.update( json_format.MessageToDict( device_config.GetPartNumberRevision   (dev.device_identifier, options) ) )
    device_info.update( json_format.MessageToDict( device_config.GetSerialNumber         (dev.device_identifier, options) ) )

    # Get hexadecimal representation of MAC address
    macAddress_hexstr = ""
    for b in device_config.GetMACAddress(dev.device_identifier, options).mac_address:
            macAddress_hexstr += "%02X:" % b
    macAddress_hexstr = macAddress_hexstr[:-1] # remove last ':'
    device_info.update( { "macAddress": macAddress_hexstr } )
    print("-----------------------------")

    print("-- {}: id = {} --".format(Common_pb2._DEVICETYPES.values_by_number[dev.device_type].name, dev.device_identifier))
    for key, value in device_info.items():
            print(str("%20s") % key + ": " + str(value))
```

<a id="markdown-other" name="other"></a>
## Other Services

The *device_identifier* can be used with other services to directly interrogate a device.

<a id="markdown-example" name="other-example"></a>
### Example

```python
# API initialisation
device_manager = DeviceManagerClient(router)
vision_config = VisionConfigClient(router)

# Getting all device routing information (from DeviceManagerClient service)
allDevicesInfo = device_manager.ReadAllDevices()

vision_handles = [hd for hd in allDevicesInfo.device_handle if hd.device_type == DeviceConfig_pb2.VISION ]

if len(vision_handles) == 0:
    print("Error: there is no vision device registered in the devices info")
elif len(vision_handles) > 1:
    print("Error: there are more than one vision device register in the devices infos")
else:
    handle = vision_handles[0]

sensor_id = VisionConfig_pb2.SensorIdentifier()
sensor_id.sensor = VisionConfig_pb2.SENSOR_COLOR

intrinsic_value = vision_config.GetIntrinsicParameters(sensor_id, handle.device_identifier)

print("Width: {0}".format(intrinsic_value.width))
print("Height: {0}".format(intrinsic_value.height))
print("Principal point x: {0}".format(intrinsic_value.principal_point_x))
print("Principal point y: {0}".format(intrinsic_value.principal_point_y))
print("Focal length x: {0}".format(intrinsic_value.focal_length_x))
print("Focal length y: {0}".format(intrinsic_value.focal_length_y))
```