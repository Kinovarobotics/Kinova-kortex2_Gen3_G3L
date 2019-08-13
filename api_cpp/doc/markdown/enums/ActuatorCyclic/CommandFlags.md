# enum CommandFlags

## Overview / Purpose

Enumeration CommandFlags

|Enumerator|Value|Description|
|----------|-----|-----------|
|NO\_COMMAND|0|0x0 Default value|
|SERVO\_ENABLE|1|0x1 Servoing mode is enabled|
|BRAKE\_DISABLE|2|0x2 Brake normally applied, 1 disables brake|
|CLEAR\_MAJOR\_FAULT|4|0x4 Clear the major fault flag \(See StatusFlags\)|
|CLEAR\_MINOR\_FAULT|8|0x8 Clear the minor fault flag \(See StatusFlags\)|
|PROTECTIVE\_STOP|16|0x10 Protective stop has been activated|
|FORCE\_BRAKE\_RELEASE|32|0x20 Force a brake release|
|IGNORE|64|0x40 ignore the other CommandFlag bits|
|LOW\_GAINS|128|0x80 Use a set of specific gain value used by the joint admittance mode|
|LED\_0|256|0x100 Activate LED 0 \(interface module buttons 0\)|
|LED\_1|512|0x200 Activate LED 1 \(interface module buttons 1\)|

**Parent topic:** [ActuatorCyclic \(C++\)](../../summary_pages/ActuatorCyclic.md)

