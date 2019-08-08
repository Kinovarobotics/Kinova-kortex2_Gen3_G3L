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

<h1>C++ API mechanism</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Blocking method](#blocking-function)
- [Callback](#callback)
	- [Example using lambda](#callback-example-lambda)
	- [Example using C callback](#callback-example-c)
- [Async function](#async-function)


<!-- /TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
The C++ Kortex API offers three mechanisms to call a method, one blocking, and two non-blocking: 

1. standard **blocking** method
2. **callback** function version, and 
3.  **async** method


<a id="markdown-blocking-function" name="blocking-function"></a>
## Blocking method
The first mechanism offered by the Kortex API is to use a **blocking** method (blocking call). If a procedural approach suffices, this is the easiest option. The method is called and execution is blocked until the result is returned by the server side.


```cpp
// Execution will be blocked until GetAllJointsSpeedHardLimitation has completed its execution.
auto limitations = base->GetAllJointsSpeedHardLimitation();
```

<a id="markdown-callback" name="callback"></a>
## Callback
You can also call a method and specify a **callback** function that will be called when the answer from the server side is received. The callback function is passed in as an additional argument to the method. Either an anonymous function (lambda) can be used as a callback function, or a named function.

The name of the callback version method is that used in the blocking call version, but with '_callback' appended to the name, i.e. `MethodName_callback()`.

<a id="markdown-callback-example-lambda" name="callback-example-lambda"></a>
#### Example using lambda
```cpp
// Callback function used in Refresh_callback
auto lambda_fct_callback = [](const Kinova::Api::Error &err, const k_api::BaseCyclic::Feedback data)
{
    // We are printing the data for example purpose
    std::string serialized_data;
    google::protobuf::util::MessageToJsonString(data, &serialized_data);
    std::cout << serialized_data << std::endl;
};

base_cyclic->Refresh_callback(base_command, lambda_fct_callback, 0);
```

<a id="markdown-callback-example-c" name="callback-example-c"></a>
#### Example using C callback
```cpp
namespace k_api = Kinova::Api;

void print_limitations(const k_api::Base::JointsLimitationsList& limitations)
{
    std::cout << "============================================" << std::endl;
    for(auto limitation : limitations.joints_limitations())
    {
        std::cout << "Joint: " << limitation.joint_identifier() << std::endl;
        std::cout << "Type of limitation: " << k_api::Base::LimitationType_Name(limitation.type()) << std::endl;
        std::cout << "Value: " << limitation.value() << std::endl << std::endl;
    }
    std::cout << "============================================" << std::endl << std::endl;
}

// Callback function used in Refresh_callback
void function_callback(const k_api::Error& err, const k_api::Base::JointsLimitationsList& limitations)
{
    std::cout << "Callback function results: " << std::endl << std::endl;
    print_limitations(limitations);
}

void example_function_call()
{
    base->GetAllJointsSpeedHardLimitation_callback(function_callback);
}
```

<a id="markdown-async-function" name="async-function"></a>
## Async method
The last mechanism offered by the Kortex API is an async function that uses the **future/promise** process. The user calls the async version of the method and then waits until the **promise** is completed and the **future** object is returned. 

The name of the async version method is that used in the blocking call version, but with '_async' appended to the name, i.e. `MethodName_async()`.

The async method is preferred when the user wants to call many functions in a short window of time. For example, if for some reason you want to talk directly to many actuators without using the robot's base synchronization process, using the **async** method could be a solution.

```cpp
namespace k_api = Kinova::Api;

void print_limitations(const k_api::Base::JointsLimitationsList& limitations)
{
    std::cout << "============================================" << std::endl;
    for(auto limitation : limitations.joints_limitations())
    {
        std::cout << "Joint: " << limitation.joint_identifier() << std::endl;
        std::cout << "Type of limitation: " << k_api::Base::LimitationType_Name(limitation.type()) << std::endl;
        std::cout << "Value: " << limitation.value() << std::endl << std::endl;
    }
    std::cout << "============================================" << std::endl << std::endl;
}

void example_future_function_call(k_api::Base::BaseClient* base)
{
    // The function returns a future object, and not a workable object.
    std::future<k_api::Base::JointsLimitationsList> limitations_future_async = base->GetAllJointsSpeedHardLimitation_async();
    
    // Waiting for the promise to be completed by the API.
    auto timeout_ms = std::chrono::milliseconds(10000);
    std::future_status status = limitations_future_async.wait_for(timeout_ms);
    if(status != std::future_status::ready)
    {
        throw std::runtime_error("Timeout detected while waiting for function\n");
    }
    
    // Retrieve the workable object from the future object.
    auto limitations_async = limitations_future_async.get();
    std::cout << "Future function results: " << std::endl << std::endl;
    print_limitations(limitations_async);
}
```
