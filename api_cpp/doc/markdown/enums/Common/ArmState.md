# enum ArmState

## Overview / Purpose

Enumeration ArmState

|Enumerator|Value|Description|
|----------|-----|-----------|
|ARMSTATE\_UNSPECIFIED|0|Unspecified arm state|
|ARMSTATE\_BASE\_INITIALIZATION|1|Cannot be reported as the Base initialization must be completed before allowing user connection|
|ARMSTATE\_IDLE|2|Base initialization succeeded|
|ARMSTATE\_INITIALIZATION|3|Arm is being initialized|
|ARMSTATE\_IN\_FAULT|4|Arm is in fault|
|ARMSTATE\_MAINTENANCE|5|Arm is in maintenance|
|ARMSTATE\_SERVOING\_LOW\_LEVEL|6|Arm is in low-level servoing mode|
|ARMSTATE\_SERVOING\_READY|7|Arm is ready to be controlled|
|ARMSTATE\_SERVOING\_PLAYING\_SEQUENCE|8|Arm is currently being controlled via a sequence|
|ARMSTATE\_SERVOING\_MANUALLY\_CONTROLLED|9|Arm is currently being controlled manually|
|ARMSTATE\_RESERVED|255|For debugging, this state must never be reported outside the base. this means that a state is not mapped correctly|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

