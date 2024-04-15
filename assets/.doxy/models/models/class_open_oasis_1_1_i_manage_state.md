

# Class OpenOasis::IManageState



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IManageState**](class_open_oasis_1_1_i_manage_state.md)



_It provides additional methods for handling component state so it can be saved, restored and cleared._ [More...](#detailed-description)

* `#include <IManageState.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**ClearState**](#function-clearstate) (const std::shared\_ptr&lt; [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) &gt; & stateId) = 0<br>_Clears a state from the linkable component._  |
| virtual std::shared\_ptr&lt; [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) &gt; | [**KeepCurrentState**](#function-keepcurrentstate) () = 0<br>_Stores the linkable component's current state to a snapshot._  |
| virtual void | [**RestoreState**](#function-restorestate) (const std::shared\_ptr&lt; [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) &gt; & stateId) = 0<br>_Restores the state identified by the stateId._  |




























# Detailed Description


An optional interface to be implemented by components in addition to the `ILinkableComponent` interface. It can be left completely to the component to handle persistence of state or it can also implement `IByteStateConverter` and provide ways for state to be converted to and from an array of bytes. 


    
## Public Functions Documentation




### function ClearState 

_Clears a state from the linkable component._ 
```C++
virtual void OpenOasis::IManageState::ClearState (
    const std::shared_ptr< IIdentifiable > & stateId
) = 0
```





**Parameters:**


* `stateId` Identifier of the componentstate to be cleared.



**Exception:**


* `If` the stateId identifier is not known by the linkable component, an exception should be trown. 




        



### function KeepCurrentState 

_Stores the linkable component's current state to a snapshot._ 
```C++
virtual std::shared_ptr< IIdentifiable > OpenOasis::IManageState::KeepCurrentState () = 0
```





**Returns:**

Identifier of the stored state. 





        



### function RestoreState 

_Restores the state identified by the stateId._ 
```C++
virtual void OpenOasis::IManageState::RestoreState (
    const std::shared_ptr< IIdentifiable > & stateId
) = 0
```





**Parameters:**


* `stateId` Identifier of the component state to be restored.



**Exception:**


* `If` the stateId identifier is not known by the linkable component, an exception should be thrown. 




        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IManageState.h`

