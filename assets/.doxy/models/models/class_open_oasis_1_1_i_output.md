

# Class OpenOasis::IOutput



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IOutput**](class_open_oasis_1_1_i_output.md)



_Output exchange item that can deliver values from an_ `ILinkableComponent` _._[More...](#detailed-description)

* `#include <IOutput.h>`



Inherits the following classes: [OpenOasis::IBaseExchangeItem](class_open_oasis_1_1_i_base_exchange_item.md)


Inherited by the following classes: [OpenOasis::IAdaptedOutput](class_open_oasis_1_1_i_adapted_output.md)














## Public Types inherited from OpenOasis::IBaseExchangeItem

See [OpenOasis::IBaseExchangeItem](class_open_oasis_1_1_i_base_exchange_item.md)

| Type | Name |
| ---: | :--- |
| typedef std::function&lt; void(std::shared\_ptr&lt; [**ExchangeItemChangeEventArgs**](class_open_oasis_1_1_exchange_item_change_event_args.md) &gt;)&gt; | [**ListenFunc**](#typedef-listenfunc)  <br> |














































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**AddAdaptedOutput**](#function-addadaptedoutput) (std::shared\_ptr&lt; [**IAdaptedOutput**](class_open_oasis_1_1_i_adapted_output.md) &gt; adaptedOutput) = 0<br>_Adds an adapted output to this output item as a transformer._  |
| virtual void | [**AddConsumer**](#function-addconsumer) (std::shared\_ptr&lt; [**IInput**](class_open_oasis_1_1_i_input.md) &gt; consumer) = 0<br>_Adds a consumer to the output item. Every input item needs to add itself as a consumer first._  |
| virtual std::vector&lt; std::shared\_ptr&lt; [**IAdaptedOutput**](class_open_oasis_1_1_i_adapted_output.md) &gt; &gt; | [**GetAdaptedOutputs**](#function-getadaptedoutputs) () const = 0<br>_Gets the adapted outputs._  |
| virtual std::vector&lt; std::weak\_ptr&lt; [**IInput**](class_open_oasis_1_1_i_input.md) &gt; &gt; | [**GetConsumers**](#function-getconsumers) () const = 0<br>_Gets inputs that will consume the value, by calling the_ `GetValues()` _method. Every input item needs to call the_`AddConsumer()` _method first._ |
| virtual void | [**RemoveAdaptedOutput**](#function-removeadaptedoutput) (const std::shared\_ptr&lt; [**IAdaptedOutput**](class_open_oasis_1_1_i_adapted_output.md) &gt; & adaptedOutput) = 0<br>_Removes a_ `IAdaptedOutput` _._ |
| virtual void | [**RemoveConsumer**](#function-removeconsumer) (const std::shared\_ptr&lt; [**IInput**](class_open_oasis_1_1_i_input.md) &gt; & consumer) = 0<br>_Removes a consumer._  |


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










































































































# Detailed Description


If an output does not provide the data in the way a consumer would like to have, the output can be adapted by an `IAdaptedOutput`, which can transform the data according to the consumer's wishes. 


    
## Public Functions Documentation




### function AddAdaptedOutput 

_Adds an adapted output to this output item as a transformer._ 
```C++
virtual void OpenOasis::IOutput::AddAdaptedOutput (
    std::shared_ptr< IAdaptedOutput > adaptedOutput
) = 0
```



The `AddAdaptedOutput()` method must and will automatically add the adapted output's adaptee by calling its `SetAdaptee()` method.




**Exception:**


* `If` an `IAdaptedOutput` item is added that can not be handled or is incompatible with the already added `IAdaptedOutput`s, an exception will be thrown. 




        



### function AddConsumer 

_Adds a consumer to the output item. Every input item needs to add itself as a consumer first._ 
```C++
virtual void OpenOasis::IOutput::AddConsumer (
    std::shared_ptr< IInput > consumer
) = 0
```



The `AddConsumer()` method must and will automatically add the consumer provider by calling the `IInput::AddProvider()` method.




**Exception:**


* `If` a consumer is added that can't be handled, or it's incompatible with the already added consumers, throw an exception. 




        



### function GetAdaptedOutputs 

_Gets the adapted outputs._ 
```C++
virtual std::vector< std::shared_ptr< IAdaptedOutput > > OpenOasis::IOutput::GetAdaptedOutputs () const = 0
```



As the output item's values have been updated, each `IAdaptedOutput` its `Refresh()` method must be called after. 


        



### function GetConsumers 

_Gets inputs that will consume the value, by calling the_ `GetValues()` _method. Every input item needs to call the_`AddConsumer()` _method first._
```C++
virtual std::vector< std::weak_ptr< IInput > > OpenOasis::IOutput::GetConsumers () const = 0
```



Please be aware that the unadulterated value in the output item provided by the read only '[**GetValues()**](class_open_oasis_1_1_i_base_exchange_item.md#function-getvalues)' method, may be called anyway, even if there are no values available. 


        



### function RemoveAdaptedOutput 

_Removes a_ `IAdaptedOutput` _._
```C++
virtual void OpenOasis::IOutput::RemoveAdaptedOutput (
    const std::shared_ptr< IAdaptedOutput > & adaptedOutput
) = 0
```



If an `IAdaptedOutput` is not interested any longer in this output item's data, it should remove itself by calling this method.


The `RemoveAdaptedOutput()` method must and will automatically remove the adapted output's adaptee by setting it to null. 


        



### function RemoveConsumer 

_Removes a consumer._ 
```C++
virtual void OpenOasis::IOutput::RemoveConsumer (
    const std::shared_ptr< IInput > & consumer
) = 0
```



If an input item isn't interested any longer in calling `GetValues()` method, it should remove the input item.


The `RemoveConsumer()` method must and will automatically remove the consumer's provider by calling the `IInput::RemoveProvider()` method. 


        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IOutput.h`

