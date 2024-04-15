

# Class OpenOasis::IDescribable



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IDescribable**](class_open_oasis_1_1_i_describable.md)



_An entity that is describable has a caption (title or heading) and a description. These are not to be used for identification._ 

* `#include <IDescribable.h>`





Inherited by the following classes: [OpenOasis::ICategory](class_open_oasis_1_1_i_category.md),  [OpenOasis::IIdentifiable](class_open_oasis_1_1_i_identifiable.md),  [OpenOasis::ISpatialDefinition](class_open_oasis_1_1_i_spatial_definition.md),  [OpenOasis::IUnit](class_open_oasis_1_1_i_unit.md),  [OpenOasis::IValueDefinition](class_open_oasis_1_1_i_value_definition.md)
































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetCaption**](#function-getcaption) () const = 0<br> |
| virtual std::string | [**GetDescription**](#function-getdescription) () const = 0<br> |
| virtual void | [**SetCaption**](#function-setcaption) (const std::string & value) = 0<br> |
| virtual void | [**SetDescription**](#function-setdescription) (const std::string & value) = 0<br> |




























## Public Functions Documentation




### function GetCaption 

```C++
virtual std::string OpenOasis::IDescribable::GetCaption () const = 0
```






### function GetDescription 

```C++
virtual std::string OpenOasis::IDescribable::GetDescription () const = 0
```






### function SetCaption 

```C++
virtual void OpenOasis::IDescribable::SetCaption (
    const std::string & value
) = 0
```






### function SetDescription 

```C++
virtual void OpenOasis::IDescribable::SetDescription (
    const std::string & value
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IDescribable.h`

