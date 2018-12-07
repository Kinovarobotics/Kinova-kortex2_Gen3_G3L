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

- [Python Setup](#python-setup)
    - [Installation of basic python & python modules](#installation-of-basic-python--python-modules)
        - [Mandatory installations](#mandatory-installations)
        - [Facultative usefull python modules](#facultative-usefull-python-modules)
- [Python Overview](#python-overview)
- [Back to root topic: **readme.md**](#back-to-root-topic-readmemd)

<!-- /TOC -->

<a id="markdown-python-setup" name="python-setup"></a>
# Python Setup

<a id="markdown-installation-of-basic-python--python-modules" name="installation-of-basic-python--python-modules"></a>
## Installation of basic python & python modules

<a id="markdown-mandatory-installations" name="mandatory-installations"></a>
### Mandatory installations
- python >= 3.5
- pip

> <details open>
> <summary>Linux Ubuntu</summary>
>
> <h4>Install Python 3.5.2</h4>  
> ```sh
> sudo apt-get install python3.5  
> sudo apt-get install python3-pip  
> python3.5 -m pip install --upgrade pip --user
> ```
> 
></details>  

<p></p>

> <details open>
><summary>Windows</summary>
>
> <h4>Download Python 3.x (based on 3.5.2)</h4>  
> 
> - direct URL: [python-3.5.2](https://www.python.org/downloads/release/python-352/)  
> - alternatively, click this link to download the file directly: https://www.python.org/ftp/python/3.5.2/python-3.5.2.exe  
>
> <h4>Installation using the wizard</h4>  
>
> - be sure to install pip and to add python to the environnement variables  
> - also you should consider to install the python test suite  
>
> </details>  

<a id="markdown-facultative-usefull-python-modules" name="facultative-usefull-python-modules"></a>
### Facultative usefull python modules
- pipenv: packages manager
- pytest: python test framework
- pytest-cov: pytest coverage tool report
- pylint: python lint (static analyser for edition)

<a id="markdown-python-overview" name="python-overview"></a>
# Python Overview

<details open>
<summary>Linux Ubuntu</summary>

```sh
# to display the actual version of python used
python -V
 
# to use specific version of python consider to chain the specific version till the desired one  
# (if there are many version install you could have to specify the full version)  
python3 -V
python3.5 -V

# use python pip module to install and manage python modules
python3.5 -m pip --help

# use python to run a specific python script
python3.5 <script>
```
  
</details>  

<details open>
<summary>Windows</summary>

```sh
# to get the actual version of python used by windows
python -VV

# to use another version call python with fullpath instead using the shortcut alias python (see following example)
C:\User\user_name\AppData\Local\Programs\Python\python35-32.exe

# python pip module
python -m pip --help

# use python to run a specific python script
python <script>
```
  
</details>  

__________________________
<a id="markdown-back-to-root-topic-readmemdreadmemd" name="back-to-root-topic-readmemdreadmemd"></a>
# Back to root topic: **[readme.md](../readme.md)**  
