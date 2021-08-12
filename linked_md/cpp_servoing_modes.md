<!--
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2019 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
-->

<h1>Servoing Mode</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Setting servoing mode](#setting-servoing-mode)
	- [High level servoing mode](#high-level-servoing-mode)
	- [Low level servoing mode](#low-level-servoing-mode)

<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
There are multiple servoing modes on the robot. A servoing mode allows commands to be transmitted to the robot devices during operation. Depending on the servoing mode chosen, the details for API control will be different.
 
<a id="markdown-set-servoing-mode" name="set-servoing-mode"></a>
## Setting servoing mode
The RPC to set the servoing mode is in the Base service

```cpp
// API initialisation
k_api::Base::BaseClient* base = new k_api::Base::BaseClient(pRouter);

// Sets the base in low level servoing
auto servoingMode = k_api::Base::ServoingModeInformation();
servoingMode.set_servoing_mode(k_api::Base::ServoingMode::LOW_LEVEL_SERVOING); //Enum type
base->SetServoingMode(servoingMode);
```

<a id="markdown-high-level" name="high-level"></a>
### High level servoing mode
High-level servoing is the default servoing mode for the robot on bootup.

In high-level servoing, users connect to the base through the API, sending command inputs. The base routes commands to the actuators, and manages a 1 kHz control loop.

High-level servoing is the recommended servoing mode for non-advanced users, because you have access to Cartesian movement and don't have to manage a 1kHz control loop to send commands to the robot. 
 
<a id="markdown-low-level" name="low-level"></a>
### Low level servoing mode
In low-level servoing, the API client connects to the base and sends commands through the base for routing. Take note that this mode **does not** support Cartesian commands.

The base ensures device routing and internal communications with the actuators at 1 kHz, but the high-level functionalities for the base control loop (Cartesian movement, robot kinematics, trajectory management, etc.) are no longer available.

Low-level servoing allows clients to control each actuator individually by sending small position increments at a 1 kHz frequency (bypassing the kinematic control library).

You can have a look at the [actuator low-level cyclic example](../api_cpp/examples/200-Actuator_low_level_control/01-actuator_low_level_velocity_control.cpp) for a code example.
