

# Class OpenOasis::CommImp::Temporal::TimeBuffer



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**CommImp**](namespace_open_oasis_1_1_comm_imp.md) **>** [**Temporal**](namespace_open_oasis_1_1_comm_imp_1_1_temporal.md) **>** [**TimeBuffer**](class_open_oasis_1_1_comm_imp_1_1_temporal_1_1_time_buffer.md)



_The_ [_**TimeBuffer**_](class_open_oasis_1_1_comm_imp_1_1_temporal_1_1_time_buffer.md) _class provides temporal buffering functionality._

* `#include <TimeBuffer.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddValues**](#function-addvalues) (const std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; & time, const std::vector&lt; real &gt; & values) <br>_Adds corresponding values for time and values to the_ [_**TimeBuffer**_](class_open_oasis_1_1_comm_imp_1_1_temporal_1_1_time_buffer.md) _. The AddValues method will internally make a copy of the added times and values. The reason for doing this is that the times and values arguments are reference, and the corresponding values could be changed by the owner of the classes._ |
|  void | [**CheckBuffer**](#function-checkbuffer) () const<br>_Checks weather the contents of the buffer is valid._  |
|  void | [**ClearAfter**](#function-clearafter) (std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; time) <br>_Clears all times and values in the buffer at/or later than the specified time. If the specified time is span, the start time is used._  |
|  void | [**ClearBefore**](#function-clearbefore) (std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; time) <br>_Clears all records in the buffer associated to time that is earlier than the time specified._  |
|  std::vector&lt; std::vector&lt; real &gt; &gt; | [**GetAllValues**](#function-getallvalues) () <br> |
|  bool | [**GetDoExtendedDataVerification**](#function-getdoextendeddataverification) () const<br> |
|  bool | [**GetDoExtrapolate**](#function-getdoextrapolate) () const<br> |
|  real | [**GetRelaxationFactor**](#function-getrelaxationfactor) () const<br> |
|  std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; | [**GetTimeAt**](#function-gettimeat) (int timeStep) const<br> |
|  std::shared\_ptr&lt; TimeSet &gt; | [**GetTimeSet**](#function-gettimeset) () const<br> |
|  int | [**GetTimesCount**](#function-gettimescount) () const<br>_Number of time streps in the buffer._  |
|  std::shared\_ptr&lt; ValueSet2D &gt; | [**GetValueSet**](#function-getvalueset) () const<br> |
|  std::vector&lt; real &gt; | [**GetValues**](#function-getvalues) (const std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; & requestedTime) <br>_Returns the values that corresponds to the requestedTime. The values may be found by interpolation, extrapolation and/or aggregation._  |
|  std::vector&lt; real &gt; | [**GetValuesAt**](#function-getvaluesat) (int timeStep) const<br> |
|  int | [**GetValuesCount**](#function-getvaluescount) () const<br>_The number of values in the valuesets contained in the buffer._  |
|  void | [**Reset**](#function-reset) () <br> |
|  void | [**SetDoExtendedDataVerification**](#function-setdoextendeddataverification) (bool value) <br> |
|  void | [**SetDoExtrapolate**](#function-setdoextrapolate) (bool value) <br> |
|  void | [**SetOrAddValues**](#function-setoraddvalues) (std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; time, std::vector&lt; real &gt; values) <br> |
|  void | [**SetRelaxationFactor**](#function-setrelaxationfactor) (real value) <br> |
|   | [**TimeBuffer**](#function-timebuffer-12) () <br> |
|   | [**TimeBuffer**](#function-timebuffer-22) (const [**TimeBuffer**](class_open_oasis_1_1_comm_imp_1_1_temporal_1_1_time_buffer.md) & TimeBuffer) <br> |
| virtual  | [**~TimeBuffer**](#function-timebuffer) () <br> |








## Protected Attributes

| Type | Name |
| ---: | :--- |
|  bool | [**mDoExtendedDataVerification**](#variable-mdoextendeddataverification)   = = false<br> |
|  bool | [**mDoExtrapolate**](#variable-mdoextrapolate)   = = true<br> |
|  int | [**mLastBufferSizeMessageCounter**](#variable-mlastbuffersizemessagecounter)   = = 0<br> |
|  real | [**mRelaxationFactor**](#variable-mrelaxationfactor)   = = 0<br> |
|  std::shared\_ptr&lt; TimeSet &gt; | [**mTimes**](#variable-mtimes)   = = nullptr<br> |
|  std::shared\_ptr&lt; ValueSet2D &gt; | [**mValues**](#variable-mvalues)   = = nullptr<br> |
















## Protected Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddValuesToBuffer**](#function-addvaluestobuffer) (const std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; & time, const std::vector&lt; real &gt; & values) <br>_Adds values to the buffer, check the time is increasing, not overlapping(spans), and has durations matching the TimeSet._  |
|  void | [**Create**](#function-create) () <br> |
|  std::vector&lt; real &gt; | [**MapFromTimeSpansToTimeSpan**](#function-mapfromtimespanstotimespan) (const std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; & requestedTime) <br>_A ValueSet corresponding to a TimeSpan is calculated using interpolation or extrapolation in corresponding lists of ValueSets and TimeSpans._  |
|  std::vector&lt; real &gt; | [**MapFromTimeSpansToTimeStamp**](#function-mapfromtimespanstotimestamp) (const std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; & requestedTimeStamp) <br>_A ValueSet for a time stamp is calculated using interpolation or extrapolation in corresponding lists of ValueSets and TimeSpans._  |
|  std::vector&lt; real &gt; | [**MapFromTimeStampsToTimeSpan**](#function-mapfromtimestampstotimespan) (const std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; & requestedTime) <br>_A ValueSet corresponding to a TimeSpan is calculated using interpolation or extrapolation in corresponding lists of ValueSets and TimeStamps._  |
|  std::vector&lt; real &gt; | [**MapFromTimeStampsToTimeStamp**](#function-mapfromtimestampstotimestamp) (const std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; & requestedTimeStamp) <br>_A ValueSet corresponding to Time Stamp is calculated using interpolation or extrapolation in corresponding lists of ValueSets and TimeStamps._  |




## Public Functions Documentation




### function AddValues 

_Adds corresponding values for time and values to the_ [_**TimeBuffer**_](class_open_oasis_1_1_comm_imp_1_1_temporal_1_1_time_buffer.md) _. The AddValues method will internally make a copy of the added times and values. The reason for doing this is that the times and values arguments are reference, and the corresponding values could be changed by the owner of the classes._
```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::AddValues (
    const std::shared_ptr< ITime > & time,
    const std::vector< real > & values
) 
```





**Parameters:**


* `time` Description of the time parameter. 
* `valueSet` Description of the values parameter. 




        



### function CheckBuffer 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::CheckBuffer () const
```






