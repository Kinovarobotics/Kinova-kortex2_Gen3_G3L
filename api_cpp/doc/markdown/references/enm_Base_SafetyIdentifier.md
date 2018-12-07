# Enum SafetyIdentifier

This page describes the C++ Kinova::Api::Base::SafetyIdentifier enumeration.

## Overview / Purpose

List of admissible Base safeties. Used with BaseCyclic.BaseFeedback.\[fault\_bank\_a | fault\_bank\_b | warning\_bank\_a | warning\_bank\_b\]

## Enumeration definition

|Enumerator|Value|Description|
|----------|-----|-----------|
|UNSPECIFIED\_BASE\_SAFETY\_IDENTIFIER|0|0x0 - Unspecified base safety|
|FIRMWARE\_UPDATE\_FAILURE|1|0x1 - Firmware update failure|
|EXTERNAL\_COMMUNICATION\_ERROR|2|0x2 - External communication error \(future\)|
|MAXIMUM\_AMBIENT\_TEMPERATURE|4|0x4 - Maximum ambient temperature reached|
|MAXIMUM\_CORE\_TEMPERATURE|8|0x8 - Maximum core temperature reached|
|JOINT\_FAULT|16|0x10 - Joint fault|
|CYCLIC\_DATA\_JITTER|32|0x20 - Cyclic data jitter \(future\)|
|REACHED\_MAXIMUM\_EVENT\_LOGS|64|0x40 - Reached Maximum number of event log entries \(future\)|
|NO\_KINEMATICS\_SUPPORT|128|0x80 - No kinematics support \(future\)|
|ABOVE\_MAXIMUM\_DOF|256|0x100 - Above maximum DoF|
|NETWORK\_ERROR|512|0x200 - Network error \(future\)|
|UNABLE\_TO\_REACH\_POSE|1024|0x400 - Unable to reach pose|
|JOINT\_DETECTION\_ERROR|2048|0x800 - Joint detection error|
|NETWORK\_INITIALIZATION\_ERROR|4096|0x1000 - Network initialization error|
|MAXIMUM\_CURRENT|8192|0x2000 - Maximum current reached|
|MAXIMUM\_VOLTAGE|16384|0x4000 - Maximum voltage reached|
|MINIMUM\_VOLTAGE|32768|0x8000 - Minimum voltage reached|
|MAXIMUM\_END\_EFFECTOR\_TRANSLATION\_VELOCITY|65536|0x10000 - Maximum end effector translation velocity reached \(future\)|
|MAXIMUM\_END\_EFFECTOR\_ORIENTATION\_VELOCITY|131072|0x20000 - Maximum end effector orientation velocity reached \(future\)|
|MAXIMUM\_END\_EFFECTOR\_TRANSLATION\_ACCELERATION|262144|0x40000 - Maximum end effector translation acceleration reached \(future\)|
|MAXIMUM\_END\_EFFECTOR\_ORIENTATION\_ACCELERATION|524288|0x80000 - Maximum end effector orientation acceleration reached \(future\)|
|MAXIMUM\_END\_EFFECTOR\_TRANSLATION\_FORCE|1048576|0x100000 - Maximum end effector translation force reached \(future\)|
|MAXIMUM\_END\_EFFECTOR\_ORIENTATION\_FORCE|2097152|0x200000 - Maximum end effector orientation force reached \(future\)|
|MAXIMUM\_END\_EFFECTOR\_PAYLOAD|4194304|0x400000 - Maximum end effector payload reached \(future\)|
|EMERGENCY\_STOP\_ACTIVATED|8388608|0x800000 - Emergency stop activated|
|EMERGENCY\_LINE\_ACTIVATED|16777216|0x1000000 - Emergency line activated|
|INRUSH\_CURRENT\_LIMITER\_FAULT|33554432|0x2000000 - In rush current limiter fault|
|NVRAM\_CORRUPTED|67108864|0x4000000 - NVRAM corrupted \(future\)|
|INCOMPATIBLE\_FIRMWARE\_VERSION|134217728|0x8000000 - Incompatible firmware version|
|POWERON\_SELF\_TEST\_FAILURE|268435456|0x10000000 - Power on seflt test failure|

**Parent topic:** [Base](../references/summary_Base.md)

