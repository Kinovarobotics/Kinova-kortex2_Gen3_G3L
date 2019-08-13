# class SafetyInformation

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|handle| [SafetyHandle](../Common/SafetyHandle.md#)|Safety handle that this information is about|To set handle, you simply assign a value directly to a field within handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|can\_change\_safety\_state|bool|True if related safety configuration can be modified|You can manipulate the field can\_change\_safety\_state as if it were a regular field. To clear the value of can\_change\_safety\_state and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|has\_warning\_threshold|bool|True if safety status can go in Warning|You can manipulate the field has\_warning\_threshold as if it were a regular field. To clear the value of has\_warning\_threshold and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|has\_error\_threshold|bool|True if safety status can go in Error|You can manipulate the field has\_error\_threshold as if it were a regular field. To clear the value of has\_error\_threshold and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|limit\_type|int|Safety limit type|You can manipulate the field limit\_type as if it were a regular field. To clear the value of limit\_type and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|default\_warning\_threshold|float|Default warning threshold \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT and 'has\_warning\_threshold' is true\)|You can manipulate the field default\_warning\_threshold as if it were a regular field. To clear the value of default\_warning\_threshold and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|default\_error\_threshold|float|Default error threshold \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT and 'has\_error\_threshold' is true\)|You can manipulate the field default\_error\_threshold as if it were a regular field. To clear the value of default\_error\_threshold and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|upper\_hard\_limit|float|Maximal threshold value \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT\)|You can manipulate the field upper\_hard\_limit as if it were a regular field. To clear the value of upper\_hard\_limit and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|lower\_hard\_limit|float|Minimal threshold value \(if 'limit\_type' is either MINIMAL\_LIMIT or MAXIMAL\_LIMIT\)|You can manipulate the field lower\_hard\_limit as if it were a regular field. To clear the value of lower\_hard\_limit and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|status|int|Current Safety status|You can manipulate the field status as if it were a regular field. To clear the value of status and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|unit|int|Unit that the safety status is in|You can manipulate the field unit as if it were a regular field. To clear the value of unit and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [DeviceConfig \(Python\)](../../summary_pages/DeviceConfig.md)