### function ClearAfter 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::ClearAfter (
    std::shared_ptr< ITime > time
) 
```






### function ClearBefore 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::ClearBefore (
    std::shared_ptr< ITime > time
) 
```






### function GetAllValues 

```C++
std::vector< std::vector< real > > OpenOasis::CommImp::Temporal::TimeBuffer::GetAllValues () 
```






### function GetDoExtendedDataVerification 

```C++
bool OpenOasis::CommImp::Temporal::TimeBuffer::GetDoExtendedDataVerification () const
```






### function GetDoExtrapolate 

```C++
bool OpenOasis::CommImp::Temporal::TimeBuffer::GetDoExtrapolate () const
```






### function GetRelaxationFactor 

```C++
real OpenOasis::CommImp::Temporal::TimeBuffer::GetRelaxationFactor () const
```






### function GetTimeAt 

```C++
std::shared_ptr< ITime > OpenOasis::CommImp::Temporal::TimeBuffer::GetTimeAt (
    int timeStep
) const
```






### function GetTimeSet 

```C++
std::shared_ptr< TimeSet > OpenOasis::CommImp::Temporal::TimeBuffer::GetTimeSet () const
```






### function GetTimesCount 

```C++
int OpenOasis::CommImp::Temporal::TimeBuffer::GetTimesCount () const
```






