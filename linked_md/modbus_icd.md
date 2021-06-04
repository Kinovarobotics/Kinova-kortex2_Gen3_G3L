<!--
  KINOVA (R) KORTEX (TM)
  Copyright (c) 2021 Kinova inc. All rights reserved.
  This software may be modified and distributed
  under the terms of the BSD 3-Clause license.
  Refer to the LICENSE file for details.
*-->

# ICD
All the data is formatted according to this:
- byte order: Big endian
- word order: Little endian

## Discrete inputs (read only)

The following section lists a series of addresses to read ON/OFF statuses from robot

Applicable Modbus function code:

- Function Code 02 (Read Discrete Inputs)

### Robot state

| Type | Unit | Address | Description                                                  | Supported platform |
| ---- | ---- | ------- | ------------------------------------------------------------ | ------------------ |
| bool | N/A  | 0       | Unspecified arm state.                                       | ALL                |
| bool | N/A  | 1       | Cannot be reported as the Base initialisation must be completed before allowing user connection. | ALL                |
| bool | N/A  | 2       | Base initialisation succeeded.                               | ALL                |
| bool | N/A  | 3       | Arm is being initialised.                                    | ALL                |
| bool | N/A  | 4       | Arm is in fault.                                             | ALL                |
| bool | N/A  | 5       | Arm is in maintenance.                                       | ALL                |
| bool | N/A  | 6       | Arm is in low-level servoing mode.                           | ALL                |
| bool | N/A  | 7       | Arm is ready to be controlled.                               | ALL                |
| bool | N/A  | 8       | Arm is currently being controlled via a sequence.            | ALL                |
| bool | N/A  | 9       | Arm is currently being controlled manually.                  | ALL                |

### Robot fault flags

| Type | Unit | Address | Description                                  | Supported platform |
| ---- | ---- | ------- | -------------------------------------------- | ------------------ |
| bool | N/A  | 32      | Firmware update failure.                     | ALL                |
| bool | N/A  | 34      | Maximum ambient temperature reached.         | ALL                |
| bool | N/A  | 35      | Maximum core temperature reached.            | ALL                |
| bool | N/A  | 36      | Joint fault.                                 | ALL                |
| bool | N/A  | 40      | Above maximum DOF.                           | ALL                |
| bool | N/A  | 42      | Unable to reach pose.                        | ALL                |
| bool | N/A  | 43      | Joint detection error.                       | ALL                |
| bool | N/A  | 44      | Network initialisation error.                | ALL                |
| bool | N/A  | 45      | Maximum current reached.                     | ALL                |
| bool | N/A  | 46      | Maximum voltage reached.                     | ALL                |
| bool | N/A  | 47      | Minimum voltage reached.                     | ALL                |
| bool | N/A  | 55      | Emergency stop activated.                    | ALL                |
| bool | N/A  | 56      | Emergency line activated.                    | ALL                |
| bool | N/A  | 57      | In rush current limiter fault.               | ALL                |
| bool | N/A  | 58      | NVRAM corrupted (not implemented yet).       | ALL                |
| bool | N/A  | 59      | Incompatible firmware version.               | ALL                |
| bool | N/A  | 60      | Power on self test failure.                  | ALL                |
| bool | N/A  | 61      | Discrete Input stuck active.                 | ALL                |
| bool | N/A  | 62      | Arm is in an illegal position (singularity). | ALL                |

### Robot warning flags

