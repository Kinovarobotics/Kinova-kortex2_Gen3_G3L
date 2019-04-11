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

<h1>API mechanism</h1>

<h2>Table Of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Blocking-method](#blocking-function)

<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
The **Python Kortex API** offers one mechanism to call a method: the standard **blocking** method.


<a id="markdown-blocking-function" name="blocking-function"></a>
## Blocking method
The **blocking** method (blocking call) is quite straightforward. The function is called, and the process waits until an answer is received from the server side.


```python
# RouterClientSendOptions is optional and needs to be passed with the keyword
# options
router_options = RouterClientSendOptions()
router_options.timeout_ms = 5000 # 5 seconds

# The same function call without the options=router_options is valid and will do the same
# using the router default value
wifi_list = base_service.GetAvailableWifi(options=router_options)

for wifi in wifi_list.wifi_information_list:
	print("============================================")
	print("SSID: {0}".format(wifi.ssid.identifier))
	print("Wi-Fi security type: {0}".format(wifi.security_type))
	print("Wi-Fi encryption type: {0}".format(wifi.encryption_type))
	print("Signal strength: {0}".format(wifi.signal_strength))
	print("============================================")
```
