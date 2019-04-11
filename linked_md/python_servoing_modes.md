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

<h2>Table Of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Setting servoing mode](#set-servoing-mode)
	- [High level servoing mode](#high-level)
	- [Low level servoing mode](#low-level)
	
<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
There are multiple servoing modes on the robot. A servoing mode is a mode through which commands are transmitted to robot devices during operation. Depending on the servoing mode chosen, the details involved in controlling via the API will be different.

<a id="markdown-set-servoing-mode" name="set-servoing-mode"></a> 
## Setting servoing mode
The RPC to set the servoing mode is in the base service

```python
# API initialisation
base_service = BaseClient(router)

# Set the base in low level servoing
servoing_mode_information = Base_pb2.ServoingModeInformation()
servoing_mode_information.servoing_mode = Base_pb2.LOW_LEVEL_SERVOING
base_service.SetServoingMode(servoing_mode_information)
```

<a id="markdown-high-level" name="high-level"></a>
### High level servoing mode
High-level servoing is the default servoing mode for the robot on bootup.

In high-level servoing, users connect to the base through the API, sending command inputs. The base routes commands to the actuators, and manages a 1 kHz control loop.

High-level servoing is the recommended servoing mode for non-advanced users, because you have access to cartesian movement and doesn't have to manage a 1kHz control loop. 

<a id="markdown-low-level" name="low-level"></a> 
### Low level servoing mode

> **This servoing mode is not meant to run under python.** C++ is a much more suitable language for this mode. Python is an interpreted language and by extension much more sensitive to jitter and will not guarantee a 1 kHz refresh rate.

In low-level servoing, the API client connects to the base and sends commands to the base for routing. Take note that this mode **does not support cartesian command**

The base ensures device routing and internal communications with the actuators at 1 kHz, but the high-level functionality for the base control loop (cartesian movement, robot kinematics, trajectory management, etc.) are no longer available.

Low-level servoing allows clients to control each actuator individually by sending little position increments at a 1 kHz frequency (bypassing the kinematic control library).
