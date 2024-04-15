

# Class OpenOasis::IArgument



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IArgument**](class_open_oasis_1_1_i_argument.md)



_Class for providing arguments for an_ `ILinkableComponent` _and others._

* `#include <IArgument.h>`



Inherits the following classes: [OpenOasis::IIdentifiable](class_open_oasis_1_1_i_identifiable.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::any | [**GetDefaultValue**](#function-getdefaultvalue) () const = 0<br>_The default value of the argument._  |
| virtual std::vector&lt; std::any &gt; | [**GetPossibleValues**](#function-getpossiblevalues) () const = 0<br>_List of possible allowed values for the argument._  |
| virtual std::any | [**GetValue**](#function-getvalue) () const = 0<br>_Gets the current value of the argument._  |
| virtual const std::type\_info & | [**GetValueType**](#function-getvaluetype) () const = 0<br>_Gets the type of the value of the argument._  |
| virtual bool | [**IsOptional**](#function-isoptional) () const = 0<br>_Specifies whether the argument is optional._  |
| virtual bool | [**IsReadOnly**](#function-isreadonly) () const = 0<br>_Defines whether the value property can be edited._  |
| virtual void | [**SetValue**](#function-setvalue) (std::any value) = 0<br>_Sets the argument value, if settable._  |


## Public Functions inherited from OpenOasis::IIdentifiable

See [OpenOasis::IIdentifiable](class_open_oasis_1_1_i_identifiable.md)

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetId**](#function-getid) () const = 0<br>_Gets id string._  |


## Public Functions inherited from OpenOasis::IDescribable

See [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)

| Type | Name |
| ---: | :--- |
| virtual std::string | [**GetCaption**](#function-getcaption) () const = 0<br> |
| virtual std::string | [**GetDescription**](#function-getdescription) () const = 0<br> |
| virtual void | [**SetCaption**](#function-setcaption) (const std::string & value) = 0<br> |
| virtual void | [**SetDescription**](#function-setdescription) (const std::string & value) = 0<br> |
















































































## Public Functions Documentation




### function GetDefaultValue 

```C++
virtual std::any OpenOasis::IArgument::GetDefaultValue () const = 0
```






### function GetPossibleValues 

```C++
virtual std::vector< std::any > OpenOasis::IArgument::GetPossibleValues () const = 0
```






### function GetValue 

_Gets the current value of the argument._ 
```C++
virtual std::any OpenOasis::IArgument::GetValue () const = 0
```



If no value has been set yet, default value is returned. 


        



### function GetValueType 

```C++
virtual const std::type_info & OpenOasis::IArgument::GetValueType () const = 0
```






### function IsOptional 

_Specifies whether the argument is optional._ 
```C++
virtual bool OpenOasis::IArgument::IsOptional () const = 0
```



If false, the argument's value must be set before it could be used. 


        



### function IsReadOnly 

```C++
virtual bool OpenOasis::IArgument::IsReadOnly () const = 0
```






### function SetValue 

```C++
virtual void OpenOasis::IArgument::SetValue (
    std::any value
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IArgument.h`

