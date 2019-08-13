# class SensorFocusAction

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|The sensor on which to perform the focus action|
|focus\_action|uint32|The focus action to perform on the sensor|
|focus\_point|oneof:action\_parameters [FocusPoint](FocusPoint.md#)|The X-Y point on which to focus|
|manual\_focus|oneof:action\_parameters [ManualFocus](ManualFocus.md#)|The manual focus abstract value|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|focus\_action\(\) const|uint32|void|Returns the current value of focus\_action. If the focus\_action is not set, returns 0.|
|set\_focus\_action\(\)|void|uint32|Sets the value of focus\_action. After calling this, focus\_action\(\) will return value.|
|clear\_focus\_action\(\)|void|void|Clears the value of focus\_action. After calling this, focus\_action\(\) will return the empty string/empty bytes.|
|has\_focus\_point\(\) const|void|void|Returns the current value of the field if oneof case is kFocus\_point. Otherwise, returns oneof:action\_parameters [FocusPoint](FocusPoint.md#)::default\_instance\(\)|
|focus\_point\(\) const|const oneof:action\_parameters [FocusPoint](FocusPoint.md#)&|void|Returns the current value of the field if oneof case is kFocus\_point|
|mutable\_focus\_point\(\)|oneof:action\_parameters [FocusPoint](FocusPoint.md#)\*|void|If any other oneof field in the same oneof is set, calls clear\_action\_parameters\(\). Sets the oneof case to kFocus\_point and returns a pointer to the mutable oneof:action\_parameters [FocusPoint](FocusPoint.md#) object that stores the field's value. If the oneof case was not kFocus\_point prior to the call, then the returned oneof:action\_parameters [FocusPoint](FocusPoint.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated oneof:action\_parameters [FocusPoint](FocusPoint.md#)\). After calling this, has\_focus\_point\(\) will return true, focus\_point\(\) will return a reference to the same instance of oneof:action\_parameters [FocusPoint](FocusPoint.md#) and action\_parameters\_case\(\) will return kFocus\_point|
|clear\_focus\_point\(\)|void|void|Nothing will be changed if the oneof case is not kFocus\_point. If the oneof case equals kFocus\_point, frees the field and clears the oneof case. has\_focus\_point\(\) will return false, focus\_point\(\) will return the default value and action\_parameters\_case\(\) will return ACTION\_PARAMETERS\_NOT\_SET.|
|set\_allocated\_focus\_point\(\)|void|oneof:action\_parameters [FocusPoint](FocusPoint.md#)\*|Calls clear\_action\_parameters\(\). If the oneof:action\_parameters [FocusPoint](FocusPoint.md#) pointer is not NULL: Sets the oneof:action\_parameters [FocusPoint](FocusPoint.md#) object to the field and sets the oneof case to kFocus\_point. The message takes ownership of the allocated oneof:action\_parameters [FocusPoint](FocusPoint.md#) object, has\_focus\_point\(\) will return true and action\_parameters\_case\(\) will return kFocus\_point. If the pointer is NULL, has\_focus\_point\(\) will return false and action\_parameters\_case\(\) will return ACTION\_PARAMETERS\_NOT\_SET. \(The behavior is like calling clear\_action\_parameters\(\)\)|
|release\_focus\_point\(\)|oneof:action\_parameters [FocusPoint](FocusPoint.md#)\*|void|Returns NULL if oneof case is not kFocus\_point. If the oneof case is kFocus\_point, clears the oneof case, releases the ownership of the field and returns the pointer of the action\_parameters object. After calling this, caller takes the ownership of the allocated action\_parameters object, has\_focus\_point\(\) will return false, focus\_point\(\) will return the default value and action\_parameters\_case\(\) will return ACTION\_PARAMETERS\_NOT\_SET.|
|has\_manual\_focus\(\) const|void|void|Returns the current value of the field if oneof case is kManual\_focus. Otherwise, returns oneof:action\_parameters [ManualFocus](ManualFocus.md#)::default\_instance\(\)|
|manual\_focus\(\) const|const oneof:action\_parameters [ManualFocus](ManualFocus.md#)&|void|Returns the current value of the field if oneof case is kManual\_focus|
|mutable\_manual\_focus\(\)|oneof:action\_parameters [ManualFocus](ManualFocus.md#)\*|void|If any other oneof field in the same oneof is set, calls clear\_action\_parameters\(\). Sets the oneof case to kManual\_focus and returns a pointer to the mutable oneof:action\_parameters [ManualFocus](ManualFocus.md#) object that stores the field's value. If the oneof case was not kManual\_focus prior to the call, then the returned oneof:action\_parameters [ManualFocus](ManualFocus.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated oneof:action\_parameters [ManualFocus](ManualFocus.md#)\). After calling this, has\_manual\_focus\(\) will return true, manual\_focus\(\) will return a reference to the same instance of oneof:action\_parameters [ManualFocus](ManualFocus.md#) and action\_parameters\_case\(\) will return kManual\_focus|
|clear\_manual\_focus\(\)|void|void|Nothing will be changed if the oneof case is not kManual\_focus. If the oneof case equals kManual\_focus, frees the field and clears the oneof case. has\_manual\_focus\(\) will return false, manual\_focus\(\) will return the default value and action\_parameters\_case\(\) will return ACTION\_PARAMETERS\_NOT\_SET.|
|set\_allocated\_manual\_focus\(\)|void|oneof:action\_parameters [ManualFocus](ManualFocus.md#)\*|Calls clear\_action\_parameters\(\). If the oneof:action\_parameters [ManualFocus](ManualFocus.md#) pointer is not NULL: Sets the oneof:action\_parameters [ManualFocus](ManualFocus.md#) object to the field and sets the oneof case to kManual\_focus. The message takes ownership of the allocated oneof:action\_parameters [ManualFocus](ManualFocus.md#) object, has\_manual\_focus\(\) will return true and action\_parameters\_case\(\) will return kManual\_focus. If the pointer is NULL, has\_manual\_focus\(\) will return false and action\_parameters\_case\(\) will return ACTION\_PARAMETERS\_NOT\_SET. \(The behavior is like calling clear\_action\_parameters\(\)\)|
|release\_manual\_focus\(\)|oneof:action\_parameters [ManualFocus](ManualFocus.md#)\*|void|Returns NULL if oneof case is not kManual\_focus. If the oneof case is kManual\_focus, clears the oneof case, releases the ownership of the field and returns the pointer of the action\_parameters object. After calling this, caller takes the ownership of the allocated action\_parameters object, has\_manual\_focus\(\) will return false, manual\_focus\(\) will return the default value and action\_parameters\_case\(\) will return ACTION\_PARAMETERS\_NOT\_SET.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

