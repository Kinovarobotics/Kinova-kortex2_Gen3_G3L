# DeviceConfig \(C++\)

This page describes the C++ DeviceConfig API.

## RPC reference

This section describes the existing RPCs used in this API.

Service to get and set device configuration information

 **DeviceConfigClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|GetRunMode|[RunMode](../messages/DeviceConfig/RunMode.md#)|[Empty](../messages/Common/Empty.md#)|Returns the run mode for the device|
|SetRunMode|[Empty](../messages/Common/Empty.md#)|[RunMode](../messages/DeviceConfig/RunMode.md#)|Sets the run mode for the device|
|GetDeviceType|[DeviceType](../messages/DeviceConfig/DeviceType.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the type for the device|
|GetFirmwareVersion|[FirmwareVersion](../messages/DeviceConfig/FirmwareVersion.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device firmware version|
|GetBootloaderVersion|[BootloaderVersion](../messages/DeviceConfig/BootloaderVersion.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device bootloader version|
|GetModelNumber|[ModelNumber](../messages/DeviceConfig/ModelNumber.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device model number|
|GetPartNumber|[PartNumber](../messages/DeviceConfig/PartNumber.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device part number|
|GetSerialNumber|[SerialNumber](../messages/DeviceConfig/SerialNumber.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device serial number|
|GetMACAddress|[MACAddress](../messages/DeviceConfig/MACAddress.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device MAC address|
|GetIPv4Settings|[IPv4Settings](../messages/DeviceConfig/IPv4Settings.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device IPv4 settings \(not implemented on Base\)|
|SetIPv4Settings|[Empty](../messages/Common/Empty.md#)|[IPv4Settings](../messages/DeviceConfig/IPv4Settings.md#)|Sets the device IPv4 settings \(not implemented on Base\)|
|GetPartNumberRevision|[PartNumberRevision](../messages/DeviceConfig/PartNumberRevision.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the device part number revision|
|RebootRequest|[Empty](../messages/Common/Empty.md#)|[RebootRqst](../messages/DeviceConfig/RebootRqst.md#)|Sends a request to the device to reboot|
|SetSafetyEnable|[Empty](../messages/Common/Empty.md#)|[SafetyEnable](../messages/DeviceConfig/SafetyEnable.md#)|Enables \(disable\) the specified safety|
|SetSafetyErrorThreshold|[Empty](../messages/Common/Empty.md#)|[SafetyThreshold](../messages/DeviceConfig/SafetyThreshold.md#)|Sets the error threshold for the specified safety|
|SetSafetyWarningThreshold|[Empty](../messages/Common/Empty.md#)|[SafetyThreshold](../messages/DeviceConfig/SafetyThreshold.md#)|Sets the warning threshold for the specified safety|
|SetSafetyConfiguration|[Empty](../messages/Common/Empty.md#)|[SafetyConfiguration](../messages/DeviceConfig/SafetyConfiguration.md#)|Configures the specified safety \(i.e. sets error and warning thresholds\)|
|GetSafetyConfiguration|[SafetyConfiguration](../messages/DeviceConfig/SafetyConfiguration.md#)|[SafetyHandle](../messages/Common/SafetyHandle.md#)|Retrieves configuration about the specified safety|
|GetSafetyInformation|[SafetyInformation](../messages/DeviceConfig/SafetyInformation.md#)|[SafetyHandle](../messages/Common/SafetyHandle.md#)|Retrieves information about the specified safety|
|GetSafetyEnable|[SafetyEnable](../messages/DeviceConfig/SafetyEnable.md#)|[SafetyHandle](../messages/Common/SafetyHandle.md#)|Indicates if specified safety is enabled \(or disabled\)|
|GetSafetyStatus|[SafetyStatus](../messages/DeviceConfig/SafetyStatus.md#)|[SafetyHandle](../messages/Common/SafetyHandle.md#)|Indicates if the specified safety is raised|
|ClearAllSafetyStatus|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Clear all safety status for this device if they are no longer raised|
|ClearSafetyStatus|[Empty](../messages/Common/Empty.md#)|[SafetyHandle](../messages/Common/SafetyHandle.md#)|Clear a specific safety status if it is no longer raised|
|GetAllSafetyConfiguration|[SafetyConfigurationList](../messages/DeviceConfig/SafetyConfigurationList.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves configuration on all safeties|
|GetAllSafetyInformation|[SafetyInformationList](../messages/DeviceConfig/SafetyInformationList.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves information on all safeties|
|ResetSafetyDefaults|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Restores all safety configurations to factory defaults|
|OnNotificationSafetyTopic|[NotificationHandle](../messages/Common/NotificationHandle.md#)|[NotificationOptions](../messages/Common/NotificationOptions.md#)|Subscribes to safety notifications|
|ExecuteCalibration|[Empty](../messages/Common/Empty.md#)|[Calibration](../messages/DeviceConfig/Calibration.md#)|Starts device calibration \(intended for Kinova Production of Pico\)|
|GetCalibrationResult|[CalibrationResult](../messages/DeviceConfig/CalibrationResult.md#)|[CalibrationElement](../messages/DeviceConfig/CalibrationElement.md#)|Retrieves the status/result of device calibration \(intended for Kinova Production of Pico\)|
|StopCalibration|[CalibrationResult](../messages/DeviceConfig/CalibrationResult.md#)|[Calibration](../messages/DeviceConfig/Calibration.md#)|Stop calibration in progress|
|SetCapSenseConfig|[Empty](../messages/Common/Empty.md#)|[CapSenseConfig](../messages/DeviceConfig/CapSenseConfig.md#)|Sets the capacitive sensor calibration|
|GetCapSenseConfig|[CapSenseConfig](../messages/DeviceConfig/CapSenseConfig.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the capacitive sensor calibration|
|ReadCapSenseRegister|[CapSenseRegister](../messages/DeviceConfig/CapSenseRegister.md#)|[CapSenseRegister](../messages/DeviceConfig/CapSenseRegister.md#)|Reads low-level register from the capacitive sensor \(for Kinova internal use ony, not to be used in the field\)|
|WriteCapSenseRegister|[Empty](../messages/Common/Empty.md#)|[CapSenseRegister](../messages/DeviceConfig/CapSenseRegister.md#)|Writes to low-level register of the capacitive sensor \(for Kinova internal use ony, not to be used in the field\)|

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[BootloaderVersion](../messages/DeviceConfig/BootloaderVersion.md#)|Bootloader version for the device|
|[Calibration](../messages/DeviceConfig/Calibration.md#)|Calibration information to push to device|
|[CalibrationElement](../messages/DeviceConfig/CalibrationElement.md#)|Calibration element|
|[CalibrationParameter](../messages/DeviceConfig/CalibrationParameter.md#)|Single calibration parameter information|
|[CalibrationResult](../messages/DeviceConfig/CalibrationResult.md#)|Result of a calibration|
|[CapSenseConfig](../messages/DeviceConfig/CapSenseConfig.md#)|Capacitive sensor configuration message|
|[CapSenseRegister](../messages/DeviceConfig/CapSenseRegister.md#)|Message used to address a register|
|[DeviceType](../messages/DeviceConfig/DeviceType.md#)|Device type|
|[FirmwareVersion](../messages/DeviceConfig/FirmwareVersion.md#)|Firmware version for the device|
|[IPv4Settings](../messages/DeviceConfig/IPv4Settings.md#)|IPv4 settings for the device, including address, subnet mask, and default gateway|
|[MACAddress](../messages/DeviceConfig/MACAddress.md#)|MAC address for the device|
|[ModelNumber](../messages/DeviceConfig/ModelNumber.md#)|Model number for the device|
|[PartNumber](../messages/DeviceConfig/PartNumber.md#)|Part number for the device|
|[PartNumberRevision](../messages/DeviceConfig/PartNumberRevision.md#)|Part number revision for the device|
|[PowerOnSelfTestResult](../messages/DeviceConfig/PowerOnSelfTestResult.md#)|Result of power on self test|
|[RebootRqst](../messages/DeviceConfig/RebootRqst.md#)|Reboot request with bootloader delay|
|[RunMode](../messages/DeviceConfig/RunMode.md#)|Run mode|
|[SafetyConfiguration](../messages/DeviceConfig/SafetyConfiguration.md#)|Configuration for a safety|
|[SafetyConfigurationList](../messages/DeviceConfig/SafetyConfigurationList.md#)|Array of safety configurations|
|[SafetyEnable](../messages/DeviceConfig/SafetyEnable.md#)|Enable or disable a specific safety|
|[SafetyInformation](../messages/DeviceConfig/SafetyInformation.md#)|Information about a specific safety|
|[SafetyInformationList](../messages/DeviceConfig/SafetyInformationList.md#)|Array of safety information|
|[SafetyStatus](../messages/DeviceConfig/SafetyStatus.md#)|Safety status|
|[SafetyThreshold](../messages/DeviceConfig/SafetyThreshold.md#)|Configure threshold of a specific safety|
|[SerialNumber](../messages/DeviceConfig/SerialNumber.md#)|Serial number for the device|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[CalibrationItem](../enums/DeviceConfig/CalibrationItem.md#)|Admissible calibration items|
|[CalibrationStatus](../enums/DeviceConfig/CalibrationStatus.md#)|Admissible calibration status|
|[CapSenseMode](../enums/DeviceConfig/CapSenseMode.md#)|Admissible capacitive sensor mode|
|[RunModes](../enums/DeviceConfig/RunModes.md#)|Options for the run mode for the device|
|[SafetyLimitType](../enums/DeviceConfig/SafetyLimitType.md#)|Types of safeties limits|
|[ServiceVersion](../enums/DeviceConfig/ServiceVersion.md#)|Identifies DeviceConfig current version|

