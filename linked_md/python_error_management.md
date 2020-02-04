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

<h1>Error management</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
		- [Example](#example)
- [Special case](#special-case)
		- [RouterClient](#routerclient)

<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
The Python Kortex API currently has only one mechanism to manage errors: surrounding the code block with a **try/except** statement pair and reacting to the exception.


Note that there are [special cases](#special-cases) explained at the end of this document.

<a id="markdown-exception-example" name="exception-example"></a>
#### Example

```python
try:
	base_service.CreateUserProfile(Base_pb2.FullUserProfile())

except KClientException as ex:
	# Get error and sub error codes
	error_code = ex.get_error_code()
	sub_error_code = ex.get_error_sub_code()
	print("Error_code:{0} , Sub_error_code:{1} ".format(error_code, sub_error_code))
	print("Caught expected error: {0}".format(ex))

except KServerException as server_ex:
	# Do something...

except Exception:
	# Do something...
```
A `KClientException` is thrown when an error occurs on the API client side, just as a `KServerException` is thrown when the error occurs on the API server side.

A `KClientException` includes error code and sub error code information describing the exception. Here is a link to documentation explaining all of the error and sub error codes:

- [Error code](https://github.com/Kinovarobotics/kortex/blob/master/api_python/doc/markdown/enums/Api/ErrorCodes.md)
- [Sub error code](https://github.com/Kinovarobotics/kortex/blob/master/api_python/doc/markdown/enums/Api/SubErrorCodes.md)

<a id="markdown-special-cases" name="special-cases"></a>
## Special case
This section describes a case that doesn't follow the standard error management rules documented earlier in this document.

<a id="markdown-special-router-client" name="special-router-client"></a>
#### RouterClient
When a `RouterClient` object is instantiated a callback function (or lambda expression) can be specified. This function will be called if an exception is thrown during the process.
```python
router = RouterClient(transport, lambda kException: print("Error detected: {}".format(kException)))
```
