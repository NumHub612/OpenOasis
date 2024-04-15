

# Class OpenOasis::IDimension



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IDimension**](class_open_oasis_1_1_i_dimension.md)



_Define the order of each dimension in_ `DimensionBase` _for a unit._

* `#include <IDimension.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual double | [**GetPower**](#function-getpower) ([**DimensionBase**](namespace_open_oasis.md#enum-dimensionbase) baseQuantity) const = 0<br>_Gets the power for the requested dimension._  |
| virtual void | [**SetPower**](#function-setpower) ([**DimensionBase**](namespace_open_oasis.md#enum-dimensionbase) baseQuantity, double power) = 0<br>_Sets a power for a base dimension._  |




























## Public Functions Documentation




### function GetPower 

_Gets the power for the requested dimension._ 
```C++
virtual double OpenOasis::IDimension::GetPower (
    DimensionBase baseQuantity
) const = 0
```



Example, For a quantity such as flow, which may have the unit m3/s, the `GetPower` method must work as follows: `Flow.GetPower(DimensionBase::AmountOfSubstance)` --&gt; returns 0 `Flow.GetPower(DimensionBase::Currency)` --&gt; returns 0 `Flow.GetPower(DimensionBase::ElectricCurrent)` --&gt; returns 0 `Flow.GetPower(DimensionBase::Length)` --&gt; returns 3 `Flow.GetPower(DimensionBase::LuminousIntensity)` --&gt; returns 0 `Flow.GetPower(DimensionBase::Mass)` --&gt; returns 0 `Flow.GetPower(DimensionBase::Temperature)` --&gt; returns 0 `Flow.GetPower(DimensionBase::Time)` --&gt; returns -1 


        



### function SetPower 

_Sets a power for a base dimension._ 
```C++
virtual void OpenOasis::IDimension::SetPower (
    DimensionBase baseQuantity,
    double power
) = 0
```





**Parameters:**


* `baseQuantity` The base dimension. 
* `power` The power. 




        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IDimension.h`

