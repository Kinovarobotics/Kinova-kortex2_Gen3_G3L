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
- [Device Manager service](#device-manager-service)
	- [Service description](#service-description)
	- [Good to know](#good-to-know)
	- [Example](#example)
- [Device Config](#device-config)
	- [Service description](#service-description-1)
	- [Good to know](#good-to-know-1)
	- [Example](#example-1)
- [Other Services](#other-services)
	- [Example](#example-2)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
Device routing is a mechanism that allows the sending of commands to specific devices using the connection with the base.  This is done by specifying a *device_identifier* when sending a command through a service, which doesn't need to be implemented by the base.

In other words, you can send a command to a sub device with a service known only by the sub device (e.g.: ``ActuatorConfigClientRpc)`` as long as the *device_identifier* is specified in the command parameter.

The **Device Manager** service is used to obtain the *device_identifier*.

<a id="markdown-srv-devMgn" name="srv-devMng"></a>
## Device Manager service

<a id="markdown-devMng-description" name="devMng-description"></a>
### Service description
The purpose of the **Device Manager** service is to return a device handle list which contains handles for all current devices.

<a id="markdown-devMng-gtk" name="devMng-gtk"></a>
### Good to know
- The device handle list returned by ``ReadAllDevices()`` is not ordered.

<a id="markdown-devMng-example" name="devMng-example"></a>
### Example
```cpp
namespace k_api = Kinova::Api;

/* API initialisation */
auto pDeviceMng = new k_api::DeviceManager::DeviceManagerClient(pRouter);
auto allDevicesInfo = pDeviceMng->ReadAllDevices();
```

<a id="markdown-srv-devConfig" name="srv-devConfig"></a>
## Device Config

<a id="markdown-devConfig-description" name="devConfig-description"></a>
### Service description
The **Device Config** service provides information about the device being interrogated, including device type, firmware version, manufacturing information and hardware revision.

<a id="markdown-devConfig-gtk" name="devConfig-gtk"></a>
### Good to know
- The device handle list returned by ``ReadAllDevices()`` is not ordered.
- Device handles also have a *device_type* field and an *order* field.

<a id="markdown-devConfig-example" name="devConfig-example"></a>
### Example
```cpp
namespace k_api = Kinova::Api;
namespace pb = google::protobuf;

/* API initialisation */
auto pDeviceMng = new k_api::DeviceManager::DeviceManagerClient(pRouter);
auto allDevicesInfo = pDeviceMng->ReadAllDevices();

// RouterClientSendOptions still available when routing
k_api::RouterClientSendOptions options;
options.timeout_ms = 4000;  // (milliseconds)

for ( auto dev : allDevicesInfo.device_handle() )
{
	std::string str;
	pb::TextFormat::PrintToString( pDeviceConfig->GetDeviceType         (dev.device_identifier(), options), &str );     std::cout << str;
	pb::TextFormat::PrintToString( pDeviceConfig->GetFirmwareVersion    (dev.device_identifier(), options), &str );     std::cout << str;
	pb::TextFormat::PrintToString( pDeviceConfig->GetBootloaderVersion  (dev.device_identifier(), options), &str );     std::cout << str;
	pb::TextFormat::PrintToString( pDeviceConfig->GetPartNumber         (dev.device_identifier(), options), &str );     std::cout << str;
	pb::TextFormat::PrintToString( pDeviceConfig->GetSerialNumber       (dev.device_identifier(), options), &str );     std::cout << str;
	pb::TextFormat::PrintToString( pDeviceConfig->GetMACAddress         (dev.device_identifier(), options), &str );     std::cout << str;
	pb::TextFormat::PrintToString( pDeviceConfig->GetPartNumberRevision (dev.device_identifier(), options), &str );     std::cout << str;
	std::cout << "\n";
}
```

<a id="markdown-other" name="other"></a>
## Other Services

The *device_identifier* can be used by other services to directly interrogate a device.

<a id="markdown-example" name="other-example"></a>
### Example

```cpp
namespace k_api = Kinova::Api;
namespace pb = google::protobuf;

/* API initialisation */
auto pDeviceMng = new k_api::DeviceManager::DeviceManagerClient(pRouter);
auto pVision = new k_api::VisionConfig::VisionConfigClient(pRouter);

auto allDevicesInfo = pDeviceMng->ReadAllDevices();

// uses device routing information to route to every device (base, actuator, interconnect, etc.)
for ( auto dev : allDevicesInfo.device_handle() )
{	
    if ( dev.device_type() == k_api::Common::DeviceTypes::VISION )
	{
	    printf("-- Using Vision Config Service to get intrinsic parameters --\n");
	    k_api::VisionConfig::SensorIdentifier sensorId;
	    sensorId.set_sensor(k_api::VisionConfig::SENSOR_COLOR);

		// We can now use the Vision service with the base connection by specifing the device_identifier
	    auto intrinsicValue = pVision->GetIntrinsicParameters(sensorId, dev.device_identifier());

	    std::cout << "Width: " << intrinsicValue.width() << std::endl;
	    std::cout << "Height: " << intrinsicValue.height() << std::endl;
	    std::cout << "Principal point x: " << intrinsicValue.principal_point_x() << std::endl;
	    std::cout << "Principal point y: " << intrinsicValue.principal_point_y() << std::endl;
	    std::cout << "focal lenght x: " << intrinsicValue.focal_length_x() << std::endl;
	    std::cout << "focal lenght y: " << intrinsicValue.focal_length_y() << std::endl;

	    break;
	}
}
```
