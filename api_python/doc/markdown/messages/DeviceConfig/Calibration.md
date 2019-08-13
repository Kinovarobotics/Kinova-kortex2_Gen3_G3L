# class Calibration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|calibration\_item|int|Item to calibrate|You can manipulate the field calibration\_item as if it were a regular field. To clear the value of calibration\_item and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|calibration\_parameter| [CalibrationParameter](CalibrationParameter.md#)|Parameters associated to calibration item|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [DeviceConfig \(Python\)](../../summary_pages/DeviceConfig.md)

