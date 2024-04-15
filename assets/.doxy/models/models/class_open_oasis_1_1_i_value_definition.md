

# Class OpenOasis::IValueDefinition



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IValueDefinition**](class_open_oasis_1_1_i_value_definition.md)



_Class describes value definition._ 

* `#include <IValueDefinition.h>`



Inherits the following classes: [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)


Inherited by the following classes: [OpenOasis::IQuality](class_open_oasis_1_1_i_quality.md),  [OpenOasis::IQuantity](class_open_oasis_1_1_i_quantity.md)




















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::any | [**GetMissingDataValue**](#function-getmissingdatavalue) () const = 0<br>_Gets flag representing missing data._  |
| virtual const std::type\_info & | [**GetValueType**](#function-getvaluetype) () const = 0<br>_Gets object value type._  |


## Public Functions inherited from OpenOasis::IDescribable

See [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetCaption**](#function-getcaption) () const = 0<br> |
| virtual std::string | [**GetDescription**](#function-getdescription) () const = 0<br> |
| virtual void | [**SetCaption**](#function-setcaption) (const std::string & value) = 0<br> |
| virtual void | [**SetDescription**](#function-setdescription) (const std::string & value) = 0<br> |






















































## Public Functions Documentation




### function GetMissingDataValue 

```C++
virtual std::any OpenOasis::IValueDefinition::GetMissingDataValue () const = 0
```






### function GetValueType 

```C++
virtual const std::type_info & OpenOasis::IValueDefinition::GetValueType () const = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IValueDefinition.h`

