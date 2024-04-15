

# Class OpenOasis::IAdaptedOutput



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IAdaptedOutput**](class_open_oasis_1_1_i_adapted_output.md)



_Extension class for adding data operations on top of an output item._ [More...](#detailed-description)

* `#include <IAdaptedOutput.h>`



Inherits the following classes: [OpenOasis::IOutput](class_open_oasis_1_1_i_output.md)


















## Public Types inherited from OpenOasis::IBaseExchangeItem

See [OpenOasis::IBaseExchangeItem](class_open_oasis_1_1_i_base_exchange_item.md)

| Type | Name |
| ---: | :--- |
| typedef std::function&lt; void(std::shared\_ptr&lt; [**ExchangeItemChangeEventArgs**](class_open_oasis_1_1_exchange_item_change_event_args.md) &gt;)&gt; | [**ListenFunc**](#typedef-listenfunc)  <br> |
































































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::weak\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; | [**GetAdaptee**](#function-getadaptee) () const = 0<br>`IOutput` _item that this_`IAdaptedOutput` _extracts content from._ |
| virtual std::vector&lt; std::shared\_ptr&lt; [**IArgument**](class_open_oasis_1_1_i_argument.md) &gt; &gt; | [**GetArguments**](#function-getarguments) () const = 0<br>_Arguments needed to let the adapted output do its work._  |
| virtual void | [**Initialize**](#function-initialize) () = 0<br>_Let the adapted output initialize itself based on the current values specified by the arguments._  |
| virtual void | [**Refresh**](#function-refresh) () = 0<br>_Requests the adapted output to refresh itself._  |
| virtual void | [**SetAdaptee**](#function-setadaptee) (std::shared\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; adaptee) = 0<br>_Sets an output which requiring the provided adaptive data operations._  |


## Public Functions inherited from OpenOasis::IOutput

See [OpenOasis::IOutput](class_open_oasis_1_1_i_output.md)

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


The `IAdaptedOutput` extends an `IOutput` item with functionality, such as spatial interpolation, temporal interpolation, unit conversion etc. 


    
## Public Functions Documentation




### function GetAdaptee 

`IOutput` _item that this_`IAdaptedOutput` _extracts content from._
```C++
virtual std::weak_ptr< IOutput > OpenOasis::IAdaptedOutput::GetAdaptee () const = 0
```



In the adapter design pattern, it is the item being adapted. 


        



### function GetArguments 

_Arguments needed to let the adapted output do its work._ 
```C++
virtual std::vector< std::shared_ptr< IArgument > > OpenOasis::IAdaptedOutput::GetArguments () const = 0
```



An unmodifiable list of the (modifiable) arguments should be returned that can be used to get info on the arguments and to modify argument values.




**Returns:**

Unmodifiable list of `IArgument`. 





        



### function Initialize 

_Let the adapted output initialize itself based on the current values specified by the arguments._ 
```C++
virtual void OpenOasis::IAdaptedOutput::Initialize () = 0
```



Only after `Initialize()` is called, the `Refresh()` method might be called. A component must invoke the `Initialize()` method of all its adapted outputs at the end of the component's prepare phase. In case of stacked adapted outputs, the adaptee must be initialized firstly. 


        



### function Refresh 

_Requests the adapted output to refresh itself._ 
```C++
virtual void OpenOasis::IAdaptedOutput::Refresh () = 0
```



After updating itself, the adapted output must call `Refresh()` method on all its adapted outputs, so the chain of outputs refreshes itself. 


        



### function SetAdaptee 

```C++
virtual void OpenOasis::IAdaptedOutput::SetAdaptee (
    std::shared_ptr< IOutput > adaptee
) = 0
```




------------------------------
The documentation for this class was generated from the following file `Models/Inc/IAdaptedOutput.h`

