# Message FrequencyResponse

This page describes the C++ Kinova::Api::ActuatorConfig::FrequencyResponse message.

## Overview / Purpose

Defines frequency response

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|loop\_selection| [ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|ControlLoopSelection enum|
|min\_frequency|float32|Minimum frequency value|
|max\_frequency|float32|Maximum frequency value|
|amplitude|float32|Amplitude value|
|duration|float32|Duration \(in seconds\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|loop\_selection\(\) const| [ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|void|Returns the current value of loop\_selection. If the loop\_selection is not set, returns 0.|
|set\_loop\_selection\(\)|void| [ControlLoopSelection](enm_ActuatorConfig_ControlLoopSelection.md#)|Sets the value of loop\_selection. After calling this, loop\_selection\(\) will return value.|
|clear\_loop\_selection\(\)|void|void|Clears the value of loop\_selection. After calling this, loop\_selection\(\) will return the empty string/empty bytes.|
|min\_frequency\(\)|float32|void|Returns the current value of min\_frequency. If the min\_frequency is not set, returns 0.|
|set\_min\_frequency\(\)|void|float32|Sets the value of min\_frequency. After calling this, min\_frequency\(\) will return value.|
|clear\_min\_frequency\(\)|void|void|Clears the value of min\_frequency. After calling this, min\_frequency\(\) will return 0.|
|max\_frequency\(\)|float32|void|Returns the current value of max\_frequency. If the max\_frequency is not set, returns 0.|
|set\_max\_frequency\(\)|void|float32|Sets the value of max\_frequency. After calling this, max\_frequency\(\) will return value.|
|clear\_max\_frequency\(\)|void|void|Clears the value of max\_frequency. After calling this, max\_frequency\(\) will return 0.|
|amplitude\(\)|float32|void|Returns the current value of amplitude. If the amplitude is not set, returns 0.|
|set\_amplitude\(\)|void|float32|Sets the value of amplitude. After calling this, amplitude\(\) will return value.|
|clear\_amplitude\(\)|void|void|Clears the value of amplitude. After calling this, amplitude\(\) will return 0.|
|duration\(\)|float32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|float32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|

**Parent topic:** [ActuatorConfig](../references/summary_ActuatorConfig.md)

