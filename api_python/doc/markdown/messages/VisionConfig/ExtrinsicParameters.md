# class ExtrinsicParameters

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|rotation| [RotationMatrix](RotationMatrix.md#)|The rotation matrix from depth sensor reference frame to color sensor reference frame|To set rotation, you simply assign a value directly to a field within rotation. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|translation| [TranslationVector](TranslationVector.md#)|The translation vector from depth sensor reference frame to color sensor reference frame|To set translation, you simply assign a value directly to a field within translation. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [VisionConfig \(Python\)](../../summary_pages/VisionConfig.md)

