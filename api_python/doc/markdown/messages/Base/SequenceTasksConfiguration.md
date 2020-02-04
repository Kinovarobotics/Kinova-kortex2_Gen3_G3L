# class SequenceTasksConfiguration

 **Member values** 

|Member name|Data type|Description|Usage|
|-----------|---------|-----------|-----|
|sequence\_task\_handle| [SequenceTaskHandle](SequenceTaskHandle.md#)|Sequence Handle and task index as the insertion point|To set sequence\_task\_handle, you simply assign a value directly to a field within sequence\_task\_handle. You can also use the parent message's HasField\(\) method to check if a message type field value has been set.|
|sequence\_tasks| [SequenceTask](SequenceTask.md#)|Tasks to be inserted|Repeated message fields are represented as an object that acts like a Python sequence. However, You must use add\(\) instead of append\(\). It also has an extend\(\) function that appends an entire list of messages, but makes a copy of every message in the list.|

**Parent topic:** [Base \(Python\)](../../summary_pages/Base.md)

