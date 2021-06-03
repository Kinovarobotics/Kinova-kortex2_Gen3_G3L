# BaseCyclic \(Python\)

This page describes the Python BaseCyclic API.

## RPC reference

This section describes the existing RPCs used in this API.

Service to exchange cyclic data with base

 **BaseCyclicClient RPCs** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|Refresh|[Feedback](../messages/BaseCyclic/Feedback.md#)|[Command](../messages/BaseCyclic/Command.md#)|Sends a command to actuators and interface and returns feedback from base, actuators, and interface on actual status|
|RefreshCommand|[Empty](../messages/Common/Empty.md#)|[Command](../messages/BaseCyclic/Command.md#)|Sends a command to actuators and interface without receiving feedback|
|RefreshFeedback|[Feedback](../messages/BaseCyclic/Feedback.md#)|[Empty](../messages/Common/Empty.md#)|Obtains feedback from base, actuators, and interface on their status|
|RefreshCustomData|[CustomData](../messages/BaseCyclic/CustomData.md#)|[CustomData](../messages/BaseCyclic/CustomData.md#)|Retrieves custom data|

## Class reference

This section describes the data classes used in this API.

 **Messages** 

|Class|Description|
|-----|-----------|
|[ActuatorCommand](../messages/BaseCyclic/ActuatorCommand.md#)|Defines an actuator command|
|[ActuatorCustomData](../messages/BaseCyclic/ActuatorCustomData.md#)|Custom development data from an actuator, content varies according to debug needs|
|[ActuatorFeedback](../messages/BaseCyclic/ActuatorFeedback.md#)|Defines the feedback provided by an actuator|
|[BaseFeedback](../messages/BaseCyclic/BaseFeedback.md#)|Defines the feedback provided by the base|
|[Command](../messages/BaseCyclic/Command.md#)|Defines a command provided to robot devices \(actuators and interface\)|
|[CustomData](../messages/BaseCyclic/CustomData.md#)|Custom development data, content varies according to debug needs|
|[Feedback](../messages/BaseCyclic/Feedback.md#)|Defines the feedback provided by robot devices \(base, actuators and interface\)|

 **Enumerators** 

|Enumerator|Description|
|----------|-----------|
|[ServiceVersion](../enums/BaseCyclic/ServiceVersion.md#)|Identifies BaseCyclic current version|