| Type | Unit | Address | Description                                 | Supported platform |
| ---- | ---- | ------- | ------------------------------------------- | ------------------ |
| bool | N/A  | 64      | Firmware update failure.                    | ALL                |
| bool | N/A  | 66      | Maximum ambient temperature reached.        | ALL                |
| bool | N/A  | 67      | Maximum core temperature reached.           | ALL                |
| bool | N/A  | 68      | Joint fault.                                | ALL                |
| bool | N/A  | 72      | Above maximum DOF.                          | ALL                |
| bool | N/A  | 74      | Unable to reach pose.                       | ALL                |
| bool | N/A  | 75      | Joint detection error.                      | ALL                |
| bool | N/A  | 76      | Network initialisation error.               | ALL                |
| bool | N/A  | 77      | Maximum current reached.                    | ALL                |
| bool | N/A  | 78      | Maximum voltage reached.                    | ALL                |
| bool | N/A  | 79      | Minimum voltage reached.                    | ALL                |
| bool | N/A  | 87      | Emergency stop activated                    | ALL                |
| bool | N/A  | 88      | Emergency line activated                    | ALL                |
| bool | N/A  | 89      | In rush current limiter fault               | ALL                |
| bool | N/A  | 91      | Incompatible firmware version               | ALL                |
| bool | N/A  | 92      | Power on self test failure                  | ALL                |
| bool | N/A  | 93      | Discrete Input stuck active                 | ALL                |
| bool | N/A  | 94      | Arm is in an illegal position (singularity) | ALL                |

## Coils (read / write)

The following section lists a series of addresses to drive ON/OFF output on robot

Applicable Modbus function codes:

- Function Code 01 (Read Coils)
- Function Code 05 (Write Single Coil)
- Function Code 15 (Write Multiple Coils)

| Category | Unit | Address | Description         | Supported platform |
| -------- | ---- | ------- | ------------------- | ------------------ |
| Control  | N/A  | 0       | Quick stop          | ALL                |
| Control  | N/A  | 1       | Abort / manual stop | ALL                |
| Control  | N/A  | 2       | Fault reset         | ALL                |

## Input registers (read only)

The following section list a series of addresses to read 16-bit number from robot .

Applicable Modbus function code:

- Function Code 04 (Read Input Registers)

### Robot

| Category                | Type             | Unit | Address | Description                                                  | Supported platform |
| ----------------------- | ---------------- | ---- | ------- | ------------------------------------------------------------ | ------------------ |
| Robot state             | uint16 (bitmask) | N/A  | 0       | **0**: Unspecified arm state<br/>**1**: Cannot be reported as the Base initialization must be completed before allowing user connectionBase initialisation succeeded. <br/>**2**: Base initialization succeededArm is being initialised.<br/>**3**: Arm is being initializedArm is in fault.<br/>**4**: Arm is in faultArm is in maintenance.<br/>**5**: Arm is in maintenanceArm is in low-level servoing mode.<br/>**6**: Arm is in low-level servoing modeArm is ready to be controlled.<br/>**7**: Arm is ready to be controlled.<br/>**8**: Arm is currently being controlled via a sequenceArm.<br/>**9**: Arm is currently being controlled manually. | ALL                |
| Fault flags             | uint32 (bitmask) | N/A  | 2 - 3   | **0**: Firmware update failure <br/>**2**: Maximum ambient temperature reached <br/>**3**: Maximum core temperature reached <br/>**4**: Joint fault <br/>**8**: Above maximum DOF <br/>**10**: Unable to reach pose <br/>**11**: Joint detection error <br/>**12**: Network initialisation error <br/>**13**: Maximum current reached <br/>**14**: Maximum voltage reached <br/>**15**: Minimum voltage reached <br/>**23**: Emergency stop activated <br/>**24**: Emergency line activated <br/>**25**: In rush current limiter fault <br/>**27**: Incompatible firmware version <br/>**28**: Power on self test failure <br/>**29**: Discrete Input stuck active <br/>**30**: Arm is in an illegal position (singularity) | ALL                |
| Warning flags           | uint32 (bitmask) | N/A  | 4 - 5   | Same as **Fault flags**                                      | ALL                |
| Arm current             | float            | A    | 6 - 7   | Arm current                                                  | ALL                |
| Arm Voltage             | float            | V    | 8 - 9   | Arm voltage                                                  | ALL                |
| Arm CPU Temperature     | float            | °C   | 10 - 11 | Arm CPU Temperature                                          | ALL                |
| Arm Ambient Temperature | float            | °c   | 12 - 13 | Arm Ambient Temperature                                      | ALL                |

