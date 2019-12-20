<!--
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed
* under the terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
-->

<h1>KINOVA<sup>®</sup> KORTEX™ API Reference</h1>

<a id="markdown-description" name="description"></a>
# Description

The official repository contains documentation and examples explaining how to use the KINOVA<sup>®</sup> KORTEX™ API client with C++ or Python:  


[https://github.com/Kinovarobotics/kortex](https://github.com/Kinovarobotics/kortex)  

<h1>Table of Contents</h1>

<!-- TOC -->

- [Description](#description)
- [Licensing](#licensing)
- [Role of Google Protocol Buffer in Kortex API](#role-of-google-protobuf-in-kortex-api)
    - [Quick Start for Python users](#quick-start-howto-python)
    - [Quick Start for C++ users](#quick-start-howto-cpp)
- [Download links](#api-download-links)
- [Language-specific details](#api-details-for-a-specific-language)
- [Reference](#reference)
            - [Useful Links](#useful-links)

<!-- /TOC -->

<a id="markdown-licensing" name="licensing"></a>
# Licensing 
This repository is licenced under the [BSD 3-Clause "Revised" License](./LICENSE) 

<a id="markdown-role-of-google-protobuf-in-kortex-api" name="role-of-google-protobuf-in-kortex-api"></a>
# Role of Google Protocol Buffer in Kortex API 

The Kortex API uses Google Protocol Buffer message objects<sup>**[1](#useful-links)**</sup> to exchange data between client and server.  

Google Protocol Buffer offers structured data objects with standard methods for each member field:  
+ structured, nested objects
+ basic types and collections
+ getter/setter methods on basic types
+ iterators, dimension and appending methods on collections
+ many helpers (e.g. serialize/deserialize, I/O functions)
  
When using the Kortex API a developer will need to understand the Google Protocol Buffer feature set to maximize their efficiency.  

<a id="markdown-quick-start-howto-cpp" name="quick-start-howto-cpp"></a>
## Quick Start for C++ users
  The following links provide some helpful guidance for C++ developer. You will find information about Kortex mechanism and some code examples.

+ [API mechanism](./linked_md/cpp_api_mechanism.md)
+ [Transport / Router / Session / Notification](./linked_md/cpp_transport_router_session_notif.md)
+ [Device routing](./linked_md/cpp_device_routing.md)
+ [Servoing modes](./linked_md/cpp_servoing_modes.md)
+ [Error management](./linked_md/cpp_error_management.md)
+ [Examples](./api_cpp/examples/readme.md)

<a id="markdown-quick-start-howto-python" name="quick-start-howto-python"></a>
## Quick Start for Python users

  To run the Python examples you will need to install the Python interpreter and the pip installation module.

  Note that for C++ developers it could be useful to install the Python Kortex API to allow for quick tests and validations.

  Here is some general information about the Python interpreter and the pip module manager.  
  - [Python General Information](./linked_md/python_quick_start.md)
  - [API mechanism](./linked_md/python_api_mechanism.md)
  - [Transport / Router / Session / Notification](./linked_md/python_transport_router_session_notif.md)
  - [Device routing](./linked_md/python_device_routing.md)
  - [Servoing modes](./linked_md/python_servoing_modes.md)
  - [Error management](./linked_md/python_error_management.md)
  - [Examples](./api_python/examples/readme.md)

<a id="markdown-api-download-links" name="api-download-links"></a>
# Download links

The latest download links for each arm type are reported in the table below:

| Arm type       | Firmware     | Release notes      | API |
| :------------- | :----------: | :-----------: | :-----------:
|  Gen3 | [2.0.1](https://artifactory.kinovaapps.com/artifactory/generic-public/kortex/gen3/2.0.1/Gen3-2.0.1.swu)   | [2.0.1](https://artifactory.kinovaapps.com/artifactory/generic-public/kortex/gen3/2.0.1/RN-001_KINOVA_Gen3_Ultra_lightweight_robot-Release_Notes_EN_R05%20(1).pdf)    | [2.0.0](https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/API/2.0.0/kortex_api_2.0.0.zip)
| Gen3 lite   | [2.1.1](https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/gen3Lite/2.1.1/Gen3Lite-2.1.1.swu) | [2.1.1](https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/gen3Lite/2.1.1/RN-002_Gen3_lite_robot_Release_Notes_EN_R01.pdf) | [2.1.0](https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/API/2.1.0/kortex_api_2.1.0.zip)

<details><summary>Previous releases</summary>
<p>
<ul>
<li>
Release 2.0.0 for Gen3: <a href="https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/gen3/2.0.0/Gen3-2.0.0.swu">Firmware</a>, <a href="https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/gen3/2.0.0/RN-001_KINOVA_Gen3_Ultra_lightweight_robot-Release_Notes_EN_R04.pdf">Release Notes</a>, <a href="https://artifactory.kinovaapps.com/artifactory/generic-local-public/kortex/API/2.0.0/kortex_api_2.0.0.zip">Kortex API</a>
</li>
</ul>
</p>
</details>

<a id="markdown-api-details-for-a-specific-language" name="api-details-for-a-specific-language"></a>
# Language-specific details 

[C++ API](./api_cpp/examples/readme.md)  
[Python API](./api_python/examples/readme.md) 

<a id="markdown-reference" name="reference"></a>
# Reference
<a id="markdown-useful-links" name="useful-links"></a>
#### Useful Links
|  |  |  
| ---: | --- |  
| Kinova home page: | [https://www.kinovarobotics.com](https://www.kinovarobotics.com)|  
| Google Protocol Buffers home page: | [https://developers.google.com/protocol-buffers](https://developers.google.com/protocol-buffers) |  
