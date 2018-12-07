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

- [Setup example Python environment](#setup-example-python-environment)
    - [Requested basic Python & Python modules](#requested-basic-python--python-modules)
    - [Install Python module Kortex Api & the needed dependencies](#install-python-module-kortex-api--the-needed-dependencies)
- [How To Use Examples With Gen3 Robot](#how-to-use-examples-with-gen3-robot)
- [Api Documentation](#api-documentation)
- [Reference](#reference)
            - [Usefull Links](#usefull-links)
- [Back to root topic: **readme.md**](#back-to-root-topic-readmemd)

<!-- /TOC -->

<a id="markdown-setup-example-python-environment" name="setup-example-python-environment"></a>
# Setup example Python environment

<a id="markdown-requested-basic-python--python-modules" name="requested-basic-python--python-modules"></a>
## Requested basic Python & Python modules

- python >= 3.5
- pip

**Refer to the main readme for python instalation details: [parent readme](../../readme.md)**  

<a id="markdown-install-python-module-kortex-api--the-needed-dependencies" name="install-python-module-kortex-api--the-needed-dependencies"></a>
## Install Python module Kortex Api & the needed dependencies  

*install what is needed to run the examples via a downloaded whl file*

+ The whl file can be downloaded via the Kinova goggle drive: [kortex_api](https://drive.google.com/file/d/19zfCNlRUfNBbZoMW9LOpLjVrYOO2BwYb/view)  
```sh
python -m pip install <whl relative fullpath name>.whl
```

*(note that root privilege is probably requested under linux to install a new module)*

<a id="markdown-how-to-use-examples-with-gen3-robot" name="how-to-use-examples-with-gen3-robot"></a>
# How To Use Examples With Gen3 Robot

Each Python example have his own ``__main__`` instruction. You only need to call it using the Python command.
```sh
python <path-to-example-file>.py
```

*(note that examples need the robot to be cable-connected and that they are using the factory default ip address)*

<a id="markdown-api-documentation" name="api-documentation"></a>
# Api Documentation
Here a link on the generated documentation  
[Api Python Services Documentation](../doc/markdown/index.md)  

<a id="markdown-reference" name="reference"></a>
# Reference
<a id="markdown-usefull-links" name="usefull-links"></a>
#### Usefull Links
|  |  |  
| ---: | --- |  
| Google Protobuf Generated Python: | https://developers.google.com/protocol-buffers/docs/reference/python-generated | 

__________________________
<a id="markdown-back-to-root-topic-readmemdreadmemd" name="back-to-root-topic-readmemdreadmemd"></a>
# Back to root topic: **[readme.md](../../readme.md)**  
