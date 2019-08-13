# class SensorFocusAction

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|sensor|int|The sensor on which to perform the focus action|You can manipulate the field sensor as if it were a regular field. To clear the value of sensor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|focus\_action|int|The focus action to perform on the sensor|You can manipulate the field focus\_action as if it were a regular field. To clear the value of focus\_action and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|focus\_point|oneof:action\_parameters [FocusPoint](FocusPoint.md#)|The X-Y point on which to focus|You can manipulate the field focus\_point as if it were a regular field. To clear the value of focus\_point and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|
|manual\_focus|oneof:action\_parameters [ManualFocus](ManualFocus.md#)|The manual focus abstract value|You can manipulate the field manual\_focus as if it were a regular field. To clear the value of manual\_focus and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface. The message class also has a WhichOneof method that lets you find out which field \(if any\) in the oneof has been set.|

**Parent topic:** [VisionConfig \(Python\)](../../summary_pages/VisionConfig.md)

