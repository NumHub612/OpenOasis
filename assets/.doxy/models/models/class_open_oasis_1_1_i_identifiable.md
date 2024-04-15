

# Class OpenOasis::IIdentifiable



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md)



_To define a method to get the Id of an_ [_**OpenOasis**_](namespace_open_oasis.md) _entity._

* `#include <IIdentifiable.h>`



Inherits the following classes: [OpenOasis::IDescribable](class_open_oasis_1_1_i_describable.md)


Inherited by the following classes: [OpenOasis::IAdaptedOutputFactory](class_open_oasis_1_1_i_adapted_output_factory.md),  [OpenOasis::IArgument](class_open_oasis_1_1_i_argument.md),  [OpenOasis::IBaseExchangeItem](class_open_oasis_1_1_i_base_exchange_item.md),  [OpenOasis::ILinkableComponent](class_open_oasis_1_1_i_linkable_component.md)




















































## Public Functions

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




### function GetId 

_Gets id string._ 
```C++
virtual std::string OpenOasis::IIdentifiable::GetId () const = 0
```



The Id must be unique within its context but does not need to be globally unique. e.g. the id of an input exchange item must be unique in the list of inputs of `ILinkableComponent`, but a similar Id might be used by an exchange item of another `ILinkableComponent`. 


        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IIdentifiable.h`

