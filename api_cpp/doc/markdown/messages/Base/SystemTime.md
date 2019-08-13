# class SystemTime

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|sec|uint32|Seconds after the minute\(0-59\)|
|min|uint32|Minutes after the hour \(0-59\)|
|hour|uint32|Hours since midnight \(0-23\)|
|mday|uint32|Day of the month \(1-31\)|
|mon|uint32|Months since January \(0-11\)|
|year|uint32|Years since 1900|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|sec\(\)|uint32|void|Returns the current value of sec. If the sec is not set, returns 0.|
|set\_sec\(\)|void|uint32|Sets the value of sec. After calling this, sec\(\) will return value.|
|clear\_sec\(\)|void|void|Clears the value of sec. After calling this, sec\(\) will return 0.|
|min\(\)|uint32|void|Returns the current value of min. If the min is not set, returns 0.|
|set\_min\(\)|void|uint32|Sets the value of min. After calling this, min\(\) will return value.|
|clear\_min\(\)|void|void|Clears the value of min. After calling this, min\(\) will return 0.|
|hour\(\)|uint32|void|Returns the current value of hour. If the hour is not set, returns 0.|
|set\_hour\(\)|void|uint32|Sets the value of hour. After calling this, hour\(\) will return value.|
|clear\_hour\(\)|void|void|Clears the value of hour. After calling this, hour\(\) will return 0.|
|mday\(\)|uint32|void|Returns the current value of mday. If the mday is not set, returns 0.|
|set\_mday\(\)|void|uint32|Sets the value of mday. After calling this, mday\(\) will return value.|
|clear\_mday\(\)|void|void|Clears the value of mday. After calling this, mday\(\) will return 0.|
|mon\(\)|uint32|void|Returns the current value of mon. If the mon is not set, returns 0.|
|set\_mon\(\)|void|uint32|Sets the value of mon. After calling this, mon\(\) will return value.|
|clear\_mon\(\)|void|void|Clears the value of mon. After calling this, mon\(\) will return 0.|
|year\(\)|uint32|void|Returns the current value of year. If the year is not set, returns 0.|
|set\_year\(\)|void|uint32|Sets the value of year. After calling this, year\(\) will return value.|
|clear\_year\(\)|void|void|Clears the value of year. After calling this, year\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

