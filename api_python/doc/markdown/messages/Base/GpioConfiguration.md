# class GpioConfiguration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|port\_number|int|Port number \(Base extension port is port 0\)|You can manipulate the field port\_number as if it were a regular field. To clear the value of port\_number and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|pin\_configurations| [GpioPinConfiguration](GpioPinConfiguration.md#)|Pin configuration list|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

