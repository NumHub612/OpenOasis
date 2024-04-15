

# Class OpenOasis::IBaseExchangeItem



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IBaseExchangeItem**](class_open_oasis_1_1_i_base_exchange_item.md)



_Class presenting a item that can be exchanged, either as an input or output._ 

* `#include <IBaseExchangeItem.h>`



Inherits the following classes: [OpenOasis::IIdentifiable](class_open_oasis_1_1_i_identifiable.md)


Inherited by the following classes: [OpenOasis::IInput](class_open_oasis_1_1_i_input.md),  [OpenOasis::IOutput](class_open_oasis_1_1_i_output.md)












## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::function&lt; void(std::shared\_ptr&lt; [**ExchangeItemChangeEventArgs**](class_open_oasis_1_1_exchange_item_change_event_args.md) &gt;)&gt; | [**ListenFunc**](#typedef-listenfunc)  <br> |




























































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**AddListener**](#function-addlistener) (const ListenFunc & func) = 0<br>_Adds a listener to the exchange item._  |
| virtual std::weak\_ptr&lt; [**ILinkableComponent**](class_open_oasis_1_1_i_linkable_component.md) &gt; | [**GetComponent**](#function-getcomponent) () const = 0<br>_Gets the owner of the exchange item._  |
| virtual std::shared\_ptr&lt; [**IElementSet**](class_open_oasis_1_1_i_element_set.md) &gt; | [**GetElementSet**](#function-getelementset) () const = 0<br>_Gets the exchange item's elements. If it's id-based, return null._  |
| virtual std::shared\_ptr&lt; [**ITimeSet**](class_open_oasis_1_1_i_time_set.md) &gt; | [**GetTimeSet**](#function-gettimeset) () const = 0<br>_Gets the exchange item's available time set. If it's time independent, return null._  |
| virtual std::shared\_ptr&lt; [**IValueDefinition**](class_open_oasis_1_1_i_value_definition.md) &gt; | [**GetValueDefinition**](#function-getvaluedefinition) () const = 0<br>_Definition of the values in the exchange item._  |
| virtual std::shared\_ptr&lt; [**IValueSet**](class_open_oasis_1_1_i_value_set.md) &gt; | [**GetValues**](#function-getvalues) () = 0<br>_Provides the values matching the value definition specified. Extensions can overwrite this base version to include more details in the query, e.g. time and space._  |
| virtual void | [**RemoveListener**](#function-removelistener) (const ListenFunc & func) = 0<br>_Removes the listener if it is no more interested at this item._  |
| virtual void | [**Reset**](#function-reset) () = 0<br>_Resets the exchange item._  |
| virtual void | [**SetElementSet**](#function-setelementset) (std::shared\_ptr&lt; [**IElementSet**](class_open_oasis_1_1_i_element_set.md) &gt; elements) = 0<br>_Sets the exchange item's elements._  |
| virtual void | [**SetTimeSet**](#function-settimeset) (std::shared\_ptr&lt; [**ITimeSet**](class_open_oasis_1_1_i_time_set.md) &gt; times) = 0<br>_Sets the exchange item's time set._  |
| virtual void | [**SetValues**](#function-setvalues) (std::shared\_ptr&lt; [**IValueSet**](class_open_oasis_1_1_i_value_set.md) &gt; value) = 0<br>_Sets the exchange item's values._  |


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
















































































## Public Types Documentation




### typedef ListenFunc 

```C++
using OpenOasis::IBaseExchangeItem::ListenFunc =  std::function<void(std::shared_ptr<ExchangeItemChangeEventArgs>)>;
```



## Public Functions Documentation




### function AddListener 

```C++
virtual void OpenOasis::IBaseExchangeItem::AddListener (
    const ListenFunc & func
) = 0
```






### function GetComponent 

_Gets the owner of the exchange item._ 
```C++
virtual std::weak_ptr< ILinkableComponent > OpenOasis::IBaseExchangeItem::GetComponent () const = 0
```



For an output exchange item this is the component responsible for providing the content of the output item. It's possible for an exchange item to have no owner, in this case the method will return null. 


        



### function GetElementSet 

```C++
virtual std::shared_ptr< IElementSet > OpenOasis::IBaseExchangeItem::GetElementSet () const = 0
```






### function GetTimeSet 

```C++
virtual std::shared_ptr< ITimeSet > OpenOasis::IBaseExchangeItem::GetTimeSet () const = 0
```






### function GetValueDefinition 

_Definition of the values in the exchange item._ 
```C++
virtual std::shared_ptr< IValueDefinition > OpenOasis::IBaseExchangeItem::GetValueDefinition () const = 0
```



This `IValueDefinition` should never be returned directly; all implementing classes should return either `IQuality`, `IQuantity`, or a custom derived value definition interface. 


        



### function GetValues 

_Provides the values matching the value definition specified. Extensions can overwrite this base version to include more details in the query, e.g. time and space._ 
```C++
virtual std::shared_ptr< IValueSet > OpenOasis::IBaseExchangeItem::GetValues () = 0
```



For an input item, this means to get the input item's value pulled from its provider(s). For an output item, this means to provide the values required by consumers. 


        



### function RemoveListener 

```C++
virtual void OpenOasis::IBaseExchangeItem::RemoveListener (
    const ListenFunc & func
) = 0
```






### function Reset 

```C++
virtual void OpenOasis::IBaseExchangeItem::Reset () = 0
```






### function SetElementSet 

```C++
virtual void OpenOasis::IBaseExchangeItem::SetElementSet (
    std::shared_ptr< IElementSet > elements
) = 0
```






### function SetTimeSet 

```C++
virtual void OpenOasis::IBaseExchangeItem::SetTimeSet (
    std::shared_ptr< ITimeSet > times
) = 0
```






### function SetValues 

```C++
virtual void OpenOasis::IBaseExchangeItem::SetValues (
    std::shared_ptr< IValueSet > value
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IBaseExchangeItem.h`

