# class SystemTime

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|sec|int|Seconds after the minute\(0-59\)|You can manipulate the field sec as if it were a regular field. To clear the value of sec and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|min|int|Minutes after the hour \(0-59\)|You can manipulate the field min as if it were a regular field. To clear the value of min and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|hour|int|Hours since midnight \(0-23\)|You can manipulate the field hour as if it were a regular field. To clear the value of hour and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|mday|int|Day of the month \(1-31\)|You can manipulate the field mday as if it were a regular field. To clear the value of mday and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|mon|int|Months since January \(0-11\)|You can manipulate the field mon as if it were a regular field. To clear the value of mon and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|year|int|Years since 1900|You can manipulate the field year as if it were a regular field. To clear the value of year and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

