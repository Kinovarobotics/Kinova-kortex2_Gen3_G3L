# Enum CustomDataIndex

## Overview / Purpose

Enumeration CustomDataIndex

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
|FLOAT\_ABSOLUTE\_POSITION\_SENSOR|18|Absolute position sensor converted value \(degrees\)|
|FLOAT\_CONTROL\_POSITION\_JOINT\_REQUESTED|19|Last axis position command received via Ethernet|
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
|FLOAT\_CURRENT\_MOTOR\_CMD|53|Motor current command sent to motor drive \(Amperes\)|
|FLOAT\_TORQUE\_JOINT\_CMD|54|Axis torque command sent to joint torque control loop \(Newton-meters\)|
|FLOAT\_POSITION\_UNWRAPPED|55|Actuator position unwrapped \(degrees\)|
|UINT32\_HALL\_SENSOR\_0|56|Hall sensor 0 value \(raw\)|
|UINT32\_HALL\_SENSOR\_1|57|Hall sensor 1 value \(raw\)|
|UINT32\_HALL\_SENSOR\_2|58|Hall sensor 2 value \(raw\)|
|INT32\_HALL\_SENSOR\_SCALED\_0|59|Hall sensor 0 scaled value \(raw\)|
|INT32\_HALL\_SENSOR\_SCALED\_1|60|Hall sensor 1 scaled value \(raw\)|
|INT32\_HALL\_SENSOR\_SCALED\_2|61|Hall sensor 2 scaled value \(raw\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_0|62|Cogging torque cancellation coefficient A0 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_1|63|Cogging torque cancellation coefficient A1 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_2|64|Cogging torque cancellation coefficient A2 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_3|65|Cogging torque cancellation coefficient A3 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_4|66|Cogging torque cancellation coefficient A4 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_5|67|Cogging torque cancellation coefficient A5 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_6|68|Cogging torque cancellation coefficient A6 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_7|69|Cogging torque cancellation coefficient A7 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_8|70|Cogging torque cancellation coefficient A8 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_9|71|Cogging torque cancellation coefficient A9 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_10|72|Cogging torque cancellation coefficient A10 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_11|73|Cogging torque cancellation coefficient A11 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_12|74|Cogging torque cancellation coefficient A12 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_13|75|Cogging torque cancellation coefficient A13 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_14|76|Cogging torque cancellation coefficient A14 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_A\_15|77|Cogging torque cancellation coefficient A15 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_0|78|Cogging torque cancellation coefficient B0 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_1|79|Cogging torque cancellation coefficient B1 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_2|80|Cogging torque cancellation coefficient B2 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_3|81|Cogging torque cancellation coefficient B3 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_4|82|Cogging torque cancellation coefficient B4 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_5|83|Cogging torque cancellation coefficient B5 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_6|84|Cogging torque cancellation coefficient B6 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_7|85|Cogging torque cancellation coefficient B7 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_8|86|Cogging torque cancellation coefficient B8 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_9|87|Cogging torque cancellation coefficient B9 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_10|88|Cogging torque cancellation coefficient B10 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_11|89|Cogging torque cancellation coefficient B11 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_12|90|Cogging torque cancellation coefficient B12 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_13|91|Cogging torque cancellation coefficient B13 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_14|92|Cogging torque cancellation coefficient B14 \(Amperes\)|
|FLOAT\_COGGING\_COEFFICIENT\_B\_15|93|Cogging torque cancellation coefficient B15 \(Amperes\)|
|FLOAT\_CURRENT\_COGGING\_FEEDFORWARD|94|Commanded cogging cancellation feedforward current sent to motor drive \(Amperes\)|

**Parent topic:** [ActuatorConfig \(Python\)](../../summary_pages/ActuatorConfig.md)

