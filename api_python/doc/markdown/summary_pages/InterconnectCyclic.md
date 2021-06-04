# InterconnectCyclic \(Python\)

This page describes the Python InterconnectCyclic API.

## RPC reference

This section describes the existing RPCs used in this API.

Service to exchange cyclic data with interface module

 **InterconnectCyclicClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|Refresh|[Feedback](../messages/InterconnectCyclic/Feedback.md#)|[Command](../messages/InterconnectCyclic/Command.md#)|Sends a command to the interface module and receive feedback about the actual status|
|RefreshCommand|[Empty](../messages/Common/Empty.md#)|[Command](../messages/InterconnectCyclic/Command.md#)|Sends a command to the interface module without receiving feedback|
|RefreshFeedback|[Feedback](../messages/InterconnectCyclic/Feedback.md#)|[MessageId](../messages/InterconnectCyclic/MessageId.md#)|Obtains feedback from the interface module on its status|
|RefreshCustomData|[CustomData](../messages/InterconnectCyclic/CustomData.md#)|[MessageId](../messages/InterconnectCyclic/MessageId.md#)|Obtains custom data from the interface module|

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[Command](../messages/InterconnectCyclic/Command.md#)|Interface module command|
|[CustomData](../messages/InterconnectCyclic/CustomData.md#)|Custom development data, content varies according to debugging needs|
|[Feedback](../messages/InterconnectCyclic/Feedback.md#)|Defines the feedback provided by interface module|
|[MessageId](../messages/InterconnectCyclic/MessageId.md#)|Identifies a message|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[ServiceVersion](../enums/InterconnectCyclic/ServiceVersion.md#)|Identifies InterconnectCyclic service current version|

