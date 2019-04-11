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
    - [To summarize:](#to-summarize)
- [Blocking method](#blocking-method)
    - [Example](#example)
    - [KDetailedException](#kdetailedexception)
    - [KError](#kerror)
- [Callback](#callback)
    - [Example using lambda](#example-using-lambda)
    - [Example using C callback](#example-using-c-callback)
- [Async method](#async-method)
    - [Async example](#async-example)
- [Special case](#special-case)
    - [RouterClient](#routerclient)


<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview

There are three mechanisms available to manage errors triggered by the C++ Kortex API: standard **Exception**, accessing the **Error object** returned by the callback function, and catching the exception thrown by a **std::future**. When you use the Kortex API, choose one of these mechanisms according to the type of called method.

#### To summarize: 
  
    - With the blocking method, use exceptions.
    - With the callback function, use the Error object from the callback header.
    - With the async method, use exceptions.

Note that there is a [special case](#special-cases) explained at the end of this document.

<a id="markdown-blocking-function" name="blocking-function"></a>
## Blocking method
Exceptions are only used if a blocking or async function is used. The code is surrounded with a **try/catch** statement pair and to catch any exceptions. The Kortex API offers its own exception object: ``Kinova::Api::KDetailedException``.


<a id="markdown-exception-example" name="exception-example"></a>
#### Example

```cpp
try
{
	// Your code...
}
catch(k_api::KDetailedException& ex)
{
	auto errorInfo = ex.getErrorInfo();
	auto errorCode = errorInfo.getError();
	
	std::cout << "KDetailedException toStr: " << ex.toString().c_str() << std::endl;
	std::cout << "KDetailedException what:  " << ex.what() << std::endl << std::endl;

	std::cout << "KError error_code: " << errorCode.error_code() << std::endl;
	std::cout << "KError sub_code: " << errorCode.error_sub_code() << std::endl;
	std::cout << "KError sub_string: " << errorCode.error_sub_string() << std::endl;
}
```

Here are the details of the object **Kinova::Api::KDetailedException** thrown by the Kortex API.

<a id="markdown-kdetailed-exception" name="kdetailed-exception"></a>
#### KDetailedException

```cpp
class KDetailedException : public KBasicException
{
    public:
        KDetailedException(const KError& error);
        KDetailedException(const KDetailedException &other);

        virtual const char* what() const throw() override;
        virtual std::string toString() override;

        KError&      getErrorInfo() { return m_error; }

    private:
        void init(const HeaderInfo& header, const Error& error);
    
        KError       m_error;
        std::string  m_errorStr;
};
```

Here are the details of the object **KError** nested in the exception.

<a id="markdown-kerror" name="kerror"></a>
#### KError

```cpp
class KError
{
    public:
        KError(Kinova::Api::ErrorCodes errorCode, Kinova::Api::SubErrorCodes errorSubCode, std::string errorDescription);
        KError(const HeaderInfo& header, Kinova::Api::ErrorCodes errorCode, Kinova::Api::SubErrorCodes errorSubCode, std::string errorDescription);
        KError(const Error& error);
        KError(const HeaderInfo& header, const Error& error);

        static Error fillError(Kinova::Api::ErrorCodes errorCode, Kinova::Api::SubErrorCodes errorSubCode, std::string errorDescription);

        std::string toString() const;

        bool            isThereHeaderInfo();
        HeaderInfo      getHeader();
        Error           getError();

        KError& operator =(const KError& other) = default;

    private:
        bool            m_isThereHeaderInfo;
        HeaderInfo      m_header;
        Error           m_error;
};
```

The **KError** object holds an error code and a sub error code to identify the fault.

Here's a link to the documentation that explains all of the error codes:

- [Error code](https://github.com/Kinovarobotics/kortex/blob/master/api_cpp/doc/markdown/references/enm_Api_ErrorCodes.md)
- [Sub error code](https://github.com/Kinovarobotics/kortex/blob/master/api_cpp/doc/markdown/references/enm_Api_SubErrorCodes.md#)

<a id="markdown-callback" name="callback"></a>
## Callback
If the callback version is used, a ``std::function`` is given as a parameter to act as a callback. The header of this ``std::function`` includes an **Error** object containing the error returned by the execution. Since it is a ``std::function``, you can either use a lambda expression or a standard C callback.

<a id="markdown-callback-example-lambda" name="callback-example-lambda"></a>
#### Example using lambda
```cpp
// callback function used in Refresh_callback
auto lambda_fct_callback = [](const Kinova::Api::Error &err, const k_api::BaseCyclic::Feedback data)
{
    // we are printing the data for example purposes
    // avoid this for a real-time loop 

    std::string serializedData;
    google::protobuf::util::MessageToJsonString(data, &serializedData);
    std::cout << serializedData << std::endl;
};

pBaseCyclicService->Refresh_callback(BaseCommand, lambda_fct_callback, 0);
```

<a id="markdown-callback-example-c" name="callback-example-c"></a>
#### Example using C callback
```cpp
// callback function used in Refresh_callback
void fct_callback(const k_api::Error &err, const k_api::BaseCyclic::Feedback data)
{
    std::cout << "Callback function results: " << std::endl << std::endl;
    //React to the fault...
}

void example_function_call()
{
	pBaseCyclicService->Refresh_callback(BaseCommand, fct_callback, 0);
}

```

<a id="markdown-async-function" name="async-function"></a>

## Async method
If an async function is used, exceptions must be used to catch any error triggered by the Kortex API. The exception is thrown during the execution of the ``get()`` function.

<a id="markdown-example-async" name="async-example"></a>
#### Async example 

```cpp
// The function returns a **future** object
std::future<k_api::Base::WifiInformationList> availableWifiFuture_async = pBase->GetAvailableWifi_async();

// Waiting for the promise to be complete by the API
auto timeout_ms = std::chrono::milliseconds(10000);
std::future_status status = availableWifiFuture_async.wait_for(timeout_ms);

if(status != std::future_status::ready)
{
	throw std::runtime_error("Timeout detected while waiting for function\n");
}

try
{
	// Retrieve the result object from the future object
	auto availableWifi_async = availableWifiFuture_async.get();
}
catch(k_api::KDetailedException& ex)
{
	//respond to the fault.
}
```

<a id="markdown-special-cases" name="special-cases"></a>
## Special case
This section describes a case that doesn't follow the standard error management rules documented earlier in this document.
#### RouterClient
When a **RouterClient** object is instantiated a callback can be specified for execution when an error occurs.
```cpp
RouterClient* pRouter = new RouterClient(pTransport, [](KError err){ cout << "callback error" << err.toString(); });
```
