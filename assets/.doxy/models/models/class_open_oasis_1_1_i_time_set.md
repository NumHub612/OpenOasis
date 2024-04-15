

# Class OpenOasis::ITimeSet



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**ITimeSet**](class_open_oasis_1_1_i_time_set.md)



_Set of time stamps or time intervals, used to indicate when an output has and can provide values, and when an input item does or may require values._ 

* `#include <ITimeSet.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**AddTime**](#function-addtime) (std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; time) = 0<br>_Adds a_ `ITime` _to this time set._ |
| virtual double | [**GetOffsetFromUtcInHours**](#function-getoffsetfromutcinhours) () const = 0<br>_Time zone offset from UTC, expressed in the number of hours._  |
| virtual std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; | [**GetTimeHorizon**](#function-gettimehorizon) () const = 0<br>_Gets the time horizon for what timespan it may require/provide values._  |
| virtual std::vector&lt; std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; &gt; | [**GetTimes**](#function-gettimes) () const = 0<br>_Time stamps or spans as available in of an output item, or as required by an input item. Times should be ordered._  |
| virtual bool | [**HasDurations**](#function-hasdurations) () const = 0<br>_Whether each_ `ITime` _have duration. In this case,duration value greater than zero is expected for each_`ITime` _in the_`GetTimes()` _list._ |
| virtual void | [**RemoveTime**](#function-removetime) (int index) = 0<br>_Removes the_ `ITime` _element with specified index. After removing time, the duration must be updated automatically._ |




























## Public Functions Documentation




### function AddTime 

_Adds a_ `ITime` _to this time set._
```C++
virtual void OpenOasis::ITimeSet::AddTime (
    std::shared_ptr< ITime > time
) = 0
```



Usually, a timeset item is ordered by timestamp, it means the insertion will trigger interval sorting. After adding time, the duration must be updated automatically. 


        



### function GetOffsetFromUtcInHours 

_Time zone offset from UTC, expressed in the number of hours._ 
```C++
virtual double OpenOasis::ITimeSet::GetOffsetFromUtcInHours () const = 0
```



Since some of the world's time zone differ half an hour from their neighbour the value is specified as a double. 


        



### function GetTimeHorizon 

_Gets the time horizon for what timespan it may require/provide values._ 
```C++
virtual std::shared_ptr< ITime > OpenOasis::ITimeSet::GetTimeHorizon () const = 0
```



The providers of this input can assume that the input item never go back further in time than the time horizon's begin time: `GetTimeHorizon() ->GetTimeStamp()`. Also, it will never go further ahead than the time horizon's end time:: `GetTimeHorizon() ->GetTimeStamp() + GetTimeHorizon() ->GetDurationInDays()`.


For an output item, thus for an adapted output, the time horizon indicates in what time span the item can provide values. Specific values: `GetTimeHorizon() ->GetTimeStamp()` == - Infinity: far back in time; `GetTimeHorizon() ->GetDurationInDays()` == + Infinity: far in the future. 


        



### function GetTimes 

_Time stamps or spans as available in of an output item, or as required by an input item. Times should be ordered._ 
```C++
virtual std::vector< std::shared_ptr< ITime > > OpenOasis::ITimeSet::GetTimes () const = 0
```



Specific values:
* `TimeSet::GetTimes().size() == 0`, in case of input: time dependent item, but currently no values required.
* `TimeSet::GetTimes().size() == 0`, in case of output: time dependent item, but no values available yet or required yet. 




        



### function HasDurations 

```C++
virtual bool OpenOasis::ITimeSet::HasDurations () const = 0
```






### function RemoveTime 

```C++
virtual void OpenOasis::ITimeSet::RemoveTime (
    int index
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/ITimeSet.h`

