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
The C++ Kortex API offers three mechanisms to call a method: (1) the standard **blocking** method, (2) the **callback** function version and the (3) **async** method.


<a id="markdown-blocking-function" name="blocking-function"></a>
## Blocking method
One of the mechanisms offered by the Kortex API is to use **blocking** method (blocking call). If a procedural approach suffices, it is the easiest. The method is called; execution is blocked until the result is returned by the server side.


```cpp
// Execution will be blocked until GetAvailableWifi has completed its execution.
auto availableWifi = pBase->GetAvailableWifi();
```

<a id="markdown-callback" name="callback"></a>
## Callback
It is also possible to call an method and specify a **callback** function that will be called when the answer from the server side is received.

<a id="markdown-callback-example-lambda" name="callback-example-lambda"></a>
#### Example using lambda
```cpp
// callback function used in Refresh_callback
auto lambda_fct_callback = [](const Kinova::Api::Error &err, const k_api::BaseCyclic::Feedback data)
{
    // we are printing the data for example purposes
    std::string serializedData;
    google::protobuf::util::MessageToJsonString(data, &serializedData);
    std::cout << serializedData << std::endl;
};

pBaseCyclicService->Refresh_callback(BaseCommand, lambda_fct_callback, 0);
```

<a id="markdown-callback-example-c" name="callback-example-c"></a>
#### Example using C callback
```cpp
namespace k_api = Kinova::Api;

void printWifiList(k_api::Base::WifiInformationList availableWifi)
{
    for(int i = 0 ; i < availableWifi.wifi_information_list_size(); i++)
    {
        std::cout << "============================================" << std::endl;
        std::cout << "SSID: " << availableWifi.wifi_information_list(i).ssid().identifier() << std::endl;
        std::cout << "Wi-Fi security type: " << availableWifi.wifi_information_list(i).security_type() << std::endl;
        std::cout << "Wi-Fi encryption type: " << availableWifi.wifi_information_list(i).encryption_type() << std::endl;
        std::cout << "Signal strength: " << availableWifi.wifi_information_list(i).signal_strength() << std::endl;
        std::cout << "============================================" << std::endl << std::endl;
    }
}

// callback function used in Refresh_callback
void fct_callback(const k_api::Error &err, const k_api::BaseCyclic::Feedback data)
{
    std::cout << "Callback function results: " << std::endl << std::endl;
    printWifiList(wifiList);
}

void example_function_call()
{
	pBaseCyclicService->Refresh_callback(BaseCommand, fct_callback, 0);
}

```

<a id="markdown-async-function" name="async-function"></a>
## Async method
The last mechanism offered by the Kortex API is an async function that uses the **future/promise** process. The user calls the async version of the method and then waits until the **promise** is completed and the **future** object is returned. The async method is preferred when the user wants to call many functions in a short window of time. As an example, if for some reason you want to talk directly to many actuators without using the robot's base synchronization process, using the **async** method could be a solution.

```cpp
namespace k_api = Kinova::Api;

void printWifiList(k_api::Base::WifiInformationList availableWifi)
{
    for(int i = 0 ; i < availableWifi.wifi_information_list_size(); i++)
    {
        std::cout << "============================================" << std::endl;
        std::cout << "SSID: " << availableWifi.wifi_information_list(i).ssid().identifier() << std::endl;
        std::cout << "Wi-Fi security type: " << availableWifi.wifi_information_list(i).security_type() << std::endl;
        std::cout << "Wi-Fi encryption type: " << availableWifi.wifi_information_list(i).encryption_type() << std::endl;
        std::cout << "Signal strength: " << availableWifi.wifi_information_list(i).signal_strength() << std::endl;
        std::cout << "============================================" << std::endl << std::endl;
    }
}

void example(k_api::Base::BaseClient* pBase)
{

    // The function returns a future, not a workable object.
    std::future<k_api::Base::WifiInformationList> availableWifiFuture_async = pBase->GetAvailableWifi_async();
    
    // Waiting for the promise to be complete by the API.
    auto timeout_ms = std::chrono::milliseconds(10000);
    std::future_status status = availableWifiFuture_async.wait_for(timeout_ms);
    
    if(status != std::future_status::ready)
    {
        throw std::runtime_error("Timeout detected while waiting for function\n");
    }
    
    // Retrieve the workable object from the future.
    auto availableWifi_async = availableWifiFuture_async.get();
    std::cout << "Future function results: " << std::endl << std::endl;
    printWifiList(availableWifi_async);
}
```
