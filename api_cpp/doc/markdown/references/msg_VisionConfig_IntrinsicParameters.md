# Message IntrinsicParameters

This page describes the C++ Kinova::Api::VisionConfig::IntrinsicParameters message.

## Overview / Purpose

Sensor intrinsic parameters

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|width|uint32|Width of the image in pixels|
|height|uint32|Height of the image in pixels|
|principal\_point\_x|float32|Horizontal coordinate of the principal point of the image, as a pixel offset from the left edge|
|principal\_point\_y|float32|Vertical coordinate of the principal point of the image, as a pixel offset from the top edge|
|focal\_length\_x|float32|Focal length of the image plane, as a multiple of pixel width|
|focal\_length\_y|float32|Focal length of the image plane, as a multiple of pixel height|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protobuf documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|width\(\)|uint32|void|Returns the current value of width. If the width is not set, returns 0.|
|set\_width\(\)|void|uint32|Sets the value of width. After calling this, width\(\) will return value.|
|clear\_width\(\)|void|void|Clears the value of width. After calling this, width\(\) will return 0.|
|height\(\)|uint32|void|Returns the current value of height. If the height is not set, returns 0.|
|set\_height\(\)|void|uint32|Sets the value of height. After calling this, height\(\) will return value.|
|clear\_height\(\)|void|void|Clears the value of height. After calling this, height\(\) will return 0.|
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

**Parent topic:** [VisionConfig](../references/summary_VisionConfig.md)