### function GetValueSet 

```C++
std::shared_ptr< ValueSet2D > OpenOasis::CommImp::Temporal::TimeBuffer::GetValueSet () const
```






### function GetValues 

```C++
std::vector< real > OpenOasis::CommImp::Temporal::TimeBuffer::GetValues (
    const std::shared_ptr< ITime > & requestedTime
) 
```






### function GetValuesAt 

```C++
std::vector< real > OpenOasis::CommImp::Temporal::TimeBuffer::GetValuesAt (
    int timeStep
) const
```






### function GetValuesCount 

```C++
int OpenOasis::CommImp::Temporal::TimeBuffer::GetValuesCount () const
```






### function Reset 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::Reset () 
```






### function SetDoExtendedDataVerification 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::SetDoExtendedDataVerification (
    bool value
) 
```






### function SetDoExtrapolate 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::SetDoExtrapolate (
    bool value
) 
```






### function SetOrAddValues 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::SetOrAddValues (
    std::shared_ptr< ITime > time,
    std::vector< real > values
) 
```






### function SetRelaxationFactor 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::SetRelaxationFactor (
    real value
) 
```






### function TimeBuffer [1/2]

```C++
OpenOasis::CommImp::Temporal::TimeBuffer::TimeBuffer () 
```






### function TimeBuffer [2/2]

```C++
OpenOasis::CommImp::Temporal::TimeBuffer::TimeBuffer (
    const TimeBuffer & TimeBuffer
) 
```






### function ~TimeBuffer 

```C++
inline virtual OpenOasis::CommImp::Temporal::TimeBuffer::~TimeBuffer () 
```



## Protected Attributes Documentation




### variable mDoExtendedDataVerification 

```C++
bool OpenOasis::CommImp::Temporal::TimeBuffer::mDoExtendedDataVerification;
```






### variable mDoExtrapolate 

```C++
bool OpenOasis::CommImp::Temporal::TimeBuffer::mDoExtrapolate;
```






### variable mLastBufferSizeMessageCounter 

```C++
int OpenOasis::CommImp::Temporal::TimeBuffer::mLastBufferSizeMessageCounter;
```






### variable mRelaxationFactor 

```C++
real OpenOasis::CommImp::Temporal::TimeBuffer::mRelaxationFactor;
```






### variable mTimes 

```C++
std::shared_ptr<TimeSet> OpenOasis::CommImp::Temporal::TimeBuffer::mTimes;
```






### variable mValues 

```C++
std::shared_ptr<ValueSet2D> OpenOasis::CommImp::Temporal::TimeBuffer::mValues;
```



## Protected Functions Documentation




### function AddValuesToBuffer 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::AddValuesToBuffer (
    const std::shared_ptr< ITime > & time,
    const std::vector< real > & values
) 
```






### function Create 

```C++
void OpenOasis::CommImp::Temporal::TimeBuffer::Create () 
```






### function MapFromTimeSpansToTimeSpan 

```C++
std::vector< real > OpenOasis::CommImp::Temporal::TimeBuffer::MapFromTimeSpansToTimeSpan (
    const std::shared_ptr< ITime > & requestedTime
) 
```






### function MapFromTimeSpansToTimeStamp 

```C++
std::vector< real > OpenOasis::CommImp::Temporal::TimeBuffer::MapFromTimeSpansToTimeStamp (
    const std::shared_ptr< ITime > & requestedTimeStamp
) 
```






### function MapFromTimeStampsToTimeSpan 

```C++
std::vector< real > OpenOasis::CommImp::Temporal::TimeBuffer::MapFromTimeStampsToTimeSpan (
    const std::shared_ptr< ITime > & requestedTime
) 
```






### function MapFromTimeStampsToTimeStamp 

```C++
std::vector< real > OpenOasis::CommImp::Temporal::TimeBuffer::MapFromTimeStampsToTimeStamp (
    const std::shared_ptr< ITime > & requestedTimeStamp
) 
```




------------------------------
The documentation for this class was generated from the following file `Models/CommImp/Temporal/TimeBuffer.h`

