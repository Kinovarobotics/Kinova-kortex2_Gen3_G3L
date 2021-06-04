# InterconnectConfig \(C++\)

This page describes the C++ InterconnectConfig API.

## RPC reference

This section describes the existing RPCs used in this API.

Service to get and set interface module \(interconnect\) configuration information, including user expansion

 **InterconnectConfigClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|GetUARTConfiguration|[UARTConfiguration](../messages/Common/UARTConfiguration.md#)|[UARTDeviceIdentification](../messages/Common/UARTDeviceIdentification.md#)|Retrieves user UART configuration|
|SetUARTConfiguration|[Empty](../messages/Common/Empty.md#)|[UARTConfiguration](../messages/Common/UARTConfiguration.md#)|Configures user UART|
|GetEthernetConfiguration|[EthernetConfiguration](../messages/InterconnectConfig/EthernetConfiguration.md#)|[EthernetDeviceIdentification](../messages/InterconnectConfig/EthernetDeviceIdentification.md#)|Retrieves user Ethernet configuration|
|SetEthernetConfiguration|[Empty](../messages/Common/Empty.md#)|[EthernetConfiguration](../messages/InterconnectConfig/EthernetConfiguration.md#)|Configures user Ethernet port|
|GetGPIOConfiguration|[GPIOConfiguration](../messages/InterconnectConfig/GPIOConfiguration.md#)|[GPIOIdentification](../messages/InterconnectConfig/GPIOIdentification.md#)|Retrieves user GPIO configuration|
|SetGPIOConfiguration|[Empty](../messages/Common/Empty.md#)|[GPIOConfiguration](../messages/InterconnectConfig/GPIOConfiguration.md#)|Configures user GPIO|
|GetGPIOState|[GPIOState](../messages/InterconnectConfig/GPIOState.md#)|[GPIOIdentification](../messages/InterconnectConfig/GPIOIdentification.md#)|Retrieves user GPIO state|
|SetGPIOState|[Empty](../messages/Common/Empty.md#)|[GPIOState](../messages/InterconnectConfig/GPIOState.md#)|Configures user GPIO state|
|GetI2CConfiguration|[I2CConfiguration](../messages/InterconnectConfig/I2CConfiguration.md#)|[I2CDeviceIdentification](../messages/InterconnectConfig/I2CDeviceIdentification.md#)|Retrieves user I2C configuration|
|SetI2CConfiguration|[Empty](../messages/Common/Empty.md#)|[I2CConfiguration](../messages/InterconnectConfig/I2CConfiguration.md#)|Configures user I2C|
|I2CRead|[I2CData](../messages/InterconnectConfig/I2CData.md#)|[I2CReadParameter](../messages/InterconnectConfig/I2CReadParameter.md#)|Performs an I2C read request|
|I2CReadRegister|[I2CData](../messages/InterconnectConfig/I2CData.md#)|[I2CReadRegisterParameter](../messages/InterconnectConfig/I2CReadRegisterParameter.md#)|Performs an I2C read register request|
|I2CWrite|[Empty](../messages/Common/Empty.md#)|[I2CWriteParameter](../messages/InterconnectConfig/I2CWriteParameter.md#)|Performs an I2C write request|
|I2CWriteRegister|[Empty](../messages/Common/Empty.md#)|[I2CWriteRegisterParameter](../messages/InterconnectConfig/I2CWriteRegisterParameter.md#)|Performs an I2C write register request|

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[EthernetConfiguration](../messages/InterconnectConfig/EthernetConfiguration.md#)|Ethernet configuration information|
|[EthernetDeviceIdentification](../messages/InterconnectConfig/EthernetDeviceIdentification.md#)|Ethernet device identification|
|[GPIOConfiguration](../messages/InterconnectConfig/GPIOConfiguration.md#)|GPIO configuration information|
|[GPIOIdentification](../messages/InterconnectConfig/GPIOIdentification.md#)|GPIO identification|
|[GPIOState](../messages/InterconnectConfig/GPIOState.md#)|GPIO state|
|[I2CConfiguration](../messages/InterconnectConfig/I2CConfiguration.md#)|I2C configuration information|
|[I2CData](../messages/InterconnectConfig/I2CData.md#)|I2C data|
|[I2CDeviceIdentification](../messages/InterconnectConfig/I2CDeviceIdentification.md#)|I2C device identification|
|[I2CReadParameter](../messages/InterconnectConfig/I2CReadParameter.md#)|I2C read request|
|[I2CReadRegisterParameter](../messages/InterconnectConfig/I2CReadRegisterParameter.md#)|I2C read register request|
|[I2CWriteParameter](../messages/InterconnectConfig/I2CWriteParameter.md#)|I2C write request|
|[I2CWriteRegisterParameter](../messages/InterconnectConfig/I2CWriteRegisterParameter.md#)|I2C write register request|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[EthernetDevice](../enums/InterconnectConfig/EthernetDevice.md#)|Admissible Ethernet device|
|[EthernetDuplex](../enums/InterconnectConfig/EthernetDuplex.md#)|Admissible Ethernet duplex mode|
|[EthernetSpeed](../enums/InterconnectConfig/EthernetSpeed.md#)|Admissible Ethernet speed|
|[GPIOIdentifier](../enums/InterconnectConfig/GPIOIdentifier.md#)|Admissible GPIO identifier|
|[GPIOMode](../enums/InterconnectConfig/GPIOMode.md#)|Admissible GPIO mode|
|[GPIOPull](../enums/InterconnectConfig/GPIOPull.md#)|Admissible GPIO pull mode|
|[GPIOValue](../enums/InterconnectConfig/GPIOValue.md#)|Admissible GPIO value|
|[I2CDevice](../enums/InterconnectConfig/I2CDevice.md#)|Admissible I2C device|
|[I2CDeviceAddressing](../enums/InterconnectConfig/I2CDeviceAddressing.md#)|I2C device addressing mode|
|[I2CMode](../enums/InterconnectConfig/I2CMode.md#)|I2C mode|
|[I2CRegisterAddressSize](../enums/InterconnectConfig/I2CRegisterAddressSize.md#)|I2C register address size|
|[SafetyIdentifier](../enums/InterconnectConfig/SafetyIdentifier.md#)|Admissible interface module safeties|
|[ServiceVersion](../enums/InterconnectConfig/ServiceVersion.md#)|Identifies InterconnectConfig current version|
|[UARTPortId](../enums/InterconnectConfig/UARTPortId.md#)|Admissible UART port|

