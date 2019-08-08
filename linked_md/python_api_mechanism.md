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

<h1>Python API mechanism</h1>

<h2>Table Of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Blocking-method](#function)

<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
The Python Kortex API offers one mechanism to call a method: a standard blocking method.


<a id="markdown-blocking-function" name="function"></a>
## Blocking method
The blocking method (blocking call) is relatively straightforward. The function is called, and the process waits until an answer is received from the server side.


```python
# RouterClientSendOptions is optional and needs to be passed with the keyword
# options
router_options = RouterClientSendOptions()
router_options.timeout_ms = 5000 # 5 seconds

# The same function call without the options=router_options is valid and will do the same
# using the router default value
all_speed_hard_limits = base.GetAllJointsSpeedHardLimitation()

for speed_limit in all_speed_hard_limits.joints_limitations:
	print("============================================")
	print("Joint: {0}".format(speed_limit.joint_identifier))
	print("Type of limitation: {0}".format(Base_pb2.LimitationType.Name(speed_limit.type)))
	print("Value: {0}".format(speed_limit.value))
	print("============================================")
```
