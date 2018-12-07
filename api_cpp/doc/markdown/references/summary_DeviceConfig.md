# DeviceConfig

This page describes the C++ Kinova::Api::DeviceConfig package.

## Overview / Purpose

Service to get and set device configuration information

## API reference

This section describes procedure calls / methods exposed by the DeviceConfig package, including the return data type, input data type, and description of what the method does. For Kinova-defined data types, you can click through to read more about the data type, its data fields, and its related methods.

 **Methods** 

Every method listed below, except the notification subscription methods \(begining with 'OnNotification'\) are available in three different forms :

-   **blocking** : called using listed method name \(default\)
-   **future/promise** : called using listed method name followed by the '**\_async**' suffix
-   **regiser callback** : called using listed method name followed by the '**\_callback**' suffix

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|ClearAllSafetyStatus|void|void|Clear all safety status for this device if they are no longer raised|
|ClearSafetyStatus|void|[SafetyHandle](msg_Common_SafetyHandle.md#)|Clear a specific safety status if it is no longer raised|
|GetAllSafetyConfiguration|[SafetyConfigurationList](msg_DeviceConfig_SafetyConfigurationList.md#)|void|Gets configuration on every safeties|
|GetAllSafetyInformation|[SafetyInformationList](msg_DeviceConfig_SafetyInformationList.md#)|void|Gets information on every safeties|
|GetBootloaderVersion|[BootloaderVersion](msg_DeviceConfig_BootloaderVersion.md#)|void|Returns the device bootloader version|
|GetDeviceType|[DeviceType](msg_DeviceConfig_DeviceType.md#)|void|Returns the type for the device|
|GetFirmwareVersion|[FirmwareVersion](msg_DeviceConfig_FirmwareVersion.md#)|void|Returns the device firmware version|
|GetIPv4Settings|[IPv4Settings](msg_DeviceConfig_IPv4Settings.md#)|void|Returns the device IPv4 settings \(not implemented on Base\)|
|GetMACAddress|[MACAddress](msg_DeviceConfig_MACAddress.md#)|void|Returns the device MAC address|
|GetModelNumber|[ModelNumber](msg_DeviceConfig_ModelNumber.md#)|void|Returns the device model number|
|GetPartNumber|[PartNumber](msg_DeviceConfig_PartNumber.md#)|void|Returns the device part number|
|GetPartNumberRevision|[PartNumberRevision](msg_DeviceConfig_PartNumberRevision.md#)|void|Returns the device part number revision|
|GetPowerOnSelfTestResult|[PowerOnSelfTestResult](msg_DeviceConfig_PowerOnSelfTestResult.md#)|void|Returns the result on the device power on self test \(future\)|
|GetRunMode|[RunMode](msg_DeviceConfig_RunMode.md#)|void|Returns the run mode for the device \(future\)|
|GetSafetyConfiguration|[SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)|[SafetyHandle](msg_Common_SafetyHandle.md#)|Retrieves configuration about the specified safety|
|GetSafetyEnable|[SafetyEnable](msg_DeviceConfig_SafetyEnable.md#)|[SafetyHandle](msg_Common_SafetyHandle.md#)|Indicates if specified safety is enabled \(or disabled\)|
|GetSafetyInformation|[SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)|[SafetyHandle](msg_Common_SafetyHandle.md#)|Retrieves information about the specified safety|
|GetSafetyStatus|[SafetyStatus](msg_DeviceConfig_SafetyStatus.md#)|[SafetyHandle](msg_Common_SafetyHandle.md#)|Indicates if the specified safety is raised|
|GetSerialNumber|[SerialNumber](msg_DeviceConfig_SerialNumber.md#)|void|Returns the device serial number|
|OnNotificationSafetyTopic|[NotificationHandle](msg_Common_NotificationHandle.md#)|[NotificationOptions](msg_Common_NotificationOptions.md#)|Subscribes to safety notifications \(future\)|
|RebootRequest|void|[RebootRqst](msg_DeviceConfig_RebootRqst.md#)|Sends a request to the device to reboot|
|ResetSafetyDefaults|void|void|Puts back all safety configuration to factory defaults \(future\)|
|SetIPv4Settings|void|[IPv4Settings](msg_DeviceConfig_IPv4Settings.md#)|Configures the device IPv4 settings \(not implemented on Base\)|
|SetMACAddress|void|[MACAddress](msg_DeviceConfig_MACAddress.md#)|Sets the device MAC address \(intented for Kinova Production\) \(future\)|
|SetModelNumber|void|[ModelNumber](msg_DeviceConfig_ModelNumber.md#)|Sets the device model number \(intented for Kinova Production\) \(future\)|
|SetPartNumber|void|[PartNumber](msg_DeviceConfig_PartNumber.md#)|Sets the device part number \(intented for Kinova Production\) \(future\)|
|SetPartNumberRevision|void|[PartNumberRevision](msg_DeviceConfig_PartNumberRevision.md#)|Sets the device part number revision \(intented for Kinova Production\) \(future\)|
|SetRunMode|void|[RunMode](msg_DeviceConfig_RunMode.md#)|Sets the run mode for the device \(future\)|
|SetSafetyConfiguration|void|[SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)|Configures the specified safety \(i.e. sets error and warning thresholds\) \(future\)|
|SetSafetyEnable|void|[SafetyEnable](msg_DeviceConfig_SafetyEnable.md#)|Enables \(disable\) the specified safety \(future\)|
|SetSafetyErrorThreshold|void|[SafetyThreshold](msg_DeviceConfig_SafetyThreshold.md#)|Sets the Error threshold for the specified safety \(future\)|
|SetSafetyWarningThreshold|void|[SafetyThreshold](msg_DeviceConfig_SafetyThreshold.md#)|Sets the Warning threshold for the specified safety \(future\)|
|SetSerialNumber|void|[SerialNumber](msg_DeviceConfig_SerialNumber.md#)|Sets the device serial number \(intented for Kinova Production\) \(future\)|

## Data types reference

This section describes the data types used in the DeviceConfig package methods, including message classes and enumerations. Click through the links to read more about the data types.

 **Messages** 

|Message|Description|
|-------|-----------|
|[BootloaderVersion](msg_DeviceConfig_BootloaderVersion.md#)|Message specifying the bootloader version for the device|
|[DeviceType](msg_DeviceConfig_DeviceType.md#)|Message specifying the device type|
|[FirmwareVersion](msg_DeviceConfig_FirmwareVersion.md#)|Message specifying the firmware version for the device|
|[IPv4Settings](msg_DeviceConfig_IPv4Settings.md#)|Message containing the IPv4 settings for the device, including address, subnet mask, and default gateway|
|[MACAddress](msg_DeviceConfig_MACAddress.md#)|MAC address for the device|
|[ModelNumber](msg_DeviceConfig_ModelNumber.md#)|Message specifying the model number for the device|
|[PartNumber](msg_DeviceConfig_PartNumber.md#)|String specifiying the part number for the device|
|[PartNumberRevision](msg_DeviceConfig_PartNumberRevision.md#)|String specifying part number revision for the device|
|[PowerOnSelfTestResult](msg_DeviceConfig_PowerOnSelfTestResult.md#)|Result of power on self test|
|[RebootRqst](msg_DeviceConfig_RebootRqst.md#)|Reboot request with bootloader delay|
|[RunMode](msg_DeviceConfig_RunMode.md#)|Message specifying the run mode|
|[SafetyConfiguration](msg_DeviceConfig_SafetyConfiguration.md#)|Configure a safety|
|[SafetyConfigurationList](msg_DeviceConfig_SafetyConfigurationList.md#)|Array of safety configuration|
|[SafetyEnable](msg_DeviceConfig_SafetyEnable.md#)|Enable or disable a specific safety|
|[SafetyInformation](msg_DeviceConfig_SafetyInformation.md#)|Information about a particular safety|
|[SafetyInformationList](msg_DeviceConfig_SafetyInformationList.md#)|Array of safety information|
|[SafetyStatus](msg_DeviceConfig_SafetyStatus.md#)|Provides safety status|
|[SafetyThreshold](msg_DeviceConfig_SafetyThreshold.md#)|Configure threshold of a specific safety|
|[SerialNumber](msg_DeviceConfig_SerialNumber.md#)|String specifying the serial number for the device|

 **Enumerations** 

|Enumeration|Description|
|-----------|-----------|
|[RunModes](enm_DeviceConfig_RunModes.md#)|Options for the run mode for the device|
|[SafetyLimitType](enm_DeviceConfig_SafetyLimitType.md#)|Types of safeties limits|
|[ServiceVersion](enm_DeviceConfig_ServiceVersion.md#)|Enumeration used to identify DeviceConfig current version|

**Parent topic:** [KINOVA® KORTEX™ C++ API Reference](../index.md#)

