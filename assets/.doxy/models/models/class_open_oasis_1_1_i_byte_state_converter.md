

# Class OpenOasis::IByteStateConverter



[**ClassList**](annotated.md) **>** [**OpenOasis**](namespace_open_oasis.md) **>** [**IByteStateConverter**](class_open_oasis_1_1_i_byte_state_converter.md)



_An optional interface to save and transform the model state._ [More...](#detailed-description)

* `#include <IByteStateConverter.h>`





































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual std::shared\_ptr&lt; [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) &gt; | [**ConvertFromByteStream**](#function-convertfrombytestream) (const std::stringstream & byteStream) = 0<br>_Creates a state from a byte stream and return the identifier._  |
| virtual std::stringstream | [**ConvertToByteStream**](#function-converttobytestream) (const std::shared\_ptr&lt; [**IIdentifiable**](class_open_oasis_1_1_i_identifiable.md) &gt; & stateId) = 0<br>_Converts the state with the stateId into a byte stream._  |




























# Detailed Description


This interface is an optional complement to the `IManageState` interface.Both are extensions to `ILinkableComponent`, meant to provide state management. It defines methods for converting a state into a byte stream and reading in a state from a byte stream.


This facilitates external modules, e.g. a GUI or an operational control system, to save a model's state somewhere as persistent state. 


    
## Public Functions Documentation




### function ConvertFromByteStream 

_Creates a state from a byte stream and return the identifier._ 
```C++
virtual std::shared_ptr< IIdentifiable > OpenOasis::IByteStateConverter::ConvertFromByteStream (
    const std::stringstream & byteStream
) = 0
```





**Parameters:**


* `byteStream` State as a byte stream. 



**Returns:**

`IIdentifiable` identifying the state. 





        



### function ConvertToByteStream 

_Converts the state with the stateId into a byte stream._ 
```C++
virtual std::stringstream OpenOasis::IByteStateConverter::ConvertToByteStream (
    const std::shared_ptr< IIdentifiable > & stateId
) = 0
```





**Parameters:**


* `stateId` Id of the state. 



**Returns:**

The state identified by stateId as a byte stream. 





        

------------------------------
The documentation for this class was generated from the following file `Models/Inc/IByteStateConverter.h`

