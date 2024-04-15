

# Class OpenOasis::IQuantity



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IQuantity**](class_open_oasis_1_1_i_quantity.md)



_Class specifies values as an amount of some unit._ 

* `#include <IQuantity.h>`



Inherits the following classes: [OpenOasis::IValueDefinition](class_open_oasis_1_1_i_value_definition.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::shared\_ptr&lt; [**IUnit**](class_open_oasis_1_1_i_unit.md) &gt; | [**GetUnit**](#function-getunit) () const = 0<br>_Unit of quantity._  |


## Public Functions inherited from OpenOasis::IValueDefinition

See [OpenOasis::IValueDefinition](class_open_oasis_1_1_i_value_definition.md)

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




### function GetUnit 

```C++
virtual std::shared_ptr< IUnit > OpenOasis::IQuantity::GetUnit () const = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IQuantity.h`

