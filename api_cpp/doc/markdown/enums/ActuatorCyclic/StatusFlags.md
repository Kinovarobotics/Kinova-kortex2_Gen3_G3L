# enum StatusFlags

## Overview / Purpose

Enumeration StatusFlags

|Enumerator|Value|Description|
|----------|-----|-----------|
|UNKNOWN\_STATUS|0|0x0 Unknown status|
|STABILIZED|16|0x10 Actuator is in a stable state|
|MOTOR\_INDEXED|32|0x20 Position sensor is indexed|
|MOTOR\_INDEXING|64|0x40 Position sensor is indexing|
|JOINT\_INDEXED|128|0x80 Reserved|
|JOINT\_INDEXING|256|0x100 Reserved|
|HIGH\_PRECISION|512|0x200 Reserved|
|BRAKING|1024|0x400 The actuator is braking|
|SERVOING|2048|0x800 The actuator is in servoing mode|
|MAJOR\_FAULT|4096|0x1000 A major fault has occurred|
|MINOR\_FAULT|8192|0x2000 A minor fault has occurred|
|CALIBRATED\_TORQUE|16384|0x4000 The torque sensor is calibrated|
|CALIBRATED\_MAG\_SENSOR|32768|0x8000 The magnetic sensor is calibrated|
|CALIBRATED\_ZERO|65536|0x10000 The zero position calibration has been performed|
|GPIO\_0|131072|0x20000 Reserved|
|GPIO\_1|262144|0x40000 Reserved|
|CS\_QUASI\_STATIC\_CONTACT|524288|0x80000 Reserved|
|CS\_TRANSIENT\_CONTACT|1048576|0x100000 Reserved|
|VFD\_HALL\_SYNC|2097152|0x200000 Reserved|
|VFD\_INDEXED|4194304|0x400000 Reserved|
|DRIVE\_BOARD\_READY|8388608|0x800000 Reserved|
|CALIBRATED\_CURRENT|16777216|0x1000000 Current sensor is calibrated|
|CALIBRATED\_MOTOR|33554432|0x2000000 Motor is calibrated|
|SW0\_ACTIVE|67108864|0x4000000 Status of interface module buttons 0|
|SW1\_ACTIVE|134217728|0x8000000 Status of interface module buttons 1|

**Parent topic:** [ActuatorCyclic \(C++\)](../../summary_pages/ActuatorCyclic.md)

