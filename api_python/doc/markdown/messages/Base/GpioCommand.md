# class GpioCommand

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|port\_identifier|int|Gpio port identifier \(0 == base expansion port\)|You can manipulate the field port\_identifier as if it were a regular field. To clear the value of port\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|pin\_identifier|int|Gpio pin identifier|You can manipulate the field pin\_identifier as if it were a regular field. To clear the value of pin\_identifier and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|action|int|Action to perform on gpio|You can manipulate the field action as if it were a regular field. To clear the value of action and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|period|int|Period, in ms, of GPIO action \(applicable only for pulse commands\)|You can manipulate the field period as if it were a regular field. To clear the value of period and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

