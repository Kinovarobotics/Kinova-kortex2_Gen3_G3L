# class Command

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|command\_id| [MessageId](MessageId.md#)|MessageId|
|flags|uint32|Flags|
|gripper\_command|oneof:tool\_command [Command](../GripperCyclic/Command.md#)|Gripper command|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_command\_id\(\) const|bool|void|Returns true if command\_id is set.|
|command\_id\(\)|const [MessageId](MessageId.md#)&|void|Returns the current value of command\_id. If command\_id is not set, returns a [MessageId](MessageId.md#) with none of its fields set \(possibly command\_id::default\_instance\(\)\).|
|mutable\_command\_id\(\)| [MessageId](MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](MessageId.md#)\). After calling this, has\_command\_id\(\) will return true and command\_id\(\) will return a reference to the same instance of [MessageId](MessageId.md#).|
|clear\_command\_id\(\)|void|void|Clears the value of the field. After calling this, has\_command\_id\(\) will return false and command\_id\(\) will return the default value.|
|set\_allocated\_command\_id\(\)|void| [MessageId](MessageId.md#) \*|Sets the [MessageId](MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](MessageId.md#) object and has\_ [MessageId](MessageId.md#)\(\) will return true. Otherwise, if the command\_id is NULL, the behavior is the same as calling clear\_command\_id\(\).|
|release\_command\_id\(\)| [MessageId](MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](MessageId.md#) object, has\_command\_id\(\) will return false, and command\_id\(\) will return the default value.|
|flags\(\)|uint32|void|Returns the current value of flags. If the flags is not set, returns 0.|
|set\_flags\(\)|void|uint32|Sets the value of flags. After calling this, flags\(\) will return value.|
|clear\_flags\(\)|void|void|Clears the value of flags. After calling this, flags\(\) will return 0.|
|has\_gripper\_command\(\) const|void|void|Returns the current value of the field if oneof case is kGripper\_command. Otherwise, returns oneof:tool\_command [Command](../GripperCyclic/Command.md#)::default\_instance\(\)|
|gripper\_command\(\) const|const oneof:tool\_command [Command](../GripperCyclic/Command.md#)&|void|Returns the current value of the field if oneof case is kGripper\_command|
|mutable\_gripper\_command\(\)|oneof:tool\_command [Command](../GripperCyclic/Command.md#)\*|void|If any other oneof field in the same oneof is set, calls clear\_tool\_command\(\). Sets the oneof case to kGripper\_command and returns a pointer to the mutable oneof:tool\_command [Command](../GripperCyclic/Command.md#) object that stores the field's value. If the oneof case was not kGripper\_command prior to the call, then the returned oneof:tool\_command [Command](../GripperCyclic/Command.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated oneof:tool\_command [Command](../GripperCyclic/Command.md#)\). After calling this, has\_gripper\_command\(\) will return true, gripper\_command\(\) will return a reference to the same instance of oneof:tool\_command [Command](../GripperCyclic/Command.md#) and tool\_command\_case\(\) will return kGripper\_command|
|clear\_gripper\_command\(\)|void|void|Nothing will be changed if the oneof case is not kGripper\_command. If the oneof case equals kGripper\_command, frees the field and clears the oneof case. has\_gripper\_command\(\) will return false, gripper\_command\(\) will return the default value and tool\_command\_case\(\) will return TOOL\_COMMAND\_NOT\_SET.|
|set\_allocated\_gripper\_command\(\)|void|oneof:tool\_command [Command](../GripperCyclic/Command.md#)\*|Calls clear\_tool\_command\(\). If the oneof:tool\_command [Command](../GripperCyclic/Command.md#) pointer is not NULL: Sets the oneof:tool\_command [Command](../GripperCyclic/Command.md#) object to the field and sets the oneof case to kGripper\_command. The message takes ownership of the allocated oneof:tool\_command [Command](../GripperCyclic/Command.md#) object, has\_gripper\_command\(\) will return true and tool\_command\_case\(\) will return kGripper\_command. If the pointer is NULL, has\_gripper\_command\(\) will return false and tool\_command\_case\(\) will return TOOL\_COMMAND\_NOT\_SET. \(The behavior is like calling clear\_tool\_command\(\)\)|
|release\_gripper\_command\(\)|oneof:tool\_command [Command](../GripperCyclic/Command.md#)\*|void|Returns NULL if oneof case is not kGripper\_command. If the oneof case is kGripper\_command, clears the oneof case, releases the ownership of the field and returns the pointer of the tool\_command object. After calling this, caller takes the ownership of the allocated tool\_command object, has\_gripper\_command\(\) will return false, gripper\_command\(\) will return the default value and tool\_command\_case\(\) will return TOOL\_COMMAND\_NOT\_SET.|

**Parent topic:** [InterconnectCyclic \(C++\)](../../summary_pages/InterconnectCyclic.md)

