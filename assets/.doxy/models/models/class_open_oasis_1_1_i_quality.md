

# Class OpenOasis::IQuality



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IQuality**](class_open_oasis_1_1_i_quality.md)



_Class describes qualitative data, where a value is specified as one category within a number of predefined (possible) categories._ [More...](#detailed-description)

* `#include <IQuality.h>`



Inherits the following classes: [OpenOasis::IValueDefinition](class_open_oasis_1_1_i_value_definition.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::vector&lt; std::shared\_ptr&lt; [**ICategory**](class_open_oasis_1_1_i_category.md) &gt; &gt; | [**GetCategories**](#function-getcategories) () const = 0<br>_Gets a list of the possible_ `ICategory` _allowed._ |
| virtual bool | [**IsOrdered**](#function-isordered) () const = 0<br>_Checks if this_ `IQuality` _is defined by an ordered set or not._ |


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
















































































# Detailed Description


Qualitative data described items in terms of some quality or categorization that may be 'informal' or may use relatively ill-defined characteristics such as warmth and flavour. However, qualitative data can include well-defined aspects such as gender, nationality or commodity type.


For qualitative data the `IValueSet` exchanged between `ILinkableComponent`s contains one of the possible `ICategory` instances per element in the element set involved. For examples: Colors : red, green, blue; Land use: nature, recreation, industry, infrastructure; Rating : worse, same, better. 


    
## Public Functions Documentation




### function GetCategories 

_Gets a list of the possible_ `ICategory` _allowed._
```C++
virtual std::vector< std::shared_ptr< ICategory > > OpenOasis::IQuality::GetCategories () const = 0
```



If the quality is not ordered, the list contains the `ICategory`s in an unspecified order. When it's ordered, the list contains the `ICategory`s in the same sequence. 


        



### function IsOrdered 

```C++
virtual bool OpenOasis::IQuality::IsOrdered () const = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IQuality.h`

