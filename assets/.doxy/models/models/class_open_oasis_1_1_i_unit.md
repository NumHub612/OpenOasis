

# Class OpenOasis::IUnit



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IUnit**](class_open_oasis_1_1_i_unit.md)



_Unit interface describes the physical unit._ 

* `#include <IUnit.h>`



Inherits the following classes: [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual double | [**GetConversionFactorToSI**](#function-getconversionfactortosi) () const = 0<br>_Conversion factor to SI. ('A' in: SI-value = A \* quantValue + B)._  |
| virtual std::shared\_ptr&lt; [**IDimension**](class_open_oasis_1_1_i_dimension.md) &gt; | [**GetDimension**](#function-getdimension) () const = 0<br>_The unit's dimension._  |
| virtual double | [**GetOffSetToSI**](#function-getoffsettosi) () const = 0<br>_OffSet to SI. ('B' in: SI-value = A \* quantValue + B)._  |


## Public Functions inherited from OpenOasis::IDescribable

See [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetCaption**](#function-getcaption) () const = 0<br> |
| virtual std::string | [**GetDescription**](#function-getdescription) () const = 0<br> |
| virtual void | [**SetCaption**](#function-setcaption) (const std::string & value) = 0<br> |
| virtual void | [**SetDescription**](#function-setdescription) (const std::string & value) = 0<br> |






















































## Public Functions Documentation




### function GetConversionFactorToSI 

```C++
virtual double OpenOasis::IUnit::GetConversionFactorToSI () const = 0
```






### function GetDimension 

```C++
virtual std::shared_ptr< IDimension > OpenOasis::IUnit::GetDimension () const = 0
```






### function GetOffSetToSI 

```C++
virtual double OpenOasis::IUnit::GetOffSetToSI () const = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IUnit.h`

