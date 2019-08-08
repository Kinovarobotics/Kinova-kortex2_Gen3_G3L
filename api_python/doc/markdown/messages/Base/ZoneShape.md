# class ZoneShape

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|shape\_type|int|Shape type|You can manipulate the field shape\_type as if it were a regular field. To clear the value of shape\_type and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|origin| [Point](Point.md#)|Origin of the protection zone shape from reference \(in meters\)|To set origin, you simply assign a value directly to a field within origin. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|orientation| [RotationMatrix](RotationMatrix.md#)|Rotation matrix to provide shape orientation|To set orientation, you simply assign a value directly to a field within orientation. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|dimensions|float|Shape size measurement \(in meters\). If rectangular prism: x, y and z dimensions. If cylinder: radius and height. If sphere: radius|You can manipulate the field dimensions as if it were a regular field. To clear the value of dimensions and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|envelope\_thickness|float|Thickness of envelop around shape \(in meters\). The envelop is of same shape type as the shape at its center.|You can manipulate the field envelope\_thickness as if it were a regular field. To clear the value of envelope\_thickness and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

