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

<h1>TransportClient, RouterClient, SessionManager and NotificationHandler</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [TransportClient classes](#transportclient-classes)
- [RouterClient class](#routerclient-class)
- [SessionManager](#sessionmanager)
- [NotificationHandler](#notificationhandler)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
This section covers communication with the robot base, in both directions.
Connections with the robot base are enabled by:
- Transport classes
- Router class
- Session Manager

Once the connection is established, commands can be sent to the robot base and corresponding responses received. 

To receive unsolicited messages from the robot base, the notification handler must be implemented.

<a id="markdown-transport" name="transport"></a>

## TransportClient classes
`TransportClient` classes are used to instantiate an object which identifies the robot base being connected to, by specifying an IP address and port number.

Kinova provides two pre-defined `TransportClient` object types:

- `TransportClientTcp` - using TCP as a transport protocol
- `TransportClientUdp` - using UDP as a transport protocol

`TransportClientTcp` is used for high-level robot control, configuration, and any other purposes not requiring sending commands at high frequency.

`TransportClientUdp` can only be used for low-level cyclic communication at 1kHz with the robot via the `Kinova::Api::BaseCyclic` service. 

```cpp
namespace k_api = Kinova::Api;

k_api::TransportClientTcp* transport = new k_api::TransportClientTcp();
transport->connect(IP_ADDRESS, PORT);
```

`TransportClientUdp` and `TransportClientTcp` are both sub-classes of an interface provided called `ITransportClient`. This interface allows you to implement your own transport. Here is the list of functions in the interface:

```cpp
// connect to a specified robot base
virtual bool connect(std::string host, uint32_t port) = 0;
// disconnect from the base
virtual void disconnect() = 0;
// send a message
virtual void send(const char* txBuffer, uint32_t txSize) = 0;
// handler for received messages
virtual void onMessage(std::function<void (const char*, uint32_t)> callback) = 0;
// obtain a transmission buffer for holding content of outgoing messages
virtual char* getTxBuffer() = 0;
// obtain maximum size of transmission buffer
virtual size_t getMaxTxBufferSize() = 0;
```

<a id="markdown-router" name="router"></a>

## RouterClient class
The `RouterClient` class is used to instantiate an object which sends the command to the robot base specified by a `TransportClient` object. A `RouterClient` object needs a `TransportClient` object to work. 

The purpose of the router is to transmit to the robot base all commands sent through the services.
It will also manage all messages sent and received by that service. A router needs to be specified each time a new service is declared.

To handle cases where there is a connection problem with the robot base, a callback method needs to be provided.

```cpp
namespace k_api = Kinova::Api;

k_api::TransportClientTcp* transport = new k_api::TransportClientTcp();

k_api::RouterClient* router = new k_api::RouterClient(transport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

transport->connect(IP_ADDRESS, PORT);
```

<a id="markdown-session-manager" name="session-manager"></a>
## SessionManager

The `SessionManager` object will manage the connection to the robot base for a specified user. If no `SessionManager` is declared on an active connection, the robot base will not answer commands.
A `SessionManager` object requires a `RouterClient` object. The `SessionManager` will also manage the connection to ensure that it is still alive if sent commands take too long to execute.

```cpp
namespace k_api = Kinova::Api;

k_api::TransportClientTcp* transport = new k_api::TransportClientTcp();

k_api::RouterClient* router = new k_api::RouterClient(transport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

transport->connect(IP_ADDRESS, PORT);

auto createSessionInfo = k_api::Session::CreateSessionInfo();
createSessionInfo.set_username("admin");
createSessionInfo.set_password("admin");
createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

k_api::SessionManager* session_manager = new k_api::SessionManager(router);
session_manager->CreateSession(createSessionInfo);
```


<a id="markdown-notification-handler" name="notification-handler"></a>
## NotificationHandler
The robot base provides notifications on different topics as requested by a client application that has a session open with the robot.
The robot base uses a **Publish/Subscribe** design pattern. Rather than polling periodically for updates, the client application subscribes to a list of topics. Whenever a change happens related to that topic, whether caused by the same client session or not, the publisher sends a notification to all subscribers.

```cpp
/*
In this example, when a user is created `notification_callback` will be called because we register it as a
handler for `ConfigurationChange` topic notifications.
*/
auto notification_callback = [](k_api::Base::ConfigurationChangeNotification data)
{
	std::string jsonString = "";
	google::protobuf::util::MessageToJsonString(data, &jsonString);
	std::cout << "********************************" << std::endl;
	std::cout << "**  Callback function called  **" << std::endl;
	std::cout << jsonString << std::endl;
	std::cout << "********************************" << std::endl;
};

// Subscribe to ConfigurationChange notifications
auto notifHandle = base->OnNotificationConfigurationChangeTopic(notification_callback, k_api::Common::NotificationOptions());
```
