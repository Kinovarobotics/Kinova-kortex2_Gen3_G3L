# class WaypointValidationReport

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|trajectory\_error\_report| [TrajectoryErrorReport](TrajectoryErrorReport.md#)|Report on the validation, the waypoint list is valid if empty|
|optimal\_waypoint\_list| [WaypointList](WaypointList.md#)|Validated Waypoint List with optimal blending radius if the option was set|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|has\_trajectory\_error\_report\(\) const|bool|void|Returns true if trajectory\_error\_report is set.|
|trajectory\_error\_report\(\)|const [TrajectoryErrorReport](TrajectoryErrorReport.md#)&|void|Returns the current value of trajectory\_error\_report. If trajectory\_error\_report is not set, returns a [TrajectoryErrorReport](TrajectoryErrorReport.md#) with none of its fields set \(possibly trajectory\_error\_report::default\_instance\(\)\).|
|mutable\_trajectory\_error\_report\(\)| [TrajectoryErrorReport](TrajectoryErrorReport.md#) \*|void|Returns a pointer to the mutable [TrajectoryErrorReport](TrajectoryErrorReport.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [TrajectoryErrorReport](TrajectoryErrorReport.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [TrajectoryErrorReport](TrajectoryErrorReport.md#)\). After calling this, has\_trajectory\_error\_report\(\) will return true and trajectory\_error\_report\(\) will return a reference to the same instance of [TrajectoryErrorReport](TrajectoryErrorReport.md#).|
|clear\_trajectory\_error\_report\(\)|void|void|Clears the value of the field. After calling this, has\_trajectory\_error\_report\(\) will return false and trajectory\_error\_report\(\) will return the default value.|
|set\_allocated\_trajectory\_error\_report\(\)|void| [TrajectoryErrorReport](TrajectoryErrorReport.md#) \*|Sets the [TrajectoryErrorReport](TrajectoryErrorReport.md#) object to the field and frees the previous field value if it exists. If the [TrajectoryErrorReport](TrajectoryErrorReport.md#) pointer is not NULL, the message takes ownership of the allocated [TrajectoryErrorReport](TrajectoryErrorReport.md#) object and has\_ [TrajectoryErrorReport](TrajectoryErrorReport.md#)\(\) will return true. Otherwise, if the trajectory\_error\_report is NULL, the behavior is the same as calling clear\_trajectory\_error\_report\(\).|
|release\_trajectory\_error\_report\(\)| [TrajectoryErrorReport](TrajectoryErrorReport.md#) \*|void|Releases the ownership of the field and returns the pointer of the [TrajectoryErrorReport](TrajectoryErrorReport.md#) object. After calling this, caller takes the ownership of the allocated [TrajectoryErrorReport](TrajectoryErrorReport.md#) object, has\_trajectory\_error\_report\(\) will return false, and trajectory\_error\_report\(\) will return the default value.|
|has\_optimal\_waypoint\_list\(\) const|bool|void|Returns true if optimal\_waypoint\_list is set.|
|optimal\_waypoint\_list\(\)|const [WaypointList](WaypointList.md#)&|void|Returns the current value of optimal\_waypoint\_list. If optimal\_waypoint\_list is not set, returns a [WaypointList](WaypointList.md#) with none of its fields set \(possibly optimal\_waypoint\_list::default\_instance\(\)\).|
|mutable\_optimal\_waypoint\_list\(\)| [WaypointList](WaypointList.md#) \*|void|Returns a pointer to the mutable [WaypointList](WaypointList.md#) object that stores the field's value. If the field was not set prior to the call, then the returned [WaypointList](WaypointList.md#) will have none of its fields set \(i.e. it will be identical to a newly-allocated [WaypointList](WaypointList.md#)\). After calling this, has\_optimal\_waypoint\_list\(\) will return true and optimal\_waypoint\_list\(\) will return a reference to the same instance of [WaypointList](WaypointList.md#).|
|clear\_optimal\_waypoint\_list\(\)|void|void|Clears the value of the field. After calling this, has\_optimal\_waypoint\_list\(\) will return false and optimal\_waypoint\_list\(\) will return the default value.|
|set\_allocated\_optimal\_waypoint\_list\(\)|void| [WaypointList](WaypointList.md#) \*|Sets the [WaypointList](WaypointList.md#) object to the field and frees the previous field value if it exists. If the [WaypointList](WaypointList.md#) pointer is not NULL, the message takes ownership of the allocated [WaypointList](WaypointList.md#) object and has\_ [WaypointList](WaypointList.md#)\(\) will return true. Otherwise, if the optimal\_waypoint\_list is NULL, the behavior is the same as calling clear\_optimal\_waypoint\_list\(\).|
|release\_optimal\_waypoint\_list\(\)| [WaypointList](WaypointList.md#) \*|void|Releases the ownership of the field and returns the pointer of the [WaypointList](WaypointList.md#) object. After calling this, caller takes the ownership of the allocated [WaypointList](WaypointList.md#) object, has\_optimal\_waypoint\_list\(\) will return false, and optimal\_waypoint\_list\(\) will return the default value.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

