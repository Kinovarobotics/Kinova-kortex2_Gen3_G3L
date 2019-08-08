# class PreComputedJointTrajectory

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|mode|int|Trajectory continuity mode|You can manipulate the field mode as if it were a regular field. To clear the value of mode and reset it to the default value for its type, you call the ClearField\(\) method of the Message interface.|
|trajectory\_elements| [PreComputedJointTrajectoryElement](PreComputedJointTrajectoryElement.md#)|List of pre-computed elements composing the trajectory.|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

