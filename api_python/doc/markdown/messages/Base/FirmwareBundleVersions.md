# class FirmwareBundleVersions

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|main\_bundle\_version|str|Version of the main bundle|You can manipulate the field main\_bundle\_version as if it were a regular field. To clear the value of main\_bundle\_version and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|components\_versions| [FirmwareComponentVersion](FirmwareComponentVersion.md#)|List containing all components of the bundle|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

