# class UARTConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|port\_id|uint32|UART port identification|
|enabled|bool|True if UART device is enabled, false otherwise|
|speed|uint32|Speed selection|
|word\_length|uint32|Word length|
|stop\_bits|uint32|Stop bits|
|parity|uint32|Parity mode|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|port\_id\(\)|uint32|void|Returns the current value of port\_id. If the port\_id is not set, returns 0.|
|set\_port\_id\(\)|void|uint32|Sets the value of port\_id. After calling this, port\_id\(\) will return value.|
|clear\_port\_id\(\)|void|void|Clears the value of port\_id. After calling this, port\_id\(\) will return 0.|
|enabled\(\)|bool|void|Returns the current value of enabled. If the enabled is not set, returns 0.|
|set\_enabled\(\)|void|bool|Sets the value of enabled. After calling this, enabled\(\) will return value.|
|clear\_enabled\(\)|void|void|Clears the value of enabled. After calling this, enabled\(\) will return 0.|
|speed\(\) const|uint32|void|Returns the current value of speed. If the speed is not set, returns 0.|
|set\_speed\(\)|void|uint32|Sets the value of speed. After calling this, speed\(\) will return value.|
|clear\_speed\(\)|void|void|Clears the value of speed. After calling this, speed\(\) will return the empty string/empty bytes.|
|word\_length\(\) const|uint32|void|Returns the current value of word\_length. If the word\_length is not set, returns 0.|
|set\_word\_length\(\)|void|uint32|Sets the value of word\_length. After calling this, word\_length\(\) will return value.|
|clear\_word\_length\(\)|void|void|Clears the value of word\_length. After calling this, word\_length\(\) will return the empty string/empty bytes.|
|stop\_bits\(\) const|uint32|void|Returns the current value of stop\_bits. If the stop\_bits is not set, returns 0.|
|set\_stop\_bits\(\)|void|uint32|Sets the value of stop\_bits. After calling this, stop\_bits\(\) will return value.|
|clear\_stop\_bits\(\)|void|void|Clears the value of stop\_bits. After calling this, stop\_bits\(\) will return the empty string/empty bytes.|
|parity\(\) const|uint32|void|Returns the current value of parity. If the parity is not set, returns 0.|
|set\_parity\(\)|void|uint32|Sets the value of parity. After calling this, parity\(\) will return value.|
|clear\_parity\(\)|void|void|Clears the value of parity. After calling this, parity\(\) will return the empty string/empty bytes.|

**Parent topic:** [Common \(C++\)](../../summary_pages/Common.md)

