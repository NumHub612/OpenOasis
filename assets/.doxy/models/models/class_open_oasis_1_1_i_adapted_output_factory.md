

# Class OpenOasis::IAdaptedOutputFactory



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IAdaptedOutputFactory**](class_open_oasis_1_1_i_adapted_output_factory.md)



_Factory class for creating instances of_ `IAdaptedOutput` _items._

* `#include <IAdaptedOutputFactory.h>`



Inherits the following classes: [OpenOasis::IIdentifiable](class_open_oasis_1_1_i_identifiable.md)










































































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::shared\_ptr&lt; [**IAdaptedOutput**](class_open_oasis_1_1_i_adapted_output.md) &gt; | [**CreateAdaptedOutput**](#function-createadaptedoutput) (const std::shared\_ptr&lt; [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) &gt; & adaptedOutputId, const std::shared\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; & adaptee, const std::shared\_ptr&lt; [**IInput**](class_open_oasis_1_1_i_input.md) &gt; & target) = 0<br>_Creates_ `IAdaptedOutput` _adapting the adaptee, so that it fits the target._ |
| virtual std::vector&lt; std::shared\_ptr&lt; [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) &gt; &gt; | [**GetAvailableAdaptedOutputIds**](#function-getavailableadaptedoutputids) (const std::shared\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; & adaptee, const std::shared\_ptr&lt; [**IInput**](class_open_oasis_1_1_i_input.md) &gt; & target) = 0<br>_Gets a list of identifier of the available_ `IAdaptedOutput` _that can make the adaptee match the target._ |


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




### function CreateAdaptedOutput 

_Creates_ `IAdaptedOutput` _adapting the adaptee, so that it fits the target._
```C++
virtual std::shared_ptr< IAdaptedOutput > OpenOasis::IAdaptedOutputFactory::CreateAdaptedOutput (
    const std::shared_ptr< IIdentifiable > & adaptedOutputId,
    const std::shared_ptr< IOutput > & adaptee,
    const std::shared_ptr< IInput > & target
) = 0
```



The adaptedOutputId used must be one of the `IIdentifiable` instances returned by the `GetAvailableAdaptedOutputIds()` method. The returned `IAdaptedOutput` will already be registered with this adaptee.




**Parameters:**


* `adaptedOutputId` The identifier of the `IAdaptedOutput` to create. 
* `adaptee` `IOutput` to adapt. 
* `target` `IInput` to adapt the adaptee to, can be `null`.



**Returns:**

The `IAdaptedOutput` item adaptes the adaptee to fit the target item. 





        



### function GetAvailableAdaptedOutputIds 

_Gets a list of identifier of the available_ `IAdaptedOutput` _that can make the adaptee match the target._
```C++
virtual std::vector< std::shared_ptr< IIdentifiable > > OpenOasis::IAdaptedOutputFactory::GetAvailableAdaptedOutputIds (
    const std::shared_ptr< IOutput > & adaptee,
    const std::shared_ptr< IInput > & target
) = 0
```



If the target is null, the identifiers of all `IAdaptedOutput`s that can adapt the adaptee are returned.




**Parameters:**


* `adaptee` `IOutput` to adapt. 
* `target` `IInput` to adapt the adaptee to, can be `null`.



**Returns:**

List of identifier of the available `IAdaptedOutput`. 





        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IAdaptedOutputFactory.h`

