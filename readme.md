<!--
* KINOVA (R) KORTEX (TM)
*
* Copyright (c) 2018 Kinova inc. All rights reserved.
*
* This software may be modified and distributed under the
* terms of the BSD 3-Clause license.
*
* Refer to the LICENSE file for details.
*
-->

<!-- TOC -->

- [Description](#description)
- [Licensing](#licensing)
- [Role of Google Protobuf in Kortex API](#role-of-google-protobuf-in-kortex-api)
    - [Quick Start HowTo Python](#quick-start-howto-python)
- [API details for a specific language](#api-details-for-a-specific-language)
- [Reference](#reference)
            - [Useful Links](#useful-links)

<!-- /TOC -->

<a id="markdown-description" name="description"></a>
# Description
Repository containing documentations and examples using Kortex
API client using multiple languages *(C++, Python)*.  
  
Part of the __**Kinova® Kortex™ suite**__  
Kortex GitHub: https://github.com/Kinovarobotics/kortex  

<a id="markdown-licensing" name="licensing"></a>
# Licensing 
Note that this repository is licenced under the **BSD 3-Clause "Revised" License**: **[LICENSE File](./LICENSE)**  

<a id="markdown-role-of-google-protobuf-in-kortex-api" name="role-of-google-protobuf-in-kortex-api"></a>
# Role of Google Protobuf in Kortex API 

The Kortex API is using Google Protobuf message objects<sup>**[1](#useful-links)**</sup> for exhange data between client & server side.  

Protobuf offers structured data objects with standard methods for each member field.  
Here are their main features:  
+ structured nested objects
+ basic types & collections
+ getters/setters/has methods on basic types
+ iterators, dimension & appending methods on collections
+ many helpers (ex: serialize/deserialize, io functions)
  
When using the Kortex API a developer will have to understand the protobuf features set to maximize his efficiency.  

<a id="markdown-quick-start-howto-python" name="quick-start-howto-python"></a>
## Quick Start HowTo Python

  To run Python examples you will need to install at least the python interpreter and the Pip installation module.  
  Note that even for C++ developper it could be usefull to install the Python Kortex API.  That will allow quick tests and validations.

  > Here some general information about python interpreter & pip modules' manager.  
  > **[Python General Information](./linked_md/python_quick_start.md)**

<a id="markdown-api-details-for-a-specific-language" name="api-details-for-a-specific-language"></a>
# API details for a specific language

**[C++ API](./api_cpp/examples/readme.md)**  
**[Python API](./api_python/examples/readme.md)**  

<a id="markdown-reference" name="reference"></a>
# Reference
<a id="markdown-useful-links" name="useful-links"></a>
#### Useful Links
|  |  |  
| ---: | --- |  
| Kinova home page: | https://www.kinovarobotics.com |  
| Google Protobuf home page: | https://developers.google.com/protocol-buffers |  
<!--
| Docker home page: | https://www.docker.com |  
-->
___________________________

[How to contribute]: ./linked_md/contributing.md  
[Installing docker]: ./linked_md/installation_docker.md  
[Using docker]: ./linked_md/howto_docker.md  
