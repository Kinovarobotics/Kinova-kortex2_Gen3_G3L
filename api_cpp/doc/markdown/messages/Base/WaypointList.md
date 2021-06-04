# class WaypointList

 **Member values** 

|Member name|Data type|Description|
|-----------|---------|-----------|
|waypoints| [Waypoint](Waypoint.md#)|Array of waypoints|
|duration|float32|Duration of the waypoint list \(in seconds\). If unspecified or equal to 0, optimal duration is assumed.|
|use\_optimal\_blending|bool|At validation if this value is true, the waypoint list with optimal blending will be returned.|

 **Member functions** 

|Function name|Return type|Input type|Description|
|-------------|-----------|----------|-----------|
|waypoints\_size\(\) const|int|void|Returns the number of elements currently in the field.|
|waypoints\(\) const|const [Waypoint](Waypoint.md#)|int index|Returns the element at the given zero-based index. Calling this method with index outside of \[0, waypoints\_size\(\)\) yields undefined behavior.|
|mutable\_waypoints\(\)| [Waypoint](Waypoint.md#)\*|int index|Returns a pointer to the mutable [Waypoint](Waypoint.md#) object that stores the value of the element at the given zero-based index. Calling this method with index outside of \[0, waypoints\_size\(\)\) yields undefined behavior.|
|add\_waypoints\(\)| [Waypoint](Waypoint.md#)\*|void|Adds a new element and returns a pointer to it. The returned [Waypoint](Waypoint.md#) is mutable and will have none of its fields set \(i.e. it will be identical to a newly-allocated [Waypoint](Waypoint.md#)\).|
|clear\_waypoints\(\)|void|void|Removes all elements from the field. After calling this, waypoints\_size\(\) will return zero.|
|waypoints\(\) const|const RepeatedPtrField< [Waypoint](Waypoint.md#)\>&|void|Returns the underlying RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|mutable\_waypoints\(\)|RepeatedPtrField< [Waypoint](Waypoint.md#)\>\*|void|Returns a pointer to the underlying mutable RepeatedPtrField that stores the field's elements. This container class provides STL-like iterators and other methods.|
|duration\(\)|float32|void|Returns the current value of duration. If the duration is not set, returns 0.|
|set\_duration\(\)|void|float32|Sets the value of duration. After calling this, duration\(\) will return value.|
|clear\_duration\(\)|void|void|Clears the value of duration. After calling this, duration\(\) will return 0.|
|use\_optimal\_blending\(\)|bool|void|Returns the current value of use\_optimal\_blending. If the use\_optimal\_blending is not set, returns 0.|
|set\_use\_optimal\_blending\(\)|void|bool|Sets the value of use\_optimal\_blending. After calling this, use\_optimal\_blending\(\) will return value.|
|clear\_use\_optimal\_blending\(\)|void|void|Clears the value of use\_optimal\_blending. After calling this, use\_optimal\_blending\(\) will return 0.|

**Parent topic:** [Base \(C++\)](../../summary_pages/Base.md)

