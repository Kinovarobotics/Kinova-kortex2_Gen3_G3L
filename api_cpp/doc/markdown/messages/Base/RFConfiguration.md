# class RFConfiguration

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|wifi\_enable\_state| [WifiEnableState](WifiEnableState.md#)| |
|bluetooth\_enable\_state| [BluetoothEnableState](BluetoothEnableState.md#)| |

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_wifi\_enable\_state\(\) const|bool|void|Returns true if wifi\_enable\_state is set.|
|wifi\_enable\_state\(\)|const [WifiEnableState](WifiEnableState.md#)&|void|Returns the current value of wifi\_enable\_state. If wifi\_enable\_state is not set, returns a [WifiEnableState](WifiEnableState.md#) with none of its fields set \(possibly wifi\_enable\_state::default\_instance\(\)\).|
|mutable\_wifi\_enable\_state\(\)| [WifiEnableState](WifiEnableState.md#) \*|void|Returns a pointer to the mutable [WifiEnableState](WifiEnableState.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [WifiEnableState](WifiEnableState.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [WifiEnableState](WifiEnableState.md#)\). After calling this, has\_wifi\_enable\_state\(\) will return true and wifi\_enable\_state\(\) will return a reference to the same instance of [WifiEnableState](WifiEnableState.md#).|
|clear\_wifi\_enable\_state\(\)|void|void|Clears the value of the field. After calling this, has\_wifi\_enable\_state\(\) will return false and wifi\_enable\_state\(\) will return the default value.|
|set\_allocated\_wifi\_enable\_state\(\)|void| [WifiEnableState](WifiEnableState.md#) \*|Sets the [WifiEnableState](WifiEnableState.md#) object to the field and frees the previous field value if it exists. If the [WifiEnableState](WifiEnableState.md#) pointer is not NULL, the message takes ownership of the allocated [WifiEnableState](WifiEnableState.md#) object and has\_ [WifiEnableState](WifiEnableState.md#)\(\) will return true. Otherwise, if the wifi\_enable\_state is NULL, the behavior is the same as calling clear\_wifi\_enable\_state\(\).|
|release\_wifi\_enable\_state\(\)| [WifiEnableState](WifiEnableState.md#) \*|void|Releases the ownership of the field and returns the pointer of the [WifiEnableState](WifiEnableState.md#) object. After calling this, caller takes the ownership of the allocated [WifiEnableState](WifiEnableState.md#) object, has\_wifi\_enable\_state\(\) will return false, and wifi\_enable\_state\(\) will return the default value.|
|has\_bluetooth\_enable\_state\(\) const|bool|void|Returns true if bluetooth\_enable\_state is set.|
|bluetooth\_enable\_state\(\)|const [BluetoothEnableState](BluetoothEnableState.md#)&|void|Returns the current value of bluetooth\_enable\_state. If bluetooth\_enable\_state is not set, returns a [BluetoothEnableState](BluetoothEnableState.md#) with none of its fields set \(possibly bluetooth\_enable\_state::default\_instance\(\)\).|
|mutable\_bluetooth\_enable\_state\(\)| [BluetoothEnableState](BluetoothEnableState.md#) \*|void|Returns a pointer to the mutable [BluetoothEnableState](BluetoothEnableState.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [BluetoothEnableState](BluetoothEnableState.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [BluetoothEnableState](BluetoothEnableState.md#)\). After calling this, has\_bluetooth\_enable\_state\(\) will return true and bluetooth\_enable\_state\(\) will return a reference to the same instance of [BluetoothEnableState](BluetoothEnableState.md#).|
|clear\_bluetooth\_enable\_state\(\)|void|void|Clears the value of the field. After calling this, has\_bluetooth\_enable\_state\(\) will return false and bluetooth\_enable\_state\(\) will return the default value.|
|set\_allocated\_bluetooth\_enable\_state\(\)|void| [BluetoothEnableState](BluetoothEnableState.md#) \*|Sets the [BluetoothEnableState](BluetoothEnableState.md#) object to the field and frees the previous field value if it exists. If the [BluetoothEnableState](BluetoothEnableState.md#) pointer is not NULL, the message takes ownership of the allocated [BluetoothEnableState](BluetoothEnableState.md#) object and has\_ [BluetoothEnableState](BluetoothEnableState.md#)\(\) will return true. Otherwise, if the bluetooth\_enable\_state is NULL, the behavior is the same as calling clear\_bluetooth\_enable\_state\(\).|
|release\_bluetooth\_enable\_state\(\)| [BluetoothEnableState](BluetoothEnableState.md#) \*|void|Releases the ownership of the field and returns the pointer of the [BluetoothEnableState](BluetoothEnableState.md#) object. After calling this, caller takes the ownership of the allocated [BluetoothEnableState](BluetoothEnableState.md#) object, has\_bluetooth\_enable\_state\(\) will return false, and bluetooth\_enable\_state\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

