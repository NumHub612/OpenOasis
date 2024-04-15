

# Class OpenOasis::ITime



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**ITime**](class_open_oasis_1_1_i_time.md)



_Time interface to support a time stamp as well as a time interval._ 

* `#include <ITime.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual double | [**GetDurationInDays**](#function-getdurationindays) () const = 0<br>_Duration in days for time interval. 0 if time is a time stamp._  |
| virtual double | [**GetTimeStamp**](#function-gettimestamp) () const = 0<br>_Time stamp as days since 08:00::00 January 1, 1970._  |




























## Public Functions Documentation




### function GetDurationInDays 

```C++
virtual double OpenOasis::ITime::GetDurationInDays () const = 0
```






### function GetTimeStamp 

```C++
virtual double OpenOasis::ITime::GetTimeStamp () const = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/ITime.h`