### Joints data

| Type  | Unit  | Address   | Description        | Supported platform |
| ----- | ----- | --------- | ------------------ | ------------------ |
| float | °     | 34 - 35   | Joint 1 position   | ALL                |
| float | °     | 36 - 37   | Joint 2 position   | ALL                |
| float | °     | 38 - 39   | Joint 3 position   | ALL                |
| float | °     | 40 - 41   | Joint 4 position   | ALL                |
| float | °     | 42 - 43   | Joint 5 position   | ALL                |
| float | °     | 44 - 45   | Joint 6 position   | ALL                |
| float | °     | 46 - 47   | Joint 7 position   | ALL                |
| float | ° / s | 48 - 49   | Joint 1 velocity   | ALL                |
| float | ° / s | 50 - 51   | Joint 2 velocity   | ALL                |
| float | ° / s | 52 - 53   | Joint 3 velocity   | ALL                |
| float | ° / s | 54 - 55   | Joint 4 velocity   | ALL                |
| float | ° / s | 56 - 57   | Joint 5 velocity   | ALL                |
| float | ° / s | 58 - 59   | Joint 6 velocity   | ALL                |
| float | ° / s | 60 - 61   | Joint 7 velocity   | ALL                |
| float | Nm    | 62 - 63   | Joint 1 torque     | ALL                |
| float | Nm    | 64 - 65   | Joint 2 torque     | ALL                |
| float | Nm    | 66 - 67   | Joint 3 torque     | ALL                |
| float | Nm    | 68 - 69   | Joint 4 torque     | ALL                |
| float | Nm    | 70 - 71   | Joint 5 torque     | ALL                |
| float | Nm    | 72 - 73   | Joint 6 torque     | ALL                |
| float | Nm    | 74 - 75   | Joint 7 torque     | ALL                |
| float | A     | 76 - 77   | Joint 1 current    | ALL                |
| float | A     | 78 - 79   | Joint 2 current    | ALL                |
| float | A     | 80 - 81   | Joint 3 current    | ALL                |
| float | A     | 82 - 83   | Joint 4 current    | ALL                |
| float | A     | 84 - 85   | Joint 5 current    | ALL                |
| float | A     | 86 - 87   | Joint 6 current    | ALL                |
| float | A     | 88 - 89   | Joint 7 current    | ALL                |
| float | °C    | 90 - 91   | Joint 1 motor temp | ALL                |
| float | °C    | 92 - 93   | Joint 2 motor temp | ALL                |
| float | °C    | 94 - 95   | Joint 3 motor temp | ALL                |
| float | °C    | 96 - 97   | Joint 4 motor temp | ALL                |
| float | °C    | 98 - 99   | Joint 5 motor temp | ALL                |
| float | °C    | 100 - 101 | Joint 6 motor temp | ALL                |
| float | °C    | 102 - 103 | Joint 7 motor temp | ALL                |

### Tool center point

| Type  | Unit | Address   | Description                  | Supported platform |
| ----- | ---- | --------- | ---------------------------- | ------------------ |
| float | m    | 104 - 105 | TCP Position X               | ALL                |
| float | m    | 106 - 107 | TCP Position Y               | ALL                |
| float | m    | 108 - 109 | TCP Position Z               | ALL                |
| float | °    | 110 - 111 | TCP Orientation Theta X      | ALL                |
| float | °    | 112 - 113 | TCP Orientation Theta Y      | ALL                |
| float | °    | 114 - 115 | TCP Orientation Theta Z      | ALL                |
| float | m/s  | 116 - 117 | TCP Velocity X               | ALL                |
| float | m/s  | 118 - 119 | TCP Velocity Y               | ALL                |
| float | m/s  | 120 - 121 | TCP Velocity Z               | ALL                |
| float | °/s  | 122 - 123 | TCP Angular Velocity Theta X | ALL                |
| float | °/s  | 124 - 125 | TCP Angular Velocity Theta Y | ALL                |
| float | °/s  | 126 - 127 | TCP Angular Velocity Theta Z | ALL                |
| float | N    | 128 - 129 | TCP Force X                  | ALL                |
| float | N    | 130 - 131 | TCP Force Y                  | ALL                |
| float | N    | 132 - 133 | TCP Force Z                  | ALL                |
| float | Nm   | 134 - 135 | TCP Torque X                 | ALL                |
| float | Nm   | 136 - 137 | TCP Torque Y                 | ALL                |
| float | Nm   | 138 - 139 | TCP Torque Z                 | ALL                |

