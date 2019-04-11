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

<h1>Transport and Router classes, Session Manager and Notification handler</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Transport](#transport)
- [Router](#router)
- [Session Manager](#session-manager)
- [Notification Handler](#notification-handler)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
This document covers how to communicate with the robot base, in both directions.

Connections with the robot base are covered by the Transport class, Router class and Sessions Manager sections. Once the connection is established commands can be sent to the robot base and corresponding responses received. To receive unsolicited messages from the robot base the notification handler must be implemented.

<a id="markdown-transport" name="transport"></a>
## Transport

The ``Transport`` class is used to instantiate an object which identifies the robot base being connected to, by specifying a communications protocol, an IP address and a port number.

Currently, only UDP is implemented.

```python
transport = UDPTransport()
transport.connect(DEVICE_IP, DEVICE_PORT)
```
Also there is an interface call ``ITransportClient`` that allow you to implement your own transport. Here's the list of function in the interface:

```python
@abstractmethod
def connect(self, host, port):
	pass

@abstractmethod
def disconnect(self):
	pass

@abstractmethod
def send(self, txBuffer, txSize):
	pass

@abstractmethod
def registerOnFrameCallback(self, callback):
	pass
```


<a id="markdown-router" name="router"></a>

## Router
The ``Router`` class is used to instantiate an object which sends the command to the robot base specified by the ``Transport`` object. A ``Router`` object needs a ``Transport`` object to work. The purpose of the router is to transmit to the robot base all commands sent through the services.

It will also manage all messages sent and received by that service. A new router needs to be specified each a new service is declared.

For cases where there is a connection problem with the robot base, a callback method needs to be provided.

```python
errorCallback = lambda kException: print("_________ callback error _________ {}".format(kException))
transport = UDPTransport()
router = RouterClient(transport, errorCallback)
transport.connect(DEVICE_IP, DEVICE_PORT)
```

<a id="markdown-session-manager" name="session-manager"></a>
## Session Manager
The **Session Manager** will manage the connection to the robot base. If no Session Manager is declared on an active connection, the robot base will not answer commands. The Session Manager will also manage the connection to ensure that it is still alive if sent commands take too long to execute.

```python
errorCallback = lambda kException: print("_________ callback error _________ {}".format(kException))
transport = UDPTransport()
router = RouterClient(transport, errorCallback)
transport.connect(DEVICE_IP, DEVICE_PORT)

session_info = Session_pb2.CreateSessionInfo()
session_info.username = 'admin'
session_info.password = 'admin'
session_info.session_inactivity_timeout = 60000   # (milliseconds)
session_info.connection_inactivity_timeout = 2000 # (milliseconds)

session_manager = SessionManager(router)
session_manager.CreateSession(session_info)
```


<a id="markdown-notification-handler" name="notification-handler"></a>
## Notification Handler
The robot base provides notifications on different topics as requested by a client application that has a session open with the robot.
The robot base uses a **Publish/Subscribe** design pattern. Rather than polling periodically for updates, the client application subscribes to a list of topics. Whenever a change happens related to that topic, whether caused by the same client session or not, the publisher sends a notification to all subscribers.

```python
# In this example, when a user is created `notification_callback` will be called because we register it as a
# handler for `ConfigurationChange` topic notifications.
def notification_callback(data):
	print("********************************")
	print("**  Callback function called  **")
	print(json_format.MessageToJson(data))
	print("********************************")

# Subscribe to ConfigurationChange notifications
notif_handle = base_service.OnNotificationConfigurationChangeTopic(notification_callback, Base_pb2.NotificationOptions())
```
