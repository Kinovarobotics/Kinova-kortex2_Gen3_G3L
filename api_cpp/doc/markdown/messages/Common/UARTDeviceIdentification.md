# class UARTDeviceIdentification

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|port\_id|uint32|UART device port id|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|port\_id\(\)|uint32|void|Returns the current value of port\_id. If the port\_id is not set, returns 0.|
|set\_port\_id\(\)|void|uint32|Sets the value of port\_id. After calling this, port\_id\(\) will return value.|
|clear\_port\_id\(\)|void|void|Clears the value of port\_id. After calling this, port\_id\(\) will return 0.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

