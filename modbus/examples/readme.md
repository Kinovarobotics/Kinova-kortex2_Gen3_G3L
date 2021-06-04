<!--
  KINOVA (R) KORTEX (TM)
  Copyright (c) 2021 Kinova inc. All rights reserved.
  This software may be modified and distributed
  under the terms of the BSD 3-Clause license.
  Refer to the LICENSE file for details.
*-->

# Modbus example

<!-- TOC -->

- [Modbus example](#modbus-example)
- [Setup (pymodbus)](#setup-pymodbus)
  - [Required Python version and module](#required-python-version-and-module)
- [How to use the examples](#how-to-use-the-examples)
- [Modbus ICD documentation](#modbus-icd-documentation)
- [Reference](#reference)
      - [useful links](#useful-links)
  - [Back to root topic: **readme.md**](#back-to-root-topic-readmemd)

<!-- /TOC -->

<a id="markdown-setup-example-pymodbus" name="setup-example-pymodbus"></a>
# Setup (pymodbus)

<a id="markdown-requested-basic-python--python-modules" name="requested-basic-python--python-modules"></a>

## Required Python version and module

- Python >= 3.5
- pip
- pymodbus

You can either install the modules manually or use the requirements.txt file that is inside the modbus example folder.

```sh
python3 -m pip install -r requirements.txt
```

Refer to the main README for Python installation details: [parent readme](../../linked_md/python_quick_start.md)

<a id="markdown-how-to-use-examples-with-your-robot" name="how-to-use-examples-with-your-robot"></a>
# How to use the examples

We assume the robot is using its default IP address: ``192.168.1.10``

Before starting, ensure that you run the test in a safe area with some examples that contain movement. Also, verify that your robot is correctly afixed to the working surface.

Prerequisites:
+ The examples require a wired network connection to your computer
+ Configure a static IP address on your network interface (e.g. ``192.168.1.11/24``)

Now you're ready to run the examples. Each Python example has its own ``__main__`` instruction. You need only to ``cd`` into the example directory and invoke the Python file using the command:

- On Linux:
```sh
python3 <example-file>.py
```
- On Windows:
```sh
python <example-file>.py
```

<a id="markdown-icd-documentation" name="icd-documentation"></a>
# Modbus ICD documentation
Here's a link to the ICD documentation of the modbus slave. 
[Modbus slave ICD](../../linked_md/modbus_icd.md)  

<a id="markdown-reference" name="reference"></a>
# Reference
<a id="markdown-useful-links" name="useful-links"></a>
#### useful links
|  |  |
| ---: | --- |
| Modbus technical resources | https://modbus.org/tech.php |
| Modbus Wikipedia: | [link](https://en.wikipedia.org/wiki/Modbus#:~:text=Modbus%20is%20a%20data%20communications,of%20connecting%20industrial%20electronic%20devices.) |

__________________________
<a id="markdown-back-to-root-topic-readmemdreadmemd" name="back-to-root-topic-readmemd"></a>

## Back to root topic: **[readme.md](../../readme.md)**  