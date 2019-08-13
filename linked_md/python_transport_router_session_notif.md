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

<h1>Transport, RouterCient, SessionManager and NotificationHandler</h1>

<h2>Table of Contents</h2>

<!-- TOC -->

- [Overview](#overview)
- [Transport](#transport)
- [RouterClient](#router)
- [SessionManager](#sessionmanager)
- [NotificationHandler](#notificationhandler)

<!-- TOC -->

<a id="markdown-overview" name="overview"></a>
## Overview
This document covers how to communicate with the robot base, in both directions.

Connections with the robot base are covered by the `Transport` class, `Router` class and `Session Manager` class. Once the connection is established, commands can be sent to the robot base and corresponding responses received. 

To receive unsolicited messages from the robot base, the notification handler must be implemented.

<a id="markdown-transport" name="transport"></a>
## Transport

A `Transport` class is used to instantiate an object which identifies the robot base being connected to, by specifying a communications protocol, an IP address and a port number.

Kinova provides two pre-defined `Transport` object types:

- `TCPTransport` - using TCP as a transport protocol
- `UDPTransport` - using UDP as a transport protocol

`TCPTransport` is used for high-level robot control, configuration, and any other purposes not requiring sending commands at high frequency.

`UDPTransport` can only be used for low-level cyclic communication at 1kHz with the robot via the `Kinova::Api::BaseCyclic` service. 

**Note**: In the Python API, low-level control is available, but for performance reasons is not recommended.
Only TCP should be used as a transport protocol in Python with a `TCPTransport` object.

`TCPTransport` and `UDPTransport` are subclasses of an abstract base class `ITransportClient`. Implementing a sub-class of this class allows you to implement your own transport. Here is the list of functions in the interface:

```python

# Connect to specified robot base. Host is a string for the 
# base IP address and port is an int for the port to use
@abstractmethod
def connect(self, host, port):
	pass

# Disconnect from robot base
@abstractmethod
def disconnect(self):
	pass

 # Send a message. txBuffer is a string holding the contents 
 # of the message, and txSize is an int for the length of the # message
@abstractmethod
def send(self, txBuffer, txSize):
	pass

#  Handler for received message. Callback is a function object
# taking a string and int as inputs.
@abstractmethod
def registerOnFrameCallback(self, callback):
	pass
```


<a id="markdown-router" name="router"></a>

## RouterClient
The `RouterClient` class is used to instantiate an object which sends the command to the robot base specified by the `Transport` object. A `RouterClient` object needs a `Transport` object to work. The purpose of the router is to transmit to the robot base all commands sent through the services.

It will also manage all messages sent and received by that service. A router needs to be specified each time a new service is declared.

To handle cases where there is a connection problem with the robot base, a callback method needs to be provided.

```python
errorCallback = lambda kException: print("_________ callback error _________ {}".format(kException))
transport = TCPTransport()
router = RouterClient(transport, errorCallback)
transport.connect(DEVICE_IP, DEVICE_PORT)
```

<a id="markdown-session-manager" name="session-manager"></a>
## SessionManager
The `SessionManager` object will manage the connection to the robot base. If no `SessionManager` is declared on an active connection, the robot base will not answer commands. A `SessionManager` requires a `RouterClient` object. The `SessionManager` will also manage the connection to ensure that it is still alive if sent commands take too long to execute.

```python
errorCallback = lambda kException: print("_________ callback error _________ {}".format(kException))
transport = TCPTransport()
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
## NotificationHandler
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
notif_handle = base.OnNotificationConfigurationChangeTopic(notification_callback, Base_pb2.NotificationOptions())
```
