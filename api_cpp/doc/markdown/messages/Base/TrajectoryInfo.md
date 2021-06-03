# class TrajectoryInfo

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|trajectory\_info\_type|uint32|Trajectory information type|
|waypoint\_index|uint32|Waypoint index \(if applicable\)|
|joint\_index|uint32|Joint index \(if applicable\)|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|trajectory\_info\_type\(\) const|uint32|void|Returns the current value of trajectory\_info\_type. If the trajectory\_info\_type is not set, returns 0.|
|set\_trajectory\_info\_type\(\)|void|uint32|Sets the value of trajectory\_info\_type. After calling this, trajectory\_info\_type\(\) will return value.|
|clear\_trajectory\_info\_type\(\)|void|void|Clears the value of trajectory\_info\_type. After calling this, trajectory\_info\_type\(\) will return the empty string/empty bytes.|
|waypoint\_index\(\)|uint32|void|Returns the current value of waypoint\_index. If the waypoint\_index is not set, returns 0.|
|set\_waypoint\_index\(\)|void|uint32|Sets the value of waypoint\_index. After calling this, waypoint\_index\(\) will return value.|
|clear\_waypoint\_index\(\)|void|void|Clears the value of waypoint\_index. After calling this, waypoint\_index\(\) will return 0.|
|joint\_index\(\)|uint32|void|Returns the current value of joint\_index. If the joint\_index is not set, returns 0.|
|set\_joint\_index\(\)|void|uint32|Sets the value of joint\_index. After calling this, joint\_index\(\) will return value.|
|clear\_joint\_index\(\)|void|void|Clears the value of joint\_index. After calling this, joint\_index\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

