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

<!-- TOC -->

- [Setup (Python environment)](#setup-example-python-environment)
  - [Python setup](#requested-basic-python--python-modules)
  - [Install Kortex Python API and required dependencies](#install-python-module-kortex-api--the-needed-dependencies)
- [How to use the examples](#how-to-use-examples-with-gen3-robot)
- [Python API documentation](#api-documentation)
- [Reference](#reference)
      - [useful links](#useful-links)
- [Back to root topic: **readme.md**](#back-to-root-topic-readmemd)

<!-- /TOC -->

<a id="markdown-setup-example-python-environment" name="setup-example-python-environment"></a>
# Setup (Python environment)

<a id="markdown-requested-basic-python--python-modules" name="requested-basic-python--python-modules"></a>
## Required Python version and module

- Python >= 3.5
- pip

**Refer to the main README for Python installation details: [parent readme](../../readme.md)**  

<a id="markdown-install-python-module-kortex-api--the-needed-dependencies" name="install-python-module-kortex-api--the-needed-dependencies"></a>
## Install Kortex Python API and required dependencies  

*Install what is needed to run the examples via a downloaded whl file (Python wheel package).*

+ The whl file can be downloaded via Kinova Google Drive: [kortex_api](https://drive.google.com/file/d/19zfCNlRUfNBbZoMW9LOpLjVrYOO2BwYb/view)  
```sh
python -m pip install <whl relative fullpath name>.whl
```

*note: root privilege is usually required to install a new module under Linux*

<a id="markdown-how-to-use-examples-with-gen3-robot" name="how-to-use-examples-with-gen3-robot"></a>
# How to use the examples

*We assume the robot is using its default IP address: 192.168.1.10*

Before starting, ensure that you run the test in a safe area with some examples that contain movement. Also verify that your Gen3 device is correctly afixed to the working surface.

Prerequisites:
+ The examples required a wired connection to your computer
+ Configure a static IP address on your network interface (e.g.    ``192.168.1.11/24``)
+ Add a route to arm actuators:
  + under Windows
    ```batch
    route ADD -p 10.10.0.0 MASK 255.255.255.0 192.168.1.10 METRIC 1
    ```
  + under Linux
    ```sh
    ip route add 10.10.0.0/24 via 192.168.1.10
    ```

Now you're ready to run the examples. Each Python example has its own ``__main__`` instruction. You need only ``cd`` into the example directory and invoke the Python file using the Python command.
```sh
python <example-file>.py
```

<a id="markdown-api-documentation" name="api-documentation"></a>
# Python API documentation
Here's a link to the generated documentation  
[Python API Services Documentation](../doc/markdown/index.md)  

<a id="markdown-reference" name="reference"></a>
# Reference
<a id="markdown-useful-links" name="useful-links"></a>
#### useful links
|  |  |  
| ---: | --- |  
| Google Proto Buffer generated Python: | [https://developers.google.com/protocol-buffers/docs/reference/python-generated](https://developers.google.com/protocol-buffers/docs/reference/python-generated) | 

__________________________
<a id="markdown-back-to-root-topic-readmemdreadmemd" name="back-to-root-topic-readmemdreadmemd"></a>
# Back to root topic: **[readme.md](../../readme.md)**  
