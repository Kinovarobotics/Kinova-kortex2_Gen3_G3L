# Enum CustomDataIndex

This page describes the C++ Kinova::Api::ActuatorConfig::CustomDataIndex enumeration.

## Overview / Purpose

## Enumeration definition

|Enumerator|Value|Description|
|----------|-----|-----------|
|NO\_CUSTOM\_DATA\_SELECTED|0|No custom data selected|
|UINT32\_TEST\_RAMP|1|Incremental value used for test and validation|
|UINT32\_MOTOR\_ENCODER\_RAW|2|Rotor optical encoder incremental value \(raw\)|
|UINT32\_JOINT\_ENCODER\_RAW|3|Joint optical encoder incremental value \(raw\)|
|FLOAT\_TEMPERATURE\_PHASE\_0|4|Motor phase 0 temperature \(degrees Celsius\)|
|FLOAT\_TEMPERATURE\_PHASE\_1|5|Motor phase 1 temperature \(degrees Celsius\)|
|FLOAT\_TEMPERATURE\_PHASE\_2|6|Motor phase 2 temperature \(degrees Celsius\)|
|INT32\_TORQUE\_SENSOR\_RAW\_0|7|Individual torque sensor strain gauge 0 ADC value \(raw\)|
|INT32\_TORQUE\_SENSOR\_RAW\_1|8|Individual torque sensor strain gauge 1 ADC value \(raw\)|
|INT32\_TORQUE\_SENSOR\_RAW\_2|9|Individual torque sensor strain gauge 2 ADC value \(raw\)|
|INT32\_TORQUE\_SENSOR\_RAW\_3|10|Individual torque sensor strain gauge 3 ADC value \(raw\)|
|FLOAT\_TORQUE\_SENSOR\_0|11|Individual torque sensor strain gauge 0 converted value \(Newton-meters\)|
|FLOAT\_TORQUE\_SENSOR\_1|12|Individual torque sensor strain gauge 1 converted value \(Newton-meters\)|
|FLOAT\_TORQUE\_SENSOR\_2|13|Individual torque sensor strain gauge 2 converted value \(Newton-meters\)|
|FLOAT\_TORQUE\_SENSOR\_3|14|Individual torque sensor strain gauge 3 converted value \(Newton-meters\)|
|UINT32\_MOTOR\_ENCODER\_RAW\_LATCH\_ON\_INDEX\_RISING|15|Rotor optical encoder incremental value at last index signal rising edge \(raw\)|
|UINT32\_JOINT\_ENCODER\_RAW\_LATCH\_ON\_INDEX\_RISING|16|Joint optical encoder incremental value at last index signal rising edge \(raw\)|
|UINT32\_ABSOLUTE\_POSITION\_SENSOR\_RAW|17|Absolute position sensor integer value \(raw\)|
|FLOAT\_ABSOLUTE\_POSITION\_SENSOR|18|Absolute position sensor converted value \(degrees\) FLOAT\_CONTROL\_POSITION\_JOINT\_REQUESTED = 19; // Last axis position command received via Ethernet|
|UINT32\_JIG\_FLAGS|20|Jig status flags \(internal use\)|
|UINT32\_TICK\_MOTOR\_CONTROL|21|Rotor optical encoder incremental value corrected for counter overflow \(raw\)|
|UINT32\_TICK\_JOINT\_CONTROL|22|Joint optical encoder incremental value corrected for counter overflow \(raw\)|
|UINT32\_INDEX\_TICK\_MOTOR\_CONTROL|23|Rotor optical encoder incremental value corrected for counter overflow at last index signal rising edge \(raw\)|
|UINT32\_INDEX\_TICK\_JOINT\_CONTROL|24|Joint optical encoder incremental value corrected for counter overflow at last index signal rising edge \(raw\)|
|FLOAT\_ACCELERATION\_X|25|x-axis acceleration \(meters per second squared\)|
|FLOAT\_ACCELERATION\_Y|26|y-axis acceleration \(meters per second squared\)|
|FLOAT\_ACCELERATION\_Z|27|z-axis acceleration \(meters per second squared\)|
|FLOAT\_ANGULAR\_RATE\_X|28|x-axis angular velocity \(degrees per second\)|
|FLOAT\_ANGULAR\_RATE\_Y|29|y-axis angular velocity \(degrees per second\)|
|FLOAT\_ANGULAR\_RATE\_Z|30|z-axis angular velocity \(degrees per second\)|
|FLOAT\_POSITION\_MOTOR\_CMD|31|Axis position command sent to motor position control loop \(degrees\)|
|FLOAT\_VELOCITY\_MOTOR\_CMD|32|Axis velocity command sent to motor velocity control loop \(degrees per second\)|
|FLOAT\_POSITION\_MOTOR|33|Actuator position measured by rotor optical encoder \(degrees\)|
|FLOAT\_VELOCITY\_MOTOR|34|Actuator angular velocity measured by rotor optical encoder \(degrees per second\)|
|UINT32\_COMMUNICATIONS\_JITTER|35|Jitter from the communication \(microseconds\)|
|FLOAT\_TORQUE\_AVERAGE|36|Actuator torque \(Newton-meters\)|
|FLOAT\_CURRENT\_MOTOR|37|Motor current \(Amperes\)|
|FLOAT\_VOLTAGE\_DIGITAL|38|Main board voltage \(Volts\)|
|FLOAT\_TEMPERATURE\_MOTOR\_CELSIUS|39|Motor temperature \(maximum of the three \(3\) phase temperatures\) \(degrees Celsius\)|
|FLOAT\_TEMPERATURE\_CORE\_CELSIUS|40|Microcontroller temperature \(degrees Celsius\)|
|UINT32\_FAULT\_A|41|Bank A faults \(see ActuatorConfig.SafetyIdentifier\)|
|UINT32\_FAULT\_B|42|Bank B faults \(see ActuatorConfig.SafetyIdentifier\)|
|UINT32\_WARNING\_A|43|Bank A warnings \(see ActuatorConfig.SafetyIdentifier\)|
|UINT32\_WARNING\_B|44|Bank B warnings \(see ActuatorConfig.SafetyIdentifier\)|
|FLOAT\_POSITION\_FROM\_HALLS|45|Actuator position measured by motor hall sensors \(degrees\)|
|FLOAT\_PHASE\_CURRENT\_0|46|Motor phase 0 current \(Amperes\)|
|FLOAT\_PHASE\_CURRENT\_1|47|Motor phase 1 current \(Amperes\)|
|FLOAT\_PHASE\_CURRENT\_2|48|Motor phase 2 current \(Amperes\)|
|FLOAT\_PHASE\_PWM\_0|49|Pulse width modulation duty cycle applied to motor phase 0 \(percentage\)|
|FLOAT\_PHASE\_PWM\_1|50|Pulse width modulation duty cycle applied to motor phase 1 \(percentage\)|
|FLOAT\_PHASE\_PWM\_2|51|Pulse width modulation duty cycle applied to motor phase 2 \(percentage\)|
|FLOAT\_MOTOR\_ELECTRICAL\_ANGLE|52|Motor electrical angle \(degrees\)|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

