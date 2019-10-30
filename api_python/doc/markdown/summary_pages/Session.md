# Session \(Python\)

This page describes the Python Session API.

## Class reference

This section describes the data classes used in this API, as well as their member values and member functions.

 **Messages** 

|Class|Description|
|-----|-----------|
|[ConnectionList](../messages/Session/ConnectionList.md#)|Array of connections|
|[CreateSessionInfo](../messages/Session/CreateSessionInfo.md#)|Parameters needed to create a new session|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[ServiceVersion](../enums/Session/ServiceVersion.md#)|Identifies session service current version|

Service to manage user sessions

 **SessionClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|CreateSession|[Empty](../messages/Common/Empty.md#)|[CreateSessionInfo](../messages/Session/CreateSessionInfo.md#)|Creates a new session on the robot using given values for user name, session timeout value, and password|
|CloseSession|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Closes an existing open session|
|KeepAlive|[Empty](../messages/Common/Empty.md#)|[Empty](../messages/Common/Empty.md#)|Sends message to robot to keep current session alive|
|GetConnections|[ConnectionList](../messages/Session/ConnectionList.md#)|[Empty](../messages/Common/Empty.md#)|Retrieves the list of connections|

