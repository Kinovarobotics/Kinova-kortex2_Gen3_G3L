# class IntrinsicParameters

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sensor|uint32|The sensor for which the parameters apply to|
|resolution|uint32|The resolution for which the parameters apply to|
|principal\_point\_x|float32|Horizontal coordinate of the principal point of the image, as a pixel offset from the left edge|
|principal\_point\_y|float32|Vertical coordinate of the principal point of the image, as a pixel offset from the top edge|
|focal\_length\_x|float32|Focal length of the image plane, as a multiple of pixel width|
|focal\_length\_y|float32|Focal length of the image plane, as a multiple of pixel height|
|distortion\_coeffs| [DistortionCoefficients](DistortionCoefficients.md#)|Distortion coefficients|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sensor\(\) const|uint32|void|Returns the current value of sensor. If the sensor is not set, returns 0.|
|set\_sensor\(\)|void|uint32|Sets the value of sensor. After calling this, sensor\(\) will return value.|
|clear\_sensor\(\)|void|void|Clears the value of sensor. After calling this, sensor\(\) will return the empty string/empty bytes.|
|resolution\(\) const|uint32|void|Returns the current value of resolution. If the resolution is not set, returns 0.|
|set\_resolution\(\)|void|uint32|Sets the value of resolution. After calling this, resolution\(\) will return value.|
|clear\_resolution\(\)|void|void|Clears the value of resolution. After calling this, resolution\(\) will return the empty string/empty bytes.|
|principal\_point\_x\(\)|float32|void|Returns the current value of principal\_point\_x. If the principal\_point\_x is not set, returns 0.|
|set\_principal\_point\_x\(\)|void|float32|Sets the value of principal\_point\_x. After calling this, principal\_point\_x\(\) will return value.|
|clear\_principal\_point\_x\(\)|void|void|Clears the value of principal\_point\_x. After calling this, principal\_point\_x\(\) will return 0.|
|principal\_point\_y\(\)|float32|void|Returns the current value of principal\_point\_y. If the principal\_point\_y is not set, returns 0.|
|set\_principal\_point\_y\(\)|void|float32|Sets the value of principal\_point\_y. After calling this, principal\_point\_y\(\) will return value.|
|clear\_principal\_point\_y\(\)|void|void|Clears the value of principal\_point\_y. After calling this, principal\_point\_y\(\) will return 0.|
|focal\_length\_x\(\)|float32|void|Returns the current value of focal\_length\_x. If the focal\_length\_x is not set, returns 0.|
|set\_focal\_length\_x\(\)|void|float32|Sets the value of focal\_length\_x. After calling this, focal\_length\_x\(\) will return value.|
|clear\_focal\_length\_x\(\)|void|void|Clears the value of focal\_length\_x. After calling this, focal\_length\_x\(\) will return 0.|
|focal\_length\_y\(\)|float32|void|Returns the current value of focal\_length\_y. If the focal\_length\_y is not set, returns 0.|
|set\_focal\_length\_y\(\)|void|float32|Sets the value of focal\_length\_y. After calling this, focal\_length\_y\(\) will return value.|
|clear\_focal\_length\_y\(\)|void|void|Clears the value of focal\_length\_y. After calling this, focal\_length\_y\(\) will return 0.|
|has\_distortion\_coeffs\(\) const|bool|void|Returns true if distortion\_coeffs is set.|
|distortion\_coeffs\(\)|const [DistortionCoefficients](DistortionCoefficients.md#)&|void|Returns the current value of distortion\_coeffs. If distortion\_coeffs is not set, returns a [DistortionCoefficients](DistortionCoefficients.md#) with none of its fields set \(possibly distortion\_coeffs::default\_instance\(\)\).|
|mutable\_distortion\_coeffs\(\)| [DistortionCoefficients](DistortionCoefficients.md#) \*|void|Returns a pointer to the mutable [DistortionCoefficients](DistortionCoefficients.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [DistortionCoefficients](DistortionCoefficients.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [DistortionCoefficients](DistortionCoefficients.md#)\). After calling this, has\_distortion\_coeffs\(\) will return true and distortion\_coeffs\(\) will return a reference to the same instance of [DistortionCoefficients](DistortionCoefficients.md#).|
|clear\_distortion\_coeffs\(\)|void|void|Clears the value of the field. After calling this, has\_distortion\_coeffs\(\) will return false and distortion\_coeffs\(\) will return the default value.|
|set\_allocated\_distortion\_coeffs\(\)|void| [DistortionCoefficients](DistortionCoefficients.md#) \*|Sets the [DistortionCoefficients](DistortionCoefficients.md#) object to the field and frees the previous field value if it exists. If the [DistortionCoefficients](DistortionCoefficients.md#) pointer is not NULL, the message takes ownership of the allocated [DistortionCoefficients](DistortionCoefficients.md#) object and has\_ [DistortionCoefficients](DistortionCoefficients.md#)\(\) will return true. Otherwise, if the distortion\_coeffs is NULL, the behavior is the same as calling clear\_distortion\_coeffs\(\).|
|release\_distortion\_coeffs\(\)| [DistortionCoefficients](DistortionCoefficients.md#) \*|void|Releases the ownership of the field and returns the pointer of the [DistortionCoefficients](DistortionCoefficients.md#) object. After calling this, caller takes the ownership of the allocated [DistortionCoefficients](DistortionCoefficients.md#) object, has\_distortion\_coeffs\(\) will return false, and distortion\_coeffs\(\) will return the default value.|

**Parent topic:** [VisionConfig \(C++\)](../../summary_pages/VisionConfig.md)

