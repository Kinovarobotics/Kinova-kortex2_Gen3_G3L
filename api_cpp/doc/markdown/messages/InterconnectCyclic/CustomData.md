# class CustomData

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|custom\_data\_id| [MessageId](MessageId.md#)|MessageId|
|custom\_data\_0|uint32|Custom data word 0|
|custom\_data\_1|uint32|Custom data word 1|
|custom\_data\_2|uint32|Custom data word 2|
|custom\_data\_3|uint32|Custom data word 3|
|custom\_data\_4|uint32|Custom data word 4|
|custom\_data\_5|uint32|Custom data word 5|
|custom\_data\_6|uint32|Custom data word 6|
|custom\_data\_7|uint32|Custom data word 7|
|custom\_data\_8|uint32|Custom data word 8|
|custom\_data\_9|uint32|Custom data word 9|
|custom\_data\_10|uint32|Custom data word 10|
|custom\_data\_11|uint32|Custom data word 11|
|custom\_data\_12|uint32|Custom data word 12|
|custom\_data\_13|uint32|Custom data word 13|
|custom\_data\_14|uint32|Custom data word 14|
|custom\_data\_15|uint32|Custom data word 15|
|gripper\_custom\_data|oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#)| |

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_custom\_data\_id\(\) const|bool|void|Returns true if custom\_data\_id is set.|
|custom\_data\_id\(\)|const [MessageId](MessageId.md#)&|void|Returns the current value of custom\_data\_id. If custom\_data\_id is not set, returns a [MessageId](MessageId.md#) with none of its fields set \(possibly custom\_data\_id::default\_instance\(\)\).|
|mutable\_custom\_data\_id\(\)| [MessageId](MessageId.md#) \*|void|Returns a pointer to the mutable [MessageId](MessageId.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [MessageId](MessageId.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [MessageId](MessageId.md#)\). After calling this, has\_custom\_data\_id\(\) will return true and custom\_data\_id\(\) will return a reference to the same instance of [MessageId](MessageId.md#).|
|clear\_custom\_data\_id\(\)|void|void|Clears the value of the field. After calling this, has\_custom\_data\_id\(\) will return false and custom\_data\_id\(\) will return the default value.|
|set\_allocated\_custom\_data\_id\(\)|void| [MessageId](MessageId.md#) \*|Sets the [MessageId](MessageId.md#) object to the field and frees the previous field value if it exists. If the [MessageId](MessageId.md#) pointer is not NULL, the message takes ownership of the allocated [MessageId](MessageId.md#) object and has\_ [MessageId](MessageId.md#)\(\) will return true. Otherwise, if the custom\_data\_id is NULL, the behavior is the same as calling clear\_custom\_data\_id\(\).|
|release\_custom\_data\_id\(\)| [MessageId](MessageId.md#) \*|void|Releases the ownership of the field and returns the pointer of the [MessageId](MessageId.md#) object. After calling this, caller takes the ownership of the allocated [MessageId](MessageId.md#) object, has\_custom\_data\_id\(\) will return false, and custom\_data\_id\(\) will return the default value.|
|custom\_data\_0\(\)|uint32|void|Returns the current value of custom\_data\_0. If the custom\_data\_0 is not set, returns 0.|
|set\_custom\_data\_0\(\)|void|uint32|Sets the value of custom\_data\_0. After calling this, custom\_data\_0\(\) will return value.|
|clear\_custom\_data\_0\(\)|void|void|Clears the value of custom\_data\_0. After calling this, custom\_data\_0\(\) will return 0.|
|custom\_data\_1\(\)|uint32|void|Returns the current value of custom\_data\_1. If the custom\_data\_1 is not set, returns 0.|
|set\_custom\_data\_1\(\)|void|uint32|Sets the value of custom\_data\_1. After calling this, custom\_data\_1\(\) will return value.|
|clear\_custom\_data\_1\(\)|void|void|Clears the value of custom\_data\_1. After calling this, custom\_data\_1\(\) will return 0.|
|custom\_data\_2\(\)|uint32|void|Returns the current value of custom\_data\_2. If the custom\_data\_2 is not set, returns 0.|
|set\_custom\_data\_2\(\)|void|uint32|Sets the value of custom\_data\_2. After calling this, custom\_data\_2\(\) will return value.|
|clear\_custom\_data\_2\(\)|void|void|Clears the value of custom\_data\_2. After calling this, custom\_data\_2\(\) will return 0.|
|custom\_data\_3\(\)|uint32|void|Returns the current value of custom\_data\_3. If the custom\_data\_3 is not set, returns 0.|
|set\_custom\_data\_3\(\)|void|uint32|Sets the value of custom\_data\_3. After calling this, custom\_data\_3\(\) will return value.|
|clear\_custom\_data\_3\(\)|void|void|Clears the value of custom\_data\_3. After calling this, custom\_data\_3\(\) will return 0.|
|custom\_data\_4\(\)|uint32|void|Returns the current value of custom\_data\_4. If the custom\_data\_4 is not set, returns 0.|
|set\_custom\_data\_4\(\)|void|uint32|Sets the value of custom\_data\_4. After calling this, custom\_data\_4\(\) will return value.|
|clear\_custom\_data\_4\(\)|void|void|Clears the value of custom\_data\_4. After calling this, custom\_data\_4\(\) will return 0.|
|custom\_data\_5\(\)|uint32|void|Returns the current value of custom\_data\_5. If the custom\_data\_5 is not set, returns 0.|
|set\_custom\_data\_5\(\)|void|uint32|Sets the value of custom\_data\_5. After calling this, custom\_data\_5\(\) will return value.|
|clear\_custom\_data\_5\(\)|void|void|Clears the value of custom\_data\_5. After calling this, custom\_data\_5\(\) will return 0.|
|custom\_data\_6\(\)|uint32|void|Returns the current value of custom\_data\_6. If the custom\_data\_6 is not set, returns 0.|
|set\_custom\_data\_6\(\)|void|uint32|Sets the value of custom\_data\_6. After calling this, custom\_data\_6\(\) will return value.|
|clear\_custom\_data\_6\(\)|void|void|Clears the value of custom\_data\_6. After calling this, custom\_data\_6\(\) will return 0.|
|custom\_data\_7\(\)|uint32|void|Returns the current value of custom\_data\_7. If the custom\_data\_7 is not set, returns 0.|
|set\_custom\_data\_7\(\)|void|uint32|Sets the value of custom\_data\_7. After calling this, custom\_data\_7\(\) will return value.|
|clear\_custom\_data\_7\(\)|void|void|Clears the value of custom\_data\_7. After calling this, custom\_data\_7\(\) will return 0.|
|custom\_data\_8\(\)|uint32|void|Returns the current value of custom\_data\_8. If the custom\_data\_8 is not set, returns 0.|
|set\_custom\_data\_8\(\)|void|uint32|Sets the value of custom\_data\_8. After calling this, custom\_data\_8\(\) will return value.|
|clear\_custom\_data\_8\(\)|void|void|Clears the value of custom\_data\_8. After calling this, custom\_data\_8\(\) will return 0.|
|custom\_data\_9\(\)|uint32|void|Returns the current value of custom\_data\_9. If the custom\_data\_9 is not set, returns 0.|
|set\_custom\_data\_9\(\)|void|uint32|Sets the value of custom\_data\_9. After calling this, custom\_data\_9\(\) will return value.|
|clear\_custom\_data\_9\(\)|void|void|Clears the value of custom\_data\_9. After calling this, custom\_data\_9\(\) will return 0.|
|custom\_data\_10\(\)|uint32|void|Returns the current value of custom\_data\_10. If the custom\_data\_10 is not set, returns 0.|
|set\_custom\_data\_10\(\)|void|uint32|Sets the value of custom\_data\_10. After calling this, custom\_data\_10\(\) will return value.|
|clear\_custom\_data\_10\(\)|void|void|Clears the value of custom\_data\_10. After calling this, custom\_data\_10\(\) will return 0.|
|custom\_data\_11\(\)|uint32|void|Returns the current value of custom\_data\_11. If the custom\_data\_11 is not set, returns 0.|
|set\_custom\_data\_11\(\)|void|uint32|Sets the value of custom\_data\_11. After calling this, custom\_data\_11\(\) will return value.|
|clear\_custom\_data\_11\(\)|void|void|Clears the value of custom\_data\_11. After calling this, custom\_data\_11\(\) will return 0.|
|custom\_data\_12\(\)|uint32|void|Returns the current value of custom\_data\_12. If the custom\_data\_12 is not set, returns 0.|
|set\_custom\_data\_12\(\)|void|uint32|Sets the value of custom\_data\_12. After calling this, custom\_data\_12\(\) will return value.|
|clear\_custom\_data\_12\(\)|void|void|Clears the value of custom\_data\_12. After calling this, custom\_data\_12\(\) will return 0.|
|custom\_data\_13\(\)|uint32|void|Returns the current value of custom\_data\_13. If the custom\_data\_13 is not set, returns 0.|
|set\_custom\_data\_13\(\)|void|uint32|Sets the value of custom\_data\_13. After calling this, custom\_data\_13\(\) will return value.|
|clear\_custom\_data\_13\(\)|void|void|Clears the value of custom\_data\_13. After calling this, custom\_data\_13\(\) will return 0.|
|custom\_data\_14\(\)|uint32|void|Returns the current value of custom\_data\_14. If the custom\_data\_14 is not set, returns 0.|
|set\_custom\_data\_14\(\)|void|uint32|Sets the value of custom\_data\_14. After calling this, custom\_data\_14\(\) will return value.|
|clear\_custom\_data\_14\(\)|void|void|Clears the value of custom\_data\_14. After calling this, custom\_data\_14\(\) will return 0.|
|custom\_data\_15\(\)|uint32|void|Returns the current value of custom\_data\_15. If the custom\_data\_15 is not set, returns 0.|
|set\_custom\_data\_15\(\)|void|uint32|Sets the value of custom\_data\_15. After calling this, custom\_data\_15\(\) will return value.|
|clear\_custom\_data\_15\(\)|void|void|Clears the value of custom\_data\_15. After calling this, custom\_data\_15\(\) will return 0.|
|has\_gripper\_custom\_data\(\) const|void|void|Returns the current value of the field if oneof case is kGripper\_custom\_data. Otherwise, returns oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#)::default\_instance\(\)|
|gripper\_custom\_data\(\) const|const oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#)&|void|Returns the current value of the field if oneof case is kGripper\_custom\_data|
|mutable\_gripper\_custom\_data\(\)|oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#)\*|void|If any other oneof field in the same oneof is set, calls clear\_tool\_customData\(\). Sets the oneof case to kGripper\_custom\_data and returns a pointer to the mutable oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#) object that stores the field's value. If the oneof case was not kGripper\_custom\_data prior to the call, then the returned oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#)\). After calling this, has\_gripper\_custom\_data\(\) will return true, gripper\_custom\_data\(\) will return a reference to the same instance of oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#) and tool\_customData\_case\(\) will return kGripper\_custom\_data|
|clear\_gripper\_custom\_data\(\)|void|void|Nothing will be changed if the oneof case is not kGripper\_custom\_data. If the oneof case equals kGripper\_custom\_data, frees the field and clears the oneof case. has\_gripper\_custom\_data\(\) will return false, gripper\_custom\_data\(\) will return the default value and tool\_customData\_case\(\) will return TOOL\_CUSTOMDATA\_NOT\_SET.|
|set\_allocated\_gripper\_custom\_data\(\)|void|oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#)\*|Calls clear\_tool\_customData\(\). If the oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#) pointer is not NULL: Sets the oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#) object to the field and sets the oneof case to kGripper\_custom\_data. The message takes ownership of the allocated oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#) object, has\_gripper\_custom\_data\(\) will return true and tool\_customData\_case\(\) will return kGripper\_custom\_data. If the pointer is NULL, has\_gripper\_custom\_data\(\) will return false and tool\_customData\_case\(\) will return TOOL\_CUSTOMDATA\_NOT\_SET. \(The behavior is like calling clear\_tool\_customData\(\)\)|
|release\_gripper\_custom\_data\(\)|oneof:tool\_customData [CustomData](../GripperCyclic/CustomData.md#)\*|void|Returns NULL if oneof case is not kGripper\_custom\_data. If the oneof case is kGripper\_custom\_data, clears the oneof case, releases the ownership of the field and returns the pointer of the tool\_customData object. After calling this, caller takes the ownership of the allocated tool\_customData object, has\_gripper\_custom\_data\(\) will return false, gripper\_custom\_data\(\) will return the default value and tool\_customData\_case\(\) will return TOOL\_CUSTOMDATA\_NOT\_SET.|

**Parent topic:** [InterconnectCyclic \(C++\)](../../summary_pages/InterconnectCyclic.md)

