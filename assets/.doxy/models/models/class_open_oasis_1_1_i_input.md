

# Class OpenOasis::IInput



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IInput**](class_open_oasis_1_1_i_input.md)



_An input item that can accept values for an_ `ILinkableComponent` _. The input item may have multiple providers._

* `#include <IInput.h>`



Inherits the following classes: [OpenOasis::IBaseExchangeItem](class_open_oasis_1_1_i_base_exchange_item.md)
















## Public Types inherited from OpenOasis::IBaseExchangeItem

See [OpenOasis::IBaseExchangeItem](class_open_oasis_1_1_i_base_exchange_item.md)

| Type | Name |
| ---: | :--- |
| typedef std::function&lt; void(std::shared\_ptr&lt; [**ExchangeItemChangeEventArgs**](class_open_oasis_1_1_exchange_item_change_event_args.md) &gt;)&gt; | [**ListenFunc**](#typedef-listenfunc)  <br> |














































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**AddProvider**](#function-addprovider) (std::shared\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; provider) = 0<br>_Adds a provider for this input item._  |
| virtual std::vector&lt; std::weak\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; &gt; | [**GetProviders**](#function-getproviders) () const = 0<br>_Gets the providers that this input should get its values from._  |
| virtual void | [**RemoveProvider**](#function-removeprovider) (const std::shared\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; & provider) = 0<br>_Removes specified provider from this input item._  |


## Public Functions inherited from OpenOasis::IBaseExchangeItem

See [OpenOasis::IBaseExchangeItem](class_open_oasis_1_1_i_base_exchange_item.md)

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










































































































## Public Functions Documentation




### function AddProvider 

```C++
virtual void OpenOasis::IInput::AddProvider (
    std::shared_ptr< IOutput > provider
) = 0
```






### function GetProviders 

_Gets the providers that this input should get its values from._ 
```C++
virtual std::vector< std::weak_ptr< IOutput > > OpenOasis::IInput::GetProviders () const = 0
```



An `IOutput` item provides data while calling its `GetValues()`. 


        



### function RemoveProvider 

```C++
virtual void OpenOasis::IInput::RemoveProvider (
    const std::shared_ptr< IOutput > & provider
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IInput.h`

