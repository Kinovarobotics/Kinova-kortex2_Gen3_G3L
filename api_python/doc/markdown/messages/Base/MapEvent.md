# class MapEvent

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|safety\_event|oneof:events [SafetyEvent](SafetyEvent.md#)|Mapped safety event \(not implemented yet\)|You can manipulate the field safety\_event as if it were a regular field. To clear the value of safety\_event and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|
|gpio\_event|oneof:events [GpioEvent](GpioEvent.md#)|Mapped GPIO event|You can manipulate the field gpio\_event as if it were a regular field. To clear the value of gpio\_event and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|
|controller\_event|oneof:events [ControllerEvent](ControllerEvent.md#)|Mapped controller event|You can manipulate the field controller\_event as if it were a regular field. To clear the value of controller\_event and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|
|name|str|Map event friendly name|You can manipulate the field name as if it were a regular field. To clear the value of name and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

