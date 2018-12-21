# Message Timestamp

This page describes the C++ Kinova::Api::Common::Timestamp message.

## Overview / Purpose

Timestamp based on Epoch \(00:00:00 Thursday, January 1, 1970\)

## Class members

 **Member variables** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sec|uint32|Number of seconds that have elapsed since Epoch|
|usec|uint32|Number of microseconds that have elapsed since the last second \(0-999999\)|

 **Methods** 

The methods listed below are some of the most commonly used. Please refer to Google Protocol Buffer documentation for an exhaustive list.

|Method name|Return type|Input type|Description|
|-----------|-----------|----------|-----------|
|sec\(\)|uint32|void|Returns the current value of sec. If the sec is not set, returns 0.|
|set\_sec\(\)|void|uint32|Sets the value of sec. After calling this, sec\(\) will return value.|
|clear\_sec\(\)|void|void|Clears the value of sec. After calling this, sec\(\) will return 0.|
|usec\(\)|uint32|void|Returns the current value of usec. If the usec is not set, returns 0.|
|set\_usec\(\)|void|uint32|Sets the value of usec. After calling this, usec\(\) will return value.|
|clear\_usec\(\)|void|void|Clears the value of usec. After calling this, usec\(\) will return 0.|

**Parent topic:** [Common](../references/summary_Common.md)

