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

<h1>Transport and Router classes, Session Manager and notification handler</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Transport class](#transport-class)
- [Router class](#router-class)
- [Session Manager](#session-manager)
- [Notification Handler](#notification-handler)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
This document covers communication with the robot base, in both directions.

Connections with the robot base are covered by the Transport class, Router class and Sessions Manager sections. Once the connection is established commands can be sent to the robot base and corresponding responses received. To receive unsolicited messages from the robot base the notification handler must be implemented.

<a id="markdown-transport" name="transport"></a>

## Transport class
The ``Transport`` class is used to instantiate an object which identifies the robot base being connected to, by specifying an IP address and port number.

Currently, only UDP is implemented.

```cpp
namespace k_api = Kinova::Api;

k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();
pTransport->connect(IP_ADDRESS, PORT);
```

Also there is an interface call ``ITransportClient`` that allow you to implement your own transport. Here's the list of function in the interface:

```cpp
virtual bool connect(std::string host, uint32_t port) = 0;
virtual void disconnect() = 0;

virtual void send(const char* txBuffer, uint32_t txSize) = 0;
virtual void onMessage(std::function<void (const char*, uint32_t)> callback) = 0;

virtual char* getTxBuffer() = 0;
virtual size_t getMaxTxBufferSize() = 0;
```

<a id="markdown-router" name="router"></a>

## Router class
The ``Router`` class is used to instantiate an object which sends the command to the robot base specified by the ``Transport`` object. A ``Router`` object needs a ``Transport`` object to work. The purpose of the router is to transmit to the robot base all commands sent through the services.

It will also manage all messages sended and received by that service. A new router needs to be specified each a new service is declared.

For cases where there is a connection problem with the robot base, a callback method needs to be provided.

```cpp
namespace k_api = Kinova::Api;

k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();

k_api::RouterClient* pRouter = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

pTransport->connect(IP_ADDRESS, PORT);
```

<a id="markdown-session-manager" name="session-manager"></a>
## Session Manager

The **Session Manager** will manage the connection to the robot base. If no Session Manager is declared on an active connection, the robot base will not answer commands. The Session Manager will also manage the connection to ensure that it is still alive if sent commands take too long to execute.

```cpp
namespace k_api = Kinova::Api;

k_api::TransportClientUdp* pTransport = new k_api::TransportClientUdp();

k_api::RouterClient* pRouter = new k_api::RouterClient(pTransport, [](k_api::KError err){ std::cout << "_________ callback error _________" << err.toString(); });

pTransport->connect(IP_ADDRESS, PORT);

auto createSessionInfo = k_api::Session::CreateSessionInfo();
createSessionInfo.set_username("admin");
createSessionInfo.set_password("admin");
createSessionInfo.set_session_inactivity_timeout(60000);   // (milliseconds)
createSessionInfo.set_connection_inactivity_timeout(2000); // (milliseconds)

k_api::SessionManager* pSessionMng = new k_api::SessionManager(pRouter);
pSessionMng->CreateSession(createSessionInfo);
```


<a id="markdown-notification-handler" name="notification-handler"></a>
## Notification Handler
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
auto notifHandle = pBase->OnNotificationConfigurationChangeTopic(notification_callback, k_api::Common::NotificationOptions());
```
