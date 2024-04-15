

# Class OpenOasis::ILinkableComponent



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**ILinkableComponent**](class_open_oasis_1_1_i_linkable_component.md)



_The key interface class for linkable modules connection and data transfer._ 

* `#include <ILinkableComponent.h>`



Inherits the following classes: [OpenOasis::IIdentifiable](class_open_oasis_1_1_i_identifiable.md)














## Public Types

| Type | Name |
| ---: | :--- |
| typedef std::function&lt; void(std::shared\_ptr&lt; [**LinkableComponentStatusChangeEventArgs**](class_open_oasis_1_1_linkable_component_status_change_event_args.md) &gt;)&gt; | [**ListenFunc**](#typedef-listenfunc)  <br> |




























































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**AddListener**](#function-addlistener) (const ListenFunc & func) = 0<br> |
| virtual void | [**Finish**](#function-finish) () = 0<br>_Finishes the component computation, and then restart it if needed._  |
| virtual std::vector&lt; std::shared\_ptr&lt; [**IAdaptedOutputFactory**](class_open_oasis_1_1_i_adapted_output_factory.md) &gt; &gt; | [**GetAdaptedOutputFactories**](#function-getadaptedoutputfactories) () const = 0<br>_Gets the list of_ `IAdaptedOutputFactory` _, each allowing to create_`IAdaptedOutput` _item for making output fit to inputs in case they do not already do so._ |
| virtual std::vector&lt; std::shared\_ptr&lt; [**IArgument**](class_open_oasis_1_1_i_argument.md) &gt; &gt; | [**GetArguments**](#function-getarguments) () const = 0<br>_Gets arguments needed to let the component do its work._  |
| virtual std::vector&lt; std::shared\_ptr&lt; [**IInput**](class_open_oasis_1_1_i_input.md) &gt; &gt; | [**GetInputs**](#function-getinputs) () const = 0<br>_Gets the input items for recieving values._  |
| virtual std::vector&lt; std::shared\_ptr&lt; [**IOutput**](class_open_oasis_1_1_i_output.md) &gt; &gt; | [**GetOutputs**](#function-getoutputs) () const = 0<br>_Gets the output items for producing results._  |
| virtual [**LinkableComponentStatus**](namespace_open_oasis.md#enum-linkablecomponentstatus) | [**GetStatus**](#function-getstatus) () const = 0<br>_Gets status of the linkable component._  |
| virtual void | [**Initialize**](#function-initialize) () = 0<br>_Initializes the component._  |
| virtual void | [**Prepare**](#function-prepare) () = 0<br>_Prepares the component for calls to the_ `Update()` _._ |
| virtual void | [**RemoveListener**](#function-removelistener) (const ListenFunc & func) = 0<br> |
| virtual void | [**Update**](#function-update) () = 0<br>_Updates the linkable component itself, thus reaching its next state._  |
| virtual std::vector&lt; std::string &gt; | [**Validate**](#function-validate) () = 0<br>_Validates the populated instance of the component._  |


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
using OpenOasis::ILinkableComponent::ListenFunc =  std::function<void(std::shared_ptr<LinkableComponentStatusChangeEventArgs>)>;
```



## Public Functions Documentation




### function AddListener 

```C++
virtual void OpenOasis::ILinkableComponent::AddListener (
    const ListenFunc & func
) = 0
```






### function Finish 

_Finishes the component computation, and then restart it if needed._ 
```C++
virtual void OpenOasis::ILinkableComponent::Finish () = 0
```



This method is and must be invoked as the last of any methods in the `ILinkableComponent` interfaces.


Immediatly after this method is invoked, it changes the component's status to `Finishing`. Once the finishing is completed, the component changes status to `Finished` if it can't be restarted; `Created`, otherwise.




**Exception:**


* `This` method must be accessible after the `Prepare()` method has been invoked. Otherwise,the component can't handled this, an exception must be thrown. 




        



### function GetAdaptedOutputFactories 

```C++
virtual std::vector< std::shared_ptr< IAdaptedOutputFactory > > OpenOasis::ILinkableComponent::GetAdaptedOutputFactories () const = 0
```






### function GetArguments 

_Gets arguments needed to let the component do its work._ 
```C++
virtual std::vector< std::shared_ptr< IArgument > > OpenOasis::ILinkableComponent::GetArguments () const = 0
```



Arguments validations can be done either when they occur, or when the `Initialize()` method is called. 


        



### function GetInputs 

_Gets the input items for recieving values._ 
```C++
virtual std::vector< std::shared_ptr< IInput > > OpenOasis::ILinkableComponent::GetInputs () const = 0
```





**Exception:**


* `The` method must be accessible after `Initialize()` method has been called and until the `Validate()` method has been invoked. Otherwise, `LinkableComponent` can't handle this, an exception must be thrown. 




        



### function GetOutputs 

_Gets the output items for producing results._ 
```C++
virtual std::vector< std::shared_ptr< IOutput > > OpenOasis::ILinkableComponent::GetOutputs () const = 0
```





**Exception:**


* `The` method must be accessible after `Initialize()` method has been invoked and until `Validate()` method has been invoked. Otherwise, `LinkableComponent` cant handle this, an exception must be thrown. 




        



### function GetStatus 

_Gets status of the linkable component._ 
```C++
virtual LinkableComponentStatus OpenOasis::ILinkableComponent::GetStatus () const = 0
```



The first status that a component sets is `Created`, as soon after it has been created. 


        



### function Initialize 

_Initializes the component._ 
```C++
virtual void OpenOasis::ILinkableComponent::Initialize () = 0
```



The `Initialize()` will and must be invoked before any other methods in the `ILinkableComponent` interface is invoked or accessed, except for the `GetArguments`.


Immediatly after the method is been invoked, it changes the linkable component's status to `Initializing`. If component initializes succesfully, the status is changed to `Initialized`.


The method will typically populate the component based on values specified in its arguments. Settings can be used to read input files, allocate memory, and organize input and output items.




**Exception:**


* `When` the method is executed and an error occurs, the status will change to `Failed`, and an exception will be thrown. 
* `It's` only required that `Initialize()` can be invoked once. If the `Initialize()` method is invoked more than once, `ILinkableComponent` can't handle this, thrown an exception. 




        



### function Prepare 

_Prepares the component for calls to the_ `Update()` _._
```C++
virtual void OpenOasis::ILinkableComponent::Prepare () = 0
```



Before `Prepare()` is called, the component are not required to honor any type of action that retrieves values from the component. After `Prepare()` is called, the component must be ready for providing values. Immediatly after the method is invoked, it changes the component's status to `Preparing`. When the method has finished, the status of the component has changed to either `Updated` or `Failed`.




**Exception:**


* `The` method must be accessible after the `Initialize()` method has been called and until the `Finish()` method has been invoked. Otherwise, the linkable component can't handle it, an exception must be thrown. 
* `It's` required the `Prepare()` method can be invoked once. Otherwise, the linkable component can't handle this, an exception must be thrown. 




        



### function RemoveListener 

```C++
virtual void OpenOasis::ILinkableComponent::RemoveListener (
    const ListenFunc & func
) = 0
```






### function Update 

_Updates the linkable component itself, thus reaching its next state._ 
```C++
virtual void OpenOasis::ILinkableComponent::Update () = 0
```



Immediately after `Update()` is invoked, it changes the component's status to `Updating`. If the method is performed succesfully, the component sets its status to `Updated`, unless after this update action is at the end of its computation, in which case it will set its status to `Done`.


According to the 'pull-driven' approach, linkable components can be connected in a chain, where invoking `Update()` method on the last component in the chain trigger the entire stack of data exchange.


The type of actions a component takes during the `Update()` method depends on the type of component. A numerical model that progresses in time will typically compute a time step. A database would typically look at the consumers of its output items, and perform one or more queries to be able to provide the values that the consumers required.




**Exception:**


* `If` during the `Update()` method problem arises, the component sets its state to `Failed` and throws an exception. 




        



### function Validate 

_Validates the populated instance of the component._ 
```C++
virtual std::vector< std::string > OpenOasis::ILinkableComponent::Validate () = 0
```



The method will must be invoked after various provider/consumer relations between this component's exchange items and the exchange items of other components present in the composition.


Immediatly after this method is invoked, it changes the component's status to `Validating`. When the method has finished, the status of the component has changed to either `Valid` or `Invalid`.


If there are messages while components status is `Valid`, the messages are purely informative. If there're messages while components status is `Invalid`, at least one of the messages indicates a fatal error.




**Exception:**


* `The` method must be accessible after the `Initialize()` has been called and until the `Finish()` method has been invoked. Otherwise, the linkable component can not handle this, an exception must be thrown. 




        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/ILinkableComponent.h`