## Holding registers

The following section lists available addresses to use. Every address holds a 16 bits register.

Applicable Modbus function codes:

- Function Code 03 (Read Holding Registers)
- Function Code 06 (Write Single Register)
- Function Code 16 (Write Multiple Registers)

### Control (read only)

| Type   | Address | Description                                                  | Supported platform |
| ------ | ------- | ------------------------------------------------------------ | ------------------ |
| uint16 | 0       | **0**: Quick stop<br/>**1**: Abort / manual stop<br/>**2**: Fault reset | ALL                |

### Action / Sequence (read only)

| Type              | Address | Description                                                  | Supported platform |
| ----------------- | ------- | ------------------------------------------------------------ | ------------------ |
| Bitmask (16 bits) | 100     | Status of executed Action or Sequence.<br/>**0**: Started<br/>**1**: Completed<br/>**2**: Paused<br/>**3**: Aborted | ALL                |
| uint16            | 101     | Active Action/Sequence **ID**.                               | ALL                |
| uint16            | 102     | Active move type.<br/>**0**: Action<br/>**1**: Sequence<br/>**2**: Cartesian trajectory<br/>**3**: Twist | ALL                |

### Speed limit (read only)

| Type  | Unit | Address   | Description                                 | Supported platform |
| ----- | ---- | --------- | ------------------------------------------- | ------------------ |
| float | m/s  | 104 - 105 | Current Linear Cartesian Speed Limit    | ALL                |
| float | °/s  | 106 - 107 | Current Angular Cartesian Speed Limit   | ALL                |


### Control (read / write)

| Type              | Unit     | Address   | Description                                                  | Supported platform |
| ----------------- | -------- | --------- | ------------------------------------------------------------ | ------------------ |
| Bitmask (16 bits) | N/A      | 200       | Status of executed Action or Sequence.<br/>**0**: No action<br/>**1**: Action start<br/>**2**: Action stop<br/>| ALL                |
| uint16            | N/A      | 201       | Active Action/Sequence **ID**.                               | ALL                |
| uint16            | N/A      | 202       | Active move type.<br/>**0**: Action<br/>**1**: Sequence<br/>**2**: Cartesian trajectory<br/>**3**: Twist | ALL                |
| uint16            | N/A      | 203       | Cartesian reference frame.<br/>**1**: Mixed<br/>**2**: Tool<br/>**3**: Base | ALL                |
| float             | m or m/s | 204 - 205 | Linear X position or velocity<br/>*Only used with Cartesian and Twist Move types* | ALL                |
| float             | m or m/s | 206 - 207 | Linear Y position or velocity<br/>*Only used with Cartesian and Twist Move types* | ALL                |
| float             | m or m/s | 208 - 209 | Linear Z position or velocity<br/>*Only used with Cartesian and Twist Move types* | ALL                |
| float             | m or °/s | 210 - 211 | Theta X Orientation or Angular X velocity<br/>*Only used with Cartesian and Twist Move types* | ALL                |
| float             | m or °/s | 212 - 213 | Theta Y Orientation or Angular Y velocity<br/>*Only used with Cartesian and Twist Move types* | ALL                |
| float             | m or °/s | 214 - 215 | Theta Z Orientation or Angular Z velocity<br/>*Only used with Cartesian and Twist Move types* | ALL                |
| float | m/s  | 216 - 217 | Desired Linear Cartesian Speed Limit | ALL                |
| float | °/s  | 218 - 219 | Desired Angular Cartesian Speed Limit | ALL                |

