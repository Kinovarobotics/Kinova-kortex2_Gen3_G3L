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
- [Device Config service](#device-config-service)
	- [Service description](#service-description-1)
	- [Example](#example-1)
- [Other Services](#other-services)
	- [Example](#example-2)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
Device routing is a mechanism that allows users to send commands to specific devices using the connection with the base.  This is done by specifying a *device_identifier* when sending a command through a service. This service doesn't need to be implemented by the base.

In other words, you can send a command to a sub device with a service known only by the sub device (e.g.: ``ActuatorConfigClient)`` as long as the *device_identifier* is specified as an additional command parameter.

The **Device Manager** service is used to obtain the *device_identifier*.

<a id="markdown-srv-devMgn" name="device-manager-service"></a>
## Device Manager service

<a id="markdown-devMng-description" name="service-description"></a>
### Service description
The **Device Manager** service contains a method `ReadAllDevices()` which returns a device handle list containing handles for all current devices in the robot.

<a id="markdown-devMng-gtk" name="good-to-know"></a>
### Good to know
- The device handle list returned by `ReadAllDevices()` is not in any particular order with respect to the location of devices in the robot.
- Device handles also have a *device_type* field and an *order* field.

<a id="markdown-devMng-example" name="example"></a>
### Example
```cpp
namespace k_api = Kinova::Api;

/* API initialisation */
auto device_manager = new k_api::DeviceManager::DeviceManagerClient(router);
auto allDevicesInfo = device_manager->ReadAllDevices();
```

<a id="markdown-srv-devConfig" name="device-config-service"></a>
## Device Config service

<a id="markdown-devConfig-description" name="service-description-1"></a>
### Service description
The **Device Config** service provides information about the device being interrogated, including:
- device type
- firmware and bootloader version
- part and serial numbers
- MAC address and 
- hardware revision


<a id="markdown-devConfig-example" name="example-1"></a>
### Example
```cpp
namespace k_api = Kinova::Api;

/* API initialisation */
auto device_manager = new k_api::DeviceManager::DeviceManagerClient(router);
auto device_config = new k_api::DeviceConfig::DeviceConfigClient(router);

// Get all device routing information (from DeviceManagerClient service)
auto allDevicesInfo = device_manager->ReadAllDevices();

k_api::RouterClientSendOptions options;
options.timeout_ms = 4000;  // (milliseconds)

// Use device routing information to route to every device (base, actuator, interconnect, etc.) in the arm base system and request general device information
for (auto device : allDevicesInfo.device_handle())
{

	std::cout << "-----------------------------\n";
	std::cout << "-- " << k_api::Common::DeviceTypes_Name(device.device_type()) << ": id = " << device.device_identifier() << " --\n";

	std::string str;
	google::protobuf::TextFormat::PrintToString(device_config->GetDeviceType(device.device_identifier(), options), &str);
	std::cout << str;
	google::protobuf::TextFormat::PrintToString(device_config->GetFirmwareVersion(device.device_identifier(), options), &str);
	std::cout << str; 
	google::protobuf::TextFormat::PrintToString(device_config->GetBootloaderVersion(device.device_identifier(), options), &str); 
	std::cout << str;
	google::protobuf::TextFormat::PrintToString(device_config->GetModelNumber(device.device_identifier(), options), &str);
	std::cout << str;
	google::protobuf::TextFormat::PrintToString(device_config->GetPartNumber(device.device_identifier(), options), &str);     
	std::cout << str;
	google::protobuf::TextFormat::PrintToString(device_config->GetPartNumberRevision(device.device_identifier(), options), &str);
	std::cout << str;
	google::protobuf::TextFormat::PrintToString(device_config->GetSerialNumber(device.device_identifier(), options), &str);   
	std::cout << str;
	std::cout << std::endl;
}
```

<a id="markdown-other" name="other-services"></a>
## Other Services

The *device_identifier* can be used by other services to directly interrogate a device.

<a id="markdown-example" name="example-2"></a>
### Example

```cpp
namespace k_api = Kinova::Api;

/* API initialisation */
auto device_manager = new k_api::DeviceManager::DeviceManagerClient(router);
auto vision_config = new k_api::VisionConfig::VisionConfigClient(router);

auto allDevicesInfo = device_manager->ReadAllDevices();

// uses device routing information to route to every device (base, actuator, interconnect, etc.)
for (auto dev : allDevicesInfo.device_handle())
{	
    if (dev.device_type() == k_api::Common::DeviceTypes::VISION)
	{
	    std::cout << "-- Using Vision Config Service to get intrinsic parameters --" << std::endl;
	    k_api::VisionConfig::SensorIdentifier sensor_id;
		sensor_id.set_sensor(k_api::VisionConfig::SENSOR_COLOR);

		// We can now use the Vision service with the base connection by specifing the device_identifier
	    auto intrinsic_value = vision_config->GetIntrinsicParameters(sensor_id, dev.device_identifier());

	    std::cout << "Width: " << intrinsic_value.width() << std::endl;
	    std::cout << "Height: " << intrinsic_value.height() << std::endl;
	    std::cout << "Principal point x: " << intrinsic_value.principal_point_x() << std::endl;
	    std::cout << "Principal point y: " << intrinsic_value.principal_point_y() << std::endl;
	    std::cout << "Focal length x: " << intrinsic_value.focal_length_x() << std::endl;
	    std::cout << "Focal length y: " << intrinsic_value.focal_length_y() << std::endl;

	    break;
	}
}
```
