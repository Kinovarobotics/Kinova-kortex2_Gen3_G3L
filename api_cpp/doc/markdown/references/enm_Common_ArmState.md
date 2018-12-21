# Enum ArmState

This page describes the C++ Kinova::Api::Common::ArmState enumeration.

## Overview / Purpose

List of admissible arm states

## Enumeration definition

|Enumerator|Value|Description|
|----------|-----|-----------|
|UNSPECIFIED\_ARM\_STATE|0|Unspecified arm state|
|BASE\_INITIALIZATION|1|Cannot be reported as the base initialization must be completed before allowing user connection|
|IDLE|2|Base initialization succeeded|
|ARM\_INITIALIZATION|3|Arm is being initialized|
|ARM\_IN\_FAULT|4|Arm is in fault|
|ARM\_MAINTENANCE|5|Arm is in maintenance|
|ARM\_SERVOING\_LOW\_LEVEL|6|Arm is in low-level servoing mode|
|ARM\_SERVOING\_READY|7|Arm is ready to be controlled|
|ARM\_SERVOING\_PLAYING\_SEQUENCE|8|Arm is currently being controlled via a sequence|
|ARM\_SERVOING\_MANUALLY\_CONTROLLED|9|Arm is currently being controlled manually|
|RESERVED|255|For debugging, this state must never be reported outside the base. this means that a state is not mapped correctly|

**Parent topic:** [Common](../references/summary_Common.md)

