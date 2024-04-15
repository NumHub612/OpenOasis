

# Class OpenOasis::ICategory



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**ICategory**](class_open_oasis_1_1_i_category.md)



_Class describes one item of a possible categorization._ [More...](#detailed-description)

* `#include <ICategory.h>`



Inherits the following classes: [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)






















































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::any | [**GetValue**](#function-getvalue) () const = 0<br>_Value for this category._  |


## Public Functions inherited from OpenOasis::IDescribable

See [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetCaption**](#function-getcaption) () const = 0<br> |
| virtual std::string | [**GetDescription**](#function-getdescription) () const = 0<br> |
| virtual void | [**SetCaption**](#function-setcaption) (const std::string & value) = 0<br> |
| virtual void | [**SetDescription**](#function-setdescription) (const std::string & value) = 0<br> |






















































# Detailed Description


It is used by the `IQuality` interface for describing qualitative data. A category defines one "class" within a "set of classes".


For qualitative data the `IValueSet` exchanged between `ILinkableComponent` contains one of the possible `ICategory` instances per data element. 


    
## Public Functions Documentation




### function GetValue 

_Value for this category._ 
```C++
virtual std::any OpenOasis::ICategory::GetValue () const = 0
```



Example, "blue" in a {"red", "green", "blue"} set. 


        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/ICategory.h`

