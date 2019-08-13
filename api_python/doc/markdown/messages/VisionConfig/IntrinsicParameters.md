# class IntrinsicParameters

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|sensor|int|The sensor for which the parameters apply to|You can manipulate the field sensor as if it were a regular field. To clear the value of sensor and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|resolution|int|The resolution for which the parameters apply to|You can manipulate the field resolution as if it were a regular field. To clear the value of resolution and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|principal\_point\_x|float|Horizontal coordinate of the principal point of the image, as a pixel offset from the left edge|You can manipulate the field principal\_point\_x as if it were a regular field. To clear the value of principal\_point\_x and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|principal\_point\_y|float|Vertical coordinate of the principal point of the image, as a pixel offset from the top edge|You can manipulate the field principal\_point\_y as if it were a regular field. To clear the value of principal\_point\_y and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|focal\_length\_x|float|Focal length of the image plane, as a multiple of pixel width|You can manipulate the field focal\_length\_x as if it were a regular field. To clear the value of focal\_length\_x and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|focal\_length\_y|float|Focal length of the image plane, as a multiple of pixel height|You can manipulate the field focal\_length\_y as if it were a regular field. To clear the value of focal\_length\_y and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|distortion\_coeffs| [DistortionCoefficients](DistortionCoefficients.md#)|Distortion coefficients|To set distortion\_coeffs, you simply assign a value directly to a field within distortion\_coeffs. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|

**Parent topic:** [VisionConfig \(Python\)](../../summary_pages/VisionConfig.md)

