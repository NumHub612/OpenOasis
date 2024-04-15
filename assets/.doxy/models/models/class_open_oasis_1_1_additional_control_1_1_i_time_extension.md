

# Class OpenOasis::AdditionalControl::ITimeExtension



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**AdditionalControl**](namespace_open_oasis_1_1_additional_control.md) **>** [**ITimeExtension**](class_open_oasis_1_1_additional_control_1_1_i_time_extension.md)



_Methods that are specific for a time-space component._ 

* `#include <ITimeExtension.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::shared\_ptr&lt; [**ITime**](class_open_oasis_1_1_i_time.md) &gt; | [**GetCurrTime**](#function-getcurrtime) () const = 0<br>_The property describes what time stamp the component is at._  |
| virtual std::shared\_ptr&lt; [**ITimeSet**](class_open_oasis_1_1_i_time_set.md) &gt; | [**GetTimeExtent**](#function-gettimeextent) () const = 0<br>_The property describes in what time span the component can operate. This can be used to support the user when creating a composition._  |




























## Public Functions Documentation




### function GetCurrTime 

```C++
virtual std::shared_ptr< ITime > OpenOasis::AdditionalControl::ITimeExtension::GetCurrTime () const = 0
```






### function GetTimeExtent 

```C++
virtual std::shared_ptr< ITimeSet > OpenOasis::AdditionalControl::ITimeExtension::GetTimeExtent () const = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/AdditionalControl/ITimeExtension.h`

